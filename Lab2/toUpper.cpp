#include "serendipity.h" 

void toUpper(string &str){
	for(int i = 0; i < str.length(); i++){
		if(str.at(i) >= 97 && str.at(i) <= 129){
			str.at(i) = str.at(i)-32;
			
		}
		
	}
}