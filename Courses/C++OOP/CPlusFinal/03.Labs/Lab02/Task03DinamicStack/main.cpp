#include <iostream>

using namespace std;

class Stack {
    int * arr;
    int tos;
    int arrSize;
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
            // This will return a rubbish data we need a solution
        }
    }
};

int main()
{
    cout << endl << "------------------------" << endl;
    cout << "Stack, Dynamically allocated";
    cout << endl << "------------------------" << endl;

    // Create a new stack
    Stack s1, s2(3), s3(10);

    cout << "\n\n=> s1 size: " << s1.getSize();

    cout << "\n\n=> s2 size: " << s2.getSize();

    cout << "\n\n=> s3 size: " << s3.getSize();

    cout << endl;

    return 0;
}
