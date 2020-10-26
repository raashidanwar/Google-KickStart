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
  int w, n;
  cin >> w >> n;
  vector <int> a;
  for (int i = 0; i < w; i++) {
    int x;
    cin >> x;
    a.push_back(x - 1);
    a.push_back(x - 1 + n);
  }
  sort(a.begin(), a.end());
  int l = 0, r = 0, left = (n - 1) / 2, right = n - 1 - ((n - 1) / 2), suml = 0, sumr = 0;
  int ans = M2 * M2;
  for (int i = 0; i < w + w; i++) {
    suml += a[i];
    while (a[l] < a[i] - left) {
      suml -= a[l++];
    }
    while (r < w + w && a[r] <= a[i] + right) {
      sumr += a[r++];
    }
    sumr = sumr - (i? a[i - 1]: 0);
    if (r - l == w)
      ans = min(ans, sumr - (r - i) * a[i] + (i - l + 1) * a[i] - suml);
  }
  cout << ans << "\n";
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
