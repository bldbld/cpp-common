// 模拟内存的首次分区算法
// 
// Author: Ballad
// Date: 2009/06/05 
// Format Date: 2011/07/20
// 
// Compile Env：MS VC++ 2008

#include <iostream>
#include <string>

using namespace std;

class Ram
{
private:
	string men;
	int length;
	int nowlen;
public:
	Ram(int size=4096){
		length=size;
		nowlen=0;
		for (int i=0;i<size;i++){
			men.push_back('A');
		}
	}
	void read(int i){
		cout<<men[i]<<endl;
	}
	void getLength(){
		cout<<men.length();
	}
	void newspace (int n, int size){
		men[n]=nowlen+48;
		nowlen++;
		for (int i=n+1;i<n+size-1;i++){
			men[i]='B';
		}
		men[n+size-1]='C';
	}
	void findnew (int size) {
		int i=0;
		string tem;
		for (i=0;i<size;i++){
			tem.push_back('A');
		}
		int pos=men.find_first_of(tem);
		if(pos>=0)
			newspace(pos,size);
		else
			cout<<"error";
	}
	void make(int size){
		findnew (size);
	}
	void free(int n){
		int i;
		int pos=men.find_first_of(n+48);
		men[pos]='A';
		for (i=pos+1;men[i]=='B';i++){
			men[i]='A';
		}
		men[i]='A';//make C to A
	}
};


int main ()
{
	Ram r1;
	r1.make(5);
	r1.make(5);
	r1.make(5);
	r1.free(1);
	r1.make(3);
	r1.read(7);
	return 0;
}