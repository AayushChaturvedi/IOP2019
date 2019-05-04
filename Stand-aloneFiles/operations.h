#include<bits/stdc++.h>
#include "data.h"
using namespace std;

#ifndef MAT_POW_H
#define MAT_POW_H

matrix pow(matrix A,int k)
{
	matrix ans(A.n,A.n);
	matrix temp(A.n,A.n);
	for(int i=0;i<A.n;i++)
		for(int j=0;j<A.n;j++)
			ans.Matrix[i][i]=1;
	while(k>0)
	{
		if((k&1))
			ans=ans*A;
		k>>=1;
		A=A*A;
	}
	return ans;
}

#endif

#ifndef MAT_INV_H
#define MAT_INV_H

long double Determinant(matrix XX)
{
	vector<vector<long double>>X(XX.n,vector<long double>(XX.n,0));
	for(int i=0;i<XX.n;i++)
		for(int j=0;j<XX.n;j++)
			X[i][j]=XX.Matrix[i][j];
	long double res=1;
	long double eps=1e-9;
	for(int i=0;i<XX.n;i++)
	{
		int select=i;
		while(select<XX.n&&fabs(X[select][i])<eps)
		{
			select++;
		}
		if(select==XX.n)
			return 0;
		if(select!=i)
		{
			res*=-1;	
			for(int j=0;j<XX.n;j++)
			{
				swap(X[i][j],X[select][j]);
			}
		}
		res*=X[i][i];
		for(int j=i+1;j<XX.n;j++)
		{
			long double tmp=X[j][i]/X[i][i];
			for(int k=0;k<XX.n;k++)
			{
				X[j][k]-=X[i][k]*tmp;
			}
		}
	}
	return res;
}


#endif

