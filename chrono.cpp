#include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>
using namespace std;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

int main(){
  ushort millisec_since_epoch = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

  cout << millisec_since_epoch << endl;
  return 0;
}
