/*
Task:              1754 Coin Piles
Sender:            lorenzo_ferrari
Submission time:   2020-04-30 17:47:51
Language:          C++17
Result:            ACCEPTED
*/
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        if((a+b)%3 || b-a > a)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}