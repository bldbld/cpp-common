// POJ 1001 ��߾�����
// 
// Problem Description:
// ����ֵ�ܴ󡢾��Ⱥܸߵ������и߾��ȼ�����һ��ʮ�ֳ��������⡣
// ���磬�Թ�ծ���м�����������������⡣
// ����Ҫ�����������ǣ���һ��ʵ��R( 0.0 < R < 99.999 )��
// Ҫ��д����ȷ���� R �� n �η�(Rn)������n ���������� 0 < n <= 25�� 
//
// Input:
// T����������� R �� n�� R ��ֵռ�� 1 ���� 6 �У�n ��ֵռ�� 8 �͵� 9 �С�
//
// Output:
// ����ÿ�����룬Ҫ�����һ�У����а�����ȷ�� R �� n �η���
// �����Ҫȥ��ǰ���� 0 ��Ҫ�� 0������������������Ҫ���С���㡣
// 
// Sample Input:
// 95.123 12
// 0.4321 20
// 5.1234 15
// 6.7592  9
// 98.999 10
// 1.0100 12
// 
// Sample Output:
// 548815620517731830194541.899025343415715973535967221869852721
// .00000005148554641076956121994511276767154838481760200726351203835429763013462401
// 43992025569.928573701266488041146654993318703707511666295476720493953024
// 29448126.764121021618164430206909037173276672
// 90429072743629540498.107596019456651774561044010001
// 1.126825030131969720661201
//
// Algorithm Description:
// Big Float multiply can be exchaged to Big Integer multiply,
// then record the position of radix point for output.
//
// Submit Information:
// Memory: 264K
// Time: 16MS
//
// Author: Ballad
// Date: 2011-08-30
// Compile Env: MS VC++ 2010 / Dev-C++ 4.9

#include <iostream>
#include <string>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Global Vars.

int a [6] = {0}; // The input data for power calculate: a.
int aint = 0; // The integer value of a after move away radix point
int aLen = 6; // The length of a-array after move away radix point
int aLenArr [7] = {10,100,1000,10000,100000,1000000,10000000}; 

int b [150] = {0};
int bSt = 149; //���ڼ���ʱ��b�ǴӺ���ǰ��ֵ������bSt���ڼ�¼��ֵ����λ�� 
int c [150] = {0};
int n = -1; //����n�η� 0<=n<=25 

// Temporary Vars.
int t =0;
int tmp = 0;
int addByte = 0;  //�Ƿ��λ  
int i = 0;
int j = 0;

// Big Integer Multiply, using Int-Array
// 
// Author: Ballad 
void bigint_mult (){

	for (i=149; i>=bSt; i--){
		tmp = b[i]*aint;
		addByte= 0;
		//cout<<"DEBUG: i"<<i<<": b"<<b[i]<<endl;
		c[i] = c[i] + tmp%10;
		tmp = tmp - tmp%10;
		if (c[i] > 9){
            c[i] = c[i]%10;
            addByte = 1;
		}else {
            addByte = 0;
		}
		
		t = 0;
		for (j=1; j<=aLen; j++){
			t = tmp%aLenArr[j];
        	//cout<<"DEBUG: i"<<i<<": j"<<j<<": tmp:"<<tmp<<endl;
			tmp = tmp - t;
			c[i-j] = c[i-j] + t/aLenArr[j-1] + addByte;
			if (c[i-j] > 9){
				c[i-j] = c[i-j]%10;
				addByte = 1;
			}else {
				addByte = 0;
			}
			//cout<<"DEBUG: i"<<i<<": c"<<c[i-j]<<endl;
		}
	
	}
	for (i=bSt - aLen;i<150; i++){
		b[i] = c[i];
		c[i] = 0; 
		//cout<<"DEBUG"<<i<<":c"<<c[i]<<endl;
	}
}


////////////////////////////////////////////////////////////////////////////////
// Main Process

void process (string s){
	// �������� 
	int pointA = -1; // a��С����λ�� 
	int pointB = -1; // b��С����λ�� 
	pointA = s.find_first_of('.');
	if (pointA >= 1){
		aLen = 5;
		pointB = 150-(aLen-pointA)*n;
	}
	
	// ��ʽ�����ݣ���stringת��Ϊint�����int����
	for (int m=0,n=0; m<6; m++,n++){
		a[m] = s[m]-48;
		if (m == pointA){
              n--;
        }else {
       	      b[bSt-aLen+n+1] = a[m];
       	      // cout<<"DEBUG"<<"m"<<m<<" "<<bSt-aLen+n+1<<"ai"<<a[m]<<endl;
       	      if (n < aLen-1 ){
                    aint = aint + a[m]*aLenArr[aLen-n-2];
                    // cout<<"DEBUG: m"<<m<<" am"<<a[m]<<" alen-n-2"<<(aLen-n-2)<<" n"<<n<<endl;
              }else{
                    aint = aint + a[m]*1;
              }
        }	
	}
	
	// cout<<aint<<endl;
	
	// ���Ĵ������� 
	for (int k=1;k<n;k++){
		bSt = 149 - k*aLen;
		bigint_mult ();
	}
	
	// ��ʽ��������
	int printSt = 0;
	int printEnd = 149; 
	for (int k=0; k<150; k++){
        if (b[k] != 0){
            printSt = k;
            break;
        }
		if (k == pointB-1){
            printSt = pointB;
            break;
        }
		if (k == 149){;
			printSt = 149;
		}
    }
    if (pointB != -1){ 
        // ��������С��
        for (int k=149; k>printSt; k--){
            if (b[k] != 0){
                printEnd = k;
                break;
            }
			if (k == pointB){
				printEnd = pointB-1;
				break;
			}
        } 
	}
	
	// ������ 
	for (int k=printSt; k<=printEnd; k++){
        if (k == pointB){
            cout<<".";
        }
		cout<<b[k];
	}
	cout<<endl;
}
// �������
void clearVars (){

	aint = 0; 
	aLen = 6;

	bSt = 149; 
	n = -1;
	
	t =0;
	tmp = 0;
	addByte = 0; 
	i = 0;
	j = 0;
	
	for (int m = 0;m<6;m++){
		a[m]= 0;
	}
	
	for (int m = 0;m<150;m++){
		b[m]= 0;
		c[m]= 0;
	}
}

int main (){
	string s;
    while (cin >>s >>n){
		if (n == 0){
			cout<<"1"<<endl;
			continue;
		}
		process (s);
		clearVars();
	}

    return 0;
}
