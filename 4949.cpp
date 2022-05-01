#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    stack<char> p;
    string line;
    bool pass = true;
    while(1)
    {
        pass = true;
        while(!p.empty())
            p.pop();
        line.clear();
        getline(cin,line);
        if(line[0] == '.')
            break;
        for(int i = 0; i<line.length();i++)
        {
            if(line[i] == '(' || line[i] == '[')
                p.push(line[i]);
            else if(line[i] == ')')
            {
                if(!p.empty() && p.top() == '(')
                    p.pop();
                else
                {
                    pass = false;
                    break;
                }
            }
            else if(line[i] == ']')
            {
                if(!p.empty() && p.top() == '[')
                    p.pop();
                else
                {
                    pass = false;
                    break;
                }
            }
        }
        

        if(p.empty() && pass)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
