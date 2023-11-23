/*
    Roilene Vhinz Fajardo
    11/23/23
    BSCS 1A
*/

#include <stdio.h>

// Functions
void gradeInput(int *Fgrade, int *Sgrade, int *Tgrade);    // Function to input grades
int calcGrade(int frstScore, int sndScore, int thrdScore); // Function to Calculate Grades
void printGrade(int finalGrade);                           // Function to Print Grades

int main()
{
    // Variables
    int score1, score2, score3;
    int average;

    // Function Calls
    gradeInput(&score1, &score2, &score3);
    average = calcGrade(score1, score2, score3);
    printGrade(average);

    return 0;
}

void gradeInput(int *Fgrade, int *Sgrade, int *Tgrade)
{
    printf("Enter First Grade: \n");
    scanf("%d", Fgrade);
    printf("Enter Second Grade: \n");
    scanf("%d", Sgrade);
    printf("Enter Third Grade: \n");
    scanf("%d", Tgrade);

    return;
}

int calcGrade(int frstScore, int sndScore, int thrdScore)
{
    int average;
    average = (frstScore + sndScore + thrdScore) / 3;
    return average;
}

void printGrade(int finalGrade)
{
    char averageinLetter;

    if (finalGrade >= 90)
    {
        averageinLetter = 'A';
    }
    else if (finalGrade >= 70)
    {
        averageinLetter = 'B';
    }
    else if (finalGrade >= 50)
    {
        averageinLetter = 'C';
    }
    else
    {
        averageinLetter = 'F';
    }

    printf("\nAverage is: %c\n", averageinLetter);
}
