#include <iostream>
#include <vector>
using namespace std;
int DP[1001];
int LCS[1001];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i = 1 ; i<=n;i++)
        cin>>LCS[i];
    for(int i = 1 ;i<=n;i++)
        DP[i] = 1;
    for(int i = 1;i<=n;i++)
    {
        for(int j = i -1;j>=1;j--)
        {
            if(LCS[i]>LCS[j] && DP[i]<=DP[j])
                DP[i] = DP[j] + 1;
        }
    }
    int max = 0;
    for(int i = 1;i<=n;i++)
    {
        if(max<DP[i])
            max = DP[i];
    }
    cout<<max;
    return 0;
}
