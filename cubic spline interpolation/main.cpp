#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

const int h = 1;


double p(double x, double xj, const vector<double>& pj, int j, const vector<double>& pj_dprim)
{
    double p0, p1, p2, p3;

    p0 = pj[j];
    p1 = (pj[j+1]-pj[j])/h - h*pj_dprim[j+1]/6.0-h*pj_dprim[j]/3.0;
    p2 = pj_dprim[j]/2.0;
    p3 = (pj_dprim[j+1]-pj_dprim[j])/(6.0*h);


    //cout<<"x = "<<x<<" xj = "<<xj<<" j = "<<j<<'\n';

    if(x==-4.9)
    {
        //cout<<"pj = "<<pj[j]<<"pj+1 = "<<pj[j+1]<<'\n';
    }

    return p0 + p1*(x-xj) + p2*pow(x-xj,2) + p3*pow(x-xj,3);
    //return p0 + p1*(x-xj) + p2*(x-xj)*(x-xj) + p3*(x-xj)*(x-xj)*(x-xj);
}


double f_x(double x)
{
    return 1/(1+pow(x,2));
}

int main()
{
//cout<<f_x(-5.0)<<'\n';

vector<double> xj;

for(int i =0; i<11; ++i)
    xj.push_back(-5.0+i*1.0);

//for(int i =0; i<11; ++i)
    //cout<<xj[i]<<'\n';


int counter = 0;
    for(double x = -5.0; x<=5.0; x+=1.0) ++counter;


int m = counter, n = counter;


vector<vector<double> > matrix;
vector<double> row;

for(int i = 0; i<counter; ++i)
{
    row.clear();
    for(int j =0; j<counter; ++j)
    {
        row.push_back(0);
    }

    matrix.push_back(row);
}

matrix[0][0]=1;
matrix[counter-1][counter-1]=1;

matrix[1][1] = 4*h;
matrix[1][2] = h;
matrix[counter-2][counter-2]=4*h;
matrix[counter-2][counter-3]=h;

//matrix[0][1]=0;
//matrix[counter-2][counter-1]=0;

for(int i = 2; i<counter-2; ++i)
{
    matrix[i][i-1]=h;
    matrix[i][i]=4*h;
    matrix[i][i+1]=h;
}

/*cout<<"a =\n";
for(int i=0; i<counter-1; ++i)
    cout<<matrix[i][i+1]<<'\n';

cout<<"b =\n";
for(int i=0; i<counter; ++i)
    cout<<matrix[i][i]<<'\n';

cout<<"c =\n";
for(int i=0; i<counter-1; ++i)
    cout<<matrix[i+1][i]<<'\n';
*/

vector<double> iksy;

    for (int i =0; i <counter; ++i)
        iksy.push_back(1);


vector<double> wyrazy;

 wyrazy.push_back(0);

 for(int i = 1; i<counter-1; ++i)
 {
     double wyraz;

     wyraz = 6*(f_x(xj[i+1])-2*f_x(xj[i])+f_x(xj[i-1]))/h;
     //cout<<"p+3 = "<<f_x(xj[i+1])<<" p+2 = "<<f_x(xj[i])<<" p+1 = "<<f_x(xj[i-1])<<'\n';

     wyrazy.push_back(wyraz);

     //if (i=counter-2) cout<<"i = "<<i<<'\n';
 }

wyrazy.push_back(0);

//for(int i = 0; i<counter; ++i)
//    cout<<"r = "<<wyrazy[i]<<'\n';


//cout<<"wyrazy.size = "<<wyrazy.size()<<'\n';
/*
for(int i =0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j) cout<<matrix[i][j]<<" ";
        cout<<setw(10)<<wyrazy[i]<<" ";
        cout<<iksy[i];
        cout<<'\n';
    }
*/

matrix[0][0]=matrix[0][0];

for(int i =1; i< counter; ++i)
{
    // cout<<"krok\n";
    matrix[i][i]=matrix[i][i]-(matrix[i][i-1]/matrix[i-1][i-1])*matrix[i-1][i];
}

for(int i =1; i< counter; ++i)
{
    //cout<<"r = "<<wyrazy[i]<<'\n';
    wyrazy[i] = wyrazy[i] - (matrix[i][i-1]/matrix[i-1][i-1])*wyrazy[i-1];
}

/*
for(int i =0; i<iksy.size(); ++i)
    cout<<i<<" ";
*/
for(int i =1; i< counter; ++i)
{
    //cout<<"a = "<<matrix[i][i-1]<<'\n';
}
//cout<<"\n\n";

/*for(int i =0; i< counter; ++i)
{
    cout<<"Rho = "<<wyrazy[i]<<'\n';
    cout<<"Beta = "<<matrix[i][i]<<"\n\n";
}*/


iksy[counter-1] = wyrazy[counter-1]/matrix[counter-1][counter-1];
for (int i = counter-2; i>=0 ; --i)
{
    iksy[i]=(wyrazy[i]-matrix[i][i+1]*iksy[i+1])/matrix[i][i];
}


/*for(int i =0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j) cout<<matrix[i][j]<<" ";
        cout<<setw(10)<<wyrazy[i]<<" ";
        cout<<iksy[i];
        cout<<'\n';
    }
*/


vector<double> pj;
int j = 0;
for(double x = -5.0; x<=5.0; x+=1.0)
{
    pj.push_back(f_x(x));
    //cout<<"pj = "<<pj[j]<<'\n';
    ++j;
}

j = 0;


for(int p = 0; p<11; ++p)
    cout<<"j = "<<p+1<<" pj'' = "<<iksy[p]<<'\n';

int xR = xj[1];

for(double x = -5.0; x<=5.0; x+=0.1)
{
    double result;

    if(x>xR)
    {
        j++;
        xR=xj[j+1];
    }
    //cout<<"x = "<<x<<" xj[j] = "<<xj[j]<<" j = "<<j<<'\n';
    result = p(x,xj[j],pj,j,iksy);

    cout<<"x = "<<x<<" j = "<<j+1<<" p_dprim = "<<f_x(j)<<" "<<"p(x) = "<<result<<'\n';
    //cout<<'\n';
    //double p_c=pj[j]+((pj[j+1]-pj[j])/h-(h*iksy[j+1])/6.0-(h*iksy[j])/3.0)*(x-xj[j]);
    //p_c=p_c+(iksy[j]/2.0)*(x-xj[j])*(x-xj[j])+((iksy[j+1]-iksy[j])/(6.0*h))*(x-xj[j])*(x-xj[j])*(x-xj[j]);
    //cout<<p_c<<'\n';
}






    return 0;
}
