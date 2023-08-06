#define size 10
#define value 100
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include<stdlib.h>
typedef struct stack{
     int val[size];
     int top;
     }STACK;
typedef enum {FALSE,TRUE}BOOL;
int main(){
    STACK s;
    int n,num,co=0;
    createStack(&s);
    printf("\n\n\t\t\t\t\tTHE AMAZING NUMBERS OF MATHEMATICS");
    printf("\n\n\t\t\t\t\t===================================\n\n");
    printf("\n\nSelect the type of number you want to get to know:\n\n");
    printf("1.Abundant Number\n2.Perfect Number\n3.Fibonacci Number\n4.Oblong Number\n5.SuperFactorial Number\n6.Niven Number\n7.Armstrong Number\n8.Strong Number\n9.Exit\n\n");
    printf("Enter your choice(1-9):");
    scanf("%d",&n);
    printf("\n\n");
    switch(n)
    {
    case 1:
       Abundant(&s);
       printf("\n\n");
       break;
    case 2:
       Perfect(&s);
       printf("\n\n");
       break;
    case 3:
       Fibonacci(&s);
       printf("\n\n");
       break;
    case 4:
       Oblong(&s);
       printf("\n\n");
       break;
    case 5:
       SuperFactorial(&s);
       printf("\n\n");
       break;
    case 6:
       Niven(&s);
       printf("\n\n");
       break;
    case 7:
       Armstrong(&s);
       printf("\n\n");
       break;
    case 8:
       Strong(&s);
       printf("\n\n");
       break;
    default:
        printf("Thank you!");
        break;
    }

   }
