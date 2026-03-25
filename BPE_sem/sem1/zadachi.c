#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

void print_numbers_as_text() {
    printf("One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten\n");
}

void star_triangle() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void frame() {
    char s;
    printf("Enter a symbol: ");
    scanf("%c", &s);
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 10; j++) {
            if (i == 1 || i == 5 || j == 1 || j == 10) printf("%c", s);
            else printf(" ");
        }
        printf("\n");
    }
}

void print_triangle() {
    char s;
    printf("Enter symbol: ");
    scanf("%c", &s);
    
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= i * 2; j++) {
            if (j == 1 || j == i * 2 - 1) printf("%c", s);
            else printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i <= 9; i++) printf("%c", s);
    printf("\n");
}

void print_reverse_triangle() {
    char s;
    printf("Enter symbol: ");
    scanf(" %c", &s);

    for (int i = 0; i < 9; i++) printf("%c", s);
    printf("\n");

    for (int i = 4; i >= 1; i--) {
        for (int j = 1; j <= i * 2; j++) {
            if (j == 1 || j == i * 2 - 1) printf("%c", s);
            else printf(" ");
        }
        printf("\n");
    }
}

void convert_inches() {
    double inches;
    printf("Enter inches: ");
    scanf("%lf", &inches);
    printf("%.2f inches are: %.2f mm; %.2f cm; %.2f dm; %.2f m.", inches, 25.4 * inches, 2.54 * inches, 0.254 * inches, 0.0254 * inches);
}

void celsius_to_fahrenheit() {
    double temperature;
    printf("Enter temperature in celsius: ");
    scanf("%lf", &temperature);
    printf("%.2f degrees celsius are %.2f degrees fahrenheit", temperature, temperature * 1.8 + 32);
}

void degrees_to_radians() {
    double degrees;
    printf("Enter degrees: ");
    scanf("%lf", &degrees);
    double radians = degrees * (PI / 180.0);
    printf("%.2f in degrees are %.2f in radians", degrees, radians);
}

void convert_levove() {
    double leva;
    printf("Enter leva: ");
    scanf("%lf", &leva);
    printf("%.2f leva are %.2f dollars, %.2f euro and %.2f pounds.", leva, leva / 1.78, leva / 1.95583, leva / 2.25);
}

void trapezoid_area() {
    double a, b, h;
    printf("Enter a, b, h: ");
    scanf("%lf %lf %lf", &a, &b, &h);
    printf("The area of the trapezoid is: %.2f", ((a + b) * h) / 2);
}

void trigonometry() {
    double degrees;
    printf("Enter angle degrees: ");
    scanf("%lf", &degrees);

    double radians = degrees * (PI / 180);
    printf("Sin(%f) = %.4f\n", degrees, sin(radians));
    printf("Cos(%f) = %.4f\n", degrees, cos(radians));

    if (cos(radians) != 0)
        printf("Tg(%f) = %.4f\n", degrees, (sin(radians) / cos(radians)));
    else 
        printf("Impossible!");

    if (sin(radians) != 0)
         printf("Cotg(%f) = %.4f\n", degrees, (cos(radians) / sin(radians)));
    else
        printf("Impossible!");
}

