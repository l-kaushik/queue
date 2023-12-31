#include "Queue.h"
#include <string>

int main(){
    Queue<std::string> abc({"Hello", "world", "glass", "monitor"});
    abc.display();
    abc.enqueue("sup boi");
    abc.enqueue("entry");
    abc.dequeue();
    abc.enqueue("harsh");
    abc.dequeue();
    abc.enqueue("rohit");
    abc.dequeue();
    abc.dequeue();
    abc.dequeue();
    abc.display();
    return 0;
}