#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <math.h>

#include <string.h>

#include <windows.h>

#define N 50

void SET_COLOR(int color);
int is_emp(char str1[N]);
void direct_input(int * n, float a[N][N], float b[N][N], float c[N][N], char str1[N]);
void file(int * n, float a[N][N], float b[N][N], float c[N][N], char str1[N]);
void save(int n, char str1[N], float b[N][N], float x[N], int demvl);
void main_method(int n, float a[N][N], float x[N], int * demvl);
void switch_rows(int n, float a[N][N], float b[N][N], float c[N][N]);


int main() {
    int n, i, j, k, cn, dem, demvl;
    float a[N][N], x[N], b[N][N], c[N][N];
    FILE * f;
    char str1[N] = "f1";
    system("cls");
    SET_COLOR(14);
    printf(" ____________________________________________________________________________________\n");
    printf("|   CHUONG TRINH GIAI HE PHUONG TRINH DAI SO TUYEN TINH BANG PHUONG PHAP GIAM DU     |\n");
    printf("|                            Mot san pham cua Tran Trong Hieu                        |\n");
    printf("|____________________________________________________________________________________|\n");
    printf("                                       **********                                     \n");
    SET_COLOR(10);
    printf("Bang chuc nang:\n");
    printf("\n1. Nhap ma tran truc tiep.\n2. Nhap ma tran thong qua file.\n3. Xuat ma tran ra man hinh.\n4. Giai he phuong trinh dai so tuyen tinh bang phuong phap giam du.\n5. Luu ket qua vao file.\n6. Ket thuc chuong trinh.\n");
    SET_COLOR(11);
    printf("\nVui long nhap chuc nang can thuc hien: ");
    scanf("%d", & cn);
    while (cn != 6) {
        while (cn < 1 || cn > 6) {
            printf("Chuong trinh khong co chuc nang nay, vui long nhap lai: ");
            scanf("%d", & cn);
        }
        SET_COLOR(15);
        switch (cn) {
        case 1: {
            direct_input( & n, a, b, c, str1);
            printf("Hoan thanh!\n");
            break;
        }
        case 2: {
            file( & n, a, b, c, str1);
            printf("\nHoan thanh!\n");
            break;
        }
        case 3: {
            dem = 0;
            printf("\n");
            for (i = 1; i <= 2; i++) {
                for (j = 1; j <= 3; j++) {
                    if (a[i][j] == 0) {
                        dem++;
                    }
                }
            }
            if (dem >= 5) {
                f = fopen("f1.txt", "r");
                fscanf(f, "%d", & n);
                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= n + 1; j++) {
                        fscanf(f, "%f", & a[i][j]);
                        b[i][j] = a[i][j];
                        c[i][j] = a[i][j];
                    }
                }
                fclose(f);
                printf("Hoan thanh nhap du lieu ma tran tu dong tu file f1!\n");
            }
            printf("Ma tran cua ban la:\n\n");
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n + 1; j++) {
                    printf("%13.3f", b[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            //doi dong ma tran neu aii=0
            dem = 0;
            switch_rows(n, a, b, c);
            for (i = 1; i <= n; i++) {
                if (b[i][i] == 0) {
                    dem++;
                }
            }
            if (dem != 0) {
                printf("Vi ma tran cua ban co chua phan tu a[i][i]=0, tu dong doi dong ma tran de co the giai he phuong trinh bang phuong phap giam du!\n");
                printf("Ma tran moi cua ban la:\n\n");
                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= n + 1; j++) {
                        printf("%13.3f", c[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            printf("Hoan thanh!\n");
            break;
        }
        case 4: {
            dem = 0;
            printf("\n");
            for (i = 1; i <= 2; i++) {
                for (j = 1; j <= 3; j++) {
                    if (a[i][j] == 0) {
                        dem++;
                    }
                }
            }
            if (dem >= 5) {
                f = fopen("f1.txt", "r");
                fscanf(f, "%d", & n);
                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= n + 1; j++) {
                        fscanf(f, "%f", & a[i][j]);
                        b[i][j] = a[i][j];
                        c[i][j] = a[i][j];
                    }
                }
                fclose(f);
                printf("Hoan thanh nhap du lieu ma tran tu dong tu file f1!\n");
            }
            printf("\n");
            dem = 0;
            for (i = 1; i <= n; i++) {
                if (b[i][i] == 0) {
                    dem++;
                }
            }
            if (dem != 0) {
                switch_rows(n, a, b, c);
                printf("Da doi dong ma tran do ma tran chua a[i][i]=0\n\n");
                main_method(n, a, x, & demvl);
                printf("\n");
            } else {
                main_method(n, a, x, & demvl);
            }
            printf("Hoan thanh!\n");
            break;
        }
        case 5: {
            //chua nhap ma tran
            dem = 0;
            printf("\n");
            for (i = 1; i <= 2; i++) {
                for (j = 1; j <= 3; j++) {
                    if (a[i][j] == 0) {
                        dem++;
                    }
                }
            }
            if (dem >= 5) {
                f = fopen("f1.txt", "r");
                fscanf(f, "%d", & n);
                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= n + 1; j++) {
                        fscanf(f, "%f", & a[i][j]);
                        b[i][j] = a[i][j];
                        c[i][j] = a[i][j];
                    }
                }
                fclose(f);
                printf("Hoan thanh nhap du lieu ma tran tu dong tu file f1!\n");
            }
            dem = 0;
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n + 1; j++) {
                    if (a[i][j] == c[i][j]) {
                        dem++;
                    }
                }
            }
            if (dem == n * (n + 1)) { //nhap nhung chua giai co 2 TH: ngoai le aii va ko ngoai le
                dem = 0;
                for (i = 1; i <= n; i++) {
                    if (b[i][i] == 0) {
                        dem++;
                    }
                }
                if (dem != 0) { //aii==0
                    switch_rows(n, a, b, c);
                    printf("Da doi dong ma tran do ma tran chua a[i][i]=0\n\n");
                    printf("Tu dong giai he phuong trinh bang phuong phap giam du: \n\n");
                    main_method(n, a, x, & demvl);
                    save(n, str1, b, x, demvl);
                } else { //ko ngoai le
                    printf("Tu dong giai he phuong trinh bang phuong phap giam du: \n\n");
                    main_method(n, a, x, & demvl);
                    save(n, str1, b, x, demvl);
                }
            } else { //da nhap va da giai
                save(n, str1, b, x, demvl);
            }
            break;
        }
        case 6:
            break;
        }
        if (cn == 6) {
            break;
        }
        SET_COLOR(13);
        printf("\n");
        system("pause");
        system("cls");
        SET_COLOR(14);
        printf(" ____________________________________________________________________________________\n");
        printf("|   CHUONG TRINH GIAI HE PHUONG TRINH DAI SO TUYEN TINH BANG PHUONG PHAP GIAM DU     |\n");
        printf("|                            Mot san pham cua Tran Trong Hieu                        |\n");
        printf("|____________________________________________________________________________________|\n");
        printf("                                       **********                                     \n");
        SET_COLOR(10);
        printf("Bang chuc nang:\n");
        printf("\n1. Nhap ma tran truc tiep.\n2. Nhap ma tran thong qua file.\n3. Xuat ma tran ra man hinh.\n4. Giai he phuong trinh dai so tuyen tinh bang phuong phap giam du.\n5. Luu ket qua vao file.\n6. Ket thuc chuong trinh.\n");
        SET_COLOR(11);
        printf("\nVui long nhap chuc nang muon thuc hien tiep theo: ");
        scanf("%d", & cn);
    }
    SET_COLOR(6);
    printf("\nCam on ban da su dung chuong trinh!\n");
    getch();
}

