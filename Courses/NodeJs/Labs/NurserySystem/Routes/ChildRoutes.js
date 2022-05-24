const express = require("express");
const { body, param, query } = require("express-validator");

const { handleValidationErrors } = require("../Middleware/ValidationErrorHandler")
const ChildController = require("../Controllers/ChildController");

const postValidationRules = [
  body("fullName").isAlpha('en-US', { ignore: ' ' })
    .withMessage("Child full name must be string"),
  body("age").isNumeric().withMessage("Child age is not valid"),
  body("level").isAlphanumeric().withMessage("Child level is not valid"),
  body("address.city").isAlpha().withMessage("Child city is not valid"),
  body("address.street").isAlpha().withMessage("Child street is not valid"),
  body("address.building").isAlphanumeric().withMessage("Child building is not valid"),
];

const updateValidationRules = [
  param("id").isNumeric().withMessage("Child id is required"), // other id validations
  ...postValidationRules
]

const router = express.Router();

router.route("/")
  .get(ChildController.getAll)
  .post(postValidationRules, handleValidationErrors, ChildController.create);

router.route("/:id")
  .get(ChildController.get)
  .put(updateValidationRules, handleValidationErrors, ChildController.update)
  .delete(ChildController.delete)

module.exports = router;
