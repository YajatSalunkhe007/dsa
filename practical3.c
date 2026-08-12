#include <stdio.h>
#include <ctype.h>
int main() {
    char name[50];
    int i;

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    for (i = 0; name[i] != '\0'; i++) {
        if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' ||
            name[i] == 'o' || name[i] == 'u' ||
            name[i] == 'A' || name[i] == 'E' || name[i] == 'I' ||
            name[i] == 'O' || name[i] == 'U') {

            printf("%c is a Vowel\n", name[i]);
        }
        else if (isalpha(name[i])) {
        printf("%c is a Consonant\n", name[i]);
        }
    }
    
    return 0;
}
