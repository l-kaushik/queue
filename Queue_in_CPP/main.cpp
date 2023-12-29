#include "Queue.h"

int main(){
    Node *temp = new Node(4);
    Node obj(temp);

    obj.getNextNode()->display();
    return 0;
}