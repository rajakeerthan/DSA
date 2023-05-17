#include<stdio.h>
#define max 10
int stack[max];
int top=-1;
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
		printf("stack underflow");
		return ;
	}
	else{
		return stack[top--];
	}
}
int evaluation(char e[]){
	int i=0;
	int k,l,c;
	while(e[i]!='\0'){
		if(isalnum(e[i])){
			push(e[i]-'0');
		}
		else{
			k=pop();
			l=pop();
			switch(e[i]){
				case '+':c=k+l;break;
				case '-':c=k-l;break;
				case '*':c=k*l;break;
				case '/':c=k/l;break;
			
			}
			push(c);
		}
	i++;	
	}
	
}
int main(){
	char s[10];
	printf("enetr postfix expression\n");
	scanf("%s",s);
	evaluation(s);
	printf("the result is %d",stack[top]);
return 0;
}
