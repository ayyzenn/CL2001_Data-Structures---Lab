#include<iostream>  

using namespace std;

void loop( int num  = 1 )  
{
    int fac = fac*i;
    cout<<fac<<endl;

    if (i == 0 )
    {
        return;
    }
    
    loop(i--);

}  
int main()  
{  
    int x;
    cout<<"Enter the number:";
    cin>>x;
    loop(x);
    return 0;  
}  

