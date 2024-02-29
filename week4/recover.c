#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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

    // Create a buffer for a block of data
    uint8_t buffer[512];

    // Counter for the JPEG files
    int file_counter = 0;

    // File pointer for the JPEG files
    FILE *img = NULL;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Check if the start of a new JPEG is found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close the current JPEG file if it exists
            if (img != NULL)
            {
                fclose(img);
            }

            // Create a new JPEG file
            char filename[8];
            sprintf(filename, "%03i.jpg", file_counter++);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create JPEG file.\n");
                return 1;
            }
        }

        // Write the block of data to the current JPEG file if it exists
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // Close the last JPEG file and the memory card
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);

    return 0;
}
