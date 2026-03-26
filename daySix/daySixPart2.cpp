//Advent of code day four



#include <iostream>
#include <fstream>
using namespace std;



int main(){
  string fileLine;
  long long answer = 0;

  // 4 input rows
  int numbers[4][1200];

  for(int b = 0;b<1200;b++){
    numbers[0][b] = 0;
    numbers[1][b] = 0;
    numbers[2][b] = 0;
    numbers[3][b] = 0;
  }


  int j = 0;
  char opp[1200];

  string input[5];

  ifstream MyReadFile("input.txt");

  //Read line by line, claims to drop the new line.
  while (getline (MyReadFile, fileLine)) {
    input[j++] = fileLine;
  }

  cout << input[0][3733] << endl;

  int i = 0;
  int o = 0;
  j = 0;
  while(input[0][i] != 0){
    int num[4];
    num[0] = input[0][i];
    num[1] = input[1][i];
    num[2] = input[2][i];
    num[3] = input[3][i];

    if(input[4][i] != ' '){
      opp[o++] = input[4][i];
      opp[o] = 0;
    }

    //cout << num[0] << '/' << num[1] << '/' << num[2] << '/' << num[3] << endl;
    //cout << opp[o-1] << endl;

    if((num[0] == ' ') && (num[1] == ' ') && (num[2] == ' ') && (num[3] == ' ')){
      j = 0;
    }else{
      int n = 0;

      for(int q = 0; q<4;q++){
        if(num[q] != ' '){
          n = (n*10) + (num[q]-'0');
        }
      }
      cout << n << endl;
      numbers[j++][o-1] = n;
    }
    i++;
  }
  //cout << i << endl;






    /*
    int i = 0;
    int num = 0;

    string::iterator c;
    for(c = fileLine.begin(); c != fileLine.end(); c++){
      //cout << *it << endl;
      if((*c >= '0') && (*c <= '9')){
        num = (num*10) + (*c - '0');
        // always stores the current number, so whenever it is done we already have the correct number stored
        numbers[j][i] = num;
        numbers[j][i+1] = 0; // submitting a 0 termination in the next spot allows us to check for next entry, and EOF behavior when running the arithmetic.
      }else if(*c == '*' || *c == '+'){
        // completely handles the addition or multiplication ingress by itself
        opp[i++] = *c;
        opp[i] = 0;
      }else if(j < 4){
        // if we are ingressing numbers, check to see if we need to advance to the next number
        if(numbers[j][i] != 0){
          i++;
          num = 0;
        }
      }
    }*/



    /*
      char *c = &fileLine;
      cout << fileLine << endl;
      cout << c << endl;
      cout << typeid(fileLine).name() << endl;

    j++;
  }*/


  int k = 0;
  int a[2] = {0,0};
  // I set the opperator function to '+' or '*' with a trailing 0
  while (opp[k] != 0){
    //cout << opp[k] << ",";
    //cout << numbers[0][k] << " " << numbers[1][k] << " " << numbers[2][k] << " " << numbers[3][k] << " " << opp[k] << endl;
    if(opp[k] == '+'){
      long long p = numbers[0][k];
      p = p + numbers[1][k];
      p = p + numbers[2][k];
      p = p + numbers[3][k];
      answer += p;
      a[0]++;
    }else if(opp[k] == '*'){
      long long p = numbers[0][k];
      if(numbers[1][k] != 0`){

      }
      p = p * numbers[1][k];
      p = p * numbers[2][k];
      p = p * numbers[3][k];
      answer += p;
      a[1]++;
    }else{
      cout << "Panic.png" << endl << endl << endl;
    }
    k++;
  }
  //cout << k << endl;
  //cout << numbers[0][k] << " " << numbers[1][k] << " " << numbers[2][k] << " " << numbers[3][k] << " " << opp[k] << endl;
  //cout << endl << a[0] << "/" << a[1] << endl;
  cout << answer << endl;
  return 0;
}
