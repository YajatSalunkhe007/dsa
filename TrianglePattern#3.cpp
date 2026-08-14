/* This code is the same as TrianglePattern#2.cpp but for characters.*/


#include <iostream>
using namespace std;
int main (){
    int n = 6;
    for (int i=0 ; i < n ; i++){
        for (int j=0 ; j < i+1 ; j++){
            cout << char (i+65);
        }
        cout << endl;
    }
}