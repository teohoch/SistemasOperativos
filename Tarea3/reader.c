#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int *GlobalTemp;

void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);

int main(){
	
	char nombre[]="data_50000000.txt";
	FILE *file;	
	
	file = fopen( nombre, "r" );

	int count = 0; 
	int comas = 1;

	char ch;
	ch = '1';
	
	while ((ch != '\n') && (ch != EOF)) 
	{	
		if (ch==','){
			comas++;
			//printf("Numeros Leidos %d \n", comas);
		}	
		ch = getc(file); // read from stream.
		
		count++;
		//printf("Elementos Leidos %d \n", count);
		
	}
	
	
	
	printf("Elementos Leidos %d \n", count);
	printf("Numeros Leidos %d \n", comas);
	
	//int data[comas];
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
	
	//int array[comas];
	
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
		//printf("tamaño: %d \n", size);
		//printf("Numero: %d \n", numero);
		
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
	
	partition(data, 0, comas-1);
	
	
	int p;
	/*for(p=0; p<comas;p++)
	{
		printf(" numero: %d \n",data[p]);
	}*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	free(GlobalTemp);
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
