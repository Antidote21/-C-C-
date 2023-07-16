#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
//합이 같다는 것은 전체 합/2라는 것인가?
//코드의 전반적인 느낌은 DFS를 활용하지 못한 채 억지로 끼워맞추는 느낌이 강하다.   
int sum1, sum2, j=1,m;
int a[11];
void recur(int n){//함수를 나타내는 이름 설정도 DFS로 변경해야 한다.  
	if(sum1==sum2||j==m){ //j는 Level을 나타내고 있으므로 변수이름을 L로 변경하는 것이 좋을 것 같다. 
		return;
	}else{ //코드 자체가 DFS를 아직 이해하지 못한 것 같음  
		sum2+=a[j];
		j++;
		if(sum2>sum1){
			sum2-=a[j];//특히 이 부분은 DFS의 원리를 이해하지 못해서 나온 코드임!  
		}
		recur(a[j]);
	}
}
 
int main(){
	freopen("input.txt","rt", stdin);
	scanf("%d", &m);
	int i;
	for(i=1;i<=m;i++){
		scanf("%d",&a[i]);//배열료 받는게 맞긴한가? 
		sum1+=a[i]; 
	}
	sum1/=2;
	recur(a[1]);//DFS라고 항상 매개변수를 한 개만 받는 것이 아니다.   
	if(sum1==sum2)printf("YES");
	else printf("NO");
	return 0; 
}

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, a[11], total=0;
bool flag=false;
void DFS(int L, int sum){
	if(sum>(total/2)) return;
	if(flag==true) return;
	if(L==n+1){
		if(sum==(total-sum)){
			flag=true;
		}
	}else{
		DFS(L+1, sum+a[L]);
		DFS(L+1, sum);
	}
}

int main(){
	freopen("input.txt","rt", stdin);
	int i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		total+=a[i];
	}
	DFS(1, 0);
	if(flag)printf("YES\n");
	else printf("NO\n");
	return 0; 
}

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int ch[10], sum=0, n, a[10];
bool isFlag=false;
void D(int L){
	int total=0;
	if(L == n+1){
		for(int i=1; i<=n; i++){
			if(ch[i]==1){
				total+=a[i];
			}		
		}
		if(total==sum/2){
			isFlag=true;
		}	
	}
	else{
		ch[L]=1;
		D(L+1);
		ch[L]=0;
		D(L+1);	
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		sum+=a[i];
	} 
	
	if(sum%2==1){
		printf("NO");
		return 0;	
	}
	
	D(1);
	
	if(isFlag==true)printf("YES");
	else printf("NO");
	
	return 0;
}


