/* Problem E */

    /* Normal Knapsack pseudocode
    dp[0, w] = 0
    dp[i, 0] = 0
    dp[i, w] = dp[i-1, w]
    dp[i, w] = dp[i-1, w - wi] + vi for (wi <= w)
    */

    /* In this question the weight constraints have been changed, and therefore instead of the usual 2D array of n and w (dp[i][j] = max value), we will have array of n and v (dp[i][j] = min weight)/
    Further this question can be solved either with a complete 2D matrix or we can use rolling array/bitset to reduce space complexity. */

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
    /* dp[n][v] = INF; all i, j 
    dp(i, v) -> Minimum weight needed to get the value V using 1...i items */

    int n, m, x, i, j, k, W;
    cin >> n >> W;

    int weights[n], values[n];
    fr(0, n, i)
        cin >> weights[i] >> values[i];
    
    int sum = 0;
    fr(0, n, i)
        sum += values[i];
    
    vector<vector<int>> dp(sum + 5, vector<int>(n+1, INF)); 
    dp[0][0] = 0;
    // rows will go until the maximum possible value sum
    // dp[i][j] = min weight for value i considering upto j items

    fr(0, sum, i) {
        fr (1, n + 1, j) {
            dp[i][j] = min(dp[i][j], dp[i][j-1]); // if item i is not part of the optimum solution
            if (i - values[j - 1] >= 0)
                dp[i][j] = min(dp[i][j], dp[i - values[j-1]][j-1] + weights[j-1]);
        }
    }

    int ans = 0;
    for (int i = N - 1; i >= 1; i--) {
        if (dp[i][n] <= W) {
            ans = i;
            break;
        }
    }
    // This gives the maximum value for which the weight is just less than or equal to maximum possible weight.

    cout << ans;
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

/* Rolling Array */
/* The logic behind the optimisation is, to compute mat[i][j], we only need solution of previous row.
In 0-1 knapsack problem if we are currently on mat[i][j] and we include ith element then we move j - wt[i]  steps back in the previous row (i-1) and if we exclude the current element we move on jth column in the previous row.
So we are essentially working with only 2 rows, the current one and the previous one.*/

/*
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

using namespace std;

int max(int a, int b) { return (a > b) ? a : b;}

void solve()
{
    int n, m, x, i, j, k, W;
    cin >> n >> W;

    int weights[n], values[n];
    fr(0, n, i)
        cin >> weights[i] >> values[i];

    int mat[W + 1];
    fr(0, W + 1, i)
        mat[i] = 0;


    // Important
    // For each weight, the code computes the maximum value that can be obtained using items up to and including the current item. The maximum value is stored in an array called mat.
    for (0, n, i)  {
        for (int j = W; j >= weights[i]; j--) {
            mat[j] = max(mat[j], values[i] + mat[j - weights[i]]);
        }
    }
    
    cout << mat[W];
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
*/

/*
The next step is to fill the rolling array dp using a nested loop. The outer loop iterates over each item i from 0 to n-1, while the inner loop iterates over each possible weight value j from W down to the weight of item i (inclusive). This order of iteration ensures that each item is only considered once for each possible weight value.
For each weight value j, the inner loop calculates the maximum value that can be obtained by either excluding item i (i.e. using the value of dp[j] from the previous iteration) or by including item i and subtracting its weight wt[i] from the current weight value j (i.e. using the value of dp[j - wt[i]] from the previous iteration plus the value of item i). The std::max function is used to select the greater of these two values and store it in dp[j].
If we iterate through the weight values first and the items second, we can avoid redundant computations by ensuring that each item is only considered once for each possible weight value.
*/


/* Additional Information */
// Using Bitsets to reduce the space (same as rolling array approach)

/* Basics of Bitset */
/*
    It is an array of bool in such a way that the space taken is less than vector(n) and bool[n].
    However, it isn't dynamically allocable, therefore size has to be known at compile time.
    Indexing in bitsets is in the opposite/backward direction (0th element is the last one)

    bitset<size> bset1;
    bitset<size> bset2(string("1100")); 00000000000000000000000000001100
    bset[index] = value;
    bset.count(); returns bits set to one
    bset.size(); total bits
    bset.test(); returns 1 if bit is set else zero
    bset.any(); returns true if even 1 bit is set
    bset.none();
    bset.set(pos, b); bset[pos] = b
    bset.set(pos); bset[pos] = 1
    bset.reset(); all bits to 0
    bset.flip(); 1 -> 0, 0 -> 1
*/

/*
Application of bitset
function knapsack(items, capacity):
    n = length(items)
    dp = array of size (2, C+1)  # initialize the rolling array
    curr_row = 0  # start with the first row
    prev_row = 1  # initialize the previous row to 1

    # initialize the first row of the rolling array
    for j from 0 to C:
        if j >= items[0].weight:
            dp[curr_row, j] = items[0].value
            bitset[j] = 1
        else:
            dp[curr_row, j] = 0

    # compute the optimal solutions for subsequent rows
    for i from 1 to (n-1):
        # switch rows for the rolling array
        curr_row, prev_row = prev_row, curr_row
        bitset.reset()  # reset the bitset for the new row
        for j from 0 to C:
            if j >= items[i].weight:
                # check if the previous capacity has been considered
                if bitset[j - items[i].weight]:
                    dp[curr_row, j] = max(dp[prev_row, j], dp[curr_row, j - items[i].weight] + items[i].value)
                    bitset[j] = 1  # mark the current capacity as considered
                else:
                    dp[curr_row, j] = dp[prev_row, j]
            else:
                dp[curr_row, j] = dp[prev_row, j]

    return dp[curr_row, C]
*/