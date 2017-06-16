#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
int a[20][20],  q[20],visited[20], r = -1, f =0, n , i, j;

void bfs(int v)
{
   for(i = 0 ; i< n ; i++)
   {
       if(a[v][i] && !visited[i] )
        q[++r] = i;
   }
   if(f<=r)
   {

       visited[q[f]]=1;
       bfs(q[f++]);
   }

}

int main()
{
    scanf("%d",&n);
    for(i = 0 ; i< n ; i++)
    {
        q[i] = 0;
        visited[i] = 0;
    }
            for(i  = 0 ; i < n ; i++)
        for(j= 0 ; j < n ; j++)
        scanf("%d",&a[i][j]);
        int v;
        scanf("%d",&v);
        bfs(v);
         printf("\n The node which are reachable are:\n");
 for(i=1;i<=n;i++)
  if(visited[i])
   printf("%d\t",i);
  else
   printf("\n Bfs is not possible");



    return 0;
}
