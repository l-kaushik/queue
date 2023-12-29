#include "Queue.h"

//NODE

//constructors and destructors
Node::Node() : m_value(0), m_next(nullptr){}
Node::Node(int value) : m_value (value){}
Node::Node(Node *next) : m_next (next){}
Node::Node(int value, Node *next)
    :m_value (value), m_next (next) {}

//Getters
int Node::getValue() const
{
    return m_value;
}

Node* Node::getNextNode() const
{
    return m_next;
}

//Setters
void Node::setValue(int value, Node* next)
{
    m_value = value;
    m_next = next;
}

//Functions
void Node::display() const
{
    std::cout<<"Value: "<<m_value;
}
