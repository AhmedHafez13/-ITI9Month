const express = require("express");
const { body, param, query } = require("express-validator");

const { handleValidationErrors } = require("../Middleware/ValidationErrorHandler")
const ClassController = require("../Controllers/ClassController");

const postValidationRules = [
  body("name").isAlphanumeric('en-US', {ignore: ' '}).withMessage("Class name must be string"),
  body("teacher").isMongoId().withMessage("Teacher id is invalid"),
  body("children").isArray().withMessage("Children must be array of ids")
];

const updateValidationRules = [
  param("id").isNumeric().withMessage("Class id is required"), // other id validations
  ...postValidationRules
]

const router = express.Router();

router.route("/")
  .get(ClassController.getAll)
  .post(postValidationRules, handleValidationErrors, ClassController.create);

// router.route("/\/([^\/]+)\/?/")
router.route("/:id(\\d+)/")
  .get(ClassController.get)
  .put(updateValidationRules, handleValidationErrors, ClassController.update)
  .delete(ClassController.delete)

router.route("/:id/childred")
  .get(ClassController.getClassChildred);

router.route("/:id/teacher")
  .get(ClassController.getClassTeacher);

module.exports = router;
