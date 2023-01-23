#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
 
class LL_stk
{
public:
    node *top , *temp; 
    int count;

    LL_stk();
    void push();
    void pop();
    void print();
};

LL_stk::LL_stk()
{
    this->top = NULL;
    this->temp = NULL; 
    count = 0;
}

void LL_stk::push()
{
    if (top == NULL)
    {
        top = new node;
        cout<<"Enter the value: ";
        cin>> top->data;
        top->next = NULL;
        count++;
        return;
    }

    temp = new node;
    temp->next = top;
    cout<<"Enter the value: ";
    cin>> temp->data;
    top = temp;
    temp = NULL;
    count++;
    return;
}

void LL_stk::pop()
{
    if (top == NULL)
    {
        cout<<"Stack underflow."<<endl;
        return;
    }

    temp = top;
    top = top->next;
    delete temp;
    temp = NULL;
    count--;
    return;            
}

void LL_stk::print()
{
    for(int i = 0 ; i < count ; i++)
    {
        cout<<top->data<<" ";
        pop();
        count++;
    }
    cout<<endl;
}


int main()
{
    LL_stk l;
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
            l.push();
            break;
        case 2:
            l.pop();
            break;
        case 3:
            l.print();
            break;
        
        default:
            break;
        }
    } while (x != 0);
    
    return 0;
}
