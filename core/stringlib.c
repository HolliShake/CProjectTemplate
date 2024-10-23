#include "stringlib.h"
#include "utf/utfc.h"

char *stringlib_new(const char *__str) {
    char *newstr = (char*) gc_malloc(strlen(__str) + 1);
    CHECKMALLOC(newstr);
    newstr[0] = '\0';
    strcpy(newstr, __str);
    return newstr;
}

char* stringlib_dup(char* __str) {
    return stringlib_new((const char*) __str);
}

char *stringlib_format(const char *__format, ...) {
    va_list args;
    va_start(args, __format);
    size_t size = vsnprintf(NULL, 0, __format, args) + 1;
    va_end(args);
    char* buffer = gc_malloc(size);
    CHECKMALLOC(buffer);
    va_start(args, __format);
    vsnprintf(buffer, size, __format, args);
    va_end(args);
    return buffer;
}

char* stringlib_concat(char* __str1, char* __str2) {
    size_t size = strlen(__str1) + strlen(__str2) + 1;
    char* buffer = gc_malloc(size);
    CHECKMALLOC(buffer);
    buffer[0] = '\0';
    strcat(buffer, __str1);
    strcat(buffer, __str2);
    return buffer;
}

char* stringlib_substring(char* __str, size_t start, size_t end) {
    size_t str_len = stringlib_length(__str);

    if (start > end || start >= str_len || end > str_len) {
        fprintf(stderr, "Invalid substring range or index out of bounds.\n");
        exit(1);
    }

    const char* str_start = __str;
    size_t byte_offset_start = 0;
    size_t char_pos = 0;

    while (char_pos < start) {
        size_t char_size = utf_size_of_utf((unsigned char)str_start[byte_offset_start]);
        byte_offset_start += char_size;
        char_pos++;
    }

    const char* str_end = str_start + byte_offset_start;
    size_t byte_offset_end = byte_offset_start;

    while (char_pos < end) {
        size_t char_size = utf_size_of_utf((unsigned char)str_end[byte_offset_end - byte_offset_start]);
        byte_offset_end += char_size;
        char_pos++;
    }

    size_t byte_size = byte_offset_end - byte_offset_start;

    char* buffer = gc_malloc(byte_size + 1);
    CHECKMALLOC(buffer);

    strncpy(buffer, __str + byte_offset_start, byte_size);
    buffer[byte_size] = '\0';

    return buffer;
}

char* stringlib_trim(char* __str) {
    size_t len = stringlib_length(__str);
    size_t start = 0;
    size_t end = len - 1;

    // Skip leading whitespace
    while (start < len && utf_is_white_space(utf_char_code_at(__str, start))) {
        start++;
    }

    // Skip trailing whitespace
    while (end >= start && utf_is_white_space(utf_char_code_at(__str, end))) {
        end--;
    }

    // Return the substring without leading or trailing whitespace
    // `end + 1` because substring functions often take an exclusive `end`
    return stringlib_substring(__str, start, end + 1);
}

char* stringlib_replace(char* __str, char* __find, char* __replace) {
    size_t findlen = strlen(__find);
    size_t replen = strlen(__replace);
    size_t size = strlen(__str) + 1;
    char* buffer = gc_malloc(size);
    CHECKMALLOC(buffer);
    buffer[0] = '\0';

    const char* str_ptr = __str;
    size_t str_len = strlen(__str);

    while (*str_ptr != '\0') {
        size_t char_size = utf_size_of_utf((unsigned char)*str_ptr);
        
        if (utf_char_code_at((char*) str_ptr, 0) == utf_char_code_at(__find, 0)) {
            if (strncmp(str_ptr, __find, findlen) == 0) {
                strcat(buffer, __replace);
                str_ptr += findlen;
                continue;
            }
        }

        strncat(buffer, str_ptr, char_size);
        str_ptr += char_size;
    }

    return buffer;
}

char* stringlib_replace_all(char* __str, char* __find, char* __replace) {
    size_t findlen = strlen(__find);
    size_t replen = strlen(__replace);
    size_t size = strlen(__str) + 1;
    char* buffer = gc_malloc(size);
    CHECKMALLOC(buffer);
    buffer[0] = '\0';

    const char* str_ptr = __str;
    size_t str_len = strlen(__str);

    while (*str_ptr != '\0') {
        size_t char_size = utf_size_of_utf((unsigned char)*str_ptr);
        
        if (utf_char_code_at((char*) str_ptr, 0) == utf_char_code_at(__find, 0)) {
            if (strncmp(str_ptr, __find, findlen) == 0) {
                strcat(buffer, __replace);
                
                str_ptr += findlen;
                
                size_t new_size = strlen(buffer) + strlen(str_ptr) + replen + 1;
                buffer = gc_realloc(buffer, new_size);
                CHECKMALLOC(buffer);
                
                continue;
            }
        }

        strncat(buffer, str_ptr, char_size);
        str_ptr += char_size;
    }

    return buffer;
}

size_t stringlib_length(char* __str) {
    return utf_length(__str);
}

size_t stringlib_char_code_at(char* __str, size_t index) {
    return utf_char_code_at(__str, index);
}

char* stringlib_char_at(char* __str, size_t index) {
    return utf_char_at(__str, index);
}

char* stringlib_nfkc(char* __str) {
    return utf_nfkc(__str);
}

bool stringlib_is_identifier(char* __str) {
    if (strlen(__str) == 0) {
        return false;
    }
    if (!utf_is_letter(utf_char_code_at(__str, 0))) {
        return false;
    }
    for (size_t i = 1; i < strlen(__str); i++) {
        if (!utf_is_letter_or_digit(utf_char_code_at(__str, i))) {
            return false;
        }
    }
    return true;
}

bool stringlib_is_whitespace(char* __str) {
    for (size_t i = 0; i < strlen(__str); i++) {
        if (!utf_is_white_space(utf_char_code_at(__str, i))) {
            return false;
        }
    }
    return true;
}

bool stringlib_is_digit(char* __str) {
    for (size_t i = 0; i < strlen(__str); i++) {
        if (!utf_is_digit(utf_char_code_at(__str, i))) {
            return false;
        }
    }
    return true;
}