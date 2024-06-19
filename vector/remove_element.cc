#include <iostream>
#include <vector>

using namespace std;
void print_vector(vector<int> v){
    for (int num : myVector) {
        cout << num << " ";
    }
 

}

int main() {
  vector<int> myVector = {1, 2, 3, 4, 5};

  myVector.erase(myVector.begin() + 2);
  cout << std::endl;
  return 0;
}

