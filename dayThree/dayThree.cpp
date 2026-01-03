//Advent of code day two
// check for phony IDs


#include <iostream>
#include <fstream>
using namespace std;

int main(){
  string fileLine;


  long long answer = 0;

  ifstream MyReadFile("input.txt");

  //Read line by line, claims to drop the new line.
  while (getline (MyReadFile, fileLine)) {
    int len = fileLine.length();
    const char *bank = fileLine.c_str();
    int pos = 0;
    int loc_max = 0;
    char max = '0';
    int pair;


    //cout << max << endl;

    // don't visit the final battery otherwise you won't make a two digit number
    while(pos < (len-1)){
      //cout << bank << "<>" << max << endl;
      if(bank[pos] > max){
        max = bank[pos];
        loc_max = pos;
      }
      pos++;
    }
    pair = (max - '0')*10;
    pos = loc_max+1;
    max = '0';
    //cout << max << endl;
    //search through the rest of the list for the largest battery to the right of it.
    while(pos < len){
      if(bank[pos] > max){
        max = bank[pos];
        loc_max = pos;
      }
      pos++;
    }
    pair+=(max-'0');
    //cout << pair << endl;
    answer+=pair;
  }
  cout << answer << endl;
  return 0;
}
