%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
int yyerror(const char *s);
extern int yylineno;

int indent_level = 1;

char* indent() {
    int i;
    int size = indent_level + 1;
    char* buf = malloc(size);
    for(i = 0; i < indent_level; i++) {
        buf[i] = '\t';  // un tab por nivel
    }
    buf[indent_level] = '\0';
    return buf;
}   

char* indent_lines(const char* code) {
    char* result = malloc(strlen(code) * 2);
    result[0] = '\0';
    char* temp = strdup(code);
    char* line = strtok(temp, "\n");
    while (line != NULL) {
        char* ind = indent();
        strcat(result, ind);
        strcat(result, line);
        strcat(result, "\n");
        free(ind);
        line = strtok(NULL, "\n");
    }
    free(temp);
    return result;
}
%}

%union {
    char* str;
}

%token PROGRAM END INTEGER REAL DBL_COLON PRINT ENDPROGRAM
%token ENDDO DO IMPLICIT
%token IF THEN ELSE ENDIF GE LE EQ NE AND OR WRITE READ
%token SELECTCASE CASE CASEDEFAULT ENDSELECT
%token EXIT CYCLE
%token LOGICAL TRUE FALSE CHARACTER

%token <str> ID NUMBER STRING COMENTARIO

%type <str> program_body declarations declaration statements statement case_blocks case_block expression id_list

%left ':'
%left OR
%left AND
%left '+' '-'
%left '*' '/'
%left '>' '<' GE LE EQ NE

%%

program:
    statement
    PROGRAM ID program_body END PROGRAM ID
    {
        printf("#include <iostream>\nusing namespace std;\n\nint main() {\n%s\treturn 0;\n}\n", $3);
    }
;

program_body:
    declarations statements
    {
        $$ = malloc(strlen($1) + strlen($2) + 1);
        sprintf($$, "%s%s", $1, $2);
        free($1); free($2);
    }

;

declarations:
     { $$ = strdup(""); }
    | declaration declarations
    {
        $$ = malloc(strlen($1) + strlen($2) + 1);
        sprintf($$, "%s%s", $1, $2);
        free($1); free($2);
    }
;

declaration:
    INTEGER DBL_COLON id_list
    {
        char* ind = indent();
        $$ = malloc(strlen(ind) + strlen($3) + 30);
        sprintf($$, "%sint %s = 0;\n", ind, $3);
        free(ind); free($3);
    }
    | REAL DBL_COLON id_list
    {
        char* ind = indent();
        $$ = malloc(strlen(ind) + strlen($3) + 40);
        sprintf($$, "%sfloat %s;\n", ind, $3);
        free(ind); free($3);
    }
    | CHARACTER DBL_COLON id_list{
        char* ind = indent();
        $$ = malloc(strlen(ind) + strlen($3) + 60);
        sprintf($$, "%sstring %s;\n", ind, $3);
        free(ind); free($3);
    }

    | LOGICAL DBL_COLON id_list {
        char* ind = indent();
        $$ = malloc(strlen(ind) + strlen($3) + 40);
        sprintf($$, "%sbool %s = false;\n", ind, $3);
        free(ind); free($3);
    }
;


id_list:
    ID { 
        $$ = malloc(strlen($1) + 5);
        sprintf($$, "%s", $1);
        free($1);
    }
  | ID '=' expression {
        $$ = malloc(strlen($1) + strlen($3) + 4);
        sprintf($$, "%s = %s", $1, $3);
        free($1); free($3);
    }
  | ID ',' id_list {
        $$ = malloc(strlen($1) + strlen($3) + 4);
        sprintf($$, "%s, %s", $1, $3);
        free($1); free($3);
    }
  | ID '=' expression ',' id_list {
        $$ = malloc(strlen($1) + strlen($3) + strlen($5) + 6);
        sprintf($$, "%s = %s, %s", $1, $3, $5);
        free($1); free($3); free($5);
    }
;

;

