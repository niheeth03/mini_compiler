%{
    #include <stdio.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    int yylex();
    int yyerror(char *);
    extern FILE *yyin;
    char str[100];
    char type[100];
    int size;
    bool stat=false;
    static int labelv=1;
    static int tempv=1;
    struct Stack {
	 int data;
	 struct Stack* next;
    };
    struct s{
	int True;
	int False;
	int next;
	int lexval;
	int val;
	char code[10000];
	struct s* left;
	struct s* right;
	char op[20];
    };
    struct Stack* newNode(int data)
    {
	 struct Stack* Stack = (struct Stack*)
	 malloc(sizeof(struct Stack));
	 Stack->data = data;
	 Stack->next = NULL;
	 return Stack;
    }
  
   int empty(struct Stack* root)
	{
	    return !root;
	}
    
     int top(struct Stack* root)
     {
		    if (empty(root))
			return -1;
		    return root->data;
     }
   void pop(struct Stack** root)
   {
	  if (empty(*root))
		return -1;
	  struct Stack* temp = *root;
	  *root = (*root)->next;
	  int popped = temp->data;
	  free(temp);
	  
	  
   }
  
    void push(struct Stack** root, int data)
    {
	  struct Stack* Stack = newNode(data);
	  Stack->next = *root;
	  *root = Stack;
	  
    }
  

    struct TypeNode{
        char type[20];
        int size;
    };
    struct new_Entry{
        char lexeme [20];
        char type [50];
        int addr;
        
        struct new_Entry* next;
    };
    struct new_Entry* global  = NULL;
    struct new_Entry* head = NULL;
    struct Stack* st = NULL;
    
    struct SymbolTable{
        struct new_Entry* head;
        struct new_Entry* tail;
        struct SymbolTable* prev;
    };
    
    struct SymbolTable* SymbolTemp=NULL;
    struct SymbolTable* SymbolHead=NULL;
   
    int verify(struct SymbolTable* symbol,char lexeme[], char type[]); 
    char* typeofvar(struct SymbolTable* symbol,char lexeme [ ]);
    void add_name(struct SymbolTable* symbol,int addr , char lexeme [ ], char type[]);
    void Construct(struct SymbolTable* symbol,struct SymbolTable* prev);
    char* itoa(int num);
    char* maximized(char* str);
    int minimized(char* str);
    int prec(char* type);
    void Symbol_Table();
    char* mini(char* str,int i);
    char* traversal(struct s* node);
%}

%union{
    char addr[100];
    struct TypeNode* TypeNode;
    struct SymbolTable* SymbolTable;
    struct s* eval;
};

%token <addr>FloatNUM DoubleNUM NUM ID INT LONG FLOAT DOUBLE STRING CHAR LBracket RBracket INC DEC COMP IF ELSE While or and
%type <TypeNode> TYPE 
%type <eval> Start List Comp Stmt Arth Term Fact Expr Block Cond 

%%


Start : LBracket {push(&st,0);SymbolHead=(struct SymbolTable*)malloc(sizeof(struct SymbolTable));Construct(SymbolHead,SymbolTemp);SymbolTemp=SymbolHead;} List RBracket {pop(&st);if(stat==false){printf(" Given program is Accepted\n"); Symbol_Table();}$$ = (struct s*)malloc(sizeof(struct s));
                               strcpy($$->code, $3->code);
                               if(stat==false){
                                printf("\n-------------TAC of the given code ------------\n%s", $3->code);
                                printf("--------------------**------------------------\n");};
                               }


