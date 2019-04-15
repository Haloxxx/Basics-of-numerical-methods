#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>



using namespace std;



double func(double x)
{
    return cos(x) - x;
}

int main()
{
    double xl = 0,xr = 1;
    const double tolerance = pow(10.0,-8.0);
    int counter = 0;

    if (func(xl)*func(xr)<0)
    {
        double xm;
        xm = (xr+xl)/2;

        while(abs((xr-xl)/xm)>tolerance)
        {

            /*cout<<abs((xr-xl)/xm);
            cin>>cok;*/
            //cout<<"test";


            //cout<<xl<<" "<<xr<<'\n';

            if (func(xl)*func(xr)<0)
            {
                if (func(xl)*func(xm)<=0)
                    xr=xm;
                else if (func(xm)*func(xr)<=0)
                    xl=xm;
            }
            ++counter;
            xm = (xr+xl)/2;

            /*if (counter==28)
                break;*/
        }

        cout<<setprecision(8)<<(xm)<<'\n';
        cout<<counter;
    }




    return 0;
}
