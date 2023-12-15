/*
    Roilene Vhinz Fajardo
    11/23/23
    BSCS 1A
*/

#include <stdio.h>

// Functions
void gradeInput(int *Fgrade, int *Sgrade, int *Tgrade);    // Function to input grades
int calcGrade(int frstScore, int sndScore, int thrdScore); // Function to Calculate Grades
void printGrade(int fstGrade, int sndGrade, int thrdGrade, int avr);                           // Function to Print Grades

int main()
{
    // Variables
    int score1, score2, score3;
    int average;

    // Function Calls
    gradeInput(&score1, &score2, &score3);
    average = calcGrade(score1, score2, score3);
    printGrade(score1, score2 , score3, average);

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

void printGrade(int fstGrade, int sndGrade, int thrdGrade, int avr)
{
    char averageinLetter;
    int avr2grades = (sndGrade + thrdGrade) / 2;
    
    if (avr >= 90)
        averageinLetter = 'A';
    else if (avr >= 70 && avr < 90) 
    {
        if (thrdGrade > 90) 
            averageinLetter = 'A';
        else 
            averageinLetter = 'B';
    }
    else if (avr >= 50 && avr < 70)
    {
      if (avr2grades > 70) 
            averageinLetter = 'C';
      else 
            averageinLetter = 'D';
    }
    else
        averageinLetter = 'F';
    printf("\nAverage is: %c\n", averageinLetter);
}
