#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3

int Mcp(int cost[R][C],int m,int  n )
 {
     int table[R][C],i , j;
     table[0][0] = cost[0][0]; // starting  cost is
     for(i = 1 ; i<= m; i++ ){
        table[i][0] = table[i-1][0] +cost[i][0];
        }
        for(j = 1 ; j<= n; j++ ){
        table[0][j] = table[0][j-1] +cost[0][j];
        }
        for(i =1; i<= m ; i++){
            for(j=1; j<= n ; j++){
                    table[i][j] = cost[i][j] + min(table[i-1][j-1],min(table[i-1][j],table[i][j-1]));

            }
        }
        return table[m][n];

     }



int main()
{
   int cost[R][C] = { {1,2,3},
   {4,8,2},
   {1,5,3}
};
 cout<<Mcp(cost,2,2)<<endl;
    return 0;
}
