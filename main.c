#include <stdio.h>
#include <string.h>
#include <conio.h> // For Windows getch() alternative
//getch(): This probably will not work in many modern compilers (especially in Unix/Linux systems or modern GCC/Clang-based setups).
int main() {
    char ch;
    char pass[20];
    char saved_pass[20];
    int i = 0;  // To track password input

    start:
    printf("Enter Your Password: ");
    i = 0;  // Reset the index for each password attempt

    // Reading password character by character and displaying '*' instead of actual characters
    while (1) {
        ch = _getch();  // Use _getch() to get single character without echoing it

        if (ch == 13) { // Enter key (ASCII 13)
            pass[i] = '\0'; // Null-terminate the string
            break;
        } else if (ch == 8) { // Backspace key (ASCII 8)
            if (i > 0) {
                i--; // Move the index back
                printf("\b \b"); // Move back, print space, then move back again to remove '*'
            }
        } else {
            if (i < 19) {  // Ensure password array does not overflow
                pass[i++] = ch;
                printf("*"); // Print asterisk for each entered character
            }
        }
    }


    // Open the password file
    FILE *ptr;
    ptr = fopen("password.txt", "r");
    if (ptr == NULL) {
        printf("Error: Could not open password file.\n");
        return 1;  // Exit if the file could not be opened
    }

    // Read saved password from file
    fscanf(ptr, "%s", saved_pass);
    fclose(ptr);

    // Compare the entered password with the saved one
    if (strcmp(pass, saved_pass) == 0) {
        printf("LOGIN SUCCESSFUL.\n\n");
    } else {
        printf("LOGIN FAILED. INCORRECT PASSWORD.\n\n");
    }

    goto start;  // You may want to remove or replace this with a proper loop
    return 0;
}
