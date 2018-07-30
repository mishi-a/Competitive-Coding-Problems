/*************
        Author - am10
             ******************/
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
  int n,m;
  cin >> n >> m;
  cout << min(n,m)+1 << endl;
  int p = 0;
  int x=min(n,m),y =0;
  while(p<min(n,m)+1)
  {
    cout << x << " " << y << endl;
    x--;
    y++;
    p++;
  }
}

