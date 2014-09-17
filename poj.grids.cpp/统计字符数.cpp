// Author : ballad
// Date : 2008-10-01

void main ()
{
    int cases, sum[26], i, max;
    char str[1001];
    cin >> cases;
    while (cases-- > 0)
    {
        gets(str);
        for (i = 0; i < 26; i++)
            sum[i] = 0;
        for (i = 0; i < strlen(str); i++)
            sum[str[i] - 'a']++;
        max = 0;
        for (i = 1; i < 26; i++)
            if(sum[i] > sum[max])
                max = i;
        cout << sum[max] << endl;

    }
}