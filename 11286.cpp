#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> arr;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        if(k!=0)
            arr.push({abs(k),k});
        else
        {
            if(arr.empty())
                cout<<"0\n";
            else
            {
                cout<<arr.top().second<<"\n";
                arr.pop();
            }
        }

    }
    return 0;
}