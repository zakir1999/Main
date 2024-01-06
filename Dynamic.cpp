#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
/****Fibonacci_Number****/
int fibonacci(int n, vector<int> &dp)
{
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
/******FrogJump*******/
int frog(int ind, vector<int> &height, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int left = frog(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
    {
        right = frog(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
    }
    return dp[ind] = min(left, right);
}
/***************Maximum sum of non adjacent number***************/
ll sumofnonad(vector<ll> &nums)
{
    ll n = nums.size();
    ll prev = nums[0];
    ll prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        ll take = nums[i];
        if (i > 1)
            take += prev2;

        ll nottake = 0 + prev;
        ll carry = max(take, nottake);
        prev2 = prev;
        prev = carry;
    }
    return prev;
}
/***********Ninja's Training*********/
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task <= 2; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int maxi = 0;
    for (int task = 0; task <= 2; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + f(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}
int ninjastrianing(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n - 1, 3, points, dp);
}
/******************Grid Uniq paths********************/
/**        Recursion       **/
int GriduniqPathre(int i, int j)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    int up = GriduniqPathre(i - 1, j);
    int left = GriduniqPathre(i, j - 1);
    return up + left;
}
/******    Dp      *********/
int Griduniqpathdp(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = Griduniqpathdp(i - 1, j, dp);
    int left = Griduniqpathdp(i, j - 1, dp);
    return dp[i][j] = left + up;
}
/******   memoization/tabulation    ******/
int Griduniqpathtb(int n, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = left + up;
            }
        }
    }
    return dp[n - 1][n - 1];
}
/*********** Subset Sum Equals to Target******************/
/********Recursion*********/
bool fun(int n, int k, vector<int> &arr)
{
    /****Base case*****/
    if (k == 0)
        return true;
    if (n == 0)
        return arr[0] == k;

    bool nottake = fun(n - 1, k, arr);
    bool take = false;
    if (k >= arr[n])
    {

        take = fun(n - 1, k - arr[n], arr);
    }
    return take | nottake;
}
/********DP*************/
bool dpfun(int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    /**Base case**/
    if (k == 0)
        return true;
    if (n == 0)
        return arr[0] == k;
    if (dp[n][k] != -1)
        return dp[n][k];
    bool nottake = dpfun(n - 1, k, arr, dp);
    bool take = false;
    if (k >= arr[n])
    {
        take = dpfun(n - 1, k - arr[n], arr, dp);
    }
    return dp[n][k] = nottake | take;
}
/*****tabulationmethod******/
bool tabsumofset(int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool nottake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= k)
                take = dp[i - 1][j - arr[i]];
            dp[i][j] = take | nottake;
        }
    }
    return dp[n - 1][k];
}
/*********Count of subsets************/
/************DP**********/
int countofsubset(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;

    if (ind == 0)
    {
        if (arr[0] == sum)
            return 1;
        else
            return 0;
    }
    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    int nottake = countofsubset(ind - 1, sum, arr, dp);
    int take = 0;
    if (arr[ind] <= sum)
    {
        take = countofsubset(ind - 1, sum - arr[ind], arr, dp);
    }
    return dp[ind][sum] = take + nottake;
}
/*******Longest common subsequence*********/
/*******Recurrsion*******/
int lcsfun(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
        return dp[i][j] = 1 + lcsfun(i - 1, j - 1, s, t, dp);
    else
    {
        return dp[i][j] = 0 + max(lcsfun(i - 1, j, s, t, dp), lcsfun(i, j - 1, s, t, dp));
    }
}

