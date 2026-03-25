#include <stdio.h>

float square_area(float a){
    return a*a;
}

float rectangle_area(float a, float b){
    return a*b;
}

float triangle_area(float a, float b){
    return (a * b)/2;
}

float circle_area(float r) {
    return 3.14159 * r * r;
}

void switch_numbers(){
    int a, b, c;
    printf("Enter a and b: ");
    scanf("%f %f", &a, &b);

    c = a;
    a = b;
    b = c;
}

void even_or_odd(){
    int number;
    printf("Enter number: ");
    scanf("%d", &number);

    if (number % 2 == 0){
        printf("The number is even.");
    } else {
        printf ("The number is odd.");
    }
}

int main() {

    int code;
    float a, b, r, area;

    printf("Enter figure code (1-square, 2-rectangle, 3-right triangle, 4-circle): ");
    scanf("%d", &code);

    switch(code) {

        case 1:
            printf("Enter side: ");
            scanf("%f", &a);
            area = square_area(a);
            printf("Figure: Square\nArea = %.2f", area);
            break;

        case 2:
            printf("Enter sides a and b: ");
            scanf("%f %f", &a, &b);
            area = rectangle_area(a, b);
            printf("Figure: Rectangle\nArea = %.2f", area);
            break;

        case 3:
            printf("Enter sides a and b: ");
            scanf("%f %f", &a, &b);
            area = triangle_area(a, b);
            printf("Figure: Right triangle\nArea = %.2f", area);
            break;

        case 4:
            printf("Enter radius: ");
            scanf("%f", &r);
            area = circle_area(r);
            printf("Figure: Circle\nArea = %.2f", area);
            break;

        default:
            printf("Invalid code!");
    }

    switch_numbers();
    even_or_odd();
    return 0;
}