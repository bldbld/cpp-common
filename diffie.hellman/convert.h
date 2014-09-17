/*
 * convert.h
 *
 *  Created on: 2010-4-10
 *      Author: bkin
 */

#ifndef CONVERT_H_
#define CONVERT_H_

#include <string>
using namespace std;

class CConvert
{
private:
public:
	//跨平台C++ Base ６４ 编码解码函数
	void _enBase64Help(unsigned char chasc[3],unsigned char chuue[4]);
	void _deBase64Help(unsigned char chuue[4],unsigned char chasc[3]);
	string enBase64 (const char* inbuf, size_t inbufLen );
	string enBase64 (const string &inbuf);
	int deBase64 (string src, char* outbuf );
	string deBase64 (string src);

};

#endif /* CONVERT_H_ */