statements:
    statement { $$ = $1; }
    | statement statements
    {
        $$ = malloc(strlen($1) + strlen($2) + 1);
        sprintf($$, "%s%s", $1, $2);
        free($1); free($2);
    }
    | IMPLICIT
    {
        char* ind = indent();
        $$ = malloc(strlen(ind) + 30);
        sprintf($$, "%s// implicit none (todas las variables deben ser declaradas)\n", ind);
        free(ind);
    }

    | error '\n' statements {
        fprintf(stderr, "Se recuperó de un error en la línea.\n");
        $$ = $3;
    }
    | error statements {
        fprintf(stderr, "Se recuperó de un error.\n");
        $$ = $2;
    }

;

statement:
    ID '=' expression
    {
        char* ind = indent();
        $$ = malloc(strlen(ind) + strlen($1) + strlen($3) + 10);
        sprintf($$, "%s%s = %s;\n", ind, $1, $3);
        free(ind); free($1); free($3);
    }
    | EXIT
    {
        char* ind = indent();
        $$ = malloc(20);
        sprintf($$, "%sbreak;\n", ind);
        free(ind);
    }
    | CYCLE
    {
        char* ind = indent();
        $$ = malloc(24);
        sprintf($$, "%scontinue;\n", ind);
        free(ind);
    }
    | PRINT '*' ',' expression
    {
        char* ind = indent();
        $$ = malloc(strlen(ind) + strlen($4) + 20);
        sprintf($$, "%scout << %s;\n", ind, $4);
        free(ind); free($4);
    }
    | PRINT '*'
    {
        char* ind = indent();
        $$ = malloc(30);
        sprintf($$, "%scout << endl;\n", ind);
        free(ind);
    }
    | DO ID '=' expression ',' expression statements ENDDO
    {
        char* ind = indent();
        char* body = indent_lines($7);
        int size = strlen(ind) + strlen($2) + strlen($4) + strlen($6) + strlen(body) + 200;
        $$ = malloc(size);
        sprintf($$, "%sfor (int %s = %s; %s <= %s; %s++) {\n%s%s}\n",
                ind, $2, $4, $2, $6, $2, body, ind);
        free($2); free($4); free($6); free($7); free(body); free(ind);
    }
    | DO statements ENDDO {
        char* ind = indent();
        char* body = indent_lines($2);
        $$ = malloc(strlen(ind) + strlen(body) + 50);
        sprintf($$, "%swhile (true) {\n%s%s}\n", ind, body, ind);
        free(ind); free(body); free($2);
    }

    | IF '(' expression ')' THEN statements ENDIF
    {
        char* ind = indent();
        char* then_body = indent_lines($6);
        int size = strlen(ind) + strlen($3) + strlen(then_body) + 50;
        $$ = malloc(size);
        sprintf($$, "%sif (%s) {\n%s%s}\n", ind, $3, then_body, ind);
        free($3); free($6); free(then_body); free(ind);
    }
    | IF '(' expression ')' THEN statements ELSE statements ENDIF
    {
        char* ind = indent();
        char* then_body = indent_lines($6);
        char* else_body = indent_lines($8);
        int size = strlen(ind) + strlen($3) + strlen(then_body) + strlen(else_body) + 100;
        $$ = malloc(size);
        sprintf($$, "%sif (%s) {\n%s%s} else {\n%s%s}\n",
                ind, $3, then_body, ind, else_body, ind);
        free($3); free($6); free($8); free(then_body); free(else_body); free(ind);
    }
    | SELECTCASE '(' expression ')' case_blocks ENDSELECT
    {
        char* ind = indent();
        char* body = indent_lines($5);
        int size = strlen(ind) + strlen($3) + strlen(body) + 200;
        $$ = malloc(size); 
        sprintf($$, "%sswitch (%s) {\n%s%s}\n", ind, $3, body, ind);
        free($3); free($5); free(body); free(ind);
    }
    | WRITE '(' '*' ',' '*' ')' expression
    {
        char* ind = indent();
        $$ = malloc(strlen(ind) + strlen($7) + 40);
        sprintf($$, "%scout << %s << endl;\n", ind, $7);
        free(ind); free($7);
    }
    | READ '(' '*' ',' '*' ')' ID
    {
        char* ind = indent();
        $$ = malloc(strlen(ind) + strlen($7) + 20);
        sprintf($$, "%scin >> %s;\n", ind, $7);
        free(ind); free($7);
    }
    | COMENTARIO {
        char* ind = indent();
        $$ = malloc(strlen(ind) + strlen($1) + 10);
        sprintf($$, "%s//%s\n", ind, $1);
        free(ind); free($1);
    }
