#include <stdio.h>
#include <string.h>

char getValidVehicleType();
int getParkingTime(int inHours, int inMinutes, int outHours, int outMinutes, int *hours, int *minutes);

int main() {
    char vehicleType;
    int inHours, inMinutes, outHours, outMinutes;
    int parkingHours, parkingMinutes;
    int roundedHours;
    double parkingFee = 0.0;
    char vehicleName[6];  // Array to return String

    // Input vehicle type using the recursive function
    vehicleType = getValidVehicleType();

    // Vehicle time Enter (Hours)
    printf("Hour Vehicle Entered Lot (0 - 24)? ");
    scanf("%d", &inHours);

    // Vehicle time Enter (Minutes)
    printf("Minute Vehicle Entered Lot (0 - 60)? ");
    scanf("%d", &inMinutes);

    // Vehicle time Left (Hours)
    printf("Hour Vehicle Left Lot (0 - 24)? ");
    scanf("%d", &outHours);

    // Vehicle time Left (Minutes)
    printf("Minutes Vehicle Left Lot (0 - 60)? ");
    scanf("%d", &outMinutes);

    // Handle the case where outMinutes is greater than or equal to 60
    if (inMinutes >= 60) 
    {
        inHours += inMinutes / 60;
        inMinutes %= 60;
    }
    // Handle the case where outMinutes is greater than or equal to 60
    if (outMinutes >= 60) 
    {
        outHours += outMinutes / 60;
        outMinutes %= 60;
    }

    // Process
    // Check if the parking times are valid
    if (inHours < 0 || inHours >= 24 || inMinutes < 0 || inMinutes > 60 ||
        outHours < 0 || outHours >= 24 || outMinutes < 0 || outMinutes > 60) 
    {
        printf("Invalid parking times. Please enter valid hours and minutes.\n");
        return 1;  // Exit with an error code
    }

    // Check if the vehicle is getting towed
    if (inHours >= 24 || outHours >= 24) {
        printf("You are getting towed.\n");
        return 1;  // Exit with an error code
    }

    // Output
    // Gets the Parking Time
    getParkingTime(inHours, inMinutes, outHours, outMinutes, &parkingHours, &parkingMinutes);

    // Convert parkingMinutes to hours if it's greater than or equal to 60
    if (parkingMinutes >= 60) {
        parkingHours += parkingMinutes / 60;
        parkingMinutes %= 60;
    }

    /* Calculate rounded hours based on the total parking time.
    If parking minutes are greater than 30, Adds 1 hour to the parking time and resets the parking minutes to 0. */
    roundedHours = (parkingMinutes >= 30) ? parkingHours + 1 : parkingHours;

    // Calculate parking fee based on the given fee structure and type of vehicle.
    switch (vehicleType) {
        case 'c':
            if (roundedHours <= 3) 
                parkingFee = 0.0;
            else 
                parkingFee = (roundedHours - 3) * 1.50 + parkingMinutes / 60.0 * 1.50;
            strcpy(vehicleName, "Car");
            break;
        case 'b':
            if (roundedHours <= 3) 
                parkingFee = roundedHours * 2.00 + parkingMinutes / 60.0 * 2.00;
            else 
                parkingFee = 3 * 2.00 + (roundedHours - 3) * 3.70 + parkingMinutes / 60.0 * 3.70;
            strcpy(vehicleName, "Bus");
            break;
        case 't':
            if (roundedHours <= 3) 
                parkingFee = roundedHours * 1.00 + parkingMinutes / 60.0 * 1.00;
            else 
                parkingFee = 3 * 1.00 + (roundedHours - 3) * 2.30 + parkingMinutes / 60.0 * 2.30;
            strcpy(vehicleName, "Truck");
            break;

        default:
            printf("Invalid vehicle type. Please enter c, b, or t.\n");
            return 1;  // Exit with an error code
    }   

    printf("\n\t\tPARKING LOT CHANGE\t\t\t\n");
    printf("Type of Vehicle: %s\n", vehicleName);
    printf("TIME-IN\t\t\t\t    %02d:%02d\n", inHours, inMinutes);
    printf("TIME-OUT\t\t\t    %02d:%02d\n", outHours, outMinutes);
    printf("\t\t\t\t --------\n");
    printf("PARKING TIME:\t\t\t    %02d:%02d\n", parkingHours, parkingMinutes);
    printf("ROUNDED TOTAL:\t\t\t    %02d:00\n", roundedHours);
    printf("\t\t\t\t --------\n");
    printf("TOTAL CHARGE:\t\t\t    $%.2f\n", parkingFee);

    return 0;
}

char getValidVehicleType() {
    char vehicleType;

    // Prompt for input
    printf("Enter vehicle type (c, b, t): ");
    scanf(" %c", &vehicleType);

    // Validate the input with recursion
    if (vehicleType != 'c' && vehicleType != 'b' && vehicleType != 't') {
        printf("Invalid vehicle type. Please enter c, b, or t.\n");
        return getValidVehicleType();  // Ask for input again
    }

    return vehicleType;
}

int getParkingTime(int inHours, int inMinutes, int outHours, int outMinutes, int *hours, int *minutes) {
    // Convert everything to minutes and calculate the difference
    int inTimeInMinutes;
    int outTimeInMinutes;
    int timeDifferenceInMinutes;

    inTimeInMinutes = inHours * 60 + inMinutes;
    outTimeInMinutes = outHours * 60 + outMinutes;
    timeDifferenceInMinutes = outTimeInMinutes - inTimeInMinutes;

    // Convert back to hours and minutes
    *hours = timeDifferenceInMinutes / 60;
    *minutes = timeDifferenceInMinutes % 60;

    return 0;  // Return success
}
