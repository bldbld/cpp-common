/*
 * schnorr.cpp
 *
 *  Created on: 2010-4-10
 *      Author: bkin
 */
#include "schnorr.h"
#include "md5.h"
#include <math.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector.h>
using namespace std;
//G为6阶群，单位元素为1 7为素数  N为7 运算：a*b mod 7 生成子为2
const static char G[10] = {1,2,3,4,5,6};
const int g = 2;

//q设为7
vector<double> Schnorr::kg(){
	srand(time(NULL));
	int x=rand()%7+1;
	int y=1;
	for (int i=0 ;i<x;i++){
		y=y*g;
	}
	double yd =(double)1.0/y;
	vector<double> re;
	re.push_back((double)x);//sk
	re.push_back((double)yd);//vk
	return re;
}

vector<int> Schnorr::sig(int sk, unsigned long msg){
	srand(time(NULL));
	int k=rand()%7+1;
	int r=1;
	for (int i=0 ;i<k;i++){
		r=r*g;
	}
	unsigned long src = msg+r;
	unsigned long* md5src=&src;
	CMD5 md5 = CMD5(md5src);
	string h = md5.ToString();
	h = h.substr(0,3);
	const char* hc = h.c_str();
	int hi = atoi(hc)%5;
	int s=(k+sk*hi)%7;
	vector<int> re;
	re.push_back(r);
	re.push_back(hi);
	re.push_back(s);
	return re;
}

bool Schnorr::vf(double vk, unsigned long msg,vector<int> rhs){
	bool re = false;
	int r = rhs[0];
	int hi = rhs[1];
	int s = rhs[2];
	long gs=1;
	for (int i = 0 ;i<s;i++){
		gs=gs*(long)g;
	}
	double yh=1.0;
	for (int i=0 ;i<hi;i++){
		yh=yh*(double)vk;
	}
	unsigned long src = msg+r;
	unsigned long* md5src=&src;
	CMD5 md5 = CMD5(md5src);
	string h = md5.ToString();
	h = h.substr(0,3);
	const char* hc = h.c_str();
	int hi2 = atoi(hc)%5;
	if((hi==hi2)&& ((double)r-(double)(gs*yh))<(double)0.00001){
		re = true;
	}
	return re;
}
