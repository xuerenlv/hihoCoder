#include <cstdio>
#include <cmath>

double a, b, c, X, Y;
double f(double x)
{
    double y = a * x * x + b * x + c;
    return hypot(x - X, y - Y);
}

int main()
{
    scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &X, &Y);
    double l = -1e5, r = 1e5;
    while (fabs(l - r) > 1e-8)
    {
        double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (f(m1) < f(m2)) r = m2; else l = m1;
    }
    printf("%.3f\n", f(l));
}
