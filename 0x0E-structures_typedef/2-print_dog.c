#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - Prints all the data of a dog
 * @my_dog: A dog structure
 *
 * Return: Nothing
 */
void print_dog(struct dog *my_dog)
{
	if (my_dog != NULL)
	{
		printf("Name: %s\n", (my_dog->name) ? my_dog->name : "(nil)");
		printf("Age: %f\n", (my_dog->age) ? my_dog->age : 0);
		printf("Owner: %s\n", (my_dog->owner) ? my_dog->owner : "(nil)");
	}
}
