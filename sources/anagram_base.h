#ifndef anagram_base
#define anagram_base 1

class anagram {
public:
  anagram(const string& word_list_path);
  bool check_word(const string& word);
  void set_random_string(const string& str);
  //sets the current random string
public:
  static void sort(string&);
  static void swap(string::iterator,string::iterator);
  //common functions to sort the string
  bool check_anagram(const string& word);
  // function to check anagram

  set<string> list; // holds all the words

  string current_random_string;
  /* the string that holding the set of chars
    word has to be a subset of this and a valid word */

  string path_to_file;

};

#endif
