#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Prenche uma matriz de tamanho linha x coluna com zeros
void preencheMatriz(int linha, int coluna, int onibus[linha][coluna]) {
    for(int i=0; i<linha; i++) {
    	for (int j=0; j<coluna; j++) {
            onibus[i][j]=0;
        }
	}
	printf("\n Todos os lugares estao disponiveis, aproveite!\n\n");
}
//Imprime a matriz onibus
void imprimeOnibus(int linha, int opcao, int coluna, int onibus[linha][coluna]){
    printf("  /--0------0--\\\n");
    printf(" /  Porta-->     /\n");
    printf("|----------------|\n");
    int contador=1;
    for (int i=0; i<linha; i++) {
        printf("| ");
        for (int j=0; j<coluna; j++) {
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
//entrada de dados e tratamento 
int tratamento(char userInput[64], int num, int *p){
    int loop=1;
    do{
        //__fpurge(stdin);
        setbuf(stdin,NULL);
        fgets(userInput, 63, stdin);
        if( sscanf(userInput, "%d", &num) != 1) {
            printf("Atencao!!!Opcao invalida! Tente novamente!\n");
        } else if (num==0){
            printf("Atencao!!!Opcao invalida! Tente novamente!\n");
        }else{
           *p=(int)num;
            loop=0; 
        }
    }while(loop==1);
    system("clear");
}
//imprime menu principal e chama a funcao de entrada de dados e tratamento
int menuRota(int *rota, char userInput[64], int num, int *menuloop){
    int loop=1;
    do{
        printf("\n*********************************************          **************");
        printf("\n* Escolha uma das rotas                     *          *  4 - SAIR  *");
        printf("\n* 1 - Rio de Janeiro x Sao Paulo            *          **************");
        printf("\n* 2 - Rio de Janeiro x Belo horizonte       *");
        printf("\n* 3 - Rio de Janeiro x Miracema             *");
        printf("\n*********************************************");
        printf("\n Rota: ");
        tratamento(userInput,num,rota);
        if (*rota==4){
            printf("\n\nAtencao!!! O programa foi encerrado!\n\n");
            loop=0;
            *menuloop=0;
        } else if (*rota<0 || *rota>3){
            printf("\n\nAtencao!!! Opcao invalida!\n");
        } else{
            loop=0;
        }
    }while(loop==1);
}
//imprime menu de opcoes e chama funcao entrada de dados e tratamento 
int menuOpcao(int *opcao, char userInput[64], int num){
    int loop=1;
    do{
        printf("\n*********************************************          ******************");
        printf("\n* Escolha a classe de onibus desejada       *          *  4 - CANCELAR  *");
        printf("\n* 1 - Convencional                          *          ******************");
        printf("\n* 2 - Executivo                             *");
        printf("\n* 3 - Leito                                 *");
        printf("\n*********************************************");
        printf("\nClasse: ");
        tratamento(userInput,num,opcao);
        if (*opcao <0 || *opcao>4) {
            printf("\n\nAtencao!!! Opcao invalida!\n");
        }else if (*opcao == 4){
            system("clear");
            loop=0;
        } else{
           loop=0;
        }   
    }while(loop==1);
}

void compraPassagem(int prosseguir,int *rota, float valorPassagem, int *opcao, int *linha){
	int continuar3=1, coluna=4, onibus[*linha][coluna], poltrona=0, posicaoLinha=0, posicaoColuna=0, contador=1, comprou=1,continuar=0;
	float passagem=0;
    do{
        if (prosseguir==1){
            preencheMatriz(*linha, coluna, onibus);
            imprimeOnibus(*linha,*opcao, coluna, onibus);
            do{
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
                do{
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
	                }
	                if (continuar==1){
	                    continuar2=0;
	                }
	            }while(continuar2==1);
	        }while (comprou==1);

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

int classesOnibus(int *opcao, int *rota, int *prosseguir, int *linha, int num, char userInput[64]){
    int loop=1;
    float valorPassagem;
    if (*opcao==4){
        return 0;
    }do{
        switch(*rota){
            case 1: //rota 1
                switch(*opcao){
                    case 1: //(onibus convencional)
                        *linha=13;
                        printf("\n Rota: Rio de Janeiro x SP\n Classe: Convencional\n Preco: R$98,99\n\n");
                        printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                        tratamento(userInput,num,prosseguir);
                        system("clear");
                        valorPassagem=98.99;
                        compraPassagem(*prosseguir,rota,valorPassagem,opcao,linha);
                        loop=0;
                    break;
                    case 2://(onibus executivo)
                        *linha=12;
                        printf("\n Rota: Rio de Janeiro x SP\n Classe: Executivo\n Preco: R$99,99\n\n");
                        printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                        tratamento(userInput,num,prosseguir);
                        system("clear");
                        valorPassagem=99,99;
                        compraPassagem(*prosseguir,rota,valorPassagem,opcao,linha);
                        loop=0;
                    break;
                    case 3://(onibus leito)
                        *linha=7;
                        printf("\n Rota: Rio de Janeiro x SP\n Classe: Leito\n Preco: R$159,99\n\n");
                        printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                        tratamento(userInput,num,prosseguir);
                        system("clear");
                        valorPassagem=159,99;
                        compraPassagem(*prosseguir,rota,valorPassagem,opcao,linha);
                        loop=0;
                    break;
                }
            break;
            case 2://rota 2
                switch(*opcao){
                    case 1:
                        *linha=13;
                        printf("\n Rota: Rio de Janeiro x Belo horizonte\n Classe: Convencional\n Preco: R$103,80\n\n");
                        printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                        tratamento(userInput,num,prosseguir);
                        system("clear");
                        valorPassagem=103.80;
                        compraPassagem(*prosseguir,rota,valorPassagem,opcao,linha);
                        loop=0;
                    break;
                    case 2:
                        *linha=12;
                        printf("\n Rota: Rio de Janeiro x Belo horizonte\n Classe: Executivo\n Preco: R$109,90\n\n");
                        printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                        tratamento(userInput,num,prosseguir);
                        system("clear");
                        valorPassagem=109,90;
                        compraPassagem(*prosseguir,rota,valorPassagem,opcao,linha);
                        loop=0;
                    break;
                    case 3:
                        *linha=7;
                        printf("\n Rota: Rio de Janeiro x Belo horizonte\n Classe: Leito\n Preco: R$139,90\n\n");
                        printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                        tratamento(userInput,num,prosseguir);
                        system("clear");
                        valorPassagem=139,90;
                        compraPassagem(*prosseguir,rota,valorPassagem,opcao,linha);
                        loop=0;
                    break;
                }
            break;
            case 3://rota3
                switch(*opcao){
                    case 1:
                        *linha=13;
                        printf("\n Rota: Rio de Janeiro x Miracema\n Classe: Convencional\n Preco: R$73,90\n\n");
                        printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                        tratamento(userInput,num,prosseguir);
                        system("clear");
                        valorPassagem=73.90;
                        compraPassagem(*prosseguir,rota,valorPassagem,opcao,linha);
                        loop=0;
                    break;
                    case 2:
                        *linha=12;
                        printf("\n Rota: Rio de Janeiro x Miracema\n Classe: Executivo\n Preco: R$81,10\n\n");
                        printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                        tratamento(userInput,num,prosseguir);
                        system("clear");
                        valorPassagem=81.10;
                        compraPassagem(*prosseguir,rota,valorPassagem,opcao,linha);
                        loop=0;
                    break;
                    case 3:
                        *linha=7;
                        printf("\n Rota: Rio de Janeiro x Miracema\n Classe: Leito\n Preco: R$88,42\n\n");
                        printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                        tratamento(userInput,num,prosseguir);
                        system("clear");
                        valorPassagem=88.42;
                        compraPassagem(*prosseguir,rota,valorPassagem,opcao,linha);
                        loop=0;
                    break;
                }
            break;
        }
    }while(loop==1);
}

int main(){
    int rota=0,opcao=0,prosseguir=0,menuloop=1,linha=0,num=0;
    char userInput[64], resp[64];
    system("clear");
    do{
    	menuRota(&rota,userInput,num,&menuloop);
        if (menuloop==0){
            break;
        }
    	menuOpcao(&opcao,userInput,num);
        classesOnibus(&opcao,&rota,&prosseguir,&linha,num,userInput);
    }while(menuloop==1);
    return 0;
}