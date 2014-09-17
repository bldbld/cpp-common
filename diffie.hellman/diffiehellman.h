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
	//1，A发送AID
	int a_sendId();
	//3，A发送GY， 签名，和E(GXY,0||A||B)
	vector<string> a_sendE(vector<int> reci);
	//5，A接收b_sendE()  并验证明文1||B||A
	bool a_reciE(string reci);
	//2, B发送BID，GX, 签名
	vector<int> b_sendB(int a_id);
	//4, B发送(GXY,1||A||B)
	string b_sendE(vector<string> reci);
	//发送消息
	string send(string msg);
	//接收消息
	string recive(string reci);

	//TOOLS,RT
	string int2string (int x);
	int string2int (string x);
};

#endif /* DIFFIEHELLMAN_H_ */
