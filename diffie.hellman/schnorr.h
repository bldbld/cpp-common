/*
 * schnorr.h
 *
 *  Created on: 2010-4-10
 *      Author: bkin
 *
 *  本次实现已经设定了默认的K,G,g,q
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
	//生成公钥私钥
	vector<double> kg();
	//生成签名
	vector<int> sig(int sk, unsigned long msg);
	//验证
	bool vf(double vk, unsigned long msg, vector<int> rhs);

};
#endif /* SCHNORR_H_ */
