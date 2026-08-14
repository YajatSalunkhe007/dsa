/* This is another form of Triangle Pattern where you print the numbers from its chro-
nological order again.*/

#include <iostream>
using namespace std;
int main (){
    int n = 6;
    for (int i=0 ; i < n ; i++){
        for (int j=1 ; j <= i+1 ; j++){
            cout << j;
        }
        cout << endl;
    }
}