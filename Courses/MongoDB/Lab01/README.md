# MongoDB Lab 1 - 2022.03.11

## Create new data folder

```bash
$ cd {path/to/data}

$ mongod --dbpath .

$ mongo
```

## 1. Create FacultySystemDB

```bash
> use FacultySystemDB
switched to db FacultySystemDB
```

## 2. Create `student` Collection

```bash
> db.createCollection("student")
{ "ok" : 1 }
```

```bash
> show collections
student
```

## 3. Insert documents into `student`

```bash
> db.student.insert({
        "FirstName": "Ahmed",
        "LastName": "Gamal",
        "Age": 20,
        "Faculty": {
            "Name": "Engineering",
            "Address": "Mans"
        },
        "Grads": [
            {"CourseName": "Networking", "Grade": "B", "Pass": true},
            {"CourseName": "Operating Systems", "Grade": "A", "Pass": true},
            {"CourseName": "MongoDB", "Grade": "F", "Pass": false}
        ],
        "isFired": true
    })
WriteResult({ "nInserted" : 1 })
```

```bash
> db.student.insert({
        "FirstName": "Ali",
        "LastName": "Salah",
        "Age": 30,
        "Faculty": {
            "Name": "Computer Science",
            "Address": "Tanta"
        },
        "Grads": [
            {"CourseName": "MySQL", "Grade": "A", "Pass": true},
            {"CourseName": "Admin 1", "Grade": "D", "Pass": true},
            {"CourseName": "MongoDB", "Grade": "B", "Pass": true}
        ],
        "isFired": false
    })
WriteResult({ "nInserted" : 1 })
```

```bash
> db.student.insert({
        "FirstName": "Ramy",
        "LastName": "Ibrahim",
        "Age": 29,
        "Faculty": {
            "Name": "Engineering",
            "Address": "Cairo"
        },
        "Grads": [
            {"CourseName": "HTML CSS", "Grade": "B", "Pass": true},
            {"CourseName": "Laravel", "Grade": "F", "Pass": false},
            {"CourseName": "MongoDB", "Grade": "C", "Pass": true}
        ],
        "isFired": false
    })
WriteResult({ "nInserted" : 1 })
```

```bash
> db.student.insert([{
        "FirstName": "stu41",
        "LastName": "stu42",
        "Age": 22,
        "Faculty": {
            "Name": "Eng1",
            "Address": "Cairo1"
        },
        "Grads": [
            {"CourseName": "HTML CSS", "Grade": "B", "Pass": true},
            {"CourseName": "Laravel", "Grade": "F", "Pass": false}
        ],
        "isFired": false
    },
    {
        "FirstName": "stu51",
        "LastName": "stu52",
        "Age": 32,
        "Faculty": {
            "Name": "Eng2",
            "Address": "Cairo2"
        },
        "Grads": [
            {"CourseName": "HTML CSS", "Grade": "B", "Pass": true},
            {"CourseName": "Laravel", "Grade": "F", "Pass": false}
        ],
        "isFired": true
    }])
BulkWriteResult({
        "writeErrors" : [ ],
        "writeConcernErrors" : [ ],
        "nInserted" : 2,
        "nUpserted" : 0,
        "nMatched" : 0,
        "nModified" : 0,
        "nRemoved" : 0,
        "upserted" : [ ]
})
```

## 4.1 All Students

```bash
db.student.find()
```

---

## 4.2 Student With `FirstName`

### Select `FirstName`

```bash
> db.student.find({}, {"FirstName": 1})
{ "_id" : ObjectId("622b6132c94c4c4f0dead470"), "FirstName" : "Ahmed" }
{ "_id" : ObjectId("622b6237c94c4c4f0dead471"), "FirstName" : "Ali" }
{ "_id" : ObjectId("622b623dc94c4c4f0dead472"), "FirstName" : "Ramy" }
{ "_id" : ObjectId("622b62d2c94c4c4f0dead473"), "FirstName" : "stu41" }
{ "_id" : ObjectId("622b62d2c94c4c4f0dead474"), "FirstName" : "stu51" }
```

### Select `FirstName` without `id`

```bash
> db.student.find({}, {"FirstName": 1, "_id": 0})
{ "FirstName" : "Ahmed" }
{ "FirstName" : "Ali" }
{ "FirstName" : "Ramy" }
{ "FirstName" : "stu41" }
{ "FirstName" : "stu51" }
```

