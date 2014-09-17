// 2011, LOST BALLAD C++ Source File
//
// POJ 1009 Edge Detection
//
// Time Limit: 1000MS		
// Memory Limit: 10000K
// 
// Description
// IONU Satellite Imaging, Inc. records and stores very large images using run 
// length encoding. You are to write a program that reads a compressed image, 
// finds the edges in the image, as described below, and outputs another 
// compressed image of the detected edges.
// A simple edge detection algorithm sets an output pixel's value to be the 
// maximum absolute value of the differences between it and all its surrounding 
// pixels in the input image. Consider the input image below:
// // IMG FILE 1009 //
// The upper left pixel in the output image is the maximum of the values 
// |15-15|,|15-100|, and |15-100|, which is 85. The pixel in the 4th row, 
// 2nd column is computed as the maximum of |175-100|, |175-100|, |175-100|, 
// |175-175|, |175-25|, |175-175|,|175-175|, and |175-25|, which is 150.
// Images contain 2 to 1,000,000,000 (10^9) pixels. All images are encoded 
// using run length encoding (RLE). This is a sequence of pairs, containing 
// pixel value (0-255) and run length (1-10^9). Input images have at most 1,000 
// of these pairs. Successive pairs have different pixel values. All lines in 
// an image contain the same number of pixels.
// 
// Input
// Input consists of information for one or more images. Each image starts 
// with the width, in pixels, of each image line. This is followed by the RLE 
// pairs, one pair per line. A line with 0 0 indicates the end of the data 
// for that image. An image width of 0 indicates there are no more images to 
// process. The first image in the example input encodes the 5x7 input image 
// above.
// 
// Output
// Output is a series of edge-detected images, in the same format as the 
// input images, except that there may be more than 1,000 RLE pairs.
// 
// Sample Input
// 7
// 15 4
// 100 15
// 25 2
// 175 2
// 25 5
// 175 2
// 25 5
// 0 0
// 10
// 35 500000000
// 200 500000000
// 0 0
// 3
// 255 1
// 10 1
// 255 2
// 10 1
// 255 2
// 10 1
// 255 1
// 0 0
// 0
// 
// Sample Output
// 7
// 85 5
// 0 2
// 85 5
// 75 10
// 150 2
// 75 3
// 0 2
// 150 2
// 0 4
// 0 0
// 10
// 0 499999990
// 165 20
// 0 499999990
// 0 0
// 3
// 245 9
// 0 0
// 0
// 
// Hint
// A brute force solution that attempts to compute an output value for every 
// individual pixel will likely fail due to space or time constraints. 
//
// Algorithm Description:
// ���ڵ����Ŀ�ǳ���������Ϊ10^9�������޷���ȫ������б�����
// ͨ������������ʱ����һЩ��Ҫ�ĵ�������Ϣ��¼������Ȼ��ֻ����Щ����д���
// ÿһ��RLE����󣬶���¼��һ���㣬����ΪӰ��㣬
// (Ӱ���ȡ��һ��RLE�ĵ�һ����)
// ͨ�������ó���
//  1.��Ӱ����Ӱ����Χ8���㼰�Լ��ļ�������
//  2.��Ӱ����Ӱ����һ�е�һ����ļ�������
// ��2����ԭ���ǣ�������һ�е�һ������˵��
// �����һ����Ӱ��㣬�����ļ��������п��ܲ�ͬ��ǰһ����ļ�������
// ���������ʾ��
// 15  15  15  15  15  100 100
// 100 100 100 100 100 100 100
// ( �������������������Ƿ����ֻ���ڵ�һ�к͵ڶ��У�������ȷ���������� ��������������)
// ������ĵ�ļ���������ͬ�����Ͻǵĵ�ļ�������
// ������Щ�ᱻӰ��ĵ㣬���ǵļ������п��ܲ�ͬ��ǰ��ĵ㣬
// ������ЩҪ����Щ�����¼��㣬���������಻��Ӱ��ĵ㣬�����ֱ��ȡ��ǰ���Ľ����
// ���ǣ�����ĸ��ӶȽ�������RLE������(������1000)�������ǿ��ܴﵽ10^9�����������
//
// Author: Ballad
// Date: 2011-09-08
// Compile Env: Dev-C++ 4.9

#include <iostream>
#include <vector>
#include <map>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// ȫ�ֱ���
int width; // ͼ������Ŀ��
int total; // ͼ�����������

// ������������ 
int rlePairValue[1000];
int rlePairNum[1000];

// ��Ӱ��ĵ�����
map<int, int> infectPoint;

////////////////////////////////////////////////////////////////////////////////
// getValue: ȡ��ĳһ��������ֵ
// ������ɲο���(i,j)��ƫ��ֵindexȷ��
// countΪrlePairNum�����rlePairValue�������Ч����

