#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stack>
using namespace std;

string solution(int n, int k, vector<string> cmd);

int main()
{   vector<string> cmdline = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"};
    cout<<solution(8,2,cmdline);
    return 0;
}
string solution(int n, int k, vector<string> cmd)
{
    string answer;
    stack<int> trash;
    list<int> li;
    for(int i = 0;i<n;i++)
        li.push_back(i);
    auto iter = li.begin();
    for(int i = 0; i<k;i++)
        iter++;
    for(int i = 0; i<cmd.size();i++)
    {
        switch(cmd[i][0])
        {
            case 'U': {
                int pos = stoi(cmd[i].substr(2));
                for(int k = 0; k<pos;k++)
                {
                    iter--;
                }
                break;
            }
            case 'D':{
                int pos = stoi(cmd[i].substr(2));
                for(int k = 0; k<pos;k++)
                {
                    iter++;
                }
                break;
            }
            case 'C':
            trash.push(*iter);
            iter=li.erase(iter);
            if(iter == li.end())
                iter--;
            break;
            case 'Z':
            {
                auto iter_back = li.begin();
                while(*iter_back<trash.top() && iter_back!=li.end())
                    iter_back++;
                li.insert(iter_back,trash.top());
                trash.pop();
                break;
            }
        }
    }
    for(int i = 0; i<n;i++)
        answer.push_back('X');
    auto iter_final = li.begin();
    for(int i = 0;i<li.size();i++)
    {
        answer[*iter_final] ='O';
        iter_final++;
    }
    return answer;
        
}
