#include <iostream>
using namespace std;
int main (){
    int n = 4;
    for ( int i = 0 ; i < n ; i++){
        for (int j=0 ; j < i+1 ; j++){
            cout << "*";
        }
        cout << endl;
    }
}

/*As the variable i in the outer signifies the number of rows, we just have to print a star extra than the number of line.
so we keep the limit of the inner loop as i+1.*/