#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main () {

string line;

ifstream in("/C:\Users/Diana/Desctop/colors.jpg");

if (in.is_open()){
    while (getline(in, line)){
        cout << line << endl;
    }
}
in.close();

return 0;

 }
