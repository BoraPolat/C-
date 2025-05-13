#include <stdio.h>
#include <stdlib.h>

int main(){

 int i,j,k,s,swap;

	scanf("%d",&s);
	
	
	
        for(i=1;i<s;i++){
        	
        	for(j=1;j<i;j++){
        		
        		printf("%d+%d\n",j,i-j);
        		
			}
		}
	
	    return 0;
}
