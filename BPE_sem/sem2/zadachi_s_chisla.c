#include <stdio.h>

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

int min(int a, int b){
    if(a < b)
        return a;
    return b;
}

void findMinMax(){

    int num;
    int biggest, smallest;

    printf("Enter number (0 to stop): ");
    scanf("%d",&num);

    biggest = num;
    smallest = num;

    while(1){

        printf("Enter number (0 to stop): ");
        scanf("%d",&num);

        if(num == 0)
            break;

        biggest = max(biggest,num);
        smallest = min(smallest,num);
    }

    printf("Max = %d\n",biggest);
    printf("Min = %d\n",smallest);
}

void add15Minutes(){
    int h,m;

    scanf("%d %d",&h,&m);

    m += 15;

    if(m >= 60){
        h++;
        m -= 60;
    }

    if(h == 24)
        h = 0;

    printf("%d:%02d\n",h,m);
}

int equals(int a, int b, int c){
    if (a == b && b == c) 
        return 1;
    return 0;
}

double bonus(int n){
    double bonus = 0;

    if(n <= 100) bonus = 5;
    if(n > 100 && n <= 1000){
        bonus = 0.2*n;
    }
    if(n > 1000){
        bonus = 0.1*n;
    }
    if(n % 2 == 0) bonus++;
    if(n % 10 == 5) bonus+= 2;

    printf("Summed points: %.2f", n+bonus);
    return bonus;
}

void race_time(){
    int t1, t2, t3;
    int total, seconds, minutes;
    scanf("%d %d %d",&t1,&t2,&t3);

    total = t1+t2+t3;

    minutes = total/60;
    seconds = total%60;

    printf("%d:%02d\n",minutes,seconds);
}

int isInside(double x1,double y1,double x2,double y2,double x,double y){

    if(x >= x1 && x <= x2 && y >= y1 && y <= y2)
        return 1;

    return 0;
}

void check_point(){

    double x1,y1,x2,y2,x,y;

    scanf("%lf %lf",&x1,&y1);
    scanf("%lf %lf",&x2,&y2);
    scanf("%lf %lf",&x,&y);

    if(isInside(x1,y1,x2,y2,x,y))
        printf("Inside\n");
    else
        printf("Outside\n");
}

double transport(int n, char period){
    double taxi;

    if (period == 'D')
        taxi = 0.70 + n * 0.79;
    else if (period == 'N')
        taxi = 0.70 + n * 0.90;

    double bus = n * 0.09;
    double train = n * 0.06;

    double price = taxi;

    if (n > 20 && bus < price) 
        price = bus;

    if (n > 100 && train < price)
        price = train;

    printf("Price: %.2f", price);
    return price;
}

void pool(){
    int V, P1, P2, N;
    scanf("%d %d %d %d", &V, &P1, &P2, &N);

    int water_in_pool = P1*N + P2*N;

    if (water_in_pool <= V){
        double percent = (water_in_pool * 100) / V;
        printf("The pool is %.2f percents full", percent);
    }
    else 
        printf("%d litters overflowed", water_in_pool - V);
}

void wine(){
    int X, Y, Z, workers;
    scanf("%d %d %d %d", &X, &Y, &Z, &workers);

    double wine_material = 0.4 * X;
    double grape_weight = wine_material*Y;
    double litres_of_wine = grape_weight / 2.5;

    if(litres_of_wine >= Z){

        double left = litres_of_wine - Z;
        double perWorker = left / workers;

        printf("%.0f liters wine\n",litres_of_wine);
        printf("%.0f liters left -> %.0f per worker\n",left,perWorker);
    }
    else{

        printf("Not enough wine. Need %.0f liters more\n", Z - litres_of_wine);
    }
}

void percentages(){
    int n,num;
    int p1=0,p2=0,p3=0,p4=0,p5=0;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&num);

        if(num < 200)
            p1++;
        else if(num <= 399)
            p2++;
        else if(num <= 599)
            p3++;
        else if(num <= 799)
            p4++;
        else
            p5++;
    }

    printf("%.2f%%\n", p1*100.0/n);
    printf("%.2f%%\n", p2*100.0/n);
    printf("%.2f%%\n", p3*100.0/n);
    printf("%.2f%%\n", p4*100.0/n);
    printf("%.2f%%\n", p5*100.0/n);
}

void fortress(int n){

    int mid = n/2;

    printf("/");
    for(int i=0;i<mid;i++) printf("^");
    printf("\\");
    for(int i=0;i<n-2*mid-2;i++) printf("_");
    printf("/");
    for(int i=0;i<mid;i++) printf("^");
    printf("\\\n");

    for(int r=0;r<n-2;r++){

        printf("|");
        for(int i=0;i<2*n-2;i++) printf(" ");
        printf("|\n");
    }

    printf("\\");
    for(int i=0;i<2*n-2;i++) printf("_");
    printf("/\n");
}

void butterfly(int n){

    for(int i=1;i<=n-2;i++){

        if(i%2==0){
            for(int j=0;j<n-1;j++) printf("-");
        }
        else{
            for(int j=0;j<n-1;j++) printf("*");
        }

        printf("\\ /");

        if(i%2==0){
            for(int j=0;j<n-1;j++) printf("-");
        }
        else{
            for(int j=0;j<n-1;j++) printf("*");
        }

        printf("\n");
    }

    for(int i=0;i<n-1;i++) printf(" ");
    printf("@\n");

    for(int i=1;i<=n-2;i++){

        if(i%2==0){
            for(int j=0;j<n-1;j++) printf("-");
        }
        else{
            for(int j=0;j<n-1;j++) printf("*");
        }

        printf("/ \\");

        if(i%2==0){
            for(int j=0;j<n-1;j++) printf("-");
        }
        else{
            for(int j=0;j<n-1;j++) printf("*");
        }

        printf("\n");
    }
}

int main(){
    int choice;
    printf("Choose task number: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:  findMinMax(); break;
        case 2:  add15Minutes(); break;
        case 3:  equals(13,13,13); break;
        case 4:  bonus(173); break;
        case 5:  race_time(); break;
        case 6:  check_point(); break;
        case 7:  transport(77, 'N'); break;
        case 8:  pool(); break;
        case 9:  wine(); break;
        case 10: percentages(); break;
        case 11: fortress(5); break;
        case 12: butterfly(8); break;
        default: printf("Невалиден номер на задача!\n");
    }
    return 0;
}