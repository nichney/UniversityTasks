#include <cstdio>
#include <cstdlib>
#include <cstring>

struct good {
    char name[30];
    int art;
    int count;
    int price;
    char in[30];
    char out[30];
};

void cls(){
    system("cls || clear");
}


void createDatabase(const char *name, good *base, int size){
    FILE *fp;
    fp = fopen(name, "wb");
    fwrite(base, sizeof(good), size, fp);
    fclose(fp);
}


void printDatabase(good *base, int size){
    cls();
    printf("No    Name  Article  Count   Cost   Import date   Export date\n");
    for(int i=0; i<size; i++){
        printf("%3d %7s %7d %5d %5d %11s %11s\n", i+1, (base+i)->name, (base+i)->art, (base+i)->count, (base+i)->price, (base+i)->in, (base+i)->out);
    }
}

good *add2base(const char *name, good *base, int *size){
    cls();
    int increment, i;
    printf("How many fields do you want to add?\n");
    scanf("%d%*c", &increment);
    good *newbase = new good[*size+increment];
    for(i=0; i<*size; i++){
        *(newbase+i) = *(base+i);
    }
    for(; i< (*size+increment); i++){
        good tmp; 
        printf("Enter name: ");
        scanf("%s%*c", tmp.name);
        printf("Enter article: ");
        scanf("%d%*c", &tmp.art);
        printf("Enter count: ");
        scanf("%d%*c", &tmp.count);
        printf("Enter cost: ");
        scanf("%d%*c", &tmp.price);
        printf("Enter import date: ");
        scanf("%s%*c", tmp.in);
        printf("Enter export date: ");
        scanf("%s%*c", tmp.out);
        *(newbase + i) = tmp;
    }
    *size += increment;
    createDatabase(name, newbase, *size);
    return newbase;
}

good *readDatabase(const char *name, int *returned_size){
    FILE *fp;   
    fp = fopen(name, "rb");
    if(fp == NULL){
        printf("No such file!!! Please, add field to database and write them to file!");
        while( getchar() != '\n');
        *returned_size = 0;
        return add2base(name, nullptr, returned_size);
    }
    good *tmp;
    int size = fread(tmp, sizeof(good), 10000,  fp);
    rewind(fp);
    good *base = new good[size];
    for(int i=0; i<size; i++){
        fread( (base+i), sizeof(good), 1,  fp  );
    }
    fclose(fp);
    *returned_size = size;
    return base;
}

void search(const char* name, good *base, int *size){
    cls();
    int searched = 0;
    char filename[30];
    printf("Please, enter number of element you're looking for: ");
    scanf("%d%*c", &searched);
    searched--;
    printf("Please, enter name of file to save result: ");
    scanf("%s%*c", filename);
    FILE *fp;   
    fp = fopen(filename, "at");
    if(searched > *size){
        fprintf(fp, "Result of your request: there is no field number %d!\n", searched+1);
    }
    else{
        fprintf(fp, "Result of your request: %7s %7d %5d %5d %11s %11s\n", (base+searched)->name, (base+searched)->art, (base+searched)->count, (base + searched)->price, (base+searched)->in, (base+searched)->out);
    }
    fclose(fp);

}

int main(int argc, char* argv[]){
    char name[30];
    good *base = nullptr;
    int size = 0;
    strcpy(name, argv[1]);
    char code = 'f';
    do {
        cls();
        printf("Author: Osmolovsky K.A., BBBBO-04-23, 11 variant\n");
        printf("Some menu:\n(1) Create database\n(2) Print database\n(3) Add to database\n(4) Search by number\n(5) Exit");
        scanf("%c%*c", &code);
        switch(code){
            case '1': {
                      createDatabase(name, base, size);
                      break;
                      }
            case '2': {
                      if(base == nullptr){
                        base = readDatabase(name, &size);
                      }
                      if(base != nullptr){
                      printDatabase(base, size);
                      break;}
                      }
            case '3': {
                      base = add2base(name, base, &size);
                      break;
                      }
            case '4': {
                      if(base == nullptr){
                        base = readDatabase(name, &size);
                      }
                      if(base != nullptr){
                      search(name, base, &size);
                      break;}
                      }
            case '5': {
                      printf("Exit? y/n");
                      scanf("%c%*c", &code);
                      break;
                      }
        
        }
    
    
    } while(code != 'y');

    delete[] base;
    return 0;
}
