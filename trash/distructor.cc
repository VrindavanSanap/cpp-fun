#include <iostream>

class MyClass
{
public:
    MyClass()
    {
        std::cout << "Creating MyClass object..." << std::endl;
        data = new int[10];
    }

    ~MyClass()
    {
        std::cout << "Destroying MyClass object..." << std::endl;
        delete[] data;
    }

private:
    int *data;
};

int main()
{
    // create a MyClass object
    MyClass myObject;

    // do some work with myObject...

    // myObject will be automatically destroyed when it goes out of scope
    return 0;
}
