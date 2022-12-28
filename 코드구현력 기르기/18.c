#include<stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int s = -1, n, m, i, num, max = 0;
	bool flag = false;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		if (num > m) {
			if (flag == true)s++;
			else if(flag == false) s = 1;
			flag = true;
			if (max < s) {
				max = s;
			}
		}
		else flag = false;
	}
	if (max != -1)printf("%d", max);
	else printf("%d",s);
	return 0;
}

