#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;
list<int> arr;
stack<pair<list<int>::iterator,int>> trash; //  next reference / vertex #24
string solution(int n, int k, vector<string> cmd)
{
    string answer(n,'X');
    for(int i = 0 ; i<n;i++)
        arr.push_back(i);
    int cur = k;
    int cur_total = n;
    auto iter = arr.begin();
    for(int i = 0; i<k;i++)
        iter = next(iter);
    for(int i = 0 ; i<cmd.size(); i++)
    {
        switch(cmd[i][0])
        {
            case 'U':{
                int cnt = stoi(cmd[i].substr(2));
                iter = prev(iter,cnt);
                break;
            }
             case 'D':{
                int cnt = stoi(cmd[i].substr(2));
                iter = next(iter,cnt);
                break;
            }
             case 'C':{
                auto tmp = next(iter);
                trash.push({tmp,*iter});
                iter=arr.erase(iter);
                if(iter == arr.end())
                    iter = prev(iter);
                cur_total--;
                break;
            }
            case 'Z':{
                auto pos = trash.top().first;
                arr.insert(pos,trash.top().second);
                trash.pop();
                cur_total++;
                break;
            }
        }
    }
    for(auto i = arr.begin();i!=arr.end();i = next(i))
        answer[*i] = 'O';
    return answer;
}
int main()
{
    
    int n = 1000000;
    int k = 900000;
    vector<string> input(k,"C");
    string ans = solution(n,k,input);
    for(int i = 0;i<ans.length();i++)
        cout<<ans[i];
    return 0;
}