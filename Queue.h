//GenQueue.h
#include "list.h"

template <class type>
class Queue{
public:
  Queue(){//defualt
    myQueue = new list<type>();
    numElements = 0;
  }

  ~Queue(){
    delete myQueue;
  }

  //core functions
  void insert(type d){//enqueue
    myQueue->Append(d);
    numElements++;
  }

  type remove(){//dequeue
    numElements--;
    return myQueue->RemoveFront();
  }

  //aux functions
  type peek(){
    return myQueue->PeekFirst();
  }

  bool isEmpty(){
    return (numElements == 0);
  }
  unsigned int getSize(){
    return numElements;
  }

private:
  unsigned int numElements;

  list <type>*myQueue;

};
