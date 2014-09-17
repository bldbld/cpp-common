#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

/*
 * KMP Algorithm.
 * ballad @ 2009 ?
 */
int *Next(char *p)
{
    int m = strlen(p);
    //assert(m>0);
    int *N = new int[m + 1];
    //assert(N!=0);
    N[0] = 0;
    int i;
    for(i = 1; i <= m; i++)
    {
        int k = N[i - 1];
        while(k > 0 && p[i] == p[k])
        {
            k = N[k - 1];
        }
        if(p[i] == p[k])
        {
            N[i] = k + 1;
        }
        else
            N[i] = 0;
    }
    return N;

}

//KMP
int KMp_Findpat(char *S, char *p, int *N, int startindex)
{
    int LastIndex = strlen(S) - strlen(p);
    if ((LastIndex - startindex) < 0)
        return (-1);
    int i;
    int j = 0;
    for(i = startindex; i < strlen(S); i++)
    {
        while(p[j] != S[i] && j > 0)
            j = N[j - 1];
        if(p[j] == S[i])
            j++;
        if(j == strlen(p))
            return (i - j + 1);
    }
    return (-1);

}

void text2()
{
    ifstream infile;
    ifstream infile2;
    infile.open("Text_s.txt");
    infile2.open("Text_p.txt");
    char p[6];
    char s[11];
    //p=new char[6];
    //s=new char[11];
    int i = 0, j = 0;
    while (i < 10)
    {
        infile.get(s[i]);
        i++;
    }

    while (j < 5)
    {
        infile2.get(p[j]);
        j++;
    }
    s[i] = '\0';
    p[j] = '\0';
    int x;
    int *N;
    cout << p << endl;
    cout << s << endl;
    N = new int[11];
    N = Next(p);
    x = KMp_Findpat(s, p, N, 0);
    cout << x << endl;
    infile.close();
    infile2.close();
}

void text1()
{
    int x;
    int *N;
    N = new int[11];
    N = Next("EFGHI");
    x = KMp_Findpat("ABCDEFGHIJ", "EFGHI", N, 0);
    cout << x << endl;
}

int main ()
{
    text1();
    text2();
    return 0;
}

