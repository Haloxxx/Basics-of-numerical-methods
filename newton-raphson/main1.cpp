#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double funkcja1(double x)
{
    return cos(x)-x;
}

double funkcja2(double x)
{
    return -sin(x)-1;
}



int main()
{

    double x0 = 0;
    double x1,x2 = 0;
    double tolerance = pow(10,-8);

    x2 = x1 - funkcja1(x1)/(funkcja1(x1)/funkcja2(x1));


    while((abs(x2-x1)/x2)>=tolerance)
    {
      x1 = x2;
      x2 = x1 - funkcja1(x1)/funkcja2(x1);
    }

    cout<<setprecision(8)<<"root = "<<x2;




    return 0;
}
