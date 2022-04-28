/*Min Heap*/
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    priority_queue<int,vector<int>,greater<int>> arr;
    int n;
    int k;
    cin>>n;
    for(int i = 0; i<n;i++)
    {
        cin>>k;
        if(k!=0)
            arr.push(k);
        else
        {
            if(arr.empty())
                cout<<"0\n";
            else
            {
                cout<<arr.top()<<"\n";
                arr.pop();
            }
        }
    }
    return 0;
}