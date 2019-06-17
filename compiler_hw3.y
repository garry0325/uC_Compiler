/*	Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
extern int error;

FILE *file;


/* Symbol table function - you can add new function if needed. */
void yyerror(char*);
int lookup_symbol(char*, int);
void create_symbol(int);
void insert_symbol(char*, char*, char*, int, int, char*, char*);
void dump_symbol(int);

char name[64];
char entryType[16];
char dataType[16];
extern int scopeLevel;

void gencode_function();

int localVariableIndex;
int intFloatString;
char addingFunctionType[16];
char funcName[64];

struct symbolTableStruct {
    char name[64];
    char entryType[16];
    char dataType[16];
    int scopeLevel;
    char formalParameters[64];
};

struct indexAndTypeStruct {
	int index;
	char type;
};

struct symbolTableStruct symbolTable[30];
int currentIndex;
int formalPIndex;
char errorMessage[64];

char jFileContent[4096];

struct indexAndTypeStruct checkIndex(char *, int);
void arithmetic(char *, int, char*);

    
%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char* string;
    int b_val;
    int v_val;
}

/* Token without return */
%token PRINT
%token SEMICOLON
%token ADD SUB MUL DIV MOD INC DEC
%token MT LT MTE LTE EQ NE
%token ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT 
%token LB RB LCB RCB LSB RSB COMMA
%token IF ELSE FOR WHILE
%token C_COMMENT CPP_COMMENT	


/* Token with return, which need to sepcify type */
//%token <i_val> I_CONST
//%token <f_val> F_CONST
%token <string> I_CONST F_CONST // NEW
%token <string> S_CONST
%token <string> INT FLOAT BOOL STRING VOID TR FA RET
%token <string> ID ASGN


/* Nonterminal with return, which need to sepcify type */
%type <string> type constant primary_expression postfix_expression unary_expression cast_expression
%type <string> multiplicative_expression additive_expression declarator

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

primary_expression
    : ID {
    	$$ = $1;
    	if(lookup_symbol($1, -2) == 0) {
    		strcpy(errorMessage, "\0");
    		strcpy(errorMessage, "Undeclared variable ");
    		strcat(errorMessage, $1);
    		yyerror(errorMessage);
    		}
    		
    	// check if is function
    	struct indexAndTypeStruct temp;
    	temp = checkIndex($1, -2);
    	if(temp.index != -3) {	// is a function name
    		strcpy(funcName, $1);
    		}
    	}
    | constant {
    	
    }
    //| LB expression RB
;

constant
    : I_CONST { $$ = $1; intFloatString = 0; }
    | F_CONST { $$ = $1; intFloatString = 1; }
	| S_CONST { $$ = $1; intFloatString = 2; }
	| TR
	| FA
;


postfix_expression
    : primary_expression { $$ = $1; }
    | postfix_expression LSB expression RSB
    | postfix_expression LB RB
    //| postfix_expression LB argument_expression_list RB
    | postfix_expression INC
    | postfix_expression DEC
;
/*
argument_expression_list
    : assignment_expression
    | argument_expression_list COMMA assignment_expression
;*/

unary_expression
    : postfix_expression { $$ = $1; }
    | INC unary_expression { $$ = $2; }
    | DEC unary_expression { $$ = $2; }
    | unary_operator cast_expression { $$ = $2; }
;

unary_operator
    : '&'
    | MUL
    | ADD
    | SUB
    | '~'
    | '!'
;

cast_expression
    : unary_expression { $$ = $1; }
;

multiplicative_expression
    : cast_expression { $$ = $1; }
    | multiplicative_expression MUL cast_expression {
    	arithmetic($1, 2, $3);
    	}
    | multiplicative_expression DIV cast_expression {
    	arithmetic($1, 3, $3);
    	}
    | multiplicative_expression MOD cast_expression {
    	arithmetic($1, 4, $3);
    	}
;

