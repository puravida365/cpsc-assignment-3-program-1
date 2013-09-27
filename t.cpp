/*
Assignment #3
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class TOKE{
	private:
		fstream f;
		string token;
		string temp_token, temp_string;
		vector <string> input;
		vector <string> input_st;
		vector<string>::iterator it;
		int size, comma, period, semicolon;
		
		bool isIdentifier;
		bool isInteger;
		bool isRealNumber;
		bool isReservedWord;
		
	public:
		void readData(){
			f.open("data.txt", ios::in);
			if(!f){
			cout << "File not found"; exit(1);
			}
			while( !f.eof() ){
				f >> token;
				input.push_back(token);
			}
		}
		void analyzeData(){
			for (it = input.begin(); it != input.end(); ++it){
				
				//cout << *it << endl;
				temp_token = *it;
				size = temp_token.length();
				
				
				if( (temp_token == "int")||(temp_token == "float")||(temp_token == "char")||(temp_token == "string") ){
					cout << temp_token << "\t RESERVED WORD" << endl;
				}
				else if( (temp_token == ".")||(temp_token == ",")||(temp_token ==";")||(temp_token == "=") ){
					cout << temp_token << "\t SPECIAL CHARACTER" << endl;
				}
				else{
					// Integer: string of digits w/o decimal point
					if(isdigit(temp_token[0])){
						// integer
						// decimal
						// real number
					}
					// Identifier: begins with letter followed by more letters or digits
					else if(isalpha(temp_token[0])){
						
					}
					
						// otherwise
					
				}
			
			}
		}
		void stripTokens(){
			for (it = input.begin(); it != input.end(); ++it){
				temp_token = *it;
				
				comma = temp_token.find(',');
				period = temp_token.find('.');
				semicolon = temp_token.find(';');
				
				if(comma != -1){
					temp_string = temp_token.substr(comma,1);
					temp_token.erase(comma);
					input_st.push_back(temp_token);
					input_st.push_back(temp_string);
				}
				
				else if(period != -1){
					temp_string = temp_token.substr(period,1);
					temp_token.erase(period);
					input_st.push_back(temp_token);
					input_st.push_back(temp_string);
				}
				
				else if(semicolon != -1){
					temp_string = temp_token.substr(semicolon,1);
					temp_token.erase(semicolon);
					input_st.push_back(temp_token);
					input_st.push_back(temp_string);
				}
				else{
					input_st.push_back(temp_token);
				}
			}
		
		}
		void print(){
			for (it = input_st.begin(); it != input_st.end(); ++it){
				temp_token = *it;
				cout << temp_token << endl;
			}
		
		}
		
};

int main(){

TOKE A;
A.readData();
A.stripTokens();
//A.analyzeData();
A.print();

return(0);
}

/* SAMPLE IO

Users-MacBook-Pro:3 josue$ ./a.out
int
Bob
,
2You
,
john
,
Adam
.
float
taxYear
=
2013
,
taxRate
=
29
.

*/