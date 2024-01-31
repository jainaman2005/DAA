#include<stdio.h>
#include<stdlib.h>


void main(){
    FILE *FP = NULL;
    FP = fopen("record.txt" , "w");
    if(FP == NULL)
    printf("file cant be opened.");
    for(int i = 0; i<10000000 ;i++){
        long int num = rand() % 989729;
        fprintf(FP,"%d,%d ",i,num);
    }
    // int arr[1500],i =0;
    // while(fscanf(FP,"%*d %d",&arr[i])== 0)
    // i++;
    // for(int  i =0;i<1500;i++){
    //     printf("%d ,",arr[i]);
    // }
    fclose(FP);

}

