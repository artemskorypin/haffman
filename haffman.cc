#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#include <cstdio>
using namespace std;
/*// Функция "просеивания" через кучу - формирование кучи
void siftDown(int *mas, int root, int bottom)
	{
	  int maxChild; // индекс максимального потомка
	  int done = 0; // флаг того, что куча сформирована
	  // Пока не дошли до последнего ряда
	  while ((root * 2 <= bottom) && (!done)) 
	  {
	    if (root * 2 == bottom)    // если мы в последнем ряду,
	      maxChild = root * 2;    // запоминаем левый потомок
	    // иначе запоминаем больший потомок из двух
	    else if (mas[root * 2] > mas[root * 2 + 1])
	      maxChild = root * 2;
	    else
	      maxChild = root * 2 + 1;
	    // если элемент вершины меньше максимального потомка
	    if (mas[root] < mas[maxChild]) 
	    {
	      int temp = mas[root]; // меняем их местами
	      mas[root] = mas[maxChild];
	      mas[maxChild] = temp;
	      root = maxChild; 
	    }
	    else // иначе
	      done = 1; // пирамида сформирована
	  }
	}
	// Функция сортировки на куче
int heapSort(int rs,) 
{
  // Формируем нижний ряд пирамиды
  for (int i = (m / 2) - 1; i >= 0; i--)
    siftDown(mas, i, m - 1);
	
 // Просеиваем через пирамиду остальные элементы
  for (int i = m - 1; i >= 1; i--)
  {
    int temp = mas[0];
    mas[0] = mas[i];
    mas[i] = temp;
    siftDown(mas, 0, i - 1);
  }
return *mas;
}
*/
int  kolafl[256],lenn = 0, flag = 0, k = 0, lenk = 0, rs = 1; 
FILE *f = fopen("book.txt",r);//vybor fole na chityvanie
if (f == NULL)//open file?
    {
        printf("error\n");
        return 0;
    }
else printf("file open\n");
fscanf(f,"%c",sym);// start chityvaniy
// alfavit
kolalf[sym] = 1;//chislo povtorov bykvy
lenn++;//kol-vo symvolov
while (!feof(f))
{
        fscanf(f,"%c",sym);
        lenn++;   
        kolafl[sym]++;
}    

	
