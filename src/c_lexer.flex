%option noyywrap

%{
extern "C" int fileno(FILE *stream);

#include "c_parser.tab.hpp"
%}

%%

auto { return T_AUTO; }
break { return T_BREAK; }
case { return T_CASE; }
char { return T_CHAR; }
const { return T_CONST; }
continue { return T_CONTINUE; }
default { return T_DEFAULT; }
do { return T_DO; }
double { return T_DOUBLE; }
else { return T_ELSE; }
enum { return T_ENUM; }
extern { return T_EXTERN; }
float { return T_FLOAT; }
for { return T_FOR; }
goto { return T_GOTO; }
if { return T_IF; }
int { return T_INT; }
long { return T_LONG; }
register { return T_REGISTER; }
return { return T_RETURN; }
short { return T_SHORT; }
signed { return T_SIGNED; }
sizeof { return T_SIZEOF; }
static { return T_STATIC; }
struct { return T_STRUCT; }
switch { return T_SWITCH; }
typedef { return T_TYPEDEF; }
union { return T_UNION; }
unsigned { return T_UNSIGNED; }
void { return T_VOID; }
volatile { return T_VOLATILE; }
while { return T_WHILE; }

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
":" { return T_COLON; }
";" { return T_SEMICOLON; }
"?" { return T_QUESTION; }

"(" { return T_LBRACKET; }
")" { return T_RBRACKET; }
"[" { return T_LSQUARE_BRACKET; }
"]" { return T_RSQUARE_BRACKET; }
"{" { return T_LCURLY_BRACE; }
"}" { return T_RCURLY_BRACE; }

%%

void yyerror (char const *s)
{
  fprintf (stderr, "Lexing error : %s\n", s);
  exit(1);
}
