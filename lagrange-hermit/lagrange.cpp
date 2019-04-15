#include <iostream>
#include <math.h>
#include <vector>

using namespace std;



double l(double x, double* xj, int j)
{
    double result = 1;
    if (j!=0)
        result = (x-xj[0])/(xj[j]-xj[0]);


    for(int i =1; i<4; ++i)
    {
        if (i!=j)
            result *= (x-xj[i])/(xj[j]-xj[i]);
    }

    return result;
}

double f(double x)
{
    return exp(x);
}

int main()
{


    double xj[] = {-1.0,0.5,1.5,2.0};

    double x = -5;

    for(double x = -5; x<=5; x+=0.1)
    {
        double p = 0;

       for(int j = 0; j<4; ++j)
        {
        p+=l(x, xj, j)*f(xj[j]);
        }

        cout<<"x = "<<x<<" p(x) = "<<p<<'\n';
    }


    return 0;
}
