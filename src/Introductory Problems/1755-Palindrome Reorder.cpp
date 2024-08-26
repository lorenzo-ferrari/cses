#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    char c;
    int freq[26]{};
    while(cin >> c){
        ++freq[c-65];
    }

    string pref, suff;
    int disp = 0;

    for(int i = 0; i < 26; i++){
        if(freq[i]&1){
            disp++;
            c = i+65;
        }
        if(disp>1){
            cout << "NO SOLUTION\n";
            exit(0);
        }
        suff += string(freq[i]/2, char(i+65));
    }
    pref = suff;
    reverse(suff.begin(), suff.end());
    cout << pref;
    if(disp) cout << c;
    cout << suff << "\n";
}