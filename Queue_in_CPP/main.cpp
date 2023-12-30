#include "Queue.h"

int main(){
    Queue obj({1,2,3,4,5});
    obj.enqueue(6);
    obj.enqueue(1);
    obj.enqueue(2);
    obj.display();
    return 0;
}