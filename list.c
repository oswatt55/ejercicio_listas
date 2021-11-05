#include "linked_list.h"
#include <stdlib.h>
struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};
struct list {
   struct list_node *first, *last;
};
struct list *list_create(void){
    struct list *list = malloc(sizeof(struct list *));
    return list;
}
bool list_is_empty(const struct list *list){
    if(list->first) return false;
    return true;
}
bool list_push(struct list *list, ll_data_t item_data){
    struct list_node *node= malloc(sizeof(struct list_node *));
    node->data = item_data;
    if(list->first){
        node->prev = list->last;
        list->last->next = node;
        list->last = list->last->next;
    }else{
        list->first = node;
        list->last = node;
    }
    return true;
}
ll_data_t list_pop(struct list *list){
    ll_data_t popped = list->last->data;
    if(list->last->prev){
        list->last = list->last->prev;
        list->last->next = NULL;
    }else{
        list->first = NULL;
        list->last = NULL;
    }
    return popped;
}
bool list_unshift(struct list *list, ll_data_t item_data){
    struct list_node *node = malloc(sizeof(struct list_node *));
    node->data = item_data;
    if(list->first){
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
    }else{
        list->first = node;
        list->last = node;
    }
    return true;
}
ll_data_t list_shift(struct list *list){
    ll_data_t shifted = list->first->data;
    if(list->first->next){
        list->first = list->first->next;
        list->first->prev = NULL;
    }else{
        list->first = NULL;
        list->last = NULL;
    }
    return shifted;
}
void list_destroy(struct list *list){
    free(list);
}
