/* This is the Inverted Triangle Pattern for Characters.*/


#include <iostream>
using namespace std;
int main (){
    int n=4;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<i ; j++){ // i times spaces
            cout << " ";
        }
        for (int j=0 ; j < n-i ; j++){ // n-i times numbers
            cout << char(i+65);
        }
        cout << endl;
    }
}