List :   Comp List{
	                        $$ = (struct s*)malloc(sizeof(struct s));
                                strcat($1->code, $2->code);
                                strcpy($$->code, $1->code);

        }
        | Comp{
	                        $$ = (struct s*)malloc(sizeof(struct s));
                                strcpy($$->code, $1->code);

        }
        | IF '(' Cond ')' LBracket List RBracket {
        					
          					$$ = (struct s*)malloc(sizeof(struct s));
          					$3->True=labelv;
          					labelv++;
          					$3->False=labelv;
          					labelv++;
          				        //printf("%s",$3->left->code);
          				        //printf($3->right->code);
          					$$->next=$3->False;
          					$6->next=$3->False;
          					//char co[20];
          				        //strcpy(co,"1");
          					//printf("%s",co);
          					strcpy($$->code,"if ");
						strcat($$->code,$3->code);
						strcat($$->code," goto label");
						strcat($$->code,itoa($3->True));
						strcat($$->code,"\n");
						strcat($$->code,"goto label");
						strcat($$->code,itoa($3->False));
						strcat($$->code,"\n");
          					strcat($$->code,"label");
          					strcat($$->code,itoa($3->True));
          					strcat($$->code,":\n");
          					strcat($$->code,$6->code);
          					strcat($$->code,"label");
          					strcat($$->code,itoa($3->False));
          					strcat($$->code,":\n");
                                          }
          | IF '(' Cond ')' LBracket List RBracket ELSE LBracket List RBracket {
          							        $$ = (struct s*)malloc(sizeof(struct s));
				  					$3->True=labelv;
				  					labelv++;
				  					$3->False=labelv;
				  					labelv++;
				  					$$->next=$3->False;
          								$6->next=$3->False;
          								$10->next=$3->False;
				  					strcpy($$->code,"if ");
									strcat($$->code,$3->code);
									strcat($$->code," goto label");
									strcat($$->code,itoa($3->True));
									strcat($$->code,"\n");
									strcat($$->code,"goto label");
									strcat($$->code,itoa($3->False));
									strcat($$->code,"\n");
				  					strcat($$->code,"label");
				  					strcat($$->code,itoa($3->True));
				  					strcat($$->code,":\n");
				  					strcat($$->code,$6->code);
				  					strcat($$->code,"label");
				  					strcat($$->code,itoa($3->False));
				  					strcat($$->code,":\n");
				  					strcat($$->code,$10->code);
				  					strcat($$->code,"label");
				  					strcat($$->code,itoa(labelv));
				  					strcat($$->code,":\n");
				  					labelv++;	
          							}
          							
         | While '(' Cond ')' LBracket List RBracket {
         					$$ = (struct s*)malloc(sizeof(struct s));
         					$3->True=labelv;
         					labelv++;
         					$3->False=labelv;
         					labelv++;
         					$$->next=$3->False;
          					$6->next=$3->True;
          					strcpy($$->code,"label");
				  		strcat($$->code,itoa($3->True));
				  		strcat($$->code,":\n");
         					strcat($$->code,"ifFalse ");
				  		strcat($$->code,$3->code);
				  		strcat($$->code," goto label");
				  		strcat($$->code,itoa($3->False));
				  		strcat($$->code,"\n");
				  		strcat($$->code,$6->code);
				  		strcat($$->code,"goto label");
				  		strcat($$->code,itoa($3->True));
				  		strcat($$->code,"\n");
				  		strcat($$->code,"label");
				  		strcat($$->code,itoa($3->False));
				  		strcat($$->code,":\n");
         				      }
	  
	
        ;

Comp:   Block {             $$ = (struct s*)malloc(sizeof(struct s));   
                                strcpy($$->code, $1->code);
              }
	| TYPE Expr ';'{   $$ = (struct s*)malloc(sizeof(struct s));   
                                strcpy($$->code, $2->code);
	}
	|Stmt ';'{   $$ = (struct s*)malloc(sizeof(struct s));   
                                strcpy($$->code, $1->code);}
	;

Stmt : ID  {
	    if(strcmp(typeofvar(SymbolTemp,$1),"none")==0){
           		 stat=true;
           		 printf("error:not declared %s\n",$1);
            }
            else{
               strcpy(type,typeofvar(SymbolTemp,$1));
               //printf("%s\n",type);
            }
        }'=' Arth {
	                  
	                  $$ = (struct s*)malloc(sizeof(struct s));
	                  strcpy($$->code,$4->code);
	                  
	                  strcat($$->code,$1);
	                  strcat($$->code, " = ");
	                  strcat($$->code, "t");
                          strcat($$->code, itoa($4->lexval));
			   strcat($$->code, "\n");
		           $$->lexval = $4->lexval;
		           //printf("%s",$$->code);
		           
		                  
	}
	| ID INC{ if(strcmp(typeofvar(SymbolTemp,$1),type)!=0){
           		 stat=true;
           		if( strcmp(typeofvar(SymbolTemp,$1),"none")==0){
           		    printf("error:not declared %s\n",$1);
           		}
           		else{
           		   printf("error:conflicting types in the above expression \n");
           		}
           		
            }
             $$ = (struct s*)malloc(sizeof(struct s));
             strcpy($$->code, "t");
             strcat($$->code, itoa(tempv)); 
             strcat($$->code, " = ");
             strcat($$->code, $2);
             strcat($$->code, " + 1\n");
             strcat($$->code, $2);
             strcat($$->code, " = t");
             strcat($$->code, itoa(tempv));
             strcat($$->code, "\n");
             $$->lexval = tempv;
             tempv++;
         }
         | ID DEC{ if(strcmp(typeofvar(SymbolTemp,$1),type)!=0){
           		 stat=true;
           		if( strcmp(typeofvar(SymbolTemp,$1),"none")==0){
           		    printf("error:not declared %s\n",$1);
           		}
           		else{
           		   printf("error:conflicting types in the above expression \n");
           		}
           		
            }
            $$ = (struct s*)malloc(sizeof(struct s));
             strcpy($$->code, "t");
             strcat($$->code, itoa(tempv)); 
             strcat($$->code, " = ");
             strcat($$->code, $2);
             strcat($$->code, " - 1\n");
             strcat($$->code, $2);
             strcat($$->code, " = t");
             strcat($$->code, itoa(tempv));
             strcat($$->code, "\n");
             $$->lexval = tempv;
             tempv++;
         };

     ;

