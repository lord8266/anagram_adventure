#include "anagram_main.h"

// ------------------------------ constructors --------------------------------------
game_entity::game_entity(const float& h,const string& name,game* g):
health(h),name(name),connection(g) { }

player::player(const string& name,const float& health,game* g):
game_entity(health,name,g),w1(new word_gen("word_refined.txt")) {
}

enemy::enemy(const string& name,const float& health,game* g):
game_entity(health,name,g) {

 }

 game::game():_player(new player("silver",50,this)),
              _enemy(new enemy("steel",50,this)),
   //both enemy and player have same starting health
 ending(60,'-'),health_end(30,'+'),buffer(new char[100]) {
   //the extras are for internal use (for printing )
   _player->target = _enemy;
   _enemy->target = _player;
   //set the targets for player and enemy
   running =true;
   //set running to true
  }


 //---------------------------------------player functions --------------------------------------------

float player::send_damage() {
  //for now return length percent
  cout<<"Word list->\n"<<endl;

  string temp;
  w1->print_formatted();
  // prints the word list in bx format
  cout<<"\nEnter your word: ";
   cin>>temp;
    while(!w1->check_and_update(temp)) { // check and update returns true if word was valid
      cout<<"try again"<<endl;
      cin>>temp;
      if(!cin) {
        connection->running =false;
        connection->error =true;
        return 0.f;
      }
    }
  dp = temp.size()*5+2;
  // the damage calculator for now

  cout<<"\nword: "<<temp <<" outputs: "<<dp<<" damage"<<endl;
  previous =temp; // setting previous to temp (the word which user sent)
  //so that enemy can produce damage from this word

  return dp;
}

void player::get_damage(const float& dp) {
  //remove that much percent health
  health-=dp;
}

//------------------------------- enemy functions --------------------------------------



float enemy::send_damage() {
  string temp =target->previous; // the previous word user sent

  // the enemy for now sends damage half of that of what the player sent for now
  dp =(temp.size()*5+2)/2.f;
  cout<<"Sending damage: "<<dp<<endl;
  return dp;
}

void enemy::get_damage(const float& dp) {
  //
  //remove that much  health
  health-=dp;
  // if health goes below zero then the se3nder of damage wins
  if(health<=0) {
    connection->running =false;
  }
}

//-------------------------- game functions ---------------------------



 void game::run() {

     update(); //for now call update
     if(running) {
       cout<<health_end<<endl;
      cout<<"enemy : ";
      print_health_formatted(_enemy);
      cout<<"player: ";
      print_health_formatted(_player);
      cout<<health_end<<endl;

      chance=!chance;
     //every run show the health of person and enemy
   }
   cout<<"\n"<<ending<<"\n"<<endl;

 }

 void game::update(){
   cout<<"chance of: ";
   if(chance) {
     cout<<"player: "<<_player->name<<" \n"<<endl;
     _enemy->get_damage(_player->send_damage());
     // the send damage from player goes to enemy get damage
   }
   else {
      cout<<"enemy: "<<_enemy->name<<" \n"<<endl;
     _player->get_damage(_enemy->send_damage());
   }
 }

void game::start() {
  // printing start message
  cout<<"In this game you will be given a set of letters"<<endl;
  cout<<"You need to spell a word and damage would depend on "<<endl;
  cout<<"how big your word is and some more extras\n"<<endl;

  cout<<"player: "<<_player->name<<" starts"<<endl;

}

 void game::end() {
   //end game result
   if(chance) {
     cout<<"Player wins"<<endl;

   }
   else {
     cout<<"enemy wins"<<endl;
   }
 }

void game::print_health_formatted(game_entity* ge) {
  float health = ge->health;
  sprintf(buffer,"%-10s",ge->name.c_str());
  cout<<buffer;
  string temp_h(health,'=');
  sprintf(buffer,"|%-50s|",temp_h.c_str());
  cout<<buffer<<endl;
}
 //---------------------------- destructors ----------------------------

 game::~game() {
   delete _player;
   delete _enemy;
 }

player::~player() {
  delete w1;
  // w1 is the wordgen class(the class which checks if the word is correct and updates list)
}

//----------------------------------------------------------------------
