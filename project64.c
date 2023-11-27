#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void quadratic_formula(double a, double b, double c);

int main() {
    
    double a, b, c;

    // Prompt Input from the user
    printf("Enter a: ");
    scanf("%lf", &a);

    printf("Enter b: ");
    scanf("%lf", &b);

    printf("Enter c: ");
    scanf("%lf", &c);

    quadratic_formula(a, b, c); // Call the quadratic_formula function

    return 0;
}

void quadratic_formula(double a, double b, double c) 
{
    if (a == 0 && b == 0)  // If a & b are 0, there will be no solutions
    {
        printf("No solution\n"); 

        exit(1);  // Indicate an error and exit the program
    } 
    else if (a == 0) // If a is zero there will be one root
    {
        
        double root;
        root = -c / b;
        
        printf("x1: %.2lf\n", root);
        printf("x2: 0\n");
    } 
    else if (b == 0) 
    {
        double root;
        root = -c / a;
        printf("x1: %.2lf\n", root);
        printf("x2: 0\n");
    }
    else 
    {
        // Calculate the discriminant
        double discriminant = b * b - 4 * a * c;

        if (discriminant >= 0) // Check if the discriminant is non-negative
        {
            // Calculate the two roots using the quadratic formula
            
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);

            printf("x1: %.2lf\n", root1);
            printf("x2: %.2lf\n", root2);
        } 
        else //if the Discriminant is Negative there are no real roots
        {
            printf("There are no real roots");
        }
    }
}