Arth   : Arth '+' Term {            $$ = (struct s*)malloc(sizeof(struct s));
                                    strcpy($$->code, $1->code);
                                    strcat($$->code, $3->code);
                                    strcat($$->code, "t");
                                    strcat($$->code, itoa(tempv));
                                    strcat($$->code, " = ");
                                    strcat($$->code, "t");
                                    strcat($$->code, itoa($1->lexval));
                                    strcat($$->code, " + ");
                                    strcat($$->code, "t");
                                    strcat($$->code, itoa($3->lexval));
                                    strcat($$->code, "\n");
                                    $$->lexval = tempv;
                                    tempv++;
                       }
	| Arth '-' Term{            $$ = (struct s*)malloc(sizeof(struct s));
                                    strcpy($$->code, $1->code);
                                    strcat($$->code, $3->code);
                                    strcat($$->code, "t");
                                    strcat($$->code, itoa(tempv));
                                    strcat($$->code, " = ");
                                    strcat($$->code, "t");
                                    strcat($$->code, itoa($1->lexval));
                                    strcat($$->code, " - ");
                                    strcat($$->code, "t");
                                    strcat($$->code, itoa($3->lexval));
                                    strcat($$->code, "\n");
                                    $$->lexval = tempv;
                                    tempv++;
			}
	| Term         { 
			 
			$$ = (struct s*)malloc(sizeof(struct s));
                         strcpy($$->code, $1->code);
                         $$->lexval = $1->lexval;
                         //printf("%s",$$->code);
	};
Term   :  Term'*' Fact {
		                    $$ = (struct s*)malloc(sizeof(struct s));
                                    strcpy($$->code, $1->code);
                                    strcat($$->code, $3->code);
                                    strcat($$->code, "t");
                                    strcat($$->code, itoa(tempv));
                                    strcat($$->code, " = ");
                                    strcat($$->code, "t");
                                    strcat($$->code, itoa($1->lexval));
                                    strcat($$->code, " * ");
                                    strcat($$->code, "t");
                                    strcat($$->code, itoa($3->lexval));
                                    strcat($$->code, "\n");
                                    $$->lexval = tempv;
                                    tempv++;
	}
	| Term '/' Fact{
				     $$ = (struct s*)malloc(sizeof(struct s));
                                    strcpy($$->code, $1->code);
                                    strcat($$->code, $3->code);
                                    strcat($$->code, "t");
                                    strcat($$->code, itoa(tempv));
                                    strcat($$->code, " = ");
                                    strcat($$->code, "t");
                                    strcat($$->code, itoa($1->lexval));
                                    strcat($$->code, " / ");
                                    strcat($$->code, "t");
                                    strcat($$->code, itoa($3->lexval));
                                    strcat($$->code, "\n");
                                    $$->lexval = tempv;
                                    tempv++;
                      }
	| Fact {
	                 
			  $$ = (struct s*)malloc(sizeof(struct s));
                         strcpy($$->code, $1->code);
                         //printf("%s",$$->code);
                         $$->lexval = $1->lexval;
                         //printf("%d",$$->lexval);
              };
