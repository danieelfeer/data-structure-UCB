#include <stdio.h>

void sum(int *num1, int *num2, int *result){
    *result = (*num1)+(*num2);
}

void sub(int *num1, int *num2, int *result){
    *result = (*num1)-(*num2);
}

void mult(int *num1, int *num2, int *result){
    *result = (*num1)*(*num2);
}

void div(int *num1, int *num2, int *result){
    *result = (*num1)/(*num2);
}


int main(){

    int num1;
    int num2;
    int result = 0;
    char operator;

    printf("Number 1: ");
    scanf("%d", &num1);
    printf("\n");

    printf("Number 2: ");
    scanf("%d", &num2);
    
    printf("operator: ");
    scanf("%s", &operator);

    switch (operator)
    {
    case '+':
        sum(&num1, &num2, &result);
        break;
    case '-':
        sub(&num1, &num2, &result);
        break;
    case '*':
        mult(&num1, &num2, &result);
        break;
    case '/':
        div(&num1, &num2, &result);
        break;
    
    default:
        break;
    }

    printf("%d %c %d = %d\n", num1, operator, num2, result);

    return 0;    
}