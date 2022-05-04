#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int DP[1001];
    DP[0] = 1;
    DP[1] = 1;
    for(int i = 2; i<=n;i++)
    {
        DP[i] = (DP[i-2]+DP[i-1])%10007;
    }
    cout<<DP[n];
    return 0;
}