Fact   :  '('Arth')' {
	                 
			  $$ = (struct s*)malloc(sizeof(struct s));
                         strcpy($$->code, $2->code);
                         //printf("%s",$$->code);
                         $$->lexval = $2->lexval;
                         //printf("%d",$$->lexval);
              }
	      | NUM {
            $$ = (struct s*)malloc(sizeof(struct s));
            strcpy($$->code, "t");
            strcat($$->code, itoa(tempv));
            strcat($$->code, " = ");
            strcat($$->code, $1);
            if(prec(type)>prec("integer")){
              strcat($$->code, ".00");
            }
            strcat($$->code, "\n");
            $$->lexval=tempv;
            //printf("%s",$$->code);
            tempv++;
          }
        | FloatNUM {
            $$ = (struct s*)malloc(sizeof(struct s));
            strcpy($$->code, "t");
            strcat($$->code, itoa(tempv));
            strcat($$->code, " = ");
            //printf("%s\n",type);
            int a=prec(type);
            int b=prec("float");
             //printf("1");
            if(a<b){
                //printf("1");
                int c=itoa(minimized($1));
            	strcat($$->code, mini($1,c));
            }
            else{
            	//printf("1");
            	strcat($$->code, $1);
            }
            //printf("%s\n",type);
            strcat($$->code, "\n");
            $$->lexval=tempv;
            //printf("%s",$$->code);
            tempv++;
          }
        |  DoubleNUM {
            $$ = (struct s*)malloc(sizeof(struct s));
            strcpy($$->code, "t");
            strcat($$->code, itoa(tempv));
            strcat($$->code, " = ");
            //printf("%s\n",type);
            int a=prec(type);
            int b=prec("float");
             //printf("1");
            if(a<b){
                //printf("1");
                int c=itoa(minimized($1));
            	strcat($$->code, mini($1,c));
            }
            else{
            	//printf("1");
            	strcat($$->code, $1);
            }
            //printf("%s\n",type);
            strcat($$->code, "\n");
            $$->lexval=tempv;
            //printf("%s",$$->code);
            tempv++;
          }
	| ID  { if(strcmp(typeofvar(SymbolTemp,$1),type)!=0){
           		 stat=true;
           		if( strcmp(typeofvar(SymbolTemp,$1),"none")==0){
           		    printf("error:not declared %s\n",$1);
           		}
           		else{
           		   printf("error:conflicting types in the above expression \n");
           		}
           		
            }
            $$ = (struct s*)malloc(sizeof(struct s));
            strcpy($$->code, "");
            //strcat($$->code, itoa(tempv));
            //strcat($$->code, " = ");
            //strcat($$->code, $1);
            //strcat($$->code, "\n");
            //$$->lexval=tempv;
            //printf("%s",$$->code);
            //tempv++;
            
         }
         |'(' TYPE ')' ID { if(strcmp($2->type,type)!=0){
           		    //stat=true;
           		     //printf("%s\n",$2->type);
           		     //printf("%s\n",$2->type);
           		    printf("error:mismatching types %s\n",$4);
           		 }
           		else if( strcmp(typeofvar(SymbolTemp,$4),"none")==0){
           		    stat=true;
           		    printf("error:not declared %s\n",$4);
           		}
           		
           		   $$ = (struct s*)malloc(sizeof(struct s));
			    strcpy($$->code, "t");
			    strcat($$->code, itoa(tempv));
			    strcat($$->code, " = ");
			    strcat($$->code, "(");
			    strcat($$->code, $2->type);
			    strcat($$->code, ")");
			    strcat($$->code, $4);
			    strcat($$->code, "\n");
			    $$->lexval=tempv;
			    //printf("%s",$$->code);
			    tempv++;
           		
           	
           		
            
           
         }
         | ID INC{ if(strcmp(typeofvar(SymbolTemp,$1),type)!=0){
           		 stat=true;
           		if( strcmp(typeofvar(SymbolTemp,$1),"none")==0){
           		    printf("error:not declared %s\n",$1);
           		}
           		else{
           		   printf("error:conflicting types in the above expression \n");
           		}
           		
            }
             $$ = (struct s*)malloc(sizeof(struct s));
             strcpy($$->code, "t");
             strcat($$->code, itoa(tempv)); 
             strcat($$->code, " = ");
             strcat($$->code, $1);
             strcat($$->code, " + 1\n");
             strcat($$->code, $1);
             strcat($$->code, " = t");
             strcat($$->code, itoa(tempv));
             strcat($$->code, "\n");
             $$->lexval = tempv-1;
             tempv++;
         }
         | ID DEC{ if(strcmp(typeofvar(SymbolTemp,$1),type)!=0){
           		 stat=true;
           		if( strcmp(typeofvar(SymbolTemp,$1),"none")==0){
           		    printf("error:not declared %s\n",$1);
           		}
           		else{
           		   printf("error:conflicting types in the above expression \n");
           		}
           		
            }
            $$ = (struct s*)malloc(sizeof(struct s));
             strcpy($$->code, "t");
             strcat($$->code, itoa(tempv)); 
             strcat($$->code, " = ");
             strcat($$->code, $1);
             strcat($$->code, " - 1\n");
             strcat($$->code, $1);
             strcat($$->code, " = t");
             strcat($$->code, itoa(tempv));
             strcat($$->code, "\n");
             $$->lexval = tempv-1;
             tempv++;
          }
         |'(' TYPE ')' ID INC{ if(strcmp($2->type,type)!=0){
           		    stat=true;
           		   
           		    printf("error:mismatching types %s\n",$4);
           		 }
           		else if( strcmp(typeofvar(SymbolTemp,$4),"none")==0){
           		    stat=true;
           		    printf("error:not declared %s\n",$4);
           		}
           		
           		
            
             $$ = (struct s*)malloc(sizeof(struct s));
             strcpy($$->code, "t");
             strcat($$->code, itoa(tempv)); 
             strcat($$->code, " = ");
             strcat($$->code, "(");
             strcat($$->code, $2->type);
             strcat($$->code, ")");
             strcat($$->code, $4);
             strcat($$->code, " + 1\n");
             strcat($$->code, $4);
             strcat($$->code, " = t");
             strcat($$->code, itoa(tempv));
             strcat($$->code, "\n");
             $$->lexval = tempv-1;
             tempv++;
         }
         | '(' TYPE ')' ID DEC{  if(strcmp($2->type,type)!=0){
           		    stat=true;
           		    printf("error:mismatching types %s\n",$4);
           		 }
           		else if( strcmp(typeofvar(SymbolTemp,$4),"none")==0){
           		    stat=true;
           		    printf("error:not declared %s\n",$4);
           		}
            
            $$ = (struct s*)malloc(sizeof(struct s));
             $$ = (struct s*)malloc(sizeof(struct s));
             strcpy($$->code, "t");
             strcat($$->code, itoa(tempv)); 
             strcat($$->code, " = ");
             strcat($$->code, "(");
             strcat($$->code, $2->type);
             strcat($$->code, ")");
             strcat($$->code, $4);
             strcat($$->code, " - 1\n");
             strcat($$->code, $4);
             strcat($$->code, " = t");
             strcat($$->code, itoa(tempv));
             strcat($$->code, "\n");
             $$->lexval = tempv-1;
             tempv++;
         }
          | INC ID{ if(strcmp(typeofvar(SymbolTemp,$2),type)!=0){
           		 stat=true;
           		if( strcmp(typeofvar(SymbolTemp,$2),"none")==0){
           		    printf("error:not declared %s\n",$2);
           		}
           		else{
           		   printf("error:conflicting types in the above expression \n");
           		}
           		
            }
             $$ = (struct s*)malloc(sizeof(struct s));
             strcpy($$->code, "t");
             strcat($$->code, itoa(tempv)); 
             strcat($$->code, " = ");
             strcat($$->code, $2);
             strcat($$->code, " + 1\n");
             strcat($$->code, $2);
             strcat($$->code, " = t");
             strcat($$->code, itoa(tempv));
             strcat($$->code, "\n");
             $$->lexval = tempv;
             tempv++;
         }
         | DEC ID{ if(strcmp(typeofvar(SymbolTemp,$2),type)!=0){
           		 stat=true;
           		if( strcmp(typeofvar(SymbolTemp,$2),"none")==0){
           		    printf("error:not declared %s\n",$2);
           		}
           		else{
           		   printf("error:conflicting types in the above expression \n");
           		}
           		
            }
            $$ = (struct s*)malloc(sizeof(struct s));
             strcpy($$->code, "t");
             strcat($$->code, itoa(tempv)); 
             strcat($$->code, " = ");
             strcat($$->code, $2);
             strcat($$->code, " - 1\n");
             strcat($$->code, $2);
             strcat($$->code, " = t");
             strcat($$->code, itoa(tempv));
             strcat($$->code, "\n");
             $$->lexval = tempv;
             tempv++;
          }
         |'(' TYPE ')' INC ID{ if(strcmp($2->type,type)!=0){
           		    stat=true;
           		   
           		    printf("error:mismatching types %s\n",$5);
           		 }
           		else if( strcmp(typeofvar(SymbolTemp,$5),"none")==0){
           		    stat=true;
           		    printf("error:not declared %s\n",$5);
           		}
           		
           		
            
             $$ = (struct s*)malloc(sizeof(struct s));
             strcpy($$->code, "t");
             strcat($$->code, itoa(tempv)); 
             strcat($$->code, " = ");
             strcat($$->code, "(");
             strcat($$->code, $2->type);
             strcat($$->code, ")");
             strcat($$->code, $5);
             strcat($$->code, " + 1\n");
             strcat($$->code, $5);
             strcat($$->code, " = t");
             strcat($$->code, itoa(tempv));
             strcat($$->code, "\n");
             $$->lexval = tempv;
             tempv++;
         }
         | '(' TYPE ')' DEC ID{  if(strcmp($2->type,type)!=0){
           		    stat=true;
           		    printf("error:mismatching types %s\n",$5);
           		 }
           		else if( strcmp(typeofvar(SymbolTemp,$5),"none")==0){
           		    stat=true;
           		    printf("error:not declared %s\n",$5);
           		}
            
            $$ = (struct s*)malloc(sizeof(struct s));
             $$ = (struct s*)malloc(sizeof(struct s));
             strcpy($$->code, "t");
             strcat($$->code, itoa(tempv)); 
             strcat($$->code, " = ");
             strcat($$->code, "(");
             strcat($$->code, $2->type);
             strcat($$->code, ")");
             strcat($$->code, $5);
             strcat($$->code, " - 1\n");
             strcat($$->code, $5);
             strcat($$->code, " = t");
             strcat($$->code, itoa(tempv));
             strcat($$->code, "\n");
             $$->lexval = tempv;
             tempv++;
         };