int getValue (int i,int j,int index,int count){
	int ipos = width * i + j + index; // ��ǰ�������ȫ������������λ��
	
	// cout<<"DEBUG:  GETVALUE"  <<"i"<<i<<"j"<<j<<" index"<<index<<endl;
	
	// ����߽��ж�
	if ( ipos<0 || ipos >= total ){
		return -1;
	}
	if ( j== 0 && (index == ((-1-width)) || index == -1 || index == (width-1)) ){
		return -1;
	}
	if ( j== width-1 && (index == (1-width) || index == 1 || index == (width+1)) ){
		return -1;
	}
	
	// ͨ���ۼ�rlePairNum���飬ȷ����ǰ�����ipos����RLE Pair��λ�ã�ȡ�ø�������ֵ��
	int cnt = 0;
	for (int i=0;i<count;i++){
		cnt+=rlePairNum[i];
		if (ipos<cnt){
		
			//  cout<<"DEBUG:  GETVALUE"  <<"i"<<i<<"j"<<j<<": "<<rlePairValue[i]<<endl;
			
			return rlePairValue[i];
		}
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////////////
// getMaxValue: ȡ��ĳһ�����������Χ8�������Ĳ�ľ���ֵ����ֵ
// ������ɲο���(i,j)ȷ��

int getMaxValue (int i,int j,int count){
	int tmpValue[8] = {-1};
	
	int thisvalue =  getValue(i,j,0,count);
	
	// ȡ�ú���Χ8�������Ĳ�ľ���ֵ
	tmpValue[0] = abs( thisvalue - getValue(i,j,1,count));
	tmpValue[1] = abs( thisvalue - getValue(i,j,-1,count));
	tmpValue[2] = abs( thisvalue - getValue(i,j,(-1-width),count));
	tmpValue[3] = abs( thisvalue - getValue(i,j,(0-width),count));
	tmpValue[4] = abs( thisvalue - getValue(i,j,(1-width),count));
	tmpValue[5] = abs( thisvalue - getValue(i,j,(width-1),count));
	tmpValue[6] = abs( thisvalue - getValue(i,j,width,count));
	tmpValue[7] = abs( thisvalue - getValue(i,j,(width+1),count));
	
	int maxvalue = -1;
	// ѡȡ���ľ���ֵ
	for (int  k = 0;k<8;k++){
		// �����ĳһ���ֵ���ڵ�ǰ�����ֵ+1,���õ��ֵ����Ϊ��-1��
		// �����Ǹõ㣬��Ϊ��������Ѿ�����������߽硣
        if ( tmpValue[k] == thisvalue+1){
			continue;
        }
		if (tmpValue[k] > maxvalue){
			maxvalue = tmpValue[k];
		}
	}
	// cout<<"DEBUG:  MAXVALLUE"  <<"i"<<i<<"j"<<j<<": "<<maxvalue<<endl;
	return maxvalue;
}

////////////////////////////////////////////////////////////////////////////////
// Main Function ������

int main ()
{
	int diffPairPoint; // ��¼Ӱ����λ�ã���ÿ��RLE Pair��ʼ�ĵ�һ�����λ��
    int count; // RLE Pair������,��rlePairNum�����rlePairValue�������Ч����
	
	// ��������ı���
    int pixelValue;
    int pixelNum;
	
	// ��������ı���
    int outValue;
    int outNum;
	
	// ��ʱ����
	int tmpValue;
	int lastPos;
	int i;
	int j;
	
	while (1){
		cin>>width;
		// 0��ʾ���� 
		if (width == 0){
			cout<<width<<endl;
			break;
		}
		// ��ʼ��
		count = 0;
		total = 0;
		diffPairPoint = 0;
		
		lastPos = 0;
		i =0;
		j = 0;
		
		while (1){
			cin>>pixelValue>>pixelNum;
			// 0 0��ʾ������������ 
			if (pixelValue==0 && pixelNum==0){
				break;
			}
			
			rlePairValue[count] = pixelValue;
			rlePairNum[count] = pixelNum;
			diffPairPoint +=  pixelNum;
			
			// ȷ����Ӱ��ĵ�����
			// ��ǰ��ǰ��������
			infectPoint[diffPairPoint + 1]=1;
			infectPoint[diffPairPoint]    =1;
			infectPoint[diffPairPoint - 1]=1;
			// ��һ�ж�Ӧ������
			infectPoint[diffPairPoint - width - 1]=1;
			infectPoint[diffPairPoint - width]=1;
			infectPoint[diffPairPoint - width + 1]=1;
			// ��һ�ж�Ӧ������
			infectPoint[diffPairPoint + width - 1]=1;
			infectPoint[diffPairPoint + width]=1;
			infectPoint[diffPairPoint + width + 1]=1;
			// ��һ����ʼ��
			infectPoint[ (diffPairPoint/width)*width + width]=1;
			
			total = total + pixelNum;
			count++;
		}
		
		// ������
		cout<<width<<endl;
		
		// �����һ����
		outValue = getMaxValue (0,0,count);
		outNum =1;
		
		map<int, int> ::iterator iter = infectPoint.begin();
		
		while( iter != infectPoint.end() ) {
			// ��֤Ҫ���������겻�����߽��Ҳ��ǵ�һ����
			if (iter->first > 0 && iter->first < total){
				// �������ϵ���һ�μ���ĵ㵽����������ĵ������������������ǰ�㡣
				// ��ǰ�㽫�ڼ������
				outNum += (iter->first - lastPos - 1) ;
				
				// cout<<"DEBUG "<<(iter->first)<<" "<<(iter->second)<<endl;
				
				// ���㵱ǰ��ĺ�������
				i = iter->first/width;
				j = iter->first%width;
				
				// tmpValueΪ�Ե�ǰ��ļ�����
				tmpValue = getMaxValue (i,j,count);
				if (tmpValue == outValue){
					// �������һ����ļ�������ͬ���������1��
					outNum++;
				}else {
					// �������һ����ļ�������ͬ��
					// �������һ��㣬����ʼ����һ��㡣
					cout<<outValue<<" "<<outNum<<endl;
					outNum = 1;
					outValue = tmpValue;
				}
				lastPos = iter->first;
            }
			iter++;
		}
		
		cout<<outValue<<" "<<outNum<<endl;
		cout<<"0 0"<<endl;
	}
	
	return 0;
}
