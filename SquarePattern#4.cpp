/* This is another form of Square Pattern where the number of rows and columns is the same but the data or elements in
the pattern is not repeated. This Square Pattern is in the form of a Matrix.*/


#include <iostream>
using namespace std;
int main () {
    int n = 6;
    int num = 1;        /* We took another variable num because we dont the elements to repeat themselves, because if we
                            used j as its limit is the value less than n, after that it will repeat itself from zero. This
                            is also a reason why we declared the variable num outside the outer for loop.*/
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            cout << num <<" ";
            num++;
        }
        cout << endl;
    }
}