TYPE :  CHAR {$$= (struct TypeNode*)malloc(sizeof(struct TypeNode));
            strcpy(type,"char");
            strcpy($$->type,"char");
            size=1;
            $$->size=1;
           
          }
       | INT {$$= (struct TypeNode*)malloc(sizeof(struct TypeNode));
            strcpy(type,"integer");
            strcpy($$->type,"integer");
            size=4;
            $$->size=4;
           
            }
       | LONG {$$= (struct TypeNode*)malloc(sizeof(struct TypeNode));
            strcpy(type,"long");
            strcpy($$->type,"long");
            size=8;
            $$->size=8;
           
            }
       | FLOAT {$$= (struct TypeNode*)malloc(sizeof(struct TypeNode));
            strcpy(type,"float");
            strcpy($$->type,"float");
            size=4;
            $$->size=4;
        
            }
        
        | DOUBLE {$$= (struct TypeNode*)malloc(sizeof(struct TypeNode));
            strcpy(type,"double");
            strcpy($$->type,"double");
            size=8;
            $$->size=8;
           
            }
        | STRING {$$= (struct TypeNode*)malloc(sizeof(struct TypeNode));
            strcpy(type,"string");
            strcpy($$->type,"string");
            size=50;
            $$->size=50;
           
            }
        ;
        
        
