#include<iostream>
#include<stdio.h> 
#include<math.h> 
using namespace std;
int gcd(int a, int h) 
{ 
	int temp; 
	while (1) 
	{ 
		temp = a%h; 
		if (temp == 0) 
		return h; 
		a = h; 
		h = temp; 
	} 
} 
int main() 
{ 

	int p,q;
	cout<<"Give the values of p and q.\n";
	cin>>p>>q;
	int n= p*q; 
    int e=2; 
	int phi = (p-1)*(q-1);
	cout<<"phi="<<phi; 
	while (e < phi) 
	{ 
		if (gcd(e, phi)==1) 
		{
		cout<<"\ne="<<e;
			break; }
		else
			e++; 
	} 
	int d=2;
	for(int i=2;i<phi;i++)
	{
		if((i*e)%phi==1)
		{
			d=i;
			cout<<"d="<<d;
			break;
		}
	}
	int msg; 
    cout<<"\nEnter the message.";
    cin>>msg;
	cout<<"\nMessage data = "<<msg; 
	int c=1;
	for(int j=1;j<=e;j++)
	{
		c=(c*msg)%n;
	}

	cout<<"\nEncrypted data ="<<c; 
	int m=1;
		for(int j=1;j<=d;j++)
	{
		m=(m*c)%n;
	}
	cout<<"\nOriginal Message Sent ="<<m; 

	return 0; 
} 

