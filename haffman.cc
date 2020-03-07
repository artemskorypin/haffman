#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#include <cstdio>
using namespace std;
int alf[256], kolafl[256],lenn = 0, flag = 0, k = 0, lenk = 0, rs = 1; 
FILE *f = fopen("book.txt",r);//vybor fole na chityvanie
if (f == NULL)//open file?
    {
        printf("error\n");
        return 0;
    }
else printf("file open\n");
fscanf(f,"%c",sym);// start chityvaniy
alf[0] = sym;// alfavit
kolalf[0] = 1;//chislo povtorov bykvy
lenn++;//kol-vo symvolov
while (!feof(f))
{
        fscanf(f,"%c",sym);
        lenn++;
        for(int i = 0, i < rs, i++)//rs - razlichnye symvoly
            {
                if (sym == alf[i])
                    {
                        kolafl[i]++;
                        flag = 1;// bykva sovpala 
                    }
            }
        if (flag == 0) 
        {
                alf[rs] = sym;
                kolafl[rs] = 1;
                rs++;
        }    
        flag = 0;//gotovimcy k novoy proverke
}    
