#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include "node.cpp"

class ForwardList {
private:
    Node* m_head; 
    int m_size;  
 
public:
    ForwardList();

    ForwardList(ForwardList& lst);
    
    ~ForwardList();

    int size() const;
    
    bool empty() const;

    void clear();
    
    Node* getNode( unsigned int index);

    int at(unsigned int index) const;

    void push_back(int value); 
    
   
    int pop_back(); 
    
    void insert(int value, unsigned int index);

    void removeAt(unsigned int index);
    
    void replaceAt(int value,  unsigned int index);
    
    void removeAll(int value);
    
    void push_front(int value);
    
    int pop_front();    
    
    bool equals(ForwardList& lst);
    

    void concat(ForwardList& lst);    
};

#endif
