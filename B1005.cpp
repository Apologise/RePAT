#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

void addAppearNumsToArrays(int num, int appearNum[], int &cnt);
bool isExistInArray(int num, int appearNum[], int &cnt);

int main(){
	int k;
	scanf("%d", &k);
	int appearNum[1000010];
	int cnt = 0;
	vector<int> inputNums;
	vector<int> ans;
	while(k--){
		int num;
		scanf("%d", &num);
		inputNums.push_back(num);
		addAppearNumsToArrays(num, appearNum, cnt);
	}
	for(int i = 0; i < inputNums.size(); ++i){
		if(isExistInArray(inputNums.at(i), appearNum, cnt)){
		}else{
			ans.push_back(inputNums.at(i));
		}
	}
	//为ans排序
	sort(ans.begin(), ans.end());
	for(int i = ans.size()-1; i >= 0; i--){
		printf("%d", ans.at(i));
		if(i != 0){
			printf(" ");
		}
	}
	return 0;
}

/*
	TODO: 将该数的卡拉兹猜想的数加入到appearNum数组中
	RETURN:修改appearNum数组和cnt的值
*/

void addAppearNumsToArrays(int num, int appearNum[], int &cnt){
	while(num!=1){
		if(num%2 == 1){
			num = (num*3+1)/2;
		}else{
			num = num/2;
		}
		appearNum[cnt++] = num;
	}
	appearNum[cnt++] = 1;
}

/*
	TODO:判断一个数是否在该数组中出现过
	RETURN: bool
*/
bool isExistInArray(int num, int appearNum[], int &cnt){
	bool flag = false;
	for(int i = 0; i < cnt; ++i){
		if(num == appearNum[i]){
			flag = true;
		}
	}
	return flag;
}
