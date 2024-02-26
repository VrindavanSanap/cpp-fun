#include <iostream>
int main(){
    int *p; // declare pointer and initialize it
                      // so that it doesn't store a random address
    int i = 5;
    p = &i;     // assign pointer to address of object
    int j = *p; // dereference p to retrieve the value at its address

    std::cout << "i = " << p << std::endl;
}