#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to rotate a character
char rotate(char c, int k)
{
    // Convert key k to k % 26
    int mod_key = k % 26;

    if (islower(c))
    {
        // 'a' is 97 in ASCII. (c - 'a') gives the 0-25 index.
        // ((index + mod_key) % 26) keeps the result within 0-25.
        // Add 'a' back to convert to ASCII.
        return (char) (((c - 'a') + mod_key) % 26 + 'a');
    }
    else if (isupper(c))
    {
        // Similar logic for uppercase letters, using 'A' (ASCII 65)
        return (char) (((c - 'A') + mod_key) % 26 + 'A');
    }
    return c; // Return non-letters unchanged
}

int main(int argc, string argv[])
{
    // Check for invalid usage (need exactly one command-line argument)
    if (argc != 2)
    {
        printf("Usage: ./cipher key\n");
        return 1;
    }

    // Check if every character in argv[1] is a digit
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./cipher key\n");
            return 1;
        }
    }

    // Convert argv[1] into an integer (the key)
    int key = atoi(argv[1]);

    // Prompt user for the plaintext
    string plaintext = get_string("plaintext: ");

    // Print the start of the ciphertext
    printf("ciphertext: ");

    // For loop for every character in the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        // Rotate the character if it's a letter (using a placeholder function call)
        if (isalpha(c))
        {
            // You would implement the actual rotation logic here or in the rotate function
            char ciphertext_char = rotate(c, key);
            printf("%c", ciphertext_char);
        }
        else
        {
            // Print non-alphabetic characters as they are
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}