void SET_COLOR(int color) {
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, & csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

int is_emp(char str1[N]) {
    FILE * f;
    int i;
    char str[N] = "", str2[N] = ".txt";
    strcat(str, str1);
    strcat(str, str2);
    f = fopen(str, "r");
    fseek(f, 0, SEEK_END);
    i = ftell(f);
    fclose(f);
    if (i == 0) {
        return 1;
    }
    return 0;
}

void direct_input(int * n, float a[N][N], float b[N][N], float c[N][N], char str1[N]) {
    int i, j;
    char str[N] = "direct_input";
    strcpy(str1, str);
    printf("\n");
    printf("Nhap so hang cua ma tran n= ");
    scanf("%d", & * n);
    printf("\n");
    printf("Nhap phan tu:\n");
    for (i = 1; i <= * n; i++) {
        for (j = 1; j <= * n + 1; j++) {
            printf("a[%d][%d]= ", i, j);
            scanf("%f", & a[i][j]);
            b[i][j] = a[i][j];
            c[i][j] = a[i][j];
        }
        printf("\n");
    }
}

void file(int * n, float a[N][N], float b[N][N], float c[N][N], char str1[N]) {
    FILE * f;
    int i, j;
    char str[N] = "", str2[N] = ".txt";
    printf("\n");
    printf("Nhap ten file: ");
    scanf("%s", str1);
    fflush(stdin);
    strcat(str, str1);
    strcat(str, str2);
    f = fopen(str, "r");
    while (f == NULL || is_emp(str1) == 1) {
        if (f == NULL) {
            printf("Khong ton tai file, xin vui long nhap lai ten file: ");
        }
        if (is_emp(str1) == 1) {
            printf("Ban da nhap file rong, vui long nhap lai ten file: ");
        }
        scanf("%s", str1);
        fflush(stdin);
        char str[N] = "", str2[N] = ".txt";
        strcat(str, str1);
        strcat(str, str2);
        f = fopen(str, "r");
    }
    fscanf(f, "%d", & * n);
    for (i = 1; i <= * n; i++) {
        for (j = 1; j <= * n + 1; j++) {
            fscanf(f, "%f", & a[i][j]);
            b[i][j] = a[i][j];
            c[i][j] = a[i][j];
        }
    }
    fclose(f);
}

void save(int n, char str1[N], float b[N][N], float x[N], int demvl) {
    int i, j;
    char str[N] = "", str3[N], str2[N] = ".txt";
    FILE * f;
    printf("\nNhap ten file: ");
    scanf("%s", str3);
    fflush(stdin);
    strcat(str, str3);
    strcat(str, str2);
    f = fopen(str, "a");
    if (demvl == 30) {
        if (strcmp(str1, "direct_input") == 0) {
            fprintf(f, "-----> Ma tran ban da nhap truc tiep:\n");
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n + 1; j++) {
                    fprintf(f, "%13.3f", b[i][j]);
                }
                fprintf(f, "\n");
            }
            fprintf(f, "khong hoi tu den nghiem!\n");
        } else {
            fprintf(f, "-----> File %s.txt khong hoi tu den nghiem!\n", str1);
        }
    } else {
        if (strcmp(str1, "direct_input") == 0) {
            fprintf(f, "-----> Ma tran ban da nhap truc tiep:\n");
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n + 1; j++) {
                    fprintf(f, "%13.3f", b[i][j]);
                }
                fprintf(f, "\n");
            }
            fprintf(f, "la:   ");
        } else {
            fprintf(f, "-----> File %s.txt la:   ", str1);
        }
        for (i = 1; i <= n - 1; i++) {
            fprintf(f, "%10.3f", x[i]);
        }
        fprintf(f, "%10.3f\n", x[n]);
    }
    fprintf(f, "\n");
    fclose(f);
    printf("Hoan thanh!\n");
}

