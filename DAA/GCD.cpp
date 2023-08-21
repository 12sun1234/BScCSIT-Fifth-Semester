#include<stdio.h>
#include<conio.h>



int gcd(int a, int b){
	if(b==0){
		return a;
	}
	else {
		return gcd(b,a%b);
	}
}

int main(){
	int i,j,res;
	printf("Enter two numbers:\t");
	scanf("%d %d", &i ,&j);
	res=gcd(i,j);
	printf("GCD of Given Number %d %d is %d",i,j,res);
	return 0;
}
