#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double xp, xk, dx, eps;

    cout << "xp = ";
    cin >> xp;

    cout << "xk = ";
    cin >> xk;

    cout << "dx = ";
    cin >> dx;

    cout << "eps = ";
    cin >> eps;

    // Перевірка коректності введених даних
    if (dx <= 0 || eps <= 0 || xp > xk)
    {
        cout << "Error: incorrect input data!" << endl;
        return 1;
    }

    // Ряд Тейлора для atan(x) збігається при |x| <= 1
    if (xp < -1 || xk > 1)
    {
        cout << "Error: x must belong to [-1; 1]!" << endl;
        return 1;
    }

    cout << fixed << setprecision(6);

    cout << "---------------------------------------------------------------" << endl;
    cout << "|"
        << setw(10) << "x" << " |"
        << setw(15) << "atan(x)" << " |"
        << setw(15) << "S" << " |"
        << setw(12) << "n" << " |" << endl;

    cout << "---------------------------------------------------------------" << endl;

    for (double x = xp; x <= xk + dx / 2.0; x += dx)
    {
        // Перший доданок:
        // a0 = x
        double a = x;

        // Сума ряду
        double S = 0.0;

        // Номер доданка
        int n = 0;

        // Кількість обчислених доданків
        int count = 0;

        do
        {
            S += a;
            count++;

            // Переходимо до наступного доданка:
            // a(n+1) = a(n) * (-x^2) * (2n+1)/(2n+3)
            a *= -x * x * (2.0 * n + 1.0) / (2.0 * n + 3.0);

            n++;

        } while (fabs(a) >= eps);

        cout << "|"
            << setw(10) << x << " |"
            << setw(15) << atan(x) << " |"
            << setw(15) << S << " |"
            << setw(12) << count << " |"
            << endl;
    }

    cout << "---------------------------------------------------------------" << endl;

    return 0;
}