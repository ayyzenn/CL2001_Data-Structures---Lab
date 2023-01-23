#include <iostream>

using namespace std;


class Queue_array
{
public:
    int *front , *rear , *que;
    int size;
    Queue_array();
    void enqueue();
    void dequeue();
    void print();
};

Queue_array::Queue_array()
{
    size = 4;
    que = new int [size];
    front = nullptr;
    rear = nullptr;
}

void Queue_array::enqueue()
{
    if (rear == nullptr)
    {
        front = rear = que;
        cout<<"Enter the number: ";
        cin>> *rear;
        return;
    }

    if (rear == (que + (size -1)) && (front == que))
    {
        cout<<"Queue is full."<<endl;
        return;
    }

    rear++;
    cout<<"Enter the number: ";
    cin>> *rear;
}

void Queue_array::dequeue()
{
    if (front == nullptr)
    {
        cout<<"Queue is empty."<<endl;
        return;
    }

    if (front == rear)
    {
        front = rear = nullptr;
        return;
    }

    if (front == (que + (size -1)))
    {
        front = que;
    }

    front++;
}

void Queue_array::print()
{
    int *temp = front;
    while (temp != rear)
    {
        cout<<*temp<<" ";
        temp++;
    }
    
    cout<<*temp<<endl;
    
}

int main()
{
    Queue_array q;

    // int x;

    // do
    // {
    //     cout<<"1.Enqueue"<<endl;
    //     cout<<"2.Dequeue"<<endl;
    //     cout<<"3.Print"<<endl;
    //     cout<<"0.Exit"<<endl;

    //     cout<<"Enter your choice: ";
    //     cin>> x;

    //     switch (x)
    //     {
    //     case 1:
    //         q.enqueue();
    //         break;
    //     case 2:
    //         q.dequeue();
    //         break;
    //     case 3:
    //         q.print();
    //         break;
    //     default:
    //         break;
    //     }
    // } while (x != 0);

    q.dequeue();
    q.enqueue();
    q.dequeue();
    q.enqueue();
    q.enqueue();
    q.enqueue();
    q.enqueue();
    q.enqueue();
    q.dequeue();
    q.dequeue();
    q.enqueue();

    q.print();
}