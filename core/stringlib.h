#include "core.h"

#ifndef CORE_STRINGLIB_H
#define CORE_STRINGLIB_H
    /**
     * @brief Creates a new string from the given string.
     * @param __str The string to create a new string from.
     * @return The new string.
     */
    char *stringlib_new(const char *__str);

    /**
     * @brief Duplicates the given string.
     * @param __str The string to duplicate.
     * @return The duplicated string. 
     */
    char *stringlib_dup(char *__str);

    /**
     * @brief Formats the given string with the given arguments.
     * @param __format The format string.
     * @param ... The arguments to format.
     * @return The formatted string.
     */
    char *stringlib_format(const char *__format, ...);

    /**
     * @brief Concatenates the given strings.
     * @param __str1 The first string.
     * @param __str2 The second string.
     * @return The concatenated string.
     */
    char* stringlib_concat(char* __str1, char* __str2);

    /**
     * @brief Returns a substring of the given string.
     * @param __str The string to get the substring from.
     * @param start The start index of the substring.
     * @param end The end index of the substring.
     * @return The substring.
     */
    char* stringlib_substring(char* __str, size_t start, size_t end);

    /**
     * @brief Trims the given string.
     * @param __str The string to trim.
     * @return The trimmed string.
     */
    char* stringlib_trim(char* __str);

    /**
     * @brief Replaces the first occurrence of the find string with the replace string.
     * @param __str The string to replace the find string in.
     * @param __find The string to find.
     * @param __replace The string to replace the find string with.
     * @return The string with the first occurrence of the find string replaced.
     */
    char* stringlib_replace(char* __str, char* __find, char* __replace);

    /**
     * @brief Replaces all occurrences of the find string with the replace string.
     * @param __str The string to replace the find string in.
     * @param __find The string to find.
     * @param __replace The string to replace the find string with.
     * @return The string with all occurrences of the find string replaced.
     */
    char* stringlib_replace_all(char* __str, char* __find, char* __replace);

    /**
     * @brief Returns the length of the given string.
     * @param __str The string to get the length of.
     * @return The length of the string.
     */
    size_t stringlib_length(char* __str);

    /**
     * @brief Returns the character length of the given string.
     * @param __str The string to get the character length of.
     * @return The character length of the string.
     */
    size_t stringlib_char_code_at(char* __str, size_t index);

    /**
     * @brief Returns the character at the given index of the given string.
     * @param __str The string to get the character from.
     * @param index The index of the character.
     * @return The character at the given index.
     */
    char* stringlib_char_at(char* __str, size_t index);

    /**
     * @brief Returns the NFKC normalized string.
     * @param __str The string to normalize.
     * @return The NFKC normalized string.
     */
    char* stringlib_nfkc(char* __str);

    /**
     * @brief Returns the length of the given string.
     * @param __str The string to get the length of.
     * @return The length of the string.
     */
    bool stringlib_is_identifier(char* __str);

    /**
     * @brief Returns the length of the given string.
     * @param __str The string to get the length of.
     * @return The length of the string.
     */
    bool stringlib_is_whitespace(char* __str);

    /**
     * @brief Returns the length of the given string.
     * @param __str The string to get the length of.
     * @return The length of the string.
     */
    bool stringlib_is_digit(char* __str);
#endif