/*
 * diffiehellman.cpp
 *
 *  Created on: 2010-4-10
 *      Author: bkin
 */

#include "diffiehellman.h"
#include "md5.h"
#include "des.h"
#include <math.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector.h>
using namespace std;

//G为6阶群，单位元素为1 7为素数  N为7 运算：a*b mod 7 生成子为2
const static char G[10] = {1,2,3,4,5,6};
const int g = 2;

DiffieHellman::DiffieHellman(int id2,double sk2,double vk_2,double vk2_2){
	id=id2;
	sk=sk2;
	vk=vk_2;
	vk2=vk2_2;
}

string DiffieHellman::int2string (int x){
	stringstream ss;
	string re;
	ss<<x;
	re = ss.str();
	return re;
}

int DiffieHellman::string2int (string x){
	const char* s = x.c_str();
	return atoi(s);
}

int DiffieHellman::a_sendId(){
	return id;
}

vector<string> DiffieHellman::a_sendE(vector<int> reci){
	id2 = reci[0];
	int gx = reci[1];
	vector<int> rhs;
	rhs.push_back(reci[2]);
	rhs.push_back(reci[3]);
	rhs.push_back(reci[4]);
	Schnorr sc = Schnorr();
	vector<string> re;
	if (sc.vf(vk2,gx,rhs)){
		srand(time(NULL));
		int y2=rand()%3+2;
		y=y2;
		long gxy2=1;
		for (int i = 0;i<y;i++){
			gxy2=(long)gxy2*gx;
		}
		gxy = gxy2;
		long gy=1;
		for (int i = 0;i<y;i++){
			gy=(long)gy*g;
		}
		vector<int> rhs2 = sc.sig(sk,gy);
		string sgy = int2string(gy);
		string sr = int2string(rhs2[0]);
		string sh= int2string(rhs2[1]);
		string ss = int2string(rhs2[2]);
		CDes cdes = CDes();
		string des = cdes.Des_EncryptText(("0"+int2string(id)+int2string(id2)),int2string(gxy));
		re.push_back(sgy);
		re.push_back(sr);
		re.push_back(sh);
		re.push_back(ss);
		re.push_back(des);
	}
	else {

	}
	return re;
}

bool DiffieHellman::a_reciE(string reci){
	CDes cdes = CDes();
	string src = cdes.Des_DecryptText(reci,int2string(gxy));
	if (src==("1"+int2string(id2)+int2string(id))){
		return true;
	}
	else
		return false;
}

vector<int> DiffieHellman::b_sendB(int a_id){
	id2 = a_id;
	srand(time(NULL));
	int x2=rand()%3+2;
	x=x2;
	long gx=1;
	for (int i = 0;i<x;i++){
		gx=(long)gx*g;
	}
	vector<int> re;
	re.push_back(id);
	re.push_back(gx);
	Schnorr sc = Schnorr();
	unsigned long ulgx = (unsigned long) gx;
	vector<int> rhs = sc.sig(sk,ulgx);
	re.push_back(rhs[0]);
	re.push_back(rhs[1]);
	re.push_back(rhs[2]);
	return re;
}

string DiffieHellman::b_sendE(vector<string> reci){
	int gy = string2int(reci[0]);
	vector<int> rhs;
	string tt = reci[1];
	int r = string2int(tt);
	rhs.push_back(r);
	rhs.push_back( string2int(reci[2]) );
	rhs.push_back( string2int(reci[3]) );
	string des = reci[4];
	Schnorr sc4 = Schnorr();
	string re;
	if (sc4.vf(vk2,gy,rhs)){
		long gxy2=1;
		for (int i = 0;i<x;i++){
			gxy2=(long)gxy2*gy;
		}
		gxy = gxy2;
		CDes cdes = CDes();
		string src = cdes.Des_DecryptText(des,int2string(gxy));
		string thetrue = "0"+int2string(id2)+int2string(id);
		if (src==thetrue ){
			string des2 = cdes.Des_EncryptText(("1"+int2string(id)+int2string(id2)),int2string(gxy));
			re = des2;
		}
	}
	else {
	}
	return re;
}

string DiffieHellman::send(string msg){
	string s = int2string(gxy);
	const char* p = s.c_str();
	CMD5 cmd5 = CMD5(p);
	string deskey = cmd5.ToString();
	CDes cdes = CDes();
	string re = cdes.Des_EncryptText(msg,deskey);
	return re;
}

string DiffieHellman::recive(string reci){
	string s = int2string(gxy);
	const char* p = s.c_str();
	CMD5 cmd5 = CMD5(p);
	string deskey = cmd5.ToString();
	CDes cdes = CDes();
	string re = cdes.Des_DecryptText(reci,deskey);
	return re;
}


