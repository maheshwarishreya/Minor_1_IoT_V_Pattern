#include<stdio.h>
#include<string.h>
#define r 256

int generate_hash(char s[], int a, int q){

    int h = 0;
    int i;
    
    for(i = 0; i < a; i++){
      h = (h * r + s[i]) % q;  
    }
    return h;
}

void match(char pat[], char text[], int q){
    
    int plen = strlen(pat);
    int tlen = strlen(text);
    int i, j;
    int rm = 1; 
    int pat_h = 0;
    int text_h = 0;
    
    for(i = 0; i < plen - 1; i++)
        rm = (rm * r) % q;
    
        pat_h = generate_hash(pat, plen, q);
        text_h = generate_hash(text, plen, q);
    
    for(i = 0; i <= tlen - plen; i++){
        
        if(pat_h == text_h){
            for(j = 0; j < plen; j++){
                
                if(text[i+j] != pat[j]){
                    break;
                }
            }
             if(j == plen){
                 printf("Pattern found at index %d \n", i);
             }
        }
        if(i < tlen - plen){
            text_h = (r * (text_h - text[i] * rm) + text[i + plen]) % q;
            if(text_h < 0){
                text_h = (text_h + q);
            }
        }
    }
}
 int main(){
     
     char text[] = "Hello my name is Shreya, we study at upes, we are working on minor1";
     char pat[] = "we";
     int q = 101;
     match (pat, text, q);
     return 0;

 }