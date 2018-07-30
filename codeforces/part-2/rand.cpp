#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;

int main()
{
  srand(time(NULL));
  cout << "50000" <<  endl;
  for(int i=0;i<50000;i++)
  {
    int x = 1+rand()%100000;
    cout << x ;
    cout << " ";
  }
  cout << endl;
  cout << "50000" << endl;
  int cnt = 0;
  while(cnt<50000)
  {
    int p = 1+rand()%2;
   cout << p <<" " ;
   if(p==1)
   {
    cout << 1+rand()%50000 << " " << 1+rand()%100000 << endl;
   }
   else
   {
    int l = 1+rand()%49999;
    int r = l+rand()%(50000-l);
    cout << l << " " << r << " " << 1+rand()%100000 << endl;
   }
   cnt++;
  }
  
}

