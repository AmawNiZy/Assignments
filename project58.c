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
    char vehicleName[6];  // Reduced array size

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
    // Vehicle time Enter (Hours)
    printf("Minutes Vehicle Left Lot (0 - 60)? ");
    scanf("%d", &outMinutes);

    // Check if the parking times are valid
    if (inHours < 0 || inHours >= 24 || inMinutes < 0 || inMinutes >= 60 ||
        outHours < 0 || outHours >= 24 || outMinutes < 0 || outMinutes >= 60) 
    {
        printf("Invalid parking times. Please enter valid hours and minutes.\n");
        return 1;  // Exit with an error code
    }

    // Parking Time
    getParkingTime(inHours, inMinutes, outHours, outMinutes, &parkingHours, &parkingMinutes);

    // Adjust parkingMinutes if it's greater than or equal to 60
    if (parkingMinutes >= 60) 
    {
        parkingMinutes %= 60;
        parkingHours += 1;
    }

    // Calculate rounded hours based on the total parking time
    roundedHours = (parkingMinutes >= 30) ? parkingHours + 1 : parkingHours;

    // Process
    // Calculate parking fee based on the given fee structure and type of vehicle.
    switch (vehicleType) 
    {
        case 'c':
            if (parkingHours <= 3) 
            {
                parkingFee = 0.0;
            } 
            else 
            {
                parkingFee = (parkingHours - 3) * 1.50 + parkingMinutes / 60.0 * 1.50;
            }
            strcpy(vehicleName, "Car");
            break;
        case 'b':
            if (parkingHours <= 3) 
            {
                parkingFee = parkingHours * 2.00 + parkingMinutes / 60.0 * 2.00;
            } 
            else 
            {
                parkingFee = 3 * 2.00 + (parkingHours - 3) * 3.70 + parkingMinutes / 60.0 * 3.70;
            }
            strcpy(vehicleName, "Bus");
            break;
        case 't':
            if (parkingHours <= 3) 
            {
                parkingFee = parkingHours * 1.00 + parkingMinutes / 60.0 * 1.00;
            } 
            else 
            {
                parkingFee = 3 * 1.00 + (parkingHours - 3) * 2.30 + parkingMinutes / 60.0 * 2.30;
            }
            strcpy(vehicleName, "Truck");
            break;
        default:
            printf("Invalid vehicle type. Please enter c, b, or t.\n");
            return 1;  // Exit with an error code
    }

    // Output
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
        return getValidVehicleType();  // repeat until input is right
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
