#include <stdio.h>
#include <math.h>

double roundToTwoDecimalPlaces(double num) ;

int main()
 {
    double number;
    double convertCeilingValue;
    double convertFloorValue;
    double convertRoundedValue;
    
    printf("Enter a floating-point number: ");
    scanf("%lf", &number);

    convertCeilingValue= ceil(number);
    convertFloorValue = floor(number);
    convertRoundedValue= roundToTwoDecimalPlaces(number);

    printf("Original number: %lf\n", number);
    printf("Ceiling value: %lf\n", convertCeilingValue);
    printf("Floor value: %lf\n",convertFloorValue);
    printf("Rounded value: %.2lf\n", convertRoundedValue);

    return 0;
}
double roundToTwoDecimalPlaces(double num) 
{
    double rounded = round(num * 100.0) / 100.0;
    return rounded;
}