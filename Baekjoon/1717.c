#include <stdio.h>

int unf[1000000];

int Find(int v){
    if(v == unf[v]) return v;
    else return unf[v] = Find(unf[v]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a != b) unf[a] = b;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i <= n; i++){
        unf[i] = i;
    }
    
    int a, b, c;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0){
            Union(b, c);
        }else{
            int res = Find(b);
            if(res == Find(c)){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
    
    return 0;
}
