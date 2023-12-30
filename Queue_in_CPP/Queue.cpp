#include "Queue.h"

// NODE

// constructors and destructors
Node::Node() : m_value(0), m_next(nullptr) {}
Node::Node(int value) : m_value(value) {}
Node::Node(Node *next) : m_next(next) {}
Node::Node(int value, Node *next)
    : m_value(value), m_next(next) {}

// Getters
int Node::getValue() const
{
    return m_value;
}

Node *Node::getNextNode() const
{
    return m_next;
}

// Setters
void Node::setValue(int value)
{
    m_value = value;
}

void Node::setNextNode(Node *next)
{
    m_next = next;
}

// Functions
void Node::display() const
{
    std::cout << "Value: " << m_value;
}

// QUEUE

// constructor and destructor
Queue::Queue() : m_first(nullptr), m_rear(nullptr) {}
Queue::Queue(std::initializer_list<int> values)
{
    initializer(values);
}

// Initializer
void Queue::initializer(std::initializer_list<int> list)
{
    for (int value : list)
    {
        enqueue(value);
    }
}

Queue::~Queue()
{
    while(!isEmpty())
        dequeue();
}

// Functions
void Queue::display() const
{
    Node *temp = m_first;
    while (temp != nullptr)
    {
        std::cout << temp->getValue() << ' ';
        temp = temp->getNextNode();
    }
}

void Queue::enqueue(int value)
{
    if (isEmpty())
        m_first = m_rear = new Node(value);
    else
    {
        m_rear->setNextNode(new Node(value));
        m_rear = m_rear->getNextNode();
    }
}

void Queue::dequeue()
{
   if(isEmpty())
   {
        Node *temp = m_first;
        m_first = m_first->getNextNode();
        delete temp;
   }
}

constexpr bool Queue::isEmpty()const
{
    return m_first == nullptr;
}

void Queue::clear()
{
    while(m_first != nullptr)
        dequeue();
}