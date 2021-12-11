class Employee {
    int id;
    char name[30];
  	int age;

public:
  	// Constructor with parameters
    Employee(int _id, char * name, int _age) {
        id = _id;	// id should be initialized just one time         
      	strcpy(name, _name);
        age = _age;
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
  
  // You can create a new object by passing parameters
  //            ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
  Employee emp2(11, "Hamada", 25);
  
  return 0;
}