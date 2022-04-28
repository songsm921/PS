#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;
string solution(int n, int k, vector<string> cmd);

int main()
{   vector<string> cmdline = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"};
    cout<<solution(8,2,cmdline);
    return 0;
}

string solution(int n,int k, vector<string> cmd)
{
    string answer(n,'X');
    stack<int> trash;
    set<int> table;
    for(int i=0; i<n;i++)
    {
        table.insert(i);
    }
    auto cur = table.find(k);
    for(string c:cmd)
    {
        switch(c[0])
        {
            case 'U':
            {
                int pos = stoi(c.substr(2));
                for(int k = 0; k<pos;k++)
                    cur = prev(cur);
                break;
            }
            case 'D':
            {
                int pos = stoi(c.substr(2));
                for(int k = 0; k<pos;k++)
                    cur = next(cur);
                break;
            }
            case 'C':
            {
                trash.push(*cur);
                cur=table.erase(cur);
                if(cur == table.end())
                    cur = prev(cur);
                break;
            }
            case 'Z':
            {
                table.insert(trash.top());
                trash.pop();
                break;
            }
        }
    }
    for(int i : table)
        answer[i] = 'O';
    return answer;
}
