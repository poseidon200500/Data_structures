#include <stdio.h>
#include <stdlib.h>

//структура данных лежащих в узле списка
typedef struct Data{
    int value;
}data_t;

//структура узла
typedef struct Node{
    struct Node* next;
    data_t data;
}Node_t;

//функция ответственная за создание узла и добавление в него данных
//скорее всего следует её изменять в зависимости от задачи
Node_t* init_node(int new_value){
    Node_t* root = malloc(sizeof(Node_t));
    root->next = NULL;
    root->data.value = new_value;
    return root;
}

//возвращает указатель на добавленный узел
Node_t* add_node(Node_t* node, int new_value){
    Node_t* new_node = init_node(new_value);
    if (node->next == NULL){
        node->next = new_node;
    } else {
        Node_t* tmp = node->next;
        node->next = new_node;
        node->next->next = tmp;
    }
    return node->next;
}

//возвращает указатель на последний элемент
Node_t* add_to_end(Node_t* node, int new_value){
    Node_t* new_node = init_node(new_value);
    while (node->next != NULL){
        node = node->next;
    }
    node->next = new_node;

    return node->next;
}

//удаляет один узел пропуская первые (pass) узлов
void del_node(Node_t* node, int pass){
    for (;pass > 0; pass--){
        node = node->next;
    }
    Node_t* tmp = node->next->next;
    free(node->next);
    node->next = tmp;

}

void del_nodes(Node_t* node, int pass, int count){
    for (;pass > 0; pass--){
        node = node->next;
    }
    Node_t* begin = node;
    node = node->next;
    for(;count>0;count--){
        Node_t* tmp = node->next;
        free(node);
        node = tmp;
    }
    begin->next = node;
}
//освобождает память выделенную на список
//если вы хотите удалить список полностью, надо передать корневой элемент
void del_list(Node_t* root){
    Node_t* tmp;
    while (root->next != NULL){
        tmp = root->next;
        free(root);
        root = tmp;
    }
}

//печатает все узлы списка начиная с переданного
void list_print(Node_t* root){
    while (root != NULL){
        printf("%d->",root->data.value);
        root = root->next;
    }
    printf("NULL\n");
}

/*
int main(){
    Node_t* root = init_node(13);
    Node_t* end = root;
    for (int i = 1; i < 10; i++){
        end = add_node(end,i*3);
    }
    list_print(root);
    del_node(root,0);
    list_print(root);
    del_nodes(root,3,3);
    list_print(root);
    del_list(root);
}
*/