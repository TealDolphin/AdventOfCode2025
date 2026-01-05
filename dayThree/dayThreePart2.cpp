//Advent of code day two
// check for phony IDs


#include <iostream>
#include <fstream>
using namespace std;


int findMax(const char *s, int start, int end){
  int max = 0;
  char c = '0';
  while(start < end){
    //cout << s[start] << endl;;
    if(s[start] > c){
      c = s[start];
      max = start;
    }
    start++;
  }
  return max;
}



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
    long long val = 0;
    int post;

    // one battery would be 0 so 12 is 11
    for(int desired = 11;desired>=0;desired--){
      loc_max = findMax(bank, pos, len-desired);
      val*=10;
      val+=(fileLine[loc_max]-'0');
      //cout << val << endl;
      //cin >> post;
      pos = loc_max+1;
    }
    answer+=val;
    cout << val << endl;
  }
  cout << answer << endl;
  return 0;
}
