#include <stdio.h>

struct Date {
    int day, month, year;
};

void CalculateAge(struct Date CurrentDate, struct Date Birthday) {
    int age_day, age_month, age_year;

    if (CurrentDate.day >= Birthday.day) {
        age_day = CurrentDate.day - Birthday.day;
    } else {
        CurrentDate.month--;
        CurrentDate.day += 30;
        age_day = CurrentDate.day - Birthday.day;
    }

    if (CurrentDate.month >= Birthday.month) {
        age_month = CurrentDate.month - Birthday.month;
    } else {
        CurrentDate.year--;
        CurrentDate.month += 12;
        age_month = CurrentDate.month - Birthday.month;
    }

    age_year = CurrentDate.year - Birthday.year;

    printf("Age: %d year, %d month, %d day\n", age_year, age_month, age_day);
}

int main() {
    struct Date CurrentDate;
    struct Date Birthday;

    printf("Enter your date of birth(d/m/y): ");
    scanf("%d/%d/%d", &Birthday.day, &Birthday.month, &Birthday.year);

    printf("Enter the current date(d/m/y): ");
    scanf("%d/%d/%d", &CurrentDate.day, &CurrentDate.month, &CurrentDate.year);

    CalculateAge(CurrentDate, Birthday);

    return 0;
}
