#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int main(void){
//	string s="123";
	cin>>s;
	int len = s.size();
	int a=0, res=0;
//	stringstream ssInt(s);
//	ssInt >> a;
	a = stoi(s);
	for(int i=0; i<len; i++){
		int tmp=0;
		tmp = a%10;
		a/=10;
		if(i==0)res+=tmp;
		
		if(tmp==0||tmp==1)res+=tmp;
		else if(i!=0 && tmp!=0){
			res*=tmp;
		}
	}
	cout<<res<<endl;
}

#include <bits/stdc++.h>

using namespace std;

string str;

int main(void){
	cin>>str;
	
	long long result = str[0] - '0';
	
	for(int i=1; i<str.size(); i++){
		int num = str[i] - '0';
		if(num<=1 || result <=1) result += num;
		else result *= num;
	}
	cout<<result<<'\n';
}
