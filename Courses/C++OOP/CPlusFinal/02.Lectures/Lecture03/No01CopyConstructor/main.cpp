#include <iostream>

using namespace std;

class Stack {
    int* arr;
    int tos;
    int arrSize;
public:
    Stack() { // <- Default constructor (parameterless)
        cout << "\n----- * Default constructor is called! * ----- ";
        tos = -1;
        arrSize = 5;
        arr = new int(arrSize);
    }

    Stack(int _size) {
        cout << "\n----- * Constructor is called! * ----- ";
        tos = -1;
        arrSize = _size;
        arr = new int(_size);
    }

    Stack (const Stack& s) {    // <- Copy constructor
        cout << "\n----- * Copy Constructor is called! * ----- ";
        tos = s.tos;
        arrSize = s.arrSize;
        arr = new int(arrSize);
        for (int i = 0; i < tos; i++) {
            arr[i] = s.arr[i];
        }
    }

    ~Stack() {  // Destructor
        cout << "\n----- * Destructor is called! * ----- ";
        delete[] arr;
    }

    int getSize() {
        return arrSize;
    }

    void push(int n) {
        if (tos < arrSize - 1) {
            tos++;
            arr[tos] = n;
            cout << endl << "Data is pushed: " << n;
        } else {
            cout << endl << "The stack is full!";
        }
    }

    int pop() {
        if (tos > -1) {
            int value = arr[tos];
            tos--;
            return value;
        } else {
            cout << endl << "Stack is empty";

        }
    }

    int hasItems() {
        if (tos > -1) {
            return 1;
        } else {
            return 0;
        }
    }

    friend void myFun(Stack s);
};

void myFun(Stack s) {
    cout << "\n\n=> myFun is called" << endl;

    Stack s2;
    Stack s4(3);

    int arrSize = s.arrSize;

    // Direct access; as myFun is a friend of class Stack
    cout << "\n\n=> size of s=" << arrSize << endl;
    cout << "\n\n=> TOS of s2=" << s2.tos << endl;

    cout << "\n\n=> end of (myFun)" << endl;
}

int main()
{
    cout << endl << "------------------------" << endl;
    cout << "Stack, Dynamically allocated";
    cout << endl << "------------------------" << endl;

    Stack s11;
    Stack s22(8);
    Stack s33(s22);

    cout << endl << "----------------******* s22: " << &s22; //0x6dfebc
    cout << endl << "----------------******* s33: " << &s33; //

    //s11.push(11);
    //s11.push(-1);
    //s11.push(22);
    //s11.push(-2);
    //s11.push(33);
    //s11.push(88888);

    //cout << "\n\npop all items";
    //while (s11.hasItems()) {
    //    cout << endl << s11.pop();
    //}

    //s11.pop();

    cout << "\n\n=> before calling (myFun)" << endl;

    myFun(s22);

    cout << "\n\n=> returned from (myFun)" << endl;

    return 0;
}
