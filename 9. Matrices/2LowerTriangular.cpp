#include<iostream>
using namespace std;
class LowTri {
private:
	int n;
	int *A;
public:
	LowTri()
	{
		n=2;
		A=new int[2*(2+1)/2];
	}
	LowTri(int n)
	{
		this->n = n;
		A=new int[n*(n+1)/2];
	}
	void setAr(int i,int j,int x);
	int getAr(int i,int j);
	void Display();
	int getDimension(){return n;}
	~LowTri(){
		delete []A;
	}
};

void LowTri :: setAr(int i,int j,int x)
{
	if(i>=j)A[i*(i-1)/2 + j-1]=x;
}

int LowTri::getAr(int i,int j) 
{
	if(i>=j)return A[i*(i-1)/2 + j-1];
	else
	return 0;
}

void LowTri:: Display()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i>=j)cout<<A[i*(i-1)/2 + j-1];
			else
				cout<<"0";
		}
		cout<<"\n";
	}
}

int main()
{
	int d,x;
	cout<<"Enter Dimension: ";
	cin>>d;
	LowTri lm(d);
	cout<<"Enter All Elements: ";
	for(int i=1;i<=d;i++)
	{
		for(int j=1;j<=d;j++)
			{
				cin>>x;
				lm.setAr(i,j,x);
			}
	}
	cout<<lm.getDimension()<<endl;
	lm.Display();

	return 0;
}
