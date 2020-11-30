#include <stdio.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define totalChars 256

int max(int, int);
bool search(char *, char *);
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
bool search(char *pat, char *txt){
    int m = strlen(pat);
    int n = strlen(txt);
    //int *tab[totalChars];
    int *tab = (int *)malloc(totalChars * sizeof(int));
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
           return true; 
            s += (s+m < n)? m-tab[txt[s+m]] : 1; 
        } 
        else
            s += max(1, j - tab[txt[s+j]]); 
    } 
    if(flag == 0)
       return false;
} 
bool executeBoyerMoore(char *pat, char *text){ 
   bool result = search(pat, text);
   return result;
 }

 /*int  boyermoorematch(char S[ ], char P[ ])‏
{
	int n, m, i, j, lastch;  n = strlen(S);  m = strlen(P);
	i = m – 1; j = m – 1;
	while  (i < n) 		//  not end of string S
		if  (P[j] == S[i])  
			if  (j == 0) 	// first char of pattern
				return  i;
			else
			{
				j--;  i--;	//  go left
			}
		else		//  no match – find char in pattern
		{
			lastch = find(P, S[i]);
			if  (lastch == -1) 	// not found
				i = i + m;		// jump over
			else
				i = i + j – lastch;	// align char
			j = m – 1;	// restart from right
		}
	return  -1;	//  not matched
}

int  find(char P[ ], char  ch)‏
{
	int m, i;  m = length(P);
	for  (i = m – 2; i >= 0; i--)‏
	{
		if  (ch == P[i])‏
		{
			return  i;
		}
	}
	return  -1;
}*/