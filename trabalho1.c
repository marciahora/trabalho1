// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

<<<<<<< HEAD
//  ----- Dados do Aluno -----
//  Nome: Marcia Marly de Souza Fonseca da Hora 
//  email: marciahora02@gmail.com
//  Matrícula: 20261160006
//  Semestre: 2

=======
//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025
>>>>>>> dab2284 (Implementa questoes do trabalho 1)

// #################################################

#include <stdio.h>
<<<<<<< HEAD

typedef struct {
    int dia; 
    int mes; 
    int ano; 
} Data;

int validarData(Data d);

int stringToInteger (char str[]);
=======
#include "trabalho1.h" 
#include <stdlib.h>
#include <string.h>
>>>>>>> dab2284 (Implementa questoes do trabalho 1)


DataQuebrada quebraData(char data[]);


/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
<<<<<<< HEAD
    char strUsuario[100];
    
    printf("Digite uma data:\n");
    scanf("%99s", strUsuario);   
   
    
    int resultado =  stringToInteger(strUsuario); 
    
    printf("%d", resultado);
    
    
    return 0;
}


int stringToInteger (char strUsuario[]) {
    
    Data data = {0,0,0}; 
    int digitos = 0;
    int barras = 0;
    
    
    for(int i = 0; strUsuario[i] != '\0'; i++){
        
        if(strUsuario[i] == '/') {
            
            if (digitos == 0 || barras >= 2)
                return 0; 
                
            barras++;
            digitos = 0;
            
        }
        else if(strUsuario[i] >= '0' && strUsuario[i] <= '9'){
            int numero = strUsuario[i] - '0';
            digitos++;
            
            if (digitos > 2 && barras < 2)
                return 0;

            if (digitos > 4 && barras == 2)
                return 0;
            
            if (barras == 0) {
                data.dia = data.dia * 10 + numero;
            }
            
            if(barras == 1){
                data.mes = data.mes * 10 + numero;
            }
            
            if(barras == 2){
                data.ano = data.ano * 10 + numero;
            }
        }
        
        else {
            return 0;
        }
    }
    
    if (barras != 2 || (digitos !=2 && digitos != 4))
        return 0;

    // Converter somente anos digitados com 2 dígitos
    if (digitos == 2) {
        if (data.ano <= 26)
            data.ano += 2000;
        else
            data.ano += 1900;
    }
    
    return validarData(data);
}



int validarData(Data dataUsuario) {
    
    // validar mês
    
    if(dataUsuario.mes < 1 || dataUsuario.mes > 12) 
        return 0;
    
   
        
    
    // 1915 - 2000
       
        
    // validar ano 2026 - 1927
    if(dataUsuario.ano < 1927 || dataUsuario.ano > 2026)
        return 0;
        
    int bissexto = 0;
    
    if(dataUsuario.ano % 4 == 0 && dataUsuario.ano % 100 != 0 ) 
        bissexto = 1;
    if(dataUsuario.ano % 400 == 0)
        bissexto = 1;
    
    //validar dia
    
    //fevereiro 
    if(dataUsuario.mes == 2 && bissexto){
        if(dataUsuario.dia < 1 || dataUsuario.dia > 29)
            return 0;
    } else if(dataUsuario.mes == 2 && !bissexto) {
        if(dataUsuario.dia < 1 || dataUsuario.dia > 28)
            return 0;
    } // Meses com 31 
     else if (  dataUsuario.mes == 4 ||
                dataUsuario.mes == 6 ||
                dataUsuario.mes == 9 ||
                dataUsuario.mes == 11  )
     {   if(dataUsuario.dia < 1 || dataUsuario.dia > 30)
            return 0;
     } else {
         if(dataUsuario.dia < 1 || dataUsuario.dia > 31)
            return 0;
     }
    
    
    return 1; 
}
   
