#include <bits/stdc++.h>
using namespace std;

int editDist(char str1[], char str2[], int m , int n){
    if(m==0)
        return n;
    if(n==0)
        return m;
    if(str1[m-1]==str2[n-1])
        return editDist(str1,str2,m-1,n-1);
    return 1 + min(editDist(str1,str2,m-1,n),min(editDist(str1,str2,m,n-1),editDist(str1,str2,m-1,n-1)));

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
