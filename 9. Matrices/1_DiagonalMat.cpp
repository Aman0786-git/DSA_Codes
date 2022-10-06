#include<iostream>
using namespace std;
class Diagonal {
private:
	int n;
	int *A;
public:
	Diagonal(int n)
	{
		this->n = n;
		A = new int[n];
	}
	void setAr(int i,int j,int x);
	int getAr(int i,int j);
	void Display();
	~Diagonal(){
		delete []A;
	}
};

void Diagonal :: setAr(int i,int j,int x)
{
	if(i==j)A[i-1]=x;
}

int Diagonal::getAr(int i,int j)
{
	if(i==j)return A[i-1];
	else
	return 0;
}

void Diagonal:: Display()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)cout<<A[i];
			else
				cout<<"0";
		}
		cout<<"\n";
	}
}

int main()
{
	Diagonal d(4);

	d.setAr(1,1,4);
	d.setAr(2,2,3);
	d.setAr(3,3,1);
	d.setAr(4,4,5);

	cout<<d.getAr(3,3)<<endl;

	d.Display();
}
