#include "forwardlist.h"
#include "node.h"
#include <stdlib.h>

ForwardList::ForwardList() {
  this->m_head = nullptr;
  this->m_size = 0;
}

ForwardList::ForwardList(ForwardList &lst) : m_head(nullptr), m_size(0) {
  Node *second = lst.m_head;

  while (second) {
    push_back(second->getValue());
    second = second->getNext();
  }
}

ForwardList::~ForwardList() {}

int ForwardList::size() const { return this->m_size; }

bool ForwardList::empty() const { return !this->m_size; }

void ForwardList::clear() {
  Node *current = m_head;
  while (current->getNext()) {
    Node *nextNode = current;
    current = current->getNext();
    free(nextNode);
  }
  free(current);
}

Node *ForwardList::getNode(unsigned int index) {
  Node *current = m_head;
  for (unsigned int i = 0; i < index; ++i) {
    current = current->getNext();
  }

  return current;
}

int ForwardList::at(unsigned int index) const {
  if ((int)index >= m_size || empty()) {
    return -1;
  }

  Node *current = m_head;
  for (unsigned int i = 0; i < index; ++i) {
    current = current->getNext();
  }

  return current->getValue();
}

void ForwardList::push_back(int value) {
  if (empty()) {
    m_head = new Node(value, nullptr);
    m_size++;
    return;
  }

  Node *newNode = getNode(m_size++ - 1);
  newNode->setNext(new Node(value, nullptr));
}

int ForwardList::pop_back() {
  if (empty()) {
    return 0;
  }

  Node *current = m_head;

  if (!current->getNext()) {
    int value = current->getValue();
    free(current);
    m_head = nullptr;
    m_size = 0;
    return value;
  }

  while (current->getNext()->getNext()) {
    current = current->getNext();
  }

  Node *newNode = current->getNext();
  int value = newNode->getValue();
  free(newNode);
  current->setNext(nullptr);
  m_size--;
  return value;
}

void ForwardList::insert(int value, unsigned int index) {
  if (empty()) {
    push_back(value);
  }
  Node *outherNode = getNode(index - 1);
  Node *nextNode = new Node(value, outherNode->getNext());
  outherNode->setNext(nextNode);
  ++m_size;
}

void ForwardList::push_front(int value) {
  Node *newNode = new Node(value, m_head);
  m_head = newNode;
  ++m_size;
}

int ForwardList::pop_front() {
  if (empty()) {
    return 0;
  }

  Node *frontNode = m_head;
  int value = frontNode->getValue();
  m_head = m_head->getNext();
  free(frontNode);
  --m_size;

  return value;
}

void ForwardList::replaceAt(int value, unsigned int index) {
  Node *node = getNode(index);
  node->setValue(value);
}

void ForwardList::removeAt(unsigned int index) {
  if (!index) {
    pop_front();
    return;
  }

  Node *node = getNode(index - 1);
  Node *toDelete = node->getNext();
  node->setNext(toDelete->getNext());
  free(toDelete);
  --m_size;
}

void ForwardList::removeAll(int value) {
  if (empty())
    return;

  if (m_head->getValue() == value) {
    pop_front();
  }

  Node *cuurent = m_head->getNext();
  int i = 1;

  while (cuurent->getNext()) {
    if (cuurent->getValue() == value) {
      removeAt(i--);
      cuurent = getNode(i);
      continue;
    }

    cuurent = cuurent->getNext();
    i++;
  }

  if (cuurent->getValue() == value) {
    pop_back();
  }
}

bool ForwardList::equals(ForwardList &lst) {
  Node *headLst = lst.m_head;
  Node *current = m_head;

  while (current && headLst) {
    if (current->getValue() != headLst->getValue()) {
      return false;
    }
    current = current->getNext();
    headLst = headLst->getNext();
  }

  if (current != nullptr || headLst != nullptr) {
    return false;
  }

  return true;
}

void ForwardList::concat(ForwardList &lst) {
  if (empty()) {
    Node *headLst = lst.m_head;
    while (headLst) {
      push_back(headLst->getValue());
      headLst = headLst->getNext();
    }
  } else {
    Node *current = m_head;
    while (current->getNext()) {
      current = current->getNext();
    }

    Node *headLst = lst.m_head;
    while (headLst) {
      push_back(headLst->getValue());
      headLst = headLst->getNext();
    }
  }
}
