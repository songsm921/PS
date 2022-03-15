#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin>>n;
    for(int i = 0; i<n;i++)
    {
        double a,b;
        int ans = 0;
        int add = 0;
        cin>>a>>b;
        int k = sqrt(b-a);
        ans = 2*k - 1;
        add = ceil(((b-a)-pow(k,2))/k);
        cout<<ans+add<<"\n";
    }
    return 0;
}
