#include <bits/stdc++.h>
using namespace std;

int editDist(char str1[], char str2[], int m , int n){
 int table[m+1][n+1];
 int i , j;
    for(i = 0 ; i<= m ; i++){
     for(j = 0 ; j<= n ; j++){
        if( i == 0)
     table[i][j] = j;
     else if( j == 0)
     table[i][j] = i;
   else if(str1[i-1]==str2[j-1])
        table[i][j] = table[i-1][j-1];

   else  table[i][j]=1+ min(table[i-1][j],min(table[i][j-1],table[i-1][j-1]));
    }

    }
    return table[m][n];
}

int main()
{
    int m,n;
  char str1[] = "Sunday";
 m =  strlen(str1);
  char str2[] = "Saturday";
  n = strlen(str2);
 int opr = editDist(str1,str2,m,n);
 cout<<opr;

    return 0;
}
