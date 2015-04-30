#include <CppUTest/CommandLineTestRunner.h>

extern "C"
{
	#include <stdio.h>
	#include "tdg.h"
}

TEST_GROUP(TDG_Basic)
{
	List* values;

	void setup()
	{
		values = NULL;
	}

	void teardown()
	{
		List_Free(values);
	}

};

TEST(TDG_Basic, integers)
{
	Gen* any = integers();
	values = toList(any);

	for ( ; values->next != NULL; values = values->next)
	{
		int x = (int)values->data;
		printf ("%d\n", x);
	}
}

TEST(TDG_Basic, characters)
{
	Gen* any = characters();
	values = toList(any);

	for ( ; values->next != NULL; values = values->next)
	{
		char x = (char)values->data;
		printf ("%c\n", x);
	}
}

Gen* genIntBoundaries(int boundary)
{
		Gen* gen = fixedValues(
						boundary-1,
						boundary,
						boundary);

		return gen;
}


TEST(TDG_Basic, boundaryGenerator)
{
	Gen* boundaries = genIntBoundaries(10);
	values = toList(boundaries);

	for ( ; values->next != NULL; values = values->next)
	{
		int x = (int)values->data;
		printf ("%d\n", x);
	}
}

