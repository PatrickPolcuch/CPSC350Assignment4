//LinkedList.h
//Patrick Polcuch
//2348668
//Made this for CPSC350. Its a generic linked list 

#include <iostream>
#include <cstddef>//have to use this to use NULL

using namespace std;

template <class type>

class ListNode{
public:
  ListNode(){
    data = 0;
  }
  ListNode(type d){
    data = d;
    next = NULL;
    prev = NULL;
  }
  ~ListNode(){
    //need to look this one up
  }

  type data;
  ListNode *next;
  ListNode *prev;
};

template <class type>
class LinkedList{
public:
  ListNode <type>*front;
  ListNode <type>*back;
  unsigned int size;

  LinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
  }

  ~LinkedList(){
    //research this. textbook?
    ListNode <type>*curr = front;
    ListNode <type>*temp = curr;
    while(curr != NULL){
      ListNode <type>*n = curr->next;
      delete curr;
      curr = n;
    }
  }

  void insertFront(type d){
    ListNode <type>*node = new ListNode<type>(d);
    if(size == 0){
      back = node;
    }else{
      front->prev = node;
      node->next = front;
    }
    front = node;
    ++size;
  }

  void insertBack(type d){
    ListNode <type>*node = new ListNode<type>(d);

    if(size == 0){
      //empty list
      front = node;
      back = node;
    }else{
      back->next = node;
      back = node;
    }
    size++;
  }

  type removeFront(){
    type temp = front->data;
    ListNode <type>*ft = front;
    front = front->next;
    ft->next = NULL;
    size--;
    delete ft;
    return temp;
  }

  type removeBack(){
    type temp = back->data;
    ListNode <type>*bk = back;
    back = back->prev;
    back->prev = NULL;
    size--;
    delete bk;
    return temp;
  }

  void printList(){
    ListNode <type>*curr = front;

    while(curr != NULL){
      cout << curr->data<<endl;
      curr = curr->next;
    }
  }

  void printListReverse(){
    ListNode <type>*curr = back;

    while(curr != NULL){
      cout << curr->data<<endl;
      curr = curr->prev;
    }
  }

  int find(int value){
    int pos = -1;
    ListNode <type>*curr = front;

    while(curr != NULL){
      //iterate until we reach the end and hopefully we find what we are looking for
      ++pos;
      if(curr->data == value){
        break;
      }
      curr = curr->next;
    }

    if(curr == NULL){
      pos = -1;
    }

    return pos;
  }

  void deletePos(int pos){
    int p = 0;
    ListNode <type>*curr = front;
    while(p != pos){
      curr = curr->next;
      p++;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    size--;
  }

  bool isEmpty(){
    return (size == 0);
  }

  unsigned int getSize(){
    return size;
  }

  void insertAfter(type y, type x){
    int pos = -1;
    ListNode <type>*curr = front;

    while(curr != NULL){
      //iterate until we reach the end and hopefully we find what we are looking for
      ++pos;
      if(curr->data == y){
        break;
      }
      curr = curr->next;
    }
    ListNode <type>*node = new ListNode<type>(x);
    curr->next->prev = node;
    curr->next = node;
    size++;
  }

  //void sort(){}//dont need this right now
};
