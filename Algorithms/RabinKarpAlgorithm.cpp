#include<bits/stdc++.h>
using namespace std;
void RabinKarp(string str,string pat,int d,int q)
{
	int l=str.size();
	int m=pat.size();
	int s=0,p=0,h=1;//storing the hash value of string and pattern in s and p//h used while removing 1st term from hash value of string 
	for(int i=0;i<m-1;i++)
	h=(d*h)%q;
	for(int i=0;i<m;i++)
	{
		p=(p*d+pat[i])%q;
		s=(s*d+str[i])%q;
	}
	for(int i=0;i<l-m+1;i++)
	{
		if(p==s)
		{
	    	bool flag=true;
	    	int j;
		  for( j=0;j<m;j++)
		  {
		  	if(str[i+j]!=pat[j])
		  	{
		  		flag=false;
		  		break;
			}
		  }
		  if(j==m&&flag)
		  cout<<i<<" ";
		}
		if(i<l-m)
		{
			s=((s-str[i]*h)*d+str[i+m])%q;
			if(s<0)
			s+=q;
		}
	}
}
int main()
{
	string s,pat;
	getline(cin,s);
	getline(cin,pat);
    RabinKarp(s,pat,256,101);
	return 0;
}
