#include <string>
#include <vector>
#include <cstring>
using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int visit[5][5];
bool flag = true;
void DFS(int x, int y, int depth, vector<string>& map)
{
    if(depth>2 || flag == false)
        return;
    if(map[x][y] == 'P' && depth>0)
    {
        flag = false;
        return;
    }
    for(int i = 0; i < 4 ;i++)
    {
        int x_pos = x + dx[i];
        int y_pos = y + dy[i];
        if(x_pos>=5 || x_pos<0 || y_pos>=5 || y_pos<0)
            continue;
        if(visit[x_pos][y_pos] == 1 || map[x_pos][y_pos] == 'X')
            continue;
        DFS(x_pos,y_pos,depth+1,map);
    }
}
vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    for(int i = 0; i<5;i++)
    {
        flag = true;
        memset(visit,0,sizeof(visit));
        for(int j = 0;j<5;j++)
        {
            for(int k = 0; k<5;k++)
            {
                if(places[i][j][k] == 'P')
                {
                    visit[j][k] = 1;
                    DFS(j,k,0,places[i]);
                    if(!flag)
                        break;
                }
            }
            if(!flag)
                break;
        }
        answer.push_back(flag);
    }
    return answer;
}
