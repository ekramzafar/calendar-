#include <stdio.h>

char *getMonthName(int month);
int getDaysInMonth(int month,int year);
int isLeapYear(int year);
int getDayNumber(int day, int month, int year) ;
int main() {
    int year, month, day, daysInMonth;

    printf("Enter a year: ");
    scanf("%d", &year);

    printf("\n\n"); 
    for (month = 1; month <= 12; month++) {
        printf("        %s %d\n", getMonthName(month), year);
        printf("-----------------------------\n");
        printf("  S  M  T  W  Th  F Sa\n");

	
        day = getDayNumber(1, month, year);

        for (int i = 1; i < day; i++) {
            printf("   ");
		}


        daysInMonth = getDaysInMonth(month, year);
        for (int i = 1; i <= daysInMonth; i++) {
            printf("%3d", i);
            if ((i + day - 1) % 7 == 0) {
                printf("\n");
            }
        }

        printf("\n\n");
    }

    return 0;
}

char *getMonthName(int month) {
    static const char *monthNames[] = {"January", "February", "March", "April", "May", "June",
                                       "July", "August", "September", "October", "November", "December"};
    return monthNames[month - 1];
}

int getDaysInMonth(int month, int year) {
    static int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    } else {
        return daysPerMonth[month -1];
    }
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int getDayNumber(int day, int month, int year) {
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}
