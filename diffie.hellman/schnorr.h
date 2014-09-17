/*
 * schnorr.h
 *
 *  Created on: 2010-4-10
 *      Author: bkin
 *
 *  ����ʵ���Ѿ��趨��Ĭ�ϵ�K,G,g,q
 */

#ifndef SCHNORR_H_
#define SCHNORR_H_

#include <stdio.h>
#include <string>
#include <vector.h>
#include "md5.h"
using namespace std;
//
//////////////////////////////////////////////////////////////////////////
class Schnorr
{
private:

public:
	//���ɹ�Կ˽Կ
	vector<double> kg();
	//����ǩ��
	vector<int> sig(int sk, unsigned long msg);
	//��֤
	bool vf(double vk, unsigned long msg, vector<int> rhs);

};
#endif /* SCHNORR_H_ */
