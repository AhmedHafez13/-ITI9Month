const express = require("express");
const { body, param, query } = require("express-validator");

const { handleValidationErrors } = require("../Middleware/ValidationErrorHandler")
const TeacherController = require("../Controllers/TeacherController");

const postValidationRules = [
  body("fullName").isAlpha('en-US', { ignore: ' ' }).withMessage("Full name must be string"),
  body("email").isEmail().withMessage("Email is not valid"),
  body("password").isStrongPassword().withMessage("Password is weak"),
  body("image").isAlpha().withMessage("Image must be string"),
];

const updateValidationRules = [
  param("id").isMongoId().withMessage("Teacher id is not valid"), // other id validations
  ...postValidationRules
]

const router = express.Router();

router.route("/")
  .get(TeacherController.getAll)
  .post(TeacherController.create)
  //.post(postValidationRules, handleValidationErrors, TeacherController.create);

router.route("/:id")
  .get(TeacherController.get)
  .put(updateValidationRules, handleValidationErrors, TeacherController.update)
  .delete(TeacherController.delete)

module.exports = router;
