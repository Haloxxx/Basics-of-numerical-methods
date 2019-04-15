#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> tab;

    for (int i =0; i<1000; ++i)
    {
        if (i!=456)
            tab.push_back(0+2*i);
    }

    int xl = 0;
    int xr = 1000;
    int xm = 0;
    int test;

    xm=(xl+xr)/2;

    while(true)
    {
        if (tab[xm]==xm*2)
            xl=xm;
        else xr=xm;

        xm=(xl+xr)/2;
        
        if ((tab[xm-1]==(xm-1)*2)&&(tab[xm+1]!=(xm+1)*2))
            break;
        
    }
    cout<<xm<<'\n';






}