additive_expression
    : multiplicative_expression { $$ = $1; }
    | additive_expression ADD multiplicative_expression {
    		arithmetic($1, 0, $3);
    	}
    | additive_expression SUB multiplicative_expression {
    		arithmetic($1, 1, $3);
    	}
;

shift_expression
    : additive_expression
;

relational_expression
    : shift_expression
    | relational_expression LT shift_expression
    | relational_expression MT shift_expression
    | relational_expression LTE shift_expression
    | relational_expression MTE shift_expression
;

equality_expression
    : relational_expression
    | equality_expression EQ relational_expression
    | equality_expression NE relational_expression
;

and_expression
    : equality_expression
    | and_expression '&' equality_expression
;

exclusive_or_expression
    : and_expression
    | exclusive_or_expression '^' and_expression
;

inclusive_or_expression
    : exclusive_or_expression
    | inclusive_or_expression '|' exclusive_or_expression
;

logical_and_expression
    : inclusive_or_expression
    | logical_and_expression AND inclusive_or_expression
;

logical_or_expression
    : logical_and_expression
    | logical_or_expression OR logical_and_expression
;

conditional_expression
    : logical_or_expression
    | logical_or_expression '?' expression ':' conditional_expression
;

assignment_expression
    : conditional_expression
    
    | ID assignment_operator assignment_expression {	// lhs of the '='
    	// first check 
    	// check if the variable is in the table
    	struct indexAndTypeStruct temp;
    	temp = checkIndex($1, scopeLevel);
    	if(temp.index == -1) {
    		fprintf(file, "\tputstatic compiler_hw3/%s %c\n", $1, temp.type);
    		}
    	else {
    		switch(temp.type) {
    				case 'I': fprintf(file, "\tistore %d\n", temp.index); break;
    				case 'F': fprintf(file, "\tfstore %d\n", temp.index); break;
    				default: break;
    				}
    		}
    }
    //| unary_expression assignment_operator assignment_expression
;

assignment_operator
    : ASGN
    | MULASGN
    | DIVASGN
    | MODASGN
    | ADDASGN
    | SUBASGN
;

expression
    : assignment_expression
    | expression COMMA assignment_expression
;

declaration
    : declaration_specifiers ID SEMICOLON {  // meet regular declaration
    	insert_symbol($2, "variable", dataType, scopeLevel, 0, NULL, NULL);
    	strcpy(name, "\0");
    	strcpy(dataType, "\0");
    	
    	//
    	}
    	
	| declaration_specifiers ID ASGN constant SEMICOLON {  // meet regular declaration // 'constant' was changed from 'assignment_expression'
    	insert_symbol($2, "variable", dataType, scopeLevel, 0, NULL, $4);
    	strcpy(name, "\0");
    	strcpy(dataType, "\0");
		}
	;

declaration_specifiers
    : type declaration_specifiers
    | type
;

type
	: INT		{ strcpy(dataType, $1); }
	| FLOAT		{ strcpy(dataType, $1); }
	| STRING	{ strcpy(dataType, $1); }
	| BOOL		{ strcpy(dataType, $1); }
	| VOID		{ strcpy(dataType, $1); }
;


declarator
    : ID {
    	$$ = $1;
    	insert_symbol($1, "function", dataType, -3, 0, NULL, NULL);
    	strcpy(dataType, "\0");
    	formalPIndex = currentIndex;
    }
    | LB declarator RB { $$ = $2; }
    | declarator LB parameter_list RB {
    	char type = 'I';
    	if(strcmp(addingFunctionType, "float") == 0)
    		type = 'F';
    	else if(strcmp(addingFunctionType, "void") == 0)
    		type = 'V';
    	fprintf(file, ")%c\n", type);
    	fprintf(file, ".limit stack 50\n"
    					".limit locals 50\n");
    	}
    | declarator LB RB {
    	char type = 'I';
    	if(strcmp($1, "main") != 0) {
			if(strcmp(addingFunctionType, "float") == 0)
				type = 'F';
			fprintf(file, "V)%c\n", type);
			fprintf(file, ".limit stack 50\n"
    						".limit locals 50\n");
    		}
    	}
