#include "Queue.h"
#include <string>

int main(){
   Queue<std::string> a({"Hello", "world"});
    a.display();
    return 0;
}