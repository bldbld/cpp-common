// Artificial Intelligence - Normalization Algorithm
// �˹����� ��һ�㷨
// Author: Ballad

#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
�˹����� ��һ�㷨
�㷨������
�����㷨��Ϊ�������֣���һ������run,������ȡF�����洢��һ��vector<string> fp�С��ڶ�������������F����ת����ff������������fp�����õ�F,P ()�ȷ��ţ�������һЩͳ�ơ�
�����������Ǿ���ִ�У���pnum,xnum�ֱ��ʾP�ĸ����Ͳ����ĸ���������ѭ���󣬷ֱ��жϣ��������ֻ��һ���ַ�����ô��ֱ�Ӱѱ����滻Ϊ�����������һ����һ���ַ���������ô�������滻�����������Ŀ����ֹһ������ô�����ж��Ƿ�����ȡ�ÿ��ѭ��ʱ�����FF�н�����Ӧ���滻�����ѽ������ans�С�
*/

vector<string > fp;//�洢�����F
vector<string > ff;//��ʱ�ã��洢�������F����,,{},()...
vector<string > ans;//�洢���
int xnum;//�����ĸ�����ȷ��ѭ������
int pnum;//���ʽ�ĸ�����Ϊ�˼��,ֻ֧��2������ �����ڶ������Ҫ��findtd���޸�sizeΪsiza[]����Ӽ���ѭ��

bool run()
{
	cout<<"������ F�б��ʽ(P)����Ŀ:"<<endl;
	//cin>>pnum;
	pnum=2;
	cout<<pnum<<endl;;
	if(pnum==1){
		cout<<"ƥ��"<<endl;
		return true;
	}
	else if(pnum<=0){
		cout<<"����"<<endl;
		return false;
	}
	else if(pnum>2){
		cout<<"Sorry������֧��"<<endl;
		return false;
	}
	fp.reserve(pnum+1);
	string stem;
	cout<<"��������ʽ��"<<endl;
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
	cout<<"��һ���һ���Ϊ:"<<endl;
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