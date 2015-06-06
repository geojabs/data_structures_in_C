#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node_t;

node_t* iniciarLista(node_t *lista){
    lista = (node_t*)malloc(sizeof(node_t));

    printf("Digite o valor: ");
    scanf("%i", &lista->val);

    lista->next = NULL;
    return lista;
}

node_t* adicionarInicio(node_t *lista){

    node_t *novo = malloc(sizeof(lista));
    printf("Digite o valor: ");
    scanf("%i", &novo->val);

    novo->next = lista;
    return novo;
}

node_t* adicionarFim(node_t *lst){
    node_t* atualItem = lst;

    while(atualItem->next != NULL){
        atualItem = atualItem->next;
    }

    node_t* novo = malloc(sizeof(node_t));
    printf("Digite o valor: ");
    scanf("%i", &novo->val);

    novo->next = NULL;
    atualItem->next = novo;

    return lst;
}

node_t* removerItem(node_t* lista, int valor){

    node_t *itemRemover = lista;
    node_t *itemAnterior;

    int encontrou = 0;

    while(itemRemover->val != valor){
        itemAnterior = itemRemover;
        itemRemover = itemRemover->next;

        if(itemRemover->val == valor){
            encontrou = 1;
        }
    }

    if(encontrou == 1){
        itemAnterior->next = itemRemover->next;
        free(itemRemover);
        printf("Item removido!");
    }else{
        printf("Item nao encontrado!");
    }

    return lista;
}


void listarTudo(node_t* lst){
    node_t *item = lst;

    while(item != NULL){
        printf("%i\n", item->val);
        item = item->next;
    }

}

int main(){

    node_t* lista = NULL;
    int op_inserir = 1;
    int valor_remover;

    while(op_inserir > 0){

        if(lista == NULL){

            printf("Inserindo primeiro item na lista\n\n");
            lista = iniciarLista(lista);

        }else{
            printf("Onde desejas inserir: \n");
            printf("1 - No inicio da lista\n");
            printf("2 - No fim da lista\n");
            printf("3 - Mostrar tudo\n");
            printf("4 - Remover um item\n");
            printf("0 - Sair do sistema\n");
            scanf("%i", &op_inserir);

            if(op_inserir == 1){

                lista = adicionarInicio(lista);

            }else if(op_inserir == 2){

                lista = adicionarFim(lista);

            }else if(op_inserir == 4){

                printf("\n\nValor que desejas remover: ");
                scanf("%i", &valor_remover);
                lista = removerItem(lista, valor_remover);

            }else if(op_inserir == 3){

                printf("Listagem completa\n\n");
                listarTudo(lista);
            }
        }
    }

    return 0;
}
