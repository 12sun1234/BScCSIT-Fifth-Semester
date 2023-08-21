#include <stdio.h>
#include <string.h>
#include <ctype.h>


int sBox[4][16]={
{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
};

int sBoxSubstitution(int input){
	int row=((input &0b100000)>>4)|(input&0b000001);
	int col=(input &0b011110)>>1;
	return sBox[row][col];
}

int main(){
	int input;
	printf("Enter 6 bit input(0to63):\t");
	scanf("%d",&input);
	
	if(input<0||input>0){
		printf("Invalid Input!!\n");
		return 1;
	}
	
	int output=sBoxSubstitution(input);
	printf("Output after sBox: %d \t",output);
	return 0;
}
