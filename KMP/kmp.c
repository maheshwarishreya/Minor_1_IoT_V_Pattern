#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void computeLPS(char *pat, int m, int *lps);

bool kmp_search(char *pat, char *text)
{
    int m = strlen(pat);
    int n = strlen(text);
    int lps[m];
    computeLPS(pat, m, lps);
    int i = 0;
    int j = 0;
    int res = 0;
    while (i < n && j < m)
    {
        if (text[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j > 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    if (j == m)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void computeLPS(char *pat, int m, int *lps)
{
    int i = 1;
    lps[0] = 0;
    int j = 0;
    while (i < m)
    {
        if (pat[i] != pat[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
        else
        {
            lps[i] = (j + 1);
            i++;
            j++;
        }
    }
}
bool executeKMP(char *pat, char *text)
{
    bool result = kmp_search(pat, text);
    return result;
}