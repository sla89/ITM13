/*
 ============================================================================
 Name        : Stack2.c
 Author      : Thomas Gaida
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


struct angValue{

	char *name;
	char *vorname;
	int gehalt;
};

struct angestellt {

	struct angValue *value;
	struct angestellt *next;

};

int stackinit(void);
int push(struct angValue *neu);
void pop(void);
void myPrint(struct angValue *data);

struct angestellt *stack_ptr, *stack_help;

int stackinit(void) {
	if ((stack_ptr = malloc(sizeof(struct angestellt))) != NULL) {
		stack_ptr->next = NULL;
		stack_ptr->value=NULL;

		return 1;
	} else {

		return 0;
	}

}

void pop(void) {

	puts("POP");

	stack_help = stack_ptr->next;
	stack_ptr->next = stack_help->next;

	myPrint(stack_help->value);

	free(stack_help);

}

int push(struct angValue *neu) {

	struct angestellt *neuAng=malloc(sizeof(struct angestellt));

	neuAng->value=neu;

	puts("PUSH");
	myPrint(neu);

	neuAng->next = stack_ptr->next;
	stack_ptr->next = neuAng;
	return 1;

}


int main(void) {
	puts("Stack it"); /* prints Stack it */

		struct angValue a1, a2, a3, a4;

		stackinit();

		a1.name="Gaida";
		a1.vorname="Thomas";
		a1.gehalt = 200;

		a2.name="Zagerle";
		a2.vorname= "Michael";
		a2.gehalt = 200;

		a3.name="Wachter";
		a3.vorname="Johannes";
		a3.gehalt = 200;

		a4.name= "L�sser";
		a4.vorname="Stefan";
		a4.gehalt = 200;

		push(&a1);
		push(&a2);
		pop();
		push(&a3);
		push(&a4);
		pop();
		pop();
		pop();

		free(stack_ptr);
		stack_ptr=NULL;
		stack_help=NULL;

		return EXIT_SUCCESS;
}

void myPrint(struct angValue *data) {

	printf("Angestellter: %s %s\n", data->name, data->vorname);
}

