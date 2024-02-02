#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random character
char getRandomChar() {
    // omit ambiguous characters and ones difficult to type
    const char charset[] = "abcdefghijkmnpqrstuvwxyzABDEFGHJKLMNPQRSTUVWXYZ23456789!@#$%&*)-=_+";
    const size_t charsetSize = sizeof(charset) - 1;
    return charset[rand() % charsetSize];
}

// Function to generate a random password of a given length
void generatePassword(int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", getRandomChar());
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <password length>\n", argv[0]);
        return 1;
    }

    // Convert command-line argument to integer
    int passwordLength = atoi(argv[1]);

    // Seed the random number generator with current time
    srand((unsigned int)time(NULL));

    // Generate and print the random password
    generatePassword(passwordLength);

    return 0;
}
