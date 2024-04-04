#include <iostream>

using namespace std;

int main(){

  int *int_ptr = new int;
  *int_ptr = 242;
  cout<< "Value:"   << *int_ptr<<endl;
  cout<< "Address:" <<  int_ptr<<endl;
  delete int_ptr;
  return 0;

  
}
