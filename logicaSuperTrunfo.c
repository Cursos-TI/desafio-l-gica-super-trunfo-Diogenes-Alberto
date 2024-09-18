#include <stdio.h>
#include <string.h>
// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

struct carta{
    char  nomeEstado[30];
    char  nomeCidade[30];
    char  codigoCidade[4];
    int populacaoCidade;
    int pointsCidade;
    float areaCidade;
    float densidadePopulacional;
    float pibPerCapita;
    float pibCidade;
    float superPoder;
};

float CalcularSuperPoder(struct carta item)
{
    float resultado = 0.0;
    resultado = item.populacaoCidade+item.pointsCidade+item.areaCidade+
                item.pibCidade+item.densidadePopulacional+item.pibPerCapita;
    return resultado;
}
void Margem()
{
    printf("\n\n");
    printf("////////////////////////////////////////////////////\n");
}
void MostrarDados(char numeroCidade[],struct carta item)
{
    Margem();
    printf("Nome Estado: %s\n",item.nomeEstado);
    printf("Nome Cidade: %s\n",item.nomeCidade);
    printf("Codigo da Cidade %s: %s \n",numeroCidade,item.codigoCidade);
    printf("populacao da Cidade %s: %d\n",item.nomeCidade,item.populacaoCidade);
    printf("Area da Cidade %s: %.3f\n",item.nomeCidade,item.areaCidade);
    printf("Pib Cidade %s: %.3f\n",item.nomeCidade,item.pibCidade);
    printf("Pontos Turisticos da Cidade %s: %d\n",item.nomeCidade,item.pointsCidade);
    printf("Densidade Populacional da Cidade %s: %.2f\n",item.nomeCidade,item.densidadePopulacional);
    printf("Pib per Capita da Cidade %s: %.2f\n",item.nomeCidade,item.pibPerCapita);
    printf("Total de super Poder da Cidade %s: %.2f\n",item.nomeCidade,item.superPoder);
}

float PibPerCapita(int populacao, float pibCidade)
{
    float resultado;
    resultado=pibCidade/populacao;
    return resultado;
}

float DensidadePopulacional(int populacao, float areaCidade)
{
    float resultado;
    resultado=populacao/areaCidade;
    return resultado;
}

void retornaIdCidade ( char nome[], char texto[], int indice)
{
    char convertido[5];
    sprintf(convertido,"%d",indice);
    strcpy(nome,texto);
    strcat(nome,convertido);
}

void MostrarValores(struct carta item1,struct carta item2,char opcao[],float valor1,float valor2)
{
    Margem();
    
    printf("==Comparando o atributo %s das Cartas==\n",opcao);
    printf("Carta 1 - Estado: %s, Código: %s : %.2f \n",item1.nomeEstado,item1.codigoCidade,valor1);
    printf("Carta 2 - Estado: %s, Código: %s : %.2f \n",item2.nomeEstado,item2.codigoCidade,valor2);
}

struct carta PreencherValores()
{
    struct carta resultado;

    printf("Digite o nome do Estado da Cidade :\n");
    scanf(" %s",resultado.nomeEstado);
    printf("Digite o nome da Cidade :\n");
    scanf(" %s",resultado.nomeCidade);
    printf("Digite a populacao da Cidade :\n");
    scanf("%d", &resultado.populacaoCidade);
    printf("Digite a area da Cidade :\n");
    scanf("%f", &resultado.areaCidade);
    printf("Digite o pib da Cidade :\n");
    scanf("%f",&resultado.pibCidade);    
    printf("Digite a quantidade de pontos turisticos da Cidade :\n");
    scanf("%d",&resultado.pointsCidade);

