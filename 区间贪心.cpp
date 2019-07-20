#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 10
typedef struct{
	int x;
	int y;
}Interval;
Interval I[maxn];

bool cmp(Interval a, Interval b){
	if(a.x != b.x){
		return a.x > b.x;
	}else{
		return a.y < b.y;
	}
}
int main(){
	int n = 4;
	//1. 输入数据
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &I[i].x, &I[i].y);
	}
	//2.根据x值大小进行排序
	sort(I, I+n, cmp);
	//3. 根据x的值从大到小遍历区间
	//3.1 首先选取x最大的一个作为最右边的区间,lastX为当前选定区间的最左端
	int flag[maxn], cnt = 0, lastX;
	flag[cnt++] = 0, lastX = I[0].x;
	for(int i = 1; i < n; ++i){
		if(I[i].y <= lastX){ //找到了一个与已选定区间不重叠的区间
			lastX = I[i].x;
			flag[cnt++] = i;
		}
	}
	//4.输出区间
	for(int i = cnt-1; i >= 0;  --i){
		printf("%d %d ", I[flag[i]].x, I[flag[i]].y);
	}
	return 0;
}