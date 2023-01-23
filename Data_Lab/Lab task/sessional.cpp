// #include<iostream>
// using namespace std;

// struct node
// {
//     int info;
//     node *next;
// };

// class queue
// {
// public:
//     node *rear , *front , *temp;
//     int size;
//     queue();
//     void enqueue(int);
//     void dequeue();
//     void print();
// };

// queue::queue()
// {
//     rear = front = temp = nullptr;
//     size = NULL;
// }   

// void queue::enqueue(int num)
// {
//     if(rear == nullptr)
//     {
//         rear = new node;
//         rear->info = num;
//         rear->next = nullptr;
//         front = rear;
//         size++;
//         return;
//     }

//     temp = rear;
//     if (size < 6)
//     {
//         temp = new node;
//         temp->info = num;
//         rear->next = temp;
//         temp->next = nullptr;
//         rear = temp;
//         size++;
//         return;
//     }
//     cout<<"Queue overflow."<<endl;
// }

// void queue :: dequeue()
// {
//     if(front == nullptr)
//     {
//         cout<< "Underflow."<<endl;
//     }

//     temp = front;

//     front = front->next;
//     delete temp;
//     size--;
//     temp = nullptr;
//     return;
// }

// void queue::print()
// {
//     temp = front;
//     while (temp->next != nullptr)
//     {
//         cout<<temp->info<<" ";
//         temp = temp->next;
//     }
//     cout<<temp->info<<" ";
//     cout<<endl;
// }

// int main()
// {
//     queue q;
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);
//     q.enqueue(4);
//     q.enqueue(5);
//     // q.enqueue(6);
//     // q.enqueue(7);
//     q.print();

//     q.dequeue();
//     q.dequeue();

//     q.print();
// }


// #include<iostream>
// using namespace std;

// class queue
// {
// public:
//     int *rear , *front , *array;
//     int size , count;
//     queue();
//     void enqueue(int);
//     void dequeue();
//     void print();
// };

// queue::queue()
// {
//     size = 5;
//     array = new int[size];
//     rear = front = nullptr;
//     count = NULL;
// }   

// void queue::enqueue(int num)
// {
//     if(rear == nullptr )
//     {
//         rear = front = array;
//         *rear = num;
//         rear++;
//         return;
//     }

//     if (rear == (array + (size-1)) && front == array )
//     {
//         cout<<"Queue is full"<<endl;
//         return;
//     }
//     rear++;
//     *rear = num;
    
// }

// void queue :: dequeue()
// {
//     front++;
//     if (front == rear)
//     {
//         front = rear = nullptr;
//     }

//     if(front == (array + (size - 1)) )    
//     {
//         front = array;
//     }

// }

// void queue::print()
// {
//     int *temp2 = front;
//     for(int i = 0 ; i < size ; i++ )
//     {
//         cout<<*temp2<<" ";
//         temp2++;
//     }
//     cout<<endl;
// }

// int main()
// {
//     queue q;
//     q.enqueue(5);
//     q.enqueue(4);
//     q.enqueue(3);
//     q.enqueue(2);
//     q.enqueue(1);
//     // q.enqueue(6);
//     // q.enqueue(7);

//     q.print();

// //     q.dequeue();
// //     q.dequeue();

// //     q.print();
// }


#include<iostream>
using namespace std;

struct node
{
    int info;
    node *left , *right;
};


class tree
{

    public:
        node *root , *test;
        tree();
        void insert(int , node *&);
        node *search(int key , node *&);
        void print(node *);
};

tree::tree()
{
    root = nullptr;
}

void tree ::insert(int num , node *&temp)
{
    if (temp == nullptr)
    {
        temp = new node;
        temp->info = num;
        temp->left = temp->right = nullptr;
        return;
    }   

    if (temp->info == num)
    {
        cout<< "Dublicate."<<endl;
        return;
    }
    

    if (temp->info > num)
    {
        insert(num , temp->left);
    }
    
    if (temp->info < num)
    {
        insert(num , temp->right);
    }
    
}

void tree::print(node *temp)
{
    if (temp == nullptr)
    {
        cout<<"Tree empty"<<endl;
        return;
    }
    
    if (temp->left != nullptr)
    {
        print(temp->left);
    }
    cout<<temp->info<<" ";
    if (temp->right != nullptr)
    {
        print(temp->right);
    }
}

node *tree::search(int num , node *&temp)
{
    if (temp == nullptr)
    {
        cout<< "Tree is empty."<<endl;
        return NULL;
    }

    if (num == temp->info)
    {
        return temp;
    }
    

    if(temp->info < num && temp->right != nullptr) // right
    {
        search(num , temp->right);
        return temp;
    }

    if (temp->info > num && temp->left != nullptr) // left
    {
        search(num , temp->right);
        return temp;
    }

    cout<<"Search not found."<<endl;
    return NULL;
}

int main()
{
    tree t;
    t.insert(100 , t.root);
    t.insert(50 , t.root);
    t.insert(150 , t.root);
    t.insert(1 , t.root);
    t.insert(60 , t.root);
    t.insert(55 , t.root);
    t.insert(140 , t.root);
    t.insert(200 , t.root);

    t.print(t.root);

    cout<<t.search(1 , t.root)<<endl;
}
