#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<map>
#define int long long 
#define MOD 1000000007
#define MOD2 1000000014000000049L
#define PI 3.1415926535
#define INF 1e18 
#define ve vector
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define bs binary_search
#define all(a) (a).begin(),(a).end()
#define lb lower_bound
#define ub upper_bound
#define mxe(a) *max_element(a.begin(),a.end())
#define mne(a) *min_element(a.begin(),a.end())
#define removeDuplicates(a) a.resize(unique(all(a))-a.begin())
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(g, i, n) for (int g = i; g < n; g++)
#define rev(g, n, i) for (ll g = n - 1; g >= i; g--)
using namespace std;
#define DEBUG(x) do { std::cerr <<#x<<":"<< x<<"   "; } while (0)
//===================================================================================================================
// THE FIRST PRINCIPLE, IS THAT YOU MUST NOT FOOL YOURSELF, AND YOU ARE THE EASIEST PERSON TO FOOL- Richard Feynman.
// ******************************************************************************************************************
void solve()
{
    string s,t;
    cin>>s>>t;
    int n=s.length(),m=t.length();
    vector<int> r(m);
    for(int i=m-1;i>=0;i--){
        int j=n-1;
        if(i+1<m)
            j=r[i+1]-1;
        while(s[j]!=t[i])
            j--;
        r[i]=j;
    }
    // r contains the rightmost index such that t[i->end]=substring of s[r->end]
    // r[0] will contain rightmost index of s, st. s[r[0]->end] will contain t as a subsequence
    // Therefore we can delete from [0->r[0]-1]
    int answer=0;
    int j=0;
    for(int i=0;i<n;i++){
        int rpos=n-1;
        if(j<m)
            rpos=r[j]-1;// less than required for jth character, so that we can delete that segment
        answer=max(answer,rpos-i+1);
        if(j<m && s[i]==t[j])// Only if we got that character from here, we can increase j
            j++;           
    }   
    cout<<answer<<endl;

}
signed main() 
{ 
    FAST;
    solve();
    return 0; 
} 



// Paste for reading from input file
//#ifndef ONLINE_JUDGE
    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
//#endif




int power(int base, int exp) {
   int res=1;
   while(exp>0) {
      if(exp%2==1) res=(res*base)%MOD;
      base=(base*base)%MOD;
      exp/=2;
   }
   return res%MOD;
}






// sometimes I believe compiler ignores all my comments