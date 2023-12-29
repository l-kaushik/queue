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