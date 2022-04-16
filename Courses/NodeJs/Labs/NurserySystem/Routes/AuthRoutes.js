const express = require("express");
const { body, param, query } = require("express-validator");

const { handleValidationErrors } = require("../Middleware/ValidationErrorHandler")
const AuthController = require("../Controllers/AuthController");
const TeacherController = require("../Controllers/TeacherController");

const loginValidationRules = [
  body("email").isEmail().withMessage("Email is not valid"),
  body("password").exists().withMessage("Password is required"),
];

const registerValidationRules = [
  body("fullName").isAlpha('en-US', { ignore: ' ' }).withMessage("Full name must be string"),
  body("email").isEmail().withMessage("Email is not valid"),
  body("password").isStrongPassword().withMessage("Password is weak"),
  body("image").isAlpha().withMessage("Image must be string"),
];

const router = express.Router();

router.route("/login")
  .post(loginValidationRules, handleValidationErrors, AuthController.login);

router.route("/register")
  .post(registerValidationRules, handleValidationErrors, TeacherController.create);

module.exports = router;