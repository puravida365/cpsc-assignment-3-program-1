#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <stack>

using namespace std;

class EVALPOST{
	private:
		int x,y,n,result,size;
		stack <char> A;
		stack <char> B;
		string expression;
		int c;
		char item;
	
	public:
		// get user input
		void getExpression(){
			cout << "Enter a postfix expression: ";
			getline(cin, expression);
			c = expression.length();
			for(int i=0; i<c; ++i){
				A.push(expression[i]);
			}
			
		}
		// takes user input and evaluates each expression that was pushed into stack previously
		void evalTokens(){
			while (!A.empty()){
				item = A.top();
				A.pop();
				
				if(item == '+'){
					cout << "plus";
					//x = A.pop();
   					//y = A.pop();
   					//B.push(y+x);
				}
				else if(item == '-'){
					cout << "minus";
					//x = A.pop();
					//y = A.pop();
					//B.push(y-x);
				}
				else if(item == '*'){
					cout << "multiply";
					//x = A.pop();
					//y = A.pop();
					//A.push(y*x);
				}
				else if(item == '/'){
					cout << "divide";
					//x = A.pop();
					//y = A.pop();
					//A.push(y/x);
				}
				else if(item == ' '){
					cout << "space" << endl;
				}
				else{
					//n = atoi(item);
   					//A.push(n);
				}
			}
			
			// output result
			result = A.pop();    
			cout << "Result is " << result << endl;
		}
		
		/*
		void tokeExpression(){
			for (it = A.begin(); it != A.end(); ++it){
				temp_token = *it;
				if(strcmp(temp_token, " ") == 0){
					cout << "hello" << endl; 
				}
			}
		}*/
		
		void printExpression(){
			while (!A.empty()){
				cout << A.top();
				A.pop();
			}
		}
};

int main()
{
	EVALPOST A;
	A.getExpression();
	A.evalTokens();
	//A.tokeExpression();
	//A.printExpression();

    return(0);
}