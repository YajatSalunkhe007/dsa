/* This is the code for the Reverse Triangle Pattern for Characters.*/


#include <iostream>
using namespace std;
int main (){
    int n = 5;
    for (int i = 0 ; i < n ; i++){
        for (int j=i+1 ; j>0 ; j--){
            cout << char(j+64) << " ";
        }
        cout << endl;
    }
    return 0;
}