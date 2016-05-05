#include <iostream>
using namespace std;

enum Boolean{FALSE,TRUE};
template <class T>
class Stack{
    public:
        Stack();
        ~Stack();
        bool IsFull();
        bool IsEmpty();
        T *Delete(T&);
        void Add(const T&);
    protected:
        int MaxSize;
        int top;
        T *stacks;
};


template<class T>
Stack<T>::Stack(){

    stacks = new T[100000];
    top = -1;
}

template<class T>
Stack<T>::~Stack(){

    delete[] stacks;
    top = -1;
}
template<class T>
bool Stack<T>::IsFull(){
    if(top == 100000 - 1){
        return TRUE;
    } else return FALSE;
}

template<class T>
bool Stack<T>::IsEmpty(){
    if(top == - 1){
        return TRUE;
    } else return FALSE;
}



template<class T>
void Stack<T>::Add(const T& x){
    if(IsFull()) cout << "full!" << endl;
    else{
        stacks[++top] = x;
    }
}

template<class T>
T* Stack<T>::Delete( T& x){
    if(IsEmpty()) cout << "empty!" << endl;
    else{
        x = stacks[top--];
        return (&x);
    }
}
