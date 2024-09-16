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

void CompararValores(struct carta item1,struct carta item2)
{
    Margem();
    printf("==Comparando o atributo Populacao das Cartas==\n");
    printf("Carta 1 - Estado: %s, Código: %s, População: %d\n",item1.nomeEstado,item1.codigoCidade,item1.populacaoCidade);
    printf("Carta 2 - Estado: %s, Código: %s, População: %d\n",item2.nomeEstado,item2.codigoCidade,item2.populacaoCidade);

    if(item1.populacaoCidade>=item2.populacaoCidade)
    {
        printf("Resultado: Carta 1 da cidade %s é a vencedora!Com um total de:%d \n",item1.nomeCidade,item1.populacaoCidade);
    }
    else{
        printf("Resultado: Carta 2 da cidade %s é a vencedora!Com um total de:%d \n",item2.nomeCidade,item2.populacaoCidade);
    }
}

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    struct carta carta01, carta02;
    int codigo=1;
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    printf("Digite o nome do Estado da Cidade 01:\n");
    scanf(" %s",carta01.nomeEstado);
    printf("Digite o nome da Cidade 01:\n");
    scanf(" %s",carta01.nomeCidade);
    printf("Digite a populacao da Cidade 01:\n");
    scanf("%d", &carta01.populacaoCidade);
    printf("Digite a area da Cidade 01:\n");
    scanf("%f", &carta01.areaCidade);
    printf("Digite o pib da Cidade 01:\n");
    scanf("%f",&carta01.pibCidade);    
    printf("Digite a quantidade de pontos turisticos da Cidade 01:\n");
    scanf("%d",&carta01.pointsCidade);

    retornaIdCidade(carta01.codigoCidade,"A0",codigo);
    carta01.densidadePopulacional=DensidadePopulacional(carta01.populacaoCidade,carta01.areaCidade);
    carta01.pibPerCapita=PibPerCapita(carta01.populacaoCidade,carta01.pibCidade);
    carta01.superPoder=CalcularSuperPoder(carta01);
    MostrarDados("01",carta01);

    Margem();    

    printf("Digite o nome do Estado da Cidade 02:\n");
    scanf(" %s",carta02.nomeEstado);
    printf("Digite o nome da Cidade 02:\n");
    scanf(" %s",carta02.nomeCidade);
    printf("Digite a populacao da Cidade 02:\n");
    scanf("%d", &carta02.populacaoCidade);
    printf("Digite a area da Cidade 02:\n");
    scanf("%f", &carta02.areaCidade);
    printf("Digite o pib da Cidade 02:\n");
    scanf("%f",&carta02.pibCidade);    
    printf("Digite a quantidade de pontos turisticos da Cidade 02:\n");
    scanf("%d",&carta02.pointsCidade);

    codigo++;
    retornaIdCidade(carta02.codigoCidade,"A0",codigo);
    carta02.densidadePopulacional=DensidadePopulacional(carta02.populacaoCidade,carta02.areaCidade);
    carta02.pibPerCapita=PibPerCapita(carta02.populacaoCidade,carta02.pibCidade);
    carta02.superPoder=CalcularSuperPoder(carta02);
    MostrarDados("02",carta02);

    CompararValores(carta01,carta02);

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.
    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}
