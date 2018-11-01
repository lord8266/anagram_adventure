#ifndef game_loop
#define game_loop 1

class player;
class enemy;
class game_entity;

// -----------------------------------------------------------------------------------

class game {
public:
  game();
  void run(); // runs the game when running is true
  void end(); // after any one person (player or enemy lost)
  void update();// update here the damages are trasnferred
  void start();//start game
  void print_health_formatted(game_entity*);
  //prints health | player and enemy health is form game_entity

  bool running = false;
  bool error = false;
  //if any error occured
  //for now the only error is eof
  ~game();

private:
  player *_player =nullptr;
  enemy *_enemy =nullptr;
  bool chance =true;

private:
  string ending;
  string health_end;
  char *buffer =nullptr;
  // for printing

};

//------------------------------------------------------------------------------------
//not the best object oriented design

class game_entity {
  // this is the abstract base class for the player and all the enemies
  friend class game;
public:
  game_entity(const float&,const string&,game*);
  virtual float send_damage()=0;
  virtual void get_damage(const float&)=0;
  virtual ~game_entity()=default;//for now
protected:
  float health;
  string name;
  game *connection = nullptr;
  //connection to the game class
};

class enemy;

//-----------------------------------------------------------------------------------

class player :public game_entity  {
  friend class game;
  friend class enemy;
public:
  player(const string& name,const float& health,game*);
   float send_damage() override;
  void get_damage(const float&) override;
  //similar for both player and enemy
  ~player();
private:
  float dp ;
  //holds the last given damage
  string previous;
  //holds the previous word spelt
  word_gen *w1 = nullptr;
  //word_gen is required by player since it outputs damage from the word given
  //word gen will do all the work of checking the word
  enemy *target = nullptr;
  //the game class will take damage from this class and output it to this target

};

//------------------------------------------------------------------------------------

class enemy :public game_entity  {
  //enemy class is derived from game_entity
  //later this will be the abstract class for all enemy types
  friend class game;
  friend class player;
public:
  enemy(const string& name,const float& health,game*);
   float send_damage() override;
  void get_damage(const float&) override;
private:
  float dp ;
  //similar to player except there is no wordgen needed
  //as it outputs damage based on something else
  //for now it is the word spelt by the user in the previous turn
  player *target =nullptr;
};



#endif
