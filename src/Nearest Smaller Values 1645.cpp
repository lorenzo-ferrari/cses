#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    stack <pair<int, int>> st;
    st.push({-1, -1});

    for(int i = 0; i < n; i++)
    {
        while(st.top().first >= v[i])
            st.pop();
        
        cout << st.top().second + 1 << " ";

        st.push({v[i], i});
    }
}
