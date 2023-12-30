#include "Queue.h"

int main(){
    Queue obj({1,2,3,4,5});
    Queue obj2(obj);
    obj2.display();

    return 0;
}