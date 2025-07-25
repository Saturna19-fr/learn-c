#include <stdio.h>
#include <string.h>  // Include string.h for strcmp()

void SayHelloToUser() {
    char test[100]; // Buffer to hold the name
    printf("Hello, what's your name?\n> ");
    fgets(test, sizeof(test), stdin);  // Read the name (including spaces)

    // Print the name
    printf("Hello, %s!\n", test);
}

void ChooseAction() {
    char choice[2];  // Buffer for a single character (1 char + '\0' for null-termination)
    printf("What do you want to do today ?\n");
    printf("1 - Get the current timestamp\n");
    printf("2 - Say hello again !\n");

    fgets(choice, sizeof(choice), stdin);  // Read the choice

    // Remove the newline character if it's there
    choice[strcspn(choice, "\n")] = '\0';

    if (strcmp(choice, "1") == 0) {  // Compare strings using strcmp
        printf("Voici le timestamp actuel\n");
    } else if (strcmp(choice, "2") == 0) {  // Compare strings using strcmp
        SayHelloToUser();
    } else {
        printf("Nothing is working\n");
    }
}

int main() {
    printf("Hello world\n");
    SayHelloToUser();  // Call SayHelloToUser() to ask for the user's name and print it
    ChooseAction();     // Call ChooseAction() to ask user what to do
    return 0;
}
