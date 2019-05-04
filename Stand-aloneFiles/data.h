#ifndef DATA_H
#define DATA_H
#include<bits/stdc++.h>
using namespace std;

struct matrix
{
	vector<vector<int>> Matrix;
	int n,m;

	matrix (int N,int M):n(N),m(M)
	{
		Matrix.clear();
		Matrix.resize(N,vector<int>(M,0));
	}

	matrix operator+(const matrix b)
	{
		matrix ans(n,m);
		ans.Matrix=Matrix;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				ans.Matrix[i][j]+=b.Matrix[i][j];
			}
		}
		return ans;
	}

	matrix operator-(const matrix b)
	{
		matrix ans(n,m);
		ans.Matrix=Matrix;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				ans.Matrix[i][j]-=b.Matrix[i][j];
			}
		}
		return ans;
	}

	matrix operator*(const matrix b)
	{
		matrix ans(n,m);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				for(int k=0;k<b.m;k++)
				{
					ans.Matrix[i][k]=ans.Matrix[i][k]+Matrix[i][j]*b.Matrix[j][k];
				}
			}
		}
		return ans;
	}
	friend ostream &operator<<( ostream &output, const matrix &D )
	{ 
        for(int i=0;i<D.n;i++)
        {
        	for(int j=0;j<D.m;j++)
        	{
        		output<<D.Matrix[i][j]<<" ";
        	}
        	output<<endl;
        }
        return output;            
    }

    friend istream &operator>>( istream  &input, matrix &D ) 
    { 
        for(int i=0;i<D.n;i++)
        {
        	for(int j=0;j<D.m;j++)
        	{
        		input>>D.Matrix[i][j];
        	}
        }
        return input;            
     }
};

#endif
