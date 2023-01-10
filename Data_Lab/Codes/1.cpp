#include<iostream>
using namespace std;

// void myftn(int myint);

// void myftn(int &myint);

void myftn(int *myint);

int main()
{
    int var; // declare

    var = 11; // initialization

    cout<<"Value of var is: "<<var<<endl;
    cout<<"Address of var is: "<<&var<<endl;

    int *ptr = nullptr; // dangling pointer
    cout<<"Address of pointer: "<<&ptr<<endl;

    ptr = &var;

    cout<<"Address store in pointer: "<<ptr<<endl;

    cout<<"Value pointed by ptr: "<<*ptr<<endl;

    myftn( ptr);

    cout<<"Value of variable: "<<var<<endl;

    int **ptr2 = &ptr;

    cout<<"Address of ptr2: "<<&ptr2<<endl;

    cout<<"Address store in ptr2: "<<ptr2<<endl;

    cout<<"Value pointed by ptr2 to ptr: "<<*ptr2<<endl;

    cout<<"Value pointed by ptr2: "<<**ptr2<<endl;

    int ***ptr3 = &ptr2;

    cout<<endl<<endl<<endl<<endl;
    
    cout<<"Address of ptr3: "<<&ptr3<<endl;

    cout<<"Address store in ptr3: "<<ptr3<<endl;

    cout<<"Value pointed by ptr3 to ptr2: "<<*ptr3<<endl;

    cout<<"Value pointed by ptr3 to ptr: "<<**ptr3<<endl;

    cout<<" is main chakak hy >> Value pointed by ptr3 to ptr: "<<***ptr3<<endl;


    // ===========================================================================
    // char ch;
    // ch = 'a';
    // char *p = &ch;
    
    // void * addr = &ch;

    // cout<<"Value of ch: "<<ch<<endl;
    // cout<<"Address of ch: "<<(void *)&ch<<endl;
    
    // cout<<"Value of p: "<<p<<endl;
    // cout<<"Address of p: "<<&p<<endl;
    // cout<<"Value of p to which it is pointing: "<<*p<<endl;

    // ===========================================================================

    return 0;
}

// void myftu(int myint)
// {
//     myint  = myint + 1;

//     cout<<"value of myint: "<<myint<<endl;

// }

// void myftn(int &myint)
// {
//     myint  = myint + 1;

//     cout<<"value of myint by reference: "<<myint<<endl;

// }

void myftn(int *myint)      // pass by value in 
{
    *myint  = *myint + 1;

    cout<<"value of myint by ptr: "<<myint<<endl;

}

// void myftn(int *& myint)      // pass by value in 
// {
//     *myint  = *myint + 1;

//     cout<<"value of myint by ptr: "<<*myint<<endl;

// }