void main_method(int n, float a[N][N], float x[N], int * demvl) {
    int i, j, k;* demvl = 0;
    float r[N], t, max, d;
    for (i = 1; i <= n; i++) {
        printf("Nhap xap xi nghiem ban dau x%d= ", i);
        scanf("%f", & x[i]);
    }
    printf("\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            if (i != j) {
                a[i][j] /= a[i][i];
            }
        }
        a[i][i] = 1;
    }
    for (i = 1; i <= n; i++) {
        r[i] = a[i][n + 1];
        for (j = 1; j <= n; j++) {
            r[i] -= a[i][j] * x[j];
        }
    }
    //in bang kq
    printf("Bang ket qua:\n\n");
    printf("   |------------------|");
    for (i = 2; i <= n * 2; i++) {
        printf("------------------|");
    }
    printf("\n");
    printf("   |        x1        |        ");
    for (i = 2; i <= n; i++) {
        printf("x%d        |        ", i);
    }
    for (i = 1; i <= n; i++) {
        printf("R%d        |        ", i);
    }
    printf("\n");
    printf("   |------------------|");
    for (i = 2; i <= n * 2; i++) {
        printf("------------------|");
    }
    printf("\n");
    do {
        for (i = 1; i <= n; i++) {
            printf("   |%12.3f   ", x[i]);
        }
        for (i = 1; i <= n; i++) {
            printf("   |%12.3f   ", r[i]);
        }
        printf("   |");
        printf("\n");
        t = 0;
        max = fabs(r[1]);
        k = 1;
        for (i = 2; i <= n; i++) {
            if (max < fabs(r[i])) {
                max = fabs(r[i]);
                k = i;
            }
        }
        x[k] += r[k];
        d = r[k];
        for (i = 1; i <= n; i++) {
            r[i] -= a[i][k] * d;
            if (fabs(r[i]) >= 0.001) {
                t = 1;
            }
        }
        * demvl = * demvl + 1;
        if ( * demvl == 30) {
            break;
        }
    }
    while (t);
    for (i = 1; i <= n; i++) {
        printf("   |%12.3f   ", x[i]);
    }
    for (i = 1; i <= n; i++) {
        printf("   |%12.3f   ", r[i]);
    }
    printf("   |\n");
    printf("   |------------------|");
    for (i = 2; i <= n * 2; i++) {
        printf("------------------|");
    }
    printf("\n");
    printf("\n");
    if ( * demvl == 30) {
        printf("He phuong trinh khong the giai bang phuong phap giam du do khong hoi tu den nghiem!\n");
    } else {
        printf("Vay nghiem (gan dung) cua he phuong trinh la: ");
        for (i = 1; i <= n - 1; i++) {
            printf("%10.3f", x[i]);
        }
        printf("%10.3f\n", x[n]);
    }
}

void switch_rows(int n, float a[N][N], float b[N][N], float c[N][N]) {
    int i, j;
    float temp;
    for (i = 1; i <= n; i++) {
        if (b[i][i] == 0 && a[i][i] == 0) {
            if (i < n) {
                for (j = 1; j <= n + 1; j++) {
                    temp = a[i][j];
                    a[i][j] = a[i + 1][j];
                    c[i][j] = a[i][j];
                    a[i + 1][j] = temp;
                    c[i + 1][j] = a[i + 1][j];
                }
            } else {
                for (j = 1; j <= n + 1; j++) {
                    temp = a[i][j];
                    a[i][j] = a[i - 1][j];
                    c[i][j] = a[i][j];
                    a[i - 1][j] = temp;
                    c[i - 1][j] = a[i - 1][j];
                }
            }
        }
    }
}