#include "node.h"

Node::Node(int val, Node *nextPtr)
{
    this->value = val;
    this->next = nextPtr;
}

int Node::getValue()
{
    return this->value;
}

Node *Node::getNext()
{
    return this->next;
}
void Node::setValue(int newValue)
{
    this->value = newValue;
}

void Node::setNext(Node *newNext)
{
    this->next = newNext;
}