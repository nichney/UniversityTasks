#include <cstdio>
#include <cmath>
#include <cstdlib>

void printArray(double* arr, int size){
    for(int i =0; i<size; i++){
        printf("%lf ", arr[i]);
    }
    printf("\n");
}

void dialog(int *a, int *b){
    printf("Please, enter A: ");
    scanf("%d", a);
    printf("Please, enter B: ");
    scanf("%d", b);
}

void swap(double *f, double *s){
    double buf = *s;
    *s = *f;
    *f = buf;
}

void do_sort(double *arr, int n, int a, int b){
    int j = 0;
    for(int i=0; i < n; i++){
        if(arr[i] > a && arr[i] < b){
            swap(&arr[i], &arr[j]);
            j++;
        }
    }
    printArray(arr, n);
    FILE *wf; // file to write
    wf = fopen("rez_5.txt", "a");
    fprintf(wf, "Sorted array: ");
    for(int i = 0; i < n; i++){
        fprintf(wf, "%lf ", arr[i]);
    }
    fprintf(wf, "\n");
    fclose(wf);
}

double* read2array(FILE *fp, int n){
    FILE *wf;
    wf = fopen("rez_5.txt", "a");
    fprintf(wf, "Default array: ");

    double *arr = new double[n];
    for(int i = 0; i < n; i++){
        fscanf(fp, "%lf", &arr[i]);
        fprintf(wf, "%lf ", arr[i]);
    }
    fprintf(wf, "\n");
    fclose(fp);
    fclose(wf);
    return arr;
}

void maximum(double *arr, int n){
    FILE *wf;
    wf = fopen("rez_5.txt", "a");

    double maximum = arr[0];
    int i = 1;
    for(; i<n; i++){
        if(abs(maximum) < abs(arr[i])){
            maximum = arr[i];
        }
    }
    printf("\nmax(arr) = arr[%d] = %lf\n", i, maximum);
    fprintf(wf, "\nmax(arr) = arr[%d] = %lf\n", i, maximum);
    fclose(wf);
}

void sumof(double *arr, int n){
    FILE *wf;
    wf = fopen("rez_5.txt", "a");
    bool flag = false;
    double result = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            flag = true;
        }
        if(flag){
            result += arr[i];
        }
    }

    printf("\nSum of elements after first not-negative: %lf\n", result);
    fprintf(wf, "\nSum of elements after first not-negative: %lf\n", result);
}

int main(){
    printf("Author: Osmolovsky K.A, BBBO-04-23, 11 variant\n");

    FILE *fp;
    fp = fopen("task_5_dbl.dat", "r");
    int n = 0;
    while(!feof(fp)){
        fscanf(fp, "%*lf");
        n++;
    }
    rewind(fp);
    double *arr = read2array(fp, n);
    printArray(arr, n);
    maximum(arr, n);
    sumof(arr, n);
    int a=0, b=0;
    dialog(&a, &b);
    do_sort(arr, n, a, b);

    delete[] arr;
    return 0;
}
