#include <iostream>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int
#define dl double
#define st string
#define vll vector<ll>
#define qll queue<ll>
#define stll stack<ll>
#define sll set<ll>
#define sts set<string>
#define vs vector<string>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define msl map<string, ll>
#define vecp vector<pair<ll, ll>>
#define vecpp vector<pair<ll, pair<ll, ll>>>
#define pb push_back
#define pf push_front
#define in insert
#define eb emplace_back
#define ppb pop_back
#define ppf pop_front
#define etr vector<ll>::iterator
#define pi 3.141592653589793238
#define lln \
    ll n;   \
    cin >> n;
int prime[300000], nprime = 0;
int mark[10000002];
/******************NUMBER_THEORY*********************/
/********Fibonacci_Number**********/
 
/******Catalan_Number***********/
unsigned long int binomialcoeff(unsigned int n, unsigned int k)
{
    unsigned long int res = 1;
    if (k > n - k)
        k = n - k;
 
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
unsigned long int catalan(unsigned int n)
{
    unsigned long int c = binomialcoeff(2 * n, n);
 
    return c / (n + 1);
}
/******Trailing_zeros**********/
int trailingzeros(int n)
{
    if (n < 0)
        return -1;
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5)
    {
        count += n / i;
    }
    return count;
}
/**************Seive_prime**************/
void seive(int n)
{
    int i, j, limit = sqrt(n * 1.) + 2;
    mark[1] = 1;
    prime[nprime++] = 2;
    for (int i = 4; i <= n; i += 2)
        mark[i] = 1;
    for (int i = 3; i <= n; i += 2)
    {
        if (!mark[i])
        {
            prime[nprime++] = i;
            if (i <= limit)
            {
                for (j = i * i; j <= n; j += i * 2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < nprime; i++)
        cout << prime[i] << " ";
 
    cout << endl;
}
 
/***********Prime_Number**************/
bool isprime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
/***********Circular_prime***********/
int checkprime(ll n)
{
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
ll circularprime(ll n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    ll temp = n;
    ll d = 0;
    while (temp > 0)
    {
        if (temp % 2 == 0)
            return 0;
        temp /= 10;
        d++;
    }
 
    ll q = pow(10, d - 1);
    for (int i = 0; i < d; i++)
    {
        if (!checkprime(n))
            return 0;
        ll rem = n % 10;
        n = n / 10;
        n = (q * rem) + n;
    }
    return 1;
}
/***********prime_factor *******/
void primefactor(int n)
{
 
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n > 2)
        cout << n << " ";
    cout << endl;
    return;
}
/******Two_Prime_factor*****/
void twoprimfact(int n)
{
    int y = 1;
    double x;
    int d;
    while (1)
    {
        d = n + y * y;
        x = sqrt(d);
        if (x == floor(x))
        {
            x = floor(x);
            break;
        }
        y++;
    }
    cout << (x + y) << " " << (x - y) << endl;
}
/**********Prime factor stores smallest prime factor its previous*************/
#define maxn 100001
int spf[maxn];
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < maxn; i++)
        spf[i] = i;
 
    for (int i = 4; i < maxn; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i < maxn; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < maxn; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
vector<int> getfactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
/***********Euler's_Totient_function**********/
int Eulerstotient(ll n)
{
    ll res = n;
    for (ll i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
 
            res -= res / i;
        }
    }
    if (n > 1)
        res -= res / n;
 
    return res;
}
/****find_ax+by=n*******/
void findaxby(int a, int b, int n)
{
    for (int i = 0; i * a <= n; i++)
    {
        if ((n - (a * i)) % b == 0)
        {
            cout << "x= " << i << " y= " << (n - (a * i)) / b << endl;
            return;
        }
    }
    cout << "No soluation" << endl;
    return;
}
/*******Lucky_Number**********/
void LuckyNumber(int n)
{
    int a = 0, b = 0, sum = n;
    while (sum > 0)
    {
        if (sum % 4 == 0)
        {
            a++;
            sum -= 4;
        }
        else if (sum % 7 == 0)
        {
            b++;
            sum -= 7;
        }
        else
        {
            a++;
            sum -= 4;
        }
    }
    if (sum < 0)
    {
        cout << "-1n" << endl;
        return;
    }
    for (int i = 0; i < a; i++)
        cout << "4";
    for (int i = 0; i < b; i++)
        cout << "7";
 
    cout << endl;
}
/**************plaindom_int***********/
bool palindom(int n)
{
    int num, digit, rev = 0;
    num = n;
    do
    {
        digit = n % 10;
        rev = (rev * 10) + digit;
        n = n / 10;
 
    } while (n != 0);
    if (num == rev)
        return true;
    else
        return false;
}
 
/************power_x^y%m*************/
int power(long long x, unsigned y, int m)
{
    int res = 1;
    x = x % m;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % m;
 
        y = y >> 1;
        x = (x * x) % m;
    }
    return res;
}
/************a^2+b^2=n*/
void sumequalton(ll n)
{
    int cunt = 0;
    while (n % 2 == 0)
    {
        cunt++;
        n /= 2;
    }
    if (cunt % 2 != 0)
    {
        cunt--;
        n *= 2;
    }
    ll even = 1LL << (cunt / 2);
    int a = -1, b = -1;
    for (int i = 0; i * i <= n; i++)
    {
        ll x = n - i * i;
        ll y = sqrt(x);
        if (y * y != x)
            y++;
        if (y * y != x)
            continue;
        a = i;
        b = y;
        break;
    }
    if (a == -1)
        cout << "-1" << endl;
    else
        cout << even * a << " " << even * b << endl;
 
    return;
}
 
/*************sum_digit*********/
int sumofdigit(int n)
{
    if (n == 0)
        return 0;
 
    return (n % 10) + sumofdigit(n / 10);
}
 
/********* Divisible_3_return 1 or 0*******/
int dividesby3(int n)
{
    int odd_count = 0;
    int even_count = 0;
    if (n < 0)
        n = -n;
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;
    while (n)
    {
        if (n & 1)
            odd_count++;
        if (n & 2)
            even_count++;
        n = n >> 2;
    }
    return dividesby3(abs(odd_count - even_count));
}
/******factorial******/
int fact(int n)
{
    if (n == 0)
        return 1;
 
    return n * fact(n - 1);
}
/*******GCD***********/
int gcd(int a, int b)
{
 
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
/*********LCM*********/
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
/***********************SEARCHING ALGORITHM***********************/
 
/****************Linear_search**********/
bool Linears_search(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
            return true;
    }
    return false;
}
/**************Binary_Search***************/
int Binary_search(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return Binary_search(arr, l, mid - 1, x);
 
        return Binary_search(arr, mid + 1, r, x);
    }
    return -1;
}
/**********Jumping_Search**********/
int Jumping_Search(int arr[], int x, int n)
{
 
    int step = sqrt(n);
    int prev = 0;
    while (arr[min(step, n) - 1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }
    while (arr[prev] < x)
    {
        prev++;
        if (prev == min(step, n))
            return -1;
    }
    if (arr[prev] == x)
        return 1;
 
    return -1;
}
/**********Finde Euniq element from a array by using XOR operator***********/
void uniqelemnt()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int res = 0;
    for (int &i : a)
    {
        cin >> i;
        res ^= i;
    }
    cout << res << endl;
}
 
