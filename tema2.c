
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
void quicksort(int number[], int first, int last){
int pivot, i, j, temp;
if(first < last){
    pivot = first;
    i=first;
    j=last;
    while(i < j){
        while(number[i] <= number[pivot] && i < last)
            i++;
            while(number[j] > number[pivot])
            j--;
            if(i < j){
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
    }
    temp = number[pivot];
    number[pivot] = number[j];
    number[j] = temp;
    quicksort(number, first, j-1);
    quicksort(number, j+1, last);
}
}
int main()
{
    int n, i;
    printf("enter the length of the array:");
    scanf(" %d", &n);

    int a[n];

    printf("enter the elements of the array:");
    for ( i = 0; i < n; i++){
        scanf(" %d", &a[i]);
    }

    int b[n];
    for (i = 0; i < n; i++){
        b[i] = a[i];
    }

            printf(" \n \n");

    int j,value, temp, flag, min, imin, k, t;
    clock_t m;
    double time_taken;

//BubbleSort
m = clock();

    for (i = n-1; i > 0; j++){ //"i" goes to the end of the array and comes to the beginning with each cycle
        flag = 1; //records the fact that no change has been made yet
        for(j = 0; j<i; j++){ //"j" from the beginning of the matrix goes to "i" with each cycle
            if(b[j] > b[j+1]){ // if the value of b[j] is bigger than the one in b[j+1] then
                flag = 0; // a change will be executed, and the flag records this
                temp = b[j]; // here the exchange of places between high and low values is performed
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
        if(flag){ //here it is checked if any change was made in the matrix, and if there was none, the cycle stops
            break;
        }
    }//thus each value goes towards the end of the array until it reaches a value greater than itself if it exists

m = clock() - m;
time_taken = ((double)m)/CLOCKS_PER_SEC;

    printf("the array sorted by BubbleSort in %f seconds: ", time_taken);

    for(i=0; i<n; i++){
        printf(" %d", b[i]);
    }

//
    for (i = 0; i < n; i++){
        b[i]=a[i];
    }
    printf(" \n \n");

//InsertionSort
m = clock();

    for(i=1; i < n; i++){ //i goes to the end of the array
        value = b[i];//stores the value from b[i]
        for(j = i-1; (j >= 0) && (value < b[j]); j--){ //check all the values from i to the beginning of the array, to find a larger value and exchange places with it, so, to move all the bigger values to make a new space for the value from b[i]
            b[j+1] = b[j]; //the exchange of places between low and high values is performed
        }
        b[j+1] = value; //here the place created by the cycle above is occupied by the initial value of b[i]
    } //thus the smaller values go to the left end of the matrix, moving the larger values to the right during the process

m = clock() - m;
time_taken = ((double)m)/CLOCKS_PER_SEC;

    printf("the array sorted by Insertion Sort in %f seconds: ", time_taken);
    for(i = 0; i<n; i++){
        printf(" %d", b[i]);
    }

//
    for (i = 0; i < n; i++){
        b[i]=a[i];
    }
    printf(" \n \n");


//Linear Selection Sort
m = clock();

    for(i = 0; i < n-1; i++){//from the beginning to the end
         min = b[i];
         imin = i;
         for(j = i+1; j < n; j++){//from i+1 to n
            if(b[j] < min){//looking for the smallest value of b between i and n
                min = b[j];//storing the value
                imin = j;// and the place
            }
         }
         b[imin] = b[i];//switching places
         b[i] = min;
    }//thus, for all the places from left to right, the smallest values, greater than those already sorted, are searched for

m = clock() - m;
time_taken = ((double)m)/CLOCKS_PER_SEC;

    printf("the array sortded by Linear Selection Sort in %f seconds: ", time_taken );
    for(i = 0; i < n; i++){
        printf(" %d", b[i]);
    }
//
    for (i = 0; i < n; i++){
        b[i]=a[i];
    }
    printf(" \n \n");


//Selection and Change
m = clock();

    for(i = 0; i < n-1; i++){
        for(k = i+1; k < n; k++){
            if(b[k] < b[i]){
                t = b[k];
                b[k] = b[i];
                b[i] = t;
            }
        }
    }//here, every time a lower value is found, places are exchanged, and so on until it is sorted

m = clock() - m;
time_taken = ((double)m)/CLOCKS_PER_SEC;

    printf("the array sorted by Selection and Change in %f seconds: ", time_taken );
    for(i = 0; i < n; i++){
        printf(" %d", b[i]);
    }
//

for (i = 0; i < n; i++){
        b[i]=a[i];
    }
    printf(" \n \n");


//Quick-sort
m = clock();

quicksort(b, 0, n-1);

m = clock() - m;
time_taken = ((double)m)/CLOCKS_PER_SEC;

    printf("the array sorted by Quick-sort in %f seconds: ", time_taken);
    for(i = 0; i<n; i++){
        printf(" %d", b[i]);
    }

//
    for (i = 0; i < n; i++){
        b[i]=a[i];
    }
    printf(" \n \n");



return 0;
}
