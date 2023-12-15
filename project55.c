/*
    Roilene Vhinz Fajardo
    11/23/23
    BSCS 1A
*/
#include <stdio.h>

// Functions
void angleInput(double* angle);          // Function to input angle
int determineQuadrant(double angle);     // Function to Determine Quadrant
void printQuadrant(int quadrant);        // Function to Print Quadrant
int main()
{
    // Variables
    double angle;
    int quadrantNumber;

    // Function Calls
    angleInput(&angle);
    quadrantNumber = determineQuadrant(angle);
    printQuadrant(quadrantNumber);
    return 0;
}

void angleInput(double* angle)
{
    printf("Enter the angle:  ");
    scanf("%lf", angle);
}

int determineQuadrant(double angle)
{
    if (angle > 0.0 && angle < 90.0) // if angle is greater than 0 and less than 90
        return 1;
    else if (angle >= 90.0 && angle < 180.0) //if angle is greater than 90 and less than 180
        return 2;
    else if (angle >= 180.0 && angle < 270.0) //if angle is greater than 180 and less than 270
        return 3;
    else if (angle >= 270.0 && angle < 360.0) //if angle is greater tham 270 amd less than 360
        return 4;
    else if (angle < 0.0)
        return 5;
    else
    
        return 0; // Angle is on the X-axis
}

void printQuadrant(int quadrant)
{
    switch (quadrant)
    {
    case 1:  //if angle is greater than 0 and less than 90 it displays this
        printf("The angle is in Quadrant 1 and on the positive X-axis");
        break;
    case 2:  //if angle is greater than 90 and less than 180 it displays this
        printf("The angle is in Quadrant 2 and on the positive Y-axis");
        break;
    case 3: //if angle is greater than 180 and less than 270 it displays this
        printf("The angle is in Quadrant 3 and on the negative X-axis");
        break;
    case 4: //if angle is greater than 270 and less than 360 it displays this
        printf("The angle is in Quadrant 4 and on the negative Y-axis");
        break;
    case 5:
        printf("Please enter a positive number");
        break;
    case 0: //if angle is 0 it displays this
        printf("The angle is on the X-axis");
        break;
    default: // if angle is invalid
        printf("Invalid angle");
    }
}
