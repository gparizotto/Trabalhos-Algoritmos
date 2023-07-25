//senha: AlgIIBCC 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

void gotoxy(short x, short y) {
 COORD pos = {x, y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
pos);
} 

int SetColor (char color) {
 HANDLE h;
 h = GetStdHandle (STD_OUTPUT_HANDLE);
 return SetConsoleTextAttribute (h,color);
} 

void texto(int x, int y, char cor) {
	gotoxy(x,y);
	SetColor(cor);
}

void limpaLinha(int x, int y, int tam) {
	gotoxy(x,y);
	for(int i = 0; i < tam; i++)
		printf(" ");
}

void data(int *d, int *m, int *a) {
	struct tm *data_hora_atual;
	time_t segundos;
	time(&segundos);
	data_hora_atual = localtime(&segundos);
	*d = data_hora_atual->tm_mday;
	*m = data_hora_atual->tm_mon + 1;
	*a = data_hora_atual->tm_year + 1900;
}

void menu() {
	int i;
	texto(45,1,79);
	printf("Caixa Eletronico de WebLands");
	texto(4,3,15);
	for(i = 0; i < 110; i++)
		printf("-");
	for(i = 0; i < 22; i++) {
		texto(4,4+i,15);
		printf("|");
		texto(113,4+i,15);
		printf("|");
	}	
	texto(4,26,15);
	for(i = 0; i < 110; i++)
		printf("-");
	printf("\n\n");	
}

void info(char nome[], char senha[], char num[]) {
	char senhaReal[11];
	strcpy(senhaReal,"AlgIIBCC");
	texto(6,5,87);
	printf("Digite o nome do proprietario da conta:");
	texto(6,7,15);
	gets(nome);
	limpaLinha(6,5,107);
	limpaLinha(6,7,107);
	texto(6,5,87);
	printf("Digite a senha: ");
	texto(6,7,15);
	gets(senha);
	limpaLinha(6,5,107);
	limpaLinha(6,7,107);
	while(strcmp(senhaReal,senha)) {
		texto(6,5,91);
		printf("Senha incorreta, digite novamente!");
		texto(6,7,15);
		gets(senha);
		limpaLinha(6,5,107);
		limpaLinha(6,7,107);
	}
	texto(6,5,87); 
	printf("Digite a quantidade de dinheiro a ser transferida (maximo 12 digitos antes da virgula): ");
	texto(6,7,15);
	printf("Modelo: XXXXXXXXXXXX,XX");
	texto(6,9,15);
	gets(num);
	limpaLinha(6,5,107);
	limpaLinha(6,7,107);
	limpaLinha(6,9,107);
}

void info2(char num[]) {
	texto(6,5,87); 
	printf("Digite a quantidade de dinheiro a ser transferida (maximo 12 digitos antes da virgula): ");
	texto(6,7,15);
	printf("Modelo: XXXXXXXXXXXX,XX");
	texto(6,12,79);
	printf("Numero digitado invalido, digite novamente");
	texto(6,9,15);
	gets(num);
	limpaLinha(6,5,107);
	limpaLinha(6,7,107);
	limpaLinha(6,9,107);
	limpaLinha(6,12,107);
}

int ValidaNum(char num[], char decimal[]) {
	int i, aux = 0, qdevirgula = 0, qdecasas;
	char *str;
	if(strlen(decimal) > 12)
		return 0;
	for(i = 0; i < strlen(num); i++) {
		if(((int)num[i] >= 48 && (int)num[i] <= 57) || (int)num[i] == 44)
			aux++;
		if(num[i] == ',')
			qdevirgula++;	
	}
	if(aux != strlen(num))
		return 0;
	if(qdevirgula > 1)
		return 0;	
	if(qdevirgula == 1) {
		for(i = 0; i < strlen(num); i++)
			if(num[i] == ',') {
				qdecasas = strlen(num) - i - 1;
				if(qdecasas >= 3)
					return 0;
			}
	}			
	return 1;		
} 

