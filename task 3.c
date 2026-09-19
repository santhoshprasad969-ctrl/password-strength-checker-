/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length;
    int uppercase = 0;
    int lowercase = 0;
    int digit = 0;
    int special = 0;
    int score = 0;

    printf("====================================\n");
    printf("      PASSWORD STRENGTH CHECKER\n");
    printf("====================================\n");

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    // Remove newline character
    password[strcspn(password, "\n")] = '\0';

    length = strlen(password);

    // Check each character
    for (int i = 0; i < length; i++) {

        if (isupper(password[i])) {
            uppercase = 1;
        }
        else if (islower(password[i])) {
            lowercase = 1;
        }
        else if (isdigit(password[i])) {
            digit = 1;
        }
        else {
            special = 1;
        }
    }

    // Display criteria
    printf("\nPassword Analysis:\n");
    printf("------------------\n");

    printf("Length: %d characters\n", length);

    if (length >= 8) {
        printf("[✓] At least 8 characters\n");
        score++;
    } else {
        printf("[X] At least 8 characters\n");
    }

    if (uppercase) {
        printf("[✓] Contains uppercase letter\n");
        score++;
    } else {
        printf("[X] Contains uppercase letter\n");
    }

    if (lowercase) {
        printf("[✓] Contains lowercase letter\n");
        score++;
    } else {
        printf("[X] Contains lowercase letter\n");
    }

    if (digit) {
        printf("[✓] Contains number\n");
        score++;
    } else {
        printf("[X] Contains number\n");
    }

    if (special) {
        printf("[✓] Contains special character\n");
        score++;
    } else {
        printf("[X] Contains special character\n");
    }

    // Determine password strength
    printf("\nPassword Strength: ");

    if (score <= 2) {
        printf("WEAK\n");
    }
    else if (score == 3 || score == 4) {
        printf("MEDIUM\n");
    }
    else {
        printf("STRONG\n");
    }

    printf("\nScore: %d/5\n", score);

    printf("====================================\n");

    return 0;
}