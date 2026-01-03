//Advent of code day two
// check for phony IDs


#include <iostream>
#include <fstream>
using namespace std;


//recursion because it's easy to compartmentalize
// checks if
bool repeats(string key, string search){
  // base case, it's either equal or not
  if(key == search){
    return true;
  }
  if(key.length() >= search.length())return false;
  // check case, if it has the pattern next, continue with the rest of the string
  if(key == search.substr(0,key.length()))return repeats(key, search.substr(key.length()));
  return false;
}


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
    max = stoll(fileLine.substr(l+1));

    // starting at val loop through IDs until the max value to check
    while (val<=max){
      string check = std::to_string(val);

      //cout << "val:" << val << " max:" << max << endl;

      int len = 1;
      string pattern = "";
      int toCheck = (check.length()/2)+1;

      // check if the current value is patterned
      while(len <= toCheck){
        pattern = check.substr(0,len);
        if(pattern == check)break;
        //cout << len << "-" << toCheck << endl;

        //cout << val << endl;
        if(repeats(pattern,check)){
          //cout << "pattern:" << pattern << " check:" << check << endl;
          //cout << answer << endl;
          //cout << val << endl;
          answer+=val;
          break;
        }
        len++;
      }

      val++;
    }
    //cout << "Answer: ";
    //cout << answer << endl;
  }
  cout << answer << endl;
  return 0;
}

