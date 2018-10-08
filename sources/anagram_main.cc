#include "anagram_main.h"



int main() {
  string s1 = "dfqwewewerwere3rte";
  anagram::sort(s1);
  anagram a1("word_refined.txt");
  a1.set_random_string("cttedoggguage");
  string temp;
  while (cin>>temp) {
  cout<<a1.check_word(temp)<<endl;
}
}
