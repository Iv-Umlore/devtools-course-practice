//  Copyright 2017 Ivan Kiselev
#include "../include/TDatLink.h"
TDatLink::TDatLink(TMonom* mon, TDatLink* link) {
	Value = *mon;
	pNext = link;
}
TDatLink::TDatLink(TDatLink &Link) {
	pNext = Link.pNext;
	Value = Link.Value;
}
TDatLink::~TDatLink() {}
void TDatLink::SetValue(TMonom value) {
	Value = value;
}
TMonom TDatLink::GetValue() {
	return Value;
}
//  Work with the pointer
TDatLink* TDatLink::GetNextLink() {
	return pNext;
}
void TDatLink::SetNextLink(TDatLink *pLink) {
	pNext = pLink;
}
bool TDatLink::operator==(TDatLink *Link) {
	return (this->GetValue() == Link->GetValue());
}
/*class TDatLink : public TRootLink {
protected:
	PTMonom pValue;  //  Value
public:
	TDatLink(PTMonom pVal = NULL, PTRootLink pN = NULL) :TRootLink(pN) {
		pValue = pVal;
	}
	TDatLink(TDatLink &Link) : TRootLink(Link.pNext) {
		pValue = Link.GeTMonom();
	}
	~TDatLink() {}
	virtual void SetValue(PTMonom pVal) {
		pValue = pVal;
	}
	virtual PTMonom GeTMonom() {
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