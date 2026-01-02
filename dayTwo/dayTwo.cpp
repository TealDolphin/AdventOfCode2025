//Advent of code day two
// check for phony IDs


#include <iostream>
#include <fstream>
using namespace std;

int main(){
  string fileLine;


  int answer = 0;

  ifstream MyReadFile("input.txt");

  //Read line by line, claims to drop the new line.
  while (getline (MyReadFile, fileLine, ',')) {
    stringstream ss(fileLine);
    int val = 0;
    int max = 0;
    string s;
    getline(ss, s,'-');
    val = stoi(s);
    getline(ss, s,'-');
    max = stoi(s);

    while (val<=max){
      string check = std::to_string(val);
      int len = check.length() >> 1;
      if((len << 1) == check.length()){
        if(check.substr(0,len) == check.substr(len))answer++;
      }
      val++;
    }
  }
  cout << answer;
  return answer;
}
