#include "Queue.h"
#include <string>

int main(){
   Queue<int> a({1,2,3,4,5});
   Queue<int> b(a);
   a.dequeue();
   b.display();
   a.display();
    
    return 0;
}