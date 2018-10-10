# include "anagram_main.h"
//include headers

word_gen::word_gen(const string& path): random_char_list(20,' ') , main_engine(time(0)) ,
consonants_engine(main_engine()),vowels_engine(main_engine()) ,
vowels_make(0,4) ,consonants_make(0,20),
vowels_next(1,4)
  {
    /*
    vowels_next is a distribution from 1 to 4
      since only 4 vowels are allowed
      look at shuffle_next to see how this is used

    vowels_make  distribution from 0 to 4
    consonants_make  distribution from 0 to 20
      there are two string vowels and consonants
      see gen_vowel and gen_consonant for more details
    */

    shuffle_new(); // make a new list of random chars
    use_cnt++; // increase the use cnt needed for update_engines

    _anagram = new anagram(path,random_char_list);
    // create a new anagram object
  }



char word_gen::gen_vowel() {
  //generates a new vowel
  char temp = vowels[vowels_make(vowels_engine)];
  //                 distribution(engine) uses engine to make a new number in the
  //                                           distribuion

  /* the char_box holds the number of characters for each letter
  each letter can only be repeated twice in the random_char list */

  if (char_box.find(temp)!=char_box.end()) {
     if(char_box[temp]==2) {
       temp = gen_vowel(); // recurively call to generate a new character
     }
     else {
      char_box[temp]++; // increase the count of character
     }
  }
  else {
    char_box[temp]=1; // otherwise set to 1
  }
  return temp;
}

char word_gen::gen_consonant() {
  //similar to vowels_make
  //except it uses consonants
  char temp = consonants[consonants_make(consonants_engine)];

  if (char_box.find(temp)!=char_box.end()) {
     if(char_box[temp]>2) {
       temp = gen_consonant();
     }
     else {
      char_box[temp]++;
     }
  }
  else {
    char_box[temp]=1;
  }
  return temp;
}

void word_gen::print_formatted() {
  /*
  prints in this format
  ---------------------
  | U | P | Z | A | P |
  ---------------------
  | C | W | U | O | O |
  ---------------------
  | V | C | V | G | Q |
  ---------------------
  | W | Z | M | L | Q |
  ---------------------
  */
  string sep_line = string(21,'-');
  cout<<" "<<sep_line<<"\n"<<" | ";
  for (int i=0;i!=20;i++) {
    if (i!=0&&i%5==0) {
      cout<<"\n "<<sep_line<<"\n | ";
    }
    cout<<(char)toupper(random_char_list[i])<<" | ";
  }
  cout<<"\n "<<sep_line<<"\n"<<endl;
}

bool word_gen::check_and_update(const string &users_word) {
  bool ret  =false;
  if (_anagram->check_word(users_word)) {
    ret =true;
    // only do anything if word is valid
  if(use_cnt%4==0) { // seed the engines every four turns
    update_engines();
  }
  use_cnt++; // increment use cnt
  int temp_loc =0;
 for( const char c : users_word) {

   /* for each char in use word
      first check if it is vowel or consonant
      and then replace it with a new character of its type
      and hence not affecting the position of any other character
    */
    temp_loc = random_char_list.find(c);
    if( consonants.find(c)!=string::npos) {
      random_char_list[temp_loc]  =gen_consonant();
    }
    else {
     random_char_list[temp_loc]  =gen_vowel();
    }
/* decrement the count of character of char box */
   decrement(c);

}
_anagram->set_random_string(random_char_list);
// update on the anagram side
// im saving a copy of the string on angram
// since the string has to be sorted for anagram to compare
}

 return ret;
 // return what anagram's check_word returns
}

void word_gen::update_engines() {
  // seed the main engine with time*use_cnt
  main_engine.seed(time(0)*use_cnt);
  vowels_engine.seed(main_engine());
  consonants_engine.seed(main_engine());
  // update the others with values from main engine
}

void word_gen::shuffle_new() {
  //sloppy way i guess
  int max_vowel_cnt = 5; // the maximum vowels
    int curr_vowel_cnt = 0;
    int next_vowel = 0; // holds when the next vowel should be generated

    for(int i=0;i!=20;i++) {
       /* if i is equal to next and havent already reached max
          then gen_vowel */
       if(next_vowel==i &&curr_vowel_cnt!=max_vowel_cnt) {
             random_char_list[i] = gen_vowel();
              next_vowel = i+vowels_next(vowels_engine);
              /* the next time the vowel will be made
               the random disribution gfor vowels_next
                between 1 and 4 so the next vowle will appeear after so much interval
               /*/
              curr_vowel_cnt++; // if curr_vowel_cnt reaches max then stop gen_vowel

       }
       else {
         random_char_list[i] = gen_consonant();
         // otherwise gen_consonant
       }
    }
}

void word_gen::decrement(char c) {
  if(char_box[c]==1) {
    char_box.erase(c); // if there is only one c in char_box
  /// then remove it
  // not required but makes it easy in gen_vowel and consonant
  }
  else {
    char_box[c]--; // otherwise it was 2 then decrement it to 1
  }
}
