// Лаба 4.c : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct save_word
{
    const char* word;
    int print;
    int num;
};



//-----------------------------------------------------------------------------
int GetWord(struct save_word* words, char* text)
{
    int num = 0;
    int number = 0;
    while (text[num - 1] != '\0')
    {
        int save_pos = 0;
        int i;

        for (i = num; text[i] != ' ' && text[i] != '\0'; i++);

        char* temp_word = (char*)calloc(i - num, sizeof(char));
        int j = 0;
        for (i = num; text[i] != ' ' && text[i] != '\0'; i++, j++)
        {
            temp_word[j] = text[i];
        }
        temp_word[j] = '\0';
        num = ++i;
        words[number].word = temp_word;
        words[number].print = 1;
        words[number].num = 1;
        number++;
    }
    return number;
}

int check(char* word_1, char* word_2)
{
    for (int i = 0; word_1[i] != '\0' || word_2[i] != '\0'; i++)
        {
            if (word_1[i] != word_2[i])
            {
                return 0;
            }
        }
    return 1;
}

check_index(char word_1, char word_2, int j, int small_index)
{
    if (word_1 < word_2)
    {
        return j;
    }
    return small_index;
}

//-----------------------------------------------------------------------------
void PrintAllWords(struct save_word* words, char* text)
{

        int number = GetWord(words, text);
        for (int i = 0; i < number - 1; i++)
        {
            for (int j = i + 1; j < number; j++)
            {
                if (check(words[i].word, words[j].word) != 0)
                {
                    words[i].num++;
                    words[j].print = 0;
                }
            }
        }
        for (int i = 0; i < number - 1; i++)
        {
            int small_index = i;
                for (int j = i + 1; j < number; j++)
                {
                    small_index = check_index(words[j].word[0], words[small_index].word[0], j, small_index);
                    
                    if (words[j].word[0] == words[small_index].word[0])
                    {
                        for (int k = 0; words[j].word[k] != '\0' && words[small_index].word[k] != '\0'; k++)
                        {
                            small_index = check_index(words[j].word[k], words[small_index].word[k], j, small_index);
                        }
                    }
                }              
                struct save_word temp = words[small_index];
                words[small_index] = words[i];
                words[i] = temp; 

        }
        
        for (int i = 0; i < number; i++)
        {
            if (words[i].print == 1)
            {
                printf("%s - %d \n", words[i].word, words[i].num);
            }
        }
}
//-----------------------------------------------------------------------------

int main(int argc, const char* argv[])
{
    struct save_word* words = (struct save_word*)calloc(100, sizeof(struct save_word));
    char text[] = "cat cat dog bat k "
        "selection of characters as white-space";

    PrintAllWords(words, text);

    return 0;
}