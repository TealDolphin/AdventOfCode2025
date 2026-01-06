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
    bool newNode = true;

    Node* m = head->next;
    Node* prev = m;
    while(m != nullptr){
      if((from >= m->from) && (from <= m->to)){// lower in the range
        if((to >= m->from) && (to <= m->to)){//upper in the range and lower in the range
          //no further numbers to work with. Tell the node creation to skip this node
          to = 0; from = 0;
          break;
        }else{
          from = m->to + 1;
        }
      }else if((to >= m->from) && (to <= m->to)){//just upper in the range
        to = m->from - 1;
      }else if ((from <= m->from) && (to >= m->to)){//new input spans old input
        //discard old input
        prev->next = m->next;
        m = prev->next;
        continue;
      }
      prev = m;
      m = m->next;
    }

    // assuming we have any numbers left, make a new node
    if(to > from){
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
    //cout << n->from << "<>" << n->to << endl;
    answer += (n->to - n->from)+1;// +1 due to inclusive to inclusive?
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
