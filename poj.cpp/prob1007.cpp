// 2011, LOST BALLAD C++ Source File
//
// POJ 1007 DNA Sorting
// 
// Description:
// One measure of "unsortedness" in a sequnece is the number of pairs of entires 
// that are out of order with respect to each other. For instance, in the letter 
// sequence "DAABEC", this measure is 5, sice D is greater than four letters to 
// its right and E is greater than one letter to its right. This measure is 
// called the number of inversions in the sequence. The sequence "AACEDGG" has 
// only one inversion (E and D) -- it is nearly sorted -- while the sequence 
// "ZWQM" has inversions (it is as unsorted as can be -- exactly the reverse of 
// sorted).
// You are responsible for cataloguing a sequence of DNA string (sequences 
// containing only the four letters A,C,G,T). However, you want to catalog them, 
// not in alphabetical order, but rather in order of "sortedness", from "most 
// sorted" to "least sorted". All the strings are of the same length.
// 
// Input:
// The first line contains 2 integers: a positive integer n (0<n<=50) giving 
// the length of the string; and a positive integer m (0<m<=100) giving the 
// number of strings. These are followed by m lines, each containing a string 
// of length n.
// 
// Output:
// Output the list of input strings, arranged from "most sorted" to "least 
// sorted". Since two string can be equally sorted, then output them according 
// the original order.
// 
// Sample Input:
// 10 6
// AACATGAAGG
// TTTTGGCCAA
// TTTGGCCAAA
// GATCAGATTT
// CCCGGGGGGA
// ATCGATGCAT
// 
// Sample Output:
// CCCGGGGGGA
// AACATGAAGG
// GATCAGATTT
// ATCGATGCAT
// TTTTGGCCAA
// TTTGGCCAAA
//
// Submit Infomation:
// Memory: 264K	
// Time: 0MS
//
// Author: Ballad
// Date: 2011-09-05
// Compile Env: Dev-C++ 4.9

#include <iostream>
#include <string>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Calculate the sortedness order.

int calcSortednessOrder (string str, int n)
{
	int count = 0;
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (str[i] > str[j]){
				count++;
			}
		}
	}
	return count;
}

////////////////////////////////////////////////////////////////////////////////
// Calculate the original order.

int calcOriginalOrder (string a, string b, int n)
{
	int ret = 0;
	for (int i=0;i<n;i++){
		if (a[i] > b[i]){
			ret = 1;
			break;
		}else if (a[i] < b[i]){
			ret = -1;
			break;
		}
	}
	return ret;
}

////////////////////////////////////////////////////////////////////////////////
// Main Function

int main ()
{
	int n,m;
	cin>>n>>m;
	
	string arrs[100];
	int arri[100];
	string str;
	int count;
	int isGreater = 0; // Whetehr the input string is greater than formers.
	
	for (int i=0;i<m;i++){
		cin>>str;
		count = calcSortednessOrder (str, n);
		arri[i] = count;
		arrs[i] = str;
		
		for (int j=i-1;j>=0;j--){
			if (arri[j] == count){
				isGreater = calcOriginalOrder (arrs[j], str, n);
			} else if (arri[j] > count){
				isGreater = 1;
			} else {
				break;
			}
			
			// Exchange the positions if isGreater equals 1. 
			if (isGreater == 1){
				arri[j+1] = arri[j];
				arrs[j+1] = arrs[j];
				arri[j] = count;
				arrs[j] = str;
			} else {
				break;
			}
		}
	}
	
	for (int i=0;i<m;i++){
		cout<<arrs[i]<<endl;
	}
	
	return 0;
}