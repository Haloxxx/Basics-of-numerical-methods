#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;

/*
 dla 1. przyk≥adu
 root = 0,52553241
 1 bisekcja, 3 newtony
 
 dla 2. przyk≥adu
 root = 2,73205081
 2 bisekcje, 5 newtonow
 */

double func(double x)
{
    return pow(x,2)-2*x-2;
}

double deriv(double x)
{
    return 2*x-2;
}

int main()
{
    double x0 = 0.4, xl = 0, xr =3;
    double tolerance = pow(10,-8);
    double xp = 0;
    double lt = 0, rt = 0;
    bool flag = 0;
    double xi, x_iplus1, xm;
    
    int counter_b = 0, counter_nr = 0;
    
    
    x_iplus1 = x0;
    
    do
    {
        xi = x_iplus1;
        x0=xi;
        
        lt = (x0-xl)*deriv(x0)-func(x0);
        rt = (x0-xr)*deriv(x0)-func(x0);
        
        
        if (deriv(x0)>0)
            if (lt>=0 && rt<=0) flag = 1;
        
        if (deriv(x0)<0)
            if (lt<=0 && rt>=0) flag = 1;
        
        if(flag == 1)
        {
            x_iplus1 = xi - func(xi)/deriv(xi);
            
            ++counter_nr;
        }
        else
        {
            xm = (xr+xl)/2;
            
            if (func(xm)*func(xr)<0) xl = xm;
            else if(func(xm)*func(xl)<0) xr = xm;
            
            x_iplus1=xm;
            ++counter_b;
        }
        
        flag = 0;
        
    } while(abs((x_iplus1-xi)/x_iplus1)>=tolerance);
    
    cout<<setprecision(8)<<(x_iplus1)<<'\n';
    cout<<counter_b<<" "<<counter_nr<<'\n';
    
    return 0;
}
