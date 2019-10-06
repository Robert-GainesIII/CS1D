#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int reverseDigits(int num)
{
    int hundreds, tens, ones; // CALC - stores number in respective place

    hundreds = num/100;
    num -= hundreds*100;
    tens = num/10;
    num -= tens*10;
    ones = num;
    
    return ones*100 + tens*10 + hundreds;
}

int sumDigits(int num)
{
    int hundreds, tens, ones; //CALC - stores number in respective place

    hundreds = num/100;
    num -= hundreds*100;
    tens = num/10;
    num -= tens*10;
    ones = num;

    return ones + tens + hundreds;
}

int main(){

    srand (time(NULL));

    vector<int> randomNumbers; 
    int num = 0;
    cout << "---Lab 1---" << endl;
    cout << "CS1D 08/19/19" << endl;
    cout << "Demonstrate basic understanding of the standard library and sorting algorithms." << endl;
    cout << "Names: Robert Gaines and Faris Hijazi." <<endl <<endl;

    for(int i =0; i < 15; i++){
        num = rand() % 900 + 100;
        randomNumbers.push_back(num);
       // cout << std::setw(3) << std::setfill('0') << "index " << i << ": " << randomNumbers[i] << endl;
    }

    cout << "Sorting Vector.." << endl;

    std::sort(randomNumbers.begin(), randomNumbers.end());

    for(int i = 0; i< 15; i++){
        //cout << "index " << i << ": " << randomNumbers[i] << endl;
    }

    cout << "Creating reversed Vector.." << endl;

    vector<int> revNums;

    for(int i = 0; i < 15; i++){
        revNums.push_back(reverseDigits(randomNumbers[i]));
    }

    cout << "Creating sum Vector.." << endl;

    vector<int> sumvect;

    for(int i = 0; i<15; i++){
        sumvect.push_back(sumDigits(randomNumbers[i]));
    }

    cout << "Printing Vectors.." << endl << endl;

    cout << "Random Number Vector.." << endl;

    for(int i = 0; i< 15; i++){
       cout << "index " << i << ": ";
       cout << std::setw(3) << std::setfill('0') << randomNumbers[i] << endl;
    }
    cout << endl << endl;


    cout << "Reversed Number Vector.." << endl;
    for(int i = 0; i< 15; i++){
        cout << "Reversed Number of " << randomNumbers[i] << ": ";
        cout << std::setw(3) << std::setfill('0') << revNums[i] << endl;
    }
    cout << endl << endl;


    cout << "Sum of Number Vector.." << endl;
    for(int i = 0; i< 15; i++){
        cout << "Sum of " << randomNumbers[i] << ": ";
        cout << std::setw(3) << std::setfill('0') << sumvect[i] << endl;
    }

    cout << "--End of Lab 1--" << endl;
    
    return 0;
}