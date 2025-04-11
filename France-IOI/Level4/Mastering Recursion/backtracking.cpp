#include <bits/stdc++.h>
using namespace std;
string letters;
int lettersSize;
map<char,bool>mp;
vector<string>ans;
void recursion(int n,string s,int cnt)
{
    if (cnt==n)
    {
        ans.push_back(s);
        return;
    }
    for(int i=0;i<lettersSize;i++)
    {
        if(!mp[letters[i]])
        {
            mp[letters[i]]=true;
            recursion(n,s+letters[i],cnt+1);
            mp[letters[i]]=false;
        }
    }
}
int main()
{
    cin>>lettersSize;
    cin>>letters;
    int n;
    cin>>n;
    recursion(n,"",0);
    cout<<ans.size()<<endl;
    for(auto i:ans)
    {
        cout<<i<<endl;
    }
}