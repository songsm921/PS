#include <iostream>
#include <queue>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    priority_queue<int> arr;
    int k;
    cin>>k;
    for(int i =0;i<k;i++)
    {
        cin>>n;
        if(n)
        {
            arr.push(n);
        }
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