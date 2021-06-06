/* C Declarations */

%{
	#include<stdio.h>
	#include<stdlib.h>
	#include <string.h>

	int yylex ();
	int yyerror();

	int switchdone = 0;
	int switchvar;

	int ifval[1000];
	int ifptr = -1;
	int ifdone[1000];

    int ptr = 0;
    int value[1000];
    char varlist[1000][1000];

    ///if already declared  return 1 else return 0
    int isdeclared(char str[]){
        int i;
        for(i = 0; i < ptr; i++){
            if(strcmp(varlist[i],str) == 0) return 1;
        }
        return 0;
    }
    /// if already declared return 0 or add new value and return 1;
    int addnewval(char str[],int val){
        if(isdeclared(str) == 1) return 0;
        strcpy(varlist[ptr],str);
        value[ptr] = val;
        ptr++;
        return 1;
    }

    ///get the value of corresponding string
    int getval(char str[]){
        int indx = -1;
        int i;
        for(i = 0; i < ptr; i++){
            if(strcmp(varlist[i],str) == 0) {
                indx = i;
                break;
            }
        }
		if(indx==-1)
		{
			return 0;
		}
        return value[indx];
    }
    int setval(char str[], int val){
    	int indx = -1;
        int i;
        for(i = 0; i < ptr; i++){
            if(strcmp(varlist[i],str) == 0) {
                indx = i;
                break;
            }
        }
		if(indx!=-1)
        value[indx] = val;

	

    }


%}

%union {
  char text[10000];
  int val;
}


%token <text>  ID
%token <val>  NUM
%token <text> STR

%type <val> expression
%type <text> LoopStatement
%type <text> Lprint
%type <val> ifexp


%left LT GT LE GE
%left PLUS MINUS
%left MULT DIV



%token SCAN LESS GREAT WHILE INT DOUBLE CHAR MAIN PB PE BB BE DOT CM ASGN PRINTVAR PRINTSTR PRINTLN PLUS MINUS MULT DIV LT GT LE GE IF ELSE ELSEIF FOR INC TO SWITCH DEFAULT COL FUNCTION
%nonassoc IFX
%nonassoc ELSE
%left SH


%%

starthere 	: function program function
		
			;

program		: INT MAIN PB PE BB statement BE { printf("\nCompilation Successful\n"); }
			;
statement	: /* empty */
			| statement declaration
			| statement print
			| statement expression 
			| statement ifelse
			| statement assign
			| statement forloop
			| statement switch
			| statement whileloop
			;




/*--------declaration begin--------*/


declaration : type variables DOT {}
			;
type		: INT | DOUBLE | CHAR {}
			;
variables	: variable CM variables {}
			| variable {}
			;
variable   	: ID 	
					{
						//printf("%s\n",$1);
						int x = addnewval($1,0);
						if(!x) {
							printf("Compilation Error:Variable %s is already declared\n",$1);
							exit(-1);
						}

					}
			| ID ASGN expression 	
					{
						//printf("%s %d\n",$1,$3);
						int x = addnewval($1,$3);
						if(!x) {
							printf("Compilation Error: Variable %s is already declared\n",$1);
							exit(-1);
							}
					}

			;

/*-------declaration end----------*/

/*------variable assign begin-----*/

assign : ID ASGN expression DOT  
					{
						if(!isdeclared($1)) {
							printf("Compilation Error: Variable %s is not declared\n",$1);
							exit(-1);
						}
						else{
							setval($1,$3);
						}
				    }
		| SCAN PB ID PE DOT
		{
			int tmp;
			tmp = 7;
			//printf("scan korte chai\n");
			scanf("%d", &tmp);
			//printf("%d - %s \n", tmp, $3);
			
			setval($3, tmp);
		}
		;

/*------variable assign end-------*/




/*--------printing begin----------*/

print		: PRINTVAR PB ID PE DOT 	
					{
						if(!isdeclared($3)){
							printf("Compilation Error: Variable %s is not declared\n",$3);
							exit(-1);
						}
						else{
							int v = getval($3);
							printf("%d",v);
						}
					}
			| PRINTSTR PB STR PE DOT
		 
					{
						int l = strlen($3);
						int i;
						for(i = 1;  i < l-1; i++) printf("%c",$3[i]);
					}
			| PRINTLN PB PE	DOT
		 	
					{
						printf("\n");
					}
			;



/*--------printing end------------*/




/*--------expression Begin--------*/

expression : NUM {$$ = $1;}
			| ID 	
					{
						if(!isdeclared($1)) {
							printf("Compilation Error: Variable %s is not declared\n",$1);
							exit(-1);
						}
						else{
							$$ = getval($1);
						}
				 	}
			| expression PLUS expression 
					{$$ = $1 + $3;}
			| expression MINUS expression 
					{$$ = $1 - $3;}
			| expression MULT expression 
					{$$ = $1 * $3;}
			| expression DIV expression 
					{
						if($3) {
 							$$ = $1 / $3;
							}
				  		else {
							$$ = 0;
							printf("\nRuntime Error: division by zero\t");
							exit(-1);
				  		} 
					}
			| expression LT expression	
					{ $$ = $1 < $3; }
			| expression GT expression	
					{ $$ = $1 > $3; }
			| expression LE expression	
					{ $$ = $1 <= $3; }
			| expression GE expression	
					{ $$ = $1 >= $3; }
			| PB expression PE
					{$$ = $2;}
			;


