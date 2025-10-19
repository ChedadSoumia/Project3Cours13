#pragma once
#include <iostream>
#include "clsMyQueue.h"

using namespace std;

template <typename T> 
class clsMyStack : public clsMyQueue <T>
{

protected:

public:
    void push(T Item)
    {

        clsMyQueue <T>::_MyList.InsertAtBeginning(Item);

    }
   

    T Top() {
        return clsMyQueue <T>::front();

    }
    T Bottom() {
        return clsMyQueue <T>::back();
    }

    

};

