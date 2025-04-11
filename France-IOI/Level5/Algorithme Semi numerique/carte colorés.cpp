#include "colors.h"
#include <vector>
using namespace std;
int ans=0;
void solve(int tab[] , int p) {
      
      int color[p];
      for(int i=0;i<p;i++){
      
         color[i]=tab[i];
      }
      
      for(int i=1;i<(1<<p);i++){
         
         vector<int>tmp;
         int cnt=0;
         for(int j=0;j<p;j++){
            
            if (i & (1<<j)){
               
               tmp.push_back(tab[j]);
               
               color[cnt]=tab[j];
               cnt++;
          
            }
            
         }
         
         if (cnt%2){
         
            ans+=question(color,cnt);
         }
         else{
         
         ans-=question(color,cnt);
         
         }
      }
      
     
      
}
int main() {
      
   int p;
   p=nbColors();
   int tab[p];
   for(int i=1;i<=p;i++){
      tab[i-1]=i;
   }
   
   solve(tab, p );
   
   answer(ans);
   
}