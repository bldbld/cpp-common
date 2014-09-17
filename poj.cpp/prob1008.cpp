//4604199_AC_0MS_256K
#include <iostream>
#include <string>
using namespace std;
char a[19][7]={"pop","no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
char b[20][9] = { "imix", "ik",  "akbal", "kan", "chicchan", "cimi", "manik", "lamat","muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
int main ()
{
	int i,j,n,day,year,mon,days;
	cin>>n;
	cout<<n<<endl;
	for(i=0;i<n;i++){
		char month[5];
		cin>>day;
		getchar();
		getchar();
		cin>>month>>year;
		for(j=0;j<19;j++)
			if(strcmp(month,a[j])==0)
				break;
		days=year*365+j*20+day;
        cout<<(days%13+1)<<" "<<b[days%20]<<" "<<days/260<<endl;
	}

}