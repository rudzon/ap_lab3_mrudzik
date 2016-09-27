#include <curses.h>
#include <stdio.h>
#include <math.h> // sqrt
#include <stdlib.h> // Я отсюда юзаю exit()

void error(char* errorMsg) {
	printf("\n %s \n ", errorMsg);
	exit(0);
}

float toPow(float val, int power) {
    for (int i = power; i > 1; i--) {
        val *= val;
    }

    return val;
}

float myFunc(float x, float k, float e) {
    float b = 1;
    float y = 1;

    while (fabsf(b) >= e) {
        b = (1 / k) * ((x / toPow(y, k - 1) - y));
        y = y + b;
    }

    return y;
}

int main(void) {
    float x = 16;
    float k = 2;
    float e = 0.001;
    float y;

    printf("\n x = %f \n k = %f \n e = %f", x, k , e);

    y = myFunc(x, k, e);

    printf("\n y = %f\n", y);
}
