/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>
#define FI first
#define SE second

/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;

int main()
{
  sync;
 
  string arr[]={"9","19","1119","3119","132119","1113122119"
	,"311311222119","13211321322119","1113122113121113222119","31131122211311123113322119"
	,"132113213221133112132123222119","11131221131211132221232112111312111213322119",
	"31131122211311123113321112131221123113111231121123222119",
	"1321132132211331121321231231121113112221121321133112132112211213322119",
"11131221131211132221232112111312111213111213211231132132211211131221232112111312212221121123222119",
"3113112221131112311332111213122112311311123112111331121113122112132113121113222112311311221112131221123113112211322112211213322119",
"132113213221133112132123123112111311222112132113311213211231232112311311222112111312211311123113322112132113212231121113112221121321132122211322212221121123222119",
"111312211312111322212321121113121112131112132112311321322112111312212321121113122112131112131221121321132132211231131122211331121321232221121113122113121122132112311321322112111312211312113221133211322112211213322119",
"3113112221131112311332111213122112311311123112111331121113122112132113121113222112311311221112131221123113112221121113311211131122211211131221131211132221121321132132212321121113121112133221123113112221131112212211131221121321131211132221123113112221131112211322212312211322212221121123222119",
"1321132132211331121321231231121113112221121321133112132112312321123113112221121113122113111231133221121321132122311211131122211213211321322112312321123113213221123113112221131112311332211211131221131211132211121312211231131112311211232221121321132132211331221122311311222112111312211311123113322112132113213221133122211332111213112221133211322112211213322119"};
int t;
cin >> t;
while(t--)
{
	int n;
	cin >> n;
	cout << arr[n-1] << endl;
}	
  
}
