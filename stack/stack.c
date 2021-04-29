// === Source file: stack.c ===

#include "stack.h"

void init_stack(stack_t *s)
{
	s->init = NULL;
	s->size = 0;
}

int empty_stack(stack_t *s)
{
	return (s->init == NULL);
}

void destroy_stack(stack_t *s)
{
	while (!empty_stack(s))
	{
		node_t *p = s->init->next;
		free(s->init);
		s->init = p;
	}
	s->size = 0;
}

int stack_size(stack_t *s)
{
	return s->size;
}

void push_stack(int x, stack_t *s)
{
	node_t *element = (node_t *)malloc(sizeof(node_t));

	if (!element)
	{
		fprintf(stderr, "Memory allocation error!\n");
		exit(1);
	}

	element->key = x;
	element->next = s->init;
	s->init = element;
	s->size++;
}

void pop_stack(stack_t *s)
{
	if (empty_stack(s))
		return;

	node_t *p = s->init->next;

	free(s->init);
	s->init = p;
	s->size--;
}

int top_stack(stack_t *s)
{
	return s->init->key;
}
