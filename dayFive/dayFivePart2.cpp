//Advent of code day four



#include <iostream>
#include <fstream>
using namespace std;

struct Node{
  long from = 0;
  long to = 0;
  Node* next = NULL;
  bool defunct = false;
};



int main(){
  string fileLine;
  long long answer = 0;
  //long l1 = 0;
  //long l2 = 0;

  Node* head = NULL;
  Node* tail = NULL;
  //cout << head << endl;

  ifstream MyReadFile("test.txt");


  //Read line by line, claims to drop the new line.
  while (getline (MyReadFile, fileLine)) {
    //l1++;
    //int len = fileLine.length();
    //const char *bank = fileLine.c_str();
    if(fileLine == "")break;

    int l = fileLine.find('-');

    long from = stol(fileLine.substr(0,l));
    long to = stol(fileLine.substr(l+1));
    //bool newNode = true;

    Node* n = new Node;
    n->from = from;
    n->to = to;
    n->defunct = false;
    //cout << n->from << "<>" << n->to << endl;
    //cout << n << endl;
    //cout << head << endl;
    //cout << !head << endl;

    if(head == NULL){
      //cout << n->from << "<>" << n->to << endl;
      head = n;
      tail = n;
      continue;
    }
    int changed = 1;
    Node* place;

    while(changed > 0){
      changed = 0;
      place = head;

      while(place != 0){
        //cout << n->from << "<>" << n->to << endl;
        // rather than dropping the node instantly, I mark is as not usable.
        if(place->defunct){
          place = place->next;
          continue;
        }
        if((place->next) && place->next->defunct){
          place->next = place->next->next;
        }
        // check for node throw away
        if((place->from <= n->from) && (place->to >= n->to)){
          changed = 2;
          break;
        }
        // new node totally outside old node
        if((place->from > n->to) || (place->to < n->from)){
          place = place->next;
          continue;
        }

        // new node lower bound already accounted for
        if(place->to >= n->from){
          n->from = place->to + 1;
          changed = 1;
        }

        // new node upper bound already accounted for
        if(place->from <= n->to){
          n->to = place->from + 1;
          changed = 1;
        }

        // new node surrounds old node
        if((place->from >= n->from) && (place->to <= n->to)){
          place->defunct = true;
          changed = 1;
        }

        // the new node would be 0 or less numbers, exit
        if(n->from > n->to){
          changed = 2;
          break;
        }
        place = place->next;
      }
      if(changed == 2) break;
    }


    if(changed == 0){
      tail->next = n;
      tail = tail->next;
      //cout << n->from << "<>" << n->to << endl;
    }
  }


  Node* p = head;
  while(p != 0){
    cout << p->defunct << endl;
    cout << answer << endl;
    if(p->defunct == false){
      // input is inclusive, but subtraction is non-inclusive.
      answer += ((p->to + 1) - p->from);
    }
    p = p->next;
  }

    /*
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
