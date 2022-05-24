const mongoose = require("mongoose");
const AutoIncrement = require('mongoose-sequence')(mongoose);

const AddressSchema = new mongoose.Schema({
  city: String,
  street: String,
  building: String,
})

const ChildSchema = new mongoose.Schema({
  _id: Number,
  fullName: String,
  age: Number,
  level: String,
  address: AddressSchema
});

ChildSchema.plugin(AutoIncrement, { id: "child_id_counter" });

module.exports = mongoose.model("child", ChildSchema);