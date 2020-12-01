#include "./KMP/kmp.c"
#include "./Rabin_Karp/RabinKarp.c"
#include "./Boyer-Moore/Boyer_Moore.c"
#include "./SelfMade/SelfMade.c"
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
//#define ANSI_COLOR_MAGENTA "\x1b[35m"
//#define ANSI_COLOR_YELLOW  "\x1b[33m"


long gettime()
{
  struct timeval start;
  gettimeofday(&start, NULL);
  return start.tv_sec * 1000000 + start.tv_usec;
}

long fsize(FILE *in)
{
  long pos, length;
  pos = ftell(in);
  fseek(in, 0L, SEEK_END);
  length = ftell(in);
  fseek(in, pos, SEEK_SET);
  return length;
}
char *fileread(char *filename)
{
  FILE *inputFile = fopen(filename, "r");
  if (inputFile == NULL)
  {
    printf("Could not find input file\n");
    return "no input";
  }
  int c;
  long len = fsize(inputFile);
  if (len == 0)
  {
    printf("empty file\n");
    return "no input";
  }
  char *text = malloc(len + 1);
  int i = 0;
  while ((c = fgetc(inputFile)) != EOF)
  {
    char ch = (char)c;
    text[i++] = ch;
  }
  return text;
}

int main()
{
  printf("enter the text file name with extension \n");
  char filename[100];
  char filename2[100];
  scanf("%s", filename);
  printf("enter the pattern name with extension \n");
  scanf("%s", filename2);
  char *inputText = fileread(filename);
  char *inputPattern = fileread(filename2);
  if (inputText == "no input" || inputPattern == "no input")
  {
    return 0;
  }
  long startSelf = gettime();
  bool self = executeSelf(inputPattern, inputText);
  printf(self ? "self executed algorithm is true \n" : "self executed program is false \n");
  long endSelf = gettime();
  printf("self result %ld\n", (endSelf - startSelf));
  long startKMP = gettime();
  bool resKMP = executeKMP(inputPattern, inputText);
  printf(resKMP ? "KMP result is true \n" : "KMP result is false \n");
  long endKMP = gettime();
  printf("kmp result %ld\n", (endKMP - startKMP));
  long startRK = gettime();
  bool resRabinKarp = executeRabinKarp(inputPattern, inputText);
  printf(resRabinKarp ? "rabin karp result is true \n" : "rabin karp result is false \n");
  long endRK = gettime();
  printf("rk result %ld\n", (endRK - startRK));
  long startBM = gettime();
  bool resBoyerMoore = executeBoyerMoore(inputPattern, inputText);
  printf(resBoyerMoore ? "boyer moore result is true \n" : "boyer moore result is false \n");
  long endBM = gettime();
  printf("BM result %ld\n", (endBM - startBM));
  return 0;
}