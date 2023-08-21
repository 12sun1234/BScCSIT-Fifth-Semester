#include<stdio.h>

int main()
{
	int arr[50],i,j,flag=0,n,key;
	printf("Enter the Number of Values:");
	scanf("%d",&n);
	printf("Enter the data in array:");
	for(i=1;i<=n;i++){
		scanf("%d", &arr[i]);
	}
	printf("Enter The Key to be searched:");
	scanf("%d",&key);
	
	for(i=1;i<=n;i++){
		if(key==arr[i]){
			flag=1;
		}
	}
	if(flag==1){
	
	printf("Search Successed");
	}
	else{
	printf("No Data Found");
	}
}
