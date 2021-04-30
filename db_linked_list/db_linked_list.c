// === Source file: db_linked_list.c ===

#include "db_linked_list.h"

void init_db_list(db_linked_list_t *l)
{
	node_t *sent_init, *sent_end;

	sent_init = (node_t *)malloc(sizeof(node_t));
	sent_end = (node_t *)malloc(sizeof(node_t));

	if (!sent_init || !sent_end)
	{
		fprintf(stderr, "Memory allocation error!\n");
		exit(1);
	}

	l->init = sent_init;
	l->end = sent_end;

	sent_init->before = NULL;
	sent_init->next = sent_end;

	sent_end->before = sent_init;
	sent_end->next = NULL;

	l->now = NULL;
	l->size = 0;
}

int empty_db_list(db_linked_list_t *l)
{
	if (destroyed_db_list(l))
		return 0;
	return (l->init->next == l->end);
}

int destroyed_db_list(db_linked_list_t *l)
{
	return (l->init == NULL);
}

void destroy_db_list(db_linked_list_t *l)
{
	if (destroyed_db_list(l))
		return;

	while (!(empty_db_list(l)))
	{
		init_now_begin_db_list(l);

		l->init->next = l->now->next;
		l->now->next->before = l->init;

		free(l->now);
	}

	free(l->init);
	free(l->end);

	l->init = NULL;
	l->now = NULL;
	l->end = NULL;

	l->size = 0;
}

int db_list_size(db_linked_list_t *l)
{
	return l->size;
}

void init_now_begin_db_list(db_linked_list_t *l)
{
	if (empty_db_list(l) || destroyed_db_list(l))
		return;
	l->now = l->init->next;
}

void init_now_end_db_list(db_linked_list_t *l)
{
	if (empty_db_list(l) || destroyed_db_list(l))
		return;
	l->now = l->end->before;
}

void add_now_db_list(db_linked_list_t *l)
{
	if (empty_db_list(l) || destroyed_db_list(l))
		return;

	if (l->now != l->end)
		l->now = l->now->next;
}

void sub_now_db_list(db_linked_list_t *l)
{
	if (empty_db_list(l) || destroyed_db_list(l))
		return;

	if (l->now != l->init)
		l->now = l->now->before;
}

void push_front_db_list(int item, db_linked_list_t *l)
{
	if (destroyed_db_list(l))
		return;

	node_t *element = (node_t *)malloc(sizeof(node_t));

	if (!element)
	{
		fprintf(stderr, "Memory allocation error!\n");
		exit(1);
	}

	element->key = item;
	element->before = l->init;
	element->next = l->init->next;

	l->init->next->before = element;
	l->init->next = element;

	l->size++;
}

void push_back_db_list(int item, db_linked_list_t *l)
{
	if (destroyed_db_list(l))
		return;

	node_t *element = (node_t *)malloc(sizeof(node_t));

	if (!element)
	{
		fprintf(stderr, "Memory allocation error!\n");
		exit(1);
	}

	element->key = item;
	element->before = l->end->before;
	element->next = l->end;

	l->end->before->next = element;
	l->end->before = element;

	l->size++;
}

void push_inorder_db_list(int item, db_linked_list_t *l)
{
	if (destroyed_db_list(l))
		return;

	if (empty_db_list(l))
		push_front_db_list(item, l);
	else
	{
		node_t *element = (node_t *)malloc(sizeof(node_t));

		if (!element)
		{
			fprintf(stderr, "Memory allocation error!\n");
			exit(1);
		}

		element->key = item;
		init_now_begin_db_list(l);

		while ((l->now != l->end) && (item >= l->now->key))
			add_now_db_list(l);

		element->next = l->now->before->next;
		element->before = l->now->before;

		l->now->before->next = element;
		l->now->before = element;

		l->size++;
	}
	init_now_begin_db_list(l);
}

void pop_front_db_list(int *item, db_linked_list_t *l)
{
	if (empty_db_list(l) || destroyed_db_list(l))
		return;

	init_now_begin_db_list(l);
	*item = l->now->key;

	l->init->next = l->now->next;
	l->now->next->before = l->init;

	free(l->now);

	l->size--;
	init_now_begin_db_list(l);
}

