#include <stdio.h>
#include <stdlib.h>
#define MAX 50


void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);

int main(){
	
	char nombre[]="data.txt";
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
	
	int p;
	for(p=0; p<comas;p++)
	{
		printf("%d \n",data[p]);
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
};
