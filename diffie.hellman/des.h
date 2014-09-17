/*
 * des.h
 *
 *  Created on: 2010-4-10
 *      Author: bkin
 */


#ifndef _DES_H_
#define _DES_H_

#include <string>
#include "md5.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
class CDes
{
protected:
 bool SubKey[16][48];
 void F_func(bool In[32], const bool Ki[48]);// f ����
 void S_func(bool Out[32], bool In[48]);// S �д���
 void Transform(bool *Out, bool *In, const char *Table, int len);// �任
 void Xor(bool *InA, const bool *InB, int len);// ���
 void RotateL(bool *In, int len, int loop);// ѭ������
 void ByteToBit(bool *Out, const char *In, int bits);// �ֽ���ת����λ��
 void BitToByte(char *Out, const bool *In, int bits);// λ��ת�����ֽ���
public:
 //�����ı�,����base64���ܽ��
 string Des_EncryptText(string text,string key);
 //�����ı�����base64���ܳ�ԭʼ�ַ���
 string Des_DecryptText(string text,string key);

 // ��/���� һ�������ڴ�飬Ҫ��len����8����
 void Des_Full(unsigned char* pdata,size_t len, bool bENCRYPT);
 // ��/���� һ��8�ֽڿ�
 void Des_Block(char* Out, char* In, bool bENCRYPT);
 // ������Կ
 void Des_SetKey(const char Key[8]);
 void Des_SetKey(const string &Key);
 //��ǰʹ�õ�key,��������56bit����
 char FullKey[8];
};
//////////////////////////////////////////////////////////////////////////
#endif
