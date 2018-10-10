//
// Created by Kisely Tamás on 2018. 10. 10..
//

#include <limits>
#include <assert.h>
#include "Stack.h"

using namespace std;


Stack::Stack(const Stack& theOther)
{
    // Az operator=-t hívjuk,
    // és az érvényes adatot feltételez
    pData = NULL;

    *this=theOther;
}

const Stack& Stack::operator = (const Stack& theOther)
{
    assert(this != &theOther);

    // Felszabadítjuk az eddigi adatokat
    if(pData!=NULL)
    {
        delete [] pData;
    }

    // Átmásoljuk a másik verem tartalmát
    if(theOther.elementNum==0)
    {
        elementNum=0;
        pData=NULL;
    }
    else
    {
        elementNum=theOther.elementNum;
        pData=new int[elementNum];
        for(unsigned int i=0;i<elementNum;i++)
        {
            pData[i]=theOther.pData[i];
        }
    }
    return *this;
}

void Stack::pop(int& element)
{
    if(elementNum==0)
    {
        // A félév elején ez egy lehetséges jó megoldás:
        // cerr << "Data request from empty stack." << endl;
        throw stack_exception("Data request from empty stack.");
        return;
    }

    if(elementNum==1)
    {
        element=pData[0];
        delete []pData;
        pData=NULL;
        elementNum=0;
        return;
    }

    elementNum--;
    element=pData[elementNum];
    int* pTemp=new int[elementNum];

    for(unsigned int i=0;i<elementNum;i++)
    {
        pTemp[i]=pData[i];
    }
    delete[] pData;
    pData=pTemp;

}

void Stack::push(int element)
{
    // C++-ban az UINT_MAX helyett a limits headerben található
    // numeric_limits sablont használjuk a maximális unsigned int érték
    // lekérdezésére
    if(elementNum==numeric_limits<unsigned int>::max())
    {
        // A félév elején ez egy lehetséges jó megoldás:
        // cerr << "Stack is full." << endl;

        throw stack_exception("Stack is full.");
        return;
    }

    int* pTemp=new int[elementNum+1];

    for(unsigned int i=0; i<elementNum;i++)
    {
        pTemp[i]=pData[i];
    }

    pTemp[elementNum]=element;

    if(pData)delete[]pData;
    pData=pTemp;
    elementNum++;
}
