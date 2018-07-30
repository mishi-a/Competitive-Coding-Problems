#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;

void solve()
{
   int n;
   cin >> n;
   char ch;
   vector <int> v;
   for(int i=0 ; i< n;i++)
   {
     cin >> ch;
     if(ch!='.')
     {
       ch == 'H' ? v.pb(0) : v.pb(1);
     }
   } 
   if(v.size() == 0)
   {
      cout << "valid" << endl;
        return;
   }
   if(v.size() == 1)
   {
      cout << "Invalid" << endl;
        return;
   }
   if(v[0] == 1 || v[v.size()-1] == 0)
   {
        cout << "Invalid" << endl;
        return;
   }
   for(int i=1;i<v.size();i++)
   { 
     if(v[i] == v[i-1])
     {
       cout << "Invalid" << endl;
        return;
     }
   }
   cout << "Valid" << endl;
} 

int main()
{
  sync;
  int r;
  cin >> r;
  while(r--)
    solve();
}
