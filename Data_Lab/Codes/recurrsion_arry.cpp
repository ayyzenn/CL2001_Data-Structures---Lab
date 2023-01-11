#include<iostream>  

using namespace std;

void array(int *pos , int *start, int *stop)  
{
    
    cout<<*pos<<endl;

    if (pos==stop)
    {
        return;
    }
    
    array( ++pos ,start , stop );

    if (pos == start-1)
    {
        return;
    }
    
    array( --pos ,start , stop );

}  
int main()  
{
    
    int a[] = {1,2,3,4,5,6};
    array(&a[3],a ,a+5);
    return 0;  
}  
