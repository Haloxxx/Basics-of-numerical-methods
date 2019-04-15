#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double f(double x)

{
    double result;
    result = cos(x) - x;
    return result;
}



int main()
{
    double xl = 0, xr = 1;
    double tolerance = pow(10,-8);
    double present, past;
    double err;

    int i = 0;

    do
    {
        present = (xl*f(xr)-xr*f(xl))/(f(xr)-f(xl));

        xl = present;

        err = abs((present-past)/present);

        past = present;
        ++i;

    } while(err>tolerance);

     cout<<"wynik1 = "<<setprecision(8)<<present<<'\n';
     cout<<"w "<<i<<" krokach\n";


     double x0 = 0, x1 = 0.2;

     int j = 0;

     double x = x1;
     double x_minus1 = x0;
     double x_plus1;


     do
    {

        x_plus1 = (x_minus1*f(x)-x*f(x_minus1))/(f(x)-f(x_minus1));

        err = abs((x_plus1-x)/x);

        x_minus1 = x;
        x = x_plus1;

        ++j;
/*
        cout<<"iteracja\n";
        cout<<"x = "<<x<<'\n';
*/
    } while(err>tolerance);


     cout<<"wynik2 = "<<setprecision(8)<<x_plus1<<'\n';
     cout<<"w "<<j<<" krokach\n";

    return 0;
}
