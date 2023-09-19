#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
//나눌 수 있는 작은 범위까지 나눈다음 다시 병합하여 정렬하는 방법이다.  
int a[101], tmp[101];
void divide(int lt, int rt){//시작값과 끝값이 매개변수로 들어간다.  
	int mid;
	if(lt<rt){
		mid=(lt+rt)/2;//분할시키기 위한 mid 변수  
		divide(lt, mid);
		divide(mid+1, rt); 
		p1=lt;
		p2=mid+1;
		p3=lt;
		while(p1<=mid && p2<=rt){//정렬 하기 위한 while문  
			if(data[p1]<data[p2])tmp[p3++]=data[p1++];
			else tmp[p3++]=data[p2++];
		}
		while(p1<=mid) tmp[p3++]=data[p1++];
		while(p2<=rt) tmp[p3++]=data[p2++];
		for(int i=lt; i<=rt; i++){
			data[i]=tmp[i];//정렬된 값을 data 배열에 대입 
		}
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	divide(1, n);
	for(i=1; i<=n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}

#include <iostream>
using namespace std;

int data[10], tmp[10];

void mergeSort(int lt, int rt){
	int mid;
	int p1, p2, p3;
	if(lt<rt){
		mid=(lt+rt)/2;
		mergeSort(lt,mid);
		mergeSort(mid+1,rt);
		p1=lt;
		p2=mid+1;
		p3=lt;
		while(p1<=mid && p2<=rt){
			tmp[p3++] = (data[p1] < data[p2]) ? data[p1++] : data[p2++]; 
		}

		while(p1 <= mid) tmp[p3++] = data[p1++];
		while(p2 <= rt) tmp[p3++] = data[p2++];

		for(int i=lt; i<=rt; i++){
			data[i] = tmp[i];
		}
	}
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    return 0;
}