;

parameter_list
    : parameter_declaration
    | parameter_list COMMA parameter_declaration
;

parameter_declaration
    : declaration_specifiers ID {
    	insert_symbol($2, "parameter", dataType, 1, 0, NULL, NULL);
    	insert_symbol(NULL, NULL, NULL, -1, 1, dataType, NULL);
    	strcpy(name, "\0");
    	strcpy(dataType, "\0");
    	}
    | declaration_specifiers
;

statement
    : compound_statement
    | expression_statement
    | selection_statement
    | iteration_statement
    | jump_statement
	| print_statement
	| function_statement_semicolon
;

compound_statement
    : LCB RCB
    | LCB block_item_list RCB {
	dump_symbol(scopeLevel+1);
	}
;

block_item_list
    : block_item
    | block_item_list block_item
;

block_item
    : declaration
    | statement
;

expression_statement
    : SEMICOLON
    | expression SEMICOLON
;

selection_statement
    : IF LB expression RB statement ELSE statement
    | IF LB expression RB statement
;

iteration_statement
    : WHILE LB expression RB statement
    | FOR LB expression_statement expression_statement RB statement
    | FOR LB expression_statement expression_statement expression RB statement
    | FOR LB declaration expression_statement RB statement
    | FOR LB declaration expression_statement expression RB statement
;

jump_statement
    : RET SEMICOLON {
    /*
    	if(strcmp(addingFunctionType, "int") == 0)
	    	fprintf(file, "\tireturn\n");
	    else if(strcmp(addingFunctionType, "float") == 0)
			fprintf(file, "\tfreturn\n");
		else if(strcmp(addingFunctionType, "void") == 0)
			fprintf(file, "\treturn\n");
		else if(strcmp(addingFunctionType, "bool") == 0)
			fprintf(file, "\tireturn\n");
		else fprintf(file, "\treturn\n");*/
		
		fprintf(file, "\treturn\n");
		fprintf(file, ".end method\n");
    	}
    | RET ID SEMICOLON {	// RET expression SEMICOLON
    	struct indexAndTypeStruct temp;
    	temp = checkIndex($2, scopeLevel);
    	
    	if(temp.index == -1) { // return a global variable
    		fprintf(file, "\tgetstatic compiler_hw3/%s\n", $2);
    		}
    	else {
    		if(strcmp(addingFunctionType, "int") == 0)
    			fprintf(file, "\tiload %d\n", temp.index);
    		else if(strcmp(addingFunctionType, "float") == 0)
    			fprintf(file, "\tfload %d\n", temp.index);
    		else if(strcmp(addingFunctionType, "bool") == 0)
    			fprintf(file, "\tiload %d\n", temp.index);
    		}
    	if(strcmp(addingFunctionType, "int") == 0)
    		fprintf(file, "\tireturn\n");
    	else if(strcmp(addingFunctionType, "float") == 0)
    		fprintf(file, "\tfreturn\n");
    	else if(strcmp(addingFunctionType, "bool") == 0)
    		fprintf(file, "\tireturn\n");
    		
    	fprintf(file, ".end method\n");
    	}
    | RET constant SEMICOLON {
    	fprintf(file, "\tldc %s\n", $2);
    	if(intFloatString == 0)
    		fprintf(file, "\tireturn\n");
    	else if(intFloatString == 1)
    		fprintf(file, "\tfreturn\n");
    	else if(intFloatString == 2)
    		fprintf(file, "\tireturn\n");
    		
    	fprintf(file, ".end method\n");
    	
    	intFloatString = -1;
    	}
;