Block : LBracket {printf("\n");push(&st,0);struct SymbolTable* temp=(struct SymbolTable*)malloc(sizeof(struct SymbolTable));Construct(temp,SymbolTemp);SymbolTemp=temp;}  List                   RBracket{  printf("\n");pop(&st);SymbolTemp=SymbolTemp->prev;$$ = (struct s*)malloc(sizeof(struct s));
                               strcpy($$->code, $3->code);
                              } ;


Expr : ID {
		
       	 if(verify(SymbolTemp,$1,type)==0){
           		 stat=true;
           		 printf("error:conflicting types for %s\n",$1);
        	 }
        	 else if(verify(SymbolTemp,$1,type)==-1){
            		stat=true;
            		printf("error:redeclaration of %s\n",$1);
        	 }
                 else{
		
			add_name(SymbolTemp,top(st),$1,type);
			int x=top(st);
			pop(&st);
			x = x+size;
			push(&st,x);
		 }
		              
		 

	}',' Expr | ID {
		
       	 if(verify(SymbolTemp,$1,type)==0){
           		 stat=true;           		 
           		 printf("error:conflicting types for %s\n",$1);
        	 }
        	 else if(verify(SymbolTemp,$1,type)==-1){
            		stat=true;
            		printf("error:redeclaration of %s\n",$1);
        	 }
                 else{
		
			add_name(SymbolTemp,top(st),$1,type);
			int x=top(st);
			pop(&st);
			x = x+size;
			push(&st,x);
		 }
		  $$ = (struct s*)malloc(sizeof(struct s));
	                   strcpy($$->code, "t");
                          strcat($$->code, itoa(tempv));
		           strcat($$->code, " = ");
			   strcat($$->code,$1);
			   strcat($$->code, "\n");
			   $$->lexval = tempv;
		          tempv++; 
		 
		  
	}
	| ID '[' NUM ']' {
		 if(verify(SymbolTemp,$1,type)==0){
           		 stat=true;           		 
           		 printf("error:conflicting types for %s\n",$1);
        	 }
	         else if(verify(SymbolTemp,$1,type)==-1){
            		stat=true;
            		printf("error:redeclaration of %s\n",$1);
        	 }
                 else{
		
			strcat(type," ");
   		        strcat (type,"array");
    		        add_name(SymbolTemp,top(st),$1,type);  
    		        int x=top(st);
                        pop(&st);
		        x = x+size*atoi($3);
		        push(&st,x); 
		 }
		  $$ = (struct s*)malloc(sizeof(struct s));
	                   strcpy($$->code, "t");
                          strcat($$->code, itoa(tempv));
		           strcat($$->code, " = ");
		           //int s=(atoi(NUM))*size;
		           
			   strcat($$->code,$3);
			   strcat($$->code,"*");
			   strcat($$->code,itoa(size));
			   tempv++; 
			   strcat($$->code, "\n");
			   strcat($$->code, "t");
                          strcat($$->code, itoa(tempv));
		           strcat($$->code, " = ");
		           strcat($$->code, $1);
		           strcat($$->code, "[");
		           strcat($$->code, "t");
                          strcat($$->code, itoa(tempv-1));
		            strcat($$->code, "]");
			   strcat($$->code, "\n");
			   $$->lexval = tempv;
		          tempv++; 

		 
        }
	| ID  {
		 
       	 if(verify(SymbolTemp,$1,type)==0){
           		 stat=true;           		 
           		 printf("error:conflicting types for %s\n",$1);
        	 }
        	 else if(verify(SymbolTemp,$1,type)==-1){
            		stat=true;
            		printf("error:redeclaration of %s\n",$1);
        	 }
                 else{
		
			add_name(SymbolTemp,top(st),$1,type);
			int x=top(st);
			pop(&st);
			x = x+size;
			push(&st,x);
		 }
	}'=' Arth{
	                  
	                  $$ = (struct s*)malloc(sizeof(struct s));
	                  strcpy($$->code,$4->code);
	                  
	                  strcat($$->code,$1);
	                  strcat($$->code, " = ");
	                  strcat($$->code, "t");
                          strcat($$->code, itoa($4->lexval));
			   strcat($$->code, "\n");
		           $$->lexval = $4->lexval;
		           //printf("%s",$$->code);
		           
		                  
	}
