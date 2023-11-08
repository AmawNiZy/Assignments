#include <stdio.h>
#include <math.h>
#define FORMULAOFRIGHTTRAINGLE 0.5

double AreaOfaRightTriangle(double base, double height);

double perimeterOfaRightTriangle(double base2, double height2);

int main()
{
   double heightOfTriangle,baseOfTriangle;
   double receivedArea;
   double receivedPerimeter;
   
   printf("Enter Height of Triangle: ");
   scanf("%lf", &heightOfTriangle);
   
   printf("Enter Base of Triangle: ");
   scanf("%lf", &baseOfTriangle);
   
   receivedPerimeter = perimeterOfaRightTriangle(baseOfTriangle, heightOfTriangle);
   receivedArea = AreaOfaRightTriangle(baseOfTriangle, heightOfTriangle);
   
   printf("The Area of a Right Triangle is: %.2lf\n", receivedArea);
   printf("The Perimeter of a Right Triangle is: %.2lf", receivedPerimeter);
   
   return 0;
}
double AreaOfaRightTriangle(double base, double height)
{
double calcArea= (FORMULAOFRIGHTTRAINGLE)  * base * height;
return calcArea;
}
double perimeterOfaRightTriangle(double base2,  double height2)
 {

    double hypotenuse = sqrt(base2* base2 + height2 * height2); 
    double calcPerimeter = base2 + height2 + hypotenuse; 
    return calcPerimeter;
}