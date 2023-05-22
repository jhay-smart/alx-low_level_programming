#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - Initializes a dog structure
 * @my_dog: A dog structure.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Return: Nothing
 */
void init_dog(struct dog my_dog, char *name, float age, char *owner)
{
	if (my_dog != NULL)
	{
		my_dog.name = name;
		my_dog.age = age;
		my_dog.owner = owner;
	}
}
