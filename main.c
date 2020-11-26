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
    printf("length = %ld \n", length);
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
double getMilliseconds() {
    return  clock() / CLOCKS_PER_SEC;
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
        double sv;
         clock_t startKmp, endKmp;
        // sv = -getMilliseconds();
        startKmp = clock();
        bool resKMP = executeKMP(inputPattern, inputText);
        printf(resKMP ? "true \n" : "false \n");
        endKmp = clock();
        //   sv += getMilliseconds();
        double resKMPi = (double)(endKmp - startKmp) / CLOCKS_PER_SEC;
        printf("Elapsed Milliseconds = %f\n", resKMPi);
        start = clock();
        bool resRabinKarp = executeRabinKarp(inputPattern, inputText);
        printf(resRabinKarp ? "true \n" : "false \n");
          end = clock();

        totalTime = (double)(end - start)/CLOCKS_PER_SEC;
        printf("%ld \n", start);
         printf("%ld \n", end);
         printf("elapsed time %f \n", totalTime);
         bool resBoyerMoore= executeBoyerMoore(inputPattern, inputText);
        printf(resBoyerMoore ? "true \n" : "false \n");
      return 0;
}