void CalculaDinheiro(char num[], char virgula[], int notas[], int moedas[], char notas100[]) {
	char num2[13];
	int n, m, resto = 0;
	strcpy(num2,num);
	for(int i = 0; i < 10; i++) {
		notas100[i] = num2[i];
		num2[i] = '0';
	}
		
	n = atoi(num2);
	
	notas[0] = n / 50;
	n -= notas[0] * 50;
	
	notas[1] = n / 20;
	n -= notas[1] * 20;
	
	notas[2] = n / 10;
	n -= notas[2] * 10;
	
	notas[3] = n / 5;
	n -= notas[3] * 5;
	
	notas[4] = n / 2;
	n -= notas[4] * 2;
	
	m = atoi(virgula);
	
	moedas[0] = n;
	
	moedas[1] = m / 50;
	m -= moedas[1] * 50;
	
	moedas[2] = m / 25;
	m -= moedas[2] * 25;
	
	moedas[3] = m / 10;
	m -= moedas[3] * 10;
	
	moedas[4] = m;
}

void AdicionaZero(char num[]) {
	int i, n;
	n = strlen(num);
	strcpy(num,strrev(num));
	if(strlen(num) < 12) {
		for(i = 0; i < 12 - n; i++) {
			strcat(num,"0");
		}
	}
	strcpy(num,strrev(num));
}

void separa(char num[], char decimal[], char virgula[]) {
	char *str, *teste;
	teste = strstr(num,",");
	if(teste != NULL) {
		str = strtok(num,",");
		strcpy(decimal,str);
		str = strtok(NULL," ");
		strcpy(virgula,str);
	}
	else {
		strcpy(decimal,num);
		strcpy(virgula,"00");
	}
}

void printaBits(char num[], char valor[]) {
	int num2;
	for(int i = 0; i < strlen(num); i++) {
		if((i == 11 || i == 8 || i == 5 || i == 2) && num[i-1] != '1') {
			if(num[i-1] != '0' && num[i] != '0' || num[i-2] != '0' && num[i-1] == '0' && num[i] != '0')
				strcat(valor,"e ");
			if(num[i] == '1')
				strcat(valor,"um ");
			if(num[i] == '2')
				strcat(valor,"dois ");
			if(num[i] == '3')
				strcat(valor,"tres ");
			if(num[i] == '4')
				strcat(valor,"quatro ");
			if(num[i] == '5')
				strcat(valor,"cinco ");
			if(num[i] == '6')
				strcat(valor,"seis ");
			if(num[i] == '7')
				strcat(valor,"sete ");
			if(num[i] == '8')
				strcat(valor,"oito ");
			if(num[i] == '9')
				strcat(valor,"nove ");
			if(num[i] != '0' || num[i-1] != '0' || num[i-2] != '0') {
				if(i == 2) {
					if(num[i] > '1' || num[i-1] >= '1' || num[i-2] >= '1')
						strcat(valor,"bilhoes, ");
					else if(num[i] == '1' && num[i-1] == '0' && num[i-2] == '0')
						strcat(valor,"bilhao, ");
				}
				if(i == 5) {
					if(num[i] != '1' || num[i-1] >= '1' || num[i-2] >= '1')
						strcat(valor,"milhoes, ");
					else if(num[i] == '1' && num[i-1] == '0' && num[i-2] == '0')
						strcat(valor,"milhao, ");
				}
				if(i == 8)
					strcat(valor,"mil, ");
			}
			if(i == 11)
				strcat(valor,"Bits");		
		}
		if(i == 10 || i == 7 || i == 4 || i == 1) {
			if(num[i-1] != '0' && num[i] != '0')
				strcat(valor,"e ");
			if(num[i] == '1') {
				if(num[i+1] == '0')
					strcat(valor,"dez ");
				if(num[i+1] == '1')
					strcat(valor,"onze ");
				if(num[i+1] == '2')
					strcat(valor,"doze ");
				if(num[i+1] == '3')
					strcat(valor,"treze ");
				if(num[i+1] == '4')
					strcat(valor,"quatorze ");
				if(num[i+1] == '5')
					strcat(valor,"quinze ");
				if(num[i+1] == '6')
					strcat(valor,"dezesseis ");
				if(num[i+1] == '7')
					strcat(valor,"dezessete ");
				if(num[i+1] == '8')
					strcat(valor,"dezoito ");
				if(num[i+1] == '9')
					strcat(valor,"dezenove ");
				if(num[i] != '0' || num[i-1] != '0' || num[i+1] != '0') {
					if(i == 1) 
						strcat(valor,"bilhoes, ");
					if(i == 4)
						strcat(valor,"milhoes, ");
					if(i == 7)	
						strcat(valor,"mil, ");
					if(i == 10)
						strcat(valor,"Bits");	
				}	
			}
			if(num[i] == '2')
				strcat(valor,"vinte ");
			if(num[i] == '3')
				strcat(valor,"trinta ");
			if(num[i] == '4')
				strcat(valor,"quarenta ");
			if(num[i] == '5')
				strcat(valor,"cinquenta ");
			if(num[i] == '6')
				strcat(valor,"sessenta ");
			if(num[i] == '7')
				strcat(valor,"setenta ");
			if(num[i] == '8')
				strcat(valor,"oitenta ");
			if(num[i] == '9')
				strcat(valor,"noventa ");
		}
		if(i == 9 || i == 6 || i == 3 || i == 0) {
			if((num[i] == '1') && (num[i+1] != '0' || num[i+2] != '0'))
				strcat(valor,"cento ");
			if(num[i] == '1' && num[i+1] == '0' && num[i+2] == '0')
				strcat(valor,"cem ");	
			if(num[i] == '2')
				strcat(valor,"duzentos ");
			if(num[i] == '3')
				strcat(valor,"trezentos ");
			if(num[i] == '4')
				strcat(valor,"quatrocentos ");
			if(num[i] == '5')
				strcat(valor,"quinhentos ");
			if(num[i] == '6')
				strcat(valor,"seiscentos ");
			if(num[i] == '7')
				strcat(valor,"setecentos ");
			if(num[i] == '8')
				strcat(valor,"oitocentos ");
			if(num[i] == '9')
				strcat(valor,"novecentos ");
		}
	}
}

