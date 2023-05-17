#include<stdio.h>
#include<stdlib.h>
int evaluate(char s[]);
int st[20];
int main(){
	int r;
	char s[10];
	printf("enter infix expression\n");
	scanf("%s",s);
	r=evaluate(s);
	printf("result=%d\n",r);
return 0;
}
int top=-1;
void push(int c){
	st[++top]=c;
}
int pop(){
	return st[top--];
}
int evaluate(char s[]){
	int i,a,b,result;
	for(i=0;s[i]!='\0';i++){
		if(isalnum(s[i]))
			push(s[i]-'0');
		else{
			a=pop();
			b=pop();
			switch(s[i]){
				case '+':result=a+b;break;
				case '-':result=a-b;break;
				case '*':result=a*b;break;
				case '/':result=a/b;break;
			}
			return result;
		}
		
	}
}
