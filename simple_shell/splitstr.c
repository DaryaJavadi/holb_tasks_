#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **split_string(const char *str)
{
	size_t len = strlen(str);
	char **words = malloc(10 * sizeof(char *));
	int word_count = 0;
	size_t word_len = 0;
	char *word = malloc(len + 1);

	if (words == NULL || word == NULL)
	{
		return NULL;
	}

	for (size_t i = 0; i <= len; i++)
	{
	if (isspace(str[i]) || str[i] == '\0')
	{
		if (word_len > 0)
		{
			word[word_len] = '\0';
			words[word_count++] = strdup(word);
		word_len = 0;
		}
	}
        else
	{
		word[word_len++] = str[i];
	}

	if (word_count >= 10)
	{
		words = realloc(words, (word_count + 10) * sizeof(char *));
		if (words == NULL)
		{
			return NULL;
		}
	}
	}

	words[word_count] = NULL;
	free(word);

	return words;
}

int main(void)
{
	char str[] = "This is a simple test string";
	char **words = split_string(str);

	if (words != NULL)
	{
	for (int i = 0; words[i] != NULL; i++)
	{
		printf("Word %d: %s\n", i + 1, words[i]);
		free(words[i]);
	}

	free(words);
	}
	else
	{
	printf("Memory allocation failed\n");
	}

	return 0;
}

