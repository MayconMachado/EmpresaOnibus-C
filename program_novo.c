#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// Prenche uma matriz de tamanho linha x coluna com zeros
void preencheMatriz(int linha, int coluna, int onibus[linha][coluna]) {
    for(int i=0; i<linha; i++) {
    	for (int j=0; j<coluna; j++) {
            onibus[i][j]=0;
        }
	}
printf("\n Todos os lugares estao disponiveis, aproveite!\n\n");
}
//funcao teste
void imprimeMatriz(int linha, int coluna, int matriz[linha][coluna]){
    for(int i=0; i<linha; i++) {
    	for (int j=0; j<coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
	}
}

//Imprime a matriz onibus
void imprimeOnibus(int linha, int opcao, int coluna, int onibus[linha][coluna]){
    printf("  /--0------0--\\\n");
    printf(" /  Porta-->     /\n");
    printf("|----------------|\n");
    int i=0,j=0;
    int contador=1;
    for ( i=0; i<linha; i++) {
        printf("| ");
        for ( j=0; j<coluna; j++) {
            if (i==0) {
                if (j<2) {
                    if (j>2){
                        printf(" ");
                    }else{
                        printf("   ");
                        continue;
                    }
                }
            }if (j==2) {
                printf("   ");
            }if (onibus[i][j] == 1) {
                printf("xx ");
            } else {
                if (contador < 10) {
                    printf("0%d ",contador);
                } else if ((opcao==3) && (contador>24)) {
                        printf("   ");
                } else {
                printf("%d ",contador);
                }
            }
            contador=contador+1;
        }
        printf("|\n");
    }
    printf("------------------\n");
}
//imprime menu e pega entrada de dados
int menu(int *rota,int *opcao, int *menuloop){
    char resp[64];
    int num;
    printf("\n*********************************************          **************");
    printf("\n* Escolha uma das rotas                     *          *  4 - SAIR  *");
    printf("\n* 1 - Rio de Janeiro x Sao Paulo            *          **************");
    printf("\n* 2 - Rio de Janeiro x Belo horizonte       *");
    printf("\n* 3 - Rio de Janeiro x Miracema             *");
    printf("\n*********************************************");
    printf("\n Rota: ");
    tratamento(resp,num,rota);

    if (*rota==4){
        printf("\n\nAtencao!!! O programa foi encerrado!\n\n");
        *menuloop=2;
        return 0;
    } else if (*rota<1 || *rota>3){
        printf("\n\nAtencao!!! Opcao invalida!\n");
       	system("pause");
    } else {
    printf("\n*********************************************          ******************");
    printf("\n* Escolha a classe de onibus desejada       *          *  4 - CANCELAR  *");
    printf("\n* 1 - Convencional                          *          ******************");
    printf("\n* 2 - Executivo                             *");
    printf("\n* 3 - Leito                                 *");
    printf("\n*********************************************");
    printf("\nClasse: ");
    //scanf("%d", opcao);
    tratamento(resp,num,opcao);

    } if (*opcao <1 || *opcao>4) {
        printf("\n\nAtencao!!! Opcao invalida!\n");
    }else if (*opcao == 4){
        system("clear");
        return 0;
    }
    system("clear");
}

void tratamento(char userInput[64], int num, int *p){
	userInput[64];
	//int num = 0;

//	while( num == 0 ) {

		//num = 0;

		fgets(userInput, 63, stdin);
		//length = strlen(userInput);
        /*
		if( strlen(userInput) < 2 || strlen(userInput) > 3) {
			printf("Atencao!!!Opcao invalida!\n");
			continue;
		}*/

		if( sscanf(userInput, "%d", &num) != 1) {
            num=0;
			printf("Atencao!!!Opcao invalida!\n");
			//system("sleep 02");
			//continue;

		}
        /*
		if( num < 1 || num > 99) {
            num=0;
			printf("Atencao!!!Opcao invalida!\n");
			continue;
		}*/

		//printf("Number OK:%d\n",num);
		//*rota=(int)num;
//	}

	//printf("\nPassando dados.%d\n",num);
		//	system("sleep 02");
    *p=(int)num;
__fpurge(stdin);

	return *p;
}


void classesOnibus(int prosseguir, float valorPassagem, int teste, int *opcao, int *linha){
int continuar3=1;
do{
    if (prosseguir==1){
        int coluna=4;
        int onibus[*linha][coluna];
        int poltrona=0;
        int posicaoLinha=0;
        int posicaoColuna=0;
        int contador=1;

        preencheMatriz(*linha, coluna, onibus);
        imprimeOnibus(*linha,*opcao, coluna, onibus);

        int comprou=1;
        int continuar=0;
        float passagem=0;
        while (comprou==1) {
            printf("Digite o numero do assento pretendido: ");
            scanf("%d", &poltrona);
            system("clear");

            if (*opcao==1){
                if (poltrona<1 || poltrona>50){
                    printf("\n\nAtencao!\n O assento escolhido nao existe!\n Escolha outro assento.\n\n");
                    imprimeOnibus(*linha, *opcao, coluna, onibus);
                    continue;
                }
            }else if (*opcao==2){
                if (poltrona<1 || poltrona>46){
                    printf("\n\nAtencao!\n O assento escolhido nao existe!\n Escolha outro assento.\n\n");
                    imprimeOnibus(*linha, *opcao, coluna, onibus);
                    continue;
                }
            }else if (*opcao==3){
                if (poltrona<1 || poltrona>24){
                    printf("\n\nAtencao!\n O assento escolhido nao existe!\n Escolha outro assento.\n\n");
                    imprimeOnibus(*linha, *opcao, coluna, onibus);
                    continue;
                }
            }

            system("clear");
                posicaoLinha=(poltrona+1)/4;
                posicaoColuna=(poltrona+1) % 4;
                if (onibus[posicaoLinha][posicaoColuna] != 1) {
                    onibus[posicaoLinha][posicaoColuna] = 1;
                    printf("\n\nAssento reservado com sucesso!\n\n");
                    passagem=passagem+1;
                } else {
                    printf("\n\nAtencao!\nEsse lugar ja esta ocupado, por favor, tente novamente...\n\n");
                }
                imprimeOnibus(*linha, *opcao, coluna, onibus);

            float result=0;
            int continuar2=1;
            while(continuar2==1){
                printf("Deseja reservar outro assento?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                scanf("%d",&continuar);
                if ( continuar<1 || continuar>2){
                    system("clear");
                    printf("\n\nAtencao!!! Opcao invalida!\n");
                    imprimeOnibus(*linha, *opcao, coluna, onibus);
                }
                if ( continuar==2){
                    system("clear");
                    result= valorPassagem*passagem;
                    printf("\n\nValor total: R$ %4.2f\n\n",result);
                    printf("Passagem reservada com sucesso. Volte sempre!\n\n");
                    continuar2=0;
                    comprou=0;
                    teste=0;
                }
                if (continuar==1){
                    continuar2=0;
                }
            }
        }

    } else if (prosseguir==2) {
        continuar3=0;
    }
    if ( prosseguir<1 || prosseguir>2){
        printf("\n\nAtencao!!! Opcao invalida!\n");
        break;
    }
    if ( prosseguir==2){
        continuar3=0;
    }
    if (prosseguir==1){
        continuar3=0;
   }
}while(continuar3==1);
}

int comprapassagem(int *opcao, int *rota, int prosseguir, int *linha){
    int rot,opt,teste=1;
    float valorPassagem;
    switch(*rota){
        case 1: //rota 1
            switch(*opcao){
                case 1: //opcao 1 (onibus convencional)
                    *linha=13;
                    printf("\n Rota: Rio de Janeiro x SP\n Classe: Convencional\n Preco: R$98,99\n\n");
                    printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                    scanf("%d", &prosseguir);
                    system("clear");
                    valorPassagem=98.99;
                    classesOnibus(prosseguir,valorPassagem,teste,opcao,linha);
                break;
                case 2:
                    *linha=12;
                    printf("\n Rota: Rio de Janeiro x SP\n Classe: Executivo\n Preco: R$99,99\n\n");
                    printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                    scanf("%d", &prosseguir);
                    system("clear");
                    valorPassagem=99,99;
                    classesOnibus(prosseguir,valorPassagem,teste,opcao,linha);
                break;
                case 3:
                    *linha=7;
                    printf("\n Rota: Rio de Janeiro x SP\n Classe: Leito\n Preco: R$159,99\n\n");
                    printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                    scanf("%d", &prosseguir);
                    system("clear");
                    valorPassagem=159,99;
                    classesOnibus(prosseguir,valorPassagem,teste,opcao,linha);
                break;
            }
        break;
        case 2://rota 2
            switch(*opcao){
                case 1: //opcao 1 (onibus convencional)
                    *linha=13;
                    printf("\n Rota: Rio de Janeiro x Belo horizonte\n Classe: Convencional\n Preco: R$103,80\n\n");
                    printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                    scanf("%d", &prosseguir);
                    system("clear");
                    valorPassagem=103.80;
                    classesOnibus(prosseguir,valorPassagem,teste,opcao,linha);
                break;
                case 2:
                    *linha=12;
                    printf("\n Rota: Rio de Janeiro x Belo horizonte\n Classe: Executivo\n Preco: R$109,90\n\n");
                    printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                    scanf("%d", &prosseguir);
                    system("clear");
                    valorPassagem=109,90;
                    classesOnibus(prosseguir,valorPassagem,teste,opcao,linha);
                break;
                case 3:
                    *linha=7;
                    printf("\n Rota: Rio de Janeiro x Belo horizonte\n Classe: Leito\n Preco: R$139,90\n\n");
                    printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                    scanf("%d", &prosseguir);
                    system("clear");
                    valorPassagem=139,90;
                    classesOnibus(prosseguir,valorPassagem,teste,opcao,linha);
                break;
            }
        break;
        case 3://rota3
            switch(*opcao){
                case 1: //opcao 1 (onibus convencional)
                    *linha=13;
                    printf("\n Rota: Rio de Janeiro x Miracema\n Classe: Convencional\n Preco: R$73,90\n\n");
                    printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                    scanf("%d", &prosseguir);
                    system("clear");
                    valorPassagem=73.90;
                    classesOnibus(prosseguir,valorPassagem,teste,opcao,linha);
                break;
                case 2:
                    *linha=12;
                    printf("\n Rota: Rio de Janeiro x Miracema\n Classe: Executivo\n Preco: R$81,10\n\n");
                    printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                    scanf("%d", &prosseguir);
                    system("clear");
                    valorPassagem=81.10;
                    classesOnibus(prosseguir,valorPassagem,teste,opcao,linha);
                break;
                case 3:
                    *linha=7;
                    printf("\n Rota: Rio de Janeiro x Miracema\n Classe: Leito\n Preco: R$88,42\n\n");
                    printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                    scanf("%d", &prosseguir);
                    system("clear");
                    valorPassagem=88.42;
                    classesOnibus(prosseguir,valorPassagem,teste,opcao,linha);
                break;
            }
        break;
    }
}

int main(){
    int rota=0,opcao=0,prosseguir=0,menuloop=1,linha=0;
    //char userInput[64];
    do{
    menu(&rota,&opcao,&menuloop);

    comprapassagem(&opcao,&rota,prosseguir,&linha);
    }while(menuloop==1);
 return 0;
}
