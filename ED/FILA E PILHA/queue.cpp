#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "queue.h"
#include <stdexcept>

template <typename T> Queue<T>::Queue() {
  m_first = nullptr;
  m_last = nullptr;
  m_size = 0;
}

template <typename T> Queue<T>::Queue(Queue<T> &lst) {
  m_first = nullptr;
  m_last = nullptr;
  m_size = 0;
  Node<T> *current = lst.m_first;
  while (current != nullptr) {
    push(current->value);
    current = current->next;
  }
}

template <typename T> Queue<T>::~Queue() { 
  clear(); 
}

template <typename T> int Queue<T>::size() { 
  return m_size; 
}

template <typename T> bool Queue<T>::empty() { 
  return m_size == 0; 
}

template <typename T> void Queue<T>::clear() {
  while (!empty()) {
    pop();
  }
}

template <typename T> void Queue<T>::push(T value) {
  Node<T> *newNode = new Node<T>(value, nullptr);
  if (empty()) {
    m_first = newNode;
    m_last = newNode;
  } else {
    m_last->setNext(newNode);
    m_last = newNode;
  }
  m_size++;
}

template <typename T> T Queue<T>::pop() {
  if (empty()) {
    throw std::runtime_error("Empty queue.");
  }
  Node<T> *temp = m_first;
  T value = temp->getValue();
  m_first = m_first->getNext();
  delete temp;
  m_size--;
  return value;
}

#endif