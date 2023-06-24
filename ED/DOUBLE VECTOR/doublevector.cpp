/**
 * @file doublevector.cpp
 * @authors Luis Estevam Rosa Chaves (536699), Gustavo Henrique Freitas de Sousa (535735)
 * @brief 
 * @date 2023-06-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include "doublevector.h"

#define VERIF_OP_VALID(index) ((int)index >= this->size() or this->empty())
#define SPACES_AVAILABLE_FRONT (this->m_head)
#define SPACES_AVAILABLE_BACK (this->m_capacity - this->m_tail) 

DoubleVector::DoubleVector() {
  this->m_capacity = 16;
  this->m_list = new int[this->m_capacity];
  this->m_head = 7;
  this->m_tail = 8;
  this->m_size = 0;
}

DoubleVector::DoubleVector(int n) {
  this->m_capacity = n;
  this->m_list = new int[this->m_capacity];
  this->m_tail = n - 1 - ((n - 1) / 2);
  this->m_head = this->m_tail - 1;
  this->m_size = 0;
}

DoubleVector::~DoubleVector() {
  if(!empty()) delete[] this->m_list;
}


bool DoubleVector::empty() {
  return !(this->size());
}

int DoubleVector::size() {
  return this->m_size;
}

void DoubleVector::push_front(int value){
  if(!SPACES_AVAILABLE_FRONT) {
    if(SPACES_AVAILABLE_BACK) {
      this->shift();
    } else {
      resize();
    }
  }

  this->m_list[this->m_head --] = value;

  this->m_size ++;
}

void DoubleVector::push_back(int value) {
  if (!SPACES_AVAILABLE_BACK) {
    if (SPACES_AVAILABLE_FRONT) {
      shift();
    } else {
      resize();
    }
  }

  if (SPACES_AVAILABLE_BACK) {
    m_list[m_tail++] = value;
    m_size++;
  } 
}

int DoubleVector::pop_back() {
  if(this->empty()) {
    return -1;
  }

  int element_rmv = this->at(this->size() - 1);

  this->m_size --;
  this->m_tail --;

  return element_rmv;
}

int DoubleVector::pop_front() {
  if(this->empty()) {
    return -1;
  }

  int element_rmv = this->at(0);

  this->m_size --;
  this->m_head ++;

  return element_rmv;
}

int DoubleVector::at(unsigned int index) {
  if(VERIF_OP_VALID(index)) {
    return -1;
  }

  int idx_real = this->m_head + index + 1;
  
  return this->m_list[idx_real];
}

void DoubleVector::resize() {
  int new_capacity = m_capacity * 2; // Duplica a capacidade atual

  int* new_list = new int[new_capacity]; // Cria um novo vetor com a nova capacidade

  // Copia os elementos do vetor antigo para o novo vetor
  for (int i = m_head; i <= m_tail; i++) {
    new_list[i] = m_list[i];
  }

  delete[] m_list; // Libera a memória alocada pelo vetor antigo

  m_list = new_list; // Atualiza o ponteiro do vetor para o novo vetor redimensionado
  m_capacity = new_capacity; // Atualiza a capacidade do vetor
}

void DoubleVector::shift() {
  int desloc = (m_capacity - size()) / 2; // Divide igualmente os espaços livres

  if (m_tail == m_capacity - 1) { // shift para a esquerda
    int new_m_head = m_head - desloc;
    for (int i = m_head; i <= m_tail; i++) {
      m_list[i - desloc] = m_list[i];
    }
    m_head = new_m_head;
    m_tail = m_tail - desloc;
  } else if (m_head == -1) { // shift para a direita
    int new_m_tail = m_tail + desloc;
    for (int i = m_tail; i >= 0; i--) {
      m_list[i + desloc] = m_list[i];
    }
    m_tail = new_m_tail;
    m_head = m_head + desloc;
  }
}
                                
void DoubleVector::remove(unsigned int index){
  if(VERIF_OP_VALID(index)){
    return;
  }

  int * new_vector = new int[this-> m_capacity];
  
  if (SPACES_AVAILABLE_FRONT < SPACES_AVAILABLE_BACK){
    for(unsigned int i = 0; i <= index; ++ i){
      new_vector[i] = this->at(i + 1);
    }
  } else {
    for(unsigned int i = this->size() - 1; i >= index; -- i){
      new_vector[i] = this->at(i - 1);
    }
  }

  delete[] this->m_list;
  m_list = new_vector;
}


void DoubleVector::removeAll(int value){
  for(unsigned int i = 0; (int)i < this->size(); ++i){
    if(this->at(i) == value){
      remove(i --); 
    }
  }
}

void DoubleVector::print() {
  for(int i = 0; i < this->size(); ++ i) {
    printf("%d ", this->at(i));
  }
}

void DoubleVector::printReverse(){
  for(int i = this->size() - 1; i >= 0; -- i) {
    printf("%d ", this->at(i));  
  }
}

void DoubleVector::concat(DoubleVector& lst){
  for(int i = 0; i < lst.size(); ++ i){
    this->push_back(lst.at(i));
  }
}

bool DoubleVector::equals(DoubleVector& lst){
  if(this->size() != lst.size()) {
    return false;
  }
  
  for(int i = 0; i < this->size(); ++ i) {
    if(this->at(i) != lst.at(i)) {
      return false;
    }
  }
  
  return true;
}

void DoubleVector::replaceAt(int value, unsigned int index) {
  if(VERIF_OP_VALID(index)) {
    return;
  }
  
  this->m_list[index] = value;
}

void DoubleVector::insert(int value, unsigned int index) {
  if(this->size() == this->m_capacity) {
    resize();
  }

  if(!index) {
    this->push_front(value);
  }else if(index == this->size() - 1) {
    this->push_back(value);
  } else if(SPACES_AVAILABLE_FRONT < SPACES_AVAILABLE_BACK) {
    for(int i = this->m_tail; i > index; -- i) {
      this->replaceAt(this->at(i + 1), i);
    }
  } else {
    for(int i = 0; i < index; ++ i) {
      this->replaceAt(this->at(i), i + 1);
    }
  }
}