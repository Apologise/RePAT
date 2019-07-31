#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;
#define N 1000
int n, W;
int w[N], v[N];	//商品的重量和价值
double cntValue;
void dfs(int index,double currentW, double currentV);
vector<int> path;
stack<int> ans;
int main(){
	scanf("%d %d", &n ,&W);
	//输入物品的重量
	for(int i = 0; i < n; ++i){
		scanf("%d", &w[i]);
	}
	//输入物品的价值
	for(int i = 0; i < n; ++i){
		scanf("%d", &v[i]);
	}
	dfs(0,  0,0);
	printf("%f\n", cntValue);
	while(!ans.empty()){
		int index = ans.top();
		printf("%d ", index);
		ans.pop();
	}
}

/*
	index: 当前物品的下标
	nowK:  当前选取的物品个数
	currentW: 当前物品的总重量
	currentV: 当前物品的总价值
*/

void dfs(int index,  double currentW, double currentV){
	if(index >= n){	//如果当前已经遍历了整个数组，那么就输出选择物品集合
		if(currentV > cntValue && currentW <= W){
			cntValue = currentV;
			//将最优方法记录在ans中
			//清空ans
			while(!ans.empty()){
				ans.pop();
			}
			for(int i = 0; i < path.size(); ++i){
				ans.push(path[i]);
			}
		}
		return ;
	}
	//不选取当前index物品,则继续选择下一个，nowK和currentW,currentV不变
	dfs(index+1,currentW, currentV);
	//选取当前index物品，则加上当前物品的质量，价值，继续选择下一个
	//剪枝操作
	if(currentW+w[index] <= W){
		path.push_back(index);
		dfs(index+1, currentW+w[index],currentV+v[index]);
		path.pop_back();
	}

}


