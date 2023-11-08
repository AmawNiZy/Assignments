#include <stdio.h>
#include <math.h>

double roundOffNumber (double randomNumber);

int main() 
{
    double userInput;
    double doneRounded;
    int roundedInt;

    printf("Enter a floating-point number: ");
    scanf("%lf", &userInput);
    
    doneRounded = roundOffNumber(userInput);
    
    roundedInt = (int)(doneRounded* 100);
    
    double result = (double)roundedInt / 100.0;

    printf("Original input: %.6lf\n", userInput);
    printf("Rounded and converted: %.6lf\n", result);

    return 0;
}
double roundOffNumber (double randomNumber)
{
    double rounded = round(randomNumber * 100) / 100;
    return rounded;
}

