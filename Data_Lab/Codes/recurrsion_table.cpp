#include<iostream>  

using namespace std;

void loop(int i , int num )  
{  
    cout<<num<<" x "<<i<<" = "<<num*i<<endl;

    if (i == 10 )
    {
        return;
    }
    
    loop(i+1 , num);
    // cout<<i<<endl;

}  
int main()  
{  
    int x;
    cout<<"Enter the number:";
    cin>>x;
    loop(1,x);
    return 0;  
}