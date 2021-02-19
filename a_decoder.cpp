#include <iostream> 
#include <fstream>
#include <vector>
#include <map>
#include <list>

using namespace std;

struct Range
{
    char s;
    int numb;
    int lb;
    int rb;
};

struct Sort//сравнивает 2, если Sort=1 то левый меньше правого и если 0, то наоборот
{
	bool operator() (Range l, Range r)
	{
		return l.numb > r.numb;
	}
};


int main()
{
    int count=0;
    ifstream f("code.txt", ios::out | ios::binary);//открываем файл для чтения, который нужно декодировать
	ofstream g("output.txt", ios::out | ios::binary);//открываем файл для записи декодированного текста
    int x1, x2;
	char s;
	map<char, int> m;
    map <char, int> ::iterator ii;														//мапа для таблицы кодирования
	// считывание из файла code.txt и декодирование
	f.read((char*)&x1, sizeof(x1));												//считываем первое число для расшифровки таблциы																//отнимаем значение int
    while (x1>0) 
	{
		f.read((char*)&s, sizeof(s));											//считываем символ
		f.read((char*)&x2, sizeof(x2));											//считываем его значение
		x1-=40;																//отнимаем 8 бит символа и 32 его значения
		m[s]=x2;                                                            //строим таблицу
    }
    list<Range> L;
    for(ii=m.begin(); ii!=m.end(); ii++)
    {
        Range p;
        p.s=ii->first;
        p.numb=ii->second;
        L.push_back(p);
    }
    L.sort(Sort());
    L.begin()->rb=L.begin()->numb;
    L.begin()->lb=0;
    list<Range>::iterator it=L.begin(), i2;
    i2=it;
    it++;
    for(; it!=L.end(); it++)
    {
        it->lb=i2->rb;
        it->rb=it->lb+it->numb;
        i2++;
    }
    count=0;
    int l=0, h=65535, delitel=L.back().rb; 
    int F_q=(h+1)/4, Half=F_q*2, T_q=F_q*3;
    int value=(f.get()<<8) | f.get();
    char symbl=f.get();
    while(!f.eof())
    {
        int freq=((value-l+1)*delitel-1)/(h-l+1);/* Hакопленная частота   */
        for(it=L.begin(); it->rb<=freq; it++);/* После нахождения символа */
        int l2=l;
        l=l+(it->lb)*(h-l+1)/delitel;
        h=l2+(it->rb)*(h-l2+1)/delitel-1;
        for(;;)
        {					/*Цикл отбpасывания битов*/
            if(h<Half);				/* Расшиpение нижней  половины   */
            else if(l>=Half)			/* Расшиpение веpхней половины после вычитание смещения Half   */
            {
                l-=Half; h-=Half; value-=Half;
            }
            else if((l>=F_q) && (h<T_q))/* Расшиpение сpедней половины   */
            {
                l-=F_q; h-=F_q; value-=F_q;
            } else break;
            l+=l; h+=h+1;				/* Увеличить масштаб интеpвала    */
            value+=value+( ( symbl>>(7-count) ) & 1);/* Добавить новый бит */
            count++;
            if(count == 8) 
            {
                symbl=f.get();
                count=0;
            }
        }
        g<<it->s;
    }
    f.close();
    g.close();
    return 0;
}