void rectangle_area() {
    double x1, y1, x2, y2;
    printf("Enter coordinates for point 1 (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter coordinates for point 2 (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);

    double width = fabs(x1 - x2);
    double height = fabs(y1 - y2);

    printf("Area of the rectangle: %.2f", (width * height));
}

void triangle_area() {
    double x1, y1, x2, y2, x3, y3;
    printf("Enter coordinates for point 1 (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter coordinates for point 2 (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);
    printf("Enter coordinates for point 3 (x3, y3): ");
    scanf("%lf %lf", &x3, &y3);

    double area = 0.5 * fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    printf("The area is: %.2f", area);
}

void classroom() {
    double h, w;
        printf("Enter width and heigth: ");

        if (scanf("%lf %lf", &h, &w) != 2) {
            printf("Invalid entry!\n");
            return;
        }

        double length_cm = h * 100;
        double width_cm = w * 100;

        double usable_width = width_cm - 100;

        int desks_per_row = (int)(usable_width / 70);

        int rows = (int)(length_cm / 120);

        int total_seats = (rows * desks_per_row) - 3;

        printf("Seats: %d\n", total_seats);
}

void calculateHarvestEarnings() {
    double vegPricePerKg, fruitPricePerKg;
    int vegTotalKg, fruitTotalKg;
    const double EUR_RATE = 1.95;

    printf("Enter Vegetable price: \n");
    if (scanf("%lf", &vegPricePerKg) != 1) return;

    printf("Enter Fruit price: \n");
    if (scanf("%lf", &fruitPricePerKg) != 1) return;

    printf("Enter Vegetable kg: \n");
    if (scanf("%d", &vegTotalKg) != 1) return;

    printf("Enter Fruit kg: \n");
    if (scanf("%d", &fruitTotalKg) != 1) return;

    double totalBgn = (vegPricePerKg * vegTotalKg) + (fruitPricePerKg * fruitTotalKg);
    double totalEur = totalBgn / EUR_RATE;

    printf("%.2f\n", totalEur);
}

void calculateTilesAndTime() {
    double n, w, l, m, o;

    printf("Въведете N (страна на площадка): ");
    if (scanf("%lf", &n) != 1) return;
    
    printf("Въведете W и L (размери на плочка): ");
    if (scanf("%lf %lf", &w, &l) != 1) return;
    
    printf("Въведете M и O (размери на пейка): ");
    if (scanf("%lf %lf", &m, &o) != 1) return;

    double totalArea = n * n;           
    double benchArea = m * o;           
    double coverArea = totalArea - benchArea; 
    double tileArea = w * l;            

    double tilesNeeded = coverArea / tileArea; 
    double timeNeeded = tilesNeeded * 0.2;     
\
    printf("%.2f\n", tilesNeeded);
    printf("%.2f\n", timeNeeded);
}

void calculateProgrammerDailyIncome() {
    int workingDaysPerMonth;
    double dollarsPerDay, usdToBgnRate;

    printf("Въведете работни дни в месеца: ");
    if (scanf("%d", &workingDaysPerMonth) != 1) return;

    printf("Въведете заработка на ден (USD): ");
    if (scanf("%lf", &dollarsPerDay) != 1) return;

    printf("Въведете курс на USD към BGN: ");
    if (scanf("%lf", &usdToBgnRate) != 1) return;

    double monthlySalaryUsd = workingDaysPerMonth * dollarsPerDay;
    double annualIncomeUsd = (monthlySalaryUsd * 12) + (monthlySalaryUsd * 2.5);
    double netAnnualIncomeUsd = annualIncomeUsd * 0.75;
    double netAnnualIncomeBgn = netAnnualIncomeUsd * usdToBgnRate;
    double averageDailyIncomeBgn = netAnnualIncomeBgn / 365;

    printf("%.2f\n", averageDailyIncomeBgn);
}

int main() {
    //print_numbers_as_text();
    //star_triangle();
    //frame();
    //print_triangle();
    //print_reverse_triangle();
    //convert_inches();
    //celsius_to_fahrenheit();
    //degrees_to_radians();
    //convert_levove();
    //trapezoid_area();
    //trigonometry();
    //rectangle_area();
    //triangle_area();
    //classroom();
    //calculateHarvestEarnings();
    //calculateTilesAndTime()
    //calculateProgrammerDailyIncome()

    int choice;
    printf("Choose task number: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:  print_numbers_as_text(); break;
        case 2:  star_triangle(); break;
        case 3:  frame(); break;
        case 4:  print_triangle(); break;
        case 5:  print_reverse_triangle(); break;
        case 6:  convert_inches(); break;
        case 7:  celsius_to_fahrenheit(); break;
        case 8:  degrees_to_radians(); break;
        case 9:  convert_levove(); break;
        case 10: trapezoid_area(); break;
        case 11: trigonometry(); break;
        case 12: rectangle_area(); break;
        case 13: triangle_area(); break;
        case 14: classroom(); break;
        case 15: calculateHarvestEarnings(); break;
        case 16: calculateTilesAndTime(); break;
        case 17: calculateProgrammerDailyIncome(); break;
        default: printf("Невалиден номер на задача!\n");
    }
    return 0;
}