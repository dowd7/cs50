#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string arg);

int main(int argc, string argv[])
{

    if(argc==2 && only_digits(argv[1]))
    {
        string s = argv[1];
        int shift = atoi(s);
        if(shift > 26)
        {
            shift = shift % 26;
        }
        string cipher = "";

        string word = get_string("plaintext: ");

        for(int i = 0; i < strlen(word); i++)
        {
            if(islower(word[i]))
            {
                word[i] += shift;
                if(word[i] > 122)
                {
                    word[i] -= 26;
                }
            }
        }

        printf("ciphertext: %s\n", word);

        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool only_digits(string arg)
{
    return atoi(arg);
}
