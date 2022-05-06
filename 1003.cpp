#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>> DP;
int main()
{
    
    int n;
    cin>>n;
    while(n--){
        DP.clear();
        DP.push_back({1,0});
        DP.push_back({0,1});
        int k;
        cin>>k;
    for(int i = 2 ;i<=k;i++)
    {
            DP.push_back({DP[i-2].first+ DP[i-1].first,DP[i-2].second+ DP[i-1].second});
    }
    cout<<DP[k].first<<" "<<DP[k].second<<"\n";
    }
    return 0;
}