#include <stdio.h>

struct Time
{
    int hours, minutes,seconds;
};

void calculateDifference(struct Time t1, struct Time t2, struct Time* diff){
    if(t1.seconds >= t2.seconds){
        diff->seconds = t1.seconds - t2.seconds;
    }else{
        t1.seconds += 60;
        t1.minutes--;
        diff->seconds = t1.seconds - t2.seconds;
    }

    if(t1.minutes >= t2.minutes){
        diff->minutes = t1.minutes - t2.minutes;
    }else{
        t1.minutes += 60;
        t1.hours--;
        diff->minutes = t1.minutes - t2.minutes;
    }

    diff->hours = t1.hours - t2.hours;
}

int main(){
    struct Time t1, t2, difference;

    printf("Enter the first time (hours minutes seconds):");
    scanf("%d %d %d", &t1.hours, &t1.minutes, &t1.seconds);

    printf("Enter the second time (hours minutes seconds):");
    scanf("%d %d %d", &t2.hours, &t2.minutes, &t2.seconds);

    int totalSec_t1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int totalSec_t2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    if(totalSec_t1 > totalSec_t2)
        calculateDifference(t1, t2, &difference);
    else
        calculateDifference(t2, t1, &difference);


    printf("Time difference is %d hour(s), %d minute(s), and %d second(s).\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}