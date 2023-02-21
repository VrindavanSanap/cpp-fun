#include <iostream>
using namespace std;

class MyClass
{
public:
    int myMember;
};

int main()
{
    MyClass *myObject = new MyClass();
    myObject->myMember = 42;

    cout << "The value of myMember is: " << myObject->myMember << endl;

    delete myObject;
    return 0;
}