print_statement
	: PRINT LB ID RB SEMICOLON {
		struct indexAndTypeStruct temp;
    	temp = checkIndex($3, scopeLevel);
    	if(temp.index == -1) {
    		fprintf(file, "\tgetstatic compiler_hw3/%s %c\n", $3, temp.type);
    		}
    	else {
    		switch(temp.type) {
    				case 'I': fprintf(file, "\tiload %d\n", temp.index); break;
    				case 'F': fprintf(file, "\tfload %d\n", temp.index); break;
    				default: break;
    				}
    		}
    	fprintf(file, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
    					"\tswap\n"
    					"\tinvokevirtual java/io/PrintStream/println(%c)V\n", temp.type);				
	}
	| PRINT LB constant RB SEMICOLON {
		if(intFloatString == 2)
			fprintf(file, "\tldc \"%s\"\n", $3);
		else
			fprintf(file, "\tldc %s\n", $3);
		
		char append[100];
		if(intFloatString == 2)
			strcpy(append, "Ljava/lang/String;");
		else if(intFloatString == 1)
			strcpy(append, "F");
		else if(intFloatString == 0)
			strcpy(append, "I");
		fprintf(file, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n"
    					"\tswap\n"
    					"\tinvokevirtual java/io/PrintStream/println(%s)V\n",append);
    					
    	intFloatString = -1;
	}
;

function_statement_semicolon
	: function_statement SEMICOLON
	| ID assignment_operator function_statement SEMICOLON {
		struct indexAndTypeStruct temp;
		temp = checkIndex($1, scopeLevel);
		if(temp.index == -2) {	// global
			fprintf(file, "\tputstatic compiler_hw3/%s %c\n", $1, temp.type);
		}
		else {
			if(temp.type == 'I')
				fprintf(file, "\tistore %d\n", temp.index);
			else if(temp.type == 'F')
				fprintf(file, "\tfstore %d\n", temp.index);
			}
		}
;

function_statement
	: ID LB ID RB {	// ID LB expression RB
		if(lookup_symbol($1, -3) == 0) {
			strcpy(errorMessage, "\0");
			strcpy(errorMessage, "Undeclared function ");
			strcat(errorMessage, $1);
			yyerror(errorMessage);
			}
		else {
			struct indexAndTypeStruct temp;
			temp = checkIndex($3, scopeLevel);
			if(temp.index == -1)
				fprintf(file, "\tgetstatic compiler_hw3/%s %c\n", $3, temp.type);
			else {
				if(temp.type == 'I')
					fprintf(file, "\tiload %d\n", temp.index);
				else if(temp.type == 'F')
					fprintf(file, "\tfload %d\n", temp.index);
				}
				
			char t = temp.type;
			temp = checkIndex($1, -2);
			fprintf(file, "\tinvokestatic compiler_hw3/%s(%c)%c\n", $1, t, temp.type);
			}
		}
	| ID LB constant RB {	// ID LB expression RB
		if(lookup_symbol($1, -3) == 0) {
			strcpy(errorMessage, "\0");
			strcpy(errorMessage, "Undeclared function ");
			strcat(errorMessage, $1);
			yyerror(errorMessage);
			}
		else {
			fprintf(file, "\tldc %s\n", $3);
			char t;
			switch(intFloatString) {
				case 0: t = 'I'; break;
				case 1: t = 'F'; break;
				case 2: t = 'I'; break;
				default: break;
				}
				
			struct indexAndTypeStruct temp;
			temp = checkIndex($1, -2);
			fprintf(file, "\tinvokestatic compiler_hw3/%s(%c)%c\n", $1, t, temp.type);
			
			intFloatString = -1;
			}
		}
	| ID LB RB {
		if(lookup_symbol($1, -3) == 0) {
			strcpy(errorMessage, "\0");
			strcpy(errorMessage, "Undeclared function ");
			strcat(errorMessage, $1);
			yyerror(errorMessage);
			}
		else {
			struct indexAndTypeStruct temp;
			temp = checkIndex($1, -2);
			fprintf(file, "\tinvokevirtual compiler_hw3/%s(V)%c\n", $1, temp.type);
			}
		}
