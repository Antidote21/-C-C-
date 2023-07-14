#include <stdio.h>
int main(){
	//freopen("input.txt", "rt", stdin);
	int i, a[10], b[10], acnt=0, bcnt=0, flag=0, total=0;
	
	for(i=0;i<10;i++){
		scanf("%d", &a[i]);
	}
	
	
	for(i=0;i<10;i++){
		scanf("%d", &b[i]);
	}
	
	for(i=0; i<10; i++){
		if(a[i]>b[i]){
			acnt+=3;
			flag=1;
		}
		else if(a[i]<b[i]){
			bcnt+=3;
			flag=2;
		}
		else{
			acnt++;
			bcnt++;
			total++;
		}
	}
	printf("%d %d\n", acnt, bcnt);
	if(acnt<bcnt)printf("B\n");
	else if(acnt>bcnt)printf("A\n");
	else{
		if(total==10)printf("D\n");
		if(flag==1)printf("A\n");
		else if(flag==2)printf("B\n");
	}
	return 0;
}
#include<bits/stdc++.h>
#include<queue>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);	
	vector<int> a(11);
	vector<int> b(11);
	int Ascore=0, Bscore=0, winner=0;
	for(int i=1; i<=10; i++){
		cin>>a[i];
	}
	for(int i=1; i<=10; i++){
		cin>>b[i];
	}
	
	for(int i=1; i<=10; i++){
		if(a[i]>b[i]){
			Ascore+=3;
			winner=1;
		}
		else if(a[i]==b[i]){
			Ascore+=1;
			Bscore+=1;
			
		}
		else{
			Bscore+=3;
			winner=2;
		}
	}
	cout<<Ascore<<" "<<Bscore<<endl;
	if(Ascore>Bscore)cout<<"A";
	else if(Ascore==Bscore){
		if(Ascore==10)cout<<"D";
		if(winner==1)cout<<"A";
		else if(winner==2)cout<<"B";
		
	}
	else cout<<"B";
	return 0;
}    

