#include <stdio.h>
#include <time.h>

struct DateOfBirth
{
    int day;
    int month;
    int year;
};

struct Employee
{
    struct DateOfBirth birthDate;
    char name[30];
    int salary;
};

int FindAge(struct Employee e){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentYear = tm.tm_year + 1900;
    return currentYear - e.birthDate.year;
}


int main(){
    struct Employee employee[3];

    for(int i = 0; i < 3; i++){
        printf("Enter the employee name, date of birth(d/m/y) and salary: ");
        scanf("%s %d/%d/%d %d", &employee[i].name, &employee[i].birthDate.day, &employee[i].birthDate.month, &employee[i].birthDate.year, &employee[i].salary);
    }

    printf("25-40 yr old Employees:\n");

    for(int i = 0; i < 3; i++){
        int age = FindAge(employee[i]);
        if(age <= 40 && age >= 25){
            printf("%s\t%d\t%d\n",employee[i].name, employee[i].salary, age);
        }
    }



    return 0;
}