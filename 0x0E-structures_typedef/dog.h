#ifndef _HEADER_
#define _HEADER_

/**
 * struct dog - Dog attributes
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Description: The attributes of a dog.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - Typedef for dog structure
 */
typedef struct dog joy_dog;

void init_dog(struct dog *my_dog, char *name, float age, char *owner);
void print_dog(struct dog *my_dog);
joy_dog *new_dog(char *name, float age, char *owner);
void free_dog(joy_dog *my_dog);

#endif
