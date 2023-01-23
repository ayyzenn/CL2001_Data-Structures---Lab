#include <iostream>
using namespace std;

struct node
{
    int info;
    node *left , *right;
    int leftbit;
    int rightbit;
};


class Th_BT
{
    public:
    node *root , *dummy , *temp;

    Th_BT();
    void insert(int , node *);
    void InOrder(node *);
    void delete_th(int , node *);
    void delete_node(node * , node *);
    node * find_successor(node* , node *& );
};

Th_BT::Th_BT()
{
    dummy = new node;

    dummy->left = dummy->right = dummy;
    dummy->leftbit = 0;              // thread = 0
    dummy->rightbit = 1;             // child  = 1

    root = nullptr;
}

void Th_BT::insert(int key , node *temp)
{
    if (root == nullptr)
    {
        root = new node;
        root->info = key;
        root->left = root->right = dummy;
        root->leftbit = root->rightbit = 0;
        dummy->left = root;
        dummy->leftbit = 1;
        return;
    }

    if (temp->info == key)
    {
        cout<<"Dublicate"<<endl;
        return;
    }
    
    if (key < temp->info)
    {
        if (temp->leftbit == 0)
        {
            node *n = new node;
            n->info = key;

            n->leftbit = temp->leftbit;
            n->left = temp->left;
            
            n->right = temp;
            n->rightbit = 0;

            temp->left = n;
            temp->leftbit = 1;

            return;   
        }

        else
        {
            insert(key , temp->left);
        }
    }
    
    if (key > temp->info)
    {
        if (temp->rightbit == 0)
        {
            node *n = new node;
            n->info = key;

            n->rightbit = temp->rightbit;
            n->right = temp->right;
            
            n->left = temp;
            n->leftbit = 0;

            temp->right = n;
            temp->rightbit = 1;

            return;   
        }

        else
        {
            insert(key , temp->right);
        }
                
    }

}

void Th_BT::InOrder(node *temp)
{
	if(temp == NULL)
    {
		cout<<"Tree is Empty "<<endl;
		return; 
	}

	if(temp->leftbit !=0)
    {
		InOrder(temp->left);
	}

	cout<<temp->info<<" ";

	if(temp->rightbit != 0)
    {
		InOrder(temp->right);
	}
}

void Th_BT::delete_th(int key , node *temp)
{
    
    if (root == nullptr)
    {
        cout << "Tree is empty"<<endl;
    }
    
    if (temp->left->info == key)
    {
        delete_node(temp->left , temp);
        return;
    }

    if ((temp != dummy) && (temp->right->info == key))
    {
        delete_node(temp->right , temp);
        return;
    }

    if (temp == dummy)
    {
        delete_th(key , temp->left);
        return;
    }
    
    if ((key > temp->info) && (temp->rightbit == 1))
    {
        delete_th(key , temp->right);
        return;
    }

    if ((key < temp->info) && (temp->leftbit == 1))
    {
        delete_th(key , temp->left);
        return;
    }
    
    cout<< "Value does not exist."<<endl;
    return;
}


void Th_BT::delete_node(node * temp , node * parent)
{
    
    if ((temp->leftbit == 1) && (temp->rightbit == 1))          // case 1
    {
        node *successor_parent = temp;

        node *successor = find_successor(temp->right , successor_parent);
        temp->info = successor->info;
        delete_node(successor , successor_parent);
        return;
    }
    
    if ((temp->leftbit == 1) && temp->rightbit == 0 )           // case 2
    {
        if (temp->info < parent->info)
        {
            parent->left = temp->left;
            parent->leftbit = temp->leftbit;
        }

        else
        {
            parent->right = temp->left;
            parent->rightbit = temp->leftbit;
        }

        node *temp2 = temp->left;
        while (temp2->rightbit != 0)
        {
            temp2 = temp2->right;
        }
        

        temp2->right = temp->right;

        delete temp;
        return;
    }

    if ((temp->rightbit == 1) && temp->leftbit == 0 )           // case 3
    {
        if (temp->info < parent->info)
        {
            parent->right = temp->right;
            parent->rightbit = temp->rightbit;
        }

        else
        {
            parent->left = temp->right;
            parent->leftbit = temp->rightbit;
        }

        node *temp2 = temp->right;
        while (temp2->leftbit != 0)
        {
            temp2 = temp2->left;
        }
        

        temp2->left = temp->left;

        delete temp;
        return;
    }

    if ((temp->leftbit == 0) && (temp->rightbit == 0))        // case 4
    {
        if (parent->left == temp)
        {
            parent->left = temp->left;
            parent->leftbit = 0;
        }

        if ((parent->right == temp) && parent != dummy)
        {
            parent->right = temp->right;
            parent->rightbit = 0;
        }

        if (temp == root)
        {
            root = nullptr;
            dummy->left = dummy;
            dummy->leftbit = 0;
        }
        
        delete temp;
    }
}

node * Th_BT::find_successor(node *temp, node *& parent )
{
    if (temp->leftbit == 0)
    {
        return temp;
    }
    
    return find_successor(temp->left , parent);
}

int main()
{
    Th_BT t;

    t.insert(6 , t.root);
    t.insert(3 , t.root);
    t.insert(8 , t.root);
    t.insert(1 , t.root);
    t.insert(5 , t.root);
    t.insert(7 , t.root);
    t.insert(11 , t.root);
    t.insert(9 , t.root);
    t.insert(13 , t.root);

    // t.insert(100 , t.root);
    // t.insert(50 , t.root);
    // t.insert(200 , t.root);
    // t.insert(40 , t.root);
    // t.insert(60 , t.root);
    // t.insert(150 , t.root);
    // t.insert(250 , t.root);
    // t.insert(180 , t.root);
    // t.insert(300 , t.root);

    t.InOrder(t.root);
    cout<<endl;

    t.delete_th(5 , t.dummy);

    t.InOrder(t.root);
    cout<<endl;

    return 0;
}