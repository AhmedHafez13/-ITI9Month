const Child = require("./../Models/Child");

exports.getAll = (request, response, next) => {
  Child.find({})
    .then(data => {
      response.status(200).json({ data })
    })
    .catch(error => next(error));
}

exports.get = (request, response, next) => {
  let id = request.params.id;

  Child.findById(id)
    .then(data => {
      response.status(200).json({ data })
    })
    .catch(error => next(error));
}

exports.create = (request, response, next) => {
  let child = new Child({
    _id: request.body.id,
    fullName: request.body.fullName,
    age: request.body.age,
    level: request.body.level,
    address: request.body.address
  });

  child.save()
    .then((data) => {
      response.status(201).json({ message: "Child Created", data });
    })
    .catch(error => next(error));
}

exports.update = (request, response, next) => {
  let id = request.params.id;

  Child.findById(id)
    .then(object => {
      if (object == null) {
        let error = new Error("Child Not Found");
        error.status = 404;
        throw error;
      }

      object.fullName = request.body.fullName;
      object.age = request.body.age;
      object.level = request.body.level;
      object.address = request.body.address;

      return object.save()
    })
    .then(data => {
      response.status(200).json({ message: "Child Updated", data });
    })
    .catch(error => next(error))
}

exports.delete = (request, response, next) => {
  let id = request.params.id;

  Child.findById(id)
    .then(object => {
      if (object == null) {
        let error = new Error("Child Not Found");
        error.status = 404;
        throw error;
      }

      return object.delete()
    })
    .then(data => {
      response.status(200).json({ message: "Child Updated", data });
    })
    .catch(error => next(error))
}