void printaBitCents(char num[], char valor[]) {
	if(num[0] != '0' || num[1] != '0')
		strcat(valor,", ");
	if(num[0] != '0' && num[0] != '1') {
		if(num[0] == '2')
			strcat(valor,"vinte ");
		if(num[0] == '3')
			strcat(valor,"trinta ");
		if(num[0] == '4')
			strcat(valor,"quarenta ");
		if(num[0] == '5')
			strcat(valor,"cinquenta ");
		if(num[0] == '6')
			strcat(valor,"sessenta ");
		if(num[0] == '7')
			strcat(valor,"setenta ");
		if(num[0] == '8')
			strcat(valor,"oitenta ");
		if(num[0] == '9')
			strcat(valor,"noventa ");
	}
	if(num[0] == '1') {
		if(num[1] == '0')
			strcat(valor,"dez ");
		if(num[1] == '1')
			strcat(valor,"onze ");
		if(num[1] == '2')
			strcat(valor,"doze ");
		if(num[1] == '3')
			strcat(valor,"treze ");
		if(num[1] == '4')
			strcat(valor,"quatorze ");
		if(num[1] == '5')
			strcat(valor,"quinze ");
		if(num[1] == '6')
			strcat(valor,"dezesseis ");
		if(num[1] == '7')
			strcat(valor,"dezessete ");
		if(num[1] == '8')
			strcat(valor,"dezoito ");
		if(num[1] == '9')
			strcat(valor,"dezenove ");
	}
	if(num[0] != '1') {
		if(num[1] != '0')
		strcat(valor,"e ");
		if(num[1] == '1')
			strcat(valor,"um");
		if(num[1] == '2')
			strcat(valor,"dois ");
		if(num[1] == '3')
			strcat(valor,"tres ");
		if(num[1] == '4')
			strcat(valor,"quatro ");
		if(num[1] == '5')
			strcat(valor,"cinco ");
		if(num[1] == '6')
			strcat(valor,"seis ");
		if(num[1] == '7')
			strcat(valor,"sete ");
		if(num[1] == '8')
			strcat(valor,"oito ");
		if(num[1] == '9')
			strcat(valor,"nove ");		
	}
	if(num[0] != '0' || num[1] != '0')
		strcat(valor,"CentBits.");
	if(num[0] == '0' && num[1] == '0')
		strcat(valor,".");
}

