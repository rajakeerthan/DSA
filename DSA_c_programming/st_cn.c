#include<stdio.h>
#include<stdlib.h>
#define max 10
void push(char );
int pop();
void convert(char exp[10]);
int top=-1;
int s[max];
int getprior(char );
int main(){
	 char a[10];
	int result;
	printf("enter postfix exp\n");
	scanf("%s",a);
	convert(a);
return 0;
}
void convert(char exp[10]){
	int i,result,a,b;
	char c;
	for(i=0;exp[i]!='\0';i++){
		if(isdigit(exp[i])){
			printf("%c",exp[i]);
		}
		else if(exp[i]=='(')
				push(exp[i]);
		else if(exp[i]==')'){
			while((c=pop())!='('){
				printf("%c",c);
			}
		}
		else{
			while(getprior(top)>getprior(exp[i])){
				printf("%c",pop());
			}
			push(exp[i]);
		}
	}
	while(top>=0){
		printf("%c",pop());
	}
}
int getprior(char x){
	if(x=='+' || x=='-')
		return 1;
	else if(x=='*' || x=='/')
		return 2;
	else
		return 0;
}
void push(char a){
	s[++top]=a;
}
int pop(){
	return s[top--];
}
