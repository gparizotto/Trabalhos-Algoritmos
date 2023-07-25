//Trabalho Algoritmos I -- Gabriel Zanforlin Parizotto
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

void gotoxy (int x, int y) {
 COORD pos = {x, y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} 
int SetColor (char color) {
 HANDLE h;
 h = GetStdHandle (STD_OUTPUT_HANDLE);
 return SetConsoleTextAttribute (h,color);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
void descobrearc(int num) {
	double valor,y;
	system("cls");
	system("color 4F");
	gotoxy(3,2);
	printf("Digite o valor que voce possui\n");
	scanf("%lf",&valor);
	if(num==49) {
		while(valor<-1 || valor>1) {
			printf("Nao existe angulo com esses parametros, digite outro valor\n");
			scanf("%lf",&valor);
		}
		y=asin(valor)*(1/(M_PI/180));
		SetColor(95);
		printf("  O angulo vale %4.2lf graus\n",y);
	}
	else if(num==50) {
		while(valor<-1 || valor>1) {
			printf("Nao existe angulo com esses parametros, digite outro valor\n");
			scanf("%lf",&valor);
		}
		y=y=acos(valor)*(1/(M_PI/180));
		SetColor(95);
		printf("  O angulo vale %4.2lf graus\n",y);
	}
	else {
		y=atan(valor)*(1/(M_PI/180));
		SetColor(95);
		printf("  O angulo vale %4.2lf graus\n",y);
	}
	SetColor(79);
	printf("\n\tDeseja executar a caluladora trigonometrica novamente? Digite qualquer tecla para executa-la ou esc para sair\n");		
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
void tela_inicial () {
	gotoxy(40,1);
	SetColor(112);
	printf("Calculadora Trigonometrica em C\n");
	SetColor(79);
	gotoxy(2,3);
	printf("Bem vindo(a)!\n");
	printf("Esse programa tem a funcao de calcular valores trigonometricos de um angulo fornecido pelo usuario\n\n");
	printf("Primeiramente, informe qual modelo voce deseja usar:\n");
	SetColor(112);
	printf("\n\t1- Digite o valor de um angulo em graus ou radianos e descubra seus valores trigonometricos\n");
	printf("\n\t2- Digite o valor de uma funcao trigonometrica e descubra o valor do angulo correspondente\n");
	SetColor(79);
	printf("Digite o numero correspondente de cada opcao, por favor\n");
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
void tabela () {
	double angulo;
	char medida;
	int i,j,cont=0;
	system("cls");
	gotoxy(3,2);
	printf("Voce deseja colocar um angulo medido em graus ou radianos? Digite ""g"" para graus e ""r"" para radianos\n");
	scanf("%s",&medida);
	while(medida!= 'g' && medida != 'r' && medida!= 'R' && medida != 'G') {
		printf("Por favor, digite novamente\n");
		scanf("%s",&medida);
	}
	if(medida == 'g' || medida == 'G') {
		printf("Digite o valor do angulo em graus\n");
		scanf("%lf",&angulo);
		angulo=angulo*M_PI/180;
	}
	else {
		printf("Digite o valor em radianos\n");
		scanf("%lf",&angulo);
	}
	system("cls");
	gotoxy(40,1);
	SetColor(95);
	printf("Tabela Trtigonometrica\n\n");
	SetColor(7);
	printf("\n\n");
	printf("\t\t\t");
	gotoxy(40,3);
	for(i=1;i<=36;i++) {
		printf("-");
	}
	printf("\n");
	for(i=1;i<=18;i++) {
		if(i%2) {
			gotoxy(40,i+3);
			if(i==1) {
				printf("|");
				SetColor(71);
				printf("Sen     ");
				SetColor(94);
				printf(" %.2lf",sin(angulo));
			}
			if(i==3) {
				printf("|");
				SetColor(112);
				printf("Cos     ");
				SetColor(94);
				printf(" %.2lf",cos(angulo));
			}
			if(i==5) {
					printf("|");
					SetColor(71);
					printf("Tan     ");
					SetColor(94);
					if(tan(angulo)<999 && tan(angulo)>-999)
						printf(" %.2lf",tan(angulo));	
					else {
						printf(" Nao Existe");	
						cont++;
					}
				}
			if(i==7) {
				printf("|");
				SetColor(112);
				printf("Sec     ");
				SetColor(94);
				if(1/cos(angulo)<999 && 1/cos(angulo)>-999)
					printf(" %.2lf",1/cos(angulo));
				else {
					printf(" Nao existe");	
					cont++;
				}
			}
			if(i==9) {
				printf("|");
				SetColor(71);
				printf("Cossec  ");
				SetColor(94);
				if(1/sin(angulo)<999 && 1/sin(angulo)>-999)
					printf(" %.2lf",1/sin(angulo));
				else {
					printf(" Nao existe");	
					cont++;
				}
			}
			if(i==11) {
				printf("|");
				SetColor(112);
				printf("Cotan   ");
				SetColor(94);
				if((1/tan(angulo))<999 && (1/tan(angulo))>-999 )
					printf(" %.2lf",1/tan(angulo));
				else {
					printf(" Nao existe");	
					cont++;
				}
			}
			if(i==13) {
				printf("|");
				SetColor(71);
				printf("Arc Sen ");
				SetColor(94);
				if(asin(angulo)<999 && asin(angulo)>-999)
					printf(" %.2lf",asin(angulo));
				else {
					printf(" Nao existe");	
					cont++;
				}
			}
			if(i==15) {
				printf("|");
				SetColor(112);
				printf("Arc Cos ");
				SetColor(94);
				if(acos(angulo)<999 && acos(angulo)>-999)
					printf(" %.2lf",acos(angulo));
				else {
					printf(" Nao existe");	
					cont++;
				}
			}
			if(i==17) {
				printf("|");
				SetColor(71);
				printf("Arc Tan ");
				SetColor(94);
				printf(" %.2lf",atan(angulo));
			}
			SetColor(94);
			if(cont==0) {
				for(j=1;j<=21;j++)
					printf(" ");
				SetColor(7);
				printf("|\n");	
			}
			else {
				for(j=1;j<=15;j++)
					printf(" ");
				SetColor(7);
				printf("|\n");
			}
			cont=0;
		}
		else {
			gotoxy(40,i+3);
			SetColor(7);
			for(j=1;j<=36;j++)
				printf("-");
			printf("\n");	
		}
	}
	SetColor(79);
	printf("\n\tDeseja executar a caluladora trigonometrica novamente? Digite qualquer tecla para executa-la ou esc para sair\n");	
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
int descobreangulo() {
	char c;
	printf("Qual valor voce tem?\n");
	SetColor(112);
	printf("\t1-Arc Sen\n\t2-Arc Cos\n\t3-Arc Tan\n");
	SetColor(79);
	c=getch();
	while(c!=49 && c!=50 && c!=51) {
		printf("Digite um valor valido\n");
		c=getch();
	}
	descobrearc(c);	
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
int main () {
	char resp,c;
	do {
		system("color 4F");
		tela_inicial();
		c=getch();
		while(c!=49 && c!=50) {
			printf("Opcao invalida, digite novamente\n");
			c=getch();
		}
		if(c==49)
			tabela();
		else
		descobreangulo();
		resp= getch();	
		system("cls");
	}while(resp!=27);	
	gotoxy(40,10);
	printf("Obrigado! Ate a proxima");
}
