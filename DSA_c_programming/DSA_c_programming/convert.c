#include<stdio.h>
#include<stdlib.h>
char stack[30];
int top=-1;
void push(char );
int prior(char );
int pop();
void convert(char exp[]){
	int i=0;
	char c;
	while(exp[i]!='\0'){
		if(isalnum(exp[i])){
			printf("%c",exp[i]);
		}
		else if(exp[i]=='('){
			push(exp[i]);
		}
		else if(exp[i]==')'){
			while((c=pop())!='(')
				printf("%c",c);
		}
		else{
			if(prior(stack[top])>prior(exp[i])){
					printf("%c",pop());
			}
			push(exp[i]);
		}
		i++;
	}
	while(top>0){
		printf("%c",pop());
	}
}
int prior(char k){
	if(k=='+' || k=='-')
		return 1;
	else if(k=='*' || k=='/')
		return 2;
	return 0;
		
}
void push(char element){
	stack[++top]=element;
}
int pop(){
	return stack[top--];
}
int main(){
	char str[20];
	printf("enter infix expression\n");
	scanf("%s",str);
	convert(str);
return 0;
}
