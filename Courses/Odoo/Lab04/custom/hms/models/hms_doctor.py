from odoo import models, fields


class HmsDoctor(models.Model):
    _name = "hms.doctor"

    first_name = fields.Char()
    last_name = fields.Char()
    image = fields.Image()

    _rec_name = "first_name"
