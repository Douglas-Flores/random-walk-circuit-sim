#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "graph.h"
#include "rdmwalk.h"
#define vertex int
#define MAX_CONNECTIONS 20
#define MAX_NOS 20

main(){
    int num_nodes = 0;
    int op;
    printf("Escolha o modo de execucao:\n");
    printf("1 - Rodar circuito exemplo\n");
    printf("2 - Inserir circuito\n");
    printf("3 - Sair\n");
    printf("->");
    scanf("%d", &op);

    if(op == 1){
        num_nodes = 7;

        Graph circ = GRAPHinit(num_nodes);

        //Criando os vértices
        float cost = 0;
        cost = 0.3/(1+0.5);
        createVertex(circ, 0, cost);
        cost = 0.1/(1.0+1.0);
        createVertex(circ, 1, cost);
        cost = 0.05/(1+(1.0/4)+1);
        createVertex(circ, 2, cost);
        cost = 0.05/(1+(1.0/4));
        createVertex(circ, 3, cost);
        createVertex(circ, 4, -1.0);
        createVertex(circ, 5, -1.0);
        createVertex(circ, 6, -1.0);

        //Criando os arcos
        float p = 1/(1+0.5);
        GRAPHinsertArc(circ, 0, circ->v_list[2], p);
        p = 0.5/(1+0.5);
        GRAPHinsertArc(circ, 0, circ->v_list[4], p);

        p = 1.0/(1.0+1.0);
        GRAPHinsertArc(circ, 1, circ->v_list[2], 0.5);
        p = 1.0/(1.0+1.0);
        GRAPHinsertArc(circ, 1, circ->v_list[5], p);

        p = 1.0/(1+(1.0/4)+1);
        GRAPHinsertArc(circ, 2, circ->v_list[0], p);
        p = 1.0/(1+(1.0/4)+1);
        GRAPHinsertArc(circ, 2, circ->v_list[1], p);
        p = (1.0/4)/(1+(1.0/4)+1);
        GRAPHinsertArc(circ, 2, circ->v_list[3], p);

        p = (1.0/4)/(1+(1.0/4));
        GRAPHinsertArc(circ, 3, circ->v_list[2], p);
        p = 1.0/(1+(1.0/4));
        GRAPHinsertArc(circ, 3, circ->v_list[6], p);

        //printAdjList(circ);
        walker* e = malloc(sizeof(e));
        e->balance = 0;

        op = 1;
        while(op < 5 && op > 0){
            printf("\n********************************************\n");
            printf("A tensao de qual no voce deseja calcular?\n");
            printf("1 - A\n");
            printf("2 - B\n");
            printf("3 - C\n");
            printf("4 - D\n");
            printf("5 - Sair\n");
            printf("********************************************\n");
            printf("->");
            scanf("%d", &op);

            if(op < 5 && op >0){
                e->vertex_id = op - 1;
                sim(e, circ, 200);
                printf("\n********************************************\n");
                printf("Resultado = %.4f V",e->balance);
            }
        }

        printf("\nRodou ate o final! %.2f\n",e->balance);
    }
    else if(op == 2){
        printf("\nNumero de nos: ");
        scanf("%d", &num_nodes);

        Graph circ = GRAPHinit(num_nodes);
        printf("\nInicializacao do circuito realizada com sucesso!\n");

        float summations[MAX_NOS] = {0};
        float g[MAX_CONNECTIONS] = {0};
        //Criando os vértices
        for(int i=0; i<num_nodes; i++){
            char option;
            fflush(stdin);
            printf("Tipo do no ('h' para home e 'c' para common): ");
            scanf("%c", &option);

            float cost = 0;
            if(option == 'c'){
                float current = 0;
                printf("\nQual a corrente em no %d?: ", i);
                scanf("%f", &current);

                int r;
                float glinha = 0;
                float summation = 0.0;
                printf("\nQuantos resistores estao conectados a este no?: ");
                scanf("%d", &r);
                for(int j = 0; j<r; j++){
                    printf("\nCondutancia %d: ",j+1);
                    scanf("%f", &glinha);
                    summation = summation + glinha;
                }

                cost = current/summation;
                summations[i] = summation;
            }
            else if(option = 'h'){
                float voltage = 0;
                printf("\nQual a tensao em no %d?: ", i);
                scanf("%f", &voltage);
                cost = -voltage;
            }
            createVertex(circ, i, cost);
        }
        printAdjList(circ);
        char option = 'y';
        fflush(stdin);
        printf("\n**************************************************\n");
        printf("Criacao de arcos");
        printf("\n**************************************************\n");
        printf("Criar novo arco? (y/n): ");
        scanf("%c", &option);
        while(option == 'y'){

            int vx, vy = 0;
            printf("\nInforme o primeiro no do arco: ");
            scanf("%d", &vx);

            printf("\nInforme o segundo no do arco: ");
            scanf("%d", &vy);

            float g=0;
            printf("\nQual e a condutancia entre os nos %d e %d?: ", vx, vy);
            scanf("%f", &g);

            float p = g/summations[vx];
            GRAPHinsertArc(circ, vx, circ->v_list[vy], p);

            printf("\nArco criado com sucesso!\n");

            fflush(stdin);
            printf("\n**************************************************\n");
            printf("Criacao de arcos");
            printf("\n**************************************************\n");
            printf("Criar novo arco? (y/n): ");
            scanf("%c", &option);
            if(option == 'n')
                break;
        }
        printf("\n**************************************************\n");
        printf("Arcos criados com sucesso!");
        printf("\n**************************************************\n");
        printAdjList(circ);
        walker* e = malloc(sizeof(e));
        e->balance = 0;
        e->vertex_id = 0;
        sim(e, circ, 200);
        printf("\n********************************************\n");
        printf("Resultado = %.4f V",e->balance);
    }
    else
        exit(0);
}

