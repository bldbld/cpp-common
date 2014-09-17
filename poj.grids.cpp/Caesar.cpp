#include <iostream>
#include <string>

using namespace std;

// POJ Test
// Carser Code
// Author : ballad
// Date : 2008-10-01
void decipher(char message[])
{
    char plain[27] = "VWXYZABCDEFGHIJKLMNOPQRSTU";
    char cipherEnd[20];
    int i, cipherLen;
    gets(message);
    cipherLen = strlen(message);
    for(i = 0; i < cipherLen; i++)
    {
        if (message[i] >= 'A' && message[i] <= 'Z')
            message[i] = plain[message[i] - 'A'];
    }
    gets(cipherEnd);
    return;
}

void main ()
{
    char message[30];
    gets(message);
    while (strcmp(message, "START") == 0)
    {
        decipher (message);
        cout << message << endl;
        gets(message);
    }
}