/*--------expression End--------*/


/*---------ifelse begin----------*/

ifelse 	: IF PB ifexp PE BB LoopStatement BE elseif
					{
						if($3)
						printf("%s", $6);
						ifdone[ifptr] = 0;
						ifptr--;
					}
		;
ifexp	: expression 
					{
						ifptr++;
						ifdone[ifptr] = 0;
						if($1){
							printf("\nIf executed\n");
							ifdone[ifptr] = 1;
						}
						$$ = $1;
					}
		;
elseif 	: /* empty */
		| elseif ELSEIF PB expression PE BB LoopStatement BE 
					{
						if($4 && ifdone[ifptr] == 0){
							printf("%s", $7);
							printf("\nElse if block expressin %d executed\n",$4);
							ifdone[ifptr] = 1;
						}
					}
		| elseif ELSE BB LoopStatement BE
					{
						if(ifdone[ifptr] == 0){
							printf("%s", $4);
							printf("\nElse block executed\n");
							ifdone[ifptr] = 1;
						}
					}

		;

/*---------ifelse end------------*/



/*--------while Begin-------------*/

whileloop : WHILE PB ID LESS NUM PE BB LoopStatement BE
		{
			int tmp = getval($3);
			while(tmp<$5)
			{
				printf("%d ", tmp);
				printf("%s",$8);
				
				
				tmp = tmp+1;
			}
			setval($3, tmp);

		}
		| WHILE PB ID GREAT NUM PE BB LoopStatement BE
		{
			int tmp = getval($3);
			while(tmp>$5)
			{
				printf("%d ", tmp);
				
				printf("%s",$8);
				
				tmp = tmp-1;
			}
			setval($3, tmp);

		}
		;

/*--------while end------------*/


/*------foor loop begin----------*/




forloop	: FOR PB expression TO expression INC expression PE BB LoopStatement BE 	
					{
						int st = $3;
						int ed = $5;
						int dif = $7;
						int cnt = 0;
						int k = 0;
						//printf(" hhel : \n%s\n", $10);
						for(k = st; k <= ed; k += dif){
							cnt++;
							int r ;
							if(strlen($10)!=0)
							printf("%s\n", $10);
						}	
						printf("Loop executes %d times\n",cnt+2);
					}
					;

LoopStatement: { strcpy($$,"");}
			| LoopStatement Lprint {
				 strcat($$, $2);
				}
			;

Lprint		: PRINTVAR PB ID PE DOT 	
					{
						char val[1000];
						strcpy(val, "");
						if(!isdeclared($3)){
							strcat(val, "Compilation Error: Variable ");

							char tmp[20];
							sprintf(tmp, "%s ", $3);
							strcat(val, tmp);
							strcat( val,"is not declared\n");
							printf("%s", val);
							exit(-1);
							strcpy($$, val);
						}
						else{
							char val[1000];
							strcpy(val, "");
							int v = getval($3);
							char tmp[18];
							sprintf(tmp, "%d", v);
							//strcpy(tmp,atoi(v));
							//printf(" v er value : %d - %s\n ", v, tmp);
							strcat(val, tmp);
							strcpy($$, val);

							//printf("%d",v);
						}
					}
			| PRINTSTR PB STR PE DOT
		 
					{
						char val[10000];
						strcpy(val, "");
						int l = strlen($3);
						int i;
						for(i = 1;  i < l-1; i++) 
						{
							char tmp[20];
							sprintf(tmp, "%c", $3[i]);
							//printf(" str er tmp:  %s\n",tmp);
							strcat(val, tmp);
							
							
							//printf("%c",$3[i]);
						}
						//strcat(val, "");
						
						//printf("  %s ", $$);
						
						strcpy($$, val);
						//printf("::: --- val: %s - %s\n",val, $$);
					}
			| PRINTLN PB PE	DOT
		 	
					{
						strcpy($$, "\n");
					}
			;




/*------foor loop end------------*/


/*------switch case begin--------*/

switch	: SWITCH PB expswitch PE BB switchinside BE 
		;

expswitch 	:  expression 
					{
						switchdone = 0;
						switchvar = $1;
					}
			;


switchinside	: /* empty */
				| switchinside expression COL BB statement BE 
					{
						if($2 == switchvar){
							printf("Executed %d\n",$2);
							switchdone = 1;
						}					
					}
				| switchinside DEFAULT COL BB statement BE 
					{
						if(switchdone == 0){
							switchdone = 1;
							printf("Default Block executed\n");
						}
					}
				;


/*------switch case end----------*/

/*------function begin-----------*/

function 	: /* empty */
			| function func
			;

func 	: type FUNCTION PB fparameter PE BB statement BE
					{
						printf("Function Declared\n");
					}
		;
fparameter 	: /* empty */
			| type ID fsparameter
			;
fsparameter : /* empty */
			| fsparameter CM type ID
			;


/*-------function end------------*/
%%


int yyerror(char *s){
	printf( "%s\n", s);
}