%{
#include "trad.tab.h"
#include <string.h>

int line_num = 1;

%}
%option yylineno


%%

implicit[ \t]+none    { return IMPLICIT; }
"::"                      { return DBL_COLON; }
"program"                 { return PROGRAM; }
"end program"                 { return ENDPROGRAM; }
"end do"                  { return ENDDO; }
"end"                     { return END; }
"integer"                 { return INTEGER; }
"real"                    { return REAL; }
"character"                { return CHARACTER; }
"logical"                 { return LOGICAL; }
"do"                      { return DO; }
"="                       { return '='; }
","                       { return ','; }
"if"         { return IF; }
"then"       { return THEN; }
"else"       { return ELSE; }
"end if"     { return ENDIF; }

"select case"      { return SELECTCASE; }
"case default"     { return CASEDEFAULT; }
"case"             { return CASE; }
"end select"       { return ENDSELECT; }
":"                { return ':'; }

"write"   { return WRITE; }
"read"    { return READ; }
"exit"      { return EXIT; }
"cycle"     { return CYCLE; }



[ \t\r]+                { /* Ignorar espacios */ }
".and."       { return AND; }
".or."       { return OR; }

[\xA0\xC2]   { /* ignorar caracteres UTF-8 especiales no válidos */ }

"("                       { return '('; }
")"                       { return ')'; }
">"                       { return '>'; }
"<"                       { return '<'; }
">="                      { return GE; }
"<="                      { return LE; }
"=="                      { return EQ; }
"/="                      { return NE; }

"+"                       { return '+'; }
"-"                       { return '-'; }
"*"                       { return '*'; }
"/"                       { return '/'; }

"print"                   { return PRINT; }
"PRINT"                   { return PRINT; }

\"([^"]*)\" {
  yylval.str = malloc(strlen(yytext) + 1);
  strcpy(yylval.str, yytext);
  return STRING;
} 

\'([^']*)\' {
  yylval.str = malloc(strlen(yytext) + 1);
  strcpy(yylval.str, yytext);
  return STRING;
}

"!"[^\n]* {
    yylval.str = strdup(yytext + 1);
    return COMENTARIO;
}



[0-9]+                    {
                            yylval.str = strdup(yytext);
                            return NUMBER;
                         }

[Tt][Rr][Uu][Ee]     { yylval.str = strdup(yytext); return TRUE; }
[Ff][Aa][Ll][Ss][Ee] { yylval.str = strdup(yytext); return FALSE; }


[a-zA-Z_][a-zA-Z0-9_]*     {
                            yylval.str = strdup(yytext);
                            return ID;
                         }

\n {
    line_num++;
}

. {
    printf("//error en línea %d: '%s'\n", line_num, yytext);
}


%%

int yywrap() { return 1; }