;

program
    : external_declaration
    | program external_declaration
;

external_declaration
    : function_definition {  }
    | declaration
;

function_definition
    : declaration_specifiers declarator compound_statement {
    	localVariableIndex = 0;
    	}
;


%%

/* C code section */
int main(int argc, char** argv)
{   
	error = 0;
	yylineno = 1;
	printf("%d: ", yylineno);
	
	scopeLevel = 0;
	
	currentIndex = -1;
	formalPIndex = -1;
    create_symbol(0);
    
    // new to hw3
    file = fopen("compiler_hw3.j", "w");
    
    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");
                    //".method public static main([Ljava/lang/String;)V\n");
	
	// new to hw3
	localVariableIndex = 0;
	intFloatString = -1;

	int result;
	result = yyparse();
	if(!result) {
		dump_symbol(0);
		printf("\n\nTotal lines: %d \n", yylineno);
		}
		
	fclose(file);
	
    return 0;
}

void yyerror(char *s)
{
    printf("\n\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n| Unmatched token: %s", yytext);
    printf("\n|-----------------------------------------------|\n");
    error = 1;
    exit(-1);
}

void create_symbol(int head) {
	for(int i=head; i<30; i++) {
		strcpy(symbolTable[i].name, "\0");
		strcpy(symbolTable[i].entryType, "\0");
		strcpy(symbolTable[i].dataType, "\0");
		symbolTable[i].scopeLevel = -1;
		strcpy(symbolTable[i].formalParameters, "\0");
		}
}

void insert_symbol(char *insertName, char *insertEntryType, char *insertDataType, int insertScopeLevel, int addFunctionParameter, char *parameter, char *value) {
	if(addFunctionParameter) {
		if(strlen(symbolTable[formalPIndex].formalParameters) == 0) {
			strcpy(symbolTable[formalPIndex].formalParameters, parameter);
			}
		else {
			strcat(symbolTable[formalPIndex].formalParameters, ", ");
			strcat(symbolTable[formalPIndex].formalParameters, parameter);
			}
		}
	else {
		int result = lookup_symbol(insertName, insertScopeLevel);
		if(result == 0) {
			currentIndex = currentIndex + 1;
			strcpy(symbolTable[currentIndex].name, insertName);
			strcpy(symbolTable[currentIndex].entryType, insertEntryType);
			strcpy(symbolTable[currentIndex].dataType, insertDataType);
			if(insertScopeLevel == -3) insertScopeLevel = 0;
			symbolTable[currentIndex].scopeLevel = insertScopeLevel;
			
			// add global variable to .j
			char typeDescriptor;
			if(strcmp(insertDataType, "int") == 0) typeDescriptor = 'I';
			else if(strcmp(insertDataType, "float") == 0) typeDescriptor = 'F';
			else if(strcmp(insertDataType, "bool") == 0) typeDescriptor = 'B';
			else if(strcmp(insertDataType, "void") == 0) typeDescriptor = 'V';

			if(strcmp(insertEntryType, "variable") == 0 && insertScopeLevel == 0) {	// assemble global variable
				if(value == NULL)
					fprintf(file, ".field public static %s %c\n", insertName, typeDescriptor);
				else
					fprintf(file, ".field public static %s %c = %s\n", insertName, typeDescriptor, value);
				}
			else if(strcmp(insertEntryType, "function") == 0 && strcmp(insertName, "main") == 0) {	// assemble main
				fprintf(file, ".method public static main([Ljava/lang/String;)%c\n", typeDescriptor);
				fprintf(file, ".limit stack 50\n.limit locals 50\n");
				
				}
			else if(strcmp(insertEntryType, "variable") == 0 && insertScopeLevel !=0) {	//assemble local variable
				if(value == NULL)
					fprintf(file, "\tldc 0\n");
				else
					fprintf(file, "\tldc %s\n", value);
					
				if(strcmp(insertDataType, "string") == 0)
					fprintf(file, "\tastore %d\n", localVariableIndex);
				else if(strcmp(insertDataType, "int") == 0)
					fprintf(file, "\tistore %d\n", localVariableIndex);
				else if(strcmp(insertDataType, "float") == 0)
					fprintf(file, "\tfstore %d\n", localVariableIndex);
				else if(strcmp(insertDataType, "bool") == 0)
					fprintf(file, "\tistore %d\n", localVariableIndex);
			
				localVariableIndex++;
				}
			else if(strcmp(insertEntryType, "function") == 0) {
				fprintf(file, ".method public static %s(", insertName);
				strcpy(addingFunctionType, insertDataType);
				}
			if(strcmp(insertEntryType, "parameter") == 0) {
				char type;
				if(strcmp(insertDataType, "string") == 0) {
					type = 'I';
					}
				else if(strcmp(insertDataType, "int") == 0) {
					type = 'I';
					}
				else if(strcmp(insertDataType, "float") == 0) {
					type = 'F';
					}
				else if(strcmp(insertDataType, "bool") == 0) {
					type = 'I';
					}
					
				fprintf(file, "%c", type);
				
				localVariableIndex++;
				}				
			}
		else if(result == 1) {
			strcpy(errorMessage, "\0");
			strcat(errorMessage, "Redeclared variable ");
			strcat(errorMessage, insertName);
			yyerror(errorMessage);
			}
		else if(result == 2) {
			strcpy(errorMessage, "\0");
			strcat(errorMessage, "Redeclared function ");
			strcat(errorMessage, insertName);
			yyerror(errorMessage);
			}
		else if(result == 3) {
			strcpy(errorMessage, "\0");
			strcat(errorMessage, "Variable declared with name ");
			strcat(errorMessage, insertName);
			yyerror(errorMessage);
			}
		else if(result == 4) {
			strcpy(errorMessage, "\0");
			strcat(errorMessage, "Function declared with name ");
			strcat(errorMessage, insertName);
			yyerror(errorMessage);
			}
		}
}

