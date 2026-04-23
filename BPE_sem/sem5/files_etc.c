#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    float price;
    int id;
} Product;

typedef struct {
    char address[100];
    int productId;
} Order;

typedef struct {
    int id;
    double hourly_rate;
    double hours_worked;
    double weekly_salary;
} Employee;

void birthday() {
    int guests, chairs = 0, tables = 0, cups = 0, dishes = 0;
    double spent = 0;
    char item[50];
    
    printf("Guest count: "); scanf("%d", &guests);
    printf("Enter items (PARTY! to end):\n");
    while(1) {
        scanf("%s", item);
        if(strcmp(item, "PARTY!") == 0) break;
        if(strcmp(item, "chair") == 0) { chairs++; spent += 13.99; }
        else if(strcmp(item, "table") == 0) { tables++; spent += 42.00; }
        else if(strcmp(item, "cups") == 0) { cups += 6; spent += 5.98; }
        else if(strcmp(item, "dishes") == 0) { dishes += 6; spent += 21.02; }
    }

    int needed_tables = (guests + 7) / 8; 
    printf("\nMoney spent: %.2f\n", spent);
    if(needed_tables > tables) printf("%d Table\n", needed_tables - tables);
    if(guests > chairs) printf("%d Chairs\n", guests - chairs);
    if(guests > cups) printf("%d Cups (sets)\n", (guests - cups + 5) / 6);
    if(guests > dishes) printf("%d Dishes (sets)\n", (guests - dishes + 5) / 6);
}

void confectionery() {
    Product products[100]; int p_count = 0;
    Order orders[100]; int o_count = 0;
    char cmd[20];

    printf("Commands: Product, Order, END\n");
    while(scanf("%s", cmd) && strcmp(cmd, "END") != 0) {
        if(strcmp(cmd, "Product") == 0) {
            Product p;
            scanf("%s %f %d", p.name, &p.price, &p.id);
            products[p_count++] = p;
            for(int i = 0; i < o_count; i++) {
                if(orders[i].productId == p.id) {
                    printf("Client %s ordered %s\n", orders[i].address, p.name);
                    for(int j = i; j < o_count - 1; j++) orders[j] = orders[j+1];
                    o_count--; i--;
                }
            }
        } else if(strcmp(cmd, "Order") == 0) {
            Order o; int found = -1;
            scanf("%s %d", o.address, &o.productId);
            for(int i = 0; i < p_count; i++) {
                if(products[i].id == o.productId) { found = i; break; }
            }
            if(found != -1) printf("Client %s ordered %s\n", o.address, products[found].name);
            else orders[o_count++] = o;
        }
    }
}

void word_chain() {
    FILE *fin = fopen("input.txt", "r");
    if(!fin) { printf("Missing input.txt!\n"); return; }
    
    char **arr = malloc(100 * sizeof(char*));
    char word[51]; int count = 0;

    if(fscanf(fin, "%s", word) == 1) {
        arr[count++] = strdup(word);
        char last_char = word[strlen(word)-1];
        while(fscanf(fin, "%s", word) == 1) {
            if(word[0] == last_char) {
                arr[count++] = strdup(word);
                last_char = word[strlen(word)-1];
            }
        }
    }
    fclose(fin);

    FILE *fbin = fopen("words.bin", "wb");
    for(int i = 0; i < count; i++) {
        fwrite(arr[i], 1, strlen(arr[i]), fbin);
        if(i < count - 1) fputc(' ', fbin); 
    }
    fclose(fbin);

    fbin = fopen("words.bin", "rb");
    char ch;
    printf("Data: ");
    while((ch = fgetc(fbin)) != EOF) putchar(ch);
    printf("\n");
    fclose(fbin);
}

void encrypt() {
    char filename[100]; int key;
    printf("File name to encrypt: "); scanf("%s", filename);
    printf("Key: "); scanf("%d", &key);
    
    FILE *src = fopen(filename, "r");
    FILE *dest = fopen("encoded.txt", "w");
    if(!src) return;

    char ch;
    while((ch = fgetc(src)) != EOF) {
        fputc(ch + key, dest);
    }
    fclose(src); fclose(dest);
}

void hangman(char *target) {
    int len = strlen(target);
    char display[50];
    
    for(int i = 0; i < len; i++) display[i] = '_';
    display[len] = '\0';

    int attempts = 0, guessed = 0;
    char letter;

    while(guessed < len) {
        printf("Word: %s | Enter letter: ", display);
        scanf(" %c", &letter);
        attempts++;
        
        int found = 0;
        for(int i = 0; i < len; i++) {
            if(target[i] == letter && display[i] == '_') {
                display[i] = letter;
                guessed++;
                found = 1;
            }
        }
        
        if(!found) printf("Wrong letter!\n");
    }

    printf("\nCorrect word: %s\n", target);
    
    if(attempts <= len + 2) {
        printf("You win! (Attempts: %d)\n", attempts);
    } else {
        printf("You lose! (Too many attempts: %d)\n", attempts);
    }
}

int anagram(char *s1, char *s2) {
    if(strlen(s1) != strlen(s2)) return 0;
    int counts[256] = {0};
    for(int i = 0; s1[i]; i++) {
        counts[(unsigned char)tolower(s1[i])]++;
        counts[(unsigned char)tolower(s2[i])]--;
    }
    for(int i = 0; i < 256; i++) if(counts[i] != 0) return 0;
    return 1;
}

void employee_system() {
    FILE *fp = fopen("staff.bin", "wb+");
    if(!fp) return;
    int n; printf("Employee count (max 30): "); scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        Employee e;
        printf("ID, Hourly rate, Hours worked: ");
        scanf("%d %lf %lf", &e.id, &e.hourly_rate, &e.hours_worked);
        
        double total;
        if(e.hours_worked > 40) total = (40 * e.hourly_rate) + ((e.hours_worked - 40) * e.hourly_rate * 1.5);
        else total = e.hours_worked * e.hourly_rate;
        
        e.weekly_salary = total * (1 - 0.0365); // 
        fwrite(&e, sizeof(Employee), 1, fp);
    }

    rewind(fp);
    Employee e;
    printf("\nSalaries:\n");
    while(fread(&e, sizeof(Employee), 1, fp)) {
        printf("ID: %d | Salary: %.2f lv.\n", e.id, e.weekly_salary);
    }
    fclose(fp);
}

int main() {
    int choice;
    printf("Enter task to run: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: birthday(); break;
        case 2: confectionery(); break;
        case 3: word_chain(); break;
        case 4: encrypt(); break;
        case 5: {
            char word[50];
            printf("Vuvedete duma за igrata: ");
            scanf("%s", word);
            task5_hangman(word);
        }
        case 6: {
            char s1[100], s2[100];
            printf("Enter first word: "); gets(s1);
            printf("Enter second word: "); gets(s2);
            if(anagram(s1, s2)) printf("The words are anagrams.\n");
            else printf("The words are not anagrams.\n");
            break;
        }
        case 7: employee_system(); break;
        default: printf("Invalid choice!");
    }
    return 0;
}

