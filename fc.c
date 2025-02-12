#include <stdio.h>

/* print Fahrenheit-Celcius table
 * for fahr = 0, 20, ..., 300 */
int ftoc(int f);

int main() {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;    /* lower limit of temperature scale */
    upper = 300;  /* upper limit */
    step = 20;    /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = ftoc(fahr);
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}

int ftoc(int f) {
    return 5 * (f-32) / 9;
}
