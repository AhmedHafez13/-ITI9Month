from odoo import models, fields, api, exceptions
from odoo.exceptions import UserError


class HmsCustomerInheritance(models.Model):
    _inherit = 'res.partner'

    related_patient_id = fields.Many2one('hms.patient')

    # @api.constrains('related_patient_id')
    # def validate_email(self):
    #     if self.related_patient_id.email != self.email:
    #         raise exceptions.ValidationError('Can\'t link a with a patient with different email!')

    @api.constrains("patient_id")
    def check_valid_email(self):
        for record in self:
            if record.patient_id.email != record.email:
                if self.env['hms.patient'].search([('email', '=', record.email)]):
                    raise UserError("you can't choose this patient")

    def unlink(self):
        if self.related_patient_id:
            raise exceptions.UserError('Can\'t Delete this record related to a patient!')
        return super(HmsCustomerInheritance, self).unlink()
