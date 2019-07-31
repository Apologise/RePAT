#include<stdio.h>
#include<stack>
#include<map>
#include<queue>
using namespace std;

typedef struct{
	double num;
	char op;
	bool isDigit;
}Node;
stack<Node> opStack;	//存放操作符的栈
map<char, int> priorityOfOp;	//存放操作符的优先级

char a[100][10];
int cnt = 0;

int allCount = 0;
bool isDigit(char ch){
	if(ch >= '0' && ch<='9'){
		return true;
	}else{
		return false;
	}
}

//将字符串按照空格拆分，返回多个字符串数组
void split(char *str, char ch){
	char *p = str;

	int index = 0;
	while(*p!=0){
		if(isDigit(*p)){
			a[cnt][index++] = *p;
		}else if(*p!= ' '){
			a[cnt][index] = *p;
		}else{
			cnt++;
			index = 0;
		}
		p++;
	}
	cnt++;
}

int main(){
	queue<Node> ans;
	//将运算符优先级表加入到priorityOfOp中
	priorityOfOp['+'] = 1;
	priorityOfOp['-'] = 1;
	priorityOfOp['*'] = 2;
	priorityOfOp['/'] = 2;
	priorityOfOp['('] = 3;
	char str[200];
	gets(str);
	split(str, ' ');
	printf("拆分完毕\n");
	char (*p)[10] = a;
	for(int i = 0; i < cnt; ++i){
		Node node, topNode;
		//将当前字符串转为Node节点
		char *s = *(p+i);
		//遍历整个字符串
		//首先判断首字符，如果首字符为非数字字符，那么直接判定为操作符
		char firstCh = *(s+0);
		if(!isDigit(firstCh)){
			//表明为一个操作符
			node.isDigit = false;
			node.op = firstCh;
			//对该操作符与操作符栈顶元素比较
			//如果当前操作符栈为空，直接加入到栈中
			if(opStack.empty()){
				opStack.push(node);
			}else{
				if(node.op == ')'){
					//不断将操作符退栈，压入后缀数组中
					while(opStack.top().op!='('){
						ans.push(opStack.top());
						opStack.pop();
					}
					opStack.pop();
				}else{
					topNode = opStack.top();
					int opLevel = priorityOfOp[node.op];
					int topLevel = priorityOfOp[topNode.op];
					//注意，这里的优先级判断条件一定要小于等于，因为当优先级相同时，则从左到右先算，那么先入栈的需要先计算，则栈顶节点也要出栈
					while(opLevel <= topLevel && topNode.op != '('){
					//将栈顶元素退栈，加入到后缀数组中
						ans.push(topNode);
						opStack.pop();
						if(opStack.empty()){break;}
						topNode = opStack.top();
						topLevel = priorityOfOp[topNode.op];
					}
					opStack.push(node);
				}
			}
		}else{
			//如果为操作数，则将字符串转为数类型，加入到后缀数组中
			double num = 0;
			int gap = 1;
			char ch;
			for(int j = 0; ch = *(s+j); ++j){
				num = num * 10+(*(s+j)-'0');
				gap *=10;
			}
			node.isDigit = true;
			node.num = num;
			//将该node加入到后缀数组中
			ans.push(node);
		}
	}
	Node node;
	printf("");
	/*
	while(!ans.empty()){
		node = ans.front();
		if(node.isDigit){
			printf("%f ", node.num);
		}else{
			printf("%c", node.op);
		}
		ans.pop();
	}
	*/
	//将操作符栈中剩余操作符压入后缀队列中
	while(!opStack.empty()){
		node = opStack.top();
		ans.push(node);
		opStack.pop();
	}
	printf("计算表达式的值");
	stack<double> result;
	while(!ans.empty()){
		Node node = ans.front();
		if(node.isDigit){
			result.push(node.num);
		}else{
			//退出两个操作数，计算结果
			double num2 = result.top();
			result.pop();
			double num1 = result.top();
			result.pop();
			double  num;
			if(node.op == '+'){
				num = num1 + num2;
			}else if(node.op == '-'){
				num = num1 - num2;
			}else if(node.op == '*'){
				num = num1 * num2;
			}else{
				num = num1 / num2;
			}
			result.push(num);
		}
		ans.pop();
	}
	double  num = result.top();
	printf("%f",num);
	return 0; 
}