#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


const int JPEG_FAT_BLOCK_SIZE = 512;

typedef uint8_t BYTE;
 
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
    int img_found_counter = 0;
    char filename[9];
    FILE *output;
    while(fread(&buffer, sizeof(buffer), 1, card_raw) != 0)
    {

        if( 
            buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0
          )
        {
            if(img_found_counter > 0)
                fclose(output);
            
            sprintf(filename, "%03i.jpg", img_found_counter);
            
            output = fopen(filename, "w");

            img_found_counter++;
        }

        if(img_found_counter > 0)
        {
            fwrite(&buffer, sizeof(buffer), 1, output);

        }
        
    }

    // Close files
    fclose(card_raw);
    fclose(output);
 
}