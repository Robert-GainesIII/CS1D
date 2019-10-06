#ifndef QUEUE_H
#define QUEUE_H

template<class T>
class queue{

    public:
        queue();
        int size();
        bool empty();
        void enqueue(T input);
        void dequeue();
        *T front();
        *T rear();
    private:
        T* front;
        T* rear;

};



#endif