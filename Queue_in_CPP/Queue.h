#ifndef QUEUE_H
#define QUEUE_H

// External required header file
#include "Node.h"

template <typename T>
class Queue
{
private:
    Node<T> *m_first{nullptr};
    Node<T> *m_rear{nullptr};

public:
    // constructor and destructor
    Queue();
    Queue(const Queue<T> &other); // copy constructor
    Queue(std::initializer_list<T> values);
    ~Queue();

    // Accessors
    T getFirst() const;
    T getLast() const;

    // Functions
    void display() const;
    void enqueue(T value);
    void dequeue();
    constexpr bool isEmpty() const;
    void clear();

    // Operator overloading
    Queue<T> &operator=(const Queue<T> &other);
};

//<--------------- METHOD DEFINITIONS --------------->

// constructor and destructor
template <typename T>
Queue<T>::Queue() : m_first(nullptr), m_rear(nullptr) {}

// copy constructor
template <typename T>
Queue<T>::Queue(const Queue<T> &other)
{
    *this = other;
}

template <typename T>
Queue<T>::Queue(std::initializer_list<T> values)
{
    for (T value : values)
    {
        enqueue(value);
    }
}

template <typename T>
Queue<T>::~Queue()
{
    while(!isEmpty())
        dequeue();
}

// Accessors
template <typename T>
T Queue<T>::getFirst() const
{
    return m_first->getValue();
}

template <typename T>
T Queue<T>::getLast() const
{
    return m_rear->getValue();
}

// Functions
template <typename T>
void Queue<T>::display() const
{
    Node<T> *temp = m_first;

    std::cout << "[";

    while (temp->getNextNode() != nullptr)
    {
        std::cout << temp->getValue() << ", ";
        temp = temp->getNextNode();
    }

    std::cout << temp->getValue() << "]\n";
}

template <typename T>
void Queue<T>::enqueue(T value)
{
    if (isEmpty())
        m_first = m_rear = new Node<T>(value);
    else
    {
        m_rear->setNextNode(new Node<T>(value));
        m_rear = m_rear->getNextNode();
    }
}

template <typename T>
void Queue<T>::dequeue()
{
    if (!isEmpty())
    {
        Node<T> *temp = m_first;
        m_first = m_first->getNextNode();

        if (m_first == nullptr)
            m_rear = nullptr;

        temp->setNextNode(nullptr);
        delete temp;
    }
}

template <typename T>
constexpr bool Queue<T>::isEmpty() const
{
    return m_first == nullptr;
}

template <typename T>
void Queue<T>::clear()
{
    while (m_first != nullptr)
        dequeue();
}

// Operator overloading
template <typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &other)
{
    if (this == &other)
        return *this;

    delete m_first;
    delete m_rear;

    m_first = nullptr;
    m_rear = nullptr;

    Node<T> *temp{other.m_first};

    while (temp)
    {
        if (m_first == nullptr)
        {
            m_first = new Node(other.m_first->getValue());
            m_rear = m_first;
        }
        else{
            m_rear->setNextNode(new Node(temp->getValue()));
            m_rear = m_rear->getNextNode();
        }
        temp = temp->getNextNode();
    }

    return *this;
}

#endif