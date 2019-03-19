%option noyywrap

%{
extern "C" int fileno(FILE *stream);
void count();

#include "c_parser.tab.hpp"
%}

DIGIT [0-9]
HEXDIGIT [0-9A-Fa-f]
OCTDIGIT [0-7]
NONDIGIT [_A-Za-z]
INTSUFFIX [uUlL]
EXPONENT [Ee][+-]?{DIGIT}+

%%

auto { count(); return T_AUTO; }
break { count(); return T_BREAK; }
case { count(); return T_CASE; }
char { count(); return T_CHAR; }
const { count(); return T_CONST; }
continue { count(); return T_CONTINUE; }
default { count(); return T_DEFAULT; }
do { count(); return T_DO; }
double { count(); return T_DOUBLE; }
else { count(); return T_ELSE; }
enum { count(); return T_ENUM; }
extern { count(); return T_EXTERN; }
float { count(); return T_FLOAT; }
for { count(); return T_FOR; }
goto { count(); return T_GOTO; }
if { count(); return T_IF; }
int { count(); return T_INT; }
long { count(); return T_LONG; }
register { count(); return T_REGISTER; }
return { count(); return T_RETURN; }
short { count(); return T_SHORT; }
signed { count(); return T_SIGNED; }
sizeof { count(); return T_SIZEOF; }
static { count(); return T_STATIC; }
struct { count(); return T_STRUCT; }
switch { count(); return T_SWITCH; }
typedef { count(); return T_TYPEDEF; }
union { count(); return T_UNION; }
unsigned { count(); return T_UNSIGNED; }
void { count(); return T_VOID; }
volatile { count(); return T_VOLATILE; }
while { count(); return T_WHILE; }

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

"." { return T_DOT; }
"->" { return T_ARROW; }
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

"!" { return T_NOT; }
"~" { return T_INVERT; }
"++" { return T_PLUS_PLUS; }
"--" { return T_MINUS_MINUS; }

0{OCTDIGIT}+{INTSUFFIX}? { yylval.number = std::stoi(yytext, nullptr, 8); return T_INT_LIT; }
0[xX]{HEXDIGIT}+{INTSUFFIX}? { yylval.number = std::stoi(yytext, nullptr, 16); return T_INT_LIT; }
{DIGIT}+{INTSUFFIX}? { yylval.number = std::stoi(yytext, nullptr, 10); return T_INT_LIT; }

{DIGIT}+\.{DIGIT}*[fF] { yylval.number = std::stod(yytext); return T_DOUBLE_LIT; }
{DIGIT}*\.{DIGIT}+[fF] { yylval.number = std::stod(yytext); return T_DOUBLE_LIT; }
{DIGIT}+\.{DIGIT}* { yylval.number = std::stod(yytext); return T_FLOAT_LIT; }
{DIGIT}*\.{DIGIT}+ { yylval.number = std::stod(yytext); return T_FLOAT_LIT; }
{DIGIT}*"."{DIGIT}+({EXPONENT})?[fF]	{ yylval.number = std::stod(yytext); return T_FLOAT_LIT; }
{DIGIT}+"."{DIGIT}*({EXPONENT})?[fF]	{ yylval.number = std::stod(yytext); return T_FLOAT_LIT; }
{DIGIT}*"."{DIGIT}+({EXPONENT})?	{ yylval.number = std::stod(yytext); return T_DOUBLE_LIT; }
{DIGIT}+"."{DIGIT}*({EXPONENT})?	{ yylval.number = std::stod(yytext); return T_DOUBLE_LIT; }

{NONDIGIT}?\"(\\.|[^\\"])*\" { yylval.string = new std::string(yytext, 1, strlen(yytext) - 2); return T_STRING_LIT; }
{NONDIGIT}?'(\\.|[^\\'])+'	{
    std::string str = yytext;
    if (str == "'\\\\'") { yylval.number = '\\'; }
    else if (str == "'\\n'") { yylval.number = '\n'; }
    else if (str == "'\\r'") { yylval.number = '\r'; }
    else if (str == "'\\t'") { yylval.number = '\t'; }
    else if (str == "'\\0'") { yylval.number = '\0'; }
    else if (str == "'\\\"'") { yylval.number = '\"'; }
    else { yylval.number = str[1]; }
    return T_CHAR_LIT;
  }

{NONDIGIT}({NONDIGIT}|{DIGIT})* { yylval.string = new std::string(yytext); return T_IDENTIFIER; }

[ \t\v\n\f]		{ count(); }
.			{ /* ignore bad characters */ }

%%

int column = 0;
int row = 0;
void count()
{
	for (int i = 0; i < strlen(yytext); ++i)
  {
		if (yytext[i] == '\n') { column = 0; row++; }
		else if (yytext[i] == '\t') { column += 8 - (column % 8); }
		else { column++; }
  }
}

void yyerror (char const *s)
{
  std::cout << "parse error: " << yytext << std::endl;
  std::cout << "line " << (row + 1) << ", column " << (column + 1) << std::endl;
  exit(1);
}
