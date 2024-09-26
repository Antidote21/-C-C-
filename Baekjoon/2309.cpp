#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int height[10];
int ch[10];
vector<int> result(7); 

void dfs(vector<int> res, int cnt, int sum, int idx){ 
    if(cnt==7){ 
        if(sum==100){ 
            result = res; 
            return;
        }
    }
    if(cnt > 7 || idx >= 9) return; 
    
    res.push_back(height[idx]);
    dfs(res, cnt+1, sum+height[idx], idx+1); 
    res.pop_back(); 
    
    dfs(res, cnt, sum, idx+1); 
}

int main(){
    for(int i=0; i<9; i++){
        cin >> height[i];
    }
    sort(height, height + 9); 
    vector<int> temp; 
    dfs(temp, 0, 0, 0); 
    for(auto k:result){
        cout << k << endl;
    }
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int tall[10];
    int sum = 0;
    for(int i=0; i<9; i++){
        cin>>tall[i];
        sum+=tall[i];
    }
    sort(tall, tall+9);
    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if(sum-(tall[i]+tall[j]) == 100){
                for(int z=0; z<9; z++){
                    if(z != i && z != j){
                        cout<< tall[z] <<'\n';
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int height[10];
int ch[10];
vector<int> result(7); 

void dfs(vector<int> res, int cnt, int sum, int idx){ 
    if(cnt==7){ 
        if(sum==100){ 
            result = res; 
            return;
        }
    }
    if(cnt > 7 || idx >= 9) return; 
    
    res.push_back(height[idx]);
    dfs(res, cnt+1, sum+height[idx], idx+1); 
    res.pop_back(); 
    
    dfs(res, cnt, sum, idx+1); 
}

int main(){
    for(int i=0; i<9; i++){
        cin >> height[i];
    }
    sort(height, height + 9); 
    vector<int> temp; 
    dfs(temp, 0, 0, 0); 
    for(auto k:result){
        cout << k << endl;
    }
    return 0;
}
