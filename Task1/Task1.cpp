// Task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <string>
using namespace std;

void _1()
{
	cout << "Task 1" << endl;
	int a=0;

	while (a != -1)
	{
		int b = 2;
		bool c = true;
		cout << "a = "; cin >> a;
		if (a < b)
			cout << "Not prime" << endl;
		else
		{
			for (b; b <= sqrt(a); b++)
			{
				if (a%b == 0) c = false;
			}
			if (c)
				cout << "Prime" << endl;
			else cout << "Not prime" << endl;
		}
	}
}
void _1_1()
{
	cout << "Task 1.1" << endl;
	int n = 0;
	while (n != -1)
	{
		cout << "n = ";
		cin >> n;
		for (int i = 2; i < n; i++)
		{
			bool flag = true;
			for (int j = 2; j <= sqrt(i); j++)
			{
				if (i%j == 0)
				{
					flag = false;
					break;
				}
			}
			if (flag) cout << i << " ";
		}
		cout << endl;
	}
}
void _1_2()
{
	cout << "Task 1.2" << endl;
	int n = 0;
	while (n != -1)
	{
		cout << "n = "; cin >> n;
		int *A = new int[n];
		for (int i = 0; i < n; i++)
		{
			cout << "A[" << i << "] = "; cin >> A[i];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j) continue;
				else
				{
					cout << A[i] << "-" << A[j] << endl;
				}
			}

		}
		cout << endl;

	}
}

double X(double x, int n)
{
	if (n > 0)
	{
		cout << n << " ";
		return pow(pow(x, n % 2) * X(x, n / 2), 2);
	}
	else return 1;
}
void _1_3()
{
	cout << "Task 1.3" << endl;
	double x = 0;
	int n = 0;
	while (n != -1)
	{
		cout << "x = "; cin >> x;
		cout << "n = "; cin >> n;
		double s = pow(x, n % 2);
		n /= 2;
		cout << s * X(x, n) << endl;
	}
}

int F14(int n, int i, string s, int task)
{
	if (n == task && i == 7)
	{
		cout << s << endl;
		return 1;
	}
	else if (i > 6) return 0;	
	F14(n + i, i + 1, s + "+", task);
	F14(n - i, i + 1, s + "-", task);
	F14(n * i, i + 1, s + "*", task);
	F14(n / i, i + 1, s + "/", task);
}
void _1_4()
{
	cout << "Task 1.4" << endl;
	int n = 0;
	while (n != -1)
	{
		cout << "n = "; cin >> n;
		F14(1, 2, "", n);
	}
}

void _2_1()
{
	cout << "Task 2.1" << endl;
	int w = 0;
	int h = 0;
	while (w != -1)
	{
		cout << "h = "; cin >> h;
		cout << "w = "; cin >> w;		
		int *A = new int[h*w];
		/*int **A = new int*[h];
		for (int i = 0; i < h; i++)
		{
			A[i] = new int[w];
		}*/
				
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cout << "A[" << i << "," << j << "] = "; cin >> A[i*w + j]; cout << i*w + j << endl;
			}
		}

		bool flag = false;
		for (int i = 0; i < w*h-1 && !flag; i++)
		{
			for (int j = i+1; j < w*h; j++)
			{
				if (A[i] == A[j])
				{
					cout << "Found! " << A[i] << endl;
					flag = true;
					break;
				}
			}
		}
		if (!flag) cout << "Not found" << endl; 


	}
}
void _2_2()
{
	cout << "Task 2.2" << endl;
	int A = 0;
	while (A != -1)
	{
		cout << "A = "; cin >> A;
		bool flag = false;
		for (int x = 1; x <= sqrt(A/2); x++)
		{
			double yd = sqrt(A - pow(x, 2));
			int y = yd;
			if (yd == y && y > 0)
			{
				cout << A << " = " << pow(x, 2) << " + " << pow(y, 2) << endl;
				flag = true;
			}
		}
		if (!flag) cout << "NO!" << endl;
	}
}
void _2_3()
{
	cout << "Task 2.3" << endl;
	int n = 0;
	while (n != -1)
	{
		int c = 1;
		cout << "n = "; cin >> n;
		int *A = new int[n];
		for (int i = 0; i < n; i++)
		{
			cout << "A[" << i << "] = "; cin >> A[i];
		}
				
		for (int i = 1; i < n; i++)
		{
			bool flag = true;
			for (int j = i-1; j>=0; j--)
			{
				if (A[j] == A[i])
				{
					flag = false;
					break;
				}
			}
			if (flag) c++;

		}
		cout << "Different: " << c << endl;

	}
}

void F24(int n, int c, bool first, string s)
{
	cout << "n=" << n << " c=" << c << " s=" << s << endl;

	string ss;
	switch (c)
	{
	case 1:
	{
		if (n>-1 && n<10)
	    ss = s + to_string(n);
		cout << ss << endl;
		break;
	}
	default:
	{
		for (int i = first; i < 10, i < n; i++)
		{
			if (((n - i)*1. / (c - 1)) <= 9)
			{
				ss = s + to_string(i);
				F24(n - i, c - 1, false, ss);
			}
		}
		break;
	}
	}	
}

void _2_4()
{
	cout << "Task 2.4" << endl;
	int n = 0;
	int c = 0;
	while (n != -1)
	{		
		cout << "c = "; cin >> c;
		cout << "n = "; cin >> n;
		F24(n, c, true, "");
	}
}

int main()
{
	int input = 0;
	cout << "input = ";
	cin >> input;
	switch (input)
	{
	case 1:
	{
		_1();
		break;
	}
	case 11:
	{
		_1_1();
		break;
	}
	case 12:
	{
		_1_2();
		break;
	}
	case 13:
	{
		_1_3();
		break;
	}
	case 14:
	{
		_1_4();
		break;
	}
	case 21:
	{
		_2_1();
		break;
	}
	case 22:
	{
		_2_2();
		break;
	}
	case 23:
	{
		_2_3();
		break;
	}
	case 24:
	{
		_2_4();
		break;
	}
	default:
	{
		break;
	}
	}
	getch();
    return 0;
}



