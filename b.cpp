#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class TOKE{
	private:
		fstream f;
		string token;
		string temp_token;
		vector <string> input;
		vector<string>::iterator it;
		// test result variables
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
		void printData(){
			for (it = input.begin(); it != input.end(); ++it){
				cout << *it;
			}
		}
		/*
		void analyzeData(){
			temp_token = input.back();
			if( (temp_token == "int")||(temp_token == "float")||(temp_token == "char")||(temp_token == "string") ){
				cout << temp_token << " is a reserved word.\n" << endl;
			}
			else if( (temp_token == ".")||(temp_token == ",")||(temp_token ==";")||(temp_token == "=") ){
				cout << temp_token << " is a special character.\n" << endl;
			}
			else{
				cout << "none of the above.\n";
			}
			
		}
		*/
		void identifierTest(){
			temp_token = input.back();
			if(isalpha(temp_token[0])){
				for(int i=1; i < temp_token.length(); ++i){
					if(isalnum(temp_token[i]))continue;
					else{
						isIdentifier = false;
					}
				}
			}
		}
		void integerTest(){}
		void realNumberTest(){}
		void decimalNumberTest(){}
		void printDataSummary(){}
};

int main(){

TOKE A;
A.readData();
A.analyzeData();

return(0);
}