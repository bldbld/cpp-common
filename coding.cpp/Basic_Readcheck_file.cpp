// Read from file and check the characters
// 读取文件，并且检查字符
// 
// Author: Ballad
//
// Compile Evn: MS VC++ 2008
//				Dev-C++ 4.9

#include<iostream>
#include<string>
#include<set>
#include<fstream>

using namespace std;

int main ()
{
	int count_all=0;
	int count_diff=0;
	int flag=0,docflag=0;
	set<string> s1;
	string s;
	string::iterator i;
	char c;
	ifstream infile;
	infile.open("1.txt");
	while(infile){
		infile>>s;

		if(*(s.begin())=='/'){
			i=s.begin();
			i++;
			if((*i)=='/'){
				i++;
				flag=1;
			}
			if((*i=='*')){
				while((*i)!='*'){
					i++;
				}
				flag=1;
			}
		}
		if(flag==0){
			i=s.begin();
			i++;
			if(*i)
			{
				while(i!=s.end())
				{
					if( ((*i)>=65&&(*i)<=90) || ((*i)>=97&&(*i)<=122) || ((*i)>=48&&(*i)<=57) )
					{

					}
					else
					{
						docflag=1;
						count_all++;
					}
					i++;

				}
			if(docflag==1)
				count_all--;
				docflag=0;
			}
			count_all++;
			s1.insert(s);
		}
		else
			flag=0;
	}
	count_diff=s1.size();
	cout<<--count_all<<endl;
	cout<<--count_diff;
	return 0;
}