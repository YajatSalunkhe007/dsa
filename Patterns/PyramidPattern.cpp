#include <iostream>
using namespace std;
int main (){
    int n=5;
    for (int i=0; i < n; i++){

        //Spaces

        for (int j=0; j < n-i-1; j++){
            cout << " ";
        } 
        
        //Num1

        for (int j=1; j < i; j++){
            cout << j;
        }

        //Num2
        
        for (int j=i; j >=1; j--){
            cout << j;
        }
        cout << endl;
    }
}