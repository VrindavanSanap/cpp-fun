// Created by vrindavan sanap
// ALl rights reserved
// word_count.cc
// Returns the number of words a text file has
// ussage ./word_count <filename>

// This directive allows the program to access the definitions of
// standard input and output objects
#include <iostream>

// This directive allows the program to access the definitions of
// standard input and output objects
#include <fstream>

#include <sstream>
#include <string>

using namespace std;

int count_words(string s) { int count = 0; }

int main() {
  string file_name = "bee_movie.txt";
  ifstream file(file_name);
  if (!file) {
    cerr << "File could not be opened for reading!" << endl;
    return 1;
  }

  string line;
  int word_count = 0;
  while (getline(file, line)) {
    istringstream stream(line);
    string word;
    while (stream >> word) {
      ++word_count;
    }
  }
  cout << "There are " << word_count << " words in " << file_name << endl;
  return 0;
}
