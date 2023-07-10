#include <iostream>
#include <chrono>
#include <sys/time.h>
#include <ctime>
using namespace std;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

int main()
{
  string pl_hand, cp_hand;
  uint cph;

  cout << "Let's play janken!" << endl;
  cout << "input your hand (rock or scissor or paper)";
  cin >> pl_hand;

  uint millisec_since_epoch = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
  cph = millisec_since_epoch % 3;
  
  if (cph == 0) {
    cp_hand = "rock";
  } else if (cph == 1) {
    cp_hand = "scissor";
  } else {
    cp_hand = "paper";
  }
  
  printf ("cp hand is %s\n", cp_hand.c_str());

  if ((pl_hand == "rock") && (cp_hand == "scissor")
      || (pl_hand == "scissor") && (cp_hand == "paper")
      || (pl_hand == "hand") && (cp_hand == "rock")) {
    printf("%s vs %s --- You won!", pl_hand.c_str(), cp_hand.c_str());
  } else if ((pl_hand == "rock") && (cp_hand == "paper")
	     || (pl_hand == "scissor") && (cp_hand == "rock")
	     || (pl_hand == "paper") && (cp_hand == "scissor")) {
    printf("%s vs %s --- You lose...", pl_hand.c_str(), cp_hand.c_str());
  } else if ((pl_hand == "rock") && (cp_hand == "rock")
	     || (pl_hand == "scissor") && (cp_hand == "scissor")
	     || (pl_hand == "paper") && (cp_hand == "paper")) {
    printf("%s vs %s --- Draw", pl_hand.c_str(), cp_hand.c_str());
  } else {
    cout << "you idiot... see you" << endl;
  }
  return 0;
}
