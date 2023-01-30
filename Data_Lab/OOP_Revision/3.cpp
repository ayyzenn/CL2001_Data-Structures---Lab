#include <iostream>

using namespace std;

class plugin
{
    public:
    void apply_filter(int img[5][5])
    {
        cout<<"Function apply_fliter for plugin called... Not doing anything"<<endl;
    }
};

class makewhite: public plugin
{
    public:

    void apply_fliter( int img[5][5])
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                img[i][j] = 255;
            }
            
        }
        
    }

};

class makeblack : public plugin
{
    public:
    void apply_fliter( int img [5][5])
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                img[i][j] = 0;
            }
            
        }
        
    }
};

void inti_matrix( int a[5][5]);
void output_matrix(int a[5][5]);

plugin *select_plugin();

void inti_matrix( int a[5][5])
{
    int val = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = val;
            val+=1;
        }
        
    }
    
}

void output_matrix(int a[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < j; j++)
        {
            cout << a[i][j]<<"\t";
        }
        cout<<endl;        
    }
    
}

int main()
{
    int pic[5][5];

    inti_matrix(pic);

    cout<< "Before: "<<endl;
    output_matrix(pic);

    plugin p;
    p.apply_filter(pic);

    makeblack mib;
    mib.apply_fliter(pic);

    cout<<"After Make black: "<<endl;
    output_matrix(pic);

    makewhite miw;
    miw.apply_fliter(pic);

    cout<<"After Make white: "<<endl;
    output_matrix(pic);

    inti_matrix(pic);

    return 0;

}