#include <iostream>

using namespace std;

struct node 
{
	int data;
	node* next;
};

class linklist
{
    public:
    node *rear , *front , *temp;
    
    linklist();
    void enqueue();
    void dequeue();
    void printList();


};

linklist::linklist()
{
    node *rear = nullptr;
	node *front = nullptr;
	node *temp = nullptr;   
}

void linklist::enqueue()
{
    int num;
    cout<<"Enter the number to be entered: ";
    cin>>num;
   

    if(rear == nullptr)
    {
        rear = new node;
        rear->data = num;
        rear->next = nullptr;
    }
    
    front = rear;
    rear->next = nullptr;
    return;
}

void linklist::dequeue()
{
    int num;

    cout<<"Enter the number to be delete: ";
    cin>>num;

    if(front == nullptr)
    {
        cout<<"Underflow."<<endl;
        return;
    }

    temp = front;

    front = front->next;

    if (front == nullptr)
    {
        rear = nullptr;
    }

    delete temp;

    temp = nullptr;
    return;

}


void linklist::printList()
{
    rear = front;

	while (rear != nullptr) 
    {
		cout << front->data << " ";
		front = front->next;
	}
    cout<<endl;
}


int main()
{
    linklist l;
    int x;

    do
    {
        cout<<"1.Enqueue."<<endl;
        cout<<"2.Print."<<endl;
        cout<<"3.Dequeue."<<endl;
        cout<<"0.Exit."<<endl<<endl;

        cout<<"Enter your choice: ";
        cin>>x;
        switch (x)
        {
        case 1:
            l.enqueue();
            break;
        case 2:
            l.printList();
            break;
        case 3:
            l.dequeue();
            break;
        default:
            break;
        }
    } while (x != 0);
    
	return 0;
}
