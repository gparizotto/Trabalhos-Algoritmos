#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#define cima 72
#define baixo 80
#define enter 13
#define esc 27
#define f1 59

int horasAlteradas, minutosAlterados, verificaAlteracao = 0;

typedef struct
{
	char nome[51], numero[31], CPF[13], sexo;
	float saldo;
	int dia, mes, ano, senha, verifica;
} INFO;

void gotoxy(int x, int y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int SetColor(char color)
{
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	return SetConsoleTextAttribute(h, color);
}

void Texto(int x, int y, int cor, char texto[])
{
	gotoxy(x, y);
	SetColor(cor);
	printf("%s", texto);
}

void Horario()
{
	int h, m, dia, mes, ano;
	struct tm *data_hora_atual;
	time_t segundos;
	time(&segundos);
	data_hora_atual = localtime(&segundos);
	dia = data_hora_atual->tm_mday;
	mes = data_hora_atual->tm_mon + 1;
	ano = data_hora_atual->tm_year + 1900;
	h = data_hora_atual->tm_hour;
	m = data_hora_atual->tm_min;
	Texto(90, 2, 95, "Horario:");
	SetColor(15);
	if (!verificaAlteracao)
		printf(" %d:%d", h, m);
	else
		printf(" %d:%d", horasAlteradas, minutosAlterados);
	Texto(15, 2, 95, "Data:");
	SetColor(15);
	printf(" %d/%d/%d", dia, mes, ano);
}

void LimpaTela()
{
	int i, j;
	SetColor(15);
	for (i = 0; i < 20; i++)
	{
		gotoxy(5, 5 + i);
		for (j = 0; j < 107; j++)
			printf(" ");
	}
}

void LimpaLinha(int x, int y)
{
	int i;
	gotoxy(x, y);
	SetColor(15);
	for (i = 0; i < 104; i++)
		printf(" ");
}

void menu1()
{
	int i, j;
	SetColor(95);
	system("cls");
	Horario();
	Texto(40, 2, 79, "Banco Central da Computacao -- BCC Unesp");
	SetColor(15);
	for (i = 0; i < 22; i++)
	{
		gotoxy(4, 4 + i);
		printf("|");
		if (i == 0 || i == 21)
		{
			for (j = 0; j < 109; j++)
				printf("-");
			printf("|");
		}
		else
		{
			for (j = 0; j < 109; j++)
				printf(" ");
			printf("|");
		}
	}
}

void menu2(int escolha)
{
	Horario();
	char opcoes[][48] = {"1 - Cadastrar nova conta                       ", "2 - Alterar informacoes da conta               ",
						 "3 - Excluir conta                              ", "4 - Consultar conta                            ",
						 "5 - Alterar informacoes das pastas e do sistema", "6 - Sair                                       "};
	int i;
	for (i = 0; i < 6; i++)
		Texto(42, 6 + i, 79, opcoes[i]);
	Texto(42, 6 + escolha, 96, opcoes[escolha]);
	Texto(10, 13, 95, "Digite F1 para obter ajuda");
}

void menu3(int escolha)
{
	Horario();
	char opcoes[][41] = {"1 - Buscar cliente por nome            ", "2 - Buscar cliente por CPF             ",
						 "3 - Buscar cliente por numero da conta "};
	int i;
	for (i = 0; i < 3; i++)
		Texto(40, 6 + i, 79, opcoes[i]);
	Texto(40, 6 + escolha, 96, opcoes[escolha]);
}

void menu4(int escolha)
{
	Horario();
	char opcoes[][50] = {"1 - Consultar arquivos da pasta ", "2 - Trocar nome de arquivos     ",
						 "3 - Remover arquivos            ", "4 - Criar nova pasta            ",
						 "5 - Alterar nome de pastas      ", "6 - Mudar um arquivo de pasta   ",
						 "7 - Alterar data e horario      ", "8 - Sair                        "};
	int i;
	for (i = 0; i < 8; i++)
		Texto(44, 6 + i, 79, opcoes[i]);
	Texto(44, 6 + escolha, 96, opcoes[escolha]);
}

void Ajuda(int escolha)
{
	Horario();
	char opcoes[][60] = {"Cadastrar dados pessoais, saldo e senha no banco        ", "Alterar/mudar informacoes incorretas da conta           ",
						 "Excluir conta permanentemente                           ", "Buscar conta no banco de dados                          ",
						 "Alterar pastas e outras informacoes como data e horario ", "Sair do programa                                         "};
	Texto(10, 16, 112, opcoes[escolha]);
}

int CarregaSetas1()
{
	int escolha = 0;
	char c;
	LimpaTela();
	menu2(escolha);
	do
	{
		c = getch();
		if (c <= 0)
		{
			c = getch();
			if (c == cima)
			{
				LimpaLinha(10, 16);
				if (escolha == 0)
					escolha = 5;
				else
					escolha--;
				menu2(escolha);
			}
			if (c == baixo)
			{
				LimpaLinha(10, 16);
				if (escolha == 5)
					escolha = 0;
				else
					escolha++;
				menu2(escolha);
			}
			if (c == f1)
			{
				Ajuda(escolha);
			}
		}
		else if (c == enter)
			return ++escolha;
	} while (c != esc);
}

int CarregaSetas2()
{
	int escolha = 0;
	char c;
	LimpaTela();
	menu3(escolha);
	do
	{
		c = getch();
		if (c <= 0)
		{
			c = getch();
			if (c == cima)
			{
				if (escolha == 0)
					escolha = 2;
				else
					escolha--;
				menu3(escolha);
			}
			if (c == baixo)
			{
				if (escolha == 2)
					escolha = 0;
				else
					escolha++;
				menu3(escolha);
			}
		}
		else if (c == enter)
			return ++escolha;
	} while (c != esc);
}

CarregaSetas3()
{
	int escolha = 0;
	char c;
	LimpaTela();
	menu4(escolha);
	do
	{
		c = getch();
		if (c <= 0)
		{
			c = getch();
			if (c == cima)
			{
				if (escolha == 0)
					escolha = 7;
				else
					escolha--;
				menu4(escolha);
			}
			if (c == baixo)
			{
				if (escolha == 7)
					escolha = 0;
				else
					escolha++;
				menu4(escolha);
			}
		}
		else if (c == enter)
			return ++escolha;
	} while (c != esc);
}

void CadastraConta(INFO info, FILE *arq)
{
	LimpaTela();
	fflush(stdin);
	Texto(6, 5, 15, "Digite seu nome: ");
	fgets(info.nome, 50, stdin);
	fflush(stdin);
	Texto(6, 6, 15, "Digite seu CPF (somente numeros): ");
	fgets(info.CPF, 12, stdin);
	fflush(stdin);
	Texto(6, 7, 15, "Digite o numero da conta: ");
	fgets(info.numero, 30, stdin);
	fflush(stdin);
	Texto(6, 8, 15, "Digite seu sexo [m/f]: ");
	scanf("%s", &info.sexo);
	Texto(6, 9, 15, "Digite o dia, mes e ano do seu nascimento (formato XX/XX/XX): ");
	scanf("%d/%d/%d", &info.dia, &info.mes, &info.ano);
	Texto(6, 10, 15, "Crie uma senha para a sua conta com ate 4 algarismos: ");
	scanf("%d", &info.senha);
	Texto(6, 11, 15, "Digite o saldo da conta: ");
	scanf("%f", &info.saldo);
	info.verifica = 1;
	fwrite(&info, sizeof(info), 1, arq);
	fflush(stdin);
	fclose(arq);
}

int AlteraConta(INFO info, FILE *arq)
{
	char nome[51], CPF[12], numero[31], c;
	int opcao, verifica = 1, senha, tentativas = 4;
	opcao = CarregaSetas2();
	switch (opcao)
	{
	case 1:
		LimpaTela();
		fflush(stdin);
		Texto(6, 5, 15, "Digite o nome do cliente: ");
		fgets(nome, 50, stdin);
		LimpaTela();
		while (fread(&info, sizeof(info), 1, arq) && verifica)
			if (strcmp(nome, info.nome) == 0)
			{
				Texto(6, 5, 15, "Digite a senha: ");
				scanf("%d", &senha);
				while (senha != info.senha)
				{
					tentativas--;
					LimpaLinha(6, 5);
					Texto(6, 5, 15, "Senha incorreta, digite novamente");
					printf(" (%d tentativas restantes): ", tentativas);
					scanf("%d", &senha);
					if (tentativas == 1)
						return 0;
				}
				fseek(arq, -sizeof(info), SEEK_CUR);
				fflush(stdin);
				Texto(6, 5, 15, "Digite seu nome: ");
				fgets(info.nome, 50, stdin);
				fflush(stdin);
				Texto(6, 6, 15, "Digite seu CPF (somente numeros): ");
				fgets(info.CPF, 12, stdin);
				fflush(stdin);
				Texto(6, 7, 15, "Digite o numero da conta: ");
				fgets(info.numero, 30, stdin);
				fflush(stdin);
				Texto(6, 8, 15, "Digite seu sexo [m/f]: ");
				scanf("%s", &info.sexo);
				Texto(6, 9, 15, "Digite o dia, mes e ano do seu nascimento (formato XX/XX/XX): ");
				scanf("%d/%d/%d", &info.dia, &info.mes, &info.ano);
				Texto(6, 10, 15, "Crie uma senha para a sua conta com ate 4 algarismos: ");
				scanf("%d", &info.senha);
				Texto(6, 11, 15, "Digite o saldo da conta: ");
				scanf("%f", &info.saldo);
				info.verifica = 1;
				fwrite(&info, sizeof(info), 1, arq);
				verifica = 0;
				LimpaTela();
			}
		if (verifica)
			Texto(50, 5, 96, " Nome nao foi encontrado ");
		else
			Texto(50, 5, 96, " Dados alterados com sucesso ");
		Texto(50, 12, 96, " Digite enter para continuar ");
		while ((c = getch()) != enter)
			;
		break;
	case 2:
		LimpaTela();
		fflush(stdin);
		Texto(6, 5, 15, "Digite o CPF do cliente: ");
		fgets(CPF, 12, stdin);
		LimpaTela();
		while (fread(&info, sizeof(info), 1, arq) && verifica)
			if (strcmp(CPF, info.CPF) == 0)
			{
				Texto(6, 5, 15, "Digite a senha: ");
				scanf("%d", &senha);
				while (senha != info.senha)
				{
					tentativas--;
					LimpaLinha(6, 5);
					Texto(6, 5, 15, "Senha incorreta, digite novamente");
					printf(" (%d tentativas restantes): ", tentativas);
					scanf("%d", &senha);
					if (tentativas == 1)
						return 0;
				}
				fseek(arq, -sizeof(info), SEEK_CUR);
				fflush(stdin);
				Texto(6, 5, 15, "Digite seu nome: ");
				fgets(info.nome, 50, stdin);
				fflush(stdin);
				Texto(6, 6, 15, "Digite seu CPF (somente numeros): ");
				fgets(info.CPF, 12, stdin);
				fflush(stdin);
				Texto(6, 7, 15, "Digite o numero da conta: ");
				fgets(info.numero, 30, stdin);
				fflush(stdin);
				Texto(6, 8, 15, "Digite seu sexo [m/f]: ");
				scanf("%s", &info.sexo);
				Texto(6, 9, 15, "Digite o dia, mes e ano do seu nascimento (formato XX/XX/XX): ");
				scanf("%d/%d/%d", &info.dia, &info.mes, &info.ano);
				Texto(6, 10, 15, "Crie uma senha para a sua conta com ate 4 algarismos: ");
				scanf("%d", &info.senha);
				Texto(6, 11, 15, "Digite o saldo da conta: ");
				scanf("%f", &info.saldo);
				info.verifica = 1;
				fwrite(&info, sizeof(info), 1, arq);
				verifica = 0;
				LimpaTela();
			}
		if (verifica)
			Texto(50, 5, 96, " CPF nao foi encontrado ");
		else
			Texto(50, 5, 96, " Dados alterados com sucesso ");
		Texto(50, 12, 96, " Digite enter para continuar ");
		while ((c = getch()) != enter)
			;
		break;
	case 3:
		LimpaTela();
		fflush(stdin);
		Texto(6, 5, 15, "Digite o numero da conta do cliente: ");
		fgets(numero, 30, stdin);
		LimpaTela();
		while (fread(&info, sizeof(info), 1, arq) && verifica)
			if (strcmp(numero, info.numero) == 0)
			{
				Texto(6, 5, 15, "Digite a senha: ");
				scanf("%d", &senha);
				while (senha != info.senha)
				{
					tentativas--;
					LimpaLinha(6, 5);
					Texto(6, 5, 15, "Senha incorreta, digite novamente");
					printf(" (%d tentativas restantes): ", tentativas);
					scanf("%d", &senha);
					if (tentativas == 1)
						return 0;
				}
				fseek(arq, -sizeof(info), SEEK_CUR);
				fflush(stdin);
				Texto(6, 5, 15, "Digite seu nome: ");
				fgets(info.nome, 50, stdin);
				fflush(stdin);
				Texto(6, 6, 15, "Digite seu CPF (somente numeros): ");
				fgets(info.CPF, 12, stdin);
				fflush(stdin);
				Texto(6, 7, 15, "Digite o numero da conta: ");
				fgets(info.numero, 30, stdin);
				fflush(stdin);
				Texto(6, 8, 15, "Digite seu sexo [m/f]: ");
				scanf("%s", &info.sexo);
				Texto(6, 9, 15, "Digite o dia, mes e ano do seu nascimento (formato XX/XX/XX): ");
				scanf("%d/%d/%d", &info.dia, &info.mes, &info.ano);
				Texto(6, 10, 15, "Crie uma senha para a sua conta com ate 4 algarismos: ");
				scanf("%d", &info.senha);
				Texto(6, 11, 15, "Digite o saldo da conta: ");
				scanf("%f", &info.saldo);
				info.verifica = 1;
				fwrite(&info, sizeof(info), 1, arq);
				verifica = 0;
				LimpaTela();
			}
		if (verifica)
			Texto(50, 5, 96, " Numero da conta nao foi encontrado ");
		else
			Texto(50, 5, 96, " Dados alterados com sucesso ");
		Texto(50, 12, 96, " Digite enter para continuar ");
		while ((c = getch()) != enter)
			;
		break;
	}
	fclose(arq);
}

void RemoveConta(INFO info, FILE *arq)
{
	char nome[51], CPF[12], numero[31], c;
	int opcao, verifica = 1, senha, tentativas = 4;
	opcao = CarregaSetas2();
	switch (opcao)
	{
	case 1:
		LimpaTela();
		fflush(stdin);
		Texto(6, 5, 15, "Digite o nome do cliente: ");
		fgets(nome, 50, stdin);
		LimpaTela();
		while (fread(&info, sizeof(info), 1, arq) && verifica)
			if (strcmp(nome, info.nome) == 0)
			{
				Texto(6, 5, 15, "Digite a senha: ");
				scanf("%d", &senha);
				while (senha != info.senha)
				{
					tentativas--;
					LimpaLinha(6, 5);
					Texto(6, 5, 15, "Senha incorreta, digite novamente");
					printf(" (%d tentativas restantes): ", tentativas);
					scanf("%d", &senha);
					if (tentativas == 1)
						return 0;
				}
				fseek(arq, -sizeof(info), SEEK_CUR);
				info.verifica = 0;
				fwrite(&info, sizeof(info), 1, arq);
				verifica = 0;
			}
		if (verifica)
			Texto(50, 5, 96, " Nome nao foi encontrado ");
		else
			Texto(50, 5, 96, " Cliente removido com sucesso ");
		Texto(50, 12, 96, " Digite enter para continuar ");
		while ((c = getch()) != enter)
			;
		break;
	case 2:
		LimpaTela();
		fflush(stdin);
		Texto(6, 5, 15, "Digite o CPF do cliente: ");
		fgets(CPF, 12, stdin);
		LimpaTela();
		while (fread(&info, sizeof(info), 1, arq) && verifica)
			if (strcmp(CPF, info.CPF) == 0)
			{
				Texto(6, 5, 15, "Digite a senha: ");
				scanf("%d", &senha);
				while (senha != info.senha)
				{
					tentativas--;
					LimpaLinha(6, 5);
					Texto(6, 5, 15, "Senha incorreta, digite novamente");
					printf(" (%d tentativas restantes): ", tentativas);
					scanf("%d", &senha);
					if (tentativas == 1)
						return 0;
				}
				fseek(arq, -sizeof(info), SEEK_CUR);
				info.verifica = 0;
				fwrite(&info, sizeof(info), 1, arq);
				verifica = 0;
			}
		if (verifica)
			Texto(50, 5, 96, " Nome nao foi encontrado ");
		else
			Texto(50, 5, 96, " Cliente removido com sucesso ");
		Texto(50, 12, 96, " Digite enter para continuar ");
		while ((c = getch()) != enter)
			;
		break;
	case 3:
		LimpaTela();
		fflush(stdin);
		Texto(6, 5, 15, "Digite o numero da conta do cliente: ");
		fgets(numero, 30, stdin);
		LimpaTela();
		while (fread(&info, sizeof(info), 1, arq) && verifica)
			if (strcmp(numero, info.numero) == 0)
			{
				Texto(6, 5, 15, "Digite a senha: ");
				scanf("%d", &senha);
				while (senha != info.senha)
				{
					tentativas--;
					LimpaLinha(6, 5);
					Texto(6, 5, 15, "Senha incorreta, digite novamente");
					printf(" (%d tentativas restantes): ", tentativas);
					scanf("%d", &senha);
					if (tentativas == 1)
						return 0;
				}
				fseek(arq, -sizeof(info), SEEK_CUR);
				info.verifica = 0;
				fwrite(&info, sizeof(info), 1, arq);
				verifica = 0;
			}
		if (verifica)
			Texto(50, 5, 96, " Nome nao foi encontrado ");
		else
			Texto(50, 5, 96, " Cliente removido com sucesso ");
		Texto(50, 12, 96, " Digite enter para continuar ");
		while ((c = getch()) != enter)
			;
		break;
	}
	fclose(arq);
}

void ConsultaConta(INFO info, FILE *arq)
{
	char nome[51], CPF[12], numero[31], c;
	int opcao, verifica = 1;
	opcao = CarregaSetas2();
	switch (opcao)
	{
	case 1:
		LimpaTela();
		fflush(stdin);
		Texto(6, 5, 15, "Digite o nome do cliente: ");
		fgets(nome, 50, stdin);
		LimpaTela();
		while (fread(&info, sizeof(info), 1, arq))
			if (info.verifica)
				if (strcmp(nome, info.nome) == 0)
				{
					verifica = 0;
					Texto(50, 5, 96, " Nome: ");
					printf("%s", info.nome);
					Texto(50, 6, 96, " Numero da conta: ");
					printf("%s", info.numero);
					Texto(50, 7, 96, " CPF: ");
					printf("%s", info.CPF);
					Texto(50, 8, 96, " Sexo: ");
					printf("%c", info.sexo);
					Texto(50, 9, 96, " Data do Nascimento: ");
					printf("%d/%d/%d", info.dia, info.mes, info.ano);
					Texto(50, 10, 96, " Saldo: ");
					printf("R$ %.2f", info.saldo);
					Texto(50, 11, 96, " Verifica: ");
					printf(" %d", info.verifica);
				}
		if (verifica)
			Texto(50, 5, 96, " Nome nao foi encontrado ");
		Texto(50, 12, 96, " Digite enter para continuar ");
		while ((c = getch()) != enter)
			;
		break;
	case 2:
		LimpaTela();
		fflush(stdin);
		Texto(6, 5, 15, "Digite o CPF do cliente: ");
		fgets(CPF, 12, stdin);
		LimpaTela();
		while (fread(&info, sizeof(info), 1, arq))
			if (info.verifica)
				if (strcmp(info.CPF, CPF) == 0)
				{
					verifica = 0;
					Texto(50, 5, 96, " Nome: ");
					printf("%s ", info.nome);
					Texto(50, 6, 96, " Numero da conta: ");
					printf("%s ", info.numero);
					Texto(50, 7, 96, " CPF: ");
					printf("%s ", info.CPF);
					Texto(50, 8, 96, " Sexo: ");
					printf("%c ", info.sexo);
					Texto(50, 9, 96, " Data do Nascimento: ");
					printf("%d/%d/%d ", info.dia, info.mes, info.ano);
					Texto(50, 10, 96, " Saldo: ");
					printf("R$ %.2f ", info.saldo);
				}
		if (verifica)
			Texto(50, 5, 96, " CPF nao foi encontrado ");
		Texto(50, 12, 96, " Digite enter para continuar ");
		while ((c = getch()) != enter)
			;
		break;
	case 3:
		LimpaTela();
		fflush(stdin);
		Texto(6, 5, 15, "Digite o numero da conta do cliente: ");
		fgets(numero, 11, stdin);
		LimpaTela();
		while (fread(&info, sizeof(info), 1, arq))
			if (info.verifica)
				if (strcmp(info.numero, numero) == 0)
				{
					verifica = 0;
					Texto(50, 5, 96, " Nome: ");
					printf("%s ", info.nome);
					Texto(50, 6, 96, " Numero da conta: ");
					printf("%s ", info.numero);
					Texto(50, 7, 96, " CPF: ");
					printf("%s ", info.CPF);
					Texto(50, 8, 96, " Sexo: ");
					printf("%c ", info.sexo);
					Texto(50, 9, 96, " Data do Nascimento: ");
					printf("%d/%d/%d ", info.dia, info.mes, info.ano);
					Texto(50, 10, 96, " Saldo: ");
					printf("R$ %.2f ", info.saldo);
				}
		if (verifica)
			Texto(50, 5, 96, " numero da conta nao foi encontrado ");
		Texto(50, 12, 96, " Digite enter para continuar ");
		while ((c = getch()) != enter)
			;
		break;
	}
	fclose(arq);
}

void ConsultarArquivosNaPasta()
{
	char c = 0;
	SetColor(15);
	system("cls");
	gotoxy(5, 5);
	system("dir");
	printf("\n\n");
	SetColor(95);
	printf("Digite enter para continuar: ");
	while (c != enter)
		c = getch();
	menu1();
}

void TrocarNomeArquivos()
{
	char c = 0, aux[50] = "rename", nomeAnterior[20], novoNome[20];
	SetColor(15);
	system("cls");
	gotoxy(5, 5);
	system("dir");
	printf("\n\n");
	SetColor(95);
	printf("Digite o nome do arquivo que deseja renomear:");
	SetColor(15);
	scanf("%s", nomeAnterior);
	printf("\n");
	SetColor(95);
	printf("Digite o novo nome do arquivo:");
	SetColor(15);
	scanf("%s", novoNome);
	strcat(aux, " ");
	strcat(aux, nomeAnterior);
	strcat(aux, " ");
	strcat(aux, novoNome);
	system(aux);
	system("cls");
	system("dir");
	printf("\n\n");
	SetColor(95);
	printf("Digite enter para continuar: ");
	while (c != enter)
		c = getch();
	menu1();
}

void RemoverArquivos()
{
	char *c, del[50] = "del ", nomeArq[20];
	SetColor(15);
	system("cls");
	gotoxy(5, 5);
	system("dir");
	printf("\n\n");
	SetColor(95);
	printf("Digite o nome do arquivo que deseja remover:");
	SetColor(15);
	scanf("%s", nomeArq);
	strcat(del, nomeArq);
	system(del);
	system("cls");
	system("dir");
	printf("\n\n");
	SetColor(95);
	printf("Digite enter para continuar: ");
	while (c != enter)
		c = getch();
	menu1();
}

void CriarPasta()
{
	char *c, mkdir[50] = "mkdir ", nomePasta[20];
	SetColor(15);
	system("cls");
	gotoxy(5, 5);
	system("dir");
	printf("\n\n");
	SetColor(95);
	printf("Digite o nome da nova pasta a ser criada:");
	SetColor(15);
	scanf("%s", nomePasta);
	strcat(mkdir, nomePasta);
	system(mkdir);
	system("cls");
	system("dir");
	printf("\n\n");
	SetColor(95);
	printf("Digite enter para continuar: ");
	while (c != enter)
		c = getch();
	menu1();
}

void AlterarNomeDePastas()
{
	char *c = '0', rename[50] = "rename ", cdentrar[50] = "cd ", nomePasta[20], nomeantigo[50], nomenovo[50];
	SetColor(15);
	system("cls");
	gotoxy(5, 5);
	system("dir");
	printf("\n\nInstrucoes: \n");
	printf("Digite 'm' para mudar entre uma pasta/diretorio\n\n");
	printf("Digite 'r' para renomear uma pasta/diretorio\n\n");
	printf("Resposta: ");
	c = getch();
	while (tolower(c) != 'e' && tolower(c) != 'm')
		c = getch();
	if (c == 'm')
	{
		system("cls");
		SetColor(95);
		printf("Instrucoes: \n\n");
		printf("1 - Para entrar em uma pasta/diretorio, digite 'cd <nome_da_pasta>'\n");
		printf("2 - Para voltar para o diretorio anterior, digite 'cd..'\n");
		printf("Para se localicar, utilize o campo C:: , sendo\n");
		printf("que a ultima palavra representa o diretorio em que voce esta atualmente\n");
		printf("3 - Para renomear uma pasta, digite 'rename <nome_da_pasta> <nome_novo_da_pasta>'\n");
		printf("4 - Para verificar os itens presentes no diretorio em que voce esta, digite 'dir'");
		printf("5 - Para sair do cmd e voltar ao programa, digite 'exit'\n\n");
		SetColor(15);
		system("cmd");
	}
	else
	{
		printf("\nDigite o nome da pasta/diretorio que deseja renomear: ");
		scanf("%s", nomeantigo);
		printf("\nDigite o novo nome da pasta/diretorio: ");
		scanf("%s", nomenovo);
		strcat(rename, nomeantigo);
		strcat(rename, " ");
		strcat(rename, nomenovo);
		system(nomenovo);
	}
	menu1();
}

void MudarArquivoDePasta()
{
	char *c = '0', move[50] = "move ", nomeArquivo[50], nomePasta[50];
	SetColor(15);
	system("cls");
	gotoxy(5, 5);
	system("dir");
	SetColor(95);
	printf("\nDigite o nome do arquivo que deseja trocar de pasta: ");
	SetColor(15);
	scanf("%s", nomeArquivo);
	SetColor(95);
	printf("\nDigite o nome da pasta que o arquivo sera alocado: ");
	SetColor(15);
	scanf("%s", nomePasta);
	strcat(move, nomeArquivo);
	strcat(move, " ");
	strcat(move, nomePasta);
	system(move);
	menu1();
}

void AlterarDataEHorario()
{
	int horas, minutos;
	SetColor(15);
	system("cls");
	SetColor(95);
	printf("\nDigite a nova hora do sistema (somente horas): ");
	SetColor(15);
	scanf("%d", &horasAlteradas);
	SetColor(95);
	printf("\nDigite a nova hora do sistema(somente minutos): ");
	SetColor(15);
	scanf("%d", &minutosAlterados);
	verificaAlteracao = 1;
	menu1();
}

void AlteraPastasEData()
{
	int opcao;
	do
	{
		opcao = CarregaSetas3();
		switch (opcao)
		{
		case 1:
			ConsultarArquivosNaPasta();
			break;
		case 2:
			TrocarNomeArquivos();
			break;
		case 3:
			RemoverArquivos();
			break;
		case 4:
			CriarPasta();
			break;
		case 5:
			AlterarNomeDePastas();
			break;
		case 6:
			MudarArquivoDePasta();
			break;
		case 7:
			AlterarDataEHorario();
			break;
		}
	} while (opcao != 8);
}

void ExcluiDadosFisicamente(INFO info, FILE *arq, FILE *arq2, char nome[])
{
	while (fread(&info, sizeof(info), 1, arq))
		if (info.verifica)
			fwrite(&info, sizeof(info), 1, arq2);
	fclose(arq);
	fclose(arq2);
	remove(nome);
	rename("prov.dat", nome);
}

int main()
{
	char nome[15], escolha;
	int opcao;
	INFO info;
	FILE *arq, *arq2;
	menu1();
	gotoxy(5, 5);
	printf("Digite o nome do arquivo que deseja abrir ou criar (sem .dat): ");
	scanf("%s", nome);
	strcat(nome, ".dat");
	arq = fopen(nome, "a+b");
	fclose(arq);
	do
	{
		opcao = CarregaSetas1();
		switch (opcao)
		{
		case 1:
			arq = fopen(nome, "ab");
			CadastraConta(info, arq);
			break;
		case 2:
			arq = fopen(nome, "r+b");
			AlteraConta(info, arq);
			break;
		case 3:
			arq = fopen(nome, "r+b");
			RemoveConta(info, arq);
			break;
		case 4:
			arq = fopen(nome, "rb");
			ConsultaConta(info, arq);
			break;
		case 5:
			AlteraPastasEData();
			break;
		case 6:
			arq = fopen(nome, "rb");
			arq2 = fopen("prov.dat", "wb");
			ExcluiDadosFisicamente(info, arq, arq2, nome);
			break;
		}
	} while (opcao != 6);
	return 0;
}