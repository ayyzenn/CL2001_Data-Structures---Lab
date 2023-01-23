#include <iostream>

using namespace std;

struct node
{
    int info;
    node *right , *left;
};

class BST
{
    public:
        node *root , *temp1 , *temp2;
        BST();
        void insert(int , node*& );
        node *search(int , node*const& );
        void Post_ord(node *);
        void Pre_ord(node *);
        void InOrder(node *);
        int successor(int);
        node* minValueNode(node*);
        node* delete_bst(node* , int );
};

BST::BST()
{
    root = nullptr;
}

void BST::insert(int key , node *&temp)
{
    if (temp == nullptr)      // check 1
    {
        temp = new node;
        temp->info = key;
        temp->left = temp->right = nullptr;

        if (root == nullptr)
        {
            root = temp;
        }
        return;
    }

    if (temp->info == key)
    {
        cout<<"Duplicate."<<endl;
        return;
    }
    
    if (temp->info > key) 
    {
        insert(key , temp->left);
        return;
    }

    if (temp->info < key)
    {
        insert(key , temp->right);
    }
}

node *BST::search(int key , node * const &temp)
{
    if (root == nullptr)
    {
        cout<<"Tree is empty."<<endl;
        return NULL;
    }
    
    if (key == temp->info)
    {
        return temp;
    }
    
    if ( (temp->left != NULL) && (key < temp->info) )
    {
        return search(key , temp->left );
    }
    
    if ( (temp->right != NULL) && (key > temp->info) )
    {
        return search(key , temp->right );
    }
    cout<<"Search not found."<<endl;
    return NULL;
}

void BST::Post_ord(node *temp)
{
    if(temp==NULL){
		cout<<"Tree is Empty "<<endl;
		return;
	}
	if(temp->left != NULL){
		Post_ord(temp->left);
	}
	if(temp->right != NULL){
		Post_ord(temp->right);
	}
	cout<<temp->info<<" ";
}

void BST::Pre_ord(node *temp)
{
	if(temp==NULL)
    {
		cout<<"Tree is Empty "<<endl;
		return;
	}
	cout<<temp->info<<" ";
	
	if(temp->left != NULL)
    {
		Post_ord(temp->left);
	}
	if(temp->right != NULL)
    {
		Post_ord(temp->right);
	}
}

void BST::InOrder(node *temp)
{
	if(temp == NULL)
    {
		cout<<"Tree is Empty "<<endl;
		return; 
	}
	if(temp->left !=NULL)
    {
		InOrder(temp->left);
	}
    
	cout<<temp->info<<" ";

	if(temp->right != NULL)
    {
		InOrder(temp->right);
	}
}

int BST::successor(int key)
{
    node *temp = search(key , root);

    node *successor = nullptr;

    if (temp == nullptr)
    {
        return NULL;
    }
    
    if (temp->right != nullptr)
    {
        temp = temp->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp->info;
    }
    else
    {
        node* temp2 = root;
        while (temp2 != temp)
        {
            if (temp2->info > temp->info)
            {
                successor = temp2;
                temp2 = temp2->left;
            }

            else
            {
                temp2 = temp2->right;
            }
        }
        return successor->info;
    }
}

node *BST:: minValueNode(struct node* temp)
{
    struct node* temp1 = temp;
 
    /* loop down to find the leftmost leaf */
    while (temp1 && temp1->left != NULL)
    {
        temp1 = temp1->left;
    }
    return temp1;
}

node *BST::delete_bst(struct node* temp, int key)
{
    // base case
    if (temp == NULL)
        return temp;
 
    // If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if (key < temp->info)
        temp->left = delete_bst(temp->left, key);
 
    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if (key > temp->info)
        temp->right = delete_bst(temp->right, key);
 
    // if key is same as root's key, then This is the node to be deleted
    else 
    {
        // node has no child
        if (temp->left==NULL and temp->right==NULL)
            return NULL;
       
        // node with only one child or no child
        else if (temp->left == NULL) 
        {
            struct node* temp1 = temp->right;
            delete temp;
            temp = nullptr;
            return temp1;
        }

        else if (temp->right == NULL) 
        {
            struct node* temp1 = temp->left;
            delete temp;
            temp = nullptr;
            return temp1;
        }
 
        // node with two children: Get the inorder successor (smallest in the right subtree)
        struct node* temp1 = minValueNode(temp->right);
 
        // Copy the inorder successor's content to this node
        temp->info = temp1->info;
 
        // Delete the inorder successor
        temp->right = delete_bst(temp->right, temp1->info);
    }
    return temp;
}

int main()
{
    BST b;
    // int x, num;

    // do
    // {
    //     cout<<"1.Insert"<<endl;
    //     cout<<"2.Search"<<endl;
    //     cout<<"3.Delete"<<endl;
    //     cout<<"4.Post Order"<<endl;
    //     cout<<"5.Pre Order"<<endl;
    //     cout<<"6.Inorder"<<endl;
    //     cout<<"7.Successor"<<endl;
    //     cout<<"0.Exit"<<endl<<endl;

    //     cout<<"Enter your choice: ";
    //     cin>>x;
    //     switch (x)
    //     {
    //     case 1:
    //         cout<<"Enter the number: ";
    //         cin>>num;
    //         b.insert(num , b.root);
    //         break;
    //     case 2:
    //         cout<<"Enter the number for search: ";
    //         cin>>num;
    //         b.search(num , b.root);
    //         break;
    //     case 3:
    //         cout<<"Enter the number to be delete: ";
    //         cin>>num;
    //         b.delete_bst( b.root , num);
    //         break;
    //     case 4:
    //         b.Post_ord(b.root);
    //         cout<<endl;
    //         break;
    //     case 5:
    //         b.Pre_ord(b.root);
    //         cout<<endl;
    //         break;
    //     case 6:
    //         b.InOrder(b.root);
    //         cout<<endl;
    //         break;
    //     case 7:
    //         cout<<"Enter the number: ";
    //         cin>>num;
    //         cout<<"Successor is: "<<b.successor(num);
    //         cout<<endl;
    //         break;
    //     default:
    //         break;
    //     }
    // } while (x != 0);
    



    /* test function */

    b.insert(100 , b.root);
    b.insert(50 , b.root);
    b.insert(150 , b.root);
    b.insert(1 , b.root);
    b.insert(60 , b.root);
    b.insert(55 , b.root);
    b.insert(140 , b.root);
    b.insert(200 , b.root);

    b.InOrder(b.root);
    cout<<endl;
    cout<<b.successor(100);
    cout<<endl;
    cout<<b.successor(55);
    cout<<endl;

    b.delete_bst(b.root , 55);
    cout<<endl;
    b.InOrder(b.root);
    cout<<endl;
}
