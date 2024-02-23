#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Computing the average number of sentences per 100 words
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    // Compute the Coleman-Liau index
    float index = (0.0588 * L - 0.296 * S - 15.8);

    // Print the grade level
    printf("%f\n", round(index));

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string text)
{
    // Return the number of letters in text
    int nl = 0;
    for (int i = 0, t_len = strlen(text); i < t_len; i++)
    {
        if (isalpha((text[i])))
        {
            nl++;
        }
    }
    return nl;
}
int count_words(string text)
{
    // Return the number of words in text
    int spaces = 0;
    for (int i = 0, t_len = strlen(text); i < t_len; i++)
    {
        // Number of words is equal to the number of space + 1
        if (isspace(text[i]) != 0)
        {
            spaces++;
        }
    }
    spaces++;
    return spaces;
}
int count_sentences(string text)
{
    int sentences = 0;
    // Return the number of sentences in text
    for (int i = 0, t_len = strlen(text); i < t_len; i++)
    {
        // Number of words is equal to the number of space + 1
        // if(ispunct((text[i])) && (isspace(text[i + 1])))
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    // This has been the most
    return sentences;
}