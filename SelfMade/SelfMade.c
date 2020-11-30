#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define r 256

int generate_hash2(char s[], int a, int q){
    int h = 0;
    int i;
    
    for(i = 0; i < a; i++){
      h = (h * r + s[i]) % q;  
    }
    return h;
}
bool match2(char pat[], char text1[], char text2[], int q){
    
    int plen = strlen(pat);
    int t1len = strlen(text1);
    int t2len = strlen(text2);
    int i, j, k;
    int rm = 1; 
    int pat_h = 0;
    int text1_h = 0;
    int text2_h = 0;
    for(i = 0; i < plen - 1; i++)
        rm = (rm * r) % q;
    
        pat_h = generate_hash2(pat, plen, q); 
        text1_h = generate_hash2(text1, plen, q); 
        text2_h = generate_hash2(text2, plen, q);
    int var = 0;
    int cap = 0;
    for(i = 0,  k = 0; i <= t1len - plen; i++, k++){
        if(pat_h == text1_h || pat_h == text2_h){
            for(j = 0; j < plen; j++){
                
                if(text1[i+j] != pat[j] && text2[i+j] != pat[j]){
                    break;
                    
                }
            }
             if(j == plen){
                 var++;
                 return true;
             }
        }
        if(i < t1len - plen){
            text1_h = (r * (text1_h - text1[i] * rm) + text1[i + plen]) % q;
            if(text1_h < 0){
                text1_h = (text1_h + q);
            }
        }
        if(i < t2len - plen){
            text2_h = (r * (text2_h - text2[i] * rm) + text2[i + plen]) % q;
            if(text2_h < 0){
                text2_h = (text2_h + q);
            }
        }
    }
    if(var == 0){
       return false;
    }
}
    bool executeSelf(char *pat, char *text){ 
    printf("%s", "Hello World");
    int lPattern = strlen(pat);
    int lText = strlen(text);
    int lTextFirstHalf = lText/2 + lPattern;// 10
    int lTextSecondHalf = lText - lText/2 + lPattern;//11
    char *new_text1;
    char *new_text2;
    // char new_text1[lTextFirstHalf];
    // char new_text2[lTextSecondHalf];
    new_text1 = (char *)malloc(lTextFirstHalf * sizeof(char));
    new_text2 = (char *)malloc(lTextSecondHalf * sizeof(char));
    int  i;
    for(i = 0; i < lTextFirstHalf; i++){
        new_text1[i] = text[i]; 
    }
    //printf("%d \n", lText);
    //printf("%d \n", lPattern);
    int var = (lText - ((lText - lText/2) + lPattern));
    printf("%d \n",var);
    for(i = 0; i < lTextSecondHalf; i++){
        new_text2[i] = text[i + var ];// 0+(15-(15-7)+3)= (15-8+3) =(4)
    }
 
    // for(i = 0; i < lTextFirstHalf; i++){
    //     printf("%c", new_text1[i]); 
    // }
    // printf("\n");
    // for(i = 0; i < lTextSecondHalf; i++){
    //     printf("%c",new_text2[i]);// 0+()
    // }
      bool result = match2(pat, new_text1, new_text2, 101);
    return result;
    }
/*  text = 0s 1h 2a 3s 4h 5a 6b 7g 8v 9b 10s 11h 12a 13h 14a = 15 15/2 = 7
    pat = bgvb = 4 15 - 7 = 8
    f = 11
    n = 12
    nt1 = {shashabgvbsh}
    nt2 = {4h} 

    12+(15-7-4)


    text = shreyabvbshreya 15 mid 15/2 = 7 
    text1 = 7+3 = 10 shreyabvbs 
    pat = bvb 3 
    text2 = (15- 7 ) 8+3 = 11 yabvbshreya (15 - 11 = 4)
  */
//  int main(){
//      bool var = executeSelf( "bvb","shreyabvbshreya");
//      printf("\n");
//     printf("%d",var);
//      return 0;
//  }