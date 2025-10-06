#include <iostream>
#include <vector>
#include <memory>

// 1. Base Class (Parent/Superclass)
class Animal {
public:
    std::string name;

    Animal(const std::string& n) : name(n) {}

    // A virtual function enables polymorphism (dynamic dispatch)
    virtual void makeSound() const {
        std::cout << "Animal " << name << " makes a generic sound." << std::endl;
    }

    // Virtual destructor is crucial for safe deletion via a base pointer
    virtual ~Animal() = default;
};

// 2. Derived Class (Child/Subclass)
class Dog : public Animal {
public:
    int tailWagsPerMinute; // Derived class's unique member

    Dog(const std::string& n, int wags) : Animal(n), tailWagsPerMinute(wags) {}

    // Overriding the base class function to provide specialized behavior
    void makeSound() const override {
        std::cout << "Dog " << name << " says Woof-Woof! 🐕" << std::endl;
    }

    // Derived class's unique function
    void wagTail() const {
        std::cout << name << " is happily wagging its tail at "
                  << tailWagsPerMinute << " wags/min." << std::endl;
    }
};

void demonstrateObjects() {
    // A. Base Class Object
    std::cout << "--- 1. Base Class Object ---" << std::endl;
    Animal genericAnimal("Zoe");
    genericAnimal.makeSound(); // Calls Animal::makeSound()

    // B. Derived Class Object
    std::cout << "\n--- 2. Derived Class Object ---" << std::endl;
    Dog myDog("Sparky", 120);

    // The derived object can call BOTH inherited and its own methods
    myDog.makeSound(); // Calls Dog::makeSound() (inherited and overridden)
    myDog.wagTail();   // Calls Dog::wagTail() (unique to Dog)
}

void demonstratePolymorphism() {
    // C. Polymorphism using Base Class Pointers/References
    std::cout << "\n--- 3. Polymorphism (The 'Is-A' Relationship) ---" << std::endl;

    // A Base Class pointer can point to a Derived Class object.
    // This is the core of runtime polymorphism.
    std::unique_ptr<Animal> a1 = std::make_unique<Animal>("Leo");
    std::unique_ptr<Animal> a2 = std::make_unique<Dog>("Buddy", 90);

    // When the virtual function makeSound() is called:
    std::cout << "Pointer a1 (points to Animal object): ";
    a1->makeSound(); // Output: Animal's sound (Static/Base behavior)

    std::cout << "Pointer a2 (points to Dog object): ";
    a2->makeSound(); // Output: Dog's sound (Dynamic/Derived behavior)

    std::cout << "\n--- Slicing Example ---" << std::endl;
    // D. Object Slicing (Avoid this!)
    // Assigning a derived object to a base object causes "slicing"
    // The derived part (Dog::tailWagsPerMinute) is cut off (sliced).
    Animal slicedAnimal = myDog; // myDog's derived parts are lost!
    slicedAnimal.makeSound();    // Calls Animal::makeSound(), NOT Dog::makeSound()
    // slicedAnimal.wagTail();   // ERROR: Animal object has no wagTail() method

    std::cout << "The derived-specific data (tailWagsPerMinute) is not copied in slicing." << std::endl;
}

int main() {
    demonstrateObjects();
    demonstratePolymorphism();
    return 0;
}
