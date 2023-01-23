#include <iostream>

using namespace std;
 
struct node 
{
	int data;
	node* next;
    node* pre;
};

class doublelinklist
{
    public:
    node *head , *temp , *temp1;
    
    doublelinklist();
    void insert();
    void delete_l();
    void printList();


};

doublelinklist::doublelinklist()
{
    node *head = nullptr;
	node *temp = nullptr;
	node *temp1 = nullptr;   
}

void doublelinklist::insert()
{
    int num , key;
    cout<<"Enter the number to be entered: ";
    cin>>num;
   

    if(head == nullptr)
    {
        head = new node;
        head->data = num;
        head->next = head->pre = head;
        return;
    }
    
    temp = head;

    cout<<"Enter the key: ";
    cin>>key;

    if(head->next == head)
    {
        if(head->data == key)
        {
            temp1 =new node;
            temp1->data = num;
            temp1->next = head;
            temp1->next->pre = temp1;
            temp1->pre = head;
        }

        return;
    }

    while (temp->next != head)
    {
        if (temp->data == key)
        {
            temp1 = new node;
            temp1->data = num;
            temp1->next = temp->next;
            temp1->pre = temp;
            temp->next = temp1;
            temp1->next->pre = temp1;
            return;
        }

        temp = temp->next;
    }

    if (head->next == head)
    {
        if (head->data == key)
        {
            temp = new node;
            temp->data = num;
            temp->next=head;
            temp->pre= head;
            head->next = temp;
            head->pre = temp;
        }
    return;
    }
}

void doublelinklist::delete_l()
{
    int num;
    cout<<"Enter the number to be deleted: ";
    cin>>num;

    if(head == nullptr)
    {
        cout<<"No node to be deleted."<<endl;
        return;
    }

    temp = head;
    
    do
    {
        if (temp->data == num)
        {
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            temp1 = temp;
            temp = temp->pre;
            if (temp1 == head)
            {
                head = head->next;
            }
            delete temp1;
        }
        
        temp = temp->next;
    } while (temp != head);
    return;

}


void doublelinklist::printList()
{
    temp = head;
    while (temp->next != head)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
    
}

int main()
{
    doublelinklist l;
    int x;

    do
    {
        cout<<"1.Insert."<<endl;
        cout<<"2.Print."<<endl;
        cout<<"3.Delete."<<endl;
        cout<<"0.Exit."<<endl<<endl;

        cout<<"Enter your choice: ";
        cin>>x;
        switch (x)
        {
        case 1:
            l.insert();
            break;
        case 2:
            l.printList();
            break;
        case 3:
            l.delete_l();
            break;
        default:
            break;
        }
    } while (x != 0);   
	return 0;
}
