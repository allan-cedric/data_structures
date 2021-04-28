// === Source file: linked_list.c ===

#include "linked_list.h"

void init_list(linked_list_t *l)
{
	l->init = NULL;
	l->size = 0;
}

int empty_list(linked_list_t *l)
{
	return (l->init == NULL);
}

void destroy_list(linked_list_t *l)
{
	if (empty_list(l))
		return;

	node_t *p;

	while (!empty_list(l))
	{

		p = l->init->next;
		free(l->init);
		l->init = p;
	}

	l->size = 0;
}

void push_front_list(int x, linked_list_t *l)
{
	node_t *element = (node_t *)malloc(sizeof(node_t));

	if (!element)
	{
		fprintf(stderr, "Memory allocation error!\n");
		exit(1);
	}

	element->key = x;
	element->next = l->init;
	l->init = element;

	l->size++;
}

void push_back_list(int x, linked_list_t *l)
{
	if (empty_list(l))
	{
		push_front_list(x, l);
		return;
	}

	node_t *element, *p;

	element = (node_t *)malloc(sizeof(node_t));

	if (!element)
	{
		fprintf(stderr, "Memory allocation error!\n");
		exit(1);
	}

	p = l->init;

	while (p->next)
		p = p->next;

	element->key = x;
	p->next = element;
	element->next = NULL;

	l->size++;
}

void push_inorder_list(int x, linked_list_t *l)
{
	if (empty_list(l) || x < l->init->key)
	{
		push_front_list(x, l);
		return;
	}

	node_t *before, *p;

	before = NULL;
	p = l->init;

	while (x >= p->key && p->next)
	{
		before = p;
		p = p->next;
	}

	node_t *element = (node_t *)malloc(sizeof(node_t));

	if (!element)
	{
		fprintf(stderr, "Memory allocation error!\n");
		exit(1);
	}

	element->key = x;
	if (x >= p->key)
	{
		p->next = element;
		element->next = NULL;
	}
	else
	{
		before->next = element;
		element->next = p;
	}

	l->size++;
}

void pop_front_list(int *item, linked_list_t *l)
{
	if (empty_list(l))
		return;

	node_t *p = l->init->next;

	*item = l->init->key;

	free(l->init);

	l->init = p;

	l->size--;
}

void pop_back_list(int *item, linked_list_t *l)
{
	if (empty_list(l))
		return;

	node_t *before, *p;

	before = NULL;
	p = l->init;

	while (p->next)
	{
		before = p;
		p = p->next;
	}

	*item = p->key;

	free(p);

	if (before)
		before->next = NULL;

	l->size--;
}

void pop_list(int key, int *item, linked_list_t *l)
{
	if (empty_list(l))
		return;

	node_t *before, *p;

	before = NULL;
	p = l->init;

	while (p->key != key && p->next)
	{
		before = p;
		p = p->next;
	}

	if (p->key != key)
		return;

	*item = p->key;

	if (!before)
		l->init = l->init->next;
	else
		before->next = p->next;

	free(p);

	l->size--;
}

int in_list(int key, linked_list_t *l)
{
	if (empty_list(l))
		return 0;

	node_t *p = l->init;

	while (p->key != key && p->next)
		p = p->next;

	return (p->key == key);
}

void concatenate_lists(linked_list_t *l, linked_list_t *m)
{
	if (empty_list(m))
		return;

	node_t *p = l->init;

	if (!empty_list(l))
	{
		while (p->next)
			p = p->next;
		p->next = m->init;
	}
	else
		l->init = m->init;

	l->size += m->size;
}

void copy_list(linked_list_t *l, linked_list_t *m)
{
	init_list(m);

	if (empty_list(l))
		return;

	node_t *p = l->init;

	while (p->next)
	{
		push_back_list(p->key, m);
		p = p->next;
	}

	push_back_list(p->key, m);
}

void print_list(linked_list_t *l)
{
	if (!empty_list(l))
	{
		node_t *p = l->init;

		while (p->next)
		{
			printf("%d ", p->key);
			p = p->next;
		}
		printf("%d\n", p->key);
	}
}
