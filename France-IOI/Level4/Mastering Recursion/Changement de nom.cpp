#include <bits/stdc++.h>
using namespace std;
string letters;
int lettersSize;
//vector<string>ans;
void recursion(int n,string s,int cnt)
{
    if (cnt==n)
    {
        cout<<s<<endl;
        return;
    }
    for(int i=0;i<lettersSize;i++)
    {
        recursion(n,s+letters[i],cnt+1);
    }
}
int main()
{
    cin>>lettersSize;
    cin>>letters;
    int n;
    cin>>n;
    cout<<pow(lettersSize,n)<<endl;
    recursion(n,"",0);
}