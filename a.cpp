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
		string temp_token;
		vector <string> input;
		vector<string>::iterator it;
		int size;
		
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
		void identifierTest(){
			temp_token = input.front();
			if(isalpha(temp_token[0])){
				for(int i=1; i < temp_token.length(); ++i){
					if(isalnum(temp_token[i])){
						isIdentifier = true;
					}
					else{
						isIdentifier = false;
					}
				}
			}
		}
		void reservedWordTest(){
			
		}
		void integerTest(){}
		void realNumberTest(){}
		void decimalNumberTest(){}
		void printDataSummary(){
			if(isIdentifier == false){
				cout << temp_token << " is not an identifier\n" << endl;
				cout << "Vector size is " << size;
			}
		}
};

int main(){

TOKE A;
A.readData();
A.analyzeData();
//A.identifierTest();
//A.printDataSummary();

return(0);
}