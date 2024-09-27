#include <iostream>
using namespace std;


class NabeedAli_Lab03{
private:
    int top;
    char *stack;
    int capacity = 5;


public:
    NabeedAli_Lab03(){
        top = -1;
        stack = new char[capacity];
    }


    ~NabeedAli_Lab03(){
        delete[] stack;
    }


    void push(char x){
        if (top == capacity - 1)
        {
            resize();
        }
        top++;
        stack[top] = x;
    }


    void pop(){
        if (top == -1)
        {
            cout << "Stack underflow." << endl;
            return;
        }
        top--;
    }


    char peek(){
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return stack[top];
    }


    bool isEmpty(){
        return (top == -1);
    }


    void resize(){
        char *newStack = new char[capacity * 2];
        for (int i = 0; i <= top; i++)
        {
            newStack[i] = stack[i];
        }
        delete[] stack;
        stack = newStack;
        capacity *= 2;
    }
};
int main(){
    string org;
    cout << "Enter a phrase: ";
    cin >> org;
    NabeedAli_Lab03 S;
    for (int i = 0; i < org.length(); i++){
        S.push(org[i]);
    }


    string ans = "";
    for (int i = 0; i < org.length(); i++){
        ans += S.peek();
        S.pop();
    }


    if (org == ans){
        cout << "Your entered string is Palindrome";
    }
    else{
        cout << "Your entered string is not Palindrome";
    }
    return 0;
}