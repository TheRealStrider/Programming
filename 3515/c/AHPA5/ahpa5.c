#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *clearMessage = fopen("clearMessage.txt", "r"); // Open the message
    char message[23]; // Stores the characters of the message
    if (clearMessage == NULL) { // Check if the file exists
        perror("File not found\n");
        return 1;
    }
    for (int i = 0; i < sizeof(message); i++) { // Read the message and store it in the array
        int character = fgetc(clearMessage);
        message[i] = character;
    }
    fclose(clearMessage); // Close the file

    for (int i = 0; i < sizeof(message); i++) { // Encrypt the message
        if (isalpha(message[i])) {
            message[i] = (char) ((int) message[i] + 3);
        }
    }

    FILE *secretMessage = fopen("secretMessage.txt", "w"); // Create the file to store the encrypted message
    fprintf(secretMessage, "%s", message); // Write the encrypted message to the file
    fclose(secretMessage); // Close the file

}
