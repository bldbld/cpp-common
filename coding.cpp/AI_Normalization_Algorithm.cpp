// Artificial Intelligence - Normalization Algorithm
// 人工智能 归一算法
// Author: Ballad

#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
人工智能 归一算法
算法简述：
整个算法分为三个部分，第一个函数run,用来读取F，并存储到一个vector<string> fp中。第二个函数用来把F进行转换成ff，这是消除了fp中无用的F,P ()等符号，并进行一些统计。
第三个函数是具体执行，用pnum,xnum分表表示P的个数和参数的个数。进入循环后，分别判断：如果参数只有一个字符，那么就直接把变量替换为常量。如果有一个是一个字符参数，那么它将被替换。如果两边数目均不止一个，那么就先判断是否有相等。每次循环时都会把FF中进行相应的替换。最后把结果存入ans中。
*/

vector<string > fp;//存储输入的F
vector<string > ff;//临时用，存储整理过的F，无,,{},()...
vector<string > ans;//存储结果
int xnum;//参数的个数，确定循环次数
int pnum;//表达式的个数，为了简便,只支持2个以内 。至于多个，需要在findtd中修改size为siza[]及添加几个循环

bool run()
{
	cout<<"请输入 F中表达式(P)的数目:"<<endl;
	//cin>>pnum;
	pnum=2;
	cout<<pnum<<endl;;
	if(pnum==1){
		cout<<"匹配"<<endl;
		return true;
	}
	else if(pnum<=0){
		cout<<"错误"<<endl;
		return false;
	}
	else if(pnum>2){
		cout<<"Sorry，还不支持"<<endl;
		return false;
	}
	fp.reserve(pnum+1);
	string stem;
	cout<<"请输入表达式："<<endl;
	//cin>>stem;//we use the default F={P(a,x,f(g(y))),P(z,f(z),f(u))}
	stem="F={P(a,x,f(g(y))),P(z,f(z),f(u))}";
	cout<<stem<<endl;
	string::iterator iter,itend;
	itend=stem.end();
	char ctem;
	int count=0;
	string fptem;
	for(iter=stem.begin();iter!=itend;iter++){
		ctem=*iter;
		switch(ctem){
		case 'F':
		case '{':
		case '=':
		case 'P':
			break;
		case '}':
			fp.push_back(fptem);
			fptem.clear();
			break;
		case ',':
			fptem.push_back(ctem);
			if(count==0){
				fp.push_back(fptem);
				fptem.clear();			
			}
			break;
		case '(':
			count++;
			break;
		case ')':
			count--;
			break;
		default:
			fptem.push_back(ctem);
			break;
		}
	}
	return true;
}
void funct()
{
	string stem;
	string::iterator iter,iend;
	stem=fp[0];
	int snum=stem.length();
	int i=0,j=0,k=0;
	xnum=0;
	for (i=0;i<snum;++i){
		if(stem[i]==','){
			++xnum;
		}
	}
	stem.clear();
	ff.reserve(xnum*pnum+1);	
	for(j=0;j<pnum;++j){
			for (k=0;k<fp[j].length();++k){			
				if(fp[j][k]==','){
					ff.push_back(stem);
					stem.clear();
					continue;
				}
				stem.push_back(fp[j][k]);
			}
	}
	ff.push_back(stem);
	stem.clear();
}
void findthed()
{
	string stem;
	string::iterator iter,iend;
	string::iterator iter2;
	int i=0,j=0,k=0;
	int compare;
	int size1,size2;//evil
	for(i=0;i<xnum;++i){
		size1=ff[i].length();
		size2=ff[i+xnum].length();
		if(size1==1&&size2==1){	
			iter=ff[i].begin();
			stem.push_back(*iter);			
			if(*iter=='x'||*iter=='y'||*iter=='z'){
				iter2=ff[i+xnum].begin();
				for(k=0;k<3;k++){
					int spos=ff[k].find(*iter);
					if(spos>=0){
						ff[k].erase(spos);
						ff[k].push_back(*iter2);
					}
				}
			}
			stem.push_back('/');
			iter=ff[i+xnum].begin();
			char lltem=*iter;
			stem.push_back(*iter);
			if(*iter=='x'||*iter=='y'||*iter=='z'){
				iter2=ff[i].begin();
				for(k=0;k<3;k++){
					int spos=ff[k+xnum].find(lltem);
					if(spos>=0){			
						ff[k+xnum].erase(spos);
						ff[k+xnum].push_back(*iter2);
					}
				}
			}			
			ans.push_back(stem);
		}
		else if(size1==1&&size2!=1){
			iend=ff[i+xnum].end();
			for(iter2=ff[i+xnum].begin();iter2!=iend;iter2++){
				stem.push_back(*iter2);
			}
			stem.push_back('/');
			iend=ff[i].end();
			for(iter2=ff[i].begin();iter2!=iend;iter2++){
				stem.push_back(*iter2);
			}
			ans.push_back(stem);			
			iter=ff[i].begin();
			iend=ff[i+xnum].end();
			ff[i].erase(0);
			for(iter2=ff[i+xnum].begin();iter2!=iend;iter2++){
				ff[i].push_back(*iter2);
			}
		}
		else if(size1!=1&&size2==1){
			iend=ff[i].end();
			iter=ff[i+xnum].begin();
			ff[i+xnum].erase(0);
			for(iter2=ff[i].begin();iter2!=iend;iter2++){
				ff[i+xnum].push_back(*iter2);
			}
			for(iter2=ff[i+xnum].begin();iter2!=iend;iter2++){
				stem.push_back(*iter2);
			}
			stem.push_back('/');
			iend=ff[i].end();
			for(iter2=ff[i].begin();iter2!=iend;iter2++){
				stem.push_back(*iter2);
			}
			ans.push_back(stem);
			
		}
		else{		
			iter=ff[i].begin();
			iter2=ff[i+xnum].begin();
			while (*iter==*iter2){
					iter++;
					iter2++;
			}
			iend=ff[i].end();
			for(;iter!=iend;iter++){
				stem.push_back(*iter);
			}
			stem.push_back('/');
			iend=ff[i+xnum].end();
			for(;iter2!=iend;iter2++){
				stem.push_back(*iter2);
			}
			ans.push_back(stem);		
		}
		ans.push_back(",");
		stem.clear();
	}
	vector<string>::iterator ifp;
	vector<string>::iterator ifend=ans.end();
	cout<<"最一般合一结果为:"<<endl;
	for (ifp=ans.begin();ifp!=ifend;++ifp){
		cout<<*ifp;
	}
	cout<<endl;
}
int main ()
{
	bool runbool;
	runbool=run();
	if(runbool){
		funct();
		findthed();
	}
	return 0;
}