// 不通过其它变量完成交换A,B的值
// 不通过其它变量完成交换A,B,C的值
//
// Author: BALLAD
// Date: 2011-08-18
//
// Compile Env: Dev-C++ 4.9

#include <cstdlib>
#include <iostream>
 
using namespace std;

// 不通过其它变量完成交换A,B的值
// 交换逻辑 b = (a + b) - b; a =  (a + b) - a
// Author: BALLAD
// Date: 2011-08-18
void exchange2IntValue (int a, int b){
     cout<<"不通过其它变量完成交换A,B的值"<<endl;
     cout<<"ITPUT : a = "<<a<<", b = "<<b<<endl;
     a = a + b;
     b = a - b;
     a = a - b;
     cout<<"OUTPUT: a = "<<a<<", b = "<<b<<endl;
}

// 不通过其它变量完成交换A,B,C的值
// 交换方式: A = B, B = C, C = A
// Author: BALLAD
// Date: 2011-08-18
void exchange3IntValue (int a, int b, int c){
     cout<<"不通过其它变量完成交换A,B,C的值"<<b<<endl;
     cout<<"ITPUT : a = "<<a<<", b = "<<b<<", c = "<<c<<endl;  
     // 先交换A,B   
     a = a + b;
     b = a - b;
     a = a - b;
     // 然后交换B,C 
     b = b + c;
     c = b - c;
     b = b - c;
     cout<<"OUTPUT: a = "<<a<<", b = "<<b<<", c = "<<c<<endl;
}

// 用于测试及验证的主函数
int main(int argc, char *argv[])
{
    exchange2IntValue(1,2);       
    system("PAUSE");
    return EXIT_SUCCESS;
}

