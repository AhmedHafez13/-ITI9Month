const Class = require("./../Models/Class");

exports.getAll = (request, response, next) => {
  Class.find({})
    .then(data => {
      response.status(200).json({ data })
    })
    .catch(error => next(error));
}

exports.get = (request, response, next) => {
  let id = request.params.id;

  Class.findById(id).populate([{ path: "teacher" }, { path: "children" }])
    .then(data => {
      response.status(200).json({ data })
    })
    .catch(error => next(error));
}

exports.create = (request, response, next) => {
  let newClass = new Class({
    name: request.body.name,
    teacher: request.body.teacher,
    children: request.body.children
  });

  newClass.save()
    .then((data) => {
      response.status(201).json({ message: "Class Created", data });
    })
    .catch(error => next(error));
}

exports.update = (request, response, next) => {
  let id = request.params.id;

  Class.findById(id)
    .then(object => {
      if (object == null) {
        let error = new Error("Class Not Found");
        error.status = 404;
        throw error;
      }

      object.name = request.body.name;
      object.teacher = request.body.teacher;
      object.children = request.body.children;

      return object.save()
    })
    .then(data => {
      response.status(200).json({ message: "Class Updated", data });
    })
    .catch(error => next(error));
}

exports.delete = (request, response, next) => {
  let id = request.params.id;

  Class.findById(id)
    .then(object => {
      if (object == null) {
        let error = new Error("Class Not Found");
        error.status = 404;
        throw error;
      }

      return object.delete()
    })
    .then(data => {
      response.status(200).json({ message: "Class Updated", data });
    })
    .catch(error => next(error))
}

exports.getClassChildred = (request, response, next) => {
  let id = request.params.id;

  Class.find({ _id: id }, { _id: false, children: true })
    .populate({ path: "children" })
    .then(object => {
      console.log(object);
      if (object == null || object.length == 0) {
        let error = new Error(`Class with id: ${id} Not Found`);
        error.status = 404;
        throw error;
      }

      return object;
    })
    .then(data => {
      response.status(200).json({ data: data[0].children })
    })
    .catch(error => next(error));
}

exports.getClassTeacher = (request, response, next) => {
  let id = request.params.id;

  Class.find({ _id: id }, { _id: false, children: true })
    .populate({ path: "teacher" })
    .then(object => {
      console.log(object);
      if (object == null || object.length == 0) {
        let error = new Error(`Class with id: ${id} Not Found`);
        error.status = 404;
        throw error;
      }

      return object;
    })
    .then(data => {
      response.status(200).json({ data: data[0].teacher })
    })
    .catch(error => next(error));
}
