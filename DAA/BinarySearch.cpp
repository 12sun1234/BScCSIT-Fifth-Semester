#include<stdio.h>


int search(int arr[], int l, int h, int key) {
    while(l<=h) {
        int mid;
        mid=(l+h)/2;
        if (arr[mid]==key) {
            return mid;
        }
        if(arr[mid]<key) {
            l=mid+1;
        }
        else{
        	h=mid-1;
		}
	

    }
    	return -1;

}

int main()
{
    int arr[50],i,j,flag=0,n,key;
    printf("Enter the Number of Values:");
    scanf("%d",&n);
    printf("Enter the data in array:");
    for(i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter The Key to be searched:");
    scanf("%d",&key);
    int res=search(arr,0,n-1,key);
    if(res!=-1)
	printf("Result Found in %dth position", res);
	else{
		printf("Not Found");
	}
    
}

