#include <stdio.h>
#include <stdlib.h>

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
void imprimeOnibus(int linha, int coluna, int onibus[linha][coluna]){
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
            }if (j==2 ) {
                printf("   ");
            }if (onibus[i][j] == 1) {
                printf("xx ");
            }if (onibus[i][j] == 0) {
                if (contador < 10) {
                    printf("0%d ",contador);
                } else{
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
   // int resp;
    printf("\n*********************************************          **************");
    printf("\n* Escolha uma das rotas                     *          *  4 - SAIR  *");
    printf("\n* 1 - Rio de Janeiro x Sao Paulo            *          **************");
    printf("\n* 2 - Rio de Janeiro x Belo horizonte       *");
    printf("\n* 3 - Rio de Janeiro x Miracema             *");
    printf("\n*********************************************");
    printf("\n Rota: ");
    scanf("%d", rota);
    //rota = resp;
   // printf("%d", *rota);
    if (*rota==4){
        printf("\n\nAtencao!!! O programa foi encerrado!\n\n");
        menuloop=2;
        return 0;
    } else if (*rota<1 || *rota>3){
        printf("\n\nAtencao!!! Opcao invalida!\n");
       	system("pause");
    } else {
    printf("\n*********************************************");
    printf("\n* Escolha a classe de onibus desejada       *");
    printf("\n* 1 - Convencional                          *");
    printf("\n* 2 - Executivo                             *");
    printf("\n* 3 - Leito                                 *");
    printf("\n*********************************************");
    printf("\nClasse: ");
    scanf("%d", opcao);
    } if (*opcao <1 || *opcao>3) {
        printf("\n\nAtencao!!! Opcao invalida!\n");
    }
}

void convencional(int prosseguir, float valorCovencional, int teste){
int continuar3=1;
do{
    if (prosseguir==1){
        int linha=13;
        int coluna=4;
        int onibus[linha][coluna];
        int poltrona=0;
        int posicaoLinha=0;
        int posicaoColuna=0;
        int contador=1;

        preencheMatriz(linha, coluna, onibus);
        imprimeOnibus(linha, coluna, onibus);
        int comprou=1;
        int continuar=0;
        float passagem=0;
        while (comprou==1) {
            printf("Digite o numero do assento pretendido: ");
            scanf("%d", &poltrona);
            if (poltrona<1 || poltrona>50){
                printf("\n\nAtencao!\n O assento escolhido nao existe!\n Escolha outro assento.\n\n");
            }else{
                posicaoLinha=(poltrona+1)/4;
                posicaoColuna=(poltrona+1) % 4;
                if (onibus[posicaoLinha][posicaoColuna] != 1) {
                    onibus[posicaoLinha][posicaoColuna] = 1;
                    printf("\n\nAssento reservado com sucesso!\n\n");
                    passagem=passagem+1;
                } else {
                    printf("\n\nAtencao!\nEsse lugar ja esta ocupado, por favor, tente novamente...\n\n");
                }
            }

            imprimeOnibus(linha, coluna, &onibus);


            float result=0;
            int continuar2=1;
            while(continuar2==1){
                printf("Deseja reservar outro assento?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                scanf("%d",&continuar);
                if ( continuar<1 || continuar>2){
                    printf("\n\nAtencao!!! Opcao invalida!\n");
                }
                if ( continuar==2){
                    result= valorCovencional*passagem;
                    printf("Valor total: R$ %4.2f\n\n",result);
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
        //system("pause");
        continuar3=0;

    }
    if ( prosseguir<1 || prosseguir>2){
        printf("\n\nAtencao!!! Opcao invalida!\n");
    }
    if ( prosseguir==2){
        continuar3=0;
        // break;
         //system("pause");
       // getchar(); problema aqui
    }
    if (prosseguir==1){
        continuar3=0;
        //break;
         //system("pause");
        //getchar();
   }
}while(continuar3==1);
}

int comprapassagem(int *opcao, int *rota, int prosseguir){
    //swicth case para rotas que vai chamar as funcoes  rota 1,2 e 3
    int rot,opt,teste=1;
    //rot=*rota;
    float valorCovencional=98.99;
    float valorExecutivo=99.99;
    float valorLeito=159.99;
    switch(*rota){
        case 1: //rota 1
            //opt=*opcao;
            switch(*opcao){
                case 1: //opcao 1 (onibus convencional)
                    //int continuar3=1;
                    //while(continuar3==1){
                        printf("\n Rota: Rio de Janeiro x SP\n Classe: Convencional\n Preco: R$98,99\n\n");
                        printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
                        scanf("%d", &prosseguir);

                    convencional(prosseguir,valorCovencional,teste);
                    //}while
                break;

                //opcoes 2 e 3 aqui!(Onibus executivo e leito)
            }
        break;

        //Rotas 2 e 3 aqui!
    }

}
	//int data, opcao, rota, prosseguir;
    //int linhaPretendida=0;
    //int colunaPretendida=0;
    //int teste=1;

int main(){
    int rota=0,opcao=0,prosseguir=0,menuloop=1;
    do{
    menu(&rota,&opcao,&menuloop);

    comprapassagem(&opcao,&rota,prosseguir);
    }while(menuloop==1);
 return 0;
}
/*
		    else if (opcao==2){
	        int prosseguir=0;
	        int continuar3=1;
	        while(continuar3==1){
	        printf("\n Rota: Rio de Janeiro x SP\n Classe: Executivo\n Preco: R$99,99\n\n");
	        printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
	        scanf("%d", &prosseguir);

	            if (prosseguir==1){
	                int linha=12;
	                int coluna=4;
	                int executivo[linha][coluna];
	                int poltrona=0;
	                int posicaoLinha=0;
	                int posicaoColuna=0;
	                int contador=1;

	                //Preenche a matriz
	                int i=0;
	                int j=0;
	                for(i=0; i<linha; i++) {
	                    for (j=0; j<coluna; j++) {
	                        executivo[i][j]=0;
	                    }
	                }
	                printf("\n Todos os lugares estao disponiveis, aproveite!\n\n");

	            //Imprime o ônibus/matriz
	                printf("  /--0------0--\\\n");
	                printf(" /  Porta-->     /\n");
	                printf("|----------------|\n");
	                i=0;
	                j=0;
	                for ( i=0; i<linha; i++) {
	                    printf("| ");
	                    for ( j=0; j<coluna; j++) {
	                        if (i==0) {
	                            if (j<2){
	                                if (j>2){
	                                    printf(" ");
	                                }else{
	                                    printf("   ");
	                                    continue;
	                                }
	                            }
	                        }if (j==2 ) {
	                            printf("   ");
	                        }if (executivo[i][j]==0) {
	                            if (contador < 10){
	                                printf("0%d ",contador);
	                            } else{
	                            printf("%d ",contador);
	                            }
	                        }
	                        contador=contador+1;
	                    }
	                    printf("|\n");
	                }
	                printf("------------------\n");

	            //Condição de permanencia
	                int comprou=1;
	                int continuar=0;
	                float passagem=0;
	                while (comprou==1) {
	                    printf("Digite o numero do assento pretendido: ");
	                    scanf("%d", &poltrona);
	                    if (poltrona<1 || poltrona>46){
	                        printf("\n\nAtencao!\n O assento escolhido nao existe!\n Escolha outro assento.\n\n");
	                    }else{
	                        posicaoLinha=(poltrona+1)/4;
	                        posicaoColuna=(poltrona+1) % 4;
	                        if (executivo[posicaoLinha][posicaoColuna] != 1) {
	                            executivo[posicaoLinha][posicaoColuna] = 1;
	                            printf("\n\nAssento reservado com sucesso!\n\n");
	                            passagem=passagem+1;
	                        } else {
	                            printf("\n\nAtencao!\nEsse lugar ja esta ocupado, por favor, tente novamente...\n\n");
	                        }
	                    }
	                //Imprime o ônibus/matriz
	                    printf("  /--0------0--\\\n");
	                    printf(" /  Porta-->     /\n");
	                    printf("|----------------|\n");
	                    i=0;
	                    j=0;
	                    contador=1;
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
	                            }if (j==2 ) {
	                                printf("   ");
	                            }if (executivo[i][j]==1) {
	                                printf("xx ");
	                            }if (executivo[i][j]==0) {
	                                if (contador < 10) {
	                                    printf("0%d ",contador);
	                                } else{
	                                printf("%d ",contador);
	                                }
	                            }
	                            contador=contador+1;
	                        }
	                        printf("|\n");
	                    }
	                    printf("------------------\n");

	                    int continuar2=1;
	                    float result=0;
	                    while(continuar2==1){
	                        printf("Deseja reservar outro assento?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
	                        scanf("%d",&continuar);
	                        if ( continuar<1 || continuar>2){
	                            printf("\n\nAtencao!!! Opcao invalida!\n");
	                        }
	                        if ( continuar==2){
	                            result= valorExecutivo*passagem;
	                            printf("Valor total: R$ %4.2f\n\n",result);
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
	                system("pause");
	                //return 0;
	            }
	            if ( prosseguir<1 || prosseguir>2){
	                printf("\n\nAtencao!!! Opcao invalida!\n");
	            }
	            if ( prosseguir==2){
	                continuar3=0;
	                //comprou=0;
	               // teste=0;
	            }
	            if (prosseguir==1){
	                continuar3=0;
	            }
	        }
	    } else if (opcao==3){
	        int prosseguir=0;
	        int continuar3=1;
	        while(continuar3==1){
	        printf("\n Rota: Rio de Janeiro x SP\n Classe: Leito\n Preco: R$159,99\n\n");
	        printf(" Deseja prosseguir?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
	        scanf("%d", &prosseguir);

	            if (prosseguir==1){
	                int linha=7;
	                int coluna=4;
	                int leito[linha][coluna];
	                int poltrona=0;
	                int posicaoLinha=0;
	                int posicaoColuna=0;
	                int contador=1;

	                //Preenche a matriz
	                int i=0;
	                int j=0;
	                for(i=0; i<linha; i++) {
	                    for (j=0; j<coluna; j++) {
	                        leito[i][j]=0;
	                    }
	                }
	                printf("\n Todos os lugares estao disponiveis, aproveite!\n\n");

	            //Imprime o ônibus/matriz
	                printf("  /--0------0--\\\n");
	                printf(" /  Porta-->     /\n");
	                printf("|----------------|\n");
	                i=0;
	                j=0;
	                for ( i=0; i<linha; i++) {
	                    printf("| ");
	                    for ( j=0; j<coluna; j++) {
	                        if (i==0) {
	                            if (j<2){
	                                if (j>2){
	                                    printf(" ");
	                                }else{
	                                    printf("   ");
	                                    continue;
	                                }
	                            }
	                        }if (j==2 ) {
	                            printf("   ");
	                        }if (leito[i][j]==0) {
	                            if (contador < 10){
	                                printf("0%d ",contador);
	                            } else if (contador<=24){
	                                printf("%d ",contador);
	                            }else{
	                                printf("   ");
	                            }
	                            contador=contador+1;
	                        }
	                    }
	                    printf("|\n|                |\n");
	                }
	                printf("------------------\n");

	            //Condição de permanencia
	                int comprou=1;
	                int continuar=0;
	                float passagem=0;
	                while (comprou==1) {
	                    printf("Digite o numero do assento pretendido: ");
	                    scanf("%d", &poltrona);
	                    if (poltrona<1 || poltrona>24){
	                        printf("\n\nAtencao!\n O assento escolhido nao existe!\n Escolha outro assento.\n\n");
	                    }else{
	                        posicaoLinha=(poltrona+1)/4;
	                        posicaoColuna=(poltrona+1) % 4;
	                        if (leito[posicaoLinha][posicaoColuna] != 1) {
	                            leito[posicaoLinha][posicaoColuna] = 1;
	                            printf("\n\nAssento reservado com sucesso!\n\n");
	                            passagem=passagem+1;
	                        } else {
	                            printf("\n\nAtencao!\nEsse lugar ja esta ocupado, por favor, tente novamente...\n\n");
	                        }
	                    }
	                //Imprime o ônibus/matriz
	                    printf("  /--0------0--\\\n");
	                    printf(" /  Porta-->     /\n");
	                    printf("|----------------|\n");
	                    i=0;
	                    j=0;
	                    contador=1;
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
	                            }if (j==2 ) {
	                                printf("   ");
	                            }if (leito[i][j] == 1) {
	                                printf("xx ");
	                            }if (leito[i][j] == 0) {
	                                if (contador < 10) {
	                                    printf("0%d ",contador);
	                                } else if (contador <= 24){
	                                    printf("%d ",contador);
	                                }else{
	                                    printf("   ");
	                                }
	                            }
	                            contador=contador+1;
	                        }
	                        printf("|\n|                |\n");
	                    }
	                    printf("------------------\n");

	                    int continuar2=1;
	                    float result=0;
	                    while(continuar2==1){
	                        printf("Deseja reservar outro assento?\n\n 1 - sim\n 2 - nao\n\nOpcao:");
	                        scanf("%d",&continuar);
	                        if ( continuar < 1 || continuar > 2){
	                            printf("\n\nAtencao!!! Opcao invalida!\n");
	                        }
	                        if ( continuar==2){
	                            result= valorLeito*passagem;
	                            printf("Valor total: R$ %4.2f\n\n",result);
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
	                system("pause");
	                //return 0;
	            }
	            if ( prosseguir<1 || prosseguir>2){
	                printf("\n\nAtencao!!! Opcao invalida!\n");
	            }
	            if ( prosseguir==2){
	                continuar3=0;
	                //comprou=0;
	                //teste=0;
	            }
	            if (prosseguir==1){
	                continuar3=0;
	            }
	        }
	    }




//system("pause");
return 0;
}*/
