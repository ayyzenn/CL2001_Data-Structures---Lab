#include<iostream>
using namespace std;

struct node
{
    int info;
    node *next;
    node *previous;
};
class doublelinklist
{
    private:
        node *head , *temp , *temp1;
    public:
        doublelinklist();
        void Insert();
        void InsertAt();
        void print();
        void del();

};

doublelinklist::doublelinklist()
{
    head= temp = temp1 = NULL;
}

void doublelinklist::InsertAt()
{
}

void doublelinklist::print()
{
    temp=head;
    while(temp->next !=head )
    {
        cout<<temp->info<<" ";
        temp= temp->next;
    }
    cout<<temp->info; // for last value
    cout<<endl;;
}

void doublelinklist::del()
{
    if(head==NULL)
    {
        return;
    }
    temp = head;
    int key;
    cout<<"Enter Value to delete "<<endl;
    cin>>key;
    do
    {
        if(temp->info==key){
        temp->previous->next = temp->next;
        temp->next->previous= temp->previous;
        temp1=temp;
        if(temp1==head)
        {
            head=head->next;  // for not deleting head
        }
        temp=temp->previous;
        delete temp1;  

    }

    temp=temp->next;
    } while(temp !=head);
}

int main()
{
    doublelinklist l;
    int x;

    do
    {
        cout<<"1.Insert."<<endl;
        cout<<"2.InsertAt."<<endl;
        cout<<"3.Print."<<endl;
        cout<<"4.Delete."<<endl;
        cout<<"0.Exit."<<endl<<endl;

        cout<<"Enter your choice: ";
        cin>>x;
        switch (x)
        {
        case 1:
            l.Insert();
            break;
        case 2:
            l.InsertAt();
            break;
        case 3:
            l.print();
            break;
        case 4:
            l.del();
            break;
        default:
            break;
        }
    } while (x != 0);   
	return 0;
}