;

case_blocks:
    case_blocks case_block
    {
        $$ = malloc(strlen($1) + strlen($2) + 1);
        sprintf($$, "%s%s", $1, $2);
        free($1); free($2);
    }
    | case_block { $$ = $1; }
;

case_block:
    CASE '(' NUMBER ')' statements
    {
        char* ind = indent();
        char* body = indent_lines($5);
        int size = strlen(ind) * strlen($3) + strlen($5) *strlen(body) + 40;
        $$ = malloc(size);
        sprintf($$, "%scase %s:\n%sbreak;\n$s",ind, $3,body, ind);
        free($3); free($5);

    }
    | CASE '(' NUMBER ':' NUMBER ')' statements
    {
        int size = strlen($3) + strlen($5) + strlen($7) + 100;
        $$ = malloc(size);
        sprintf($$, "    default:\n        if ($switch_var >= %s && $switch_var <= %s) {\n%s        break;\n        }\n",
                $3, $5, $7);
        free($3); free($5); free($7);
    }
    | CASEDEFAULT statements
    {
        $$ = malloc(strlen($2) + 40);
        sprintf($$, "    default:\n%s        break;\n", $2);
        free($2);
    }
;

expression:
    NUMBER { $$ = strdup($1); free($1); }
    | STRING { $$ = strdup($1); free($1); }
    | ID { $$ = strdup($1); free($1); }
    | expression '+' expression
    {
        $$ = malloc(strlen($1) + strlen($3) + 5);
        sprintf($$, "(%s + %s)", $1, $3);
        free($1); free($3);
    }
    | expression '-' expression
    {
        $$ = malloc(strlen($1) + strlen($3) + 5);
        sprintf($$, "(%s - %s)", $1, $3);
        free($1); free($3);
    }
    | expression '*' expression
    {
        $$ = malloc(strlen($1) + strlen($3) + 5);
        sprintf($$, "(%s * %s)", $1, $3);
        free($1); free($3);
    }
    | expression '/' expression
    {
        $$ = malloc(strlen($1) + strlen($3) + 5);
        sprintf($$, "(%s / %s)", $1, $3);
        free($1); free($3);
    }
    | expression '>' expression
    {
        $$ = malloc(strlen($1) + strlen($3) + 5);
        sprintf($$, "%s > %s", $1, $3);
        free($1); free($3);
    }
    | expression '<' expression
    {
        $$ = malloc(strlen($1) + strlen($3) + 5);
        sprintf($$, "%s < %s", $1, $3);
        free($1); free($3);
    }
    | expression GE expression
    {
        $$ = malloc(strlen($1) + strlen($3) + 6);
        sprintf($$, "%s >= %s", $1, $3);
        free($1); free($3);
    }
    | expression LE expression
    {
        $$ = malloc(strlen($1) + strlen($3) + 6);
        sprintf($$, "%s <= %s", $1, $3);
        free($1); free($3);
    }
    | expression EQ expression
    {
        $$ = malloc(strlen($1) + strlen($3) + 6);
        sprintf($$, "%s == %s", $1, $3);
        free($1); free($3);
    }
    | expression NE expression
    {
        $$ = malloc(strlen($1) + strlen($3) + 6);
        sprintf($$, "%s != %s", $1, $3);
        free($1); free($3);
    }
    | expression AND expression
    {
        $$ = malloc(strlen($1) + strlen($3) + 6);
        sprintf($$, "%s && %s", $1, $3);
        free($1); free($3);
    }
    | expression OR expression
    {
        $$ = malloc(strlen($1) + strlen($3) + 6);
        sprintf($$, "%s || %s", $1, $3);
        free($1); free($3);
    }
    | TRUE { $$ = strdup("true"); }
    | FALSE { $$ = strdup("false"); }

;

%%

int yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis en la línea %d: %s\n", yylineno, s);
    return 0;
}


int main() {
    int result = yyparse();
    if (result != 0) {
        fprintf(stderr, "Se encontraron errores durante el análisis.\n");
    }
    return result;
}
