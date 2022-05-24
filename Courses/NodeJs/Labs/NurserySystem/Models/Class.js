const mongoose = require("mongoose");
const AutoIncrement = require('mongoose-sequence')(mongoose);

const ClassSchema = new mongoose.Schema({
  _id: Number,
  name: String,
  teacher: { type: Object, ref: "teachers" },
  children: [{ type: Number, ref: "child" }],
});

ClassSchema.plugin(AutoIncrement, { id: "class_id_counter" });

module.exports = mongoose.model("classes", ClassSchema);