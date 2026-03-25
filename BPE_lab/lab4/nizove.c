#include <stdio.h>

int str_len(char str[]){
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int count_words(char str[]){
    int count = 0;
    int in_word = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'){
            if (!in_word){
                in_word = 1;
                count++;
            }
        }else {
            in_word = 0;
        }
    }
    return count;
}

void count_letters(char str[]){
    int letters[26] = {0};

    for (int i = 0; str[i] != '\0'; i++){
        if (isalpha(str[i])){
            char c = tolower(str[i]);
            letters[c - 'a']++;
        }
    }
    printf("Letters:\n");
    for (int i = 0; i < 26; i++) {
        if (letters[i] > 0) {
            printf("%c: %d\n", i + 'a', letters[i]);
        }
    }
}

int str_comp(char str1[], char str2[]){
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if (str1[i] != str2[i]){
            return 1;
        }
        i++;
    }
    return 0;
}

int main(){
    char text[] = "Zdravejte dragi priqteli!";
    char second_text[] = "Zdravejte dragi priqteli";

    printf("Niz: \"%s\"\n", text);
    
    printf("Length: : %d\n", str_len(text));

    printf("Words count: %d\n", count_words(text));

    count_letters(text);

    if(str_comp(text,second_text)){
        printf("The strings are not similar!");
    } else{
        printf("The strings are similar!");
    }

    return 0;
}