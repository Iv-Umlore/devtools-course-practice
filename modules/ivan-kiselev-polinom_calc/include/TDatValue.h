// Copyright 2017 Ivan Kiselev

#ifndef _TDatValue_
#define _TDatValue_

#include <iostream>

using namespace std;

class TDatValue {
public:
	virtual TDatValue * GetCopy() = 0; // copia
	~TDatValue() {};
};


#endif
