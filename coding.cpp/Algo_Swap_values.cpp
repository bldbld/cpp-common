// ��ͨ������������ɽ���A,B��ֵ
// ��ͨ������������ɽ���A,B,C��ֵ
//
// Author: BALLAD
// Date: 2011-08-18
//
// Compile Env: Dev-C++ 4.9

#include <cstdlib>
#include <iostream>
 
using namespace std;

// ��ͨ������������ɽ���A,B��ֵ
// �����߼� b = (a + b) - b; a =  (a + b) - a
// Author: BALLAD
// Date: 2011-08-18
void exchange2IntValue (int a, int b){
     cout<<"��ͨ������������ɽ���A,B��ֵ"<<endl;
     cout<<"ITPUT : a = "<<a<<", b = "<<b<<endl;
     a = a + b;
     b = a - b;
     a = a - b;
     cout<<"OUTPUT: a = "<<a<<", b = "<<b<<endl;
}

// ��ͨ������������ɽ���A,B,C��ֵ
// ������ʽ: A = B, B = C, C = A
// Author: BALLAD
// Date: 2011-08-18
void exchange3IntValue (int a, int b, int c){
     cout<<"��ͨ������������ɽ���A,B,C��ֵ"<<b<<endl;
     cout<<"ITPUT : a = "<<a<<", b = "<<b<<", c = "<<c<<endl;  
     // �Ƚ���A,B   
     a = a + b;
     b = a - b;
     a = a - b;
     // Ȼ�󽻻�B,C 
     b = b + c;
     c = b - c;
     b = b - c;
     cout<<"OUTPUT: a = "<<a<<", b = "<<b<<", c = "<<c<<endl;
}

// ���ڲ��Լ���֤��������
int main(int argc, char *argv[])
{
    exchange2IntValue(1,2);       
    system("PAUSE");
    return EXIT_SUCCESS;
}

