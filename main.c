#include "./KMP/kmp.c"
#include "./Rabin_Karp/RabinKarp.c"
#include "./Boyer-Moore/Boyer_Moore.c"
#include<stdlib.h>
#include<time.h>

long fsize (FILE *in)
{
    long pos, length;
    pos = ftell(in);
    fseek(in, 0L, SEEK_END);
    length = ftell(in);
    fseek(in, pos, SEEK_SET);
    return length;
}
char* fileread(char* filename){
    FILE *inputFile = fopen(filename, "r" );
      if ( inputFile== NULL ){
        printf( "Could not find input file\n" );
        return "no input";
     }
    int c;
    long len = fsize(inputFile);
    if(len == 0){
        printf( "empty file\n" );
        return "no input";
    }
    char *text = malloc(len+1);
    int i = 0; 
    while((c = fgetc(inputFile))!=EOF){
        char ch = (char)c;
        text[i++] = ch;
      }
      return text;
}
int main(){
    clock_t start, end;
    double totalTime;
    printf("enter the text file name with extension \n");
    char filename[100];
    char filename2[100];
    scanf("%s", filename);
    printf("enter the pattern name with extension \n");
    scanf("%s",filename2);
     char* inputText = fileread(filename);
     char* inputPattern = fileread(filename2);
     if(inputText == "no input" || inputPattern == "no input"){
         return 0;
     }
    //  printf("%s\n",inputText);
    //  printf("%s\n",inputPattern);
        start = clock()*10000;
        bool resKMP = executeKMP(inputPattern, inputText);
        printf(resKMP ? "true \n" : "false \n");
         end = clock()*10000000;
        totalTime = (double)(end - start);
        printf("%f \n", totalTime);
        bool resRabinKarp = executeRabinKarp(inputPattern, inputText);
        printf(resRabinKarp ? "true \n" : "false \n");
         
         bool resBoyerMoore= executeBoyerMoore(inputPattern, inputText);
        printf(resBoyerMoore ? "true \n" : "false \n");
      return 0;
}