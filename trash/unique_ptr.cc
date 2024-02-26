#include <iostream>
#include <memory>

class DummyClass
{
public:
    DummyClass()
    {
        std::cout << "Creating DummyClass object..." << std::endl;
    }

    ~DummyClass()
    {
        std::cout << "Destroying DummyClass object..." << std::endl;
    }

    void sayHello()
    {
        std::cout << "Hello from DummyClass!" << std::endl;
    }
};

int main()
{
    // create a unique_ptr to a DummyClass object
    std::unique_ptr<DummyClass> dummyPtr(new DummyClass());

    // call a member function of the object
    dummyPtr->sayHello();

    // unique_ptr will automatically delete the object when it goes out of scope
    return 0;
}
