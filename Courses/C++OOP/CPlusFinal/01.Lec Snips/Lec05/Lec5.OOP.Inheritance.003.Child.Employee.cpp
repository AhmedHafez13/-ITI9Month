// ----- * ----- Employee Class ----- * ----- //
class Employee : public Person {
    int salary;

public:
    void setSalary(int _salary) {
        salary = _salary;
    }
    int getSalary() {
        return salary;
    }

    void print() {
        Person::print();

        cout << ", salary: " << salary;
    }
};