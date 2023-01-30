#include <iostream>

using namespace std;

class Count
{
    private:
        static int count; //only one data item for all objects
        //note: “declaration” only!
    public:
        Count() //increments count when object created
        {
            count++;
            //cout<<count;
        }
        int getcount() //returns count
        { 
            return count; 
        }
};

//--------------------------------------------------------------
int Count::count = 0; //*definition* of count
////////////////////////////////////////////////////////////////
int main()
{
    Count c1, c2, c3; //create three objects
    cout << "Count is "<< c1.getcount() << endl; //each object
    cout << "Count is " << c2.getcount() << endl; //sees the
    cout << "Count is " << c3.getcount() << endl; //same value
    return 0;
}
