#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <unordered_map>
 
 
#define sync ios_base::sync_with_stdio
#define endl '\n'
 
using namespace std;
set <string> ans;char word[200007];
vector <string> v;
 
struct Trie
{
    bool isLeaf;    // true when node is a leaf node
    
    // each node stores a map to its child nodes
    unordered_map<char, Trie*> map;
};
 struct Trie temp[200007];
 int p = 0;
// Function that returns a new Trie node
Trie* getNewTrieNode()
{
    temp[p].isLeaf = false;
   
    p++;
    return &temp[p-1];
}
 
// Iterative function to insert a string in Trie.
void insert(Trie* head, char* str ,int type)
{
    // start from root node
    Trie* curr = head;
    while (*str)
    {
        // create a new node if path doesn't exists
        if (curr->map.find(*str) == curr->map.end())
            curr->map[*str] = getNewTrieNode();
 
        // go to next node
        curr = curr->map[*str];
        if(type == 1)
          curr -> isLeaf = true;
        // move to next character
        str++;
    }
}
// Iterative function to search a string in Trie. It returns true
// if the string is found in the Trie, else it returns false
int search(Trie* head, string str)
{
    // return false if Trie is empty
    if (head == NULL)
        return false;
    int i=0;
    Trie* curr = head;
    int len = str.size();
    while (i<len)
    {
        // go to next node
        curr = curr->map[str[i]];
         if(curr ->isLeaf == false)
        {
          string inp(str,0,i+1);
          ans.insert(inp);
          break;
        }
 
        // move to next character
        i++;
    }
    if(i==len)
  {
    cout << "-1" << endl;
    return -1;
  }
  return 0;
 
    // if current node is a leaf and we have reached the
    // end of the string, return true
    
}
int main()
{
  sync;
  int n;
  Trie* head = getNewTrieNode();
  cin >> n;
  int val = 0;
   int j = 0;
  for(int i=0;i<n;i++)
  {
    //scanf("%[^\n]s",word);
    //cin.getline(word,sizeof(word));
    
    char ch,e;
    cin >> ch >> word;
    if(ch == '-'){
       v.push_back(word);
       insert(head , word,0);
       j++;
       }
    //cout << "Root " << root << endl;
    else
      insert(head , word,1);
   
  }
  //sort(v.begin(),v.end(),acompare);
  for(int i=0;i<v.size();i++)
  {
    int flag = search(head,v[i]);
    if(flag == -1)
      return 0;  
  }
  cout << ans.size() << endl;
  for(set <string> :: iterator itr = ans.begin();itr!=ans.end();itr++)
  {
    cout << *itr << endl;
  }
} 
