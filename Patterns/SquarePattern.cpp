#include <iostream>
using namespace std;
int main (){
    int n = 10;
    for (int i=1; i<=n; i++){       /* The Outer Loop will tell how many columns the Output have.*/
        for ( int j=1; j<=n; j++){  /* The Inner Loop will tell how many rows the Output have.*/
            cout << j;
        }
        cout << endl;
    }
}