/* This is the same as TrianglePattern#4.cpp but for characters.*/


#include <iostream>
using namespace std;
int main (){
    int n = 6;
    for (int i=0 ; i < n ; i++){
        for (int j=1 ; j <= i+1 ; j++){
            cout << char (j+64);
        }
        cout << endl;
    }
}