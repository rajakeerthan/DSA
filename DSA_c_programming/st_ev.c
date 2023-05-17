#include<stdio.h>
#include<stdlib.h>
#define max 10
void push();
int pop();
int evaluate();
int top=-1;
int s[max];
int main(){
	 char a[10];
	int result;
	printf("enter postfix exp\n");
	scanf("%s",a);
	result=evaluate(a);
	printf("result=%d",result);
return 0;
}
int evaluate(char exp[10]){
	int i,result,a,b;
	for(i=0;exp[i]!='\0';i++){
		if(isalnum(exp[i])){
			push(exp[i]-'0');
		}
		else{
			a=pop();
			b=pop();
			switch(exp[i]){
				case '+':result=a+b;break;
				case '-':result=a-b;break;
				case '*':result=a*b;break;
				case '/':result=a/b;break;	
			}
				push(result);
		}
	
	}
	return result;
}
void push(int a){
	s[++top]=a;
}
int pop(){
	return s[top--];
}
