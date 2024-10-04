#include <stdio.h>
#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    printf("\nSelected GrayScale Filter\n");

    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int ave = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            image[i][j].rgbtBlue = ave;
            image[i][j].rgbtGreen = ave;
            image[i][j].rgbtRed = ave;

        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    printf("\nSelected Reflect Filter\n");

    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE aux = image[i][j];

            image[i][j] = image[i][width - j - 1];

            image[i][width - j - 1] = aux;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    printf("\nSelected Blur Filter\n");

    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if( i < 1 || j < 1 || (i + 1) == height || (j + 1) == width) continue;

            int b_ave = 0;
            int g_ave = 0;
            int r_ave = 0;

            for (int line = i-1; line < i+2; line++)
            {
                for (int col = j-1; col < j+2; col++)
                {
                    b_ave += image[line][col].rgbtBlue;
                    g_ave += image[line][col].rgbtGreen;
                    r_ave += image[line][col].rgbtRed;
                }
            }
          
            b_ave /= 9;
            g_ave /= 9;
            r_ave /= 9;

            image[i][j].rgbtBlue = b_ave;
            image[i][j].rgbtGreen = g_ave;
            image[i][j].rgbtRed = r_ave;
        }
    }

    return;
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    printf("\nSelected Edges Filter\n");

    /**
     * Create a copy to not read the same modify array.
     * Therefore, I read the 'copy' variable and modify 'image' variable.
     * BTW, I spend hours to 'realize' that.
     * (Thanks, chatGPT)
     *  */
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if( i < 1 || j < 1 || (i + 1) == height || (j + 1) == width) continue;
            int b_gx = 0;
            int b_gy = 0;

            int g_gx = 0;
            int g_gy = 0;

            int r_gx = 0;
            int r_gy = 0;

            int gx[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
            int gy[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
            int kernel_index = 0;

            for (int line = i-1; line < i+2; line++)
            {
                for (int col = j-1; col < j+2; col++)
                {
                    b_gx += gx[kernel_index] * copy[line][col].rgbtBlue;
                    b_gy += gy[kernel_index] * copy[line][col].rgbtBlue;

                    g_gx += gx[kernel_index] * copy[line][col].rgbtGreen;
                    g_gy += gy[kernel_index] * copy[line][col].rgbtGreen;

                    r_gx += gx[kernel_index] * copy[line][col].rgbtRed;
                    r_gy += gy[kernel_index] * copy[line][col].rgbtRed;

                    kernel_index++;
                }
            }

            int b_result = round( sqrt( ( pow(b_gx, 2) + pow(b_gy, 2) ) ) );
            int g_result = round( sqrt( ( pow(g_gx, 2) + pow(g_gy, 2) ) ) );
            int r_result = round( sqrt( ( pow(r_gx, 2) + pow(r_gy, 2) ) ) );

            b_result = ( b_result > 255 ) ? 255 : b_result;
            g_result = ( g_result > 255 ) ? 255 : g_result;
            r_result = ( r_result > 255 ) ? 255 : r_result;

            image[i][j].rgbtBlue = b_result;
            image[i][j].rgbtGreen = g_result;
            image[i][j].rgbtRed = r_result;
        }
    }

    return;
}
