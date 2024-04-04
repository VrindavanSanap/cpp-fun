#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include <atomic>

void AdvancedSharedPointer();
void FileExample();

class Base{
  public:

    virtual void speak(){
      std::cout<<"I am base"<<std::endl;
    }

    virtual ~Base(){
      std::cout<<"base destroyed"<<std::endl;
    }
};

class Derived : public Base {
  public:
    void speak(){
      std::cout<<"I am derived"<<std::endl;
    }

    ~Derived() override{
      std::cout<<"Derived destroyed"<<std::endl;
    }
}

void custom_deleter(Base *ptr){
  std::cout<<"Custom deleter called."<<std::endl;
  delete ptr;
}

int main(){
  
}
