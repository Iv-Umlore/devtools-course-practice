//  Copyright 2017 Kiparenko Ilya

#ifndef MODULES_KIPARENKO_ILYA_SYMBOLIC_DERIVATIVE_INCLUDE_TYPES_AND_CONSTS_H_
#define MODULES_KIPARENKO_ILYA_SYMBOLIC_DERIVATIVE_INCLUDE_TYPES_AND_CONSTS_H_

#include <unordered_map>
#include <math.h>

using std::string;
using std::unordered_map;

/*
enum Types::Type : unsigned int;

namespace std {
  template<>
  struct hash<Types::Type> {
	typedef PNR argument_type;
    typedef size_t result_type;

    result_type operator () (const argument_type& x) const {
      using type = typename std::underlying_type<argument_type>::type;
      return std::hash<type>()(static_cast<type>(x));
    }
  };
}

*/

namespace Types {

  enum Type {
    SYMBOL   = 0,
    NUMBER   = 1,
    FUNCTION = 2,
    EMPTY    = 3
  };

  enum Op : unsigned int{
    ADD     =  0,
    SUB     =  1,
    MUL     =  2,
    DIV     =  3,
    POW     =  4,
    LOG     =  5,
    SIN     =  6,
    COS     =  7,
    L_BRACE =  8,
    R_BRACE =  9
  };

  struct Node {
    Type type;
    union {
      int index;
      Op op_type;
      double real_value;
    };
    Node* left;
    Node* right;
  };

  Node* cr_Symbol_node(int   index = -1,
                       Node* left  = 0,
                       Node* right = 0);

  Node* cr_Number_node(double real_value = 0.0,
                       Node*  left       = 0,
                       Node*  right      = 0);

  Node* cr_Op_node(Op op_type = L_BRACE,
                   Node* left  = 0,
                   Node* right = 0);

  Node* cr_Empty_node(Node* left  = 0,
                      Node* right = 0);

  const unordered_map<string, Op> functions {
                                        {"+",   ADD},
                                        {"-",   SUB},
                                        {"*",   MUL},
                                        {"/",   DIV},
                                        {"^",   POW},
                                        {"log", LOG},
                                        {"sin", SIN},
                                        {"cos", COS},
                                        {"(",   L_BRACE},
                                        {")",   R_BRACE}
  };

  const unordered_map<Op, string> func_names {
                                        {ADD,     "+"},
                                        {SUB,     "-"},
                                        {MUL,     "*"},
                                        {DIV,     "/"},
                                        {POW,     "^"},
                                        {LOG,     "log"},
                                        {SIN,     "sin"},
                                        {COS,     "cos"},
                                        {L_BRACE, "("},
                                        {R_BRACE, ")"}
  };

  const unordered_map<Op, int> precendence {
                                        {ADD,     2},
                                        {SUB,     2},
                                        {MUL,     3},
                                        {DIV,     3},
                                        {POW,     4},
                                        {LOG,     5},
                                        {SIN,     5},
                                        {COS,     5},
                                        {L_BRACE, 0},
                                        {R_BRACE, 9}
  };

  const unordered_map<Op, int> nargs {
                                        {ADD,     2},
                                        {SUB,     2},
                                        {MUL,     2},
                                        {DIV,     2},
                                        {POW,     2},
                                        {LOG,     1},
                                        {SIN,     1},
                                        {COS,     1},
  };

  typedef double (*fun2args)(double, double);
  const unordered_map<Op, fun2args>
    real_funcs {
                {ADD,     [](double x, double y) {return x + y;}     },
                {SUB,     [](double x, double y) {return x - y;}     },
                {MUL,     [](double x, double y) {return x * y;}     },
                {DIV,     [](double x, double y) {return x / y;}     },
                {POW,     [](double x, double y) {return pow(x, y);} },
                {LOG,     [](double x, double y) {return log(x);}    },
                {SIN,     [](double x, double y) {return sin(x);}    },
                {COS,     [](double x, double y) {return cos(x);}    }
  };

}

#endif //  MODULES_KIPARENKO_ILYA_SYMBOLIC_DERIVATIVE_INCLUDE_TYPES_AND_CONSTS_H_
