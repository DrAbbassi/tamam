#include <stdio.h>
#include <string.h>

int main() {
    char name[20];
    char input[100];

    printf("Hi, what's your name? ");
    scanf("%s", name);

    printf("Nice to meet you, %s! How are you today?\n", name);

    while (1) {
        printf("%s: ", name);
        scanf("%[^\n]%*c", input);

        if (strcmp(input, "good") == 0 || strcmp(input, "Good") == 0) {
            printf("Chatbot: That's great to hear!\n");
        } else if (strcmp(input, "bad") == 0 || strcmp(input, "Bad") == 0) {
            printf("Chatbot: I'm sorry to hear that. Is there anything I can help with?\n");
        } else if (strcmp(input, "quit") == 0 || strcmp(input, "Quit") == 0) {
            break;
        } else {
            printf("Chatbot: I don't understand what you're saying. Can you rephrase that?\n");
        }
    }

    printf("Chatbot: Goodbye, %s! Have a great day!\n", name);

    return 0;
}
