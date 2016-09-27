#include <curses.h>
#include <stdio.h>
#include <math.h> // sqrt
#include <stdlib.h> // Я отсюда юзаю exit()

void error(char* errorMsg) {
	printf("\n %s \n ", errorMsg);
	exit(0);
}

bool isLeapYear(int year) {
    bool result = false;

    if (year % 100 != 0) {
        if (year % 4 == 0) {
            result = true;
        }
    } else {
        if (year % 400 == 0) {
            result = true;
        }
    }

    return result;
}

void printDay(year, month, date) {
    int day;

    int n;
    if (month > 2) {
        n = 0;
    } else {
        if (isLeapYear(year)) {
            n = 1;
        } else {
            n = 2;
        }
    }

    day = ((int)(fabs(365.25f * year) + fabs(30.56f * month) + date + n)) % 7;

    //printf("%i\n", day);

    switch(day) {
        case 0:
            printf("Mon \n");
            break;
        case 1:
            printf("Tue \n");
            break;
        case 2:
            printf("Wed \n");
            break;
        case 3:
            printf("Thu \n");
            break;
        case 4:
            printf("Fri \n");
            break;
        case 5:
            printf("Sat \n");
            break;
        case 6:
            printf("Sun \n");
            break;
    };
}

int main(void) {
    int year = 2016;
    int month = 9;
    int date = 25;

    printDay(year, month, date);
}
