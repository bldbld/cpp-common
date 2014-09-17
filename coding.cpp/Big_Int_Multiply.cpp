// 1024位大数相乘
//
// Author：Ballad
//
// Date: 2009/10/16 (大三网络上机)
// Format Date: 2011/07/20
//
// Compile Env：MS VC++ 2008

#include "stdafx.h"

#include <iostream>

using namespace std;

int main ()
{

	int a[1024];
	int b[1024];
	
	for (int i=0;i<1024;i++ )
		a[i]=2;
	for (int i=0;i<1024;i++ )
		b[i]=2;

	// 这里是判断结果是2048位还是2047位，相比于后面，发现这里可能没必要了
	long  tem1=0,tem2=0;
	int t=0;
	for (int i=5;i>0;i--){
		t=1;
		for(int j =1 ;j<i;j++)
			t=t*10;
		tem1+=a[5-i]*t;
	}
	for (int i=5;i>0;i--){
		t=1;
		for(int j =1 ;j<i;j++)
			t=t*10;
		tem2+=b[5-i]*t;
	}
	int ans[2048];
	for (int i=0;i<2048;i++){
		ans[i]=0;
	}
	//cout<<tem1;
	if(tem1*tem2<10000000000){
		ans[0]=0;
	}
	
	
	int tem[1025];
	for (int i=0;i<1025;i++){
		tem[i]=0;
	}
	//int flag=0;
	//int countTem=0;//进位
	int tem3=0;
	for (int p = 1023;p>=0;p--){
		for (int i=0;i<1025;i++){
			tem[i]=0;
		}
		for(int k =1024 ;k>0;k--){
			tem3=0;
			tem3=b[p]*a[k-1];
			tem[k]+=tem3%10;
			tem[k-1]+=tem3/10;
			
		}
		for(int k=p,j=0;k<p+1024;k++,j++){
			tem3=0;
			tem3=ans[k]+tem[j];
			if (ans[k]>10){
				ans[k-1]=ans[k]/10;
				ans[k]=ans[k]%10;
			}
			ans[k]+=tem3%10;
			ans[k-1]+=tem3/10;		
		
		}
	}

	for (int i=0;i<2048;i++){
		cout<<ans[i];
		
	}
	/*
	int a[9];
	int b[9];

	for (int i=0;i<9;i++ )
	a[i]=i+1;
	for (int i=0;i<9;i++ )
	b[i]=i+1;
	for (int i=0;i<9;i++ )
	cout<<a[i];
	cout<<endl;
	*/
	return 0;

}
