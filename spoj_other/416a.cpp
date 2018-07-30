#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;

int main()
{
  sync;
  ll a,b;
  cin >> a >> b;
  ll x = floor(sqrt(a));
  ll y = floor((-1+sqrt(1+4*b))/2);
  if(x <= y)
    cout << "Vladik" << endl;
  else
    cout << "Valera" << endl;
}
