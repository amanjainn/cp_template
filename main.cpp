/*
 Date: 10-06-2020
 Author: Aman jain
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define REP(a, n) for (int i = a; i < n; i++)
#define pb(a) push_back(a)
#define mod 1000000007
const char nl ='\n';


 
 
typedef long long ll;
typedef long l;
typedef unsigned long long ull;
typedef vector<int> V;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef map<int,int> Map;
 
// Input/output
void IO(){
  #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
 #endif
}
 
// Returns true if str1 is smaller than str2, 
// else false. 
bool isSmaller(string str1, string str2) {  
  int n1 = str1.length(), n2 = str2.length(); 
    if (n1 < n2)  return true; 
    if (n2 > n1)  return false;  
    for (int i=0; i<n1; i++) { 
        if (str1[i] < str2[i]) return true; 
        else if (str1[i] > str2[i]) return false;} 
    return false; 
} 
  
// Function for finding difference of larger numbers 
string findDiff(string str1, string str2) 
{    if (isSmaller(str1, str2)) 
        swap(str1, str2); 
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n1 - n2;int carry = 0; 
    for (int i=n2-1; i>=0; i--) { 
        int sub = ((str1[i+diff]-'0') -   (str2[i]-'0') - carry); 
        if (sub < 0) { sub = sub+10; carry = 1; } 
        else carry = 0; 
        str.push_back(sub + '0'); } 
    for (int i=n1-n2-1; i>=0; i--) { 
        if (str1[i]=='0' && carry) { 
            str.push_back('9');continue; } 
        int sub = ((str1[i]-'0') - carry); 
        if (i>0 || sub>0) 
            str.push_back(sub+'0'); carry = 0; } 
    reverse(str.begin(), str.end());  
    return str; 
} 



int toi(string s){
  int r=s[0]-'0';
  for(int i=1;i<s.length();i++)
    r*=10,r+=s[i]-'0';
  return r;
}
 
// Interger t
string tos(int n){
  string r;
  while(n>9){
    r.push_back(n%10+'0');
    n/=10;
  }
  r.push_back(n%10+'0');
  reverse(r.begin(),r.end());
  return r;
}
 
// Sum of two strings
string sum(string s,string p,int m=10,char z='0'){
  string r;
  int b=0;
  reverse(s.begin(),s.end());
  reverse(p.begin(),p.end());
  if(s.size()<p.size())s.swap(p);
  for(int i=0;i<s.size();i++){
    if(i>=p.size()){
      r.push_back((s[i]-z+b)%m+z);
      if(s[i]-z+b>=m)b=1;
      else b=0;
    }
    else{
      r.push_back((p[i]-z+s[i]-z+b)%m+z);
      if(p[i]-z+s[i]-z+b>=m)b=1;
      else b=0;
    }
  }
  if(b>0)r.push_back(b+z);
  reverse(r.begin(),r.end());
  return r;
}
 
// Multiply int to a string
string multiplyint(string s,int n){
  string r=tos((s[0]-'0')*n);
  for(int i=1;i<s.length();i++){
    r.push_back('0');
    r=sum(r,tos((s[i]-'0')*n));
  }
  return r;
}
 
 
// Multiply two strings
string multiply(string s,string p){
  string r=multiplyint(p,s[0]-'0');
  for(int i=1;i<s.length();i++){
    r.push_back('0');
    r=sum(r,multiplyint(p,s[i]-'0'));
  }
  return r;
}
 
 
 
//Check for prime
 bool isPrime(int num){
   if(num==1)
    return false;
    for(int i=2 ; i*i<num ; i++)
      if(num%i==0)
       return false;  
    return true;
 }
 
vll prime;


//SieveofEratosthenes
  void sieveofEratosthenes(ll maxn= 5000000){
   int is_prime[maxn];
      for(ll i=0; i<=maxn ; i+=1){is_prime[i]=1;}
        is_prime[0]=is_prime[1]=0;
 
        for(ll i=2 ; i*i<=maxn  ;i+=1){
          if(is_prime[i]){
           for(int j= i*i; j<=maxn ; j+=i){
             is_prime[j]=0;
         }}
     }
     REP(0,maxn)if(is_prime[i]==1)prime.pb(i);
   }

//SegmentedSieve
 void segmentedSieve(ll L, ll R){
   if(L==1)L++;
    int maxN =R-L+1;
     vll v(maxN,0);
    for(ll i :prime){
       if(i*i<=R){
          int start= (L/i)*i;
          if(start<L)start+=i;
         for(int j=start ; j<=R;j+=i){
          if(j!=i)
          v[j-L]=1;
           }}
    } REP(0,maxN)if(v[i]==0)cout<<L+i<<nl;
 }
 
// Prime factorization
void primeFactor(ll num){
    vector<pair<int,int>> factors;
    int count =0;
    for(int i=2 ;i*i<=num ; i++){
      count=0;
       if(num%i==0){
         while(num%i==0){
           num/=i;
           count++;
         }
       factors.push_back(make_pair(i,count));}
       }
    if(num!=1)factors.push_back(make_pair(num,1));
}


 
// Power function
ll power(ll a, ll n){
   if(n==1)return 1;
   ll res=1;
   while(n>0){
     if(n & 1)  
      res*=a;
      n=n>>1;
    a*=a;
   }  return res;
}
 
// Breadth first Search
void BFS(vector<int> Graph[],int s, int n){
     bool visited[n];
     queue<int> qu;
     qu.push(s);

     visited[s]=true;     
     while(!qu.empty()){
         int curr= qu.front();
         qu.pop();
         cout<<curr<<" ";
         for(auto itr=Graph[curr].begin() ; itr!=Graph[curr].end() ;++itr){
           if(visited[*itr]==false){
             qu.push(*itr);
             visited[*itr]=true;
           }
         }
     }
}
  
  

void SBFS(int s,int d, int n,vector<int>Graph[]){
     bool visited[n];
     queue<int> qu;
     qu.push(s);
     
     visited[s]=true;     
     while(!qu.empty()){
         int curr= qu.front();
         qu.pop();
         cout<<curr<<" ";
         for(auto itr=Graph[curr].begin() ; itr!=Graph[curr].end() ;++itr){
           if(visited[*itr]==false){
             qu.push(*itr);
             visited[*itr]=true;
           }
         }
     }
}




int main(){
  IO();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  


      

}
 