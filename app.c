#include "core/core.h"
#include "core/array.h"
#include "core/stringlib.h"
/**
 | Other imports below.
 */

int start(int argc, char* argv[]) {
    /**
     * EXAMPLES
     * Your code here. 
     */
    Array_string_t_t *arr = array_string_t_new(3, (string_t[]) {"foo", "bar", "baz"});
    array_string_t_push(arr, "qux");
    array_string_t_push(arr, "abc");
    array_string_t_push(arr, "def");
    array_string_t_pop(arr);
    array_string_t_push(arr, "ghi");
    for (size_t i = 0; i < array_string_t_length(arr); i++) {
        printf("%s\n", array_string_t_get(arr, i));
    }
    char* msg = stringlib_format("Hello World from GC %s", "!!!");
    printf("MSG: '%s'\n", msg);
    char* trm = stringlib_trim("  fo😀ooc   ");
    printf("TRM: '%s'\n", trm);
    char* sub = stringlib_substring(trm, 1, 4);
    char* rep = stringlib_replace(sub, "o", "@");
    printf("'%s' '%s' '%s' '%s' '%s'\n", msg, trm, sub, rep, stringlib_replace(rep, "😀", "@"));
    gc_free(msg);
    gc_run();
    return 0;
}


