#include <stdio.h>
#include<string.h>
#include<stdio.h>
#define totalChars 256

int max(int, int);
void search(char *, char *);
void table(char *, int, int[]);

int max(int a, int b){
    if(a >= b){
        return a;
    }
    else{
        return b;
    } 
}
void table(char *str, int len, int tab[totalChars]){
        int i;
        for(i = 0; i < len; i++){
            tab[i] = -1;
        }
        for(i = 0; i < len; i++){
            tab[(int)str[i]] = i;
        }   
}

void search(char *pat, char *txt){
    int m = strlen(pat);
    int n = strlen(txt);
    int tab[totalChars];
    table(pat, m, tab);
    int s = 0; 
    int flag = 0;
    while(s <= (n - m)) 
    { 
         int j = m-1; 
        while(j >= 0 && pat[j] == txt[s+j]) 
            j--;
        if (j < 0) 
        { 
            flag++;
            printf(" pattern present \n"); 
            s += (s+m < n)? m-tab[txt[s+m]] : 1; 
        } 
        else
            s += max(1, j - tab[txt[s+j]]); 
    } 
    if(flag == 0)
        printf("pattern does not exists \n");
} 
int main(){
    char txt[] = "Hello I am in Upes."; 
    char pat[] = "I am a";
    search(pat, txt);
    return 0;
}