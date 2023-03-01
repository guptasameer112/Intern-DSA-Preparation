# include <iostream>
# include <bits/stdc++.h>
# include <vector>
# include <set>
# define INF 1e9
# define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
# define fr(a, b, i) for(int i = a; i < b; i++)
# define printArray(array) for(auto edge: array) {cout << edge << " ";}
# define all(x) x.begin(),x.end() // sort(all(arr))
# define vi vector<int>
# define int long long
# define pb push_back
# define pii pair<int, int>
# define seev(v, n) for(int i = 0; i < n; i++) {cin >> x; v.push_back(x);}
# define sees(s, n) for(int i= 0; i < n; i++) {cin >> x; s.insert(x);}
const int mod =  1e9 + 7;

// int dp[1000005];

/*
j = i + 1 or j = i + 2
// Reccurence Relation: dp[j] = min(dp[j], dp[i] + abs(a[j] - a[i]))
*/

using namespace std;

int max(int a, int b) { return (a > b) ? a : b;}

void solve()
{
    int n, m, x, i, j, k;

    cin >> n;
    vector<int> arr;
    seev(arr, n);

    // printArray(arr);

    vector<int> dp(n, INF);

    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);

    fr (2, n, i)
        dp[i] = min(min(dp[i], dp[i-1] + abs(arr[i-1] - arr[i])), min(dp[i], dp[i - 2] + abs(arr[i-2] - arr[i])));
        // dp[i] = min(dp[i-1] + abs(arr[i-1] - arr[i]), dp[i - 2] + abs(arr[i-2] - arr[i]));

    cout << dp[n-1];
    
}

signed main()
{
    fast_io;
    int t;

    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // cin >> t;
    t = 1;

    while (t--)
    {
        // code here
        solve();
    }

    #ifdef LOCAL
    clock_t tStart = clock();
    cerr << fixed<< setprecision(10) << "\nTime Taken: " << (double)(clock()- tStart)/CLOCKS_PER_SEC << endl;
    #endif

    return 0;
}