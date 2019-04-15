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

double dl(double* xj, int j)
{
    double result = 0;

    for(int i =0; i<4; ++i)
    {
        if (i!=j)
            result += 1/(xj[j]-xj[i]);
    }

    return result;
}

double h(double x, double* xj, int j)
{
    double result = 0;

    result = (1-2*(x-xj[j])*dl(xj, j))*pow(l(x,xj,j),2);

    return result;
}

double h_(double x, double* xj, int j)
{
    double result = 0;

    result = (x-xj[j])*pow(l(x,xj,j),2);

    return result;
}

double f(double x)
{
    return exp(x);
}

double df(double x)
{
    return exp(x);
}

int main()
{


    double xj[] = {-1.0,0.5,1.5,2.0};

    for(double x = -5; x<=5; x+=0.1)
    {
        double p = 0;

       for(int j = 0; j<4; ++j)
        {
            p+=h(x, xj, j)*f(xj[j]);
        }
        for(int j = 0; j<4; ++j)
        {
            p+=h_(x, xj, j)*df(xj[j]);
        }
        cout<<"x = "<<x<<" p(x) = "<<p<<'\n';
    }


    return 0;
}
