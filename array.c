#include "array.h"
#include "pebble.h"

#ifndef ARRAY
#define ARRAY

//ALWAYS USE SIZE 48, because that's a lot.
void initArray(Array *a, size_t initialSize) {
  a->array = (Event *)malloc(initialSize * sizeof(Event));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, Event element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (Event *)realloc(a->array, a->size * sizeof(Event));
  }
  a->array[a->used++] = element;
}


void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

void removeElement(Array *a, Event e) {
	unsigned int i = 0;

	while(i < a->used) {
		if(a->array[i].start_day == e.start_day &&
			a->array[i].end_day == e.end_day &&
			a->array[i].start_time == e.start_time &&
			a->array[i].end_time == e.end_time) //&& strcmp(a->array[i].title,e.title)) 
		{
	            APP_LOG(APP_LOG_LEVEL_DEBUG, "WE FOUND TWO PEOPLE THAT R ALIKE :)");
			for(unsigned int k = i + 1; k < a->used; k++) {
				a->array[k-1] = a->array[k];
			}
			a->used--;
		}
		i++;
	}
}
#endif
