#include<iostream>
#include<string>
using namespace std;

string seat[11][21];

int main(){
    int n;
    int x, y;
    cin>>n;
    string a = "XABCDEFGHIJ";
        
    for(int i=1; i<=10; i++){
        for(int j=1; j<=20; j++){
            seat[i][j]=".";
            //cout<<seat[i][j];
        }
        //cout<<endl;
    }
    
    for(int i=0; i<=n; i++){
        string s;
        cin>>s;
        for(int j=1; j<=10; j++){
            if(a[j]==s[0]){
                int x, y;
                x = j;
                if(s.size()>2){
                    int y1 = int(s[1])-48;
                    int y2 = int(s[2])-48;
                    y = y1*10+y2;
                }else if(s.size()==2){
                    y = int(s[1])-48;    
                }
               
                seat[x][y] = "o";
            }
        }
    }
    
    for(int i=1; i<=10; i++){
        for(int j=1; j<=20; j++){
            cout<<seat[i][j];
        }
        cout<<endl;
    }
    

}
