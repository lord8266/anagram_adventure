#include<iostream>
#include<cstdlib>
#include<fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void printLettersInAGrid(const string&);

//----------------------- globals ------------------------------
using set_str=set<string>;
set_str dictionary;
string base(20,' ');//i dont know how to allocate string
//---------------------------------------------------------

bool check_word(string word,string base) {
  sort(word.begin(),word.end());
  sort(base.begin(),base.end());
  //sort both the words
  //notice im making a copy here
  int off=0; //offset for the base word
  //the base will always be bigger than the word

  bool ret=true;
  for (int i=0;i!=word.size();) {

    if (word[i]==base[i+off]) {
      i++;
      off++; //if letter matches move to next letter
      //since they are sorted they will match in an order
    }
    else
      off++;//if not found chck if the letter is the next alphabet in base

    if(off==base.size()) {
      ret=false;//if the base end is reached then word cant be spelt from the list

      break; //break out of the loop and return false

    }
  }

  return ret;
}

void readFile(set_str& dictionary)
{
    ifstream f("word_refined.txt");
    string word;
    //append each word onto dictionary
    while(getline(f,word))
        {
            dictionary.insert(word);
        }
}

//every turn a new random string is generated

void makeRandomLetters(string &base) // Creates a sequence of 20 random letters consisting 5 vowels and 15 consonants.
{
    srand(time(0));
    int vowelCount=0;
    int consonantCount=0;
    char vowels[] { 'a','e','i','o','u'};
    for(int i=0;i<20;i++)
    {

        base[i]=rand()%26;
        base[i]+=97;//get it to the ASCII range

        if(base[i]=='a' || base[i]=='e' ||base[i]=='i' ||base[i]=='o' || base[i]=='u' )
            ++vowelCount; //if vowel was generated increment count
        else
            ++consonantCount;

        if(consonantCount>15) // if there are already 15 consonants
        {
           // --i could be done to rewrite the char again
           //but in practice that would take a long time
           //so make a new vowel here itself
            base[i]=rand()%5; // 5 vowels
            //append a vowel instead
            base[i]=vowels[(int)base[i]];
            --consonantCount;
            //decrement count so that this is not carried over to the next loop

        }
        if(vowelCount>5) // if 5 vowels are already there
        {
            --i; // rewrite the char
            --vowelCount; //dont let this carry over
        }
    }
    printLettersInAGrid(base);
}

void printLettersInAGrid(const string& base)
{
    cout<<" ---------------------\n";
    for(int i=0;i<4;i++)
    {
        cout<<" |";
        for(int j=0;j<5;j++)
        {
            cout<<" "<<(char)(base[i*5+j]-32)<<" |";
        }
        cout<<"\n ---------------------\n";
    }

}
int main()
{
    makeRandomLetters(base);
    readFile(dictionary);
    string temp;

    while (cin>>temp) {
    if(dictionary.find(temp)!=dictionary.end()) {
      //check if the word is present in the dictionary
      if(check_word(temp,base))
        cout<<"word possible"<<endl;
      else
        cout<<"word not possible"<<endl;
    }
    else  {
       cout<<"hiya iya!"<<endl;
  }
  }
}
