// ћодуль, объ€вл€ющий абстрактный класс объектов-значений списка

#ifndef _TDatValue_
#define _TDatValue_

#include <iostream>

using namespace std;

class TDatValue {
public:
	virtual TDatValue * GetCopy() = 0; // создание копии
	~TDatValue() {};
};


#endif
