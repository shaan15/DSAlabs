#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

struct person{
char *name;
int age;
int ht;
int wt;
};

struct person *person_create(char *name,int age, int ht,int wt)
{
struct person *who=malloc(sizeof(struct person));
assert(who!=NULL);
who -> name = strdup(name);
who -> age = age;
who -> ht = ht;
who -> wt = wt;

return who;
}

void person_destroy(struct person *who)
{
assert(who != NULL);
free(who -> name);
free(who);
}

void person_print(struct person *who)
{
printf("name: %s \n",who->name);
printf("\tage: %d\n",who->age);
printf("\tht: %d\n",who->ht);
printf("\twt: %d\n",who->wt);
}

int main(int agrc,char *argv[])
{
struct person *joe=person_create("joe alex",32,64,140);
struct person *frank=person_create("frank blank",20,72,180);
//print the 2 person profiles and their memory location
printf("joe is at memory location %p: \n",joe);
person_print(joe);
printf("frank is at memory location %p: \n",frank);
person_print(frank);
//make everyone 20 yrs and print again
joe->age+=20;
joe->ht-=2;
joe->wt+=40;
person_print(joe);

frank->age+=20;
frank->wt+=20;
person_print(frank);
//destroy them both so that can clean up
person_destroy(joe);
person_destroy(frank);
return 0;
}
