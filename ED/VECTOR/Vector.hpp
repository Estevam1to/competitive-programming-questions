#pragma once

#include <string>

class Vector{
    private:
        int *elements;
        unsigned int capacity;
        unsigned int tam;
    
    public:
        Vector();
        Vector(int n);
        Vector(Vector& vector);
        ~Vector();

        unsigned int size();
        const int& operator[](unsigned int index) const;

        bool empty();

        int getCapacity();

        void push_back(int value);
        int pop_back();
        void push_front(int value);
        int pop_front();

        void resize(unsigned int value);

        int at(unsigned int i);

        void replaceAt(unsigned int k, int value);

        void removeAt(unsigned int k);

    
        void insert(unsigned int k, int value);

        void removeAll(int value);

        void sort();
};
