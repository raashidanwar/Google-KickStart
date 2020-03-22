/* 
  In the name of ALLAH
  Author : Raashid Anwar
  problem : Workout
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define int    int64_t
const int MOD = 1000000007;

int n;
vector <int> a;
 
int get(int x,int k) {
  for(int i=1;i<n;i++) {
    k-=((a[i]-a[i-1]-1)/x);
  }
  if(k<0)
    return false;
  return true;
}
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin>>T;
  for(int t=1;t<=T;t++) {
    int x,k;
    cin>>n>>k;
    a.clear();
    for(int i=0;i<n;i++) {
      cin>>x;
      a.push_back(x);
    }
    int lo=1,hi=1000000000;
    while(lo<=hi) {
      int mi=(lo+hi)>>1;
      if(get(mi,k))
        hi=mi-1;
      else
        lo=mi+1;
    }
    cout<<"Case #"<<t<<": "<<lo<<"\n";
  }
}
