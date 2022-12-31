#include<iostream>
#include<string.h>


using namespace std;


//Pass by value in pointers is same as pass by reference in var.
void myFun(int *& myInt){ 

    *myInt = *myInt + 1;

    cout<<"Value of myInt is:   "<<*myInt<<endl;


}


int main(){


/*
    int var; //declare 
    var = 11; // initialization

    cout<<"Value stored in var:     "<<var<<endl;

    cout<<"Address of var:      "<<&var<<endl;

    int *ptr = nullptr; //dangling pointer

    cout<<"Address of pointer:      "<<&ptr<<endl;

    ptr = &var;

    cout<<"Address stored in pointer:   "<<ptr<<endl;

    cout<<"Value pointed by ptr:    "<<*ptr<<endl;

    myFun(ptr);
    cout<<"value of var:    "<<var<<endl;
    
    int ** ptr2 = &ptr;

    cout<<"Adrress of ptr2: "<<&ptr2<<endl;

    cout<<"Address stored in ptr2:  "<<ptr2<<endl;

    cout<<"Value pointed by ptr2:   "<<**ptr2<<endl;


    




    
    //cout << ptr << endl; // << stream insertion operator OR concatenation operator



    //declare and initialize a char varaiable
    //declare a char pointer
    //assign the char var address to the pointer
    //print addresses and values of variable and pointer



    char ch = 'b';

    cout<<"my char is:  "<<ch<<endl;

    cout<<"address of my Char is :  "<<(void *)&ch<<endl;

    char *chPtr = &ch;

    cout<<"address stored in pointer:   "<<(void *)chPtr<<endl;



    char chArray [3] = {'a','c','v'};

    char ch2 = 'g';

    char *chptr = "hello";
*/


    char *chptr = new char[4];

    char *ch = new char;

    *ch = 'z';


    cout<<"value of ch is:  "<<*ch<<endl;


    strcpy(chptr , "Helloworld");
    cout<<chptr<<endl;

    cout<<"value of ch is:  "<<*ch<<endl;


    cout<<chptr<<endl;
   

    
    return 0;
}