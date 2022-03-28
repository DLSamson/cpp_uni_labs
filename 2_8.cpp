#include <iostream>

using namespace std;

int res(int n)
{	
	int array[10];
	
	for (int i=0; i<10; i++)
	{
		array[i] = 0;
	}
	while(n>0)
	{
		int c = n%10;
		if(array[c] != 0)
		{
			cout << "Odinakovie";
			return 0;
		}
		array[c] = 1;
		n /= 10;
	}
	cout << "Razlich";
	
	return 0;
}

int main()
{
	int n = 0 ;
	
	cin >> n;
	
	res(n);
	
	return 0;
}