=======
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
    return stringToInteger(data);
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
    DiasMesesAnos dma = {0, 0, 0, 0};

    if (q1(datainicial) == 0)
    {
        dma.retorno = 2;
        return dma;
    }
    else if (q1(datafinal) == 0)
    {
        dma.retorno = 3;
        return dma;
    }

    int d1 = 0, m1 = 0, a1 = 0;
    int d2 = 0, m2 = 0, a2 = 0;
    int etapa = 0;
    int digitosAno = 0;

    for (int i = 0; datainicial[i] != '\0'; i++)
    {
        if (datainicial[i] == '/')
        {
            etapa++;
        }
        else
        {
            int numero = datainicial[i] - '0';

            if (etapa == 0)
                d1 = d1 * 10 + numero;
            else if (etapa == 1)
                m1 = m1 * 10 + numero;
            else if (etapa == 2)
            {
                a1 = a1 * 10 + numero;
                digitosAno++;
            }
        }
    }

    if (digitosAno == 2)
    {
        if (a1 <= 26)
            a1 += 2000;
        else
            a1 += 1900;
    }

    etapa = 0;
    digitosAno = 0;

    for (int i = 0; datafinal[i] != '\0'; i++)
    {
        if (datafinal[i] == '/')
        {
            etapa++;
        }
        else
        {
            int numero = datafinal[i] - '0';

            if (etapa == 0)
                d2 = d2 * 10 + numero;
            else if (etapa == 1)
                m2 = m2 * 10 + numero;
            else if (etapa == 2)
            {
                a2 = a2 * 10 + numero;
                digitosAno++;
            }
        }
    }

    if (digitosAno == 2)
    {
        if (a2 <= 26)
            a2 += 2000;
        else
            a2 += 1900;
    }

    if (a1 > a2 ||
        (a1 == a2 && m1 > m2) ||
        (a1 == a2 && m1 == m2 && d1 > d2))
    {
        dma.retorno = 4;
        return dma;
    }

    int dias = d2 - d1;
    int meses = m2 - m1;
    int anos = a2 - a1;

    if (dias < 0)
    {
        meses--;

        int mesAnterior = m2 - 1;
        int anoAnterior = a2;

        if (mesAnterior == 0)
        {
            mesAnterior = 12;
            anoAnterior--;
        }

        int bissexto = 0;

        if (anoAnterior % 4 == 0 && anoAnterior % 100 != 0)
            bissexto = 1;

        if (anoAnterior % 400 == 0)
            bissexto = 1;

        int diasMes = 31;

        if (mesAnterior == 4 || mesAnterior == 6 ||
            mesAnterior == 9 || mesAnterior == 11)
        {
            diasMes = 30;
        }
        else if (mesAnterior == 2)
        {
            diasMes = 28 + bissexto;
        }

        dias += diasMes;

        if (dias < 0)
        {
            dias = d2;
        }
    }

    if (meses < 0)
    {
        anos--;
        meses += 12;
    }

    dma.qtdDias = dias;
    dma.qtdMeses = meses;
    dma.qtdAnos = anos;
    dma.retorno = 1;

    return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    size_t tamanho = strlen(texto);

    char busca = c;

    if (isCaseSensitive != 1) {
        if (busca >= 'A' && busca <= 'Z') {
            busca = busca + 32;
        }
    }

    for (int i = 0; i < tamanho; i++)
    {
        char atual = texto[i];

        if (isCaseSensitive != 1) {
            if (atual >= 'A' && atual <= 'Z') {
                atual = atual + 32;
            }
        }

        unsigned char u_atual = (unsigned char) atual;

        if (u_atual == 225 || u_atual == 224 || u_atual == 226 || u_atual == 227) atual = 'a';
        else if (u_atual == 233 || u_atual == 232 || u_atual == 234) atual = 'e';
        else if (u_atual == 237 || u_atual == 236 || u_atual == 238) atual = 'i';
        else if (u_atual == 243 || u_atual == 242 || u_atual == 244 || u_atual == 245) atual = 'o';
        else if (u_atual == 250 || u_atual == 249 || u_atual == 251) atual = 'u';

        if (isCaseSensitive == 1) {
            if (u_atual == 193 || u_atual == 192 || u_atual == 194 || u_atual == 195) atual = 'A';
            else if (u_atual == 201 || u_atual == 200 || u_atual == 202) atual = 'E';
            else if (u_atual == 205 || u_atual == 204 || u_atual == 206) atual = 'I';
            else if (u_atual == 211 || u_atual == 210 || u_atual == 212 || u_atual == 213) atual = 'O';
            else if (u_atual == 218 || u_atual == 217 || u_atual == 219) atual = 'U';
        } else {
            if (u_atual == 193 || u_atual == 192 || u_atual == 194 || u_atual == 195) atual = 'a';
            else if (u_atual == 201 || u_atual == 200 || u_atual == 202) atual = 'e';
            else if (u_atual == 205 || u_atual == 204 || u_atual == 206) atual = 'i';
            else if (u_atual == 211 || u_atual == 210 || u_atual == 212 || u_atual == 213) atual = 'o';
            else if (u_atual == 218 || u_atual == 217 || u_atual == 219) atual = 'u';
        }

        if (atual == busca) {
            qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    int p = 0;

    int tamTexto = strlen(strTexto);
    int tamBusca = strlen(strBusca);

    if (tamBusca == 0 || tamTexto == 0)
        return 0;

    for (int i = 0; i <= tamTexto - tamBusca; i++)
    {
        int achou = 1;

        for (int j = 0; j < tamBusca; j++)
        {
            if (strTexto[i + j] != strBusca[j])
            {
                achou = 0;
                break;
            }
        }

        if (achou == 1)
        {
            if (p + 1 >= 30)
                break;

            int inicio = 0;
            int tamanho = 0;

            for (int k = 0; k < i; k++)
            {
                if (((unsigned char)strTexto[k] & 192) != 128)
                    inicio++;
            }

            for (int k = 0; k < tamBusca; k++)
            {
                if (((unsigned char)strBusca[k] & 192) != 128)
                    tamanho++;
            }

            posicoes[p] = inicio + 1;
            posicoes[p + 1] = inicio + tamanho;

            p += 2;
            qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int resultado = 0;
>>>>>>> dab2284 (Implementa questoes do trabalho 1)
    
    while (num > 0) {
        int digito = num % 10;
        resultado = (resultado * 10) + digito;
        num = num / 10; //atualizar depois dde usar %
    }
    
    return resultado;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int mult = 1;
    int temp = numerobusca;

    while (temp > 0) {
        mult *= 10;
        temp /= 10;
    }

    while (numerobase > 0) {
        if (numerobase % mult == numerobusca) {
            qtdOcorrencias++;
            numerobase /= mult; 
        } else {
            numerobase /= 10; 
        }
    }

    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

int q7(char matriz[8][10], char palavra[])
{
    int tam = strlen(palavra);
    
    int dirLinha[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dirColuna[] = {0, 0, -1, 1, -1, 1, -1, 1};

    for (int l = 0; l < 8; l++) {
        for (int c = 0; c < 10; c++) {
            
            if (matriz[l][c] == palavra[0]) {
                
                for (int d = 0; d < 8; d++) {
                    int k;
                    
                    for (k = 0; k < tam; k++) {
                        int nova_linha = l + (k * dirLinha[d]);
                        int nova_coluna = c + (k * dirColuna[d]);
                        
                        if (nova_linha < 0 || nova_linha >= 8 || nova_coluna < 0 || nova_coluna >= 10) {
                            break;
                        }
                        
                        if (matriz[nova_linha][nova_coluna] != palavra[k]) {
                            break;
                        }
                    }
                    
                    if (k == tam) {
                        return 1;
                    }
                }
            }
        }
    }
    
    return 0; 
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}




int stringToInteger (char strUsuario[]) {
    
    Data data = {0,0,0}; 
    int digitos = 0;
    int barras = 0;
    
    
    for(int i = 0; strUsuario[i] != '\0'; i++){
        
        if(strUsuario[i] == '/') {
            
            if (digitos == 0 || barras >= 2)
                return 0; 
                
            barras++;
            digitos = 0;
            
        }
        else if(strUsuario[i] >= '0' && strUsuario[i] <= '9'){
            int numero = strUsuario[i] - '0';
            digitos++;
            
            if (digitos > 2 && barras < 2)
                return 0;

            if (digitos > 4 && barras == 2)
                return 0;
            
            if (barras == 0) {
                data.dia = data.dia * 10 + numero;
            }
            
            if(barras == 1){
                data.mes = data.mes * 10 + numero;
            }
            
            if(barras == 2){
                data.ano = data.ano * 10 + numero;
            }
        }
        
        else {
            return 0;
        }
    }
    
    if (barras != 2 || (digitos !=2 && digitos != 4))
        return 0;

    // Converter somente anos digitados com 2 dígitos
    if (digitos == 2) {
        if (data.ano <= 26)
            data.ano += 2000;
        else
            data.ano += 1900;
    }
    
    return validarData(data);
}



int validarData(Data dataUsuario) {
    
    // validar mês
    
    if(dataUsuario.mes < 1 || dataUsuario.mes > 12) 
        return 0;
    
   
        
    
    // 1915 - 2000
       
        
    // validar ano 2026 - 1927
    if(dataUsuario.ano < 1927 || dataUsuario.ano > 2026)
        return 0;
        
    int bissexto = 0;
    
    if(dataUsuario.ano % 4 == 0 && dataUsuario.ano % 100 != 0 ) 
        bissexto = 1;
    if(dataUsuario.ano % 400 == 0)
        bissexto = 1;
    
    //validar dia
    
    //fevereiro 
    if(dataUsuario.mes == 2 && bissexto){
        if(dataUsuario.dia < 1 || dataUsuario.dia > 29)
            return 0;
    } else if(dataUsuario.mes == 2 && !bissexto) {
        if(dataUsuario.dia < 1 || dataUsuario.dia > 28)
            return 0;
    } // Meses com 31 
     else if (  dataUsuario.mes == 4 ||
                dataUsuario.mes == 6 ||
                dataUsuario.mes == 9 ||
                dataUsuario.mes == 11  )
     {   if(dataUsuario.dia < 1 || dataUsuario.dia > 30)
            return 0;
     } else {
         if(dataUsuario.dia < 1 || dataUsuario.dia > 31)
            return 0;
     }
    
    
    return 1; 
}
  
