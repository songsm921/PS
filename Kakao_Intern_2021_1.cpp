#include <iostream>
#include <string>
using namespace std;
int solution(string s);
int main()
{   
    string s;
    cin>>s;
    cout<<solution(s)<<"\n";
    return 0;
}
int solution(string s)
{
    int answer;
    string tmp;
    for(int i = 0; i<s.length();)
    {
        if(s[0] == '0' || 'z')
            break;
        if(s[i]=='z')
        {
           tmp.push_back('0');
           i = i+4;
        }
        else if(s[i]=='o')
        {
           tmp.push_back('1');
           i = i+3;
        }
        else if(s[i]=='t')
        {  
            if(s[i+1]=='w'){
                tmp.push_back('2');
                i = i+3;
            }
            else{
                tmp.push_back('3');
                i = i+5;
            }
        }
        else if(s[i]=='f')
        {  
            if(s[i+1]=='o'){
                tmp.push_back('4');
                i = i+4;
            }
            else{
                tmp.push_back('5');
                i = i+4;
            }
        }
        else if(s[i]=='s')
        {  
            if(s[i+1]=='i'){
                tmp.push_back('6');
                i = i+3;
            }
            else{
                tmp.push_back('7');
                i = i+5;
            }
        }
        else if(s[i]=='e')
        {
           tmp.push_back('8');
           i = i+5;
        }
        else if(s[i]=='n')
        {
           tmp.push_back('9');
           i = i+4;
        }
        else // number
        {
            tmp.push_back(s[i]);
            i++;
        }
    }
    answer = stoi(tmp);
    return answer;
}