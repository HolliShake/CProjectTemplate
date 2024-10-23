#include "core.h"

#ifndef CORE_ARRAY_H
#define CORE_ARRAY_H

    #define INITIALIZE_ARRAY_H(element_type)                                                          \
        typedef struct Array_##element_type##_struct Array_##element_type##_t;                        \
        Array_##element_type##_t* array_##element_type##_new(size_t count, element_type elements[]);  \
        void array_##element_type##_push(Array_##element_type##_t* array, element_type element);      \
        element_type array_##element_type##_pop(Array_##element_type##_t* array);                     \
        element_type array_##element_type##_get(Array_##element_type##_t* array, size_t index);       \
        size_t array_##element_type##_length(Array_##element_type##_t* array);                        \

    
    #define INITIALIZE_ARRAY_S(element_type)           \
        typedef struct Array_##element_type##_struct { \
            element_type* data;                        \
            size_t capacity;                           \
            size_t length;                             \
            size_t index;                              \
        } Array_##element_type##_t;                    \
        Array_##element_type##_t* array_##element_type##_new(size_t count, element_type elements[]) {     \
            Array_##element_type##_t* array = gc_malloc(sizeof(Array_##element_type##_t) * (count || 1)); \
            CHECKMALLOC(array);                                                                           \
            array->data = gc_malloc(sizeof(element_type) * 10);                                           \
            CHECKMALLOC(array->data);                                                                     \
            array->capacity = count;                                                                      \
            array->length = count;                                                                        \
            for (array->index = 0; array->index < count; array->index++) {                                \
                array->data[array->index] = elements[array->index];                                       \
            }                                                                                             \
            return array;                                                                                 \
        }                                                                                                 \
        void array_##element_type##_push(Array_##element_type##_t* array, element_type element) {         \
            if (array->index >= array->capacity) {                                                        \
                array->capacity++;                                                                        \
                array->data = gc_realloc(array->data, sizeof(element_type) * array->capacity);            \
                CHECKMALLOC(array->data);                                                                 \
            }                                                                                             \
            array->data[array->index++] = element;                                                        \
            array->length++;                                                                              \
        }                                                                                                 \
        element_type array_##element_type##_pop(Array_##element_type##_t* array) {                        \
            if (array->length == 0) {                                                                     \
                fprintf(stderr, "Array::%s[%ld]: Array is empty!!!\n", __func__, __LINE__);               \
                exit(1);                                                                                  \
            }                                                                                             \
            element_type element = array->data[--array->index];                                           \
            array->length--;                                                                              \
            return element;                                                                               \
        }                                                                                                 \
        element_type array_##element_type##_get(Array_##element_type##_t* array, size_t index) {          \
            if (index >= array->index) {                                                                  \
                fprintf(stderr, "Array::%s[%ld]: Index out of bounds!!!\n", __func__, __LINE__);          \
                exit(1);                                                                                  \
            }                                                                                             \
            return array->data[index];                                                                    \
        }                                                                                                 \
        size_t array_##element_type##_length(Array_##element_type##_t* array) {                           \
            return array->length;                                                                         \
        }                                                                                                 \

    INITIALIZE_ARRAY_H(int8_t);
    INITIALIZE_ARRAY_H(int16_t);
    INITIALIZE_ARRAY_H(int32_t);
    INITIALIZE_ARRAY_H(int64_t);
    INITIALIZE_ARRAY_H(uint8_t);
    INITIALIZE_ARRAY_H(uint16_t);
    INITIALIZE_ARRAY_H(uint32_t);
    INITIALIZE_ARRAY_H(uint64_t);
    INITIALIZE_ARRAY_H(float);
    INITIALIZE_ARRAY_H(double);
    INITIALIZE_ARRAY_H(string_t);

#endif