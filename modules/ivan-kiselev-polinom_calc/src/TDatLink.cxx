//  Copyright 2017 Ivan Kiselev
#include "../include/TDatLink.h"
template <class CL>
TDatLink<CL>::TDatLink(CL value, TDatLink<CL>* link) {
	Value = value;
	pValue = &Value;
	pNext = link;
}
template <class CL>
TDatLink<CL>::TDatLink(TDatLink<CL> &Link) {
	pNext = Link.pNext;
	Value = Link.Value;
}
template <class CL>
TDatLink<CL>::~TDatLink() {}
template <class CL>
void TDatLink<CL>::SetValue(CL value) {
	Value = value;
}
template <class CL>
CL* TDatLink<CL>::GetValue() {
	return Value;
}
//  Work with the pointer
template <class CL>
TDatLink<CL>* TDatLink<CL>::GetNextLink() {
	return pNext;
}
template <class CL>
void TDatLink<CL>::SetNextLink(TDatLink<CL> pLink) {
	pNext = pLink;
}
/*class TDatLink : public TRootLink {
protected:
	PTDatValue pValue;  //  Value
public:
	TDatLink(PTDatValue pVal = NULL, PTRootLink pN = NULL) :TRootLink(pN) {
		pValue = pVal;
	}
	TDatLink(TDatLink &Link) : TRootLink(Link.pNext) {
		pValue = Link.GetDatValue();
	}
	~TDatLink() {}
	virtual void SetDatValue(PTDatValue pVal) {
		pValue = pVal;
	}
	virtual PTDatValue GetDatValue() {
		return pValue;
	}
	TDatLink* GetNextDatLink() {
		return reinterpret_cast<TDatLink*>(pNext);
	}
	friend class TDatList;
};
typedef TDatLink *TDatLink<CL>;
#endif  //  MODULES_IVAN_KISELEV_POLINOM_CALC_INCLUDE_TDATLINK_H_
*/