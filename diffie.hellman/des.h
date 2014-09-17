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
 void F_func(bool In[32], const bool Ki[48]);// f 函数
 void S_func(bool Out[32], bool In[48]);// S 盒代替
 void Transform(bool *Out, bool *In, const char *Table, int len);// 变换
 void Xor(bool *InA, const bool *InB, int len);// 异或
 void RotateL(bool *In, int len, int loop);// 循环左移
 void ByteToBit(bool *Out, const char *In, int bits);// 字节组转换成位组
 void BitToByte(char *Out, const bool *In, int bits);// 位组转换成字节组
public:
 //加密文本,产生base64加密结果
 string Des_EncryptText(string text,string key);
 //解密文本，由base64解密成原始字符串
 string Des_DecryptText(string text,string key);

 // 加/解密 一个连续内存块，要求len必须8倍数
 void Des_Full(unsigned char* pdata,size_t len, bool bENCRYPT);
 // 加/解密 一个8字节块
 void Des_Block(char* Out, char* In, bool bENCRYPT);
 // 设置密钥
 void Des_SetKey(const char Key[8]);
 void Des_SetKey(const string &Key);
 //当前使用的key,即常见的56bit密码
 char FullKey[8];
};
//////////////////////////////////////////////////////////////////////////
#endif
