#include <iostream>

using namespace std;

int res(int n[], int sum, int ar[])
{
	
	for(int i = 0; i < 9; i++)
	{
		cin >> n[i];
		
		while(n[i]<10 || n[i]>99)
		{
			cout << "Nevernoe znach";
			cin >> n[i];
		}
		sum+=(int)(n[i]/10);
        sum+=n[i] % 10;
        ar[i]=sum;
	}	
	
	for (int i=0; i<9; i++)
        cout<<ar[i]<<" ";
	
	return 0;
}

int main()
{
	cout << "Vvedite 9 chisel";
	
	int n[9], sum = 0, ar[9];
	
	res(n, sum, ar);
	
	return 0;
}