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
  int n,k;
  cin >> n >> k;
  int sum = 0;
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    sum+=a;
  }
  int pc = 1.0*sum/n+0.5;
  if(pc == k)
    cout << "0" <<endl;
  else
  {
    int res = 2*(k*n - 0.5*n - sum);
    cout << ceil(res) << endl;
  }
}
