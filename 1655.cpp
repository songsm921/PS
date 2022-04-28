#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    priority_queue<int,vector<int>,greater<int>> min_heap;
    priority_queue<int> max_heap;
    int k,n;
    cin>>k;
    for(int i = 0; i <k ;i++)
    {
        cin>>n;
        if(max_heap.size()<= min_heap.size())
            max_heap.push(n);
        else
            min_heap.push(n);
        if(!max_heap.empty()&&!min_heap.empty())
        {
            if(min_heap.top()<max_heap.top())
            {
                int max_heap_top = max_heap.top();
                int min_heap_top = min_heap.top();
                max_heap.pop();
                min_heap.pop();
                max_heap.push(min_heap_top);
                min_heap.push(max_heap_top);
            }
        }
        cout<<max_heap.top()<<"\n";
    }
    return 0;
}