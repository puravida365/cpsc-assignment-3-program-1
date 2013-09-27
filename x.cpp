#include <iostream>
#include <fstream>
using namespace std;

int main(){

ifstream in;     //delcraing instream

string oneline;

in.open("data.txt");  //open instream

while(getline(in, oneline))
{
    size_t begin(0); 
    size_t end;
    do
    {
        end = oneline.find_first_of(" ,", begin);

        //outputs file into copy file
        out << oneline.substr(begin, 
                    (end == string::npos ? oneline.size() : end) - begin) << ' ';

        begin = end+1;
        //pointer moves to second token after first scan is over 
    }
    while (end != string::npos);
}

in.close();      //closes in file

}