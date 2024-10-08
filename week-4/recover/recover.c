#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 4;

const int JPEG_FAT_BLOCK_SIZE = 512;

const int true = 1;
const int false = 0;

typedef uint8_t BYTE;
typedef uint8_t BOOL;
 
int main(int argc, char *argv[])
{
    // Check command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE_FILENAME\n");
        return 1;
    }

    // Open file
    FILE *card_raw = fopen(argv[1], "r");
    if (card_raw == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    //  Read samples from input file and write updated data to output file
    BYTE buffer[JPEG_FAT_BLOCK_SIZE];
    BOOL is_writing = false;
    int img_found_counter = 0;
    BYTE output_buffer[JPEG_FAT_BLOCK_SIZE];
    char* filename;
    while(fread(&buffer, sizeof(buffer), 1, card_raw) != 0)
    {

        if(buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            printf("IMAGE START!\n");
            is_writing = true;
            sprintf(filename, "%03i.jpg", img_found_counter);
        }

        if(is_writing)
        {
            fwrite(&buffer, sizeof(buffer), 1, filename);
        }
        
    }

    // Close files
    fclose(card_raw);
 
}