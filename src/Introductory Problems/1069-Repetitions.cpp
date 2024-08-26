#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int mas = 0, tMax = 0;
    for(int i = 0; i < s.size(); ++i){
        if(!i || s[i] == s[i-1])
            ++tMax;
        else
        {
            mas = max(mas, tMax);
            tMax=1;
        }
    }

    cout << max(mas, tMax) << "\n";
}