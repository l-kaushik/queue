#include <iostream>

class Node
{
private:
    int m_value {0};
    Node* m_next {nullptr};
public:
    //constructors and destructors
    Node();
    Node(int value);
    Node(Node *next);
    Node(int value, Node *next);

    //Getters
    int getValue()const;
    Node* getNextNode()const;

    //Setters
    void setValue(int value);
    void setNextNode(Node *next);

    //Functions
    void display()const;
};

class Queue
{
private:
    Node * m_first{nullptr}; 
    Node * m_rear{nullptr};

    //Initializer
    void initializer(std::initializer_list<int> list);

public:
    //constructor and destructor
    Queue();
    Queue(const Queue &other);  //copy constructor
    Queue(std::initializer_list<int> values);
    ~Queue();

    //Accessors
    int getFirst()const;
    int getLast()const;

    //Functions
    void display()const;
    void enqueue(int value);
    void dequeue();
    constexpr bool isEmpty()const;
    void clear();

    //Operator overloading
    Queue &operator=(const Queue& other)
    {
        this->clear();
        
        Node *temp = other.m_first;

        while(temp != nullptr)
        {
            this->enqueue(temp->getValue());
            temp = temp->getNextNode();
        }

        return *this;
    }
};