void Abundant(STACK *s)
{
    int n;
    printf("An abundant is a number that is smaller than the sum of its aliquot parts (proper divisors).\n\n");
    printf("Enter the number you wish to check:");
    scanf("%d",&n);
    printf("\n\n");
    int sum=0,data;
    int i=1;
    while(i<=n)
    {
        if (n%i==0) push(s,i);
        i++;
    }
    {
    while (pop(s,&data))
    {
        sum=sum+data;
    }
    }
    if (sum-1>n)
    {
        printf("%d is an Abundant Number",n);
    }
    else
    {
        printf("%d is not an Abundant Number",n);
    }
}
void Perfect(STACK *s)
{
    int n;
    printf("A perfect number is a whole number that is equal to the sum of all its factors except itself.\n\n");
    printf("Enter the number you wish to check:");
    scanf("%d",&n);
    printf("\n\n");
    int sum=0,data;
    int i=1;
    while(i<=n/2)
    {
        if (n%i==0) push(s,i);
        i++;
    }
    while (pop(s,&data))
    {
        sum=sum+data;
    }
    if (sum==n)
    {
        printf("%d is a Perfect Number",n);
    }
    else
    {
        printf("%d is not a Perfect Number",n);
    }
}
void Fibonacci(STACK *s)
{
    int n;
    printf("Fibonacci number is a part of the Fibonacci sequence, in which each number is the sum of the two preceding ones.\n\n");
    printf("Enter the number you wish to check:");
    scanf("%d",&n);
     printf("\n\n");
    int sum2=1,sum1=0,data,temp,flag=0;
    push(s,sum1);
    push(s,sum2);
    while((sum1<n) && (sum2<n))
    {
        temp=sum1;
        sum1=sum2;
        sum2=sum2+temp;
        push(s,sum2);
    }
    while (pop(s,&data))
    {
    if (data==n)
    {
        flag=1;
        break;
    }
    else
    {
        flag=0;
    }
    }
    if (flag==1) printf("%d is a Fibonacci Number",n);
    else printf("%d is not a Fibonacci Number",n);
}
void Oblong(STACK *s)
{
    int n;
    printf("An oblong number is any number that is the product of two consecutive integers. Oblong numbers are also known as pronic numbers.\n\n");
    printf("Enter the number you wish to check:");
    scanf("%d",&n);
     printf("\n\n");
    int i=1,prod=1,data,flag=0;
    while((i<n) && (i+1<n))
    {
        prod=1;
        prod=prod*i*(i+1);
        push(s,prod);
        i=i+1;
    }
    while (pop(s,&data))
    {
    if (data==n)
    {
        flag=1;
        break;
    }
    else
    {
        flag=0;
    }
    }
    if (flag==1) printf("%d is an Oblong Number",n);
    else printf("%d is not an Oblong Number",n);
}
void SuperFactorial(STACK *s)
{
    int n;
    printf("A superfactorial is the product of the first n factorials.\n\n");
    printf("Enter the number you wish to check:");
    scanf("%d",&n);
     printf("\n\n");
    int i=0,prod=1,data,temp;
    STACK t;
    createStack(&t);
    while(Factorial(i)<n)
    {
        push(s,Factorial(i));
        i++;
    }
    while (pop(s,&data))
    {

           push(&t,data);
    }
    while (pop(&t,&data) && prod<n)
    {
        prod=prod*data;
    }
    if ((n==1)||(prod==n))
    {
        printf("%d is a SuperFactorial Number",n);
    }
    else
    {
        printf("%d is a not a SuperFactorial Number",n);
    }
}
void Niven(STACK *s)
{
    int n;
    printf("A Harshad number is a number that is divisible by the sum of its own digits.\nFor example, 1729 is a Harshad number because 1 + 7 + 2 + 9 = 19 and 1729 = 19 × 91.\n\n");
    printf("Enter the number you wish to check:");
    scanf("%d",&n);
     printf("\n\n");
    int r,sum=0,co=0,data;
    int a=n;
    while(n!=0)
    {
          r=n%10;
          push(s,r);
          n=n/10;
    }
    while (pop(s,&data))
    {
           sum=sum+data;
    }
    if (a%sum==0)
    {
           printf("%d is a Niven Number",a);
    }
    else printf("%d is not a Niven Number",a);
}
void Strong(STACK *s)
{
    int n;
    printf("Strong number is a special number whose sum of the factorial of digits is equal to the original number.\n\n");
    printf("Enter the number you wish to check:");
    scanf("%d",&n);
     printf("\n\n");
    int r,sum=0,co=0,data;
    int a=n;
    while(n!=0)
    {
          r=n%10;
          push(s,Factorial(r));
          n=n/10;
    }
    while (pop(s,&data))
    {
           sum=sum+data;
    }
    if (sum==a)
    {
           printf("%d is Strong Number",a);
    }
    else printf("%d is not a Strong Number",a);
}
int Factorial(int a)
{
    int i=1,prod=1;
    while(i<=a)
    {
        prod=prod*i;
        i++;
    }
    return prod;
}
void Armstrong(STACK *s)
   {
       int n;
       printf("A narcissistic number, also known as an Armstrong number or a plus perfect number, is an n-digit number equal to\nthe sum of its digits raised to the nth power.\n\n");
       printf("Enter the number you wish to check:");
       scanf("%d",&n);
        printf("\n\n");
       int r,sum=0,co=0,data;
       int a=n;
       while(n!=0)
       {
          r=n%10;
          push(s,r);
          n=n/10;
       }
       co=count(*s);
       while (pop(s,&data))
       {
           sum=sum+pow(data,co);
       }
       if (sum==a)
       {
           printf("%d is an Armstrong Number",a);
       }
       else printf("%d is not an Armstrong Number",a);
   }
void createStack(STACK *t){
       t->top=0;
       (*t).top=0;
   }
int isEmpty(STACK s)
   {
       if (s.top==0){
            return 1;
       }
       return 0;
   }
int isFull(STACK s)
   {
       return (s.top==size-1);

   }
int push(STACK *s,int data)
   {
       if (!isFull(*s))
       {
           s->top=s->top+1;
           s->val[s->top]=data;
           return 1;
       }
       return 0;
   }
int pop(STACK *s,int *data)
   {
       if (isEmpty(*s)){
           return 0;
       }
       *data=s->val[s->top];
       s->top=s->top-1;
       return 1;
   }
int peep(STACK s){
        if (isEmpty(s)) return -1;
        return s.val[s.top];
   }
void print(STACK s){
        int data;
        while (!isEmpty(s)){
            pop(&s,&data);
            printf("%d\n",data);
        }
   }
int count(STACK s){
        int data,c=0;
        while (!isEmpty(s)){
            pop(&s,&data);
            c++;
        }
        return c;
   }
