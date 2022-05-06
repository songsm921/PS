#include <iostream>
#include <string>
using namespace std;
int DP[1001][1001];
int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for(int i = 0; i<=s1.length();i++)
    {
        for(int j = 0; j<=s2.length();j++)
        {
            if(i==0 || j==0)
                DP[i][j] =0;
            else if(s1[i-1] == s2[j-1])
                DP[i][j] = DP[i-1][j-1] + 1;
            else
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
        }
    }
    int ans = -1;
    for(int i = 0; i<=s1.length();i++)
    {
        for(int j = 0; j<=s2.length();j++)
        {
            if(ans<DP[i][j])
                ans = DP[i][j];
        }
    }
    cout<<ans;
    return 0;
}