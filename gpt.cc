#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  ifstream file;
  file.open("bee_movie.txt");
  if (!file) {
    cerr << "File could not be opened for reading!" << endl;
    return 1;
  }

  stringstream s_stream;
  s_stream << file.rdbuf();
  file.close();

  string line;
  while (getline(s_stream, line, ',')) {
    cout << line << endl;
    cout << "---------" << endl;
  }

  return 0;
}
