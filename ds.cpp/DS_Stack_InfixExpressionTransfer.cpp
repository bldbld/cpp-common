// 中缀表达式转后缀表达式
// ballad 2009 ?
class Toto
{
private:
    Stack <char> OPTD;//操作数
    Stack <char> OPTR;//操作符
    Stack <char> ANS;//结果
public:
    Toto()
    {
        Stack <char> OPTD;//操作数
        Stack <char> OPTR;//操作符
        Stack <char> ANS;//结果
    }
    ~Toto()
    {}
    void Convert();

    int icp(char c);
    int isp(char c);

};

void Toto::Convert()
{
    int len = 8;
    char s[8];
    int i;
    //	for(i=0;i<len-1;i++){
    //		cin>>s[i];
    //}
    cin >> s[0];
    cin >> s[1];
    cin >> s[2];
    cin >> s[3];
    cin >> s[4];
    cin >> s[5];
    cin >> s[6];
    char c;
    char num1, num2;

    OPTD.push(s[0]);
    OPTR.push('#');
    for(i = 1; i < len - 1; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
            OPTD.push(s[i]);
        else
        {
            if(isp(s[i]) > icp(OPTR.gettop()))
                OPTR.push(s[i]);
            if(isp(s[i]) < icp(OPTR.gettop()))
            {
                c = OPTR.pop();
                i++;
                num1 = s[i];
                num2 = OPTD.pop();

                ANS.push(num2);
                ANS.push(num1);
                ANS.push(c);
            }
            if(isp(s[i]) == icp(OPTR.gettop()))
            {
                c = OPTR.pop();
                ANS.push(c);
            }
        }
    }
    for(i = 0; i < len - 1; i++)
    {
        cout << ANS.pop();
    }
}

int Toto::icp(char c)
{
    int x = 0;
    switch(c)
    {
    case'#':
        x = 0;
        break;
    case'(':
        x = 7;
        break;
    case'^':
        x = 1;
        break;
    case'*':
    case'/':
    case'%':
        x = 5;
        break;
    case'+':
    case'-':
        x = 3;
        break;
    case' )':
        x = 8;
        break;
    }
    return x;
}
int Toto::isp(char c)
{
    int x = 0;
    switch(c)
    {
    case'#':
        x = 0;
        break;
    case'(':
        x = 8;
        break;
    case'^':
        x = 6;
        break;
    case'*':
    case'/':
    case'%':
        x = 4;
        break;
    case'+':
    case'-':
        x = 2;
        break;
    case' )':
        x = 1;
        break;
    }
    return x;
}

int main ()
{
    Toto T1;
    T1.Convert();
    return 0;
}