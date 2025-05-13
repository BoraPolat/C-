#include <stdio.h>

int main(){
    char space=10;
    int counter;
    int truth=0;
    char temp,key;
    FILE *fp;
    fp=fopen("D:/bora/t.txt","r");

    printf("Please enter the value that you are searching for...\n");
    scanf("%c",&key);

    while (fscanf(fp,"%1c",&temp)!=EOF){
        if(temp!=space){
            counter++;    
        }
        if(temp==key){
            printf("You have found the key...\nProbe is:%d\n------------------------------------\n",counter);
            truth++;
        }
    }

    if(truth==0){    
        printf("\nCouldnt Found!");    
    }
    else if(truth>0){
        printf("\nTask done!");
    }

    return 0;
}
