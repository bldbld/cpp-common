/*
 * main.cpp
 *
 *  Created on: 2010-4-10
 *      Author: bkin
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "schnorr.h"
#include "diffiehellman.h"
#include "md5.h"
#include "des.h"
using namespace std;

void runok(){
	int i;
	cin>>i;
}

void md5Test(){
	unsigned long src = 2313412;
	unsigned long* md5src=&src;
	CMD5 md5 = CMD5(md5src);
	string ans = md5.ToString();
	long unsigned* p = md5.m_data;
	cout<<(*p)<<endl;
	cout<<ans<<endl;
	runok();
}

void md5TestString(){
	string s = "123242";
	const char * p = s.c_str();
	CMD5 tt = CMD5(p);
	string ans = tt.ToString();
	cout<<ans<<endl;
}

void desTest (){
	CDes cdes = CDes();
	string text = "2321324213223231321415123dfadfgaer133";
	string key = "2132142455656";
	string des = cdes.Des_EncryptText(text,key);
	string src = cdes.Des_DecryptText(des,key);
	cout<<des<<endl;
	cout<<src<<endl;
	runok();
}
void schnorrTest (){
	Schnorr st = Schnorr();
	vector<double> vs = st.kg();
	unsigned long msg = 232;
	vector<int> sig = st.sig(vs[0],msg);
	Schnorr sc = Schnorr();
	if (sc.vf(vs[1],msg,sig)){
		cout<<"签名验证OK!"<<endl;
	}
}

void diffieTest (){
	Schnorr sca = Schnorr();
	Schnorr scb = Schnorr();
	vector<double> vsa = sca.kg();
	vector<double> vsb = scb.kg();

	DiffieHellman dha = DiffieHellman(1234,vsa[0],vsa[1],vsb[1]);
	DiffieHellman dhb = DiffieHellman(2345,vsb[0],vsb[1],vsa[1]);
	int aid = dha.a_sendId();
	vector<int> vi1 = dhb.b_sendB(aid);
	vector<string> vs1 = dha.a_sendE(vi1);
	string s1 = dhb.b_sendE(vs1);
	if (dha.a_reciE(s1)){
		cout<<"协议运行ok!"<<endl;
		cout<<"开始聊天;"<<endl;
		string text1,text2;
		text1 = dha.send("Hello");
		text2 = dhb.recive(text1);
		cout<<"A said(加密过):"<<text1<<endl;
		cout<<"B listen:"<<text2<<endl;
	}
}
int main (){
	//md5TestString();
	//desTest();
	//schnorrTest ();
	diffieTest ();


	runok();
	return 0;
}


