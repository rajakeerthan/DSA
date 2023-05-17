#include<stdio.h>
#define max 10
int stack[max];
int top=-1;
int in_postfix(char e[]){
	int i=0,count=0,j;
	char c;
	while(e[i]!='\0'){
		count++;
		i=i+1;
	}
	printf(" no.of characters you enteres %d\n",count);
	for(j=0;j<=count;j++){
		if(isalnum(e[j])){
			printf("%c",e[j]);
		}
		else if(e[j]=='('){
			push(e[j]);
		}
		else if(e[j]==')'){
			while((c=pop())!='('){
				printf("%c",c);
			}
		}
		else{	
			push(e[j]);
		}
			 
	}
	while(top>=0)
			printf("%c",pop());
}
void push(char element){
	if(top>max-1){
		printf("stack overflow\n");
	}
	else{
		stack[++top]=element;
	}
}
int pop(){
	if(top<0){
		printf("stack underflow\n");
		return ' ';
	}
	else{
		return stack[top--];
	}
}
int main(){
	char s[20];
	printf("enter infix expression\n");
	scanf("%s",s);
	printf(" the infix exp is %s\n",s);
	printf("the postfix exp\n");
	in_postfix(s);
	
return 0;
}
