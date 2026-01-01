//Advent of code day one
// lock picking, check for land on zero

#include <iostream>
using namespace std;

int main(){
  string fileLine;

  // dial starts at 50 and goes left and right from there.
  int dial = 50;
  /*int dial[100];

  for (int i = 0; i<100; i++){
    dial[i] = i;
  }*/

  int answer = 0;

  ifstream MyReadFile("dayOne.txt");

  //Read line by line, claims to drop the new line.
  while (getline (MyReadFile, fileLine)) {
    //Left or Right
    char direction = fileLine.substr(0,1);
    try{
      //should be a single number to end of line
      int clicks = (int) fileLine.substr(1);
    }catch(){
      cout << "Impropper input formatting";
    }

    // spin the dial
    if(direction == 'L'){
      dial = dial - clicks;
    }else if(direction == 'R'){
      dial = dial + clicks;
    }else{
      cout << "Impropper directional input.";
    }

    //bounding as the dial goes from 0-99
    while(dial < 0)dial = dial + 100;
    while(dial > 99)dial = dial - 100;
    if(dial == 0)answer++;

  }
}
