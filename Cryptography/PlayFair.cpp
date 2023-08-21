#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

void generatekey(char key[], char keytable[5][5]){
    int keylength = strlen(key);
    char letters[26];
    int index=0;
    for(int i=0;i<keylength;i++){
        if(key[i]!='j')
        {
        if(!strchr(letters,key[i])){
                keytable[index/5][index%5]=key[i];
                letters[index]=key[i];
                index++;
            }
        }
    }
    for(char ch='A'; ch<='Z';ch++){
        if(ch!='J'){
            if(!strchr(letters,ch)){
                keytable[index/5][index%5]=ch;
                letters[index]=ch;
                index++;
            }
        }
    }
}
 void findposition(char keytable[5][5], char ch,int *row, int *col){
    if(ch=='J'){
        ch='I';
     }
     for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(keytable[i][j]==ch){
                *row=i;
                *col=j;
                return;
             }
         }
     }
     
 }
 
  void playfairEncrypt(char keytable[5][5],char input[], char encrypted[]){
    int inputlength=strlen(input);
    for(int i=0;i<inputlength;i+=2){
        char first =input[i];
        char second =(i+1<inputlength)?input[i+1]:'X';
        
        int row1,col1,row2,col2;
        findposition(keytable,first,&row1,&col1);
        findposition(keytable,second,&row2,&col2);
        
        if(row1==row2){
            encrypted[i]=keytable[row1][(col1+1)%5];
            encrypted[i+1]=keytable[row2][(col2+1)%5];
          }
          else if (col1==col2){
            encrypted[i]=keytable[(row1+1)%5][col1];
            encrypted[i+1]=keytable[(row2+1)%5][col2];
          }
          else{
            encrypted[i]=keytable[row1][col2];
            encrypted[i+1]=keytable[row2][col1];
          }
      }
  }

int main(){
    char key[25];
    char keytable[5][5];
    char input[100];
    char encrypted[100];    
    printf("Enter the key without J: \t");
    scanf("%s", key);
    printf("Enter Plain text in uppercase: \t");
    scanf("%s", input);
    generatekey(key, keytable);
    playfairEncrypt(keytable,input,encrypted);
    printf("Encrypted Text: %s \n", encrypted);
    return 0;
}

