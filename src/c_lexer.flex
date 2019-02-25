%option noyywrap

%{
extern "C" int fileno(FILE *stream);

#include "c_parser.tab.hpp"
%}

%%

auto { return AUTO; }

"+" { return T_PLUS; }
"-" { return T_MINUS; }
"*" { return T_MULTIPLY; }
"/" { return T_DIVIDE; }
"%" { return T_MODULO; }
"<<" { return T_LSHIFT; }
">>" { return T_RSHIFT; }

"<" { return T_LESS_THAN; }
">" { return T_GREATER_THAN; }
"<=" { return T_LESS_THAN_EQ; }
">=" { return T_GREATER_THAN_EQ; }
"==" { return T_EQ_EQ; }
"!=" { return T_NOT_EQ; }

"&" { return T_AND; }
"&&" { return T_AND_AND; }
"|" { return T_OR; }
"||" { return T_OR_OR; }
"^" { return T_XOR; }

"=" { return T_EQ; }
"+=" { return T_PLUS_EQ; }
"-=" { return T_MINUS_EQ; }
"*=" { return T_MULTIPLY_EQ; }
"/=" { return T_DIVIDE_EQ; }
"%=" { return T_MODULO_EQ; }
"&=" { return T_AND_EQ; }
"|=" { return T_OR_EQ; }
"^=" { return T_XOR_EQ; }
"<<=" { return T_LSHIFT_EQ; }
">>=" { return T_RSHIFT_EQ; }

"," { return T_COMMA; }

%%

void yyerror (char const *s)
{
  fprintf (stderr, "Lexing error : %s\n", s);
  exit(1);
}
