#include "anagram_main.h"



int main() {
  string s1 = "dfqwewewerwere3rte";
  anagram::sort(s1);
  //anagram a1("word_refined.txt");
  //a1.set_random_string("cttedoggguage");



    std::default_random_engine e;
    std::uniform_int_distribution<int> u(0,9);

    for(int i=0;i!=10;i++) {
      cout<<u(e)<<endl;
    }

    word_gen w1("word_refined.txt");
    cout<<w1.random_char_list<<endl;
    cout<<endl;
    w1.print_formatted();

  string temp ="";

  while(cin>>temp) {
    if(w1.check_and_update(temp)) {
      cout<<"nice word"<<endl;
      w1.print_formatted();
    }
    else {
      cout<<"try again"<<endl;
    }

  }


  }
