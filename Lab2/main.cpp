#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iomanip>
using namespace std;

void toUpper(string &str){
	for(int i = 0; i < str.length(); i++){
		if(str.at(i) >= 97 && str.at(i) <= 129){
			str.at(i) = str.at(i)-32;
			
		}
		
	}
}

void removeSpaces(char *str) 
{ 
    // To keep track of non-space character count 
    int count = 0; 
  
    // Traverse the given string. If current character 
    // is not space, then place it at index 'count++' 
    for (int i = 0; str[i]; i++) 
        if (str[i] != ' ') 
            str[count++] = str[i]; // here count is 
                                   // incremented 
    str[count] = '\0'; 
} 

bool isPalRec(string word, int firstC, int lastC) 
{ 
    // If there is only one character 
    if (firstC == lastC) 
    return true; 
  
    // If first and last 
    // characters do not match 
    if (word.at(firstC) != word.at(lastC))
    return false; 
  
    // If there are more than  
    // two characters, check if  
    // middle substring is also  
    // palindrome or not. 
    if (firstC < lastC + 1) 
    return isPalRec(word, firstC + 1, lastC - 1); 
  
    return true; 
} 

bool isPalindrome(string & word) 
{ 

    string copy = word;
    //reverses the copy of the word 
    reverse(copy.begin(), copy.end());
    copy.c_str();
    int len = copy.length();
    //cout << "Length of string being checked is " << len << endl;
    if(len == 0 || len == 1)return true ;//if word is empty or just one letter it is a palindrome
    if(strcmp(word.c_str(),copy.c_str()) == 0)return true;//checks if word and reversed word are equal
    return false; //default return false
}

bool isPalidromeRec(string & word){

    int length = word.size();
    if(length == 0 || length == 1)return true;//is palindrome if only one or none characters 

    bool result = isPalRec(word, 0, length-1);
    return result;
}

int main(){
    cout << "Lab2 Recursive functions" << endl;
    cout << "8/21/19 CS1D T TH 5-7" << endl;
    cout << "Robert Gaines" << endl;
    cout << "Arthur Siu" << endl;
    cout << "------------------------" << endl;
    cout << "Description of Lab: To demonstrate the ability to use and understand recursion to solve complex logic problems." << endl << endl;
    int size = 10;

    string data[] = {"A man a plan a canal Panama", "The rain in Spain", "No lemon, no melon",
                     "radar", "CS1D", "Was it a cat I saw?", "Racecar",  "Saddleback", "dad", 
                     "Work with a partner"}; //dataset


    cout << "Size of data is: " << size << endl << endl;
    cout << "Removing Whitespaces from dataset.." << endl;
    
    //REMOVES WHITESPACES FROM WORDS
    for(int i =0; i < size; i++){
        cout << i << ") ";
        data[i].erase(std::remove_if(data[i].begin(), data[i].end(), ::isspace), data[i].end());
        cout << data[i] << endl;
        toUpper(data[i]);
    }

    cout << "Running Palidrome check.. " << endl << endl;

    
    for(int i =0; i < size; i++){
        cout << i << ") ";
        cout << " Is " << data[i] << " a palidrome? " << std::boolalpha << isPalidromeRec(data[i]);
        cout << endl;
    }

    cout << "END OF LAB GOOD JOB! " << endl << endl;
    return 0;
}