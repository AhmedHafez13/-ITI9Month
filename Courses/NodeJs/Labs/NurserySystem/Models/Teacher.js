const mongoose = require("mongoose");

const TeacherSchema = new mongoose.Schema({
  fullName: String,
  email: String,
  password: String,
  image: String,
});

module.exports = mongoose.model("teachers", TeacherSchema);