#include <iostream>
using namespace std;
int stair[301];
int DP[301];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i = 1 ;i<=n;i++)
        cin>>stair[i];
    DP[1] = stair[1];
    DP[2] = stair[1]+stair[2];
    DP[3] = max(stair[1],stair[2]) + stair[3];
    for(int i = 4 ; i<=n;i++)
    {
        DP[i] = max(DP[i-2], DP[i-3] + stair[i-1]) + stair[i];
    }
    cout<<DP[n];
    return 0;
}