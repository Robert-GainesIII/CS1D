#include "queueLinked.h"
#include <iostream>
using namespace std;

int main(){
    linkedQueueType<double> list;
    list.addQueueFront(5);
    double temp;
    list.deQueueFront(temp);
    cout << temp << endl;
    return 0;
}