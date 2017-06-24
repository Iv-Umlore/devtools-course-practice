//  Copyright 2017 Ivan Kiselev
#include "../include/Link.h"

Link::Link(PValue pval, PRootLink pn) : RootLink(pn) {
    pvalue_ = pval;
}

Link::Link(const Link &val) : RootLink(val.pnext_) {
    pvalue_ = val.pvalue_;
}

Link::~Link() {}

void Link::SetValue(PValue pval) {
    pvalue_ = pval;
}

PValue Link::GetValue() {
    return pvalue_;
}

Link* Link::GetNexLink() {
    return reinterpret_cast<Link*>(pnext_);
}
