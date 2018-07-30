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
stack <int> a;
stack <int> b;
int placed[1001] = {0};
int main()
{
  sync;
  while(1)
  {  
    int n;
    cin >> n;
    while(!a.empty())
      a.pop();
    while(!b.empty())
      b.pop();
    if(n == 0)
      break;
    else
    {
      for(int i=0;i<n;i++)
      {
        int x;
        cin >> x;
        b.push(x);
      }
      for(int i=0;i<n;i++)
      {
         a.push(b.top());
         b.pop();
      }
     
       memset(placed,0,sizeof(placed));
      int ind = 1;
      int flag = 0;
      while(1)
      {//cout << ind << endl;
        if(a.size() == 0 && b.size() == 0)
           break;
        if(a.size() > 0 && a.top() == ind)
        {
          a.pop();
          ind++;
        }
        else
        {
          if(placed[ind] == 0)
          {
            b.push(a.top());
            placed[a.top()] = 1;
            a.pop();
          }
          else
          {
            //a.push(b.top());
           //placed[b.top()] = 0;
           if(b.size()>0&& b.top()!=ind)
           {
             flag = 1;
             break;
           }
            b.pop();
            ind++;
          }
        }
      }flag == 1 ? cout << "no" << endl : cout << "yes" << endl;
    }
    
  }
}

