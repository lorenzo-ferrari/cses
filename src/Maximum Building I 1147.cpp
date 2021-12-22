#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int banner(int n, vector <int> h)
{
    vector <int> nxt(n);
    stack <pii> st;

    st.push({-1, n});
    for(int i = n-1; i >= 0; i--)
    {
        while(st.top().first >= h[i])
            st.pop();
        
        nxt[i] = st.top().second;

        st.push({h[i], i});
    }

    int  maxArea = 0;
    while(!st.empty()) st.pop();
    st.push({-1, -1});
    
    for(int i = 0; i < n; i++)
    {
        while(st.top().first >= h[i])
            st.pop();

        if(h[i]*(nxt[i]-st.top().second-1) >= maxArea)
            maxArea = h[i]*(nxt[i]-1 - st.top().second);
        
        st.push({h[i], i});
    }

    return maxArea;
}

int main()
{
    int n, m, maxArea = 0;
    char c;
    cin >> n >> m;

    vector <int> freeSpace (m);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> c;
            if(c == '*')
                freeSpace[j] = 0;
            else 
                freeSpace[j]++;
        }

        maxArea = max(maxArea, banner(m, freeSpace));
    }

    cout << maxArea << "\n";
}
