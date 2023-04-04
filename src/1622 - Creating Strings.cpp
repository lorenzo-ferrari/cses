/*
Task:              1622 Creating Strings
Sender:            lorenzo_ferrari
Submission time:   2020-06-12 22:24:28
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int freq[130];
string s, a;
vector <string> sol;

int freqHere(char c){
    int ans = 0;
    for(char x : a)
        ans += (x==c);

    return ans;
}

void solve(){
    if(a.size() == s.size()){
        sol.push_back(a);
    }
    else{
        for(int i = 0; i < 26; i++){
            if(freq[i+97] && freq[i+97] > freqHere(i+97)){
                a.push_back(i+97);
                solve();
                a.pop_back();
            }
        }
    }
}

int main(){
    cin >> s;
    for(char c : s) freq[c]++;
    sort(s.begin(), s.end());
    solve();
    cout << sol.size() << "\n";
    for(auto x : sol){
        cout << x << "\n";
    }
}