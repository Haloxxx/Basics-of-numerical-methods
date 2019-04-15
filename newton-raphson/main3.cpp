#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double funkcja1 (double x)
{
    return pow(x,3)-169;
}

double funkcja2 (double x)
{
    return 3*pow(x,2);
}

int main()
{
    double x1 = 0.81,x2 = 0.81;
    double tolerance = pow(10,-9);
    int counter =0;

    x2 = x1 - funkcja1(x1)/funkcja2(x1);

    while((abs(x2-x1)/x2)>=tolerance)
    {
      x1 = x2;
      x2 = x1 - funkcja1(x1)/funkcja2(x1);
      ++counter;
    }

    cout<<setprecision(9)<<"root = "<<x2<<" counter = "<<counter;



    return 0;
}
