// Osmolovsky K.A. BBBO-04-23 11 var
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

void dialog(double& x, double& y, double& z, double& step, int& num){
    system("clear || cls");
    int correct = 0;
    printf("Please, specify values of x, y, z, step and num.\nEnter x: ");
    correct = scanf("%lf%*c", &x);
    while(!correct){
        printf("Wrong input! Reenter x: ");
        correct = scanf("%lf", &x);
        while(getchar() != '\n');
    } 

    printf("Enter y: ");
    correct = scanf("%lf%*c", &y);
    while(correct != 1){
        printf("Wrong input! Reenter y: ");
        correct = scanf("%lf", &y);
        while(getchar() != '\n');
    }
    printf("Enter z:");
    correct = scanf("%lf%*c", &z);
    while(correct != 1){
        printf("Wrong input! Reenter z: ");
        correct = scanf("%lf", &z);
        while(getchar() != '\n');
    }
    printf("Enter step:");
    correct = scanf("%lf%*c", &step);
    while(correct != 1){
        printf("Wrong input! Reenter step: ");
        correct = scanf("%lf", &step);
        while(getchar() != '\n');
    }
    printf("Enter num:");
    correct = scanf("%d%*c", &num);
    while(correct != 1 || num <= 0){
        printf("Wrong input! Reenter num: ");
        correct = scanf("%d", &num);
        while(getchar() != '\n');
    }
}


double* calcA(double x, double y, double z, double step, int num){
    double* result = new double[num];
    for(int i=0; i<num; i++){
        result[i] = exp(6.8 * z) + y * ( x * sqrt(y));
        z += step;
    }
    return result;
}

double* calcB(double x, double y, double z, double step, int num){
    double* result = new double[num];
    int i=0;
    while(i<num){
        result[i] = sqrt(y + x) - z;
        z += step;
        i++;
    }
    return result;
}

double* calcC(double x, double y, double z, double step, int num, int j){
    double* result = new double[num-j+1];
    result[0] = num-j;
    int i=1;
    do{
        result[i] = tan(x) - y * sqrt(pow(z, 3));
        z += step;
        i++;
    }while(i<num-j+1);
    return result;
}

void printArray(double* arr, int size){
    for(int i=0; i<size; i++){
        printf("[%d] = %.3f\n", i,  arr[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    double x=0, y=0, z=0, step=0;
    int num=0;
    char ex = 'f';
    
    if(argc == 6){
        if(atof(argv[1]) &&  atof(argv[2]) &&  atof(argv[3]) &&  atof(argv[4]) &&  atof(argv[5]))
        { 
            x = atof(argv[1]);
            y = atof(argv[2]);
            z = atof(argv[3]);
            step = atof(argv[4]);
            num = atoi(argv[5]);
        }
        else {
            printf("Incorrect input values!\n");
            dialog(x, y, z, step, num);
        }
    }
    else {
        printf("Incorrect input values!\n");
        dialog(x, y, z, step, num);
    }
    do {

        if(ex != 'f') system("clear || cls");
        printf("Author: Kirill Osmolovsky, BBBO-04-23, 11 variant\n");
        printf("Menu:\n(1) Input values\n(2) Calculate A\n(3) Calculate B\n(4) Calculate C\n(5) Exit program\n");
        scanf("%c%*c", &ex);
        switch(ex){
            case '1':
                dialog(x, y, z, step, num);
                break;
            case '2':{
                printf("Input values: x = %.3lf y = %.3lf z = %.3lf step = %.3lf num = %d\n", x, y, z, step, num);
                if(y<0){
                    printf("Can't calculate A: y < 0\n");
                }
                else {
                    double* A = calcA(x, y, z, step, num);
                    printf("Array A:\n");
                    printArray(A, num);
                }
                printf("(type enter to clear the screen) ");
                while(getchar() != '\n');
                break;}
            case '3':{
                printf("Input values: x = %.3lf y = %.3lf z = %.3lf step = %.3lf num = %d\n", x, y, z, step, num);
                if(x+y<0){
                    printf("Can't calculate B: x+y < 0\n");
                }
                else {
                    double* B = calcB(x, y, z, step, num);
                    printf("Array B:\n");
                    printArray(B, num);
                }
                printf("(type enter to clear the screen) ");
                while(getchar() != '\n');
                break;}
            case '4':{
                printf("Input values: x = %.3lf y = %.3lf z = %.3lf step = %.3lf num = %d\n", x, y, z, step, num);
                int j=0;
                if(z<0){
                for( ; z < 0 && j < num; j++){
                    z += step;   
                }
                if(z < 0){
                    printf("There is no calculates for C\n");
                    while(getchar() != '\n');
                    break;
                    }
                }
                double* C = calcC(x, y, z, step, num, j);
                printf("Array C:\n");
                printArray((C+1), C[0]);
                printf("(type enter to clear the screen) ");
                while(getchar() != '\n');
                break;}
            case '5':{
                printf("Exit? y/n ");
                scanf("%c%*c", &ex);
                break;}
        }
    } while(ex != 'y');
    return 0; 
}
