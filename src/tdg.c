#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include "tdg.h"

static unsigned int s_max_number_of_runs = MAX_NUMBER_OF_RUNS;
static void* nextInt(void*);
static void* nextChar(void*);

static Gen _integers = { .next = nextInt };
static Gen _characters = { .next = nextChar };

void TDG_setMaxRun(unsigned int runs)
{
	s_max_number_of_runs = runs;
}

List* toList(Gen* gen)
{
	return toListUntil(gen, s_max_number_of_runs);	
}

List* toListUntil(Gen* gen, unsigned int max)
{
	List* ret = NULL;

	for (int i=0; i<max; i++)
	{
		ret = List_Append(ret, Gen_next(gen));
	}
	return ret;
}


void* Gen_next(Gen* gen)
{
	return gen->next(gen->env);
}

Gen* integers()
{
	return &_integers;
}


Gen* fixedValues(void* arg, ...)
{
	va_list params;

	va_start(params, arg);
	va_end(params);
}

static void* nextFixedValue(void* env)
{

}

Gen* characters()
{
	return &_characters;
}

static void* nextInt(void* env)
{
	return (void*)rand();
}

static void* nextChar(void* env)
{
	char ret = rand() % 256;
	return (void*)ret;
}

List*	List_Create(void* data)
{
	List* r = (List*)calloc(1, sizeof(List));
	r->next = NULL;
	r->data = data;
	return r;
}

List*	List_Append(List* list, void* data)
{
	List *p = list;
	if (NULL == p) return List_Create(data);

	while (NULL != p)
	{
		if (NULL == p->next)
		{
			p->next = List_Create(data);
			break;
		}
		else
		{
			p = p->next;
		}
	}
	assert (p->next);
	return list;
}

List*  findLastNode(List* list)
{
	while (NULL != list)
	{
		if (NULL == list->next)
			return list;

		list = list->next;
	}
	return NULL;
}

List*	List_Concat(List* l1, List* l2)
{
	List* lastNode = findLastNode(l1);
	if (NULL == lastNode) return l2;

	lastNode->next = l2;
	return l1;
}

void 	List_Free(List* list)
{
	while (NULL != list)
	{
		List* next = list->next;
		free (list);
		list = next;
	}
}

int		List_Length(List* list)
{
	int cnt = 0;
	while (NULL != list)
	{
		list = list->next;
		++cnt;
	}
	return cnt;
}
