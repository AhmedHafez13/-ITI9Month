class Employee {
    int id;
    char name[30];
  	int age;

public:
  	// Constructor with 1 parameters
  	Employee(int _id) {
      	// id should be initialized just one time
      	// id will not be allowed to change after creatin the object         
        id = _id;
    }
  
  	// Constructor with 3 parameters
    Employee(int _id, char * name, int _age) {
      	// id should be initialized just one time
      	// id will not be allowed to change after creatin the object        
        id = _id;
      	strcpy(name, _name);
        age = _age;
    }
  
    void getId() {
      	return id;
    }

    void setAge(int _age) {
        age = _age;
    }

    int getAge() {
        return age;
    }
  
  	void setName(char * _name) {
      	strcpy(name, _name);
    }
  
  	char * getName() {
      	return name;
    }
};

int main() {
  // Can't create a new object withou parameters
  // ↓↓↓↓↓↓↓↓↓↓
  Employee emp1; 	// <- Compline Error
  
  // You can create a new object by passing 1 parameter
  //           ↓↓↓↓
  Employee emp2(11);
  
  // You can create a new object by passing 3 parameters
  //            ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
  Employee emp2(11, "Hamada", 25);
  
  return 0;
}