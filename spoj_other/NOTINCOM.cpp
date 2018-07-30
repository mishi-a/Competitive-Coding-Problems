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

vector <int> a;
int b[1000005] = {0};

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
      int x;
      cin >> x;
      a.pb(x);
    }
    for(int i=0;i<m;i++)
    {
      int x;
      cin>>x;
      b[x] = 1;
    }
    int cunt = 0;
    for(int i=0;i<n;i++)
    {
      if(b[a[i]]==1)
        cunt++;
    }
    cout << cunt << endl;
    memset(b,0,sizeof(b));
    a.clear();
  }
}

