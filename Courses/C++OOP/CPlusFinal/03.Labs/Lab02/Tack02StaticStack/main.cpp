#include <iostream>

using namespace std;

class Stack {
    int arr[5];
    int tos;
    int arrSize;
public:
    Stack() {
        tos = -1;
        arrSize = 5;
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
};

int main()
{
    cout << endl << "------------------------" << endl;
    cout << "Stack, Statically allocated";
    cout << endl << "------------------------" << endl;

    // Create a new stack
    Stack s1;

    s1.push(11);
    s1.push(22);
    s1.push(-1);
    s1.push(44);

    for (int i = 0; i < 6; i++) {
        if (s1.hasItems()) {
            cout << endl << s1.pop();
        }
    }

    return 0;
}
