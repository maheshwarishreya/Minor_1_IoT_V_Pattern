#include "./KMP/kmp.c"
#include "./Rabin_Karp/RabinKarp.c"
#include "./Boyer-Moore/Boyer_Moore.c"
#include<stdlib.h>
#include<time.h>

long fsize (FILE *in){
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
    return 10000.0* clock() / CLOCKS_PER_SEC;
}
int main(){
    time_t a, b;
    a = time(NULL);
    clock_t start, end;
    long long int totalTime;
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
         sv = -getMilliseconds();
        startKmp = clock();
        bool resKMP = executeKMP(inputPattern, inputText);
        printf(resKMP ? "Kmp result is true \n" : "KMP result is false \n");
        endKmp = clock();
          sv += getMilliseconds();
        double resKMPi = (double)(endKmp - startKmp) / CLOCKS_PER_SEC;
         printf("Elapsed Milliseconds actual = %f\n", sv);
        printf("Elapsed seconds = %f\n", resKMPi);
        start = clock();
        bool resRabinKarp = executeRabinKarp(inputPattern, inputText);
        printf(resRabinKarp ? "rabin karp result is true \n" : "rabin karp result is false \n");
          end = clock();
        totalTime = (long long int)(end - start);
        printf("%ld \n", start);
         printf("%ld \n", end);
         printf("elapsed time total time %lld \n", totalTime);
         bool resBoyerMoore= executeBoyerMoore(inputPattern, inputText);
         b = time(NULL);
         printf("difference is %ld",(b-a));
        printf(resBoyerMoore ? "boyer moore result is true \n" : "boyer moore result is false \n");

      return 0;
}