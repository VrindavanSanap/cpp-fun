#include <iostream>

class MyClass {
public:
    int value;

    MyClass(int val) : value(val) {}

    // Define the infix @ operator
    MyClass operator@(const MyClass& other) const {
        return MyClass(value * other.value);
    }
};

int main() {
    MyClass a(5);
    MyClass b(6);

    // Using the @ operator
    MyClass result = a @ b;

    std::cout << "Result: " << result.value << std::endl; // Output: Result: 30

    return 0;
}

