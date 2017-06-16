#include <iostream>
#include<algorithm>

using namespace std;
struct Job{
char id;
int deadline;;
int profit;
};

bool comparison(Job a, Job b)
{

    return (a.profit >= b.profit);
}
void printJob(Job arr[], int n)
{

    sort(arr,arr+n,comparison);
    char result[n];
    bool slot[n] = {false};
    int i,j;
    for(i = 0 ; i< n ; i++)
    {

        for( j = min(n,arr[i].deadline)-1; j>=0; j--)
        {
            if(slot[j]==false)
            {
                result[j] = arr[i].id;
                slot[j] = true;
                break;
            }
        }
    }
    for(i = 0 ; i < n ; i++)
        cout<<result[i];

}

int main()
{
    Job arr[] =  { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
                   printJob(arr , 5);

    return 0;
}
