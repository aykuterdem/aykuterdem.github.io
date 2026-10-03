/**
 * File: color_wheel.c
 * Based on code written by Jerry Cain and Lisa Yan
 * ----------------------------------
 * This program prints out information about the color encoded by the unsigned
 * integer specified as a command-line argument.  The entered integer will be
 * subdivided into its bytes, where the understanding is that of its 4 least
 * significant bytes, byte 0 (from the left) encodes an opacity on a scale
 * from 0 - 255, byte 1 encodes a red contribution from 0 - 255, byte two a
 * green contribution from 0 - 255, and byte 3 a blue contribution from 0 - 255.
 *
 * Specifically, this program uses bitwise operations and masking tricks to
 * list the color's red, blue, and green contributions, a description of its
 * opacity, and information about the color's complement as well.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/* This function prints out information for the given RGB/Opacity values. */
void print_RGB_values(unsigned char red, unsigned char green, 
    unsigned char blue, unsigned char opacity) {

    // Print a description of the opacity
    printf("\topacity: ");
    if (opacity == UCHAR_MAX) {
        printf(" fully opaque");
    } else if (opacity == 0) {
        printf(" entirely transparent");
    } else if (opacity > 3 * UCHAR_MAX / 4) {
        printf(" mostly opaque, but not fully so");
    } else if (opacity > UCHAR_MAX / 2) {
        printf(" more opaque than not");
    } else if (opacity > UCHAR_MAX / 4) {
        printf(" more transparent than not");
    } else {
        printf(" almost transparent, but not fully so");
    }
    printf("\n");

    printf("\tred:     %03u (0x%02x)\n", red, red);
    printf("\tgreen:   %03u (0x%02x)\n", green, green);
    printf("\tblue:    %03u (0x%02x)\n", blue, blue); 
    printf("\n");
}

/* This function breaks the given color value into its RGB/Opacity values
 * and prints out information about them. 
 */
void print_RGB_values_for_color(unsigned int color) {
    unsigned char opacity = color >> CHAR_BIT * 3;
    unsigned char red = color >> CHAR_BIT * 2;
    unsigned char green = color >> CHAR_BIT;
    unsigned char blue = color;
    
    print_RGB_values(red, green, blue, opacity);
}

/* This function prints out an overview of the given color, including its
 * decimal and hex representations, RGB/opacity values, and the RGB/opacity
 * values of its complement color.
 */
void print_color_analysis(unsigned int color) {    
    printf("As a decimal number: %u\n", color);
    printf("As a hex number: 0x%x\n", color);
    printf("These are the color's red, green, and blue contributions:\n\n");
    print_RGB_values_for_color(color);

    unsigned int complement = color ^ 0x00FFFFFF;
    printf("These are the complementary color's red, green, and blue contributions:\n\n");
    print_RGB_values_for_color(complement);
}

int main(int argc, const char *argv[]) {
    // strtod helps us convert string -> unsigned int (we'll learn more later)
    unsigned int color = strtod(argv[1], NULL);
    print_color_analysis(color);
    return 0;
}
