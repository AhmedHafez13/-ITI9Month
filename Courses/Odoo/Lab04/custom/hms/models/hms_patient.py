from odoo import models, fields, api, exceptions
import re
from dateutil.relativedelta import relativedelta


class HmsPatient(models.Model):
    _name = "hms.patient"

    first_name = fields.Char(required=True)
    last_name = fields.Char(required=True)
    email = fields.Char(required=True)
    birth_date = fields.Date()
    history = fields.Html()
    cr_ratio = fields.Float()
    blood_type = fields.Selection([
        ('A', 'A'),
        ('B', 'B'),
        ('C', 'C'),
        ('O', 'O')
    ], default="A")
    pcr = fields.Boolean()
    image = fields.Image()
    address = fields.Text()
    age = fields.Integer(compute="calc_age", store=True)

    state = fields.Selection([
        ('Undetermined', 'Undetermined'),
        ('Good', 'Good'),
        ('Fair', 'Fair'),
        ('Serious', 'Serious'),
    ], default='Undetermined')

    department_id = fields.Many2one(comodel_name='hms.department', string="Department")
    is_department_opened = fields.Boolean(related='department_id.is_opened')

    doctors_ids = fields.Many2many(comodel_name='hms.doctor')

    log = fields.One2many(comodel_name='hms.log', inverse_name='patient_id', string="Log")

    # @api.onchange('department_id')
    # def onchange_department_id(self):
    #     if self.first_name and not self.is_department_opened:
    #         raise exceptions.UserError("Department is closed!")

    @api.depends('birth_date')
    def calc_age(self):
        for record in self:
            if record.birth_date and record.birth_date <= fields.Date.today():
                record.age = relativedelta(
                    fields.Date.from_string(fields.Date.today()),
                    fields.Date.from_string(record.birth_date)).years
            else:
                record.age = 0

    @api.onchange('age')
    def onchange_age(self):
        if self.first_name and self.age < 30:
            self.pcr = True
            return {
                'warning': {
                    'title': 'Warning',
                    'message': 'PCR has been checked'
                }
            }

    @api.constrains('email')
    def validate_email(self):
        if self.email:
            match = re.match(
                '^([A-Z|a-z|0-9](\.|_){0,1})+[A-Z|a-z|0-9]\@([A-Z|a-z|0-9])+((\.){0,1}[A-Z|a-z|0-9]){2}\.[a-z]{2,3}$',
                self.email)
            if not match:
                raise exceptions.ValidationError('Email is not valid')

    _sql_constraints = [
        ('Duplicate_Email', 'UNIQUE(email)', 'Email already exists'),
    ]

    def update_state(self, state):
        self.env['hms.log'].create({
            'details': "State has changed to " + state,
            'patient_id': self.id
        })

    def set_state_undetermined(self):
        self.state = 'Undetermined'
        self.update_state('Undetermined')

    def set_state_good(self):
        self.state = 'Good'
        self.update_state('Good')

    def set_state_fair(self):
        self.state = 'Fair'
        self.update_state('Fair')

    def set_state_serious(self):
        self.state = 'Serious'
        self.update_state('Serious')
