%option noyywrap

%{
extern "C" int fileno(FILE *stream);

#include "c_parser.tab.hpp"
%}

%%

auto { return AUTO; }

%%

void yyerror (char const *s)
{
  fprintf (stderr, "Lexing error : %s\n", s);
  exit(1);
}
