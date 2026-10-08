#include <stdio.h>
 
typedef struct 
    {
     int dia;
     int mes;
     int ano;
    } Data;
    

    
int validarData(Data dataNascimento) {
    // mês inválido 
    if(dataNascimento.mes > 12 || dataNascimento.mes < 1) 
        return 0;
        
    // considerando um intervalo entre 1920 - 2026
    if(dataNascimento.ano < 1920 || dataNascimento.ano > 2026)
        return 0;
    
    //descobrir se o ano é bissexto
    
        int bissexto = 0;
        
    if (dataNascimento.ano % 400 == 0) {
        // bissexto
        bissexto = 1;
        
        }
    else if (dataNascimento.ano % 100 == 0) {
            // NÃO bissexto
            bissexto = 0;
        }
    else if (dataNascimento.ano % 4 == 0) {
            // bissexto
            bissexto = 1;
        }
    else {
            // NÃO bissexto
            bissexto = 0;
        }        
    
    
    
    // validar o dia de acordo com o mês
    
    if(dataNascimento.mes == 2 && bissexto) {
        if(dataNascimento.dia < 1 || dataNascimento.dia > 29)
            return 0;
    } else if(dataNascimento.mes == 2 && !bissexto) {
        if(dataNascimento.dia < 1 || dataNascimento.dia > 28)
            return 0;
    }
        
    
    // meses com 30 dias 
    
    if (dataNascimento.mes == 4 ||
        dataNascimento.mes == 6 ||
        dataNascimento.mes == 9 ||
        dataNascimento.mes == 11) {
            if(dataNascimento.dia < 1 || dataNascimento.dia > 30)
                return 0;
        }
    else {
        if(dataNascimento.dia < 1 || dataNascimento.dia > 31)
                return 0;
    }
    
     // como aceitar diferentes formatos de data?
     
    
}

int main()
{
    printf("Informe a data:\n");
    
    Data dataNascimento;
    
    scanf("%d %d %d", &dataNascimento.dia, &dataNascimento.mes, &dataNascimento.ano);
    
    validarData(dataNascimento);
    
    
    //printf("%d/%d/%d", dataNascimento.dia, dataNascimento.mes, dataNascimento.ano);


    return 0;
}


    
