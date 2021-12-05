// ----- * ----- Person Class ----- * ----- //
class Person {
    int id;
    char name[20];
    int age;

public:
    void setId(int _id) {
        id = _id;
    }
    int getId() {
        return id;
    }

    void setName(char* _name) {
        strcpy(name, _name);
    }
    char* getName() {
        return name;
    }

    void setAge(int _age) {
        age = _age;
    }
    int getAge() {
        return age;
    }

    void print() {
        cout << endl << "id: " << id
                     << ", name: " << name
                     << ", age: " << age;
    }
};