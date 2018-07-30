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
  cout << "15" <<  endl;
  for(int i=0;i<15;i++)
  {
    int x = 1+rand()%100000;
    cout << x ;
    cout << " ";
    cout << endl;
  }
  cout << endl;
  cout << "10";
  int cnt = 0;
  while(cnt<10)
  {
    int p = 1+rand()%2;
   cout << p <<" " << endl;
   if(p==1)
   {
    cout << 1+rand()%15 << " " << 1+rand()%100000 << endl;
   }
   else
   {
    int l = 1+rand()%14;
    int r = l+rand()%(15-l);
    cout << l << " " << r << " " << 1+rand()%100000 << endl;
   }
   cnt++;
  }
  
}

