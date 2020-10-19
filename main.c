#include <stdio.h>
#include <math.h>
#include <assert.h>
void Solver(double a, double b, double c) {
    // check the parameters
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    // solving
    if (a == 0) {
        printf("Oh, it's not a square equation :(\n");
        return;
    }
    else {
        double d = b * b - 4 * a * c; // discriminant
        if (d < 0) {
            printf("There are no roots!\n");
            return;
        }
        else if (d == 0) {
            double x = - b / 4 / a;
            printf("There are two equal roots: x1 = x2 = %lg\n", x);
            return;
        }
        else {
            double x1 = (- b - sqrt(d)) / 4 / a;
            double x2 = (- b + sqrt(d)) / 4 / a;
            printf("There are two roots: x1 = %lg, x2 = %lg\n", x1, x2);
        }
    }
}

int main() {
    printf("Hello, let's solve some square equation!\n");
    printf("An equation should look like 'a * x ^ 2 + b * x + c = 0', where a > 0\n");
    printf("Enter your coefficients: a, b and c\n");

    double a, b, c;
    scanf("%lg %lg %lg", &a, &b, &c);

    printf("Sooo, your equation is: %lg * x ^ 2 + %lg * x + %lg = 0\n", a, b, c);

    Solver(a, b, c);

    return 0;
}



//----------------------------------------------—
//! Solver of square equation ax^2 + bx + c = 0
//!
//! @param [in] a a-coeff
//! @param [in] b b-coeff
//! @param [in] c c-coeff
//! @param [out] x_1 Pointer to the first root
//! @param [out] x_2 Pointer to the second root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots,
//! returns INF_ROOTS
//! In case of complex roots,
//! return COMPLEX_ROOTS
//------------------------------------------------
