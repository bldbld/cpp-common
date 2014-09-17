// Open file test
// 打开问价测试
// ballad 2009 ?
int main ()
{
    ifstream infile;
    ofstream outfile;
    outfile.open("text.txt");
    char c[10];
    int i = 0;
    cin.getline(c, 10);
    while (i < 10)
    {
        outfile.put(c[i]);
        i++;
    }
    outfile.close();
    infile.open("text.txt");
    outfile.open("t1.txt");
    char ch;
    i = 0;
    while (i < 10)
    {
        infile.get(ch);
        outfile.put(ch);
        i++;
    }
    outfile.close();
    infile.close();
    return 0;
}