/*
  In the name of ALLAH
  Author : Raashid Anwar
*/

#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
const int M1 =  998244353;
const int M2 =  1000000007;
mt19937 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  int n;
  cin >> n;
  vector <vector <double>> dp(n, vector <double> (n));
  vector <vector <double>> dp0(n, vector <double> (n));
  vector <double> sum(n, 0);
  for (int i = 0; i < n; i++) {
    double x;
    cin >> x;
    sum[i] = (i? sum[i - 1]: 0) + x;
  }
  for (int l = 1; l < n; l++) {
    for (int i = 0; i + l < n; i++) {
      dp[i][i + l] = (dp0[i][i + l - 1] + dp0[i + l][i + 1]);
      dp[i][i + l] /= double(l);
      dp[i][i + l] += sum[i + l] - (i? sum[i - 1]: 0);
      dp0[i][i + l] = dp0[i][i + l - 1] + dp[i][i + l];
      dp0[i + l][i] = dp0[i + l][i + 1] + dp[i][i + l];
    }
  }
  cout << fixed << setprecision(6) << dp[0][n - 1] << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cout << "Case #" << tt << ": ";
    solve();
  }
}
