#include <iostream>

class Animal {
public:
    // Make the function virtual
    virtual void makeSound() {
        std::cout << "Some generic animal sound" << std::endl;
    }
    // It's a good practice to have a virtual destructor in a base class
    virtual ~Animal() {} 
};

class Dog : public Animal {
public:
    // Override the base class function
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    // Override the base class function
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal* animalPtr;
    Animal myAnimal; // Base Animal object
    Dog myDog;
    Cat myCat;

    // Point to a Dog object
    animalPtr = &myDog;
    animalPtr->makeSound(); // Correctly calls the Dog version!

    // Point to a Cat object
    animalPtr = &myCat;
    animalPtr->makeSound(); // Correctly calls the Cat version!

    // Point to an Animal object
    animalPtr = &myAnimal;
    animalPtr->makeSound(); // Calls the base Animal version

    return 0;
}
