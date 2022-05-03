#include <iostream>
#include <queue>
using namespace std;
queue<pair<int,int>> vertex;
bool visited[100001];
int main()
{
    int u,v;
    bool flag = false;
    int time = 0;
    int ans = 0;
    cin>>u>>v;
    vertex.push({u,time});
    visited[u] = 1;
    while(!vertex.empty())
    {   
        pair<int,int> cur = vertex.front();
        vertex.pop();
        if(cur.first == v)
        {
            ans = cur.second;
            break;
        }
       if(cur.first - 1 >= 0) {
            if(!visited[cur.first - 1]) {
                vertex.push({cur.first- 1, cur.second + 1});
                visited[cur.first] = true;
            }
        }

        if(cur.first + 1 <= 100000) {
            if(!visited[cur.first + 1]) {
                vertex.push({cur.first + 1, cur.second + 1});
                visited[cur.first] = true;
            }
        }

        if(cur.first * 2 <= 100000) {
            if(!visited[cur.first * 2]) {
                vertex.push({cur.first * 2, cur.second + 1});
                visited[cur.first] = true;
            }
        }

    }
    cout<<ans;
    return 0;

}