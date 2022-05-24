{
    'name': 'HMS Module',
    'version': '1.0',
    'category': 'Custom Modules',
    'description': "Hospitals Management System",
    'depends': ["crm"],
    'data': [
        'security/hms_security.xml',
        'security/ir.model.access.csv',
        'views/hms_patient_views.xml',
        'views/hms_department_views.xml',
        'views/hms_doctor_views.xml',
        'views/hms_customer_views.xml',
        'reports/hms_reports.xml',
        'reports/hms_templates.xml',
    ]
}
