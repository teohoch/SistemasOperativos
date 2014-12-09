#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int *GlobalTemp;

void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);

int main(int argc, char *argv[]){
	
	if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s filename", argv[0] );
    }
    else 
		{	
		
		FILE *file;	
		
		file = fopen( argv[1], "r" );

		int count = 0; 
		int comas = 1;

		char ch;
		ch = '1';
		
		while ((ch != '\n') && (ch != EOF)) 
		{	
			if (ch==','){
				comas++;
			}	
			ch = getc(file); // read from stream.		
			count++;		
		}	
		rewind(file);
		char *buffer = (char*) malloc(sizeof(char) * count); // allocate buffer.
		int *data = (int*) malloc(sizeof(int) * comas);
		GlobalTemp = (int*) malloc(sizeof(int) * comas);
		
		ch = '1';
		int length = 0;
		while ((ch != '\n') && (ch != EOF)) {		
			ch = getc(file); // read from stream.
			buffer[length] = ch;
			count++;
			length++;
		}	
		
		int position = 0;
		char current;
		current = '1';
		int posdata = 0;
			
		while((current != '\n') && (current != EOF) )
		{
			char temp [100];
			int size = 0;		
			
			current = buffer[position];		
			
			while(current != ',' &&(current != '\n') && (current != EOF))
			{			
				if (current!= ' ')
				{
					temp[size] = current;
					size++;
				}
				position++;
				current = buffer[position];							
			}
			// convert to int
			char litleTemp[size];
			int k;
			int numero;
			for(k = 0; k<size;k++)
			{
				litleTemp[k] = temp[k];			
			}		
			sscanf(litleTemp, "%d", &numero);		
			
			for(k = 0; k<size;k++)
			{
				litleTemp[k] = NULL;
			}	
			data[posdata] = numero;
			posdata++;			
			position++;		
							
		}
		
		
		free(buffer);
		fclose(file);
		printf("Iniciando Ordenamiento...\n");
		partition(data, 0, comas-1);
		printf("Ordenamiento Finalizado.");
		
		free(GlobalTemp);
	}
	return 0;
};

void partition(int arr[],int low,int high){

    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}

void mergeSort(int arr[],int low,int mid,int high){	
	
	int i,m,k,l;

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             GlobalTemp[i]=arr[l];
             l++;
         }
         else{
             GlobalTemp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             GlobalTemp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             GlobalTemp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=GlobalTemp[k];
    }
    
}
