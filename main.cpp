



//                                            ********* Writer: Matt Hamilton            *********
 //                                             ******** Class: CS 136                   ******** 
 //                                              ******* Professor: Brian Dauzat         *******
 //                                                ***** Recursive Palindrome Recognizer *****
 //                                                 **** =============================== ****
 //                                                   ** *** *** *** *** *** *** *** *** **



//A palindrome is a string that reads the same both forward and backward. 
//For example, the string “Madam, I’m Adam” is a palindrome. Write a program that uses 
//a recursive function to check whether a string is a palindrome.
// Your program must contain a value-returning recursive function that returns true if
// a string is a palindrome and false otherwise. Do not use any global variables;
// use appropriate parameters.



#include <iostream>
#include <string>
#include <cctype>


using namespace std;

string filter(string word);//FILTERS STRINGS FROM SPACES AND OTHER NON-ALPHABETICAL VALUES
bool isPalindrome(string word,int startPoint, int endPoint);


int main() {

	string user_input;
	int startIdx {0};

   cout << "Please enter your string: " ;
  getline(cin,user_input);
  
//  cout << filter(user_input) << endl;
   
   if(isPalindrome(filter(user_input), startIdx, filter(user_input).length() - 1))
	   cout << "\n\t " << user_input << " is a palindrome" << endl;
   else
	    cout << "\n\t " << user_input << " is not a palindrome" << endl;
  

system("pause");

return 0;
}


string filter(string word){
	
	string filtered;
	
	for(unsigned int idx{0}; idx < word.length(); idx++){
		
		if(isalpha(word[idx])){
			filtered+=tolower(word[idx]);
		}
	}
	
	return filtered;
	
}


bool isPalindrome(string word,int startPoint, int endPoint){
	
// in case if the length of the stirng is 0 OR 1
	if( startPoint == endPoint || endPoint - startPoint == 1 ){
		return true;
	}
        
	else{
			//THE PROGRAM RUNS TILL IT COMPARES ALL THE CHARACTERS IN STRING //IF ALL OF THEM ARE THE SAME, IT RETURNS TRUE
		if (word[startPoint] == word[endPoint]){
                        
			return isPalindrome(word,startPoint+1,endPoint-1);
                }
                
		else{
		   return false;
		}
	}
 
}