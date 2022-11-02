
#include<stdio.h>
int ch[10];
int main(){
	//freopen("input.txt", "rt", stdin);
	int i, digit, max=-2147000000, res;
	char a[101];
	scanf("%s", &a);
	for(i=0; a[i]!='\0'; i++){
		digit=a[i]-48;
		ch[digit]++;
	}
	for(i=0; i<=9; i++){
		if(ch[i]>=max){
			max=ch[i];
			res=i;
		}
	}
	printf("%d\n", res);
	return 0;
}

#include <iostream>
#include<string> 
using namespace std; 

int main() {
	int n;
	int cnt = 0;
	int a[10]={0};
	cin >> n;
	int m = n;
	string s = to_string(n);
	//s << n;
	for (int i = 0; i < s.length(); i++) {
		int k = 0;
		k = m %10;
		a[k]+=1;
		m /= 10;
	}
	int max = 0;
	int index = 0;
	for (int i = 0; i < s.length(); i++) {
		if (a[i] >= max) {
			max = a[i];
			index = i;
		}	
	}
	cout << index;

}
