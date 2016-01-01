#include "bf.h"

char* noExecLoop(char **pstring, char *curp){
	
	for((*pstring)++;**pstring != ']';(*pstring)++){
		if (**pstring == '['){
			subInterpreter(pstring, curp);
		}
	}

	return curp;
}

char* execLoop(char **pstring, char *curp){
	
	char *leftBraceStart = *pstring;

	for((*pstring)++; **pstring != '\0';(*pstring)++){

		switch(**pstring){
			case '+' : (*curp)++; break;
			case '-' : (*curp)--; break;
			case '>' : curp++;break;
			case '<' : curp--;break;
			case '[' : curp = subInterpreter(pstring, curp);continue;
			case ']' : 
				if (*curp == 0){
					//(*pstring)++;
					//printf("==%c==",(**pstring));
					return curp;
				}
				else{
					*pstring = leftBraceStart;
				};
				break;
			case '.' : printf("%c", *curp);/*getch()*/; break;
			case ',' : *curp = getchar() ;break;
			default : break;
		}
		
	}
}

char* subInterpreter(char **pstring, char *curp){
	
	if(*curp == 0){
		curp = noExecLoop(pstring,curp);

	}else{
		curp = execLoop(pstring,curp);
	}
	
	return curp;
}

int intepreter(char *string, char *curp){
	
	char **pstring = &string;

	for(int i = 0;**pstring != '\0';(*pstring)++,i++){
		
		switch(**pstring){
			case '+' : (*curp)++; break;
			case '-' : (*curp)--; break;
			case '>' : curp++;break;
			case '<' : curp--;break;
			case '[' : 
				curp = subInterpreter(pstring, curp); 
				//printf("%c", *((*pstring)+1));
				break;
			case ']' :
				/*printf("%c", *((*pstring)+1))*/;exit(-1);
				//continue;
			case '.' : printf("%c", *curp);/*getch()*/; break;
			case ',' : *curp = getchar(); break;
			default	: break;
		}
		
	}
}

void get_arg(char *arg){
	
	if(!strcmp(arg,"-v") || !strcmp(arg,"-V")){
		
		printf("version 0.1");
		
	}else if(!strcmp(arg,"-h") || !strcmp(arg,"-H")){
		
		printf("--help");
		
	}else{
		
		char arr[3000] = {0};
		char str[10000]={'\0'};
		FILE *source = fopen(arg,"r");
		
		if(!source){
			
			printf("oen file %s fail", arg);
			exit(-1);
			
		}else{
			
			for(int i = 0;(str[i] = fgetc(source)) != EOF; i++){
				
			}
			
		}
		
		intepreter(str, arr);		
	}
}

void show_arg_error(){
	
	puts("illegal option");
	exit(-1);
	
}

int main(int argc, char **argv)
{
	
	if(argc == 2){
		
		get_arg(argv[1]);
		
	}else if(argc == 1){
		
		char arr[3000] = {0};
		char str[1000]={'\0'};
		scanf("%s",str);
		intepreter(str, arr);
		
	}else{
		
		show_arg_error();
		
	}

	return 0;
}