#include <iostream>

using namespace std;

class Stack {
    int * arr;
    int tos;
    int arrSize;
    // push
    // pop
public:
    Stack() {
        tos = -1;
        arrSize = 5;
        arr = new int(arrSize);
    }

    Stack(int _size) {
        tos = -1;
        arrSize = _size;
        arr = new int(_size);
    }

    ~Stack() {
        delete[] arr;
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
            // This will return a rubbish data we need a solution
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;

    // Create a new stack
    Stack s1;

    s1.push(11);
    s1.push(22);
    s1.push(33);
    s1.push(44);
    s1.push(55);
    s1.push(66);

    cout << endl << s1.pop();
    cout << endl << s1.pop();
    cout << endl << s1.pop();
    cout << endl << s1.pop();
    cout << endl << s1.pop();
    cout << endl << s1.pop();

    return 0;
}
