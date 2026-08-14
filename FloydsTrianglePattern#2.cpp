/* This is the code for Floyd's Triangle for Characters. */


#include <iostream>
using namespace std;
int main (){
    int n=4;
    int num = 1;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<i+1 ; j++){
            cout << char (num+64) << " ";
            num++;
        }
        cout << endl;
    }
    return 0;
}