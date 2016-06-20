#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef VECTOR_C_H
#define VECTOR_C_H
#endif

#ifdef __cplusplus
#define V_MALLOC(T)  (T*) malloc(INITIAL_VECTOR_SIZE * sizeof(T))
#define V_RESERVE(T) (T*) realloc(vec->ptr, sizeof(T) * size)
#define V_REALLOC(T) (T*) realloc(vec->ptr, vec->size * sizeof(T) * VECTOR_GROW_FACTOR)
extern "C" {
#else
#define V_MALLOC(T)  malloc(INITIAL_VECTOR_SIZE * sizeof(T))
#define V_RESERVE(T) realloc(vec->ptr, sizeof(T) * size)
#define V_REALLOC(T) realloc(vec->ptr, vec->size * sizeof(T) * VECTOR_GROW_FACTOR)
#endif

/* 
	TYPEDEF				
*/
typedef size_t mem_size; 

/* 
	VECTOR SETTINGS				
*/
#ifndef DEBUG
#define DEBUG 1
#endif

#ifndef INITIAL_VECTOR_SIZE
#define INITIAL_VECTOR_SIZE 8
#endif
#if INITIAL_VECTOR_SIZE < 4
#define INITIAL_VECTOR_SIZE 4
#endif

#ifndef VECTOR_GROW_FACTOR
#define VECTOR_GROW_FACTOR 2
#endif
#if VECTOR_GROW_FACTOR < 1
#define VECTOR_GROW_FACTOR 2
#endif
#if VECTOR_GROW_FACTOR > 8
#define VECTOR_GROW_FACTOR 8
#endif

/* 
	VECTOR AVAIABLE FUNCTIONS			
*/
#define Vector_init(VECTOR, T) Vector_##T VECTOR = {0,               							\
 													                          0, 			   			    					\		
												                            &T##_MALLOC, 					    		\
 												                            &T##_RESERVE,					    		\
					  							                          &T##_FREE,		   							\
					  							                          &T##_PUSHBACK,			  		    \
												                            &T##_POPBACK   								\
													                          }; VECTOR.init(&VECTOR)			  \
														     																	  													  
#define Vector_reserve(VECTOR, SIZE) VECTOR.reserve(&VECTOR, SIZE)			  
#define Vector_clear(VECTOR) VECTOR.clear(&VECTOR.ptr)
#define Vector_push(VECTOR, ELEM) VECTOR.push_back(&VECTOR, &ELEM)
#define Vector_pop(VECTOR) VECTOR.pop_back(VECTOR.ptr, &VECTOR.index)
				  
/* #define Vector_at(VECTOR, INDEX) VECTOR.ptr[INDEX]
   #define Vector_size(VECTOR) VECTOR.index
   #define Vector_capacity(VECTOR) VECTOR.size
   #define Vector_clear_keep_capacity(VECTOR) VECTOR.index = 0	*/
														  
/* 
	VECTOR DEFINITION				
*/												  																									
#define Vector_template(T) 																	                  \
	typedef struct Vector_##T;																	                \
	typedef void (*memory_alloc_##T)(Vector_##T* vec);						        			\
	typedef void (*memory_realloc_##T)(Vector_##T* vec, const mem_size size); 	\
	typedef void (*memory_free_##T)(T** ptr);												            \
	typedef void (*element_pop_##T)(T* ptr, mem_size* index);			  					  \
	typedef void (*element_push_##T)(Vector_##T* vec, const T* elem);					  \
	typedef struct Vector_##T {																                  \
		mem_size              size;																                \
		mem_size              index;															                \
		memory_alloc_##T  	  init;		 	  	 /* Initial memory allocation */			\
		memory_realloc_##T    reserve;  	 	 /* Realloc of the vector */					\
		memory_free_##T	      clear;			   /* Memory free */								    \
		element_push_##T      push_back;		 /* Element push_back */					  	\
		element_pop_##T       pop_back;			 /* Element pop_back */						  	\
																								                              \
		T* ptr;																				                            \
	} Vector_##T;																		                            \																	
																								                              \
	void T##_MALLOC(Vector_##T* vec) {															            \
		vec->ptr = V_MALLOC(T); 						        								              \
		if (vec->ptr == NULL) {																	                  \
			printf("ERROR: Memory allocation fail\n");										        	\
			return;																				                          \
		} vec->size = INITIAL_VECTOR_SIZE;														            \							   	 								
	}																							                              \
																								                              \
	void T##_RESERVE(Vector_##T* vec, const mem_size size) {									  \
		if(vec->size < size) {vec->ptr = V_RESERVE(T);}			   								    \	
		if (vec->ptr == NULL) {																	                  \
			printf("ERROR: Memory re-allocation fail\n");										        \
			return;																				                          \
		}																						                              \
		vec->size = size; 																		                    \
	}																							                              \
																								                              \
	void T##_PUSHBACK(Vector_##T* vec, const T* elem) {											    \														
		if(vec->index == vec->size) {															                \
			vec->ptr = V_REALLOC(T);															                  \
			if (vec->ptr == NULL) {																                  \
				printf("ERROR: Memory re-allocation fail\n"); return;							    \
			}																					                              \
			vec->size *= VECTOR_GROW_FACTOR; 													              \		
		}																						                              \																						
		*(vec->ptr + vec->index) = *elem; 								   						          \
		vec->index += 1;																		                      \
	}																							                              \
																								                              \
	void T##_POPBACK(T* ptr, mem_size* index) {  											          \
		if(*index == 0) 																		                      \
			return;																				                          \
		*index -= 1;																			                        \		
	}																							                              \
																								                              \
	void T##_FREE(T** ptr) {																	                  \
		free(*ptr);																				                        \
	}																							                              \
																								                              \		
#ifdef __cplusplus
}
#endif

	
	
							