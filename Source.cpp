#include <stdio.h>
#include <math.h>
int fact(int n)
{
	if (n<0)
	{
		return 0;
	}
	if (n==0)
	{
		return n = 1;
	}
	return n * fact(n - 1);
}
double calc(const double m, double x, int n)
{
	double exp = 0;
	double res = m;
	for (int i = 1; i < n; i++)
	{
		res *= (m - i);
	}
	res *= (m - n + 1);
	exp = pow(-1, n) * res * pow(x, n) / fact(n);
	exp += 1;
	
	return exp;
}
int main()
{
	double a, b, exp, x, m, h, d;
	int n;
	printf("Enter an interval: ");
	scanf_s("%lf %lf", &a, &b);
	printf("Enter n, x, m, h, d:");
	scanf_s("%d %lf %lf %lf %lf", &n, &x, &m, &h, &d);
	printf("interval = (%.2lf %.2lf), x = %.2lf, m = %.2lf, h = %.2lf, d = %.3lf \n", a, b, x, m, h, d);
	if (x < 0 && x>0.5)
	{
		return 0;

	}
	int i = 0;
	for (x = a; x <= b; x += h)
	{
		double exp_prev = 0;
		exp_prev = calc(m, x, n - 1);
		exp = calc(m, x, n);
		n++;
		printf("%d : x = %.3lf : exp = %.3lf\n ", i, x, exp);
		i++;

		if (fabs(exp - exp_prev) < d) {
			break;
		}
	}
}









