// Author : ballad
// Date : 2008-10-01

void main ()
{
    int chs = 0, ras = 0;
    int a = 1;
    while (a != 0)
    {
        cin >> a;
        if (a % 2 == 1)
            cout << "0 0" << endl;
        else
        {
            if (a % 4 == 0)
                cout << (a / 4) << " " << (a / 2) << endl;
            else
                cout << (a / 4) + (a % 4) / 2 << " " << (a / 2) << endl;
        }
    }
}