/*
Task:              1068 Weird Algorithm
Sender:            lorenzo_ferrari
Submission time:   2020-04-09 23:50:33
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int64_t n;
    cin >> n;
    
    cout << n << " ";
    
    while(n != 1)
    {
        if(n&1)
            n = 3*n+1;
        else
            n = n>>1;
        
        cout << n << " ";
    }
}