#ifndef LIST_STACK2
#define LIST_STACK2

#include <string>
#include <iostream>
using namespace std;

struct Node2 { 
    double data; 
    struct Node2* link; 
}; 
//struct Node* top; 

class listStack2{
    public:

    struct Node2* top;
    listStack2();
    void push(double);
    int isEmpty();
    double peek();
    void pop();
    void display();
    
};

listStack2::listStack2(){
    top = nullptr;
}
  
// Utility function to add an element data in the stack 
 // insert at the beginning 
void listStack2::push(double data) 
{ 
    // create new node temp and allocate memory 
    struct Node2* temp; 
    temp = new Node2(); 
  
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
int listStack2::isEmpty() 
{ 
    return top == NULL; 
} 
  
// Utility function to return top element in a stack 
double listStack2::peek() 
{ 
    // check for empty stack 
    if (!isEmpty()) 
        return top->data; 
    else
        exit(1); 
} 
  
// Utility function to pop top  
// element from the stack 
  
void listStack2::pop() 
{ 
    struct Node2* temp; 
  
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
void listStack2::display()  
{ 
    struct Node2* temp; 
  
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