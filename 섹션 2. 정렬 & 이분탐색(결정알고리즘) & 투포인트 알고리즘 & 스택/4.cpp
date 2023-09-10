#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); //C++ 스트림과 C 스트림을 동기화하지 않음 
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int n, res=0;
	cin>>n;
	vector<int> arr(n+1), dy(n+1);
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	dy[1]=1;
	//동적 프로그래밍 과정 
	for(int i=2; i<=n; i++){
		int max=0;
		for(int j=i-1; j>=1; j--){
			if(arr[j]<arr[i] && dy[j]>max){
				max=dy[j];
			}
		}
		dy[i]=max+1;
		if(dy[i]>res) res=dy[i];
	}
	cout<<res;
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int dp[100];
int arr[100];
int n;

void LIS() // Longest Increasing Subsequence
{
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    LIS();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(dp[i], res);
    }
    cout << res;
    return 0;
}
