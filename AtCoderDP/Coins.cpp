# include <iostream>
# include <bits/stdc++.h>
# include <string>
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

using namespace std;

int max(int a, int b) { return (a > b) ? a : b;}

void solve()
{
    int n, m, i, j, k;
    double x;

    cin >> n;
    vector<double> p;
    seev(p, n);

    vector<vector<double>> dp (n + 1, vector<double>(n + 1, 0.0));    
    dp[0][0] = 1.0;

    /*
        Attempt 1:
        Rows -> Toss
        Columns -> Heads
    */

        fr(1, n + 1, i) {
        dp[i][0] = (1.0 - p[i-1]) * dp[i-1][0];
        // cout << dp[i][0] << " ";
        }

        fr (1, n + 1, i) {
            fr(1, n + 1, j) {
                dp[i][j] = (1.0 - p[i-1]) * (dp[i-1][j]) + (p[i-1]) * (dp[i-1][j-1]);
            }
        }

        double answer = 0;
        fr(n/2 + 1, n + 1, i) {
            answer += dp[n][i];
        }
        cout.precision(10);
        cout << answer << endl;

}

signed main()
{
    fast_io;
    int t;

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
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