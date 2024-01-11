// Осмоловский, БББО-04-23, 11 вариант
#include <cstdio>
#include <math.h>

int main() {
    printf("Author: Osmolovskiy K.A. BBBO-04-23, 11 variant\n");
    int N = 1, R=0, count_GR=0;
    printf("Please, enter count of elements of array: ");
    scanf("%d", &N);
    int *arr = new int[N];
    
    for(int i=0; i<N; i++){
        arr[i] = rand() % 101 - 50; // from -50 to 50
        printf("arr[%2d] = %d\n", i, arr[i]);
    }
    printf("Please, enter R (for count elements greather than R): ");
    scanf("%d", &R);

    for(int i=0; i<N; i++){
        if(arr[i] > R )
            count_GR += 1;
    }
    printf("Count of elements greather than R: %d\n", count_GR);

    int g_index=0, prod=1, count_GM=0;
    for(int i=1; i<N; i++){
        // greatest for magnitude
        if(abs(arr[g_index]) < abs(arr[i]))
            g_index = i;
    }
    printf("Greatest element by magnitude is arr[%d] = %d\n", g_index, arr[g_index]);
    for(int i = g_index+1; i<N; i++){
        prod *= arr[i];
        count_GM += 1;
    }
    printf("Product of elements after greatest by magnitude: %d\n", count_GM > 0 ? prod : 0);
    int max_i;
    // selection sort
    for(int i=0; i<N; i++){
        max_i = i;
        for(int j=i; j<N; j++){
            if(arr[max_i] < arr[j])
                max_i = j;
        }
        int buf = arr[i];
        arr[i] = arr[max_i];
        arr[max_i] = buf;
    
    }

    printf("Sorted array:\n");
    for(int i=0; i<N; i++){
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    delete[] arr;

    return 0;
}
