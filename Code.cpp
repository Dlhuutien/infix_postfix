#include<stdio.h>
#include<string>
#define MAX 100
int stack[MAX], top = -1;

int isEmpty(){
	if(top == -1)
    	return 1;
	else
    	return 0;
}
void push(int x){
	if (top == (MAX - 1))
		printf("\nStack is full");
	else{
		++top;
		stack[top] = x;
	}
}

int Top(){
	return (stack[top]);
}
int pop(){
	return stack[top--];
}
int doUuTien(char x){
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1 ;
	if (x == '*' || x == '/' || x == '%')
		return 2;
	return 3;
}

void infixSangPostfix(char in[], char post[]){
	char x, token;
	int i = 0, j = 0;    // i= infix, j= postfix
	for (i = 0; in[i] != '\0'; i++){
		token = in[i];
		if (isalnum(token))
			post[j++] = token;
		else if (token == '(')
				push('(');
			else if (token == ')')
					while ((x = pop()) != '(')
						post[j++] = x;
				else{
					while (doUuTien(token) <= doUuTien(Top()) && !isEmpty()){
						x = pop();
						post[j++] = x;
					}
					push(token);
				}
	}
	while (!isEmpty()){
		x = pop();
		post[j++] = x;
	}
	post[j] = '\0';
}

void tinh(char *Post){
    int n1,n2,kq,num;
    char *p;
    p = &Post[0];
    while(*p != '\0'){
        if(isdigit(*p)){
            num = *p - 48;
            push(num);
        }
        else{
            n1 = pop();
            n2 = pop();
            switch(*p){
            case '+':
                kq = n1 + n2;
                break;
            case '-':
                kq = n2 - n1;
                break;
            case '*':
                kq = n1 * n2;
                break;
            case '/':
                kq = n2 / n1;
                break;
            }
            push(kq);
        }
        p++;
    }
    printf("Ket qua= %d", pop());
}

int main(){
	char in[MAX], post[MAX];
	printf("Nhap bieu thuc: ");
	gets(in);
	infixSangPostfix(in, post);
	printf("Postfix: %s\n", post);
	tinh(&post[0]);
	return 0;
	// A+(B*C-(D/E^F)*G)*H
	// A*B+C*((D-E)+F)/G
	// 2*((3+4)-(5-6))


}
