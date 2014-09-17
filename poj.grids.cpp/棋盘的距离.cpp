// Author : ballad
// Date : 2008-10-01

void main ()
{
    int nCases, i;
    cin >> nCases;
    for (i = 0; i < nCases; i++)
    {
        char begin[5], end[5];
        scanf("%s %s", begin, end);
        x = abs(begin[0] - end[0]);
        y = abs(begin[1] - end[1]);
        if (x == 0 && y == 0) cout << "0 0 0 0 " << endl;
        else
        {
            if (x < y) cout << y << " ";
            else cout << x << " ";;
            if (x == y || x == 0 || y == 0) cout << "1 ";
            else cout << "2 ";
            if (x == 0 || y == 0) cout << "1 ";
            else cout << "2 ";
            if (abs(x - y) % 2 != 0) cout << "Inf";
            else if(x == y) cout << "1" << endl;
            else cout << "2" << endl;
        }
    }

}