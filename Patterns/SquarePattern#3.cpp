/*This is another way of representing Square Patterns for characters.*/


#include <iostream>
using namespace std;
int main (){
    int n = 6;

    for (int i = 1; i<n; i++){
        char ch = 'A';
        for (int j = 0; j<n; j++){
            cout << ch;
            ch = ch + 1;
        }
        cout << endl;   
    }

}