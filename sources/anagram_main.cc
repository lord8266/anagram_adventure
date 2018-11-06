#include "anagram_main.h"



int main() {

  game g1;
  while(g1.running) {
    g1.run();
  }
  //comes out when enemy or player has died

  //if came out because of error
  if(g1.error) {
    cout <<"an error occured in the game,sorry"<<endl;

  }
  else {
  g1.end();
}

  }
