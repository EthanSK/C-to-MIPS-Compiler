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
<< { return T_LSHIFT; }
>> { return T_RSHIFT; }
< { return T_LESS_THAN; }
> { return T_GREATER_THAN; }
<= { return T_LESS_THAN_EQ; }
>= { return T_GREATER_THAN_EQ; }
== { return T_EQUALS; }
!= { return T_NOT_EQUALS; }

%%

void yyerror (char const *s)
{
  fprintf (stderr, "Lexing error : %s\n", s);
  exit(1);
}
