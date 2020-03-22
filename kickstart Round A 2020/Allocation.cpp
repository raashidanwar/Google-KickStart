/* 
  In the name of ALLAH
  Author : Raashid Anwar
  problem : Allocation
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define int    int64_t
const int MOD = 1000000007;
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin>>T;
  for(int t=1;t<=T;t++) {
    int n,b,ans=0;
    cin>>n>>b;
    int a[n+1];
    for(int i=1;i<=n;i++)
      cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n&&b;i++)
      if(b>=a[i]) {
        b-=a[i];
        ans++;
      }
    cout<<"Case #"<<t<<": "<<ans<<"\n";
  }
}
