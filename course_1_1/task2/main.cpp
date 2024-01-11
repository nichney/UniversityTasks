#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    
    char c;
    int n;
    short a=0, b=0;
    short *result;

    do {
     system("clear");
     printf("Program has been made by Osmolovskiy K.A., BBBO-04-23, 11-th variant\n");
     printf("Please, enter first value of short type:\n");
     scanf("%hx", &a);
     printf("Please, enter second value of short type:\n");
     scanf("%hx", &b);
     fflush(stdin);
     printf("Entered numbers: %#x %#x\n", a, b);

     unsigned char a1, a2, b1, b2;
     a1 = a;
     a2 = a >> 8;
     b1 = b;
     b2 = b >> 8;
     printf("Bytes of first number: %#x %#x\n", a2, a1);
     printf("Bytes of second number: %#x %#x\n", b2, b1);
   
     result = new short(0);
     *((unsigned char*) result) = (unsigned char) (a1+b1);
     *((unsigned char*) result + 1) = (unsigned char) (a2*b2);

     printf("New short number binary:\n");
     for(int i=15; i >= 0; i--)
         printf("%d ", (short)*result >> i  & 1);
     printf("\nAddress: %p\n", result);
     
     printf("Enter N for check bit number N (0 - 15):\n");
     scanf("%d", &n);
     while(1){
        if(n<0 || n > 15) {
            printf("Wrong value. Please, reenter:\n");
            scanf("%d", &n);
        } else {
        printf("Checked bit is %x\n", *result >> n & 1);
        if( *result >> n & 1 ){
            printf("Sum of bytes of number %#x = %#x\n", *result, a1+b1+a2*b2);
        }
       break;
        }
     }

     printf("Exit? y/n\n");
     c = getchar();
    } while(c != 'y');
    return 0;
}
