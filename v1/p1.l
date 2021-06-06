char [a-zA-Z]
digit [0-9]
special [$_@]
space " "
newline "\n"
Datatype "Integer"|"Double"|"Type_Char"|"Type_Void"
Operator "Op_Equ"|"Op_Plus"|"Op_Minus"|"Op_Divide"|"Op_Multiply"|"Op_And"|"Op_Or"|"Op_Mod"
Relational_Operator "Ro_GT"|"Ro_LT"|"Ro_GE"|"Ro_LE"|"Ro_And"|"Ro_Or"|"Ro_Equ"|"Ro_Equ"|"Ro_NEqu"

%{
	#include "bison.tab.h"
	#include <string.h>
%}



%%
{space}|{newline} {}
"#".*"#" {/*This is comment*/}
"." {return DOT;}
"," {return CM;}
{digit}+ 	{
				yylval.val = atoi(yytext);
				return NUM;
			}

"Func_Main" { return MAIN;}
"Print_Var" { return PRINTVAR;}
"Print_str" {return PRINTSTR;}
"Print_Line" {return PRINTLN;}

"Func_"({char}|{digit}|{special})+ {return FUNCTION;}

"Var_"({char}|{digit}|{special})+ { strcpy(yylval.text,yytext);return ID;}

"Integer" {  return INT;}
"Double" { return DOUBLE;}
"Char" { return CHAR;}

"Scan" {return SCAN;}

"PB" { return PB;}
"PE" { return PE;}

"BB" { return BB;}
"BE" { return BE;}

"Equal" {return ASGN;}
"Plus" {return PLUS;}
"Minus" {return MINUS;}
"Multiply" {return MULT;}
"Divide" {return DIV;}
"L_Sm" {return LT;}
"L_Gr" {return GT;}
"L_EqOrSm" {return LE;}
"L_EqOrGr" {return GE;}


"If" { return IF;}
"ElseIf" {return ELSEIF;}
"Else" {return ELSE;}

"For_Loop" {return FOR;}
"IncrementBy" {return INC;}
"To" {return TO;}
"While" {return WHILE;}
"Less"  {return LESS;}
"Great" {return GREAT;}

"Switch" {return SWITCH;}
"*" {return DEFAULT;}
":" {return COL;}
. {}


"\""(.)*"\"" {strcpy(yylval.text,yytext);return STR;}




%%


int yywrap()
{
	return 1;
}


int main(){
	yyin = fopen("sample.txt","r");
	//yyout = fopen("output.txt","w");
	yyparse();
}