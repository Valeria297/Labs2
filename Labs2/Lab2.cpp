#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>

using namespace std;

FILE* f, * fl, * fll;

struct shop
{
	int nomer;
	char fio[50];
	int data;
	char adr[50];
};

shop sp[30];
int nst = 0;
int nm = 0;
int i, j;
int take, take3;
char take2[50], take4[50];
int err;

int menu()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Choose:" << endl;
	cout << "1. Create file" << endl;
	cout << "2. Input data" << endl;
	cout << "3. Read data" << endl;
	cout << "4. Add data" << endl;
	cout << "5. Linear search" << endl;
	cout << "6. Linear sort" << endl;
	cout << "7. Quicksort" << endl;
	cout << "8. Binary search" << endl;
	cout << "9. Exit" << endl;

	int i;
	cin >> i;

	return i;
}

void fileCreatingTost()
{
	fopen_s(&f, "LLex.txt", "w");
	fclose(f);
	cout << "File was created" << endl;
}

void addData()
{
	fopen_s(&f, "LLex.txt", "wb+");

	cout << "Input the number of item names: " << endl;
	cin >> nst;

	for (i = 0; i < nst; i++)
	{
		cout << "Input the number of the item:" << endl;

		cin >> sp[i].nomer;
		cout << "Input fio:" << endl;

		cin >> sp[i].fio;
		cout << "Input address:" << endl;

		cin >> sp[i].adr;
		cout << "Input data:" << endl;

		cin >> sp[i].data;
		fwrite(&sp[i], sizeof(shop), 1, f);
	}
	fclose(f);
}

void readData()
{
	cout << "Read data: " << endl;
	fopen_s(&f, "LLex.txt", "rb+");

	cout << "Naming" << " " << "Count" << " " << "Plant number" << endl;
	nst = 0; shop std;

	while (true)
	{
		int nwrt = fread(&std, sizeof(shop), 1, f);

		if (nwrt != 1) break;
		sp[nst] = std;
		cout << sp[nst].nomer << " " << sp[nst].fio << " " << sp[nst].adr << " " << sp[nst].data << endl;

		nst++;
	}
	fclose(f);
}

void addsCount()
{
	fopen_s(&f, "LLex.txt", "a");
	cout << "The count of adds: " << endl;

	int db = 0;
	cin >> db;

	for (j = 0; j < db; j++)
	{
		cout << "Input muber: " << endl;

		cin >> sp[j + nst].nomer;
		cout << "Input fio:" << endl;

		cin >> sp[j + nst].fio;
		cout << "Input address:" << endl;

		cin >> sp[j + nst].adr;
		cout << "Input data:" << endl;

		cin >> sp[j + nst].data;
		fwrite(&sp[j + nst], sizeof(shop), 1, f);
	}
	fclose(f);
}

void linearSort()
{
	fopen_s(&f, "LLex.txt", "rb+");
	fread(sp, sizeof(shop), 1, f);

	int kod = 0;
	cout << "Input data: " << endl;

	int f_key;
	cin >> f_key;

	for (i = 0; i < nst; i++)
	{
		if (sp[i].data == f_key)
		{
			kod = 1;
		}
	}

	if (kod == 1)
	{
		cout << "Found:" << endl << "number" << " " << "fio " << " " << "address" << endl;

		for (i = 0; i < nst; i++)
		{
			if (sp[i].data == f_key)
			{
				cout << sp[i].nomer << " " << sp[i].fio << " " << sp[i].adr << endl;
			}
		}
	}

	else if (kod == 0)
		cout << "Nothing was found." << endl;
	fclose(f);
}

void lin()
{
	fopen_s(&fl, "lineunaya_sortirovka.txt", "wb+");
	fopen_s(&f, "LLex.txt", "rb+");
	fread(sp, sizeof(shop), 1, f);

	cout << "Naming" << " " << "Count" << " " << "Plant number" << endl;

	for (i = 0; i < nst - 1; i++)
	{
		nm = i;

		for (j = i + 1; j < nst; j++)
			if (sp[j].data > sp[nm].data)
				nm = j;

		sp[nst + 1] = sp[nm];
		sp[nm] = sp[i];
		sp[i] = sp[nst + 1];

		fwrite(&sp[i], sizeof(shop), 1, fl);

		cout << sp[i].nomer << " " << sp[i].fio << " " << sp[i].adr << " " << sp[i].data << endl;

		if (i == nst - 2)
		{
			cout << sp[i + 1].nomer
				<< " " << sp[i + 1].fio 
				<< " " << sp[i + 1].adr
				<< " " << sp[i + 1].data << endl;

			fwrite(&sp[i + 1], sizeof(shop), 1, fl);
		}
	}

	err = 1;

	fclose(f);
	fclose(fl);
}

