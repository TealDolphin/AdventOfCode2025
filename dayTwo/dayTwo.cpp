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
  while (getline (MyReadFile, fileLine, ',')) {
    long long val = 0;
    long long max = 0;

    int l = fileLine.find('-');

    val = stoll(fileLine.substr(0,l));
    //cout << val << endl;
    max = stoll(fileLine.substr(l+1));
    //cout << max << endl;

    while (val<=max){
      string check = std::to_string(val);
      int len = check.length() >> 1;
      if((len << 1) == check.length()){
        if(check.substr(0,len) == check.substr(len))answer += val;
      }
      val++;
    }
    //cout << "Answer: ";
    //cout << answer << endl;
  }
  cout << answer << endl;
  return 0;
}
