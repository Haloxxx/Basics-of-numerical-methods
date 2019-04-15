#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int m = 5, n = 5;

    vector<vector<double> > matrix;
    vector<double> row;
    row.push_back(2);
    row.push_back(-1);
    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    matrix.push_back(row);

    row.clear();
    row.push_back(-1);
    row.push_back(2);
    row.push_back(-1);
    row.push_back(0);
    row.push_back(0);
    matrix.push_back(row);

    row.clear();
    row.push_back(0);
    row.push_back(-1);
    row.push_back(2);
    row.push_back(-1);
    row.push_back(0);
    matrix.push_back(row);

    row.clear();
    row.push_back(0);
    row.push_back(0);
    row.push_back(-1);
    row.push_back(2);
    row.push_back(-1);
    matrix.push_back(row);

    row.clear();
    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    row.push_back(-1);
    row.push_back(2);
    matrix.push_back(row);

////////////////////////////////////////////////////////////
//////////////////////////////LICZENIE//////////////////////////////
////////////////////////////////////////////////////////////

    vector<double> iksy;

    for (int i =0; i <5; ++i)
        iksy.push_back(1);

    vector<double> wyrazy;

    wyrazy.push_back(0);
    wyrazy.push_back(1);
    wyrazy.push_back(2);
    wyrazy.push_back(3);
    wyrazy.push_back(4);

    /*for(int i =0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
            cout<<matrix[i][j]<<" ";

        cout<<'\n';
    }
    */



//cout<<"bj = "<<matrix[1][1]<<"\n\n\n\n\n";




    matrix[0][0]=matrix[0][0];

    for(int i =1; i< 5; ++i)
     {
        // cout<<"krok\n";
        matrix[i][i]=matrix[i][i]-(matrix[i][i-1]/matrix[i-1][i-1])*matrix[i-1][i];
     }

    for(int i =1; i< 5; ++i)
    {
       wyrazy[i] = wyrazy[i] - (matrix[i][i-1]/matrix[i-1][i-1])*wyrazy[i-1];
    }

    iksy[4] = wyrazy[4]/matrix[4][4];
    for (int i = 3; i>=0 ; --i)
    {
        iksy[i]=(wyrazy[i]-matrix[i][i+1]*iksy[i+1])/matrix[i][i];
    }









    for(int i =0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
            cout<<setw(8)<<matrix[i][j]<<" ";

        cout<<iksy[i]<<" "<<wyrazy[i]<<'\n';
    }



    return 0;
}