;

Cond    :
		    
	ID COMP ID {
			$$ = (struct s*)malloc(sizeof(struct s));
			strcpy($$->code, $1);
			strcat($$->code, $2);
			strcat($$->code,$3);
			$$->left=NULL;
			$$->right=NULL;
			//printf("compared \n");
			if(strcmp(typeofvar(SymbolTemp,$1),typeofvar(SymbolTemp,$3))!=0){
           		    printf("error:both %s and %s are of two different data types\n",$1,$3);
           		    stat=true;
           		}
           		else if( strcmp(typeofvar(SymbolTemp,$1),"none")==0||strcmp(typeofvar(SymbolTemp,$3),"none")==0){
           		    printf("error:not declared \n");
           		    stat=true;
           		}
           		
		      }
	|  NUM COMP ID {
			$$ = (struct s*)malloc(sizeof(struct s));
			strcpy($$->code, $1);
			strcat($$->code, $2);
			strcat($$->code,$3);
			//printf("%s",$$->code);
			$$->left=NULL;
			$$->right=NULL;
			if( strcmp(typeofvar(SymbolTemp,$3),"none")==0){
           		    printf("error:not declared %s\n",$3);
           		    stat=true;
           		}
			}
	|  ID COMP NUM {
			$$ = (struct s*)malloc(sizeof(struct s));
			strcpy($$->code, $1);
			strcat($$->code, $2);
			strcat($$->code,$3);
			$$->left=NULL;
			$$->right=NULL;
			if( strcmp(typeofvar(SymbolTemp,$1),"none")==0){
           		    printf("error:not declared %s\n",$1);
           		    stat=true;
           		}
			}
	|  NUM COMP NUM {
			$$ = (struct s*)malloc(sizeof(struct s));
			strcpy($$->code, $1);
			strcat($$->code, $2);
			strcat($$->code,$3);
			$$->left=NULL;
			$$->right=NULL;
			}
;


%%
int yyerror(char * s){

    printf("Not Accepted  %s\n",s);

    return 0;
}



 
void add_name(struct SymbolTable* symbol,int addr , char lexeme [], char type[]){

     if(symbol->head == NULL){
       struct new_Entry* temp=(struct new_Entry*)malloc(sizeof(struct new_Entry));
       if(global==NULL&&head==NULL){
          global= temp;
          head=global;
       }
       else{
          global->next=temp;
          global=temp;
          global->next=NULL;
       }
       
       symbol->head = global;
       symbol->head->addr = addr;
       strcpy(symbol->head->lexeme,lexeme);
       strcpy(symbol->head->type,type);
       symbol->tail=symbol->head;
       symbol->head->next=NULL;
    }
    else{
        struct new_Entry*  Entry = (struct new_Entry*)malloc(sizeof(struct new_Entry));
        Entry->addr = addr;
        strcpy(Entry->lexeme,lexeme);
        strcpy(Entry->type,type);
        global->next=Entry;
        global=Entry;
        global->next=NULL;
        symbol->tail->next = Entry;
        symbol->tail = Entry;
        symbol->tail->next=NULL;
    }
}

void Construct(struct SymbolTable* symbol,struct SymbolTable* prev){
    symbol->prev=prev;
    symbol->head=NULL;
    symbol->tail=NULL;
}