int lookup_symbol(char *lookupName, int lookupScopeLevel) {
	int same = 0;
	if(lookupScopeLevel == -3) {	// function name looks for same function or variable names
		for(int i=0; i<30; i++) {
			if(strcmp(symbolTable[i].name, lookupName) == 0) {
				if(strcmp(symbolTable[i].entryType, "function") == 0)
					same = 2;	// function name meets same function name
				else if(strcmp(symbolTable[i].entryType, "variable") == 0)
					same = 3;	// function name meets same variable name
				break;
				}
			}
		}
	else {	
		for(int i=0; i<30; i++) {
			if(strcmp(symbolTable[i].name, lookupName) == 0 && strcmp(symbolTable[i].entryType, "function") == 0 && lookupScopeLevel == 0) {
				same = 4;	// global variable declared with existing function name
				break;
				}
			if(strcmp(symbolTable[i].name, lookupName) == 0 && (symbolTable[i].scopeLevel == lookupScopeLevel || lookupScopeLevel == -2)) {
				same = 1;	// for redeclared variable name
				break;
				}
			}
		}
	return same;
}

void dump_symbol(int scope) {
	int startFrom=-1;
	for(int i=0; i<=currentIndex; i++) {
		if(symbolTable[i].scopeLevel == scope) {
			startFrom = i;
			break;
			}
		}
	if(startFrom == -1) return;

    printf("\n\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");

	for(int i=startFrom; symbolTable[i].scopeLevel == scope; i++) {
		printf("%-10d%-10s%-12s%-10s%-10d%-10s\n", i - startFrom, symbolTable[i].name, symbolTable[i].entryType, symbolTable[i].dataType, symbolTable[i].scopeLevel, symbolTable[i].formalParameters);
		currentIndex = currentIndex - 1;
		
		}
	create_symbol(startFrom);
}

