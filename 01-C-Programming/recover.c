#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for correct command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open the forensic image file
    FILE *drive = fopen(argv[1], "r");
    if (drive == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Allocate buffer for a 512-byte block
    unsigned char buffer[512];

    // Variables for file naming and the current output file
    char filename[8];
    FILE *imgf = NULL;
    int count = 0;

    // Read 512-byte blocks from the forensic image
    while (fread(buffer, 512, 1, drive) == 1)
    {
        // Check for the start of a new JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If an image is currently open, close it
            if (imgf != NULL)
            {
                fclose(imgf);
            }

            // Create a new filename (e.g., 000.jpg, 001.jpg)
            sprintf(filename, "%03i.jpg", count);

            // Open the new image file for writing
            imgf = fopen(filename, "w");
            if (imgf == NULL)
            {
                fclose(drive);
                return 1;
            }

            // Increment the image counter
            count++;
        }

        // If a JPEG file is currently open, write the block to it
        if (imgf != NULL)
        {
            fwrite(buffer, 512, 1, imgf);
        }
    }

    // Clean up: close any remaining open files and free memory
    if (imgf != NULL)
    {
        fclose(imgf);
    }
    fclose(drive);

    return 0;
}
