#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // Check if the file was opened successfully
    if (card == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        return 2;
    }

    // Create a buffer for a block of data
    uint8_t buffer[512];

    // Initialize external variables needed for recovery:
    FILE *img = NULL;
    int img_count = 0;
    bool found_jpeg = false;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, BLOCK_SIZE, card) == BLOCK_SIZE)
    {
        // Create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If this is not the very first JPEG, close the previous one
            if (found_jpeg == true)
            {
                fclose(img);
            }

            // A new JPEG header has been found
            found_jpeg = true;

            // Generate filename (e.g., "000.jpg", "001.jpg")
            char filename[8]; // Enough for "000.jpg\0"
            sprintf(filename, "%03i.jpg", img_count);

            // Open new file for writing
            img = fopen(filename, "w");

            // Write the current 512-byte block to the new file
            fwrite(buffer, 1, BLOCK_SIZE, img);

            // Increment image count for the next file
            img_count++;
        }
        // If a JPEG has already been found, keep writing to it
        else if (found_jpeg == true)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }

    // Close any remaining open files

    // Close the last JPEG file (if one was found)
    if (img != NULL)
    {
        fclose(img);
    }

    // Close the input card file
    fclose(card);

    return 0;
}
