#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll ;
ll MOD = 1000000007;

/*

	UBER QUESTION-1
*/
int main(){

	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


   int n;
   cin >> n;
   int ar[n];
   set<int> vals;
   for(int i=0;i<n;i++){
        cin >> ar[i];
        vals.insert(ar[i]);
   }      
   const int MAX_VAL = 40000;
   int prev[n][MAX_VAL+1];
   int ans[n][MAX_VAL+1];
   memset(prev, -1, sizeof(prev));
   int longest = (n == 1) ? 1 : 2;
   for(int i=0;i<n;i++){
        
        for(auto &x : vals){
            if(i > 0){
                prev[i][x] = prev[i-1][x];
            }
            ans[i][x] = 1;
        }
        if(prev[i][ar[i]] == -1){
            prev[i][ar[i]] = i;
            continue;
        } // it would be the first instance and hence won't do anything to final answer
        prev[i][ar[i]] = i;
        for(auto &other : vals){
            if(other != ar[i]){
                int prevOtherIndex = prev[i][other]; 
                if(prevOtherIndex != -1){
                    int prevSameIndex = prev[prevOtherIndex][ar[i]];
                    if(prevSameIndex != -1){
                        ans[i][other] = 2+ans[prevSameIndex][other];
                        cout << ans[i][other] << " for i=" << i << " other=" << other << "\n";
                        longest = max(longest, ans[i][other]);
                    }
                }
            }
        }

   }
   cout << longest << "\n";
}
