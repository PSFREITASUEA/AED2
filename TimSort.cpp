#include<bits/stdc++.h>
#include <stdio.h>
#include<time.h>

using namespace std;
const int RUN = 32;
 
// Essa funcao ordena o array di index left ate o
// index right que tem o tamanho bem proximo ou igual a RUN
void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
 
// Funcao Merge
void merge(int arr[], int l, int m, int r)
{
     
    // O array original e quebrado em duas partes
    // left e right array
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    // Depois de comparar, nos iremos
    // fazer o merge desses dois arrays
    // em um sub array maior
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    // copia os elementos restantes da esquerda, se houver
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
 
    // copia os elementos restantes da direita, se houver
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}
 
// Funcao iterativa Timsort para ordenar o
// array[0...n-1] (similar ao merge sort)
void timSort(int arr[], int n)
{
     
    // Ordena os subarrays individuais de size RUN
    for (int i = 0; i < n; i+=RUN)
        insertionSort(arr, i, min((i+RUN-1),
                                    (n-1)));
 
    // Comeca o merge de size RUN (or 32).
    // E ira fazer o merge
    // para formar os size 64, entao 128, 256
    // e assim sucessivamente ....
    for (int size = RUN; size < n;
                             size = 2*size)
    {
         
        // pega o comeco do
        // left sub array. nos
        // iremos fazer o merge
        // arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // depois de cada merge, nos
        // incrementamos left para 2*size
        for (int left = 0; left < n;
                             left += 2*size)
        {
             
            // Acha o ponto em que acaba
            // o left sub array
            // mid+1 e o comeco
            // do right sub array
            int mid = left + size - 1;
            int right = min((left + 2*size - 1),
                                            (n-1));
 
            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
              if(mid < right)
                merge(arr, left, mid, right);
        }
    }
}
 
// Funcao printar array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}
 
// Funcao main
int main()
{
	int tam = 10;
	int i;
    int *arr;
    
    arr = (int *) malloc (tam * sizeof(int));
    
    if(arr){ 
    for(i = 0; i < tam; i++)
	{
		
        *(arr + i) = rand() % 100000; // sorteia n�meros entre 0 e 100000
	}
	

   for(i = 0; i < tam; i++)
    {
        printf("%d ", *(arr + i)); // imprime o conteudo desta regiao de memoria
        printf("\n");
	}
    }
    else
    {
    	return 1;
	}
                       
    int n = tam;
    
    
    printf("Ordenando %d numeros dispostos aleatoriamente...", n);
    
    printf("\nGiven Array is\n");
    printArray(arr, n);
    
 
    // Chamada da funcao
    timSort(arr, n);
 
    printf("After Sorting Array is\n");
    printArray(arr, n);
    
    return 0;
}