char* itoa(int num){
    int len, i = 0, q = 0, temp = num;
    //printf("%d",num);
    char* str = (char*) malloc(sizeof(char)*10);
    if(num == 0){
        str[0] = '0';
        return str;
    }
    while(temp > 0){
        int rem = temp%10;
        q = 10*q + rem;
        temp /= 10;
    }
    temp = q;
    while(temp > 0){
        int rem = temp%10;
        str[i] = '0' + rem;
        temp /= 10;
        i++;
    }
    return str;
}

int prec(char* type){
   //printf("%s\n",type);
   if(strcmp(type,"double")==0||strcmp(type,"float")==0){
      return 2;
   }
   if(strcmp(type,"integer")==0||strcmp(type,"long")==0){
   //printf("%s\n",type);
      return 1;
   }
   return 0;
}

int minimized(char* str){
   
   for(int i=0;i<strlen(str);i++){
    
    if(str[i]=='.'){
    
       return i;
    }
    
   }
   return -1;
}

char* maximized(char* str){
   strcat(str,".00");
   return str;
}

char* traversal(struct s* node){
        
        char *cod;
        strcpy(cod,"1");
	if(node==NULL){
	     return "";
	}
	if(node->left==NULL && node->right==NULL){
	         strcpy(cod,"if ");
	         strcat(cod,node->code);
	         strcat(cod," goto label");
	         strcat(cod,itoa(node->True));
	         strcat(cod,"\n");
	         strcat(cod,"goto label");
	         strcat(cod,itoa(node->False));
	         strcat(cod,"\n");

	}
	else if(strcmp(node->op,"!")==0){
	         strcpy(cod,"if ");
	         strcat(cod,node->code);
	         strcat(cod," goto label");
	         strcat(cod,itoa(node->False));
	         strcat(cod,"\n");
	         strcat(cod,"goto label");
	         strcat(cod,itoa(node->True));
	         strcat(cod,"\n");
	}
	
	else if(strcmp(node->op,"||")==0){
		 strcpy(cod,"if ");
	         strcat(cod,node->left->code);
	         strcat(cod," goto label");
	         strcat(cod,itoa(node->True));
	         strcat(cod,"\n");
	         strcat(cod,"goto label");
	         strcat(cod,itoa(labelv));
	         strcat(cod,"label");
	         strcat("%d:\n",labelv);
	         strcat(cod,"if ");
	         strcat(cod,node->right->code);
	         strcat(cod," goto label");
	         strcat(cod,itoa(node->True));
	         strcat(cod,"\n");
	         strcat(cod,"goto label");
	         strcat(cod,itoa(node->False));
	         labelv++;
	         strcpy(cod,"\n");
	}
	else if(strcmp(node->op,"&&")==0){
	         strcpy(cod,"if ");
	         strcat(cod,node->left->code);
	         strcat(cod," goto label");
	         strcat(cod,itoa(labelv));
	         strcat(cod,"\n");
	         strcat(cod,"goto label");
	         strcat(cod,itoa(node->False));
	         strcat(cod,"label");
	         strcat("%d:\n",labelv);
	         strcpy(cod,"if ");
	         strcat(cod,node->right->code);
	         strcat(cod," goto label");
	         strcat(cod,itoa(node->True));
	         strcat(cod,"\n");
	         strcat(cod,"goto label");
	         strcat(cod,itoa(node->False));
	         labelv++;
	         strcat(cod,"\n");
	}
	return cod;
}


int verify(struct SymbolTable* symbol,char lexeme [ ], char type[]){
    struct new_Entry* h=symbol->head;
    for(struct new_Entry* i=h;i!=NULL;i=i->next){
        if(strcmp(h->lexeme,lexeme)==0){
            if(strcmp(h->type,type)==0){
                return -1;
            }
            return 0;
        }
    }
    return 1;
 }
char* typeofvar(struct SymbolTable* symbol,char lexeme [ ]){
    struct new_Entry* h=symbol->head;
    for(struct new_Entry* i=h;i!=NULL;i=i->next){
    	//printf("%s\n",i->lexeme);
        if(strcmp(i->lexeme,lexeme)==0){
            return i->type;
        }
    }
    return "none";
 }
 
 
 char* mini(char* str,int i){
    char *token;
    char s[2]=".";
   /* get the first token */
   token = strtok(str, s);
   return token;
 }

void Symbol_Table(){
    struct SymbolTable* symbol=SymbolHead;
    while(symbol!=NULL){
	    struct new_Entry* temp  = symbol->head;
	    while(temp !=NULL){
		printf("%#06x %s %s\n",temp ->addr,temp ->lexeme,temp ->type);
		temp =temp ->next;
	    } 
	    printf("\n");
	    symbol=symbol->prev;
   }
}



int main(int argc , char* argv[]){

    if(argc>1){
        FILE *fp = fopen(argv[1],"r");

        if(fp)yyin = fp;
    }

    yyparse();
    return 0;
}
