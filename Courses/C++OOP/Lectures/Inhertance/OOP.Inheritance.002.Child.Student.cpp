// ----- * ----- Student Class ----- * ----- //
class Student : public Person {
    char grade;

public:
    void setGrade(char _grade) {
        grade = _grade;
    }
    char getGrade() {
        return grade;
    }

    void print() {
        Person::print();

        cout << ", grade: " << grade;
    }
};