void arithmetic(char *num1, int ari, char *num2) {
    	int intOrFloat = 0;	// 0 int 1 float
    	struct indexAndTypeStruct temp;
    	temp = checkIndex(num1, scopeLevel);
    	if(temp.index == -2) {	// is a number
    		if(strstr(num1, ".") != NULL) {	// is a float
    			fprintf(file, "\tldc %s\n", num1);
    			intOrFloat = 1;
    			}
    		else	//is an int
    			fprintf(file, "\tldc %s\n", num1);
    		}
    	else if(temp.index == -1){	// is a global variable
    		fprintf(file, "\tgetstatic compiler_hw3/%s %c\n", num1, temp.type);
    		if(temp.index == 'F')
    			intOrFloat = 1;
    		}
    	else {	// is a local variable
    		if(temp.type == 'I')
    			fprintf(file, "\tiload %d\n", temp.index);
    		else if(temp.type == 'F') {
    			fprintf(file, "\tfload %d\n", temp.index);
    			intOrFloat = 1;
    			}
    		}
    	
    	temp = checkIndex(num2, scopeLevel);
    	if(temp.index == -2) {	// is a number
    		if(strstr(num2, ".") != NULL)	// is a float
    			fprintf(file, "\tldc %s\n", num2);
    		else{	//is an int
    			fprintf(file, "\tldc %s\n", num2);
    			}
    		}
    	else if(temp.index == -1)	// is a global variable
    		fprintf(file, "\tgetstatic compiler_hw3/%s %c\n", num2, temp.type);
    	else {	// is a local variable
    		if(temp.type == 'I')
    			fprintf(file, "\tiload %d\n", temp.index);
    		else if(temp.type == 'F')
    			fprintf(file, "\tfload %d\n", temp.index);
    		}
    		
    	char operand[20];
    	if(intOrFloat == 0)
    		strcpy(operand, "i");
		else
			strcpy(operand, "f");
			
		switch(ari) {
			case 0: strcat(operand, "add"); break;
			case 1: strcat(operand, "sub"); break;
			case 2: strcat(operand, "mul"); break;
			case 3: strcat(operand, "div"); break;
			case 4: strcat(operand, "mod"); break;
			default: break;
			}
		fprintf(file, "\t%s\n", operand);
		return;
}

struct indexAndTypeStruct checkIndex(char *name, int scope) {
	struct indexAndTypeStruct ret;
	int index = -1;
	int matchedName = 0;
	char type = 'n';
	for(int i=0; i<=currentIndex; i++) {
		if((symbolTable[i].scopeLevel == scope && (strcmp(symbolTable[i].entryType, "variable") == 0 || strcmp(symbolTable[i].entryType, "parameter") == 0)) || (strcmp(symbolTable[i].entryType, "function") == 0 && scope == -2)) {
			index = index + 1;
			if(strcmp(symbolTable[i].name, name) == 0) {
				matchedName = 1;
				if(strcmp(symbolTable[i].dataType, "int") == 0)
					type = 'I';
				else if(strcmp(symbolTable[i].dataType, "float") == 0)
					type = 'F';
				else if(strcmp(symbolTable[i].dataType, "string") == 0)
					type = 'I';
				else if(strcmp(symbolTable[i].dataType, "bool") == 0)
					type = 'I';
				else if(strcmp(symbolTable[i].dataType, "void") == 0)
					type = 'V';
				break;
				}
			}
		}
	if(matchedName == 0 && scope != 0) {
		ret = checkIndex(name, 0);
		}
	else {
		if(scope == 0 && matchedName == 1)
			ret.index = -1;
		else if(scope == 0 && matchedName == 0)
			ret.index = -2;
		else if(scope == -2 && matchedName == 0)
			ret.index = -3;
		else
			ret.index = index;
		ret.type = type;
		}
	return ret;
}
