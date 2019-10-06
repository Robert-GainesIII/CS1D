#ifndef H_linkedQueue
#define H_linkedQueue

#include <iostream>

using namespace std;

//Definition of the node
template <class Type>
struct nodeType
{
	Type info;
    nodeType<Type> *prev;
	nodeType<Type> *next;
};

template<class Type>
class linkedQueueType
{
public:
    const linkedQueueType<Type>& operator=
								(const linkedQueueType<Type>&);
              // overload the assignment operator
    bool isEmptyQueue();
    bool isFullQueue();
    void destroyQueue();
    void initializeQueue();
    void addQueueFront(const Type& newElement);
    void addQueueRear(const Type& newElement);
    void deQueueFront(Type& deqElement);
    void deQueueRear(Type & deqElement);
    linkedQueueType (); //default constructor
    linkedQueueType(const linkedQueueType<Type>& otherQueue);
		//copy constructor
    ~linkedQueueType(); //destructor
    void print();

private:
    nodeType<Type> *front; //pointer to the front of the queue
    nodeType<Type> *rear;  //pointer to the rear of the queue
};


template<class Type>
linkedQueueType<Type>::linkedQueueType() //default constructor
{
	front = nullptr; // set front to nullptr
	rear = nullptr;  // set rear to nullptr

/* 
    front->next = nullptr;
    rear->prev = nullptr;

    front->prev = nullptr;
    rear->next = nullptr;
*/
}


template<class Type>
bool linkedQueueType<Type>::isEmptyQueue()
{
	return(front == nullptr);
}

template<class Type>
bool linkedQueueType<Type>::isFullQueue()
{
	return false;
}

template<class Type>
void linkedQueueType<Type>::destroyQueue()
{
	nodeType<Type> *temp;

	while(front != nullptr)  //while there are elements left in the queue
	{
	   temp = front;         // set temp to point to the current node
	   front = front ->link; // advance front to the next node
	   delete temp;          // deallocate memory occupied by temp
	}

	rear = nullptr;  // set rear to nullptr
}

template<class Type>
void linkedQueueType<Type>::initializeQueue()
{
  destroyQueue();
}


template<class Type>
void linkedQueueType<Type>::addQueueFront(const Type& newElement)
{
	nodeType<Type> *newNode;

	newNode = new nodeType<Type>;	//create the node
	newNode->info = newElement;		//store the info		//initialize the link field to nullptr

    if(front == nullptr)				//if initially queue is empty
    {
		front = newNode;
		rear = newNode;
		front->prev = nullptr;
		rear->next = nullptr;
    }
    else	
    {
        newNode->next= front;	
        newNode->prev = nullptr;
        front = newNode;
		rear->next = nullptr;
    }
    cout << "added " << front ->info << " to the deque." << endl;
}//end addQueue

template<class Type>
void linkedQueueType<Type>::addQueueRear(const Type& newElement)
{
	nodeType<Type> *newNode;

	newNode = new nodeType<Type>;	//create the node
	newNode->info = newElement;		//store the info
    newNode->next= nullptr;			//initialize the link field to nullptr

    if(front == nullptr)				//if initially queue is empty
    {
		front = newNode;
		rear = newNode;
		front->prev = nullptr;
		rear->next = nullptr;
    }
    else				//add newNode at the end
    {
        newNode->prev = rear;
		rear->next = newNode;
        rear = rear->next;
    }
}//end addQueue



template<class Type>
void linkedQueueType<Type>::deQueueFront(Type& deqElement)
{
	nodeType<Type> *temp;

	deqElement = front->info;  //copy the info of the first element
	temp = front;              //make temp point to the first node
	front = front->next;       //advance front to the next node
	delete temp;               //delete the first node

	if(front == nullptr)          //if after deletion the queue is empty
		rear = nullptr;		   //set rear to nullptr
}//end deQueue


template<class Type>
void linkedQueueType<Type>::deQueueRear(Type& deqElement)
{
	nodeType<Type> *temp;

	deqElement = rear->info;  //copy the info of the first element
	temp = rear;              //make temp point to the first node
	rear = rear->prev;       //advance front to the next node
	delete temp;  
    
    rear->next = nullptr;             //delete the first node
	   //set rear to nullptr
}//end deQueue



template<class Type>
linkedQueueType<Type>::~linkedQueueType() //destructor
{
	nodeType<Type> *temp;

	while(front != nullptr)	  //while there are elements left in the queue
	{
	   temp = front;         //set temp to point to the current node
	   front = front ->next; //advance first to the next node
	   delete temp;          //deallocate memory occupied by temp
	}

	rear = nullptr;  // set rear to nullptr
}

template<class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
								(const linkedQueueType<Type>& otherQueue)
{
	//Write the definition of to overload the assignment operator

}

	//copy constructor
template<class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue)
{
    //Write the definition of the copy constructor
}//end copy constructor

template<class Type>
void linkedQueueType<Type>::print(){
    nodeType<Type> *node = front;
    do{
        cout << node->info << " ";
        node = node->next;
    }while(node !=nullptr);
    cout << endl;
}

#endif
//queue3.cpp
//Test Program l
