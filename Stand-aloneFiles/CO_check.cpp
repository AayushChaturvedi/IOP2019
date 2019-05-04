#include<bits/stdc++.h>
using namespace std;
#include "operations.h"
#define eps 1e-9

int main()
{
	int states;
	int inputs;
	int outputs;
	cout<<"Enter Number of States: ";
	cin>>states;
	cout<<endl<<"Enter Number of Inputs: ";
	cin>>inputs;
	cout<<endl<<"Enter Number of Outputs: ";
	cin>>outputs;
	matrix A(states,states);
	matrix B(states,inputs);
	matrix C(outputs,states);
	matrix D(outputs,inputs);
	cout<<endl<<"Enter A Matrix:"<<endl;
	cin>>A;
	cout<<endl<<"Enter B Matrix:"<<endl;
	cin>>B;
	cout<<endl<<"Enter C Matrix:"<<endl;
	cin>>C;
	cout<<endl<<"Enter D Matrix:"<<endl;
	cin>>D;

	matrix control(states,states);
	matrix observe(states,states);

	for(int i=0;i<states;i++)
	{
		matrix temp = pow(A,i)*B;
		for(int j=0;j<states;j++)
		{
			control.Matrix[j][i]=temp.Matrix[j][0];
		}
	}

	for(int i=0;i<states;i++)
	{
		matrix temp = C*pow(A,i);
		for(int j=0;j<states;j++)
		{
			observe.Matrix[i][j]=temp.Matrix[0][j];
		}
	}
	cout<<"Controllability Matrix: "<<endl;
	cout<<control<<endl;
	cout<<"Observability Matrix: "<<endl;
	cout<<observe<<endl;

	long double detc=Determinant(control);
	long double deto=Determinant(observe);
	if(fabs(detc)<eps)
	 	cout<<"System is not controllable."<<endl;
	 else
	 	cout<<"system is controllable"<<endl;
	if(fabs(deto)<eps)
		cout<<"System is not Observable."<<endl;
	else
		cout<<"system is Observable"<<endl;
	
	return 0;
}
