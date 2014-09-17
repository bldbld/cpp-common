// NFA to DFA
//
// Author: Ballad
// Date: 2009-4-10
// Compile Env: MS VC++ 2005/2008
//
// Requier the nfatodfa_file.txt

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int flag[10][3];//chenk whether the nfa is a 'O'
vector<string> a;//store NFA's link
vector<set<int> > E;// shote the¦Å-closure
set<set<int> > T2;//store the DFA
vector<string > anss;//the result

string tems;
set<int> sstem;
int countset=0;
string sd;
string ansKey="ABCD";

void getNfa(){  
	//cin by console
	// we regard it as status:10 and move:3 a b e
	a.reserve(20);
	string s;
	int count=0;
	for(int i=0;i<10;i++)
		for(int j=0;j<3;j++){
			cin>>s;
			flag[i][j]=10;
			if(s[0]!='O'){
				flag[i][j]=count;
				count++;
				a.push_back(s);
			}
		}
}

void getNfaF(){  //cin by 1.txt
	a.reserve(20);
	string s;
	int count=0;
	ifstream infile;
	infile.open("nfatodfa_file.txt");
	for(int i=0;i<10;i++){
		for(int j=0;j<3;j++){
			infile>>s;
			flag[i][j]=10;
			if(s[0]!='O'){
				flag[i][j]=count;
				count++;
				a.push_back(s);
			}
		}
	}
}

set<int> find_e(int i){
	if(flag[i][2]!=10){
		set<int> s,sr,s2;
		set<int>::iterator iter;
		string st;
		int j;
		st=a[flag[i][2]];
		int len=st.length();
		s.insert(i);
		for (j=0;j<len;j++){
			s.insert(st[j]-48);
			s2=find_e(st[j]-48);
			sr=s2;
			int m,k,l;
			iter=sr.begin();
			for(m=0;m<sr.size();m++){                      
				s.insert(*iter);
				iter++;
			}
		}
		return s;
	}
	if(flag[i][2]==10){
		set<int> s1;
		s1.insert(i);
		return s1;
	}		
}

void NfaToE(){
	E.reserve(20);
	vector<string>::iterator iter;
	iter=a.begin();
	int i,j,k;
	set<int> s;
	for(i=0;i<10;i++){
		s=find_e(i);
		E.push_back(s);
	}
}

void find_d(int i,int j){
	if(flag[i][j]!=10){
		string s=a[flag[i][j]];
		char c=s[0];
		int m=c-48;
		sstem.insert(m);
		set<int> s2=E[m];
		set<int>::iterator iter=s2.begin();
		for(int k=0;k<s2.size();k++){
			sstem.insert(*iter);
			iter++;
		}
	}
}

void find_dfa(set<int> s,int j){
	set<int>::iterator iter;
	iter=s.begin();
	int i;
	sstem.clear();
	for(i=0;i<s.size();i++){		
		int f=*iter;
		iter++;
		find_d(f,j);
	}
	set<set<int> >::iterator iter2;
	iter2=T2.find(sstem);
	if(iter2==T2.end()){  //NEW
		string stem;
		stem.push_back(ansKey[countset]);
		stem.push_back(j+48);
		T2.insert(sstem);
		int lastchar=T2.size()-1;
		stem.push_back(ansKey[lastchar]);
		anss.push_back(stem);
	}
	else{
		iter2=T2.begin();
		i=0;
		for(i=0;i<4;i++){
			if(*iter2==sstem)
				break;
			iter2++;
		}
		string stem;
		stem.push_back(ansKey[countset]);
		stem.push_back(j+48);
		stem.push_back(ansKey[i]);
		anss.push_back(stem);
	}
}

void eToDfa(){
	anss.reserve(16);
	T2.insert(E[0]);//it is the A
	int k=0;//T
	int cur=0;
	int many;
	set<set<int> >::iterator iter=T2.begin();
	for(int i=0;i<4;i++){    //do the evil
		find_dfa(*iter,0);
		find_dfa(*iter,1);
		iter++;
		countset++;
	}
}

void print(){
	set<set<int> >::iterator iter=T2.begin();
	set<int>::iterator iter2;
	for(int i=0;i<4;i++){
		iter2=(*iter).begin();
		for(;iter2!=(*iter).end();iter2++){
			cout<<*iter2;
		}
		iter++;
		cout<<endl;
	}
	cout<<"- a b "<<endl;
	for(int i=0;i<4;i++){
		cout<<ansKey[i];
		cout<<" ";
		for(int j=0;j<2;j++){		
			cout<<anss[i*2+j][2];
			cout<<" ";		
		}
		cout<<endl;
	}
}

int main (){
	getNfaF();
	NfaToE();
	eToDfa();
	print();
	return 0;
}