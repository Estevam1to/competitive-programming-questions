#ifndef NODE_H
#define NODE_H

class Node {
private:
  int value;
  Node *next;

public:
  Node(int val, Node *nextPtr);

  int getValue();
  Node *getNext();
  void setValue(int newValue);
  void setNext(Node *newNext);
};

#endif
