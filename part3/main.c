#include <curses.h>
#include <stdio.h>
#include <math.h> // sqrt
#include <stdlib.h> // Я отсюда юзаю exit()

void error(char* errorMsg) {
	printf("\n %s \n ", errorMsg);
	exit(0);
}

void printMyFunc(float a, float b, float c) {
    float p = b - (pow(a, 2) / 3);
    float q = ((2 * pow(a, 3)) / 27 ) - ((a * b) / 3) + c;
    float d = pow(p, 3) / 27 + pow(q, 2) / 4;

    if (d > 0) {
        float u = cbrt(sqrt(d) - q / 2);
        float v = -(p / ( 3 * u));

        float y1 = u + v;

        float y23_re = -(u + v) / 2;
        float y23_im = (sqrt(3) * (u - v)) / 2;

        printf("y1 = %f \n y2 = %f + i%f \n y3 = %f - i%f\n", y1, y23_re, y23_im, y23_re, y23_im);
    }

    if (d == 0) {
        float y1 = (3 * q) / p;
        float y2 = - (3 * q) / (2 * p);

        printf("y1 = %f \n y2 = y3 = %f \n", y1, y2);
    }

    if (d < 0) {
        float r = sqrt((-pow(p, 3) / 27));
        float fi = acos(-(q / (2 * r)));

        float y1 = 2 * cbrt(r) * cos(fi / 3);
        float y2 = 2 * cbrt(r) * cos((fi + (2 * M_PI)) / 3);
        float y3 = 2 * cbrt(r) * cos((fi + (4 * M_PI)) / 3);

        printf("y1 = %f \n y2 = %f \n y3 = %f \n", y1, y2, y3);
    }
}

int main(void) {
    float a = 2;
    float b = 3;
    float c = 4;

    printMyFunc(a, b, c);
}
