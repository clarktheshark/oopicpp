// ex_12.cpp
// building a frequency table of words - hooray
#include <iostream>
#include <map>
#include <iterator>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
  string fn;
  cout << "\nEnter filename to parse: ";
  cin >> fn;
  
  // establish file and file stream
  ifstream infile(fn.c_str());
  istream_iterator<string> file_iter(infile);
  istream_iterator<string> eof;

  // create map to store frequencies
  map<string, int> freq;

  string word;
  while(file_iter != eof)
    {
      word = *file_iter;
      // remove punction
      word.erase(remove_if(word.begin(), word.end(), ::ispunct),
		 word.end());
      // make lowercase
      transform(word.begin(), word.end(),
		word.begin(), ::tolower);
      
      cout << *file_iter << ' ';
      freq[word]++;
      file_iter++;
    }
  
  cout << endl;
  cout << "\n<Word> : <Count>\n";
  map<string, int>::iterator mi;
  mi = freq.begin();
  while(mi != freq.end())
    {
      cout << '\'' << (*mi).first << "\' : " << (*mi).second << endl;
      mi++;
    }
  
  return 0;
}
