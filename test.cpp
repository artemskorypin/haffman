#include <iostream> 
#include <fstream>
#include <stdio.h>

using namespace std;
int main(){
// тест на совпадение оригинала и разжатого текста

	int error=0,k=0,l=0;;//количество несовпадений, кол-во открытого текста,закрытого
	 ifstream e ("text.txt");
	 ifstream t ("output.txt");
	ifstream v ("code.txt");
	char a,b;
	while(!e.eof())
	{
		a=e.get();
		b=t.get();
		if(a!=b)
		{
			error++;
			cout<<k+1<<endl;// место ошибки
		}
		k++;	
	}
	if (t.eof())
	{ 
		cout<< "output.txt close \n"<< k<<endl;
		if (error==0){printf("текст совпадает\n");}
		else {printf("текст не совпадает\n");}
		cout<<error<<endl;
	}
// вычисление сжатия

	while(!v.eof())
	{
		v.get();
		l++;	
	}
	cout<<"coef sj "<<(float)k/l<<endl;//коеф сжатия
		
	e.close();
	t.close();
	v.close();

	return 0;
}

