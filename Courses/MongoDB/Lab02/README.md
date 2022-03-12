# MongoDB Lab 2 - 2022.03.12

```bash
$ cd {path/to/data}

$ mongod --dbpath .

$ mongo
```

## 1. Using aggregation display the sum of final mark for all courses in Course collection.

```bash
> db.course.aggregate(
   [
     {
       $group:
         {
           _id: null,
           sumOfFinalMarks: { $sum: "$mark" }
         }
     }
   ]
)
{ "_id" : null, "sumOfFinalMarks" : 300 }
```

---

## 2. Display the count of students (use Group by with \_id: null, to not specify grouping column).

```bash
> db.student.aggregate(
   [
     { $group: { _id: null, studentsCount: { $sum: 1 } } }
   ]
)
{ "_id" : null, "studentsCount" : 3 }
```

---

## 3. Implement Embedded modeling between Student and Course, by adding array of Courses in the student object.

```bash
> db.student.insertMany([
    {
        "FirstName": "Mohamed",
        "LastName": "Tarek",
        "isFired": false,
        "FacultyID": 20,
        "Courses": [
            {"CourseId": 4, "Grade": "C"},
            {"CourseId": 5, "Grade": "A"},
            {"CourseId": 1, "Grade": "B"}
        ],
    },
    {
        "FirstName": "Ali",
        "LastName": "Ibrahim",
        "isFired": false,
        "FacultyID": 10,
        "Courses": [
            {"CourseId": 4, "Grade": "F"},
            {"CourseId": 5, "Grade": "C"},
            {"CourseId": 1, "Grade": "B"}
        ],
    }
])
```

### 3.1 Write a query to select courses of specific student.

```bash
> db.student.find(
    { "FirstName" : "Mohamed" },
    { _id : 0, Courses : 1 }
).pretty()

{
    "Courses" : [
        { "CourseId" : 4, "Grade" : "C" },
        { "CourseId" : 5, "Grade" : "A" },
        { "CourseId" : 1, "Grade" : "B" }
    ]
}
```

---

## 4. Implement referenced modeling (Manual references) between Student and faculty by adding the faculty id in student object

```bash
> db.student.updateMany(
...     { FacultyID : 10 },
...     { $set: { FacultyID : ObjectId("622b794e21c0562fe9e8d5e6") } }
... )
WriteResult({ "nMatched" : 1, "nUpserted" : 0, "nModified" : 1 })
```

```bash
> db.student.updateMany(
...     { FacultyID: 10 },
...     { $set: { FacultyID: ObjectId("622b794e21c0562fe9e8d5e7") }}
... )
{ "acknowledged" : true, "matchedCount" : 2, "modifiedCount" : 2 }
```

### 4.1 Select specific student with his name, and then display his faculty

```bash
> var student = db.student.findOne(
    { FirstName: "Ahmed" }, { FacultyID: 1 }
)

> db.faculty.find( { _id: student.FacultyID } ).pretty()
{
    "_id" : ObjectId("622b794e21c0562fe9e8d5e7"),
    "name" : "Computer Science",
    "address" : "Cairo"
}
```

---

## 5. In previous relation, use DbRefs and replace faculty id with faculty object containing $ref, $id

Update students

```bash
> db.student.updateOne(
...    { FirstName : "Ahmed" },
...    {
...        $set: {
...            Faculty : {
...                 $ref : "faculty",
...                 $id : ObjectId("622b794e21c0562fe9e8d5e6"),
...                 $db : "FacultySystemDBV2"
...             }
...        }
...    }
... )
{ "acknowledged" : true, "matchedCount" : 1, "modifiedCount" : 1 }
```

```bash
> db.student.updateOne(
...    { FirstName : "Mohamed" },
...    {
...        $set: {
...            Faculty : {
...                 $ref : "faculty",
...                 $id : ObjectId("622b794e21c0562fe9e8d5e7"),
...                 $db : "FacultySystemDBV2"
...             }
...        }
...    }
... )
{ "acknowledged" : true, "matchedCount" : 1, "modifiedCount" : 1 }
```

Get students with first name and faculity

```bash
> db.student.find( { }, { _id : 0, FirstName : 1 , Faculty : 1 } ).pretty()
{
    "FirstName" : "Ahmed",
    "Faculty" : DBRef("faculty", ObjectId("622b794e21c0562fe9e8d5e6"), "FacultySystemDBV2")
}
{
    "FirstName" : "Mohamed",
    "Faculty" : DBRef("faculty", ObjectId("622b794e21c0562fe9e8d5e7"), "FacultySystemDBV2")
}
{
    "FirstName" : "Ali",
    "Faculty" : DBRef("faculty", ObjectId("622b794e21c0562fe9e8d5e6"), "FacultySystemDBV2")
}
>
```

### 5.1 Select specific student with his name, and then display his faculty

```bash
> var student = db.student.findOne( { FirstName : "Ahmed" } );
> var facultyRef = student.Faculty;
> db[facultyRef.$ref].find( { _id : facultyRef.$id } ).pretty();
{
    "_id" : ObjectId("622b794e21c0562fe9e8d5e6"),
    "name" : "Engineering",
    "address" : "Mans"
}
```