### Select `FirstName` with value `Ahmed`

```bash
> db.student.find({"FirstName": "Ahmed"})
{ "_id" : ObjectId("622b6132c94c4c4f0dead470"), "FirstName" : "Ahmed", "LastName" : "Gamal", "Age" : 20, "Faculty" : { "Name" : "Engineering", "Address" : "Mans" }, "Grads" : [ { "CourseName" : "Networking", "Grade" : "B", "Pass" : true }, { "CourseName" : "Operating Systems", "Grade" : "A", "Pass" : true }, { "CourseName" : "MongoDB", "Grade" : "F", "Pass" : false } ], "isFired" : true }
```

---

## 4.3 Student With `FirstName` = `Ahmed` or `LastName` = `Ahmed`

```bash
> db.student.find({$or: [{"FirstName": "Ahmed"}, {"LastName": "Ahmed"}]})
{ "_id" : ObjectId("622b6132c94c4c4f0dead470"), "FirstName" : "Ahmed", "LastName" : "Gamal", "Age" : 20, "Faculty" : { "Name" : "Engineering", "Address" : "Mans" }, "Grads" : [ { "CourseName" : "Networking", "Grade" : "B", "Pass" : true }, { "CourseName" : "Operating Systems", "Grade" : "A", "Pass" : true }, { "CourseName" : "MongoDB", "Grade" : "F", "Pass" : false } ], "isFired" : true }
{ "_id" : ObjectId("622b65f4c94c4c4f0dead475"), "FirstName" : "Kamal", "LastName" : "Ahmed", "Age" : 19, "Faculty" : { "Name" : "Engineering", "Address" : "Cairo" }, "Grads" : [ { "CourseName" : "HTML CSS", "Grade" : "B", "Pass" : true }, { "CourseName" : "Laravel", "Grade" : "F", "Pass" : false }, { "CourseName" : "MongoDB", "Grade" : "C", "Pass" : true } ], "isFired" : false }
```

---

## 4.4 Student With `FirstName` != `Ahmed`

```bash
> db.student.find({ FirstName: { $ne: "Ahmed" } }, {FirstName: 1, LastName: 1, _id: 0})
{ "FirstName" : "Ali", "LastName" : "Salah" }
{ "FirstName" : "Ramy", "LastName" : "Ibrahim" }
{ "FirstName" : "stu41", "LastName" : "stu42" }
{ "FirstName" : "stu51", "LastName" : "stu52" }
{ "FirstName" : "Kamal", "LastName" : "Ahmed" }
```

---

## 4.5 Student With `Age` <= 21

```bash
> db.student.find({ }, { FirstName: 1, Age: 1, _id: 0 })
{ "FirstName" : "Ahmed", "Age" : 20 }
{ "FirstName" : "Ali", "Age" : 30 }
{ "FirstName" : "Ramy", "Age" : 29 }
{ "FirstName" : "stu41", "Age" : 22 }
{ "FirstName" : "stu51", "Age" : 32 }
{ "FirstName" : "Kamal", "Age" : 19 }
```

```bash
> db.student.find({ Age: { $lt: 21 } }, { FirstName: 1, Age: 1, _id: 0 })
{ "FirstName" : "Ahmed", "Age" : 20 }
{ "FirstName" : "Kamal", "Age" : 19 }
```

---

## 4.6 All fired students

```bash
> db.student.find({ }, { FirstName: 1, isFired: 1, _id: 0 })
{ "FirstName" : "Ahmed", "isFired" : true }
{ "FirstName" : "Ali", "isFired" : false }
{ "FirstName" : "Ramy", "isFired" : false }
{ "FirstName" : "stu41", "isFired" : false }
{ "FirstName" : "stu51", "isFired" : true }
{ "FirstName" : "Kamal", "isFired" : false }
```

```bash
> db.student.find({ isFired: true }, { FirstName: 1, isFired: 1, _id: 0 })
{ "FirstName" : "Ahmed", "isFired" : true }
{ "FirstName" : "stu51", "isFired" : true }
```

---

## 4.7 Studens with (`Age` >= 21 and `Faculty` != NULL)

