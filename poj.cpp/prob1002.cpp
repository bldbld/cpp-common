// 2011, LOST BALLAD C++ Source File
//
// POJ 1002 487-3279
// 
// Problem Description: 
// ��ҵϲ�������ױ���ס�ĵ绰���롣
// �õ绰�������ױ���ס��һ���취�ǽ���д��һ�����׼�ס�ĵ��ʻ��߶��
// ���磬����Ҫ�� Waterloo ��ѧ��绰ʱ�����Բ��� TUT-GLOP��
// ��ʱ��ֻ���绰�����в�������ƴд�ɵ��ʡ�
// �������ϻص��Ƶ꣬����ͨ������310-GINO���� Gino's ��һ�� pizza��
// �õ绰�������ױ���ס����һ���취����һ�ֺüǵķ�ʽ�Ժ�������ֽ��з��顣
// ͨ������ Pizza Hut �ġ�����ʮ������ 3-10-10-10������Դ��������ﶩpizza�� 
// �绰����ı�׼��ʽ����λʮ�����������ڵ���������λ����֮����һ�����ӷ���
// �绰�������ṩ�˴���ĸ�����ֵ�ӳ�䣬ӳ���ϵ���£� 
// A, B, �� C ӳ�䵽 2  
// D, E, �� F ӳ�䵽 3  
// G, H, �� I ӳ�䵽 4  
// J, K, �� L ӳ�䵽 5  
// M, N, �� O ӳ�䵽 6  
// P, R, �� S ӳ�䵽 7  
// T, U, �� V ӳ�䵽 8  
// W, X, �� Y ӳ�䵽 9  
// Q��Zû��ӳ�䵽�κ����֣����ַ�����Ҫ���ţ�����������Ӻ�ɾ���� 
// TUT-GLOP �ı�׼��ʽ�� 888-4567�� 
// 310-GINO�ı�׼��ʽ�� 310-4466�� 
// 3-10-10-10 �ı�׼��ʽ�� 310-1010��   
// ���������������ͬ�ı�׼��ʽ����ô���Ǿ��ǵ�ͬ�ģ���ͬ�Ĳ��ţ�  
// ��Ĺ�˾����Ϊ���صĹ�˾��дһ���绰���뱡��
// ��Ϊ�������Ƶ�һ���֣�����Ҫ����Ƿ��������Ͷ����˾ӵ����ͬ�ĵ绰���롣
//  
// Input: 
// ����ĸ�ʽ�ǣ�
// ��һ����һ����������ָ���绰���뱡�к�������������100000����
// ���µ�ÿ����һ���绰���롣
// ÿ���绰���������֣���д��ĸ������ Q �� Z���Լ����ӷ���ɡ�
// 
// Output:
// ����ÿ�������ظ��ĺ������һ�������
// ����Ǻ���ı�׼��ʽ����һ���ո�Ȼ���������ظ�������
// ������ڶ���ظ��ĺ��밴�պ�����ֵ����������
// ���û���ظ��ĺ��룬���һ�У�No duplicates. 
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
