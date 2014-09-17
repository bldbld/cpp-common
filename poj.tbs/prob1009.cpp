// 2011, LOST BALLAD C++ SOURCE FILE
//
// POJ 1009 Edge Detection
//
// Time Limit: 1000MS		Memory Limit: 10000K
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
// Author: Ballad
// Date:
// Compile Env: 

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int width;
int pixelValue;
int pixelNum;
int outValue;
int outNum;
int total;
int height = 0;

// 存放输入的数据 
int rlePairValue[1000];
int rlePairNum[1000];

// 受影响的点数组
map<int, int> infectPoint;

int getValue (int i,int j,int index,int count){
	int pos = width * i + j;
	int ipos = pos+index;
	// cout<<"DEBUG:  GETVALUE"  <<"i"<<i<<"j"<<j<<" index"<<index<<endl;
	if ( ipos<0 || ipos >= total ){
      //     cout<<"DEBUG:  IAM OUT@1"<<endl;
		return -1;
	}
	if ( j==0 && (index == -8 || index == -1 || index == 6) ){
     //    cout<<"DEBUG:  IAM OUT@2"<<endl;
		return -1;
	}
	if ( j==width-1 && (index == -6 || index == 1 || index == 8) ){
   //      cout<<"DEBUG:  IAM OUT@3"<<endl;
		return -1;
	}
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

int getMaxValue (int i,int j,int count){
	int tmpValue[8] = {-1};
	
	int thisvalue =  getValue(i,j,0,count);

	tmpValue[0] = abs( thisvalue- getValue(i,j,1,count));
	tmpValue[1] = abs( thisvalue- getValue(i,j,-1,count));
	tmpValue[2] = abs( thisvalue- getValue(i,j,-8,count));
	tmpValue[3] = abs( thisvalue- getValue(i,j,-7,count));
	tmpValue[4] = abs( thisvalue- getValue(i,j,-6,count));
	tmpValue[5] = abs( thisvalue- getValue(i,j,6,count));
	tmpValue[6] = abs( thisvalue- getValue(i,j,7,count));
	tmpValue[7] = abs( thisvalue- getValue(i,j,8,count));
	
	int maxvalue = -1;
	for (int  k = 0;k<8;k++){
        if ( tmpValue[k] == thisvalue+1){
           continue;
        }
		if (tmpValue[k] > maxvalue){
			maxvalue = tmpValue[k];
		}
	}
	return maxvalue;
}

////////////////////////////////////////////////////////////////////////////////
// Main Function

int main ()
{
	int diffPairPoint; 
	int tmpValue;
	int pos;
    int count = 0; // The count num of input RLE pairs.
	
	while (1){
		cin>>width;
		// 0 indicates there are no more images. 
		if (width == 0){
			cout<<width;
			break;
		}
		// 初始化
		count = 0;
		total = 0;
		
		while (1){
			cin>>pixelValue>>pixelNum;
			// 0 0 indicates the end of the data.
			if (pixelValue==0 && pixelNum==0){
				break;
			}
			
			
			rlePairValue[count] = pixelValue;
			rlePairNum[count] = pixelNum;
			
			if (count>0){
				diffPairPoint +=  pixelNum;
			}else{
				diffPairPoint= pixelNum;
			}
			
			// 受影响的点数组
			infectPoint[diffPairPoint + 1]=1;
			infectPoint[diffPairPoint]    =1;
			infectPoint[diffPairPoint - 1]=1;
			
			infectPoint[diffPairPoint - 8]=1;
			infectPoint[diffPairPoint - 7]=1;
			infectPoint[diffPairPoint - 6]=1;
			
			infectPoint[diffPairPoint + 6]=1;
			infectPoint[diffPairPoint + 7]=1;
			infectPoint[diffPairPoint + 8]=1;
			
			total = total + pixelNum;
			
			count++;
		}
		
		height = total/width;
	  //	cout<<"DEBUG: count" <<count<<endl;
		outValue = getMaxValue (0,0,count);
		outNum =0;
		
		for (int i=0;i<height;i++){
			for (int j=0;j<width;j++){
				pos = width * i + j;
				
				if (infectPoint[pos] > 0 || j == 0){
					tmpValue = getMaxValue (i,j,count);
					if (tmpValue == outValue){
						outNum++;
					}else {
						cout<<outValue<<" "<<outNum<<endl;
						outNum = 1;
						outValue = tmpValue;
					}
				}else{
					outNum++;
				}
				// cout<<"DEBUG:" <<"i"<<i<<"j"<<j<<": "<<outValue<<endl;
			}
		}
		
		cout<<outValue<<" "<<outNum<<endl;
		cout<<"0 0"<<endl;
	}
	
	return 0;
}
