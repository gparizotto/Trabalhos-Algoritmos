//Trabalho 2 Algoritmos I -- Gabriel Zanforlin Parizotto
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define baixo 80
#define cima 72
#define esc 27
#define enter 13
#define F1 59
#define esquerda 75
#define direita 77
#define max 10
//-------------------------------------------------------------------------
void gotoxy (int x, int y) {
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//-------------------------------------------------------------------------
int SetColor (char color) {
  HANDLE h;
  h = GetStdHandle (STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute (h,color);
}
//-------------------------------------------------------------------------
void escreveTexto (int x, int y, char texto[], int cor){
  SetColor (cor);
  gotoxy (y,x);
  printf ("%s",texto);
}
//-------------------------------------------------------------------------
void menu (int op) {
	int i,j;
	char vet[][100] = 
	{"1. Trocar os elementos da linha X pela linha Y",
	 "2. Trocar os elementos da coluna X pela coluna Y",
	 "3. Trocar os elementos da diagonal principal pelos elementos da diagonal secundaria",
	 "4. Verificar se uma matriz eh simetrica",
	 "5. Verificar se uma matriz eh um quadrado magico",
	 "6. Verificar se uma matriz eh um quadrado latino",
	 "7. Verificar se uma matriz eh matriz de permutacao"};
					   
	char info[][150] = 
	{"1. Troca os elementos da linha selecionada para outra linha selecionada                                     ",
	 "2. Troca os elementos da coluna selecionada para outra coluna selecionada                                   ",
	 "3. Troca elementos da diagonal principal da matriz pelos da diagonal secundaria                             ",
	 "4. Matriz simetrica: Matriz e igual a sua transposta                                                        ",
	 "5. Quadrado magico: soma dos elementos da diagonal principal, secundaria, linhas e colunas forem iguais     ",
	 "6. Quadrado latino: os elementos de cada linha e coluna sao permutacoes dos naturais ate a ordem da matriz  ",
	 "7. Matriz de permutacao: em cada linha e coluna deve haver n-1 elementos nulos e 1 elemento igual a 1       "};		   
					   
		escreveTexto(2,50,"Programa de Matrizes",79);
		for(i=0;i<7;i++) {
			escreveTexto (5+i, 10, vet[i], 10);
			escreveTexto ( 13, 10, "AJUDA:", 13);
	  		escreveTexto (14, 10, info[op-1], 15);
		}
		escreveTexto (4+op, 10, vet[op-1], 5);	
		
		escreveTexto (22, 10, "INFO: utilize as SETAS e ENTER para escolher as opcoes,e ESC para sair",95);
}
//-------------------------------------------------------------------------
void menu2 (int aux) {
	int i;
	char vet[][5] = {"SIM", "NAO"};
	escreveTexto (17,10,"ESCOLHER?",79);
	for (i = 0; i < 2; i++)
		escreveTexto (18,10+10*i,vet[i],15);
	if(aux < 3)	
		escreveTexto (18,10+10*(aux-1),vet[aux-1],79);
	SetColor (15);		
}
//-------------------------------------------------------------------------
void leMatriz (int mat[max][max],int linhas,int colunas,int x,int y,int cor) {
	int i, j, y2 = y;
	for (i = 0; i < linhas; i++)
		for(j = 0; j < colunas; j++) {
			gotoxy (x,y);
			SetColor (cor);
			printf ("Elemento linha %d, coluna %d: ",i+1,j+1);
			SetColor (15);
			scanf ("%d",&mat[i][j]);
			y += 2;
			if(y >= 27) {
				system ("cls");
				y = 5;
			}
				
		}
}
//-------------------------------------------------------------------------
void info (int num, int mat[max][max], int *linhas, int *colunas, int *ordem) {
	int i = 11;
	if (num == 1) {
		system("cls");
		escreveTexto (10, 3, "Digite o numero de linhas: ",15);
		scanf("%d", &*linhas);
		while ( *linhas < 1 || *linhas > 10) {
			escreveTexto (i, 3, "Valor invalido, Digite o numero de linhas (entre 1 e 10): ",15);
			scanf("%d",& *linhas);
			i++;
		}
		i = 11;
		system ("cls");
		escreveTexto (10, 3, "Digite o numero de colunas: ",15);
		scanf ("%d", &*colunas);
		while ( *colunas < 1 || *colunas > 10) {
			escreveTexto (i, 3, "Valor invalido, Digite o numero de colunas (entre 1 e 10): ",15);
			scanf("%d",& *colunas);
			i++;
		}
		system ("cls");
		leMatriz (mat, *linhas, *colunas, 12, 3, 15);
		system ("cls");
	}
	if (num == 2) {
		system("cls");
		escreveTexto (10, 3, "Digite a ordem da matriz: ",15);
		scanf("%d", &*ordem);
		while (*ordem < 1 || *ordem > 10) {
			escreveTexto (i, 3, "Valor invalido, Digite a ordem da matriz (entre 1 e 10): ",15);
			scanf("%d",& *ordem);
			i++;
		}
		system("cls");
		leMatriz(mat, *ordem, *ordem, 12, 3, 15);
		system("cls");
	}
}
//-------------------------------------------------------------------------
void info2 (int *temp) {
	escreveTexto(1,30,"Digite ENTER para executar a mesma funcao ou SETAS para voltar ao menu",95);
	SetColor(15);
	*temp = 0;
}
//-------------------------------------------------------------------------
void igualaMatriz (int mat[max][max], int matAux[max][max], int linhas, int colunas) {
	int i, j;
	for (i = 0; i < linhas; i++)
		for ( j = 0; j < colunas; j++)
			matAux[i][j] = mat[i][j];
}
//-------------------------------------------------------------------------
void trocaLinhaXPorLinhaY (int mat[max][max], int linhas, int colunas, int x, int y) {
	int i, j, aux;
	x--;
	y--;
	for (i = 0; i < colunas; i++) {
		aux = mat[x][i];
		mat[x][i] = mat[y][i];
		mat[y][i] = aux;
	}
}
//--------------------------------------------------------------------------------------
void trocaColunaXPorColunaY(int mat[max][max],int linhas,int colunas,int x,int y) {
	int i,j,aux;
	x--;
	y--;
	for( i = 0; i < linhas; i++) {
		aux = mat[i][x];
		mat[i][x] = mat[i][y];
		mat[i][y] = aux;
	}
}
//--------------------------------------------------------------------------------------
void trocaPrincipalSecundaria(int mat[max][max], int ordem) {
	int i , j, aux, lin = 0, col = ordem-1;
	for (i = 0; i < ordem; i++)
		for (j = 0; j < ordem; j++) {
			if (i == j) {
				aux = mat[i][j];
				mat[i][j] = mat[lin][col];
				mat[lin][col ] =aux;
				lin++;
				col--;
			}
		}
}
//--------------------------------------------------------------------------------------
int Simetrica (int mat[max][max], int transposta[max][max] ,int ordem) {
	int i, j ,aux = 0;
	for ( i = 0; i < ordem; i++)
		for (j = 0; j < ordem; j++) {
			transposta[j][i] = mat[i][j];
		}
			
	for (i = 0; i < ordem; i++)
		for(j = 0; j < ordem; j++)
			if (transposta[i][j] != mat[j][i])
				aux++;
	if(aux)
		return 0;
	else
		return 1;				
}
//--------------------------------------------------------------------------------------
int QuadradoMagico (int mat[max][max], int ordem, int *soma1) {
	int i, j, soma2 = 0, temp = ordem-1, cont = 0;
	*soma1 = 0;
	for (i = 0; i < ordem; i++)
		for (j = 0; j < ordem; j++)
			if (i == j) {
				*soma1 += mat[i][j];
				soma2 += mat[i][temp];
				temp--;		
			}
	if (*soma1 != soma2)
		cont++;
	soma2 = 0;	
				
	for (i = 0; i < ordem; i++) {
		for (j = 0; j < ordem; j++) 
			soma2 += mat[i][j];
		if(*soma1 != soma2)
			cont++;
		soma2 = 0;	
	}
	
	for (j = 0; j < ordem; j++) {
		for (i = 0; i < ordem; i++)
			soma2 += mat[i][j];
		if (*soma1 != soma2)
			cont++;
		soma2 = 0;		
	}
	
	if(cont)
		return 0;
	else
		return 1;	
}
//--------------------------------------------------------------------------------------
int QuadradoLatino (int mat[max][max], int ordem) {
	int i, j, k, aux1, aux2, temp = 1;
	for (i = 0; i < ordem && temp; i++) {
		for (k = 1; k <= ordem && temp;k++) {
			aux1 = aux2 = 0;
			for (j = 0; j < ordem;j++) 
				if (mat[i][j] == k)
					aux1++;
			for (j = 0; j < ordem; j++) 
				if (mat[j][i] == k)		
					aux2++;
			if (aux1 !=1 || aux2 != 1)	
				return 0;		
		}
	}
	return 1;		
}
//--------------------------------------------------------------------------------------
int MatrizDePermutacao (int mat[max][max], int ordem) {
	int i, j, n = ordem-1, cont1 = 0, cont2 = 0;
	for (i = 0; i < ordem; i++) {
		for (j = 0; j < ordem; j++) {
			if (mat[i][j] == 0)
				cont1++;
			if (mat[i][j] == 1)
				cont2++;	
		}
		if(cont1 != n || cont2 != 1)
			return 0;
		cont1 = cont2 = 0;		
		for (j = 0; j < ordem; j++) {
			if (mat[j][i] == 0)
				cont1++;
			if (mat[j][i] == 1)
				cont2++;	
		}
		if(cont1 != n || cont2 != 1)
			return 0;	
		cont1 = cont2 = 0;	
	}
	return 1;
}
//--------------------------------------------------------------------------------------
void printMatriz(int mat[max][max],int linhas,int colunas,int x,int y) {
	int i,j;
	SetColor(79);
	gotoxy(x,y);
	y+=2;
	SetColor(15);
	for(i=0;i<linhas;i++) {
		gotoxy(x,y);
		printf("|");
		y++;
		for(j=0;j<colunas;j++)
			printf("%4d  ",mat[i][j]);	
		printf(" |");		
	}
}
//--------------------------------------------------------------------------------------
int main(){
    int op,aux,linhas,colunas,mat[max][max],matAux[max][max],x,y,ordem,verifica,soma,temp = 1,i = 6;
    char t;
    op = 1;
    aux = 3;
    menu (op);
    menu2 (aux);
    do {
  		t = getch();
  		if (temp == 0 && t != enter) {
  			system("cls");
  			menu(op);
  			temp = 1;
		  }
		if (t <= 0){
	 		t = getch();
	  		if (t == baixo){
	  			aux = 3;
	   			if (op != 7) 
			   		op++;
				else 
					op = 1;
				menu (op);
				menu2 (aux);
	  		}
	  		else if (t == cima) {
	  			aux = 3;
	  			if (op != 1) 
					op--;
				else 
					op = 7;
				menu (op);
				menu2 (aux);
	  		}
	  		else if (t == direita) {
	  			if(aux < 2)
        			aux++;
        		else	
        			aux=1;
        		menu2(aux);	
			}
			else if (t == esquerda) {
				if(aux != 1)
					aux--;
				else
					aux=2;
				menu2(aux);
			} 
    	}
    	else {
    		if (t == enter) {
    			if (aux == 1) {
    				if (op == 1) {
						info (1, mat, &linhas, &colunas, &ordem);
						if (linhas >= 2) {
							escreveTexto (5,3,"Digite a linha X: ",15);
							scanf("%d",&x);
							while (x < 1 || x > linhas) {
								escreveTexto (i,3,"Digite um valor valido para a linha X: ",15);
								scanf("%d",&x);
								i+=2;
							}
							system("cls");
							i =6;
							escreveTexto (5,3,"Digite a linha Y: ",15);
							scanf("%d",&y);
							while (y < 1 || y > linhas) {
								escreveTexto (i,3,"Digite a linha Y (valores de 1 a 10): ",15);
								scanf("%d",&y);
								i+=2;
							}
							system("cls");
							igualaMatriz (mat,matAux,linhas,colunas);
							trocaLinhaXPorLinhaY (matAux,linhas,colunas,x,y);
							escreveTexto(5,5,"MATRIZ ORIGINAL",79);
							printMatriz(mat,linhas,colunas,5,5);
							escreveTexto(5,55,"MATRIZ GERADA",79);
							printMatriz(matAux,linhas,colunas,55,5);
							info2(&temp);
							SetColor(15);
						}
						else {
							escreveTexto(5,3,"Numero de linhas insuficientes",79);
							temp = 0;
							SetColor(15);
						}
					}
					else if (op == 2) {
						info (1, mat, &linhas, &colunas, &ordem);
						i = 6;
						if (colunas >= 2) {
							escreveTexto (5,3,"Digite a coluna X: ",15);
							scanf("%d",&x);
							while (x < 1 || x > colunas) {
								escreveTexto (i,3,"Digite a coluna X (valores de 1 a 10): ",15);
								scanf("%d",&x);
								i+=2;
							}
							system("cls");
							i = 6;
							escreveTexto (5,3,"Digite a coluna Y: ",15);
							scanf("%d",&y);
							while (y < 1 || y > colunas) {
								escreveTexto (i,3,"Digite a coluna Y (valores de 1 a 10): ",15);
								scanf("%d",&y);
								i+=2;
							}
							system("cls");
							igualaMatriz (mat,matAux,linhas,colunas);
							trocaColunaXPorColunaY (matAux,linhas,colunas,x,y);
							escreveTexto(5,5,"MATRIZ ORIGINAL",79);
							printMatriz(mat,linhas,colunas,5,5);
							escreveTexto(5,55,"MATRIZ GERADA",79);
							printMatriz(matAux,linhas,colunas,55,5);
							info2(&temp);
							SetColor(15);
						}
						else {
							escreveTexto(5,3,"Numero de colunas insuficientes",79);
							temp = 0;
							SetColor(15);
						}
					}
					else if (op == 3) {
						info (2, mat, &linhas, &colunas, &ordem);
						igualaMatriz (mat,matAux,ordem,ordem);
						trocaPrincipalSecundaria (matAux,ordem);
						escreveTexto(5,5,"MATRIZ ORIGINAL",79);
						printMatriz(mat,ordem,ordem,5,5);
						escreveTexto(5,55,"MATRIZ GERADA",79);
						printMatriz(matAux,ordem,ordem,55,5);
						info2(&temp);
						SetColor(15);
					}
					else if (op == 4) {
						info (2, mat, &linhas, &colunas, &ordem);
						verifica = Simetrica (mat,matAux,ordem);
						escreveTexto(5,5,"MATRIZ ORIGINAL",79);
						printMatriz(mat,ordem,ordem,5,5);
						escreveTexto(5,55,"MATRIZ GERADA",79);
						printMatriz(matAux,ordem,ordem,55,5);
						if (verifica)
							escreveTexto(25,3,"A matriz e simetrica",79);
						else
							escreveTexto(25,3,"A matriz e simetrica",79);
						info2(&temp);
						SetColor(15);	
					}
					else if (op == 5) {
						info (2, mat, &linhas, &colunas, &ordem);
						verifica = QuadradoMagico (mat, ordem, &soma);
						escreveTexto(5,5,"MATRIZ ",79);
						printMatriz(mat,ordem,ordem,5,5);
						if (verifica) {
							gotoxy(25,3);
							SetColor(79);
							printf("A matriz e um quadrado magico de soma %d",soma);
						}
						else
							escreveTexto(3,25,"A matriz nao e um quadrado magico",79);
						info2(&temp);	
						SetColor(15);	
					}
					else if (op == 6) {
						info (2, mat, &linhas, &colunas, &ordem);
						verifica = QuadradoLatino (mat, ordem);
						escreveTexto(5,5,"MATRIZ ",79);
						printMatriz(mat,ordem,ordem,5,5);
						if (verifica) 
							escreveTexto(3,25,"A matriz e um quadrado latino",79);
						else
							escreveTexto(3,25,"A matriz nao e um quadrado latino",79);	
						info2(&temp);	
						SetColor(15);	
					}
					else if (op == 7) {
						info (2, mat, &linhas, &colunas, &ordem);
						verifica = MatrizDePermutacao (mat,ordem);
						escreveTexto(5,5,"MATRIZ ",79);
						printMatriz(mat,ordem,ordem,5,5);
						if (verifica) 
							escreveTexto(3,25,"A matriz e uma matriz de permutacao",79);
						else
							escreveTexto(3,25,"A matriz nao e uma matriz de permutacao",79);
						info2(&temp);	
						SetColor(15);	
					}
				}	
				else if (aux == 2){
					op = 1;
					aux = 3;
					menu (op);
					menu2 (aux);
				}	
       	    }
    	}
	} while (t != esc);
}
