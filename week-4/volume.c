// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

typedef uint8_t BYTE;
typedef uint16_t DOUBLE_BYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    BYTE header_buffer[HEADER_SIZE];
    fread(&header_buffer, 44, 1, input);
    //printf("%d\n", header_buffer);
    fwrite(&header_buffer, 44, 1, output);


    // TODO: Read samples from input file and write updated data to output file
    DOUBLE_BYTE sample_buffer = 0;
    while(fread(&sample_buffer, sizeof(sample_buffer), 1, input) != 0)
    {
        DOUBLE_BYTE amp_sample_buffer = sample_buffer * factor;
        //printf("%f, %d, %d\n", factor, sample_buffer, amp_sample_buffer);
        fwrite(&amp_sample_buffer, sizeof(sample_buffer), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}

/**
      >>> BUT, what is the transfer rate?
    
      >>>>> MACHINE
    
           _,met$$$$$gg.          geovani@SeuMadruga 
        ,g$$$$$$$$$$$$$$$P.       ------------------ 
      ,g$$P"     """Y$$.".        OS: Debian GNU/Linux 12 (bookworm) x86_64 
     ,$$P'              `$$$.     Host: 270E5K/270E5Q/271E5K/2570EK P08RDH 
    ',$$P       ,ggs.     `$$b:   Kernel: 6.1.0-25-amd64 
    `d$$'     ,$P"'   .    $$$    Uptime: 7 days, 2 hours, 56 mins 
     $$P      d$'     ,    $$P    Packages: 1853 (dpkg), 4 (snap) 
     $$:      $$.   -    ,d$$'    Shell: bash 5.2.15 
     $$;      Y$b._   _,d$P'      Resolution: 1920x1080 
     Y$$.    `.`"Y$$$$P"'         DE: GNOME 43.9 
     `$$b      "-.__              WM: Mutter 
      `Y$$                        WM Theme: Adwaita 
       `Y$$.                      Theme: Adwaita [GTK2/3] 
         `$$b.                    Icons: Adwaita [GTK2/3] 
           `Y$$b.                 Terminal: gnome-terminal 
              `"Y$b._             CPU: Intel i5-5200U (4) @ 2.100GHz 
                  `"""            GPU: Intel HD Graphics 5500 
                                  GPU: NVIDIA GeForce 920M 
                                  Memory: 6408MiB / 7836MiB
                                  SSD: 120GB


    >>>>> DATA

    geovani@SeuMadruga:~/app/cs50/week-4$ time ./volume input.wav output.wav 0.1
    real    0m0,021s <----- TIME
    user    0m0,021s
    sys     0m0,000s
    geovani@SeuMadruga:~/app/cs50/week-4$ ls -la
    total 724
    drwxr-xr-x  2 geovani geovani   4096 set 14 12:43 .
    drwxr-xr-x 10 geovani geovani   4096 set 12 22:42 ..
    -rw-r--r--  1 geovani geovani 352844 dez 31  2021 input.wav
    -rw-r--r--  1 geovani geovani 352844 set 14 12:43 output.wav <---- SIZE
    -rwxr-xr-x  1 geovani geovani  16240 set 14 12:43 volume
    -rw-r--r--  1 geovani geovani   1442 set 14 12:43 volume.c

    >>>>> CALC

    rate = SIZE / TIME
            352844 B / 0.021s
            0.352844 MB / 0.021s

    rate = 16.802095238 MB/s

    
    >>> COMPARE TO REGULAR 'cp'

    geovani@SeuMadruga:~/app/cs50/week-4$ time cp input.wav output.wav

    real    0m0,015s
    user    0m0,011s
    sys     0m0,001s

    >>>>> CALC

    rate = SIZE / TIME
            352844 B / 0.015s
            0.352844 MB / 0.015s

    rate = 23.522933333 MB/s

*/
