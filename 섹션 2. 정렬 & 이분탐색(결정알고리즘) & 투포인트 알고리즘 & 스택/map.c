#include<fstream>
#include<iostream>
#include<map>
#include <string>
using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	ifstream cin;
	cin.open("input.txt");
	map<string, int> ch;
	map<string, int>::iterator it;
	char a[100];
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin>> a;
		ch[a]++;
	}
	
	int max=0;
	string res;
	for(it=ch.begin(); it != ch.end(); it++ ){
		if(it->second>max){
			max = it->second;
			res=it->first;
		}
	}
	cout<< res << " : " <<max<<"\n";
	
	return 0;
}
