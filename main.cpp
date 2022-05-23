#include <iostream>
#include <cmath>
#include <set>

constexpr double pi = 3.14159265;

double around(double x, unsigned int n)
{
	return round(x * pow(10., n)) / pow(10., n);
}

std::set<double> depcubic(double p, double q = 0) 
{
	double Q = pow(q / 2., 2.) + pow(p / 3., 3.);
	double D = -Q;
	if (D < 0)
		return { cbrt(-q / 2. + sqrt(Q)) + cbrt(-q / 2. - sqrt(Q)) };
	if (D == 0.)
		return { 2. * cbrt(-q / 2), cbrt(q / 2) };
	double a = q / 2.;
	double r = sqrt(pow(q / 2., 2.) - Q);
	double phi = acos(a / r);
	double cr = -2. * cbrt(r);
	return {
		cr * cos(phi / 3. + 2. * pi / 3.),
		cr * cos(phi / 3. + 4. * pi / 3.),
		cr * cos(phi / 3.)
	};
}
std::set<double> cubic(double a, double b = 0, double c = 0, double d = 0) 
{
	b /= a;
	c /= a;
	d /= a;
	double p = -b * b / 3 + c;
	double q = 2 * pow(b / 3, 3) - b * c / 3 + d;
	std::set<double> x;
	for (auto y : depcubic(p, q))
		x.insert(y - b / 3);
	return x;
}

int main()
{
	double a = 0, b = 0, c = 0, d = 0;
	int dec = 2;
	for (;;)
	{
		std::cout << "return a: ";
		std::cin >> a;
		std::cout << "return b: ";
		std::cin >> b;
		std::cout << "return c: ";
		std::cin >> c;
		std::cout << "return d: ";
		std::cin >> d;
		std::cout << "return decimals: ";
		std::cin >> dec;
		for (auto &x : cubic(a, b, c, d))
			std::cout << around(x, dec) << "\t";
		std::cout << "\n";
	}
	return 0;
}
