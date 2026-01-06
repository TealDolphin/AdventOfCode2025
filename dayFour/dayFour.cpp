//Advent of code day four

/*
 * Adjacency map
 * ...
 * ...
 * ...
 * [-1,-1]...[1,1]
 */


#include <iostream>
#include <fstream>
using namespace std;

int main(){
  string fileLine;

  int rows = 142;
  int cols = 142;

  char map[cols][rows];
  for(int a = 0;a<rows;a++){
    map[0][a]='.';
    map[cols-1][a]='.';
  }

  int nRow = 1;

  long long answer = 0;

  ifstream MyReadFile("input.txt");

  //Read line by line, claims to drop the new line.
  while (getline (MyReadFile, fileLine)) {
    cout << nRow << endl;

    int len = fileLine.length();
    //const char *bank = fileLine.c_str();

    //cout << len << endl;

    map[nRow][0] = '.';map[nRow][cols-1]='.';
    for(int i = 0;i<len;i++){
      map[nRow][i+1] = fileLine[i];

      if(fileLine[i] != '.' && fileLine[i] != '@'){
        cout << nRow << "<>" << i << "<>" << fileLine[i] << endl;
      }

      //cout<<i<<endl;
    }
    //cout << map[nRow] << endl;
    nRow++;
  }
//cout << map << endl;
//cout << map[0] << endl;
//cout << map[0][0] << endl;
//cout << map[0][0][0] << endl;
  /*for(int a = 0;a<142;a++){
    cout << map[a] << endl;
    cin >> nRow;
  }*/


  // seperate search algorithm because the lines rely on the previous and next lines' input.
  for(int i = 1;i<(rows-1);i++){
    for(int j = 1;j<(cols-1);j++){
      //int adj = 0;
      //'.' = 46, '@' = 64, max 3 @
      //4*64+4*46=440
      long val = map[i-1][j-1]+map[i-1][j]+map[i-1][j+1]+map[i][j-1]+map[i][j+1]+map[i+1][j-1]+map[i+1][j]+map[i+1][j+1];
      //cout << val << endl;
      if(val < 440){
        answer++;
      }
    }
  }


  cout << answer << endl;
  return 0;
}
