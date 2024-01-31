#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<stdbool.h>
#define MAX 400000
bool linear_search(long int arr[],int key,int record_length){
    bool found = false;
    for(int  i = 0;i < record_length;i++){
        if(arr[i]==key)
        return (found = true);
    }
    return found;
}

void main(){
    FILE *fp;
    fp = fopen("record.txt","r");
    if(fp==NULL){
        printf("the fle can't be opened.");
        exit(1);
    }
    
    //array of record
    long int arr[MAX],rrecord_length = 0;

    //taking record value from file record.txt
    while (!feof(fp))
        fscanf(fp,"%*ld,%ld ",&arr[rrecord_length++]);
    fclose(fp);
    
    int test_case = 10,key,size;
    do{
    //input :
    printf("\nEnter the key want to found and size of record:\n");
    scanf("%d%d",&key,&size);
    if(size<1)
    break;
    //clock pulse at start
    clock_t start  = clock(); 

    //calling linear search
    bool found  = linear_search(arr,key,size);

    //clock pulse at end
    clock_t end = clock();
    found ? printf("\nkey found.") : printf("\nkey not found.");

    //clock taken by program/searching technique
    printf("\n clock_difference: %fsec",(double)(end - start)/CLOCKS_PER_SEC);
    }while(--test_case);
}