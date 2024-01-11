// Osmolovsky K.A. BBBO-04-23 11 var
#include "stdio.h"
#include <cstring>

void input(char *s){ 
    printf("Please, enter you sentence (maximum 255 characters): ");
    gets(s);
}

void print(char *s){
    puts(s);
}
void print2level(char s[][256], int length){
      for(int i=0; i< length; i++){
        printf("%s ", s[i]);
      }
      printf("\n");
}

void magic(char *s){
    int word_count = 0, current_pos = 0;
    char n[128][256];
    for(int i=0; s[i] != '\0'; i++){
        if(i == 0 && s[i] != ' '){
            n[word_count][current_pos] = s[i];
            current_pos++;
            continue;
    }
        if(s[i] != ' ' && s[i-1] == ' '){
            word_count++; 
            n[word_count][current_pos] = s[i];
            current_pos++;
        }
        if(s[i] != ' ' && s[i-1] != ' '){
            n[word_count][current_pos] = s[i];
            current_pos++; 
        } 
        if(s[i] == ' '){
            current_pos = 0;
        }
    }

    for(int i=0; i < word_count; i++){
        for(int j = i+1; j <= word_count; j++){
            if(strlen(n[i]) > strlen(n[j])){
                char *buf = new char[256];
                strcpy(buf, n[i]);
                strcpy(n[i], n[j]);
                strcpy(n[j], buf);
                delete[] buf;
            }
        }
    }
    printf("Same sentence in ascending word lenghts order:\n");
    print2level(n, word_count+1);
    
}

int main() {
    char s[256];
    printf("Author: Kirill Osmolovsky, BBBO-04-23, 11 variant\n");
    input(s);
    magic(s);

    return 0; 
}
