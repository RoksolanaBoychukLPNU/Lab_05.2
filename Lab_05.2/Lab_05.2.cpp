// Лабораторна робота № 5.2
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double S(const double x, const double eps, int& n);  // сума ряду, n - к-сть доданків
double A(const double x, const int n, double a);      // наступний доданок

int main()
{
    double xp, xk, x, dx, eps, s;
    int n = 0;

    cout << "xp = ";  cin >> xp;      // початок інтервалу
    cout << "xk = ";  cin >> xk;      // кінець інтервалу
    cout << "dx = ";  cin >> dx;      // крок
    cout << "eps = "; cin >> eps;     // точність

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << "   |"
        << setw(10) << "exp(-x)" << "   |"
        << setw(10) << "S" << "   |"
        << setw(5) << "n" << "   |"
        << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)          
    {
        s = S(x, eps, n);

        cout << "|" << setw(7) << setprecision(2) << x << "   |"
            << setw(10) << setprecision(5) << exp(-x) << "   |"
            << setw(10) << setprecision(5) << s << "   |"
            << setw(5) << n << "   |"
            << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}

double S(const double x, const double eps, int& n)
{
    n = 0;
    double a = 1;          // перший доданок a0 = 1
    double s = a;
    do {
        n++;
        a = A(x, n, a);    // a(n) = a(n-1) * R
        s += a;
    } while (abs(a) >= eps);
    return s;
}

double A(const double x, const int n, double a)
{
    double R = -x / n;     // коефіцієнт рекурентності
    a *= R;
    return a;
}

