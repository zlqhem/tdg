#ifndef __TDG_H__
#define __TDG_H__

#define MAX_NUMBER_OF_RUNS 200
#define ALLOC(T)	(T*)calloc(1, sizeof(T))

// TDG configuration
extern void TDG_setMaxRun(unsigned int);

typedef struct _List {
	void*			data;
	struct _List* 	next;
} List;

typedef void* (*generator) (void* env);

// Gen: generator
typedef struct _Gen {
	generator next;
	void* env;				// optional data for generating a value
} Gen;

extern void* Gen_next(Gen* gen);

// Iterable
extern List* toList(Gen* gen);
extern List* toListUntil(Gen* gen, unsigned int max);

// Primitive Gen
extern Gen* integers(void);
extern Gen* fixedValues(void* arg, ...);
extern Gen* characters(void);
extern Gen* anyFloat(void);


// Combinator
//	oneOf
//	pairs
//	ensureValues
//	frequency

// Combined Gen

// List
extern List*	List_Create(void* data);
extern List*	List_Append(List*, void* data);
extern List*	List_Concat(List*, List*);
extern void 	List_Free(List*);
extern int		List_Length(List*);

#endif 

