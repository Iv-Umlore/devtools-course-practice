//  Copyright 2017 Ivan Kiselev
#include "../include/TDatLink.h"
TDatLink::TDatLink(TMonom* mon, TDatLink* link) : Value(*mon) {
that = mon;
pNext = link;
}
TDatLink::TDatLink(const TDatLink &Link) : Value(Link.Value) {
pNext = Link.pNext;
that = &Value;
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
TMonom* TDatLink::GetLinkMonom() {
return that;
}