/********Interpolation_Search**********/
bool Interpolation_Search(int arr[], int n, int x)
{
    int l = 0, h = n - 1;
    while (l <= h && x >= arr[l] && x <= arr[h])
    {
        if (l == h)
        {
            if (arr[l] == x)
            {
                return true;
            }
            return false;
        }
        int pos = l + (((double)(h - l) / (arr[h] - arr[l])) * (x - arr[l]));
        if (arr[pos] == x)
            return true;
 
        if (arr[pos] < x)
            l = pos + 1;
 
        else
            h = pos - 1;
    }
    return false;
}
 
/************ Pattern_Searching****************/
 
/************KMP_algorithm**************/
vector<int> LPS(string pat)
{
 
    vector<int> lps(pat.length());
    int index = 0;
    for (int i = 1; i < pat.length();)
    {
        if (pat[index] == pat[i])
        {
            lps[i] = index + 1;
            index++, i++;
        }
        else
        {
            if (index != 0)
            {
                index = lps[index - 1];
            }
            else
            {
                lps[i] = index, i++;
            }
        }
    }
 
    return lps;
}
bool kmp(string txt, string pat)
{
    vector<int> lps = LPS(pat);
    bool flag = false;
    int i = 0, j = 0;
    while (i < txt.length())
    {
        if (txt[i] == pat[j])
        {
            i++, j++;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
        if (j == pat.length())
        {
           // cout << "Found at Index " << i - pat.length() << endl;
           return true;
            j = lps[j - 1];
            flag = true;
        }
    }
    // if (!flag)
    // {
    //     //cout << "Not found" << endl;
    //     return false;
    // }
    return false;
}
 
/******get Z array******/
void getzarr(string str,vector<int>&z){
    int n=str.length();
    int l,r,k;
    l=r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n&&str[r-l]==str[r])
            r++;
 
            z[i]=r-l;
            r--;
        }
        else{
            k=i-l;
            if(z[k]<r-i+1)
            z[i]=z[k];
 
            else{
                l=i;
                while(r<n&&str[r-l]==str[r])
                r++;
 
                z[i]=r-l;
                r--;
            }
        }
    }
 
}
void search(string text,string pattern){
    string concat=pattern+"$"+text;
    int n=concat.length();
    vector<int>z(n);
    getzarr(concat,z);
    for(int i=0;i<n;i++){
        if(z[i]==pattern.length()){
            cout<<"Pattern found at index"<<i-pattern.length()-1<<endl;
 
        }
    }
}
/**********Manacher's algorithm(This code is run only java mode)********/
// int checkcenter(String str,int i,int j){
//     while(i>=0&&j<str.length()&&str.charAt(i)==str.charAt(j)){
//         i--;j++;
//     }
//     return j-i-1;
// }
// String manachersalgo(String str){
//     int s=0,e=0;
//     for(int i=0;i<str.length();i++){
//         int len1=checkcenter(str,i,i);
//         int len2=checkcenter(str,i,i+1);
//         int len=Math.max(len1,len2);
//         if(e-s<len){
//             s=i-(len-1)/2;
//             e=i+len/2;
//         }
//     }
//     return str.substring(s,e+1);
 
