/*
 * stack.h
 *
 *  Created on: Apr 15, 2019
 *      Author: bblouin
 */

#ifndef SRC_STACK_H_
#define SRC_STACK_H_
#define DEFAULT_CAPACITY 5

typedef char* stack_item;
struct stack {
   size_t capacity;
   size_t size;
   stack_item *data;
};
typedef struct stack stack;
stack *Stack(void){
    stack *s = malloc(sizeof(stack));
    s->capacity = DEFAULT_CAPACITY;
    s->size = 0;
    s->data = malloc(s->capacity * sizeof(stack_item));
    return s;
}
int full_stack(stack *this){
    return this->capacity == this->size;
}

int empty_stack(stack *this){
    return this->size == 0;
}

void realloc_stack(stack *this){
    this->capacity += DEFAULT_CAPACITY;
    this->data = realloc(this->data, this->capacity*sizeof(stack_item));
}

void push_stack (stack *this, stack_item item) {
    if (full_stack (this))
        realloc_stack (this);
    this->data[this->size++]=item;
}

stack_item pop_stack (stack *this) {
    assert (!empty_stack (this));
    if(this->data == NULL){
        fprintf(stderr, "fail");
        exit(1);//Maybe malloc or realloc
    }
    return this->data[--(this->size)];
}
#endif /* SRC_STACK_H_ */
