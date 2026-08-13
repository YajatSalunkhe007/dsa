/* This is the Second Form of Square Pattern for characters.*/


#include <iostream>
using namespace std;
int main (){
    char ch = 'E';
    char start='A';
    for (char xyz = 'A' ; xyz <= ch ; xyz++){
        for (char abc = 'A'; abc <= ch ; abc++){
            cout << start;
            start++;
        }
        cout << endl;
    }
}