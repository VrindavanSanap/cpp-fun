#include <iostream>
class MyClass {
 public:
  explicit MyClass(std::string name) : mName(name) {}

  ~MyClass() { std::cout << "I'm dying…" << std::endl; }

  void saySomething() {
    std::cout << "Oh hello! I am " << mName << "!" << std::endl;
  }

 private:
  std::string mName;
};

int main() {
  auto* myClass = new MyClass("");
  myClass->saySomething();
  delete myClass;

  return 0;
}
