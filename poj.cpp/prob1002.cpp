// 2011, LOST BALLAD C++ Source File
//
// POJ 1002 487-3279
// 
// Problem Description: 
// 企业喜欢用容易被记住的电话号码。
// 让电话号码容易被记住的一个办法是将它写成一个容易记住的单词或者短语。
// 例如，你需要给 Waterloo 大学打电话时，可以拨打 TUT-GLOP。
// 有时，只将电话号码中部分数字拼写成单词。
// 当你晚上回到酒店，可以通过拨打310-GINO来向 Gino's 订一份 pizza。
// 让电话号码容易被记住的另一个办法是以一种好记的方式对号码的数字进行分组。
// 通过拨打 Pizza Hut 的“三个十”号码 3-10-10-10，你可以从他们那里订pizza。 
// 电话号码的标准格式是七位十进制数，并在第三、第四位数字之间有一个连接符。
// 电话拨号盘提供了从字母到数字的映射，映射关系如下： 
// A, B, 和 C 映射到 2  
// D, E, 和 F 映射到 3  
// G, H, 和 I 映射到 4  
// J, K, 和 L 映射到 5  
// M, N, 和 O 映射到 6  
// P, R, 和 S 映射到 7  
// T, U, 和 V 映射到 8  
// W, X, 和 Y 映射到 9  
// Q和Z没有映射到任何数字，连字符不需要拨号，可以任意添加和删除。 
// TUT-GLOP 的标准格式是 888-4567， 
// 310-GINO的标准格式是 310-4466， 
// 3-10-10-10 的标准格式是 310-1010。   
// 如果两个号码有相同的标准格式，那么他们就是等同的（相同的拨号）  
// 你的公司正在为本地的公司编写一个电话号码薄。
// 作为质量控制的一部分，你想要检查是否有两个和多个公司拥有相同的电话号码。
//  
// Input: 
// 输入的格式是，
// 第一行是一个正整数，指定电话号码薄中号码的数量（最多100000）。
// 余下的每行是一个电话号码。
// 每个电话号码由数字，大写字母（除了 Q 和 Z）以及连接符组成。
// 
// Output:
// 对于每个出现重复的号码产生一行输出，
// 输出是号码的标准格式紧跟一个空格然后是它的重复次数。
// 如果存在多个重复的号码按照号码的字典升序输出。
// 如果没有重复的号码，输出一行：No duplicates. 
// 
// Example Input: 
// 12 
// 4873279 
// ITS-EASY 
// 888-4567 
// 3-10-10-10 
// 888-GLOP 
// TUT-GLOP 
// 967-11-11 
// 310-GINO 
// F101010 
// 888-1200 
// -4-8-7-3-2-7-9- 
// 487-3279 
// 
// Example Output:
// 310-1010 2 
// 487-3279 4 
// 888-4567 3 
//  
// Submit Infomation:
// Memory: 5208K
// Time: 1188MS
//
// Author: Ballad
// Date: 2011-09-02
// Compile Env: Dev-C++ 4.9

#include <iostream>
#include <string>
#include <map>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Main Function.

int main (){
	int n;
	bool isHaveDup = false;
	string str;
	char arr[9] = {'0'};
	
	// Store the Map of telenumber and it's duplicate count.
	map<string, int> telmap;
	
	cin>>n;
	
	// Input, format and calctulate.
	for (int i=0; i<n; i++){
		cin>>str;
		
		for (int j=0,k=0; j<str.length();j++,k++){
            // End the loop when the array 'arr' come to it's end,
            // because that means the useful words are alreadly put from 'str'
            // to 'arr' and the remains words in 'str' are useless to 'arr'.
            if (k == 8){
                  break;
            }
            // Format the telenumber like "XXX-XXXX".
			if (k == 3){
                  arr[k] = '-';
                  k++;
            }
			switch (str[j]){
				case '0':
					arr[k] = '0';
					break;
				case '1':
					arr[k] = '1';
					break;
				case '2':
				case 'A':
				case 'B':
				case 'C':
					arr[k] = '2';
					break;
				case '3':
				case 'D':
				case 'E':
				case 'F':
					arr[k] = '3';
					break;
				case '4':
				case 'G':
				case 'H':
				case 'I':
					arr[k] = '4';
					break;
				case '5':
				case 'J':
				case 'K':
				case 'L':
					arr[k] = '5';
					break;
				case '6':
				case 'M':
				case 'N':
				case 'O':
					arr[k] = '6';
					break;
				case '7':
				case 'P':
				case 'R':
				case 'S':
					arr[k] = '7';
					break;
				case '8':
				case 'T':
				case 'U':
				case 'V':
					arr[k] = '8';
					break;
				case '9':
				case 'W':
				case 'X':
				case 'Y':
					arr[k] = '9';
					break;
				default:
					// Restore the value of k, because do nothing with arr[k]. 
					k--; 
					break;
            }
		}
		telmap[arr]++;
	}
	
	// Output the result.
	map<string, int>::iterator iter = telmap.begin();
	while( iter != telmap.end() ) {
		if ( (iter->second) > 1 ){
			cout<<(iter->first)<<" "<<(iter->second)<<endl;
			isHaveDup = true;
		}
		iter++;
	}
	if (!isHaveDup){
		cout<<"No duplicates. "<<endl;
	}
	
	system("PAUSE");
	return 0;
}
