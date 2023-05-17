#include<stdio.h>
#include<stdlib.h>
void convert(char s[]);
char st[20];
int main(){
	char s[10];
	printf("enter infix expression\n");
	scanf("%s",s);
	convert(s);
return 0;
}
int top=-1;
void push(char c){
	st[++top]=c;
}
char pop(){
	return st[top--];
}
int getprior(char c){
	if(c=='+' || c=='-')
		return 1;
	else if(c=='*' || c=='/')
		return 2;
	else
		return 0;
}
void convert(char s[]){
	int i;
	char c;
	for(i=0;s[i]!='\0';i++){
		if(isalnum(s[i])){
			printf("%c",s[i]);
		}
		else if(s[i]=='('){
			push(s[i]);
		}
		else if(s[i]==')'){
			while((c=pop())!='('){
				printf("%c",c);
			}
		}
		else{
			while((getprior(top))>(getprior(s[i]))){
				printf("%c",pop());
			}
			push(s[i]);
		}
	}
	while(top>=0){
		printf("%c",pop());
	}
}
