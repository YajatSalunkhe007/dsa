/* This Code Prints Square Pattern for Characters */

#include <iostream>
using namespace std;
int main (){
    char ch = 'E';
    for (char cha='A'; cha<=ch; cha++){       /* The Outer Loop will tell how many columns the Output have.*/
        for ( char chara ='A'; chara<=ch; chara++){  /* The Inner Loop will tell how many rows the Output have.*/
            cout << chara;
        }
        cout << endl;
    }
}