/*
LCS PseudoCode
C[i, j] = {0 (i = 0, j = 0)
            C[i-1, j-1] + 1 (i, j > 0 and xi = yj)
            max(C[i, j -1], c[i-1, j]) (i, j > 0 and xi != yj)}
*/

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

using namespace std;

int max(int a, int b) { return (a > b) ? a : b;}

void solve()
{
    int n, m, x, i, j, k;
    
    string a, b;
    cin >> a >> b;

    int asize = a.size();
    int bsize = b.size();

    vector<vector<int>> dp (asize + 1, vector<int>(bsize + 1, 0));

    fr (1, asize + 1, i) {
        fr (1, bsize + 1, j) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }

    string answer;
    i = asize, j = bsize;

    while (i && j) {
        if (a[i - 1] == b[j - 1]) {
            answer += a[i - 1];
            i--, j--;
        }
        else if (dp[i][j - 1] >= dp[i - 1][j]) {
            j--;
        }
        else i--;
    }
    reverse(answer.begin(), answer.end());
    cout << answer;
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

/*
   |   | a | b | y | x | b |
---+---+---+---+---+---+---|
   | 0 | 0 | 0 | 0 | 0 | 0 |
 a | 0 | 1 | 1 | 1 | 1 | 1 |
 x | 0 | 1 | 1 | 1 | 2 | 2 |
 y | 0 | 1 | 1 | 2 | 2 | 2 |
 b | 0 | 1 | 2 | 2 | 2 | 3 |
*/