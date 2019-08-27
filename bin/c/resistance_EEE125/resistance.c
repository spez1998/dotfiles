#include <stdio.h>
#include <math.h>
#include "resistance.h"

/* Since most of my functions call upon other functions, it is good practice to declare them now so that the functions know what they are referring to.
void choices(float size_x, float x[]);
float res_mean(float size_x, float x[]);
void res_stdev(float size_x, float x[]);
void res_largest(float size_x, float x[]);
The use of size_x and float x[] for each function is a way of passing the same values for resistances and number of resistors through many different functions. */

void list_res_values(float size_x, float x[]) /* Function to print all the array values for the resistances. */
{
    int counter;
    printf("\n"); /* For formatting. */
    for (counter = 0; counter < size_x; counter++) /* for loop prints each datum at each array point once, giving a list of inputted values. */
    {
        printf("%14.6f\n", x[counter]); /* 14.6 ensures that the values are aligned by their decimal points. */
    }
}


void end_choices(float size_x, float x[]) /* Function to direct user when the current analysis tool finishes. */
{
    int end_choice;
    scanf("%d", &end_choice);
    switch(end_choice)
    {
        case 1: /* First choice; user wants to do something else with the same resistor values. */
            choices(size_x, x);
            break;
        case 2: /* Second choice; user wants to exit program. Since main() returns 0, this is not required here. */
            break;
        default: /* For invalid inputs. */
            printf("\nYou have not made a valid selection. Please try again.");
            end_choices(size_x, x); /* Invalid input restarts function. */
    }

}


void choices(float size_x, float x[]) /*Function for choosing which analysis to perform on resistor values. */
{
    printf("\nPlease choose which function you would like to use.\n");
    printf("Select 1 for mean value calculation, 2 for standard deviation calculation, or 3 for the largest resistor value.\n");
    int choice;
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            res_mean(size_x, x);
            printf("\nWould you like to return to the calculation selector or exit the program?"); /* Printing these questions now rather than at the end at each of the functions is easiest to do */
            printf("\nSelect 1 to return to the calculation selector, or 2 to exit.");
            end_choices(size_x, x); /* At every point, size_x and x are passing through the values for the resistances and the number of resistors chosen */
            break;
        case 2:
            res_stdev(size_x, x);
            printf("\nWould you like to return to the calculation selector or exit the program?");
            printf("\nSelect 1 to return to the calculation selector, or 2 to exit.");
            end_choices(size_x, x);
            break;
        case 3:
            res_largest(size_x, x);
            printf("\nWould you like to return to the calculation selector or exit the program?");
            printf("\nSelect 1 to return to the calculation selector, or 2 to exit.");
            end_choices(size_x, x);
            break;
        default:
            printf("You have chosen an invalid option. Please try again.");
            choices(size_x, x);
    }
}


float res_mean(float size_x, float x[]) /* Function for finding mean; this returns a float value so it must be initialised with float */
{
    int count;
    float sum = 0, mean;
    for (count = 0; count < size_x; count++)
    {
        sum = sum + x[count]; /* Loop adds every value to the sum of all values until all resistor values have been exhausted. */
    }
    mean = sum / size_x;
    printf("\nThe mean resistance is %f\n", mean);
    float *mean_loc; /* Pointer to mean value was required instead of just returning the mean value which would actually return the memory address at which the mean value was stored. */
    mean_loc = &mean;
    return(*mean_loc);
}

void res_stdev(float size_x, float x[])
{
    float stdev_mean, stdev_numer = 0, stdev_denom, stdev;
    stdev_mean = res_mean(size_x, x); /* Use previous mean function to save lines. */
    int counter;
    for (counter = 0; counter < size_x ; counter++)
    {
        stdev_numer = stdev_numer + pow(((x[counter]) - stdev_mean),2); /* Calculating each of the numerator and denominator to the standard deviation formula is easiest for formatting. */
    }
    stdev_denom = size_x - 1;
    stdev = sqrt(stdev_numer / stdev_denom);
    printf("The standard deviation for the resistor values is %f.\n", stdev); /* No return value since no other function needs the standard deviation value. */
}


void res_largest(float size_x, float x[])
{
    float res_max;
    int count; /* Equivalent to "counter" variable for previous loops of this nature. */
    res_max = x[0];
    for (count = 0; count < size_x; count++) /* Loop compares if the next array value is larger than the current one; if it is, the current array value is used as the comparison for the others. */
    {
        if (x[count] > res_max)
        {
            res_max = x[count];
        }

    }
    printf("The largest resistance is %f.\n", res_max);
}

int main(void)
{
    float num_of_res = 0;
    float resistors[10]={0}; /* Array required initial size; variable-based array sizes impossible to use with this compiler. */
    printf("Please enter the number of resistors whose values you wish to analyse.\n");
    printf("Please enter only a number between 2 and 10 inclusive.\n");
    scanf("%f", &num_of_res);
    if (num_of_res < 2 || num_of_res > 10)
    {
        printf("You have chosen an invalid number of resistors.\n");
        main();
    }
    else
    {
        ("You have chosen to analyse %d resistors.", num_of_res);
        printf("\nPlease prepare to enter the resistor values.");
        printf("\nValues lower than 0.001 ohms or larger than 1000000 ohms will not be accepted by the program.\n");
        int counter;
        for (counter = 0; counter < num_of_res; counter++) /* This for loop structure is seen throughout the program; it's an effective way of limiting the amount of results inputted into an array. */
        {
            do
            {
                scanf("%f", &resistors[counter]);
            } while (resistors[counter] < 0.001 || resistors[counter] > 1000000); /* This rejects any value smaller than 0.001 or grater than 1x10^6 ohms */
        }
        printf("Thank you. Your entered values will now be displayed on screen.\n");
        list_res_values(num_of_res, resistors); /*For efficiency, this was made into a separate function. */
        choices(num_of_res, resistors);
        return (0); /* return value for program called here rather than within choices() since main must always return an int value */
    }
}


