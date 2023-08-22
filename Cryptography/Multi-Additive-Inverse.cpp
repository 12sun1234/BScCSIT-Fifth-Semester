#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

int findadditiveinverse(int num, int mod){
	return(mod-num)%mod;
}

int findmultiplicativeinverse(int num, int mod){
	int gcdvalue=gcd(num,mod);
	if(gcdvalue!=1){
		printf("Multiplicative Inverse Does not Exist!!");
		return -1;
	}
	
	for(int i=1;i<mod;i++){
		if((num*i)%mod==1){
			return i;
		}
	}
	return -1;
}

int main(){
	int num,mod;
	printf("Enter a Number:\t");
	scanf("%d",&num);
	
	printf("Enter the modulus:\t");
	scanf("%d",&mod);
	
	int addi= findadditiveinverse(num,mod);
	printf("Additive Inverse:\t %d \n ", addi);
	
	int multi= findmultiplicativeinverse(num,mod);
	if(multi!=-1){
	printf("Multiplicative Inverse: %d \t", multi);
}
return 0;
}