// }
 
 
 
/****************Bitwise_operation************/
 
/*********************SetBit***************/
void setbit(int n)
{
    vector<int> mem(n + 1);
    mem[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        mem[i] = mem[i / 2] + i % 2;
    }
    for (auto x : mem)
        cout << x << " ";
    cout << endl;
}
int SetBit(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (n & 1)
            count++;
        n >>= 1;
    }
    return count;
}
//__builtin_popcount(n);
int Brian_keringhan(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        cnt++;
    }
    return cnt;
}
/******Count_setbit_from_1_to_N*******/
vector<int> countsetbit(int n)
{
    vector<int> mem(n + 1);
    mem[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        mem[i] = mem[i / 2] + i % 2;
    }
    return mem;
}
/****************Sorting_Algorithm************/
 
 
 
 
/**********Sliding window techniques****/
 
 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty()&&dq.front()==i-k)
            dq.pop_front();
 
            while(!dq.empty() && nums[dq.back()]<nums[i])
            dq.pop_back();
 
            dq.push_back(i);
 
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
 
 
        }
        return ans;
}
 
 
 
 
 
 
map<int, int> frequency(int arr[], int n)
{
    map<int, int> mark;
    for (int i = 0; i < n; i++)
    {
        mark[arr[i]]++;
    }
    return mark;
}
/********Find right intervals*********/
 
int binary_search(vector<pair<pair<int,int>,int>>& sorted,int x){
    int n=sorted.size();
    if(sorted[n-1].first.first<x)return -1;
 
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(sorted[mid].first.first>=x)r=mid-1;
        else
        l=mid+1;
 
    }
    return sorted[l].second;
}
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<pair<int,int>,int>>sorted;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            sorted.push_back({{intervals[i][0],intervals[i][1]},i});
 
        }
        sort(sorted.begin(),sorted.end());
 
        vector<int>result(n,-1);
        for(int i=0;i<n;i++){
            result[i]=binary_search(sorted,intervals[i][1]);
        }
        return result;
        
    }
 
/*Meet in the middle algorithm*********/
// ll x[2000005],y[2000005];
// void calsubsum(ll arr[],ll x[],int n,int c){
//     for(int i=0;i<(1<<n);i++){
//         ll s=0;
//         for(int j=0;j<n;j++){
//             if(i&(1<<j))
//             s+=arr[j+c];
//         }
//         x[i]=s;
//     }
// }
// ll mettinthemiddle(ll arr,int n,ll s){
//    calsubsum(arr,x,n/2,0);
//    calsubsum(arr,y,n-n/2,n/2);
//    int size_x=1<<(n/2);
//    int size_y=1<<(n-n/2);
 
//    sort(y,y+size_y);
//    ll maxi=0;
//    for(int i=0;i<size_x;i++){
//     if(x[i]<=s){
//         int p=lower_bound(y,y+size_y,s-x[i])-y;
//         if(p==size_y||y[p]!=(s-x[i]))
//         p--;
 
//         if((y[p]+x[i]>maxi))
//         maxi=y[p]+x[i];
//     }
//    }
//    return maxi;
 
// }
 
 
 
 
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll maxi,mini;
        maxi=max(a,max(b,c));
        mini=min(a,min(b,c));
        ll f=(a+b+c)-(maxi+mini);
        ll count=0;
        bool flag=true;
        while(mini<maxi){
            count++;
            maxi-=mini;
            if(count>3||maxi<mini){ 
                flag=false;
 
            }
 
        }
        if(flag){
            while(mini<f){
                count++;
                f-=mini;
                if(count>3||f<mini){
                    flag=false;
                }
            }
        }
 
        if(flag==true&& count<=3){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
 
        
 
    }
}
int main()
{
    solve();
}