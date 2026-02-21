#include <stdio.h>

enum Day {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
};

enum Month {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER,
};

struct Date {
    enum Day day_name;
    int day;
    enum Month month;
    int year;
};

void debug_date(struct Date date) {
    switch (date.day_name) {
        case MONDAY: printf("Mon "); break;
        case TUESDAY: printf("Tue "); break;
        case WEDNESDAY: printf("Wed "); break;
        case THURSDAY: printf("Thu "); break;
        case FRIDAY: printf("Fri "); break;
        case SATURDAY: printf("Sat "); break;
        case SUNDAY: printf("Sun "); break;
    }
    printf("%d ", date.day);
    switch (date.month) {
        case JANUARY: printf("Jan "); break;
        case FEBRUARY: printf("Feb "); break;
        case MARCH: printf("Mar "); break;
        case APRIL: printf("Apr "); break;
        case MAY: printf("May "); break;
        case JUNE: printf("Jun "); break;
        case JULY: printf("Jul "); break;
        case AUGUST: printf("Aug "); break;
        case SEPTEMBER: printf("Sep "); break;
        case OCTOBER: printf("Oct "); break;
        case NOVEMBER: printf("Nov "); break;
        case DECEMBER: printf("Dec "); break;
    }
    printf("%d\n", date.year);
}

int month_length(enum Month month, int year) {
    switch (month) {
        case JANUARY: return 31;
        case FEBRUARY: if (year % 4 == 0 && (year % 1000 != 0 || year % 400 == 0)) return 29; else return 28;
        case MARCH: return 31;
        case APRIL: return 30;
        case MAY: return 31;
        case JUNE: return 30;
        case JULY: return 31;
        case AUGUST: return 31;
        case SEPTEMBER: return 30;
        case OCTOBER: return 31;
        case NOVEMBER: return 30;
        case DECEMBER: return 31;
    }
}

void increment_date(struct Date *date) {
    date->day_name += 1;
    if (date->day_name > SUNDAY) {
        date->day_name = MONDAY;
    }

    date->day += 1;
    if (date->day <= month_length(date->month, date->year)) return;
    date->day = 1;
    date->month += 1;
    if (date->month <= DECEMBER) return;
    date->month = JANUARY;
    date->year += 1;
}

int sundays_on_the_first(int day, enum Month month, int year) {
    int count = 0;
    struct Date date = {MONDAY, 1, JANUARY, 1900};

    for (;;) {
        if (date.day_name == SUNDAY && date.day == 1) count += 1;

        if (
            date.day == day &&
            date.month == month &&
            date.year == year
        ) {
            break;
        }

        increment_date(&date);
    }

    return count;
}

int main(void) {
    int start = sundays_on_the_first(31, DECEMBER, 1900);
    int end = sundays_on_the_first(31, DECEMBER, 2000);

    printf("%d\n", end - start);

    return 0;
}
