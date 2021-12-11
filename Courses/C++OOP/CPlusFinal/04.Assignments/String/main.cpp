#include <iostream>
#include <string.h>

using namespace std;

class String {
    char* text;

public:
    String() {
        text = new char[0];
        strcpy(text, "");
    }

    String(char* _text) {
        int length = strlen(_text);
        text = new char[length];
        strcpy(text, _text);
    }

    String(const String& s) {
        int length = strlen(s.text);
        text = new char[length];
        strcpy(text, s.text);
    }

    String& operator=(const String& s) {
        delete[] text;
        int length = strlen(s.text);
        text = new char[length];
        strcpy(text, s.text);
        return *this;
    }

    String& operator=(const char* _text) {
        delete[] text;
        int length = strlen(_text);
        text = new char[length];
        strcpy(text, _text);
        return *this;
    }

    String operator+(const String& s) {
        int length = strlen(text) + strlen(s.text);
        char* result = new char[length];
        strcpy(result, text);
        strcat(result, s.text);
        String temp(result);
        return temp;
    }

    String operator+(const char* _text) {
        int length = strlen(text) + strlen(_text);
        char* result = new char[length];
        strcpy(result, text);
        strcat(result, _text);
        String temp(result);
        return temp;
    }

    String& operator+=(const String& s) {
        int length = strlen(text) + strlen(s.text);
        char* result = new char[length];
        strcpy(result, text);
        strcat(result, s.text);
        delete[] text;
        text = result;
        return *this;
    }

    friend ostream &operator<<(ostream &output, const String& s) {
        output << s.text;
        return output;
    }

    friend istream &operator>>(istream  &input, String& s) {
        input >> s.text;
        return input;
    }

    int length() {
        return strlen(text);
    }

    //friend String operator+(const char* text1,const char* text2);
    friend String operator+(char* text, String& s) ;
};

String operator+(char* text, String& s) {
    int length = strlen(text) + strlen(s.text);
    char* result = new char[length];
    strcpy(result, text);
    strcat(result, s.text);
    String temp(result);
    return temp;
}

int main() {
    String s1;

    s1 = "Ahmed"; // length of s1 = 5

    cout << endl << "s1: " << s1 << endl;

    s1 = "Mahmoud"; // length of s1 = 7

    cout << endl << "s1: " << s1 << endl;

    String s2 = s1 + " Ali"; // length of s2 = 7 + 4 = 11

    cout << endl << "s2: " << s2 << endl;

    s2 += " Kareem"; // length of s2 = 11 + 7 = 18

    cout << endl << "s2: " << s2 << endl;

    String s3;
    s3 += s1; // length of s3 = 7

    cout << endl << "s3: " << s3 << endl;


    cout << endl << endl << "Lengths: " << endl;
    cout << "Length of s1: " << s1.length() << endl;
    cout << "Length of s2: " << s2.length() << endl;
    cout << "Length of s3: " << s3.length() << endl << endl;


    /* operator+ Stand Alone Function */
    String s4 = " Mohamed";
    String s5 = "Ziad" + s4;

    cout << endl << "s5: " << s5 << endl;

    return 0;
}
