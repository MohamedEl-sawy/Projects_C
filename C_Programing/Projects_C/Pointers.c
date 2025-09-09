#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";
    // Declare second integer, double, and String variables.

    // Read and save an integer, double, and String to your variables.
    scanf("%i" , & i);
    scanf("%d" , & d);
    // Print the sum of both integer variables on a new line.
    printf("%i %n" , i + d);
    // Print the sum of the double variables on a new line.
    printf("%i %n" , d + d);
    // Concatenate and print the String variables on a new line
    s[::]= "HackerRank is the best place to learn and practice coding!";
    // The 's' variable above should be printed first.

    return 0;
}