void pop_back_db_list(int *item, db_linked_list_t *l)
{
	if (empty_db_list(l) || destroyed_db_list(l))
		return;

	init_now_end_db_list(l);
	*item = l->now->key;

	l->now->next->before = l->now->before;
	l->now->before->next = l->end;

	free(l->now);

	l->size--;
	init_now_begin_db_list(l);
}

void pop_now_db_list(int *item, db_linked_list_t *l)
{
	if (empty_db_list(l) || destroyed_db_list(l))
		return;

	node_t *aux = l->now;

	*item = l->now->key;

	l->now->before->next = l->now->next;
	l->now->next->before = l->now->before;

	add_now_db_list(l);

	l->size--;

	free(aux);
}

void check_now_key_db_list(int *item, db_linked_list_t *l)
{
	if (empty_db_list(l) || destroyed_db_list(l))
		return;

	*item = l->now->key;
}

int in_db_list(int item, db_linked_list_t *l)
{
	if (empty_db_list(l) || destroyed_db_list(l))
		return 0;

	init_now_begin_db_list(l);

	l->end->key = item;

	while (l->now->key != item)
		add_now_db_list(l);

	node_t *cmp = l->now;
	init_now_begin_db_list(l);

	return (cmp != l->end);
}

void print_db_list(db_linked_list_t *l)
{
	if (destroyed_db_list(l) || empty_db_list(l))
		return;

	init_now_begin_db_list(l);

	while (l->now != l->end)
	{
		printf("%d ", l->now->key);
		add_now_db_list(l);
	}
	printf("\n");

	init_now_begin_db_list(l);
}

void copy_db_list(db_linked_list_t *l, db_linked_list_t *c)
{
	if (destroyed_db_list(l) || empty_db_list(l))
		return;

	if (!empty_db_list(c))
	{
		destroy_db_list(c);
		init_db_list(c);
	}

	init_now_begin_db_list(l);

	while (l->now != l->end)
	{
		push_back_db_list(l->now->key, c);
		add_now_db_list(l);
	}
	c->size = l->size;

	init_now_begin_db_list(l);
}

void concatenate_db_lists(db_linked_list_t *l, db_linked_list_t *c)
{
	if (destroyed_db_list(l) || destroyed_db_list(c) || empty_db_list(c))
		return;

	l->end->before->next = c->init->next;
	c->init->next->before = l->end->before;

	free(l->end);
	free(c->init);

	l->end = c->end;
	c->end = NULL;

	l->size += c->size;
	c->size = 0;
}

void sort_db_list(db_linked_list_t *l)
{
	if (destroyed_db_list(l) || empty_db_list(l))
		return;

	db_linked_list_t aux;

	init_db_list(&aux);

	while (!empty_db_list(l))
	{
		int key;
		pop_front_db_list(&key, l);
		push_inorder_db_list(key, &aux);
	}
	concatenate_db_lists(l, &aux);
	init_now_begin_db_list(l);
}

void merge_db_lists(db_linked_list_t *l, db_linked_list_t *c, db_linked_list_t *i)
{
	if ((empty_db_list(l) && empty_db_list(c)) || !(empty_db_list(i)))
		return;

	if (destroyed_db_list(l) || destroyed_db_list(c))
		return;

	sort_db_list(l);
	sort_db_list(c);

	init_now_begin_db_list(l);
	init_now_begin_db_list(c);

	while ((l->now != l->end) && (c->now != c->end))
	{
		if (l->now->key < c->now->key)
		{
			push_back_db_list(l->now->key, i);
			add_now_db_list(l);
		}
		else
		{
			push_back_db_list(c->now->key, i);
			add_now_db_list(c);
		}
	}

	while (l->now != l->end)
	{
		push_back_db_list(l->now->key, i);
		add_now_db_list(l);
	}

	while (c->now != c->end)
	{
		push_back_db_list(c->now->key, i);
		add_now_db_list(c);
	}

	init_now_begin_db_list(l);
	init_now_begin_db_list(c);
}