    return resultado;
}

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    struct carta carta01, carta02;
    char opcao1,opcao2;
    char textoOpcao1[30],textoOpcao2[30];
    int codigo=1;
    int resultado1,resultado2, pontuacao1, pontuacao2;
    pontuacao1=pontuacao2=0;
    
    carta01 = PreencherValores();

    retornaIdCidade(carta01.codigoCidade,"A0",codigo);
    carta01.densidadePopulacional=DensidadePopulacional(carta01.populacaoCidade,carta01.areaCidade);
    carta01.pibPerCapita=PibPerCapita(carta01.populacaoCidade,carta01.pibCidade);
    carta01.superPoder=CalcularSuperPoder(carta01);
    MostrarDados("01",carta01);

    Margem();    

    carta02 = PreencherValores();

    codigo++;
    retornaIdCidade(carta02.codigoCidade,"A0",codigo);
    carta02.densidadePopulacional=DensidadePopulacional(carta02.populacaoCidade,carta02.areaCidade);
    carta02.pibPerCapita=PibPerCapita(carta02.populacaoCidade,carta02.pibCidade);
    carta02.superPoder=CalcularSuperPoder(carta02);
    MostrarDados("02",carta02);

    // CompararValores(carta01,carta02);
    printf("Escolha qual propriedade desejam comparar:\n");
    printf("(1) Populacao.\n");
    printf("(2) Area da cidade.\n");
    printf("(3) Pib.\n");
    printf("(4) Pib per capita.\n");
    printf("(5) Pontos turisticos.\n");
    printf("(6) Densidade Populacional.\n");
    printf("(7) Super poder.\n");
    printf("Digite a primeira opcao: ");
    scanf(" %c",&opcao1);
    printf("Digite a segunda opcao: ");
    scanf(" %c",&opcao2);

    switch (opcao1)
    {
        case '1':
            strcpy(textoOpcao1,"Populacao");
            resultado1=(carta01.populacaoCidade>=carta02.populacaoCidade)?1:0;
            MostrarValores(carta01,carta02,textoOpcao1,carta01.populacaoCidade,carta02.populacaoCidade);
            (carta01.populacaoCidade>=carta02.populacaoCidade)?printf("\nCarta 1 vencedora\n"):printf("\nCarta 2 vencedora\n");
            break;
        case '2':
            strcpy(textoOpcao1,"Area da cidade");
            resultado1=(carta01.areaCidade>=carta02.areaCidade)?1:0;
            MostrarValores(carta01,carta02,textoOpcao1,carta01.areaCidade,carta02.areaCidade);
            (carta01.areaCidade>=carta02.areaCidade)?printf("\nCarta 1 vencedora\n"):printf("\nCarta 2 vencedora\n");
            break;
        case '3':        
            strcpy(textoOpcao1,"Pib");
            resultado1=(carta01.pibCidade>=carta02.pibCidade)?1:0;
            MostrarValores(carta01,carta02,textoOpcao1,carta01.pibCidade,carta02.pibCidade);
            (carta01.pibCidade>=carta02.pibCidade)?printf("\nCarta 1 vencedora\n"):printf("\nCarta 2 vencedora\n");
            break;
        case '4':        
            strcpy(textoOpcao1,"Pib per capita");
            resultado1=(carta01.pibPerCapita>=carta02.pibPerCapita)?1:0;
            MostrarValores(carta01,carta02,textoOpcao1,carta01.pibPerCapita,carta02.pibPerCapita);
            (carta01.pibPerCapita>=carta02.pibPerCapita)?printf("\nCarta 1 vencedora\n"):printf("\nCarta 2 vencedora\n");
            break;
        case '5':        
            strcpy(textoOpcao1,"Pontos turisticos");
            resultado1=(carta01.pointsCidade>=carta02.pointsCidade)?1:0;
            MostrarValores(carta01,carta02,textoOpcao1,carta01.pointsCidade,carta02.pointsCidade);
            (carta01.pointsCidade>=carta02.pointsCidade)?printf("\nCarta 1 vencedora\n"):printf("\nCarta 2 vencedora\n");
            break;
        case '6':        
            strcpy(textoOpcao1,"Densidade Populacional");
            resultado1=(carta01.densidadePopulacional<=carta02.densidadePopulacional)?1:0;
            MostrarValores(carta01,carta02,textoOpcao1,carta01.densidadePopulacional,carta02.densidadePopulacional);
            (carta01.densidadePopulacional<=carta02.densidadePopulacional)?printf("\nCarta 1 vencedora\n"):printf("\nCarta 2 vencedora\n");
            break;
        case '7':        
            strcpy(textoOpcao1,"Super poder");
            resultado1=(carta01.superPoder>=carta02.superPoder)?1:0;
            MostrarValores(carta01,carta02,textoOpcao1,carta01.superPoder,carta02.superPoder);
            (carta01.superPoder>=carta02.superPoder)?printf("\nCarta 1 vencedora\n"):printf("\nCarta 2 vencedora\n");
            break;    
        default:
        printf("Opcao invalida");
            break;
    }

    switch (opcao2)
    {
        case '1':
            strcpy(textoOpcao2,"Populacao");
            resultado2=(carta01.populacaoCidade>=carta02.populacaoCidade)?1:0;
            MostrarValores(carta01,carta02,textoOpcao2,carta01.populacaoCidade,carta02.populacaoCidade);
            (carta01.populacaoCidade>=carta02.populacaoCidade)?printf("\nCarta 1 vencedora\n"):printf("\nCarta 2 vencedora\n");
            break;
        case '2':
            strcpy(textoOpcao2,"Area da cidade");
            resultado2=(carta01.areaCidade>=carta02.areaCidade)?1:0;
            MostrarValores(carta01,carta02,textoOpcao2,carta01.areaCidade,carta02.areaCidade);
            (carta01.areaCidade>=carta02.areaCidade)?printf("\nCarta 1 vencedora\n"):printf("\nCarta 2 vencedora\n");
            break;
        case '3':        
            strcpy(textoOpcao2,"Pib");
            resultado2=(carta01.pibCidade>=carta02.pibCidade)?1:0;
            MostrarValores(carta01,carta02,textoOpcao2,carta01.pibCidade,carta02.pibCidade);
            (carta01.pibCidade>=carta02.pibCidade)?printf("\nCarta 1 vencedora\n"):printf("\nCarta 2 vencedora\n");
            break;
        case '4':        
            strcpy(textoOpcao2,"Pib per capita");
            resultado2=(carta01.pibPerCapita>=carta02.pibPerCapita)?1:0;
            MostrarValores(carta01,carta02,textoOpcao2,carta01.pibPerCapita,carta02.pibPerCapita);
            (carta01.pibPerCapita>=carta02.pibPerCapita)?printf("\nCarta 1 vencedora\n"):printf("\nCarta 2 vencedora\n");
            break;
        case '5':        
            strcpy(textoOpcao2,"Pontos turisticos");
            resultado2=(carta01.pointsCidade>=carta02.pointsCidade)?1:0;
            MostrarValores(carta01,carta02,textoOpcao2,carta01.pointsCidade,carta02.pointsCidade);
            (carta01.pointsCidade>=carta02.pointsCidade)?printf("\nCarta 1 vencedora\n"):printf("\nCarta 2 vencedora\n");
            break;
        case '6':        
            strcpy(textoOpcao2,"Densidade Populacional");
            resultado2=(carta01.densidadePopulacional<=carta02.densidadePopulacional)?1:0;
            MostrarValores(carta01,carta02,textoOpcao2,carta01.densidadePopulacional,carta02.densidadePopulacional);
            (carta01.densidadePopulacional<=carta02.densidadePopulacional)?printf("\nCarta 1 vencedora\n"):printf("\nCarta 2 vencedora\n");
            break;
        case '7':        
            strcpy(textoOpcao2,"Super poder");
            resultado2=(carta01.superPoder>=carta02.superPoder)?1:0;
            MostrarValores(carta01,carta02,textoOpcao2,carta01.superPoder,carta02.superPoder);
            (carta01.superPoder>=carta02.superPoder)?printf("\nCarta 1 vencedora\n"):printf("\nCarta 2 vencedora\n");
            break;    
        default:
        printf("Opcao invalida");
            break;
    }

    if(resultado1&& resultado2)
    {
        printf("\nJogador1 venceu\n");
    }
    else if(!resultado1&& !resultado2)
    {
        printf("\njogador2 venceu\n");
    }
    else{
        printf("\njogo empatado\n");
    }

    return 0;
}
