#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;
#define N 1000
int n, W;
int w[N], v[N];	//��Ʒ�������ͼ�ֵ
double cntValue;
void dfs(int index,double currentW, double currentV);
vector<int> path;
stack<int> ans;
int main(){
	scanf("%d %d", &n ,&W);
	//������Ʒ������
	for(int i = 0; i < n; ++i){
		scanf("%d", &w[i]);
	}
	//������Ʒ�ļ�ֵ
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
	index: ��ǰ��Ʒ���±�
	nowK:  ��ǰѡȡ����Ʒ����
	currentW: ��ǰ��Ʒ��������
	currentV: ��ǰ��Ʒ���ܼ�ֵ
*/

void dfs(int index,  double currentW, double currentV){
	if(index >= n){	//�����ǰ�Ѿ��������������飬��ô�����ѡ����Ʒ����
		if(currentV > cntValue && currentW <= W){
			cntValue = currentV;
			//�����ŷ�����¼��ans��
			//���ans
			while(!ans.empty()){
				ans.pop();
			}
			for(int i = 0; i < path.size(); ++i){
				ans.push(path[i]);
			}
		}
		return ;
	}
	//��ѡȡ��ǰindex��Ʒ,�����ѡ����һ����nowK��currentW,currentV����
	dfs(index+1,currentW, currentV);
	//ѡȡ��ǰindex��Ʒ������ϵ�ǰ��Ʒ����������ֵ������ѡ����һ��
	//��֦����
	if(currentW+w[index] <= W){
		path.push_back(index);
		dfs(index+1, currentW+w[index],currentV+v[index]);
		path.pop_back();
	}

}


