#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define r 256

// int generate_hash(char s[], int a, int q){

//     int h = 0;
//     int i;
    
//     for(i = 0; i < a; i++){
//       h = (h * r + s[i]) % q;  
//     }
//     return h;
// }
// bool match(char pat[], char text[], char text2[], int q){
    
//     int plen = strlen(pat);
//     int tlen = strlen(text);
//     int i, j;
//     int rm = 1; 
//     int pat_h = 0;
//     int text_h = 0;
    
//     for(i = 0; i < plen - 1; i++)
//         rm = (rm * r) % q;
    
//         pat_h = generate_hash(pat, plen, q); 
//         text_h = generate_hash(text, plen, q); 
//     int var = 0;
//     for(i = 0; i <= tlen - plen; i++){
        
//         if(pat_h == text_h){
//             for(j = 0; j < plen; j++){
                
//                 if(text[i+j] != pat[j]){
//                     break;
                    
//                 }
//             }
//              if(j == plen){
//                  var++;
//                  return true;
//              }
//         }
//         if(i < tlen - plen){
//             text_h = (r * (text_h - text[i] * rm) + text[i + plen]) % q;
//             if(text_h < 0){
//                 text_h = (text_h + q);
//             }
//         }
//     }
//     if(var == 0){
//        return false;
//     }
// }
    bool executeRabinKarp(char *pat, char *text){ 
    long lPattern = strlen(pat);
    long lText = strlen(text);
    long lTextFirstHalf = lText/2 + lPattern;// 10
    long lTextSecondHalf = lText - lText/2 + lPattern;//11
    char new_text1[lTextFirstHalf];
    char new_text2[lTextSecondHalf];
    int  i;
    for(i = 0; i < lTextFirstHalf; i++){
        new_text1[i] = text[i]; 
    }
    printf("%ld \n", lText);
    printf("%ld \n", lPattern);
    int var = (lText - ((lText - lText/2) + lPattern));
    printf("%d \n",var);
    for(i = 0; i < lTextSecondHalf; i++){
        new_text2[i] = text[i + var ];// 0+(15-(15-7)+3)= (15-8+3) =(4)
    }
 
    for(i = 0; i < lTextFirstHalf; i++){
        printf("%c", new_text1[i]); 
    }
    printf("\n");
    for(i = 0; i < lTextSecondHalf; i++){
        printf("%c",new_text2[i]);// 0+()
    }
     // bool result = match(pat, new_text1, new_text2, 101);
    return true;
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
 int main(){
     bool var = executeRabinKarp( "bvb","shreyabvbshreya");
     return 0;
 }