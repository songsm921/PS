#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
struct node{
    int vertex;
    node* prev;
    node* next;
    node(int v, node* prev, node* next):vertex(v),prev(prev),next(next){}
};
string solution(int n, int k, vector<string> cmd)
{
    string answer(n,'X');
    node* cur = new node(0,NULL,NULL);
    stack<node*> trash;
    for(int i = 1; i<n;i++)
    {
        cur->next = new node(i,cur,NULL);
        cur = cur->next;
    }
    for(int i = 0; i<n-k-1;i++)
    {
        cur = cur->prev;
    }
    for(int i = 0 ;i<cmd.size();i++)
    {
        switch(cmd[i][0])
        {
            case 'U':
            {
                int c = stoi(cmd[i].substr(2));
                while(c--)
                    cur = cur->prev;
                break;
            }
            case 'D':
            {
                int c = stoi(cmd[i].substr(2));
                while(c--)
                    cur = cur->next;
                break;
            }
            case 'C':
            {
                trash.push(cur);
                if(cur->prev!=NULL) 
                    cur->prev->next = cur->next;
                if(cur->next!=NULL) 
                    cur->next->prev = cur->prev;
                if(cur->next == NULL)
                    cur = cur->prev;
                else
                    cur = cur->next;
                break;
            }
            case 'Z':
            {
                node* hist = trash.top();
                trash.pop();
                if(hist->prev!=NULL)
                    hist->prev->next = hist;
                if(hist->next!=NULL)
                    hist->next->prev = hist;
                break;
            }
        }
    }
    while(cur->prev!=NULL)
        cur = cur->prev;
    while(cur!=NULL)
    {
        answer[cur->vertex] = 'O';
        cur = cur->next;
    }
    return answer;
}


int main()
{
    
    int n = 8;
    int k = 2;
    vector<string> input = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"};
    string ans = solution(n,k,input);
    for(int i = 0;i<ans.length();i++)
        cout<<ans[i];
    return 0;
}
