#include <iostream>

class Animal {
public:
    void makeSound() {
        std::cout << "Some generic animal sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal* animalPtr;
    Dog myDog;
    Cat myCat;

    // Point to a Dog object
    animalPtr = &myDog;
    animalPtr->makeSound(); // Calls the Animal version!

    // Point to a Cat object
    animalPtr = &myCat;
    animalPtr->makeSound(); // Also calls the Animal version!

    return 0;
}