void quicksort(shop sp[30], int l, int r)
{
	int l_h = l;
	int r_h = r;

	take = sp[l].data;
	take3 = sp[l].nomer;

	swap(take2, sp[l].fio);
	swap(take4, sp[l].adr);

	while (l < r)
	{
		while ((sp[r].data >= take) && (l < r))
			r--;

		if (l != r)
		{
			sp[l] = sp[r];
			l++;
		}
		while ((sp[l].data <= take) && (l < r))
			l++;

		if (l != r)
		{
			sp[r] = sp[l];
			r--;
		}
	}

	sp[l].data = take;
	sp[l].nomer = take3;

	swap(sp[l].fio, take2);
	swap(sp[l].adr, take4);

	take = l;
	l = l_h;
	r = r_h;
	err += 1;

	if (l < take)
		quicksort(sp, l, take - 1);

	if (r > take)
		quicksort(sp, take + 1, r);
}

void qssf()
{
	fopen_s(&f, "LLex.txt", "rb+");
	fopen_s(&fll, "quicksort.txt", "wb+");
	quicksort(sp, 0, nst - 1);

	for (i = 0; i < nst; i++)
	{
		cout << sp[nst - 1 - i].nomer << " "
			<< sp[nst - 1 - i].fio 
			<< " " << sp[nst - 1 - i].adr 
			<< " " << sp[nst - 1 - i].data << endl;

		fwrite(&sp[nst - 1 - i], sizeof(shop), 1, fll);
	}

	fclose(f);
	fclose(fll);
}

int maxAtShop(shop sp[30], int left, int right, int key)
{
	int midd = 0;

	while (1)
	{
		midd = (left + right) / 2;
		int mm = sp[midd].data;

		if (key > mm)
			right = midd - 1;
		else if (key < mm)
			left = midd + 1;
		else
			return midd;

		if (left > right)
			return -1;
	}
}

void binarySearch()
{
	if (err == 1)
	{
		fopen_s(&fl, "lineunaya_sortirovka.txt", "rb+");
		cout << "Input the count of items, which is necessary: " << endl;
		int key, index;
		cin >> key;
		index = maxAtShop(sp, 0, nst, key);

		if (index >= 0)
			cout << "Item with this naming: " << index << endl;
		else
			cout << "Nothing was found. " << endl;
		fclose(fl);
	}

	else
	{
		cout << "Error. You need to sort your data" << endl;
	}
}

void linearSort(shop sp[50])
{
	int so, sa;
	char* str, * str1, * str2, * str3;
	fopen_s(&f, "shop.txt", "w+");

	for (int i = 0; i < nst - 1; i++)
	{
		str = sp[i].fio;
		str1 = sp[i].adr;
		sa = 0;

		for (int j = i + 1; j < nst; j++)
		{
			so = 0;
			str2 = sp[j].fio;
			str3 = sp[j].adr;

			if (str == str2 && str1 == str3)
			{
				so = 1;
				sa = 1;
			}

			if (so == 1)
			{
				for (int k = j; k < nst; k++)
				{
					sp[k] = sp[k + 1];
				}

				j--;
				nst--;
			}
		}

		if (sa == 1)
		{
			for (int p = i; p < nst - 1; p++)
				sp[p] = sp[p + 1];
			i--;
			nst--;
		}
	}

	for (int i = 0; i < nst; i++)
		fwrite(&sp[i], sizeof(shop), 1, f);
	fclose(f);
}

int main()
{
	while (true)
	{
		switch (menu())
		{
		case 1: fileCreatingTost(); break;
		case 2: addData(); break;
		case 3: readData(); break;
		case 4: addsCount(); break;
		case 5: linearSort(); break;
		case 6:lin(); break;
		case 7:qssf(); break;
		case 8:binarySearch(); break;
		case 9: return 0;
		case 10:linearSort(sp); break;
		default:cout << "Input the real number of menu, please" << endl;
		} 

		puts("Press any key to continue");
		system("pause"); system("cls");
		/*Sort and Search Lab was developed by Valeria Serbin*/
	}
}