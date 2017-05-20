#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3

 int Mcp(int cost[R][C],int m,int  n )
 {
     if(m < 0 || n < 0) // if m and n are negative then no path exist so cost is infinity
        return INT_MAX;

      else if(m == 0 && n == 0) //  if starting point is cutoff then cost is only to go starting point
            return cost[m][n];
       else return cost[m][n]+ min(Mcp(cost, m -1, n-1),min(Mcp(cost,m-1,n),Mcp(cost,m,n-1))); // else we have three option to go diagonally , horizontally and vertically
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
