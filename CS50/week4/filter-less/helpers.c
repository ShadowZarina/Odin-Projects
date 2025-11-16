#include <getopt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get original color values
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // Take average of red, green, and blue
            int average = (int) ((originalRed + originalGreen + originalBlue) / 3.0 + 0.5);

            // Update pixel values
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get original color values
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // Compute sepia values
            int sepiaRed =
                (int) (.393 * originalRed + .769 * originalGreen + .189 * originalBlue + 0.5);
            int sepiaGreen =
                (int) (.349 * originalRed + .686 * originalGreen + .168 * originalBlue + 0.5);
            int sepiaBlue =
                (int) (.272 * originalRed + .534 * originalGreen + .131 * originalBlue + 0.5);

            // Update pixel with sepia values
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all rows of pixels
    for (int i = 0; i < height; i++)
    {
        // Loop over only the first half of the pixels in the row
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels: image[i][j] with image[i][width - 1 - j]
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            int count = 0;

            // Loop through the 3x3 grid around the current pixel (i, j)
            for (int r = -1; r <= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    int row = i + r;
                    int col = j + c;

                    // Check if the neighbor pixel is within the image bounds
                    if (row >= 0 && row < height && col >= 0 && col < width)
                    {
                        sumRed += copy[row][col].rgbtRed;
                        sumGreen += copy[row][col].rgbtGreen;
                        sumBlue += copy[row][col].rgbtBlue;
                        count++;
                    }
                }
            }

            // Calculate the average (with rounding) and update the original image
            image[i][j].rgbtRed = (int) (sumRed / (float) count + 0.5);
            image[i][j].rgbtGreen = (int) (sumGreen / (float) count + 0.5);
            image[i][j].rgbtBlue = (int) (sumBlue / (float) count + 0.5);
        }
    }
}
