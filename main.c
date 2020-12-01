#include "./KMP/kmp.c"
#include "./Rabin_Karp/RabinKarp.c"
#include "./Boyer-Moore/Boyer_Moore.c"
#include "./SelfMade/SelfMade.c"
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"


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
  printf("\n");
  printf("\n");
  printf(ANSI_COLOR_GREEN  "**********************WELCOME*********************"  ANSI_COLOR_RESET "\n");
  printf("\n");
  printf("\n");
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
  printf(ANSI_COLOR_YELLOW "--------------------------------------------------------------------------------------------------" ANSI_COLOR_RESET "\n");
  printf("\n");
  printf(ANSI_COLOR_MAGENTA "SELF MADE ALGORITHM" ANSI_COLOR_RESET "\n");
  printf("\n");
  long startSelf = gettime();
  bool self = executeSelf(inputPattern, inputText);
  printf(self ? "Self Made algorithm found the pattern match in the text \n" : "Self Made algorithm did not find the pattern match in the text \n");
  long endSelf = gettime();
  printf("time taken %ld\n", (endSelf - startSelf));
  printf(ANSI_COLOR_YELLOW "--------------------------------------------------------------------------------------------------" ANSI_COLOR_RESET "\n");
  printf("\n");
  printf(ANSI_COLOR_MAGENTA "KNUTH MORRIS PRATT(KMP) ALGORITHM" ANSI_COLOR_RESET "\n");
  printf("\n");
  long startKMP = gettime();
  bool resKMP = executeKMP(inputPattern, inputText);
  printf(resKMP ? "KMP algorithm found the pattern match in the text \n" : "KMP algorithm did not find the pattern match in the text \n");
  long endKMP = gettime();
  printf("time taken %ld\n", (endKMP - startKMP));
  printf(ANSI_COLOR_YELLOW "--------------------------------------------------------------------------------------------------" ANSI_COLOR_RESET "\n");
  printf("\n");
  printf(ANSI_COLOR_MAGENTA "RABIN KARP ALGORITHM" ANSI_COLOR_RESET "\n");
  printf("\n");
  long startRK = gettime();
  bool resRabinKarp = executeRabinKarp(inputPattern, inputText);
  printf(resRabinKarp ? "Rabin Karp algorithm found the pattern match in the text \n" : "Rabin Karp algorithm did not find the pattern match in the text \n");
  long endRK = gettime();
  printf("time taken %ld\n", (endRK - startRK));
  printf(ANSI_COLOR_YELLOW "--------------------------------------------------------------------------------------------------" ANSI_COLOR_RESET "\n");
  printf("\n");
  printf(ANSI_COLOR_MAGENTA "BOYER MOORE ALGORITHM" ANSI_COLOR_RESET "\n");
  printf("\n");
  long startBM = gettime();
  bool resBoyerMoore = executeBoyerMoore(inputPattern, inputText);
  printf(resBoyerMoore ? "Boyer Moore algorithm found the pattern match in the text \n" : "Boyer Moore algorithm did not find the pattern match in the text \n");
  long endBM = gettime();
  printf("time taken %ld\n", (endBM - startBM));
  printf(ANSI_COLOR_YELLOW "--------------------------------------------------------------------------------------------------" ANSI_COLOR_RESET "\n");
  printf("\n");
  printf("\n");
  printf(ANSI_COLOR_GREEN  "**********************END*********************"  ANSI_COLOR_RESET "\n");
  printf("\n");
  printf("\n");
  return 0;
}