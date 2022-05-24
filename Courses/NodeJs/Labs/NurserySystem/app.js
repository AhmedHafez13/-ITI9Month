const express = require('express');
const bodyParser = require("body-parser")
const cors = require('cors')
const morgan = require('morgan')
const mongoose = require("mongoose");

const AuthRoutes = require('./Routes/AuthRoutes');
const TeacherRoutes = require('./Routes/TeacherRoutes');
const StudentRoutes = require('./Routes/ChildRoutes');
const ClassRoutes = require('./Routes/ClassRoutes');

const PORT = process.env.PORT || 8080;

// -----* ----- * ----- * -----

// Open the server
const server = express();

// CORS-enabled for all origins and for all routes
server.use(cors())

// -----* ----- * ----- * -----

// Database Connection
mongoose.connect("mongodb://localhost:27017/OSDB")
  .then(() => {
    console.log("DB connected...")

    server.listen(PORT, function () {
      console.log(`CORS-enabled web server listening on port ${PORT}`)
    })
  })
  .catch(error => {
    console.log(error + "");
  })

// -----* ----- * ----- * -----

// HTTP request logger middleware
server.use(morgan('tiny'));

// -----* ----- * ----- * -----

// Parsing middleware
server.use(bodyParser.urlencoded({ extended: false }));
server.use(bodyParser.json());

// -----* ----- * ----- * -----

// Routes
server.use(AuthRoutes)
server.use("/teachers", TeacherRoutes)
server.use("/child", StudentRoutes)
server.use("/class", ClassRoutes)

// -----* ----- * ----- * -----

// Not Found
server.use((request, response) => {
  response.status(404).json({ message: "The url doesn't match any valid endpoint" })
});

// Errors
server.use((error, request, response, next) => {
  response.status(error.status || 500).json({ message: error + "" })
});
