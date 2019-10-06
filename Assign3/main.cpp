#include <iostream> 
#include "queueArray.h"
#include "queueLinked.h"

using namespace std;

int main(){
    cout << "Assignment 3 Queues and Deques" << endl;
    cout << "Date due: September 23" << endl;
    cout << "Purpose: Demonstrate knowledge and ability to implement queues and deques" << endl;
    cout << "Either as a linked list or a circular array." << endl;


   string sData[] = {"Mark", "Alan", "Jennifer", "Sonny", "Eric", "JoAnn", "Bill"};
   double dData[] = {983.3, 44.44, 888.55, 99.99, 123.123, 8.445};

    cout << "Part A: using my array based queue load in the strings and doubles." << endl;

    queueType<string> stringQueue;
    for(int i = 0; i < 7; i++){
        stringQueue.addQueue(sData[i]);
    }

    stringQueue.print();

    queueType<double> doubleQueue;

    for(int i = 0; i < 6; i++){
        doubleQueue.addQueue(dData[i]);
    }

    doubleQueue.print();

    cout << "Part B: Delete Sonny and 99.99 from the above queues (you will need to delete others)" << endl
         << "and print the remaining elements in the queues. Do not use the STL." << endl;

    string queueType;
    do{
       stringQueue.deQueue(queueType);
       cout << "Item dequeued : " << queueType << endl;
    }
    while(queueType.compare("Sonny") != 0);

    stringQueue.print();

    stringQueue.destroyQueue();

    double x;
    do{
       doubleQueue.deQueue(x);
       cout << "Item dequeued : " << x << endl;
    }
    while(x != 99.99);

    doubleQueue.print();

    doubleQueue.destroyQueue();

    cout << "Part C: " <<  "Implement and print the deques using a linked list using the above data (using push front)." << endl;

    linkedQueueType<string> deckS;
    linkedQueueType<double> deckD;

    for(int i = 0; i < 7; i++){
        deckS.addQueueFront(sData[i]);
    }
    deckS.print();

    for(int i = 0; i < 6; i++){
        deckD.addQueueFront(dData[i]);
     }
    deckD.print();

    cout<< endl <<"Part D: Delete Sonny (pop front) and 99.99 (pop back) from the above deques" << endl 
        << " (you will need to delete others) and print the" <<endl
        << "remaining elements in the deques. Do not use the STL." << endl;
    string s;
    do{
       deckS.deQueueFront(s);
       cout << "Item dequeued : " << s << endl;
    }
    while(s.compare("Sonny") != 0);

    deckS.print();

    double y;
    do{
       deckD.deQueueRear(y);
       cout << "Item dequeued : " << y << endl;
    }
    while(y != 99.99);

    deckD.print();

    cout << "END OF ASSIGNMENT 3 " << endl << endl; 
    
    getline(cin, s);


    return 0;
}