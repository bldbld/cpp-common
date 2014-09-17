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
// 由于点的数目非常大，最大可能为10^9，所以无法对全部点进行遍历。
// 通过在输入数据时，把一些重要的点的相关信息记录起来，然后只对这些点进行处理。
// 每一组RLE输入后，都记录下一个点，定义为影响点，
// (影响点取下一组RLE的第一个点)
// 通过分析得出：
//  1.该影响点会影响周围8个点及自己的计算结果；
//  2.该影响点会影响下一行第一个点的计算结果。
// 第2条的原因是，对于下一行第一个点来说，
// 如果上一行有影响点，则它的计算结果很有可能不同于前一个点的计算结果，
// 情况如下所示：
// 15  15  15  15  15  100 100
// 100 100 100 100 100 100 100
// ( ！！！！！！！对于是否局限只存在第一行和第二行，还不能确定，估计是 ！！！！！！！)
// 左下面的点的计算结果将不同于右上角的点的计算结果。
// 对于这些会被影响的点，它们的计算结果有可能不同于前面的点，
// 所以这些要对这些点重新计算，而对于其余不受影响的点，则可以直接取它前面点的结果。
// 于是，计算的复杂度将依赖于RLE的组数(不超过1000)，而不是可能达到10^9的坐标点数。
//
// Author: Ballad
// Date: 2011-09-08
// Compile Env: Dev-C++ 4.9

#include <iostream>
#include <vector>
#include <map>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// 全局变量
int width; // 图像坐标的宽度
int total; // 图像坐标点总数

// 存放输入的数据 
int rlePairValue[1000];
int rlePairNum[1000];

// 受影响的点数组
map<int, int> infectPoint;

////////////////////////////////////////////////////////////////////////////////
// getValue: 取得某一个坐标点的值
// 坐标点由参考点(i,j)和偏移值index确定
// count为rlePairNum数组和rlePairValue数组的有效长度

int getValue (int i,int j,int index,int count){
	int ipos = width * i + j + index; // 当前坐标点在全部坐标点数组的位置
	
	// cout<<"DEBUG:  GETVALUE"  <<"i"<<i<<"j"<<j<<" index"<<index<<endl;
	
	// 坐标边界判断
	if ( ipos<0 || ipos >= total ){
		return -1;
	}
	if ( j== 0 && (index == ((-1-width)) || index == -1 || index == (width-1)) ){
		return -1;
	}
	if ( j== width-1 && (index == (1-width) || index == 1 || index == (width+1)) ){
		return -1;
	}
	
	// 通过累加rlePairNum数组，确定当前坐标点ipos所在RLE Pair的位置，取得该坐标点的值。
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
// getMaxValue: 取得某一个坐标点与周围8个坐标点的差的绝对值最大的值
// 坐标点由参考点(i,j)确定

int getMaxValue (int i,int j,int count){
	int tmpValue[8] = {-1};
	
	int thisvalue =  getValue(i,j,0,count);
	
	// 取得和周围8个坐标点的差的绝对值
	tmpValue[0] = abs( thisvalue - getValue(i,j,1,count));
	tmpValue[1] = abs( thisvalue - getValue(i,j,-1,count));
	tmpValue[2] = abs( thisvalue - getValue(i,j,(-1-width),count));
	tmpValue[3] = abs( thisvalue - getValue(i,j,(0-width),count));
	tmpValue[4] = abs( thisvalue - getValue(i,j,(1-width),count));
	tmpValue[5] = abs( thisvalue - getValue(i,j,(width-1),count));
	tmpValue[6] = abs( thisvalue - getValue(i,j,width,count));
	tmpValue[7] = abs( thisvalue - getValue(i,j,(width+1),count));
	
	int maxvalue = -1;
	// 选取最大的绝对值
	for (int  k = 0;k<8;k++){
		// 如果与某一点差值等于当前坐标点值+1,即该点的值被设为了-1。
		// 不考虑该点，因为这点坐标已经超出了坐标边界。
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
// Main Function 主方法

int main ()
{
	int diffPairPoint; // 记录影响点的位置，即每个RLE Pair起始的第一个点的位置
    int count; // RLE Pair的总数,即rlePairNum数组和rlePairValue数组的有效长度
	
	// 用于输入的变量
    int pixelValue;
    int pixelNum;
	
	// 用于输出的变量
    int outValue;
    int outNum;
	
	// 临时变量
	int tmpValue;
	int lastPos;
	int i;
	int j;
	
	while (1){
		cin>>width;
		// 0表示结束 
		if (width == 0){
			cout<<width<<endl;
			break;
		}
		// 初始化
		count = 0;
		total = 0;
		diffPairPoint = 0;
		
		lastPos = 0;
		i =0;
		j = 0;
		
		while (1){
			cin>>pixelValue>>pixelNum;
			// 0 0表示结束本次输入 
			if (pixelValue==0 && pixelNum==0){
				break;
			}
			
			rlePairValue[count] = pixelValue;
			rlePairNum[count] = pixelNum;
			diffPairPoint +=  pixelNum;
			
			// 确定受影响的点数组
			// 当前行前后三个点
			infectPoint[diffPairPoint + 1]=1;
			infectPoint[diffPairPoint]    =1;
			infectPoint[diffPairPoint - 1]=1;
			// 上一行对应三个点
			infectPoint[diffPairPoint - width - 1]=1;
			infectPoint[diffPairPoint - width]=1;
			infectPoint[diffPairPoint - width + 1]=1;
			// 下一行对应三个点
			infectPoint[diffPairPoint + width - 1]=1;
			infectPoint[diffPairPoint + width]=1;
			infectPoint[diffPairPoint + width + 1]=1;
			// 下一行起始点
			infectPoint[ (diffPairPoint/width)*width + width]=1;
			
			total = total + pixelNum;
			count++;
		}
		
		// 输出宽度
		cout<<width<<endl;
		
		// 计算第一个点
		outValue = getMaxValue (0,0,count);
		outNum =1;
		
		map<int, int> ::iterator iter = infectPoint.begin();
		
		while( iter != infectPoint.end() ) {
			// 保证要计算点的坐标不超过边界且不是第一个点
			if (iter->first > 0 && iter->first < total){
				// 计数加上到上一次计算的点到这个点的区间的点的数量，但不包括当前点。
				// 当前点将在计算后处理。
				outNum += (iter->first - lastPos - 1) ;
				
				// cout<<"DEBUG "<<(iter->first)<<" "<<(iter->second)<<endl;
				
				// 计算当前点的横纵坐标
				i = iter->first/width;
				j = iter->first%width;
				
				// tmpValue为对当前点的计算结果
				tmpValue = getMaxValue (i,j,count);
				if (tmpValue == outValue){
					// 如果和上一个点的计算结果相同，则计数加1。
					outNum++;
				}else {
					// 如果和上一个点的计算结果不同，
					// 则输出上一组点，并初始化下一组点。
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
