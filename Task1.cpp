#include <iostream>
using namespace std;


class NabeedAli_Lab03{
private:
    int top;
    int *stack;
    int capacity = 5;


public:
    NabeedAli_Lab03(){
        top = -1;
        stack = new int[capacity];
    }


    ~NabeedAli_Lab03(){
        delete[] stack;
    }


    void push(int x){
        if (top == capacity - 1){
            resize();
        }
        top++;
        stack[top] = x;
    }
    void pop(){
        if (top == -1){
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
    }


    int peek(){
        if (top == -1){
            cout << "Stack is empty." << endl;
            return -1;
        }
        return stack[top];
    }


    bool isEmpty(){
        return (top == -1);
    }


    int size(){
        return top + 1;
    }


    void resize(){
        int *newStack = new int[capacity * 2];
        for (int i = 0; i <= top; i++)
        {
            newStack[i] = stack[i];
        }
        delete[] stack;
        stack = newStack;
        capacity *= 2;
    }


    void display(){
        if (top == -1){
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++){
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    NabeedAli_Lab03 org;


    org.push(1);
    org.push(2);
    org.push(3);
    org.push(4);
    org.push(5);


    org.display();


    org.pop();
    org.display();


    int t = org.peek();
    if (t != -1){
        cout << "Peek element is: " << t << endl;
    }
    if (org.isEmpty()){
        cout << "Stack is empty." << endl;
    }
    else{
        cout << "Stack contains elements." << endl;
    }


    cout << "Size of the stack is: " << org.size() << endl;
    cout<<"After resizing"<<endl;
    org.push(6);
    org.push(7);
    org.push(8);


    org.display();
    return 0;
}