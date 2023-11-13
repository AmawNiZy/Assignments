#include <stdio.h>

// Constants
#define LABOR 0.35 // Labor
#define TAX 0.085   // Tax

// Function declarations
int calculateCarpetCost(int carpetArea, int carpetCost); // Cost of Carpet after Calculating with Cost per Square foot
int area(int reLength, int reWidth);                // Area of Carpet
double convertDiscount(double discount);            // Convert discount to percentage
double discountAmount(double iniArea, double discountofCustomer); // Total discount of Customer
double finalLaborCost(double PriceArea, double labor); // Labor Cost per Square Foot
double finalInstallPrice(double finalLaborCost, double installArea); // Install Price after Calculating Labor Cost and Area
double initialSubtotal(double carpetCost, double laborCost, double installPrice); // Subtotal
double initialTotal(double final_Subtotal, double final_TAX); // Total
double iniTAX(double iniTotal, double ini_tax); // Amount of tax after Calculation
double squareFootCarpet();     // input Cost per Square foot
int roomLength();              // Input room length
int roomWidth();               // Input room Width
int inputDiscount();           // Input discount
void Measurement(int finLength, int finWidth, int finArea); // Print Measurements
void Charges(double costPerSqFoot, int finCarpetPrice, double costLabor, double installFinal, int custDisc, char per, double finDiscAmount, double SubTotal, double iniTAXAmount, double fintotal);

int main() {
    // Variables
    char percent = '%';
    int inputLength1;
    int inputWidth1;
    int inputCustomerDiscount1;
    int finalCarpetPrice;
    int initialArea;
    double finalDiscountAmount;
    double inputCostPerSquareFoot1;
    double laborCost;
    double finalInstall;
    double subTotal;
    double Total;
    double InitialTAX;

    // Statements
    printf("\n");
    inputLength1 = roomLength();
    inputWidth1 = roomWidth();
    inputCustomerDiscount1 = inputDiscount();
    inputCostPerSquareFoot1 = squareFootCarpet();
    printf("\n\n");

    // Function calls
    initialArea = area(inputLength1, inputWidth1);
    finalCarpetPrice = calculateCarpetCost(initialArea, inputCostPerSquareFoot1);
    laborCost = finalLaborCost(initialArea, LABOR);
    finalInstall = finalInstallPrice(laborCost, initialArea);
    finalDiscountAmount = discountAmount(finalCarpetPrice, inputCustomerDiscount1);
    subTotal = initialSubtotal(finalCarpetPrice, laborCost, finalInstall);
    Total = initialTotal(subTotal, TAX);
    InitialTAX = iniTAX(subTotal, TAX);

    // Outputs
    Measurement(inputLength1, inputWidth1, initialArea);
    Charges(inputCostPerSquareFoot1, finalCarpetPrice, laborCost, finalInstall, inputCustomerDiscount1,
             percent, finalDiscountAmount, subTotal, InitialTAX, Total);

    return 0;
}

int roomLength() {
    int inputlength;
    printf("Length of room (feet)?\t\t");
    scanf("%d", &inputlength);
    return inputlength;
}

int roomWidth() {
    int inputwidth;
    printf("Width of room (feet)?\t\t");
    scanf("%d", &inputwidth);
    return inputwidth;
}

int inputDiscount() {
    int inputCustomerDiscount;
    printf("Customer discount (percent)?\t ");
    scanf("%d", &inputCustomerDiscount);
    return inputCustomerDiscount;
}

double squareFootCarpet() {
    double inputCostPerSquareFoot;
    printf("Cost per square foot (xxx.xxx)?\t ");
    scanf("%lf", &inputCostPerSquareFoot);
    return inputCostPerSquareFoot;
}

int area(int reLength, int reWidth) {
    int finalArea = reLength * reWidth;
    return finalArea;
}

void Measurement(int finLength, int finWidth, int finArea) {
    int inputLength2 = finLength;
    int inputWidth2 = finWidth;
    int initialArea1 = finArea;
    printf("\t\t\t MEASUREMENT \t\t\t\n");
    printf("Length:\t\t\t\t\t\t%d ft\n", inputLength2);
    printf("Width:\t\t\t\t\t\t%d ft\n", inputWidth2);
    printf("Area:\t\t\t\t\t\t%d square ft\n", initialArea1);
    return;
}

int calculateCarpetCost(int carpetArea, int carpetCost) {
    int finalCarpetCost = carpetArea * carpetCost;
    return finalCarpetCost;
}

double discountAmount(double iniArea, double discountofCustomer) {
    double finalDiscount = iniArea * (discountofCustomer / 100.0);
    return finalDiscount; // Return the discounted amount
}

double finalLaborCost(double PriceArea, double labor) {
    double laborCost = PriceArea * labor;
    double finalLabor = laborCost;
    return finalLabor;
}

double finalInstallPrice(double finalLaborCost, double installArea) {
    double Install = finalLaborCost + installArea;
    return Install;
}

double initialSubtotal(double carpetCost, double laborCost, double installPrice) {
    double subtotal = carpetCost + laborCost + installPrice;
    return subtotal;
}

double initialTotal(double final_Subtotal, double final_TAX) {
    double iniTotal = final_Subtotal + (final_Subtotal * final_TAX);
    return iniTotal;
}

double iniTAX(double Itotal, double ini_tax) {
    double iniTotal = Itotal * ini_tax;
    return iniTotal;
}

void Charges(double costPerSqFoot, int finCarpetPrice, double costLabor, double installFinal, int custDisc, char per, double finDiscAmount, double SubTotal, double iniTAXAmount, double fintotal) {
    double inputCostPerSquareFoot1 = costPerSqFoot;
    int finalCarpetPrice1 = finCarpetPrice;
    double laborCost = costLabor;
    double finalInstall1 = installFinal;
    int inputCustomerDiscount2 = custDisc;
    char percent1 = per;
    double finalDiscountAmount1 = finDiscAmount;
    double subTotal1 = SubTotal;
    double InitialTAX1 = iniTAXAmount;
    double Total1 = fintotal;

    printf("\n\t\t\t     CHARGES \t\t\t\n");
    printf("\n");
    printf("DESCRIPTION\t           COST/SQ.FT.\t\t\tCHARGE\n");
    printf("-----------\t           -----------\t\t   ---------------\n");
    printf("Carpet\t\t               %.2lf\t\t\t  $%d\n", inputCostPerSquareFoot1, finalCarpetPrice1);
    printf("Labor\t\t               0.35\t\t\t  $%.2lf\n", laborCost);
    printf("\t\t\t\t\t\t   ---------------\n");
    printf("INSTALLED PRICE\t\t\t\t\t\t  $%.2lf\n", finalInstall1);
    printf("Discount (Percent)\t\t%d%c\t\t\t  $%.2lf\n", inputCustomerDiscount2, percent1, finalDiscountAmount1);
    printf("\t\t\t\t\t\t   ---------------\n");
    printf("SUBTOTAL\t\t\t\t\t\t  $%.2lf\n", subTotal1);
    printf("Tax\t\t\t\t\t\t\t  $%.2lf\n", InitialTAX1);
    printf("TOTAL\t\t\t\t\t\t\t  $%.2lf\n", Total1);
    return;
}

