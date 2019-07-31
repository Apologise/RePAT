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
stack<Node> opStack;	//��Ų�������ջ
map<char, int> priorityOfOp;	//��Ų����������ȼ�

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

//���ַ������տո��֣����ض���ַ�������
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
	//����������ȼ�����뵽priorityOfOp��
	priorityOfOp['+'] = 1;
	priorityOfOp['-'] = 1;
	priorityOfOp['*'] = 2;
	priorityOfOp['/'] = 2;
	priorityOfOp['('] = 3;
	char str[200];
	gets(str);
	split(str, ' ');
	printf("������\n");
	char (*p)[10] = a;
	for(int i = 0; i < cnt; ++i){
		Node node, topNode;
		//����ǰ�ַ���תΪNode�ڵ�
		char *s = *(p+i);
		//���������ַ���
		//�����ж����ַ���������ַ�Ϊ�������ַ�����ôֱ���ж�Ϊ������
		char firstCh = *(s+0);
		if(!isDigit(firstCh)){
			//����Ϊһ��������
			node.isDigit = false;
			node.op = firstCh;
			//�Ըò������������ջ��Ԫ�رȽ�
			//�����ǰ������ջΪ�գ�ֱ�Ӽ��뵽ջ��
			if(opStack.empty()){
				opStack.push(node);
			}else{
				if(node.op == ')'){
					//���Ͻ���������ջ��ѹ���׺������
					while(opStack.top().op!='('){
						ans.push(opStack.top());
						opStack.pop();
					}
					opStack.pop();
				}else{
					topNode = opStack.top();
					int opLevel = priorityOfOp[node.op];
					int topLevel = priorityOfOp[topNode.op];
					//ע�⣬��������ȼ��ж�����һ��ҪС�ڵ��ڣ���Ϊ�����ȼ���ͬʱ������������㣬��ô����ջ����Ҫ�ȼ��㣬��ջ���ڵ�ҲҪ��ջ
					while(opLevel <= topLevel && topNode.op != '('){
					//��ջ��Ԫ����ջ�����뵽��׺������
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
			//���Ϊ�����������ַ���תΪ�����ͣ����뵽��׺������
			double num = 0;
			int gap = 1;
			char ch;
			for(int j = 0; ch = *(s+j); ++j){
				num = num * 10+(*(s+j)-'0');
				gap *=10;
			}
			node.isDigit = true;
			node.num = num;
			//����node���뵽��׺������
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
	//��������ջ��ʣ�������ѹ���׺������
	while(!opStack.empty()){
		node = opStack.top();
		ans.push(node);
		opStack.pop();
	}
	printf("������ʽ��ֵ");
	stack<double> result;
	while(!ans.empty()){
		Node node = ans.front();
		if(node.isDigit){
			result.push(node.num);
		}else{
			//�˳�������������������
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