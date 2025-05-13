#include <stdio.h>
#define lenght 12
int main() {
    int temp,arr[lenght],i=0,j=0,swap=0;
    
    FILE *fp;
    fp = fopen("D:/t_sorting.txt", "r");
    
    
    while (fscanf(fp, "%d", &temp) != EOF) {
        printf("%d\n",temp);
        
        arr[i]=temp;
        i++;
    }
    fclose(fp);//---------------------------------------------
    
    for(i=0;i<lenght-1;i++){
    	for(j=i+1;j<lenght;j++){
    		
    		if(arr[i]>arr[j]){
    			swap++;
    			//arr[i] = arr[i] + arr[j] - (arr[j] = arr[i]);
				arr[i] = arr[i] ^ arr[j];
                arr[j] = arr[i] ^ arr[j];
                arr[i] = arr[i] ^ arr[j];
			}
		}
	}
	
    printf("-------------------------------------\n");
    
    for(i=0;i<lenght;i++){
	printf("%d\n",arr[i]);
	} 
	printf("\nSwap = %d",swap);
	//---------------------------------------------
    
	
    return 0; 
}
