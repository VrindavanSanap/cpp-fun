#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  // Create an fstream object
  fstream file;

  // Open a file in read and write mode

  file.open("example.txt", ios::in | ios::out | ios::trunc);

  // Check if the file is open
  if (!file) {
    cerr << "File could not be opened!" << endl;
    return 1;
  }

  // Write to the file
  file << "Hello, World!" << endl;
  file << "This is a test file." << endl;

  // Close the file after writing
  file.close();

  // Reopen the file for reading
  file.open("example.txt", ios::in);

  // Check if the file is open
  if (!file) {
    cerr << "File could not be opened for reading!" << endl;
    return 1;
  }

  // Read from the file and display the content
  string line;
  while (getline(file, line)) {
    cout << line << endl;
  }
  file.close();

  return 0;
}