void printaDinheiro(int notas[], int moedas[], char num[], char notas100[]) {
	int i = 0, cont = 0;
	system("cls");
	menu();
	while(notas100[i] == '0') {
		cont++;
		i++;
	}
	texto(5,4,15);
	printf("Valor total: B$ %s",num);
	texto(53,5,79);
	printf("Notas:");
	texto(47,8,15);
	printf("Notas de B$ 100,00: ");
	if(atoi(notas100) != 0)
		for(int k = cont; k < strlen(notas100); k++)
			printf("%c",notas100[k]);	
	else
		printf("0");			
	texto(47,9,15);
	printf("Notas de B$ 50,00: %d",notas[0]);
	texto(47,10,15);
	printf("Notas de B$ 20,00: %d",notas[1]);
	texto(47,11,15);
	printf("Notas de B$ 10,00: %d",notas[2]);
	texto(47,12,15);
	printf("Notas de B$ 5,00: %d",notas[3]);
	texto(47,13,15);
	printf("Notas de B$ 2,00: %d",notas[4]);
	texto(53,16,79);
	printf("Moedas:");
	texto(47,19,15);
	printf("Moedas de B$ 1,00: %d",moedas[0]);
	texto(47,20,15);
	printf("Moedas de B$ 0,50: %d",moedas[1]);
	texto(47,21,15);
	printf("Moedas de B$ 0,25: %d",moedas[2]);
	texto(47,22,15);
	printf("Moedas de B$ 0,10: %d",moedas[3]);
	texto(47,23,15);
	printf("Moedas de B$ 0,01: %d",moedas[4]); 
	texto(6,27,15);
}

void separaString(char str[],int tam, int lin, int col) {
	int i, j = 0;
	for(i = 0; i < strlen(str); i++) {
		printf("%c",str[i]);
		j++;
		if(j == tam) {
			col++;
			texto(lin,col,15);
			j = 0;
		}
	}
}

void cheque(char nome[], int dia, int mes, int ano, char dec[], char vir[]) {
	char valor[200] = "Total: ";
	char enter;
	texto(6,5,112);
	printf("Nome do titular:");
	SetColor(15);
	printf(" ");
	puts(nome);
	texto(6,7,112);
	printf("Data:");
	SetColor(15);
	printf(" ");
	data(&dia,&mes,&ano);
	printf("%d/%d/%d",dia,mes,ano);
	texto(6,9,112);
	printf("Quantia:");
	SetColor(15);
	printf(" ");
	if(vir[0] == NULL)
		vir[0] = '0';
	if(vir[1] == NULL) {
		vir[1] = '0';
		vir[2] = NULL;	
	}
	printf("B$ %s,%s",dec,vir);
	texto(6,12,15);
	printaBits(dec,valor);
	printaBitCents(vir,valor); 
	separaString(valor,105,6,12);
	texto(6,16,79);
	printf("Pressione enter para continuar e calcular a quantidade de notas.");
	SetColor(15);
	enter = getch();
	while(enter != 13) {
		enter = getch();
	}
}

int main () {
	int Notas[5], Moedas[5], dia, mes, ano, aux;
	char num[50], num2[50], decimal[13], virgula[3], Nome[50], Senha[11], teste[100], notas100[11];
	menu();
	info(Nome,Senha,num);
	strcpy(num2,num);
	separa(num2, decimal, virgula);
	aux = ValidaNum(num, decimal);
	while(aux != 1) {
		info2(num2);
		strcpy(num,num2);
		separa(num2, decimal, virgula);
		aux = ValidaNum(num, decimal);
	}
	AdicionaZero(decimal);
	CalculaDinheiro(decimal,virgula,Notas,Moedas,notas100);
	cheque(Nome,dia,mes,ano,decimal,virgula);
	printaDinheiro(Notas,Moedas,num2,notas100);
}
