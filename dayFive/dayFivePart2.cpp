//Advent of code day four



#include <iostream>
#include <fstream>
using namespace std;

struct Node{
  long from;
  long to;
  struct Node* next;
};



int main(){
  string fileLine;
  long long answer = 0;
  int l1 = 0;
  int l2 = 0;

  Node* head;
  Node* tail;

  head = new Node;
  tail = head;


  ifstream MyReadFile("input.txt");

  //Read line by line, claims to drop the new line.
  while (getline (MyReadFile, fileLine)) {
    //l1++;
    //int len = fileLine.length();
    //const char *bank = fileLine.c_str();
    if(fileLine == "")break;

    int l = fileLine.find('-');

    long from = stol(fileLine.substr(0,l));
    long to = stol(fileLine.substr(l+1));

    Node* m = head->next;
    while(m != nullptr){
      if((from >= m->from) && (from <= m->to)){
        if(to > m->to){
          m->to = to;
        }
        from = 0;
        to = 0;
        break;
      }else if((to >= m->from) && (to <= m->to)){
        if(from < m->from){
          m->from = from;
        }
        from = 0;
        to = 0;
        break;
      }

      m = m->next;
    }
    if(from != 0 && to != 0){
      Node* n = new Node;
      n->from = from;
      n->to = to;

      tail->next = n;
      tail = tail->next;
    }
  }

  Node* first = head;
  head = head->next;
  delete first;

  Node* n = head;

  while(n!=nullptr){
    answer += (n->to - n->from);
    n = n->next;
  }

  /*
  // Read in the values to query for the listed IDs
  while (getline (MyReadFile, fileLine)) {
    l2++;
    Node* n = head;
    long id = stol(fileLine);
    while(n != nullptr){
      if((id >= n->from) && (id <= n->to)){
        answer++;
        break;
      }
      n = n->next;
    }
  }*/

  //cout << l1 << "<>" << l2 << endl;

  cout << answer << endl;
  return 0;
}
