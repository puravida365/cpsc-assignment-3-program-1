#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

fstream f;
string token;

vector <string> input;

f.open("data.txt", ios::in);
	if(!f){
	cout << "File not found"; exit(1);
	}
	
while( !f.eof() ){
	f >> token;
	input.push_back(token);
}



for (vector<string>::iterator it = input.begin(); it != input.end(); ++it){
	token = *it;

	}

return(0);
}