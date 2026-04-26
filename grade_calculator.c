#include <stdio.h>

// Function to calculate grade based on percentage
char getGrade(float percentage) {
    if (percentage >= 90) return 'O';       // Outstanding
    else if (percentage >= 80) return 'A';  // Excellent
    else if (percentage >= 70) return 'B';  // Very Good
    else if (percentage >= 60) return 'C';  // Good
    else if (percentage >= 50) return 'D';  // Average
    else return 'F';                        // Fail
}

// Function to get grade description
void getGradeDescription(char grade) {
    switch (grade) {
        case 'O': printf("Outstanding\n");  break;
        case 'A': printf("Excellent\n");    break;
        case 'B': printf("Very Good\n");    break;
        case 'C': printf("Good\n");         break;
        case 'D': printf("Average\n");      break;
        case 'F': printf("Fail\n");         break;
    }
}

int main() {
    int n;
    float marks[10], total = 0, percentage;
    char subjects[10][30];
    char grade;

    printf("========================================\n");
    printf("       STUDENT GRADE CALCULATOR         \n");
    printf("========================================\n\n");

    // Input student name
    char name[50];
    printf("Enter Student Name: ");
    fgets(name, sizeof(name), stdin);

    // Input number of subjects
    printf("Enter Number of Subjects (max 10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Invalid number of subjects!\n");
        return 1;
    }

    float maxMark;
    printf("Enter Maximum Mark per Subject: ");
    scanf("%f", &maxMark);

    printf("\n--- Enter Subject Names and Marks ---\n");
    for (int i = 0; i < n; i++) {
        printf("Subject %d Name: ", i + 1);
        scanf(" %[^\n]", subjects[i]);
        do {
            printf("Marks obtained in %s (out of %.0f): ", subjects[i], maxMark);
            scanf("%f", &marks[i]);
            if (marks[i] < 0 || marks[i] > maxMark)
                printf("  Invalid! Enter marks between 0 and %.0f\n", maxMark);
        } while (marks[i] < 0 || marks[i] > maxMark);
        total += marks[i];
    }

    // Calculate percentage
    percentage = (total / (n * maxMark)) * 100;
    grade = getGrade(percentage);

    // Display Result
    printf("\n========================================\n");
    printf("            RESULT CARD                 \n");
    printf("========================================\n");
    printf("Student Name : %s", name);
    printf("----------------------------------------\n");
    printf("%-25s %10s\n", "Subject", "Marks");
    printf("----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-25s %10.2f\n", subjects[i], marks[i]);
    }
    printf("----------------------------------------\n");
    printf("%-25s %10.2f\n", "Total Marks", total);
    printf("%-25s %9.2f%%\n", "Percentage", percentage);
    printf("%-25s %10c\n", "Grade", grade);
    printf("%-25s ", "Result");
    getGradeDescription(grade);
    printf("========================================\n");

    if (grade != 'F') {
        printf("  Congratulations! You have PASSED.\n");
    } else {
        printf("  You have FAILED. Better luck next time!\n");
    }
    printf("========================================\n");

    return 0;
}
