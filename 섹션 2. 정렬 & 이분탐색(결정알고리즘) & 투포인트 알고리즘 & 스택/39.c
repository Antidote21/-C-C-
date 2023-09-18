#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("input.txt","rt", stdin);
	int n, m, i, j,min=999;
	scanf("%d",&n);
	vector<int> a(n);
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	vector<int> b(m);
	for(i=0; i<m; i++){
		scanf("%d",&b[i]);
	}
	vector<int> c(n+m);
	
	for(i=0;i<m+n;i++){
		if(i<n){
			c[i]=a[i];
		}
		else{
			c[i]=b[i-n];
		}
	}
	sort(c.begin(),c.end());

	for(i=0;i<m+n;i++){
		printf("%d ", c[i]);
	}
	return 0;
}

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[101], b[101], c[300];
int main(){
	//freopen("input.txt","rt", stdin);
	int n, m, i, p1=1, p2=1, p3=1;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(i=1; i<=m; i++){
		scanf("%d", &b[i]);
	}
	while(p1<=n&&p2<=m){
		if(a[p1]<b[p2]){
			c[p3++]=a[p1++];
		}
		else{
			c[p3++]=b[p2++];
		}
	}
	
	for(i=p1+p2;i<m+n+2;i++){
		if(p1<=n){
			c[p3++] = a[p1++];
		}
		else if(p2<=m){
			c[p3++] = b[p2++];
		}
	}
		
	for(i=1;i<p3;i++){
		printf("%d ", c[i]);
	}
	return 0;
}

#include<stdio.h>
//a1과 b1이 각각이 오름차순인 상태에서 비교된 문제
//투 포인터를 활용해서 오름차순인 배열을 만드는 문제이다. 
int main(){
	//freopen("input.txt","rt", stdin);
	int a[101];
	int b[101];
	int c[300];
	int i, n, m, p1=1, p2=1;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	scanf("%d", &m);
	for(i=1;i<=m; i++)
	{
		scanf("%d",&b[i]);
	}
	
	for(i=1;i<=n+m; i++){ 
		if(p1<=n && p2<=m){ //하나의 배열이 먼저 끝나면 나머지 배열 원소를 순서대로 집어넣으면 된다.  
			if(a[p1]>=b[p2]){//a의 배열 값이 b의 배열 값보다 크면 더 작은 b의 배열 값을 집어넣고 p2를 증가시킨다.  
				c[i]=b[p2++];
			}
			else{ 
				c[i]=a[p1++];
			}
		}else if(p1<=n){ //b의 배열이 끝나면 남은 a의 배열의 원소를 순차적으로 c배열에 넣어 완성시킨다. 
			c[i]=a[p1++];
		}else{
			c[i]=b[p2++];
		} 
		printf("%d ", c[i]);//완성되는 c배열의 값을 출력한다. 
	}
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;
int a[100];
int b[100];

int main()
{
    int n, m, p1=0, p2=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    vector<int> c;
    
    while(p1<n && p2<m){
        if(a[p1]<b[p2]){
            c.push_back(a[p1++]);
        }
        else{
            c.push_back(b[p2++]);
        }       
    }
    
    while(p1<n)c.push_back(a[p1++]);
    while(p2<m)c.push_back(b[p2++]);
    
    for(int i=0; i<c.size(); i++)cout<<c[i];

    return 0;
}

