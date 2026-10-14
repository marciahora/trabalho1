// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Dados do Aluno -----
//  Nome: Marcia Marly de Souza Fonseca da Hora 
//  email: marciahora02@gmail.com
//  Matrícula: 20261160006
//  Semestre: 2


// #################################################

#include <stdio.h>

typedef struct {
    int dia; 
    int mes; 
    int ano; 
} Data;

int validarData(Data d);

int stringToInteger (char str[]);


int main()
{
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
   
    
