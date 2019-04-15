#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double funkcja1(double x)
{
    return (6435*pow(x,8)-12012*pow(x,6)+6930*pow(x,4)-1260*pow(x,2)+35)/128;
}

double funkcja2(double x)
{
    return (51480*pow(x,7)-72072*pow(x,5)+27720*pow(x,3)-2520*x)/128;
}


int main()
{
    double x1 = 0.81,x2 = 0.81;
    double tolerance = pow(10,-8);
    int counter =0;

    x2 = x1 - funkcja1(x1)/funkcja2(x1);

    while((abs(x2-x1)/x2)>=tolerance)
    {
      x1 = x2;
      x2 = x1 - funkcja1(x1)/funkcja2(x1);
      ++counter;
    }

    cout<<setprecision(8)<<"root = "<<x2<<" counter = "<<counter;



    return 0;
}
