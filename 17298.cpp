#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
stack<int> stk;
int num[1000001];
int ans[1000001];
int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i<n;i++)
        cin>>num[i];
    for(int i = n - 1; i>=0;i--)
    {
        while(!stk.empty()&&stk.top()<=num[i])
            stk.pop();
        if(stk.empty())
            ans[i] = -1;
        else
            ans[i] = stk.top();
        stk.push(num[i]);
    }
    for(int i = 0; i<n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
