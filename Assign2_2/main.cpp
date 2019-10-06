//Assignment 2 Stacks 
//Author: Robert Gaines
//Purpose: to demonstrate ability to implement stack data structures using stl and 
//         singly linked lists


#include <iostream> 
#include <iomanip>
#include <string>
#include <stack>
#include <cstdlib>
#include "listStack2.h"
#include "listStack.h"
using namespace std;




template <class type>
void printStack(stack <type> stack) 
{ 
    while (!stack.empty()) 
    { 
        cout << '\t' << stack.top() << endl; 
        stack.pop(); 
    } 
    cout << endl << endl; 
}

template <class type> 
void deleteItem(stack <type> & stack, type element)
{
    while (!stack.empty() && stack.top ) 
    { 
        cout << '\t' << stack.top(); 
        stack.pop(); 
    } 
    cout << '\n'; 
}

bool balanced(string & exp){
   listStack<char> parentheses;
   char * cstr = new char [exp.length()+1];
   std::strcpy (cstr, exp.c_str());

  //to print line by line
  // for(int i = 0; i < exp.length() + 1; i++ ){
  //     cout << cstr[i] << endl;
  // }
    int negativeCount = 0;
    for(int i = 0; i < exp.length() + 1; i++ ){
        
        if(cstr[i] == '{' || cstr[i] == '[' || cstr[i] == '('){
            if(negativeCount < 1)
            parentheses.push(cstr[i]);
            else 
            negativeCount--;
            
        }
        else if(cstr[i] == '}' || cstr[i] == ']' || cstr[i] == ')')
        {
            if(!(parentheses.isEmpty()))
            parentheses.pop();
            else negativeCount++;
        }
    }

    if(parentheses.isEmpty() && negativeCount < 1)return true;
    else return false;

}


//HW STARTS NOW
using namespace std;
int main(){

//part A
    cout << "Part A" << endl;
    stack <string> sStack;
    sStack.push("Mark");
    sStack.push("Alan");
    sStack.push("Jennifer");
    sStack.push("Sonny");
    sStack.push("Eric");
    sStack.push("JoAnn");
    sStack.push("Bill");

    cout << "Stack 1: " << endl;
    printStack<string>(sStack);
 
    stack <double> dStack;
    dStack.push(983.3);
    dStack.push(44.44);
    dStack.push(888.55);
    dStack.push(99.99);
    dStack.push(123.123);
    dStack.push(8.445);

    cout << "Stack 2: " << endl;
    printStack<double>(dStack);


    cout << "Part B: " << endl;


    sStack.pop();
    sStack.pop();
    sStack.pop();
    sStack.pop();
    cout<< "Stack 1 after deletion of Sonny" << endl;
    printStack(sStack);

    dStack.pop();
    dStack.pop();
    dStack.pop();

    cout << "Stack 2 after deletion of 99.99" << endl;
    printStack(dStack);

    cout << "Part C: " << endl;

    listStack<string> stack1;
    cout << "Stack 1 as linked list: " << endl;

    
    stack1.push("Mark");
    stack1.push("Alan");
    stack1.push("Jennifer");
    stack1.push("Sonny");
    stack1.push("Eric");
    stack1.push("JoAnn");
    stack1.push("bill");

    stack1.display();
    cout << endl;

    cout << "Stack 2 as linked list: " << endl;

    listStack<double> stack2;
    stack2.push(983.3);
    stack2.push(44.44);
    stack2.push(888.55);
    stack2.push(99.99);
    stack2.push(123.123);
    stack2.push(8.445);

    stack2.display();
    cout << endl;

    cout << endl <<  "Part D: " << endl;

    cout << "Stack 1 as list after deletion of Sonny" << endl;

    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();

    stack1.display();

    cout << endl;

    cout << "Stack 2 as list after deletion of 99.99" << endl;

    stack2.pop();
    stack2.pop();
    stack2.pop();


    stack2.display();


    cout << endl;

    cout << "Part F: " << endl;

    string exp[] = {"{2x - 8) (12x + 6)", 
                            "{{8x+5) - 5x[9x+3]})",
                            "{2x + 5} (6x+4)",
                            "(((4x+8) - x[4x+3])))" , 
                            "[(5x - 5) - 4x[6x + 2]]",
                            "{(8x+5) - 6x[9x+3]]",
                            "(12x + 6) (2x - 4)"
                            };

    for(int i = 0; i < 7; i++){
        int x = balanced(exp[i]);
        if(x){
        cout << exp[i] << "is Balanced." << endl;
        }
        else {
            cout << exp[i] << "is not Balanced." << endl;
        }
    }

    

    return 0;
}