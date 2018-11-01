#ifndef word_gener
#define word_gener 1

/* this class takes care of generating new random_string every turn

every turns generates a new set of chars and prints them like this
only replaces words which have been used in the word given by user
*/
class word_gen { // makes a 5x4 display of chars
public:
  word_gen(const string& path); //constructor takes path to word list
  char gen_vowel();
  char gen_consonant();
  void print_formatted(); // prints the characters in a format like this
  bool check_and_update(const string &users_word);
  // every time user enters word check_and_update
  void shuffle_new();
  void update_engines();
  void decrement(char);
  ~word_gen();
public:
  anagram *_anagram  =nullptr;
  string random_char_list; //holds the current characters
  map<char,int> char_box;
private:
  std::default_random_engine main_engine;
  std::default_random_engine consonants_engine;
  std::default_random_engine vowels_engine;
 /* initiliaze engines to generate random numbers
    main engine is seeded from time and consonants_engine and
    vowels_engine is seeded from main engine's random values

  */
  std::uniform_int_distribution<int> vowels_make;
  std::uniform_int_distribution<int> consonants_make;
  std::uniform_int_distribution<int> vowels_next;
  /* define distributions */

  string consonants ="bcdfghjklmnpqrstvwxyz";
  string vowels = "aeiou";
private:
  int use_cnt = 0;
};

#endif
