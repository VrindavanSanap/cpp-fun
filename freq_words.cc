// Created by Vrindavan Sanap
// freq_words.cc this file gives you the top ten most common words in your
// text file
// Ussage ./freq_words <filename>
//

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

void remove_trailing_punct(std::string &str) {
  while (!str.empty() && (std::ispunct(str.back()) || str.back() == '\n')) {
    str.pop_back();
  }
}

int main() {

  ifstream file;
  string file_name = "bee_movie.txt";
  file.open(file_name);
  if (!file) {
    cerr << "File could not be opened for reading!" << endl;
    return 1;
  }

  stringstream s_stream;
  s_stream << file.rdbuf();
  file.close();

  map<string, int> map_;
  string word;
  int total_count = 0;
  while (getline(s_stream, word, ' ')) {
    cout << word << endl;
    remove_trailing_punct(word);
    map_[word] += 1;
    total_count++;
  }
  for (const auto &pair : map_) {
    std::cout << pair.first << " -> " << pair.second << '\n';
  }

  cout << "There are " << total_count << " (" << map_.size()
       << ") unique words in " << file_name << endl;
  return 0;
}
