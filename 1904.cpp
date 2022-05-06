#include <iostream>
#include <vector>
using namespace std;
vector<int> DP;
int main()
{
    
    int n;
    cin>>n;
    DP.push_back(0);
    DP.push_back(1);
    DP.push_back(2);
    for(int i = 3;i<=n;i++)
    {
        DP.push_back((DP[i-1]+DP[i-2])%15746);
    }
    cout<<DP[n];
    return 0;
}