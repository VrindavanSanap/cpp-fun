#include <iostream>
using namespace std;

class MyClass{
  friend void double_x(MyClass &object);
  private:
    int x;
    void add(int n){
      x += n;
    };

  public:
    MyClass(int x): x(x){};
    void print(){
      cout << "x: "<< x << endl;
    };
    
    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
        os << "MyClass(" << obj.x << ")";
        return os;
    }
    

};
void double_x(MyClass &object){
      object.add(object.x);
}
int main(){
  MyClass myobj(4);
  myobj.print();
  double_x(myobj);
  myobj.print();
  cout << myobj<<endl;
  return 0;
 

}
