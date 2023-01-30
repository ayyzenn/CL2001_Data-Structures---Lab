#include<iostream>

using namespace std;

void test(int b[]);

int main()
{
    int a[6] = {3,1,6,8,7,9};
    test(a);
    return 0;
}

void test(int b[])
{
    int even = 0, odd = 0 , prime = 0;

    for (int i = 0; i <= 5; i++)
    {
        if (b[i]%2 == 0)
        {
            even +=1;
        }
        else 
        {
            odd +=1;
        }

        if (b[i]%b[i] == 0 && b[i]%1==0)
        {
            prime+=1;
        }
          
    }

    cout<<"Even: "<<even<<endl;
    cout<<"Odd: "<<odd<<endl;
    cout<<"Prime: "<<prime<<endl;
    
}
 