```bash
> db.student.find({ $and: [{ Age: { $gte: 21 } } , {Faculty: { $ne: null }}] }, { Age: 1, Faculty: 1, _id: 0 })
{ "Age" : 30, "Faculty" : { "Name" : "Computer Science", "Address" : "Tanta" } }
{ "Age" : 29, "Faculty" : { "Name" : "Engineering", "Address" : "Cairo" } }
{ "Age" : 22, "Faculty" : { "Name" : "Eng1", "Address" : "Cairo1" } }
{ "Age" : 32, "Faculty" : { "Name" : "Eng2", "Address" : "Cairo2" } }
```

---

## 4.8 Studens with (`Age` >= 21 and `Faculty` != NULL)

```bash
> db.student.find({ FirstName: "Ahmed", isFired: true }, { FirstName: 1, isFired: 1, _id: 0 })
{ "FirstName" : "Ahmed", "isFired" : true }
```

---

## 5 Update `LastName` of student with `FirstName` = `Ahmed`

```bash
> db.student.updateOne(
...    { FirstName: "Ahmed" },
...    {
...      $set: { "LastName": "Changed" },
...      $currentDate: { lastModified: true }
...    }
... )
{ "acknowledged" : true, "matchedCount" : 1, "modifiedCount" : 1 }
```

```bash
> db.student.find({ FirstName: "Ahmed" }, { FirstName: 1, LastName: 1, _id: 0 })
{ "FirstName" : "Ahmed", "LastName" : "Changed" }
```

---

## 6 Delete students with `isFired` = `true`

```bash
> db.student.find({ }, { FirstName: 1, isFired: 1, _id: 0 })
{ "FirstName" : "Ahmed", "isFired" : true }
{ "FirstName" : "Ali", "isFired" : false }
{ "FirstName" : "Ramy", "isFired" : false }
{ "FirstName" : "stu41", "isFired" : false }
{ "FirstName" : "stu51", "isFired" : true }
```

```bash
> db.student.remove( { isFired: true } )
WriteResult({ "nRemoved" : 2 })
```

```bash
> db.student.find({ }, { FirstName: 1, isFired: 1, _id: 0 })
{ "FirstName" : "Ali", "isFired" : false }
{ "FirstName" : "Ramy", "isFired" : false }
{ "FirstName" : "stu41", "isFired" : false }
```

---

## 7 Delete the database

```bash
> db.student.drop()
> true
```

---

## 8 Delete the database

```bash
> db.dropDatabase()
{ "ok" : 1 }
```

---

## 9 Create database `FacultySystemDBV2`

```bash
> use FacultySystemDBV2
switched to db FacultySystemDBV2
```

### 9.1 collection `student`

```bash
> db.createCollection("student")
{ "ok" : 1 }
```

```bash
> db.student.insert({
        "FirstName": "Ahmed",
        "LastName": "Gamal",
        "isFired": true,
        "FacultyID": 10,
        "Courses": [
            {"CourseId": 4, "Grade": "B"},
            {"CourseId": 5, "Grade": "A"},
            {"CourseId": 1, "Grade": "F"}
        ],
    })
WriteResult({ "nInserted" : 1 })
```

```bash
> db.student.find()
{ "_id" : ObjectId("622b787e21c0562fe9e8d5e5"), "FirstName" : "Ahmed", "LastName" : "Gamal", "isFired" : true, "FacultyID" : 10, "Courses" : [ { "CourseId" : 4, "Grade" : "B" }, { "CourseId" : 5, "Grade" : "A" }, { "CourseId" : 1, "Grade" : "F" } ] }
```

---

### 9.2 collection `faculty`

```bash
> db.createCollection("faculty")
{ "ok" : 1 }
```

```bash
> db.faculty.insertMany([
    {
        "name": "Engineering",
        "address": "Mans"
    },
    {
        "name": "Computer Science",
        "address": "Cairo"
    }
    ])
"acknowledged" : true,
"insertedIds" : [
        ObjectId("622b794e21c0562fe9e8d5e6"),
        ObjectId("622b794e21c0562fe9e8d5e7")
]
```

---

### 9.3 Course `course`

```bash
> db.createCollection("course")
{ "ok" : 1 }
```

```bash
> db.course.insertMany([
    {
        "name": "Networking",
        "mark": 100
    },
    {
        "name": "MongoDB",
        "mark": 120
    },
    {
        "name": "NodeJS",
        "mark": 80
    }
    ])
"acknowledged" : true,
"insertedIds" : [
        ObjectId("622b79b121c0562fe9e8d5e8"),
        ObjectId("622b79b121c0562fe9e8d5e9")
]
```
