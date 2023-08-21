#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


void vigenereEncrypt(char *input, char *key){
	int inputlength=strlen(input);
	int keylength=strlen(key);
	int i,j;
	for (i=0,j=0;i<inputlength;i++){
		char currentchar=input[i];
		if(isalpha(currentchar)){
			char keychar=key[j%keylength];
			int shift=toupper(keychar)-'A';
			if(islower(currentchar)){
				currentchar= 'a'+(currentchar-'a'+shift)%26;
			}
			else if(isupper(currentchar)){
				currentchar='A'+(currentchar-'A'+shift)%26;
				
			}
			j++;
		}
		input[i]=currentchar;
	}
}
int main(){
	char input[50];
	char key[50];
	printf("Enter the plain text:");
	scanf("%[^\n]s",input); //read with space 
	printf("Enter the key:");
	scanf("%s",key);
	vigenereEncrypt(input,key);
	printf("Encrypted text: %s \t",input);
	return 0;
}
