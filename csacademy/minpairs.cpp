#include <bits/stdc++.h>

using namespace std;
vector <int> v;

int main() {
   int n;
   int ans = 0;
   cin >> n;
   for(int i=0;i<n;i++)
   {
      int a;
      cin >> a;
      v.push_back(a);
   }
   sort(v.begin(),v.end());
   for(int i=1;i<v.size();i=i+2)
     ans = ans + (v[i]-v[i-1]);
   cout << ans << endl;
}
