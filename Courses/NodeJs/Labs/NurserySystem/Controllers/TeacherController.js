const Teacher = require("./../Models/Teacher");

exports.getAll = (request, response, next) => {
  Teacher.find({})
    .then(data => {
      response.status(200).json({ data })
    })
    .catch(error => next(error));
}

exports.get = (request, response, next) => {
  let id = request.params.id;

  Teacher.findById(id)
    .then(data => {
      response.status(200).json({ data })
    })
    .catch(error => next(error));
}

exports.create = (request, response, next) => {
  let teacher = new Teacher({
    // _id: new Types.ObjectId(),
    fullName: request.body.fullName,
    email: request.body.email,
    password: request.body.password,
    image: request.body.image
  });

  teacher.save()
    .then((data) => {
      response.status(201).json({ message: "Teacher Created", data });
    })
    .catch(error => next(error));
}

exports.update = (request, response, next) => {
  let id = request.params.id;

  Teacher.findById(id)
    .then(object => {
      if (object == null) {
        let error = new Error("Teacher Not Found");
        error.status = 404;
        throw error;
      }

      object.fullName = request.body.fullName;
      object.email = request.body.email;
      object.password = request.body.password;
      object.image = request.body.image;

      return object.save()
    })
    .then(data => {
      response.status(200).json({ message: "Teacher Updated", data });
    })
    .catch(error => next(error));
}

exports.delete = (request, response, next) => {
  let id = request.params.id;

  Teacher.findById(id)
    .then(object => {
      if (object == null) {
        let error = new Error("Teacher Not Found");
        error.status = 404;
        throw error;
      }

      return object.delete()
    })
    .then(data => {
      response.status(200).json({ message: "Teacher Updated", data });
    })
    .catch(error => next(error))
}
