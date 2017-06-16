#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
int a[20][20], reach[20],  n , i, j;

void dfs(int v)
{
   reach[v] = 1;
   for(i =0; i< ; i++)
   {
       if( a[v][i] && !reach[i] )
        printf("\n %d->%d",v,i);
   dfs(i);
   }

}

int main()
{
    scanf("%d",&n);
    for(i = 0 ; i< n ; i++)
    {
        reach[i] = 0;
        for(j = 0 ; j< n ; j++)
            a[i][j] = 0;
    }
            for(i  = 0 ; i < n ; i++)
        for(j= 0 ; j < n ; j++)
        scanf("%d",&a[i][j]);
        int v;
        scanf("%d",&v);
        dfs(0);
        for(i=0;i<n;i++)
 {
  if(reach[i])
   count++;
 }
 if(count==n-1)
  printf("\n Graph is connected");
 else
  printf("\n Graph is not connected");


    return 0;
}
