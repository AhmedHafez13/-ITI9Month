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

    int getTos() {
        return tos;
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
    Stack s1, s2(3), s3(10), s4;

    cout << "\n\n=> s1 size: " << s1.getSize() << "s1 tos: " << s1.getTos();

    cout << "\n\n=> s2 size: " << s2.getSize() << "s2 tos: " << s2.getTos();

    cout << "\n\n=> s3 size: " << s3.getSize() << "s3 tos: " << s3.getTos();

    cout << "\n\n=> s4 size: " << s4.getSize() << "s4 tos: " << s4.getTos();

    cout << "\nSet s3 = s1 + s2";
    s3 = s1 + s2;

    cout << "\nSet s4 = s2";
    s4 = s2;

    cout << "\n\n=> s1 size: " << s1.getSize() << "s1 tos: " << s1.getTos();

    cout << "\n\n=> s2 size: " << s2.getSize() << "s2 tos: " << s2.getTos();

    cout << "\n\n=> s3 size: " << s3.getSize() << "s3 tos: " << s3.getTos();

    cout << "\n\n=> s4 size: " << s4.getSize() << "s4 tos: " << s4.getTos();

    cout << endl;

    return 0;
}
