#include <iostream>
#include <algorithm>
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
            return;
        }
        top--;
    }


    char peek(){
        if (top == -1){
            return '\0';
        }
        return stack[top];
    }


    bool isEmpty(){
        return (top == -1);
    }


    void resize(){
        char *newStack = new char[capacity * 2];
        for (int i = 0; i <= top; i++){
            newStack[i] = stack[i];
        }
        delete[] stack;
        stack = newStack;
        capacity *= 2;
    }


    string process(string org){
        for (int i = 0; i < org.length(); i++){
            if (org[i] != '#'){
                push(org[i]);
            }
            else{
                pop();
            }
        }


        string result = "";
        while (!isEmpty()){
            result += peek();
            pop();
        }
        return result;
    }
};
int main()
{
    string first;
    cout << "Enter a phrase: ";
    cin >> first;


    string second;
    cout << "Enter a phrase: ";
    cin >> second;
    NabeedAli_Lab03 S1;
    string fir = S1.process(first);
    string sec = S1.process(second);
    reverse(fir.begin(), fir.end());
    reverse(sec.begin(), sec.end());
    cout << fir << endl
         << sec << endl;
    if (fir == sec){
        cout << "True";
    }
    else{
        cout << "False";
    }
    return 0;
}