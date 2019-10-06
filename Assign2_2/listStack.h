#ifndef LIST_STACK
#define LIST_STACK

#include <string>
#include <iostream>
using namespace std;

template<class type>
struct Node { 
    type data; 
    struct Node* link; 
}; 
//struct Node* top; 

template<class type>
class listStack{
    public:

    Node<type>* top;
    listStack();
    void push(type data);
    int isEmpty();
    type peek();
    void pop();
    void display();
    
};

template<class type>
listStack<type>::listStack(){
    top = nullptr;
}
  
// Utility function to add an element data in the stack 
 // insert at the beginning 
template<class type>
void listStack<type>::push(type data) 
{ 
    // create new node temp and allocate memory 
    Node<type>* temp; 
    temp = new Node<type>(); 
  
    // check if stack (heap) is full. Then inserting an element would 
    // lead to stack overflow 
    if (!temp) { 
        cout << "\nHeap Overflow"; 
        exit(1); 
    } 
  
    // initialize data into temp data field 
    temp->data = data; 
  
    // put top pointer reference into temp link 
    temp->link = top; 
  
    // make temp as top of Stack 
    top = temp; 
} 
  
// Utility function to check if the stack is empty or not 
template<class type>
int listStack<type>::isEmpty() 
{ 
    return top == NULL; 
} 
  
// Utility function to return top element in a stack 
template<class type>
type listStack<type>::peek() 
{ 
    // check for empty stack 
    if (!isEmpty()) 
        return top->data; 
    else
        exit(1); 
} 
  
// Utility function to pop top  
// element from the stack 
template<class type>
void listStack<type>::pop() 
{ 
    Node<type>* temp; 
  
    // check for stack underflow 
    if (top == NULL) { 
        cout << "\nStack Underflow" << endl; 
        exit(1); 
    } 
    else { 
        // top assign into temp 
        temp = top; 
  
        // assign second node to top 
        top = top->link; 
  
        // destroy connection between first and second 
        temp->link = NULL; 
  
        // release memory of top node 
        free(temp); 
    } 
} 
  
// Function to print all the  
// elements of the stack 
template<class type> 
void listStack<type>::display()  
{ 
    Node<type>* temp; 
  
    // check for stack underflow 
    if (top == NULL) { 
        cout << "\nStack Underflow"; 
        exit(1); 
    } 
    else { 
        temp = top; 
        while (temp != NULL) { 
  
            // print node data 
            cout <<  temp->data << " "; 
  
            // assign temp link to temp 
            temp = temp->link; 
            cout << endl;
        } 
    } 
}

#endif