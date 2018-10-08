#include "header.h"


bool check(const string& s) { //check if string is ok
  bool ret = true;

  if (s.size() <3) {
    return false; //only take more than 3 letter words
  }
 /*
  if the character is a number,space or punctuation char
  hen string is invalid and return false
  */

    for ( const char &c : s) {
    if (isdigit(c)||isspace(c)||ispunct(c)) {
      ret =false;
      break;
    }
  }

return ret;

}

void lower(string& str) {
  //function to change to lower case
  for(char & c : str ) {
    c = tolower(c);
  }
}


int main() {
  ifstream file_from("words.txt");
  //create new stream to words file
  ofstream file_to("word_refined.txt");
  //create new stream to make a refined word list

  set<string> refine_set = {}; //holds refined words

  string word_temp = ""; //holds the current word

  while(file_from>>word_temp) {
    //if the word is fine then append it to the new file

    if (check(word_temp)) { //if check passed

        lower(word_temp); //change word to lower case

        refine_set.insert(word_temp); //remove duplicates
    }
  }

  for (const string& word : refine_set) {
    file_to<<word<<"\n"; //append to refined file
  }

  file_to<<flush;


}