/*****Iteration******/
int lcs(string s, string t)
{

    int i = s.length(), j = t.length();
    vector<vector<int>> dp(i + 1, vector<int>(j + 1, 0));
    for (int a = 0; a < j; a++)
    {
        dp[0][a] = 0;
    }
    for (int b = 0; b < i; b++)
    {
        dp[b][0] = 0;
    }
    for (int a = 1; a <= i; a++)
    {
        for (int b = 1; b <= j; b++)
        {
            if (s[a - 1] == t[b - 1])
                dp[a][b] = 1 + dp[a - 1][b - 1];
            else
                dp[a][b] = max(dp[a - 1][b], dp[a][b - 1]);
        }
    }

    return dp[i][j];
}
/********Print Lcs******/
void printlcs(string s, string t)
{
    int i = s.length(), j = t.length();
    vector<vector<int>> dp(i + 1, vector<int>(j + 1, 0));
    for (int a = 0; a < j; a++)
    {
        dp[0][a] = 0;
    }
    for (int b = 0; b < i; b++)
    {
        dp[b][0] = 0;
    }
    for (int a = 1; a <= i; a++)
    {
        for (int b = 1; b <= j; b++)
        {
            if (s[a - 1] == t[b - 1])
                dp[a][b] = 1 + dp[a - 1][b - 1];
            else
                dp[a][b] = max(dp[a - 1][b], dp[a][b - 1]);
        }
    }
    int len = dp[i][j];
    string str = "";
    for (int i = 0; i < len; i++)
    {
        str += '$';
    }
    int index = len - 1;

    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            str[index] = s[i - 1];
            index--;
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
            j--;
    }
    cout << str << endl;
}
/********Shortest Common Supersequence**********/
string shcmspseq(string s, string t)
{
    int i = s.length(), j = t.length();
    vector<vector<int>> dp(i + 1, vector<int>(j + 1, 0));
    for (int a = 0; a < j; a++)
    {
        dp[0][a] = 0;
    }
    for (int b = 0; b < i; b++)
    {
        dp[b][0] = 0;
    }
    for (int a = 1; a <= i; a++)
    {
        for (int b = 1; b <= j; b++)
        {
            if (s[a - 1] == t[b - 1])
                dp[a][b] = 1 + dp[a - 1][b - 1];
            else
                dp[a][b] = max(dp[a - 1][b], dp[a][b - 1]);
        }
    }
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans += s[i - 1];
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += s[i - 1];
            i--;
        }
        else
        {
            ans += t[j - 1];
            j--;
        }
    }
    while (i > 0)
    {
        ans += s[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += t[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
/************Stocks buy and selling ****************/
int stocks(vector<int> &price, int n)
{
    int mini = price[0];
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = price[i] - mini;
        mini = min(mini, price[i]);
        profit = max(profit, cost);
    }
    return profit;
}
/***********Anytime buy any time sell***********/
/********Recurrsion*******/
int anybuy(int ind, int buy, vector<int> &price, int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    int profit = 0;
    if (buy)
    {
        profit = max(-price[ind] + anybuy(ind + 1, 0, price, n, dp), 0 + anybuy(ind + 1, 1, price, n, dp));
    }
    else
    {
        profit = max(price[ind] + anybuy(ind + 1, 1, price, n, dp), 0 + anybuy(ind + 1, 0, price, n, dp));
    }
    return dp[ind][buy] = profit;
}
/*********Tabulation ***********/
int tabanybuy(vector<int> &price, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max(-price[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
            }
            else
            {
                profit = max(price[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}
/*************LIS******************/
/******DP*******/
int fun(int ind, int prev, int n, vector<int> &heights, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];
    int len = 0 + fun(ind + 1, prev, n, heights, dp);
    if (ind == -1 || heights[ind] > heights[prev])
    {
        len = max(len, 1 + fun(ind + 1, ind, n, heights, dp));
    }
    return dp[ind][prev + 1] = len;
}
/*************Tabulation**************/
int listab(int arr[], int n)
{
    vector<int> dp(n, 1);
    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(dp[i], maxi);
    }
    return maxi;
}
/********Lis by Binarysearch***************/
int lisbinary(vector<int> arr, int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return temp.size();
}
/******Print LIS*****/
void lisprint(vector<int> arr, int n)
{
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastindex = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastindex = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastindex]);
    while (hash[lastindex] != lastindex)
    {
        lastindex = hash[lastindex];
        temp.push_back(arr[lastindex]);
    }
    reverse(temp.begin(), temp.end());
    for (auto it : temp)
        cout << it << " ";

    cout << endl;
}
/*******Divisibleset**********/
vector<int> divisibleSet(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastindex = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] % arr[prev] == 0 && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastindex = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastindex]);
    while (hash[lastindex] != lastindex)
    {
        lastindex = hash[lastindex];
        temp.push_back(arr[lastindex]);
    }
    reverse(temp.begin(), temp.end());

    return temp;
}
/*************partition Dp***************/
/**********Matrix Chain Multipication***********/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> price(n);
        for (auto &x : price)
            cin >>x;


        for(auto it:price){
            cout<<it<<endl;
        }
    }
}