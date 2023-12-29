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
public:
    //constructor and destructor
    Queue();
    Queue(std::initializer_list<int> values);

    //Initializer
    void initializer(std::initializer_list<int> list);

    //Functions
    void display()const;
};