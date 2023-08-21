#include<bits/stdc++.h>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	vector<int> v;
	int n, x, res=0, isFlag=false;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>x;
		v.push_back(x);
		cout<<x;
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0; i<n; i++){
		isFlag=false;
		if(n>=v[i]){
			for(int j=i; j<i+v[i]; j++){
				if(v[j]==v[i]) isFlag = true;	
			}
			if(isFlag){
				n-=v[i];
				res++;
			} 
		}
		else continue;
	}
	cout<<res;
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

int main(){
	cin>>n;

	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		arr.push_back(x);
	}
	
	sort(arr.begin(), arr.end());
	
	int result = 0; //총 그룹 수 
	int cnt = 0; //현재 그룹에 포함된 모험가 수 
	for(int i=0; i<n; i++){
		cnt += 1; //현재 그룹에 해당 모험가 포함시키기
		if(cnt >= arr[i]) { //현재 그룹에 포함된 모험가 수가 현재 공포도 이상이면 그룹 결성 
			result +=1; //총 그룹 수 증가
			cnt = 0; //현재 그룹에 포함된 모험가 수 초기화   
		} 
			
	} 
	
	cout<<res;
	return 0;
}
