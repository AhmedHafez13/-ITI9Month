const { validationResult } = require("express-validator");

exports.handleValidationErrors = (request, response, next) => {
  const validation = validationResult(request);
  if (!validation.isEmpty()) {
    let errorMessages = validation.array()
      .reduce((allErrors, error) => allErrors + error.msg + " ", "")
    let error = new Error(errorMessages);
    error.status = 422;
    throw error;
  }
  next();
}