#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int checkKhoangTrong(char c) 
{
	if(c == ' ' || c == '\t' || c == '\n')
       return 1;
    return 0;
}

int timViTri(char* s, int* Dodai) 
{
	int Dodaituhientai = 0; 
	int Dodaitulonnhat = 0; 
	int Vitritudainhat = 0; 
	int Vitrituhientai = 0; 
	int size = strlen(s);
	for(int i = 0; i< size; i++) 
    {
		if(checkKhoangTrong(s[i]) == 0) 
        { 
			Vitrituhientai = i - Dodaituhientai;
			Dodaituhientai++;
		} 
        else 
        {
			if(Dodaituhientai > Dodaitulonnhat) 
            {
				Dodaitulonnhat = Dodaituhientai;
				Vitritudainhat = Vitrituhientai;
			}
			Dodaituhientai = 0;
		}
	}
	
	*Dodai = Dodaitulonnhat;
	return Vitritudainhat;
}

void InTu(char *s, int Vitritudainhat, int Dodai) 
{
	for(int i = Vitritudainhat; i < Vitritudainhat + Dodai; i++) 
    {
		cout<<s[i];
	}
}

void InRaTuCoDoDaik(char *s, int k)
{
    int Dodaituhientai =0;
    int Vitrituhientai = 0; 
    int size = strlen(s);
	for(int i = 0; i< size; i++) 
    {
		if(checkKhoangTrong(s[i]) == 0) 
        { 
			Vitrituhientai = i - Dodaituhientai;
			Dodaituhientai++;
		} 
        else 
        {
			if(Dodaituhientai == k) 
            {
				InTu(s,Vitrituhientai, Dodaituhientai);
                cout<<"\t";
			}
            Dodaituhientai = 0;
		}
	}
}

int main()
{
	char *s = new char[9999];
    cout<<"Nhap cau: ";
	fgets(s,9999, stdin);

	int Dodai = 0;
	int Vitri = timViTri(s, &Dodai);

	cout<<"Tu dai nhat: ";
    InTu(s, Vitri, Dodai);
    cout<<endl;

    int k;
    cout<<"Nhap k: "; cin>>k;
    cout<<"Cac tu co do dai la k: ";
    InRaTuCoDoDaik(s, k);


	cout<<"Thunao";
    delete[] s;
	return 0;
}
