#include <stdio.h>

//Constants
#define LABOR 0.35
#define TAX 0.085

//Functions
int area(int reLength, int reWidth);
double convertDiscount (double discount);
int carpetCost(int carpetArea, int carpetCost);
double discountAmount(double iniArea, double discountofCustomer);
double finalLaborCost(double PriceArea, double labor);
double finalInstallPrice (double finalLaborCost, double installArea);
double initialSubtotal (double InitialDiscountAmount, double initialFinalInstall);
double initialTotal(double final_Subtotal, double final_TAX);
double iniTAX(double iniTotal, double ini_tax);

//Main function
int main()
{
    // Variables
    char percent = '%';
    int length;
    int width;
    int customerDiscount;
    int finalCarpetPrice;
    int initialArea;
    double finalDiscountAmount;
    double costPerSquareFoot;
    double laborCost;
    double finalInstall; 
    double subTotal;
    double Total;
    double InitialTAX;

    //Statements
    printf("\n");
    printf("Length of room (feet)?\t\t");
    scanf("%d", &length);
    printf("Width of room (feet)?\t\t");
    scanf("%d", &width);
    printf("Customer discount (percent)?\t ");
    scanf("%d", &customerDiscount);
    printf("Cost per square foot (xxx.xxx)?\t ");
    scanf("%lf", &costPerSquareFoot);
    printf("\n\n");

    // function calls
    initialArea = area(length, width);  
    finalCarpetPrice = carpetCost(customerDiscount, costPerSquareFoot);
    laborCost = finalLaborCost(initialArea, LABOR);
    finalInstall = finalInstallPrice(laborCost , initialArea); 
    finalDiscountAmount = discountAmount(finalInstall, customerDiscount);
    subTotal = initialSubtotal(finalDiscountAmount, finalInstall);
    Total = initialTotal(subTotal, TAX);
    InitialTAX = iniTAX(subTotal, TAX);

    //Outputs
    printf("\t\t\t MEASUREMENT \t\t\t\n");
    printf("Length:\t\t\t\t\t\t%d ft\n", length);
    printf("Width:\t\t\t\t\t\t%d ft\n", width);
    printf("Area:\t\t\t\t\t\t%d square ft\n", initialArea);
   
    printf("\n\t\t\t     CHARGES \t\t\t\n");
    printf("\n");
    printf("DESCRIPTION\t           COST/SQ.FT.\t\t\tCHARGE\n");
    printf("-----------\t           -----------\t\t   ---------------\n");
    printf("Carpet\t\t               %.2lf\t\t\t  $%d\n", costPerSquareFoot , finalCarpetPrice);
    printf("Labor\t\t               0.35\t\t\t  $%.2lf\n", laborCost);
    printf("\t\t\t\t\t\t   ---------------\n");
    printf("INSTALLED PRICE\t\t\t\t\t\t  $%.2lf\n", finalInstall);
    printf("Discount (Percent)\t\t%d%c\t\t\t  $%.2lf\n", customerDiscount, percent, finalDiscountAmount);
    printf("\t\t\t\t\t\t   ---------------\n");
    printf("SUBTOTAL\t\t\t\t\t\t  $%.2lf\n", subTotal);
    printf("Tax\t\t\t\t\t\t\t  $%.2lf\n", InitialTAX);
    printf("TOTAL\t\t\t\t\t\t\t  $%.2lf\n", Total);

    return 0;
}
int area(int reLength, int reWidth)
{
    int finalArea = reLength * reWidth;
    return finalArea;
}
int carpetCost(int carpetArea, int carpetCost)
{
    int finalCarpetCost =  carpetArea * carpetCost;
    return finalCarpetCost;
}
double discountAmount(double carpetinstallPrice, double discountofCustomer)
{
    double finalCarpet = (double)carpetinstallPrice;
    double finalDiscount = discountofCustomer / 100.0;
    double finalPrice = (finalCarpet * finalDiscount);
    return finalPrice; // Return the discounted price
}
double finalLaborCost(double PriceArea, double labor)
{
    double laborCost = PriceArea * labor;
    double finalLabor = laborCost;
    return finalLabor;
}
double finalInstallPrice (double finalLaborCost, double installArea)
{
    double Install = finalLaborCost + installArea;
    return Install;
}
double initialSubtotal (double InitialDiscountAmount, double initialFinalInstall)
{
    double final_subtotal = initialFinalInstall - InitialDiscountAmount;
    return final_subtotal;
}
double initialTotal(double final_Subtotal, double final_TAX)
{
    double iniTotal = final_Subtotal * final_TAX;
    double finaltotal = final_Subtotal - iniTotal;
    return finaltotal;
}
double iniTAX(double Itotal, double ini_tax)
{
    double iniTotal = Itotal * ini_tax;
    return iniTotal;
}
