#include <iostream>
using namespace std;
 
class Array_stk
{
public:
    int *top; 
    int *stk;
    int size; 

    Array_stk();
    void push();
    void pop();
    void print();
};

Array_stk::Array_stk()
{
    top = nullptr;
    cout<<"Enter the size of the array: ";
    cin>> size;
    stk = new int[size];
}

void Array_stk::push()
{
    if (top == nullptr)
    {
        top = stk;
        cout<<"Enter the number: ";
        cin>> *top;
        return;
    }

    if (top == stk+size-1)
    {
        cout<< "Stack overflow."<<endl;
        return;
    }

    else
    {
        top++;
        cout<<"Enter the number: ";
        cin>> *top;
        return;
    }
    
}

void Array_stk::pop()
{
    if (top == nullptr)
    {
        cout<<"Stack underflow."<<endl;
        return;
    }
    if (top == stk)
    {
        top = nullptr;
        return;
    }
    else
    {
        top--;
        return;
    }
        
}

void Array_stk::print()
{
    while (top != stk)
    {
        cout<<*top<<" ";
        top --;
    }
    cout<<*top<<" ";
    top = nullptr;
    cout<<endl;
        
}


int main()
{
    Array_stk a;
    int x;
    do
    {
        cout<<"1.Push"<<endl;
        cout<<"2.Pop"<<endl;
        cout<<"3.Print"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin >> x;

        switch (x)
        {
        case 1:
            a.push();
            break;
        case 2:
            a.pop();
            break;
        case 3:
            a.print();
            break;
        
        default:
            break;
        }
    } while (x != 0);
    

    return 0;
}
