#include <cs50.h>
#include <stdio.h>

int confirm(string name, int age);

int main(void)
{
    string name;
    int age;
    int answer;
    do
    {

        // Name
        name = get_string("What\'s you\'re name? ");

        // Age
        age = get_int("How old are you? ");

        // Confirm
        answer = confirm(name, age);

    }
    while (answer != 1);
    printf("Great! Nice to meet you, %s!\n", name);
}

int confirm(string name, int age)
{
    int answer = get_int("So you\'re %s and you\'re %i? [1 = YES, 0 = NO]\n", name, age);
    return answer;
}
