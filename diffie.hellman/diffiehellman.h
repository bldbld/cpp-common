/*
 * diffiehellman.h
 *
 *  Created on: 2010-4-10
 *      Author: bkin
 */

#ifndef DIFFIEHELLMAN_H_
#define DIFFIEHELLMAN_H_
#include <stdio.h>
#include <string>
#include <vector>
#include "md5.h"
#include "des.h"
#include "schnorr.h"

class DiffieHellman{
private:
	int id;
	int id2;
	double vk;
	double sk;
	double vk2;
	int x;
	int y;
	long gxy;
public:
	DiffieHellman (int id,double sk,double vk,double vk2);
	//1��A����AID
	int a_sendId();
	//3��A����GY�� ǩ������E(GXY,0||A||B)
	vector<string> a_sendE(vector<int> reci);
	//5��A����b_sendE()  ����֤����1||B||A
	bool a_reciE(string reci);
	//2, B����BID��GX, ǩ��
	vector<int> b_sendB(int a_id);
	//4, B����(GXY,1||A||B)
	string b_sendE(vector<string> reci);
	//������Ϣ
	string send(string msg);
	//������Ϣ
	string recive(string reci);

	//TOOLS,RT
	string int2string (int x);
	int string2int (string x);
};

#endif /* DIFFIEHELLMAN_H_ */
