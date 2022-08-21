#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
pair<int,int> L_cur = {3,0};
pair<int,int> R_cur = {3,2};
string solution(vector<int> numbers, string hand) {
    string answer = "";
    for(int i = 0 ; i<numbers.size();i++)
    {
        if(numbers[i] % 3 == 1)
        {
            answer+='L';
            L_cur.first = numbers[i]/3;
            L_cur.second = 0;
        }
        else if(numbers[i] % 3 == 0 && numbers[i] != 0){
            answer+='R';
            R_cur.first = numbers[i]/3 - 1;
            R_cur.second = 2;
        }
        else if(numbers[i] % 3 == 2 || numbers[i] == 0)
        {
            int distBtwLeft;
            int distBtwRight;
            if(numbers[i] == 0){
                distBtwLeft = abs(3 - L_cur.first) + abs(1- L_cur.second);
                distBtwRight = abs(3 - R_cur.first) + abs(1 - R_cur.second);
            }
            else{
            distBtwLeft = abs(numbers[i]/3 - L_cur.first) + abs(1-L_cur.second);
            distBtwRight = abs(numbers[i]/3 - R_cur.first) + abs(1 - R_cur.second);
            }
            if(distBtwLeft<distBtwRight){
                answer+='L';
                if(numbers[i] == 0){
                    L_cur.first = 3;
                }
                else
                    L_cur.first = numbers[i]/3;
                L_cur.second = 1;
            }
            else if(distBtwLeft>distBtwRight)
            {
                answer+='R';
                if(numbers[i]==0)
                    R_cur.first = 3;
                else
                    R_cur.first = numbers[i]/3;
                R_cur.second = 1;
            }
            else{
                if(hand == "right")
                {
                    answer+='R';
                    if(numbers[i]==0)
                        R_cur.first = 3;
                    else
                        R_cur.first = numbers[i]/3;
                    R_cur.second = 1;
                }
                else if(hand == "left"){
                    answer+='L';
                    if(numbers[i]==0)
                        L_cur.first = 3;
                    else
                        L_cur.first = numbers[i]/3;
                    L_cur.second = 1;
                }
            }
        }
    }
    return answer;
}
