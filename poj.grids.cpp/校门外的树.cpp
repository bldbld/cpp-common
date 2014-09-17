// Author : ballad
// Date : 2008-10-01

void main ()
{
    int L, i, j, n;
    bool trees[10001];
    for(i = 0; i < 10001; i++)
        trees[i] = true;
    cin >> L >> n;
    for(i = 0; i < n; i++)
    {
        int begin, end;
        cin >> begin >> end;
        for(j = begin; j < end; j++)
            trees[j] = false;
    }
    int count = 0;
    for(i = 0; i <= L; i++)
        if(trees[i]) count++;
    cout << count;

}