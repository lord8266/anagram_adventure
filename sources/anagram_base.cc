/*
  anagram class checks if the certain word can be spelled from the
  current set of characters
*/

#include "anagram_main.h"



anagram::anagram(const string& path,const string& random_string):
 current_random_string(random_string) , path_to_file(path)
 //initiliaze with random_string and path to word list
 {
  ifstream file_from(path); //load stream from path

  string word; //holds the current word

  while(file_from>>word) {
    list.insert(word); //add each word into list
  }
 sort(current_random_string); // sorts the string needed
}

bool anagram::check_word(const string& word) {
  bool ret = false;
  if (list.find(word)!=list.end()) {
    //is the word in the list of words
    ret = check_anagram(word);
    //then check if it is a subset of random_string or anagram
  }

  return ret;
}

bool anagram::check_anagram(const string& word) {

/*
 this is how it goes might not be the best way
 so there are two strings
one is the word you have to check and other is the random_string

to pass condition word must be a subset of random_string

first sort both the strings
set an iterator to random_string . begin

now go through each char in word
	if that char is not equal to the one in the random_string
	move to next char in the random_string
	if i find that the char is present in the random_string
	move to next iteration of word that is the main for loop

	if i hit random_string end before hitting the words end
  the word isnt a subset of random_string
	then return false

 else if i hit end of word before random word
    word is a subset and return true
  */

 string word_copy = word;
 sort(word_copy); //sort the copy

 bool passed = true;
 string::iterator str_main_iter = current_random_string.begin();
  // set the iterator to current_random_string
 for (const char& c : word_copy) {

    while(*str_main_iter!=c){
       str_main_iter++;
       if(str_main_iter==current_random_string.end()) {
           passed = false;
           break; // break off sub loop
       }
    }

      if(passed==false)
        break; // break off main loop

      str_main_iter++;
      /*
      move to next char in random_string as we dont want to evaluate
      a repeating char again
      */

 }


 return passed;
}



void anagram::set_random_string(const string &str) {
  current_random_string = str;
  sort(current_random_string); //sort the string
}


void anagram::sort(string& str) {
  // selection sort algorithm

  int len = str.size();
  string::iterator min;

  for(auto str_iter = str.begin();str_iter!=str.end();str_iter++) {
    min =str_iter;
     for(auto sub_iter = str_iter+1;sub_iter!=str.end();sub_iter++) {

      //if sub iter is less than min then set min to sub iter
        if (*sub_iter<*min )  {
          min = sub_iter;
        }
      }
     swap(str_iter,min); //swap
  }
}

void anagram::swap(string::iterator c1,string::iterator c2) {
  /* swap */
  char temp = *c1;
  *c1 = *c2;
  *c2 =temp;
}
