//list.h
//Patrick Polcuch
//2348668

//used to make my linked list use the functions of the list ADT
#include "LinkedList.h"

template <class type>
class list{
private:
  LinkedList <type>*mylist;
public:
  list(){
    mylist = new LinkedList<type>();
  }

  ~list(){
    delete mylist;
  }

  void Append(type x){
    mylist->insertBack(x);
  }

  void Prepend(type x){
    mylist->insertFront(x);
  }

  void InsertAfter(type w,type x){
    mylist->insertAfter();
  }

  void Remove(type x){
    int pos = mylist->find(x);
    mylist->deletePos(pos);
  }

  type Search(type x){
    if(mylist->find(x) != -1){
      return x;
    }
    return NULL;
  }

  void Print(){
    mylist->printList();
  }

  void PrintReverse(){
    mylist->printListReverse();
  }

  //void Sort(){}//dont need this right now

  bool IsEmpty(){
    return mylist->isEmpty();
  }

  unsigned int GetLength(){
    return mylist->getSize();
  }

  type RemoveFront(){
    return mylist->removeFront();
  }

  type PeekFirst(){
    return mylist->front->data;
  }

};
