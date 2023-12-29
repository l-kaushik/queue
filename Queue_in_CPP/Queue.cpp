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
void Node::setValue(int value)
{
    m_value = value;
}

void Node::setNextNode(Node *next)
{
    m_next = next;
}

//Functions
void Node::display() const
{
    std::cout<<"Value: "<<m_value;
}

//QUEUE

//constructor and destructor
Queue::Queue() :m_first(nullptr), m_rear(nullptr){}
Queue::Queue(std::initializer_list<int> values)
{
    initializer(values);
}

//Initializer    
void Queue::initializer(std::initializer_list<int> list)
{
    for(int value: list)
    {
       if(m_first == nullptr)
            m_first = m_rear = new Node(value);
        else if(m_rear->getNextNode() == nullptr)
        {
            m_rear->setNextNode(new Node(value));
            m_rear = m_rear->getNextNode();
        }
        else
            m_rear = m_rear->getNextNode();
    }
}

//Functions
void Queue::display()const
{
    Node *temp = m_first;
    while(temp != nullptr)
    {
        std::cout<<temp->getValue()<<' ';
        temp = temp->getNextNode();
    }
}