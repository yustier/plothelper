#include <stdio.h>
#include <math.h>

// タイトル画面を表示する
int msgtitle(void){
    printf("\n+----------------------+\n"
             "|      PlotHelper      |\n"
             "|    Made by Airoku    |\n"
             "+----------------------+\n\n");
    return 0;
}

// 説明を表示する
int msginfo(void){
    printf("This little program assists you to determine where to plot your data on grid\n"
           "sheets.\n\n");
    return 0;
}

// 終了メッセージを表示する
int msgexit(void){
    printf("Thank you!\n");
    return 0;
}

// メインメニューを表示する
int msgmenu(void){
    printf("[ Menu ]\n"
           "1. Get the position\n"
           "2. Config the grid sheet\n"
           "3. Exit\n\n"
           "Command? ");
}

// intを標準入力から取る
int examineint(int* input){
    if(scanf("%d%*c", input) != 1){
        scanf("%*s");
        printf("Invalid command. Use integers.\n\n");
        return 1; // 入力がおかしい
    }
    return 0;
}

// doubleを標準入力から取る
int examinedouble(double* input){
    if(scanf("%lf%*c", input) != 1){
        scanf("%*s");
        printf("Invalid command. Use real numbers.\n\n");
        return 1; // 入力がおかしい
    }
    return 0;
}

// プロット位置を決定する
int posit(int mode, int* g, double* d, double* x){
    double nearestdiv, displacement;
    double gauss; // "小数"部分
    gauss = fmod(*x, *d);
    if(gauss < *d - gauss){
        nearestdiv = *x - gauss;
        displacement = (*x - nearestdiv) / *d * *g;
    } else{
        nearestdiv = *x - gauss + *d;
        displacement = -1.0 * (nearestdiv - *x) / *d * *g;
    }
    if(mode==1)printf("The horizontal position is %.2f grid(s) off from %lf\n", displacement, nearestdiv);
    else if(mode==2)printf("The vertical position is %.2f grid(s) off from %lf\n", displacement, nearestdiv);
    else return 1; // mode引数がおかしい
    return 0;
}

// 方眼紙の目盛りを設定する
int configsheet(int* hg, int* vg, double* hd, double* vd){
    while(1){
        printf("Input the size of a single division in horizontal axis: ");
        if(examinedouble(hd)==0)break;
    }
    while(1){
        printf("Input the number of grids in one horizontal division: ");
        if(examineint(hg)==0)break;
    }
    while(1){
        printf("Input the size of a single division in vertical axis: ");
        if(examinedouble(vd)==0)break;
    }
    while(1){
        printf("Input the number of grids in one vertical division: ");
        if(examineint(vg)==0)break;
    }
    printf("Configuration completed!\n\n");
    return 0;
}

int main(void){
    int hgrid=10, vgrid=10, maincmd;
    double hdivision=1.0, vdivision=1.0, hdata, vdata;
    msgtitle();
    msginfo();
    while(1){
        msgmenu();
        if(examineint(&maincmd)!=0)continue;
        if(maincmd==1){
            while(1){
                printf("Input the horizontal data: ");
                if(examinedouble(&hdata)==0)break;
            }
            while(1){
                printf("Input the vertical data: ");
                if(examinedouble(&vdata)==0)break;
            }
            posit(1, &hgrid, &hdivision, &hdata);
            posit(2, &vgrid, &vdivision, &vdata);
            printf("\n");
        }
        else if(maincmd==2)configsheet(&hgrid, &vgrid, &hdivision, &vdivision);
        else if(maincmd==3)break;
        else{
            printf("Out of bound. Use integers from 1 to 3.\n\n");
        }
    }
    msgexit();
    return 0;
}

///////////////////////////////////
// (C) 2020 Airoku
///////////////////////////////////
