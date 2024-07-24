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
#include <vector>
using namespace std;

void remove_trailing_punct(std::string &str) {
  while (!str.empty() && (std::ispunct(str.back()) || str.back() == '\n')) {
    str.pop_back();
  }
}

bool sort_by_second_desc(const pair<string, int> &a,
                         const pair<string, int> &b) {
  return a.second > b.second;
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
    remove_trailing_punct(word);
    if (word != "") {

      map_[word] += 1;
    }
    total_count++;
  }
  /*
  for (const auto &pair : map_) {
    std::cout << pair.first << " -> " << pair.second << '\n';
  }
  */
  std::cout << "There are " << total_count << " (" << map_.size()
            << ") unique words in " << file_name << endl;

  vector<pair<string, int>> freq_vector;

  // Iterate through the map and push each key-value pair into the vector
  for (const auto &pair : map_) {
    freq_vector.push_back(pair);
  }

  sort(freq_vector.begin(), freq_vector.end(), sort_by_second_desc);
  std::cout << "Top 10 most freqently used words are:\n";
  for (int i = 0; i < 10; i++) {
    auto p = freq_vector[i];
    std::cout << p.first << " --> " << p.second << endl;
  }

  return 0;
}
