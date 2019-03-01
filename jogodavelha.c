#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void mostrarQuadro(char quadro[])
{
	for(int i = 0;i<3;i++)
		printf(" %c |", quadro[i]);
	printf("\n____________\n");
	for(int i = 3;i<6;i++)
		printf(" %c |", quadro[i]);
	printf("\n____________\n");
	for(int i = 6;i<9;i++)
		printf(" %c |", quadro[i]);
	printf("\n");
}
void fazerJogada(char quadro[])
{
	int escolha;
	
	printf("Digite o numero da posicao escolhida");
	scanf("%d", &escolha);
	
	if(escolha<=8 && escolha>=0 && quadro[escolha] != 'o')
		quadro[escolha] = 'x';
}
void jogadaCpu(char quadro[])
{
	int quinas[4] = {0, 2, 6, 8};
	int linha1[3] = {0, 1, 2};
	int linha2[3] = {3, 4, 5};
	int linha3[3] = {6, 7, 8};
	int coluna1[3] = {0, 3, 6};
	int coluna2[3] = {1, 4, 7};
	int coluna3[3] = {2, 5, 8};
	int diagonal1[3] = {0, 4, 8};
	int diagonal2[3] = {2, 4, 6};
	int meios[4] = {1, 3, 5, 7};
	int vazio=1, col1=0, col2=0, col3=0, dia1=0, dia2=0, lin1=0, lin2=0, lin3=0, qui=0, mei=0, meioVazio = 1;
	int posicao = rand()%8;
	
	if(quadro[5] == 'x' || quadro[5] == 'o')
		meioVazio = 0;
	for(int i=0;i<9;i++)
	{
		if(quadro[i] == 'x' || quadro[i] == 'o')
			vazio = 0;
	}
	for(int i = 0;i<3;i++)
	{
		if(quadro[coluna1[i]] == 'x')
			col1 = col1 + 1;
		if(quadro[coluna2[i]] == 'x')
		{
			col2 = col2 + 1;
		}
		if(quadro[coluna3[i]] == 'x')
			col3 = col3 + 1;
		if(quadro[linha1[i]] == 'x')
			lin1 = lin1 + 1;
		if(quadro[linha2[i]] == 'x')
			lin2 = lin2 + 1;
		if(quadro[linha3[i]] == 'x')
			lin3 = lin3 + 1;
		if(quadro[diagonal1[i]] == 'x')
			dia1 = dia1 + 1;
		if(quadro[diagonal2[i]] == 'x')
			dia2 = dia2 + 1;
	}
	for(int i=0;i<4;i++)
	{
		if(quadro[quinas[i]] =='x')
			qui = qui + 1;
		if(quadro[meios[i]] == 'x')
			mei = mei + 1;
	}
	if(vazio)
		quadro[4] = 'o';

	else if(col1 == 2 && quadro[coluna1[0]] != 'o' && quadro[coluna1[1]] != 'o' && quadro[coluna1[2]] != 'o')
	{
		printf("col1\n");
		for(int i = 0;i<3;i++)
			if(quadro[coluna1[i]] != 'x')
				quadro[coluna1[i]] = 'o';
	}
	else if(col2 == 2 && quadro[coluna2[0]] != 'o' && quadro[coluna2[1]] != 'o' && quadro[coluna2[2]] != 'o')
	{
		printf("col2\n");
		for(int i = 0;i<3;i++)
			if(quadro[coluna2[i]] != 'x')
				quadro[coluna2[i]] = 'o';
	}
	else if(col3 == 2 && quadro[coluna3[0]] != 'o' && quadro[coluna3[1]] != 'o' && quadro[coluna3[2]] != 'o')
	{
		printf("col3\n");
		for(int i = 0;i<3;i++)
			if(quadro[coluna1[i]] != 'x')
				quadro[coluna1[i]] = 'o';
	}
	else if(lin1 == 2 && quadro[linha1[0]] != 'o' && quadro[linha1[1]] != 'o' && quadro[linha1[2]] != 'o')
	{
		printf("lin1\n");
		for(int i = 0;i<3;i++)
			if(quadro[linha1[i]] != 'x')
				quadro[linha1[i]] = 'o';
	}
	else if(lin2 == 2 && quadro[linha2[0]] != 'o' && quadro[linha2[1]] != 'o' && quadro[linha2[2]] != 'o')
	{
		printf("lin2\n");
		for(int i = 0;i<3;i++)
			if(quadro[linha2[i]] != 'x')
				quadro[linha2[i]] = 'o';
	}
	else if(lin3 == 2 && quadro[linha3[0]] != 'o' && quadro[linha3[1]] != 'o' && quadro[linha3[2]] != 'o')
	{
		printf("lin3\n");
		for(int i = 0;i<3;i++)
			if(quadro[linha3[i]] != 'x')
				quadro[linha3[i]] = 'o';
	}
	else if(dia1 == 2 && quadro[diagonal1[0]] != 'o' && quadro[diagonal1[1]] != 'o' && quadro[diagonal1[2]] != 'o')
	{
		printf("dia1\n");
		for(int i = 0;i<3;i++)
			if(quadro[diagonal1[i]] != 'x')
				quadro[diagonal1[i]] = 'o';
	}
	else if(dia2 == 2 && quadro[diagonal2[0]] != 'o' && quadro[diagonal2[1]] != 'o' && quadro[diagonal2[2]] != 'o')
	{
		printf("dia2\n");
		for(int i = 0;i<3;i++)
			if(quadro[diagonal2[i]] != 'x')
				quadro[diagonal2[i]] = 'o';
	}
		else if(qui == 1 && meioVazio)
	{
		printf("um na quina\n");
		quadro[4] = 'o';
	
	}
	else if(qui == 0)
	{
		int k = rand()%4;
		
		quadro[quinas[k]] = 'o';
	}
	else if(qui == 2)
		quadro[meios[rand()%4]] = 'o';
	else
	{
		printf("aleatorio\n");
		while(1)
		{
			if(quadro[posicao] != 'x' && quadro[posicao] != 'o')
				quadro[posicao] = 'o';
				break;
		}
		if(posicao < 8)
			posicao = posicao + 1;
	}
}

int main()
{
	char quadro[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
	
	for(int i = 0;i<8;i++)
	{
		mostrarQuadro(quadro);
		fazerJogada(quadro);
		clrscr();
		jogadaCpu(quadro);
		
	}
	
	
	return 0;
}
