#include "Vector.hpp"

Vector::Vector(){
    this->capacity = 16;
    this->elements = new int[this->capacity];
    this->tam = 0;
}

Vector::Vector(int n){
    this->capacity = n;
    this->elements = new int[this->capacity];
    this->tam = 0;
}

Vector::Vector(Vector& vector){
    if(this != &vector){
        this->capacity = vector.getCapacity();
        this->elements = new int[this->capacity];
        this->tam = vector.size();

        for(int i = 0; i < vector.size(); ++i){
            this->elements[i] = vector[i];
        }
    }
}

Vector::~Vector(){ }

bool Vector::empty(){
    if(this->tam == 0)
        return true;

    return false;
}

unsigned Vector::size(){
    return this->tam;
}

int Vector::getCapacity(){ 
    return this->capacity;
}

const int& Vector::operator[](unsigned int index) const{
    return this->elements[index];
}

void Vector::push_back(int value){
    if(this->capacity == this->tam){
        resize(this->capacity * 2);
    }

    this->elements[this->tam] = value;
    this->tam++;
}

void Vector::push_front(int value) {
    if (this->capacity == this->tam) {
        resize(this->capacity * 2);
    }

    for (int i = this->tam; i > 0; i--) {
        this->elements[i] = this->elements[i - 1];
    }

    this->elements[0] = value;
    this->tam++;
}

int Vector::pop_back(){
    if(this-> tam > 0){
        this->tam--;
        return this->elements[this->tam];
    }
    return -1;
}

int Vector::pop_front() {
    if (this->tam > 0) {
        int *new_array = new int[this->capacity];
        int aux = this->elements[0];
        for (unsigned int i = 1; i < this->tam; ++i) {
            new_array[i - 1] = this->elements[i];
        }
        delete[] this->elements;
        this->elements = new_array;
        this->tam--;
        return aux;
    }
    return -1;
}

void Vector::resize(unsigned int new_size){
    if(new_size > this->capacity){
        this->capacity = new_size;
        int *new_array = new int[this->capacity];
        for(unsigned int i = 0; i < this->tam; ++i){
            new_array[i] = this->elements[i];
        }
        delete[] this->elements;
        this->elements = new_array;
    }else if(new_size < this->tam){
        if(this->tam > this->capacity){
            this->tam = new_size; 
        }
        this->tam = new_size;
    }
}

int Vector::at(unsigned int index){
    if(index < this->tam){
        return this->elements[index];
    }
    return -1;
}

void Vector::replaceAt(unsigned int index, int value){
    if(index < this->tam)
        this->elements[index] = value;
}

void Vector::removeAt(unsigned int index) {
    if (index < this->tam) {
        if (index == 0)
            pop_front();
        else if (index == size() - 1)
            pop_back();
        else {
            int *new_vector = new int[this->capacity];
            for (unsigned int i = 0, j = 0; i < this->tam; ++i, ++j) {
                if (i == index) {
                    --j;
                    continue;
                } else
                    new_vector[j] = this->elements[i];
            }
            delete[] this->elements;
            this->elements = new_vector;
            this->tam--;
        }
    }
}

void Vector::insert(unsigned int index, int value){
    if(this->tam == this->capacity)
        resize(this->capacity * 2);

    if(index < this->tam){
        int *new_vector = new int[this->capacity];
        for(unsigned int i = 0, j = 0; i < this-> tam; ++i, ++j){
           if(i < index){
            new_vector[j] = this->elements[i];
           }else if(j == index){
            new_vector[j] = value;
            i--;
           }else{
            new_vector[j] = this->elements[i];
           }
        }
        delete[] this->elements;
        this->elements = new_vector;
        this-tam++;
    }
}

void Vector::removeAll(int value) {
    for (unsigned int i = 0; i < this->tam; i++) {
        if (this->elements[i] == value) {
            removeAt(i--);
        }
    }
}
void swap(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}

int partition(int *vet, int ini, int fim){
    int pivot = vet[ini];
    int i = ini;

    for(int j = ini + 1; j <= fim; ++j){
        if(vet[j] <= pivot){
            swap(vet[++i], vet[j]);
        }
    }

    swap(vet[ini], vet[i]);

    return i;
}

void quickSort(int *vet, int ini, int fim){
    if(ini < fim){
        int index = partition(vet, ini, fim);
        quickSort(vet, ini, index - 1);
        quickSort(vet, index + 1, fim);
    }
}

void Vector::sort(){
    quickSort(elements, 0, size() - 1);
}

