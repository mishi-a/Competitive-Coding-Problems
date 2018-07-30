#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <algorithm>


#define sync ios::sync_with_stdio(false)
#define endl '\n'

using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector <int> l(n,-1);
  int x = 1;
  int num =0,coun = 0,coun1 = 0;
  while(num < n)
  {     // cout << "coun" << coun << "coun1" << coun1 <<endl;
    coun = coun+1;
    coun1 = coun;
    for(int i=0;coun1>=0;i++)
    {
      if(i == l.length())
         i = 0;
      if(l[i] == -1)
      {
        if(coun1 == 0)
        {
          l[i] = x;
          x++;
          num++;
          i++;
        }
        coun1--; 
      }
     
    }
  }
  for(i=0;i<n;i++)
  {
    cout << l[i] << " " ;
  } 
  cout << endl;
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
    solve();
}
