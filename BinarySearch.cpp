/* write a program to accept an array, sort it using either quicksort or mergesort. Then accept a number from the user and display whether the element exists in the list. If yes display the corresponding index number as well.
*/

#include<stdio.h>
#include<conio.h>

int partition(int arr[],int start, int end)
{
    
    int pivot  = arr[end],i;                                    //set pivot to the last element of the array 
    int partitionIndex = start;
    
    for(i = start;i<=end-1;i++)                                  //traverse the array from start to end-1
    {
          if(arr[i]<=pivot)
          {
                int temp = arr[i];                               //swap ith element with the element at partitionIndex
                arr[i] = arr[partitionIndex];
                arr[partitionIndex]=temp;
                partitionIndex++;                               //increment the value of part
                                        
          }
    }                               
    int t = arr[partitionIndex];                                 //swap last element with the element at partitionIndex
    arr[partitionIndex] = arr[end];
    arr[end] = t;
    return partitionIndex;                                       //return partitionIndex
      
}                                               

int quickSort(int arr[],int first, int last)
{   int pivotIndex,i;
    if(first<last)                                              //this is to check whether there are more than one elements in the array under consideration
                {    
                    pivotIndex = partition(arr,first,last);     //partition the array 
                    quickSort(arr,first,pivotIndex-1);          //recursively call quicksort from first to pivotIndex-1 and from pivotIndex+1 to last
                    quickSort(arr,pivotIndex+1,last);
                }
}

int binarySearch(int arr[],int first,int last,int search)
{
    if(first>last)                  return 9999;
    else
    {
    
    int mid = (first+last)/2;
    
    if(search==arr[mid])                { printf("found at index no %d",mid);return 0;}
    
    else if(search<arr[mid])         binarySearch(arr,first,mid-1,search);
         
    else                            binarySearch(arr,mid+1,last,search);
}      
}


int main()
{
    printf("enter the array size \n");
    int size;
    scanf("%d",&size);
    int arr[size],i,res=0;
    printf("enter the array elements \n");
    
    for(i=0;i<size;i++)
    {
            scanf("%d",&arr[i]);
    }
    printf("The array before sorting \n");
    
    for(i=0;i<size;i++)
    {
            printf("%d  ",arr[i]);
    }
    
    quickSort(arr,0,size-1);
    
    printf("The array after sorting \n");
    
    for(i=0;i<size;i++)
    {
            printf("%d  ",arr[i]);
    }
   
    int search; 
    printf("enter the element to search \n");
    scanf("%d",&search);
    
    res= binarySearch(arr,0,size-1,search);
    
     if(res==9999)printf("Not found\n");
     
     getch();
     return 0;
     
}
   
