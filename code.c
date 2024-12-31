#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saisie_phrase(char *t, int n) {
    printf("Donner votre phrase:\n");
    fgets(t, n, stdin);
    t[strcspn(t, "\n")] = '\0'; // Remove trailing newline
}

int cherche_mot_phrase(const char *t, const char *m, char **rep, int max_occurrences) {
    int count = 0;
    char *word = strtok((char *)t, " ");

    while (word != NULL && count < max_occurrences) {
        if (strcmp(word, m) == 0) {
            rep[count] = word;
            count++;
        }
        word = strtok(NULL, " ");
    }

    return count;
}

int main() {
    char t[50], m[12];
    char *rep[10]; // Array of pointers to found words

    saisie_phrase(t, 50);
    saisie_phrase(m, 12);

    int num_occurrences = cherche_mot_phrase(t, m, rep, 10);

    if (num_occurrences > 0) {
        printf("Number of repetitions of '%s'is %d\n",m,num_occurrences );
        printf("Occurrences of '%s':\n", m);
        for (int i = 0; i < num_occurrences; i++) {
            printf("%s\n", rep[i]);
        }
    } else {
        printf("Word '%s' not found.\n", m);
    }

    return 0;
}

