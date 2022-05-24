int main() {
    cout << endl << "Create a Student and print it" << endl;

    Student s1;
    s1.setGrade('A');

    // Inherited attributes, and function from Person Class
    s1.setId(111);
    s1.setName("Ahmed");
    s1.setAge(25);

    s1.print();
  
  	// ----- * ----- * ----- * -----
  
    cout << endl << "Create a Employee and print it" << endl;

    Employee employee1;
    employee1.setSalary(40000);

    // Inherited attributes, and function from Person Class
    employee1.setId(222);
    employee1.setName("Mohamed");
    employee1.setAge(54);

    employee1.print();
  
  	// ----- * ----- * ----- * -----
  	
  	cout << endl << "Create a Pointer pointing to a Student" << endl;

    Student s2;
    Student* strPtr = &s2;

    strPtr->setGrade('A');

    // Inherited attributes, and function from Person Class
    strPtr->setId(111);
    strPtr->setName("Ali");
    strPtr->setAge(27);

    strPtr->print();
  
  	return 0;
}
