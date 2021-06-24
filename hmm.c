#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
double counta [11][11];
double countR [11];
double countB [11];
double kaku;
double waria [11][11];
double wariR [11];
double wariB [11];
char iro [2];
double ball [11];
};

int main (){
  struct data pattern [11];
  struct data color [11];
  double a[11][11];
  double R[11] ,B[11];

  double sum ,sum2 ,sum3 ,sum4;
  char r[2]="r",b[2]="b";
  int i,j,k,kai =1;
  int kazu =4, tubo =2;
  for(i=1;i<= kazu;i++){
    a[i][i]=0.5;
    a[i][i+1]=0.5;
    R[i]=0.5;
    B[i]=0.5;
  }

  printf("% d 個 の ボ ー ル の 色 を 入 力 \n",kazu );
  for(i=1;i<= kazu;i++){
    scanf(" %s",color[i]. iro );
  }
  
  pattern [1]. counta [1][1]=2;
  pattern [1]. counta [1][2]=1;
  pattern [1]. counta [2][2]=0;
  pattern [1]. counta [2][3]=1;

  pattern [2]. counta [1][1]=1;
  pattern [2]. counta [1][2]=1;
  pattern [2]. counta [2][2]=1;
  pattern [2]. counta [2][3]=1;

  pattern [3]. counta [1][1]=0;
  pattern [3]. counta [1][2]=1;
  pattern [3]. counta [2][2]=2;
  pattern [3]. counta [2][3]=1;
  
  for(i=1;i<=kazu -1;i++){
  for(j=1;j<= tubo;j++){
  pattern[i]. countR [1]=0;
  pattern[i]. countB [1]=0;
  }
  }

  printf("\ n 学 習 に 使 用 す る 系 列 \nr: 赤 い 玉 , b: 青 い 玉\ n");
  for(i=1;i<= kazu;i++) printf("%s ",color[i]. iro );
  printf("\n\n");

  if(! strcmp(color [1]. iro ,r)){
    pattern [1]. countR [1]+=1;
    pattern [2]. countR [1]+=1;
    pattern [3]. countR [1]+=1;
  }
  if(! strcmp(color [2]. iro ,r)){
    pattern [1]. countR [1]+=1;
    pattern [2]. countR [1]+=1;
    pattern [3]. countR [2]+=1;
  }
  if(! strcmp(color [3]. iro ,r)){
    pattern [1]. countR [1]+=1;
    pattern [2]. countR [2]+=1;
    pattern [3]. countR [2]+=1;
  }
  if(! strcmp(color [4]. iro ,r)){
    pattern [1]. countR [2]+=1;
    pattern [2]. countR [2]+=1;
    pattern [3]. countR [2]+=1;
  }
  if(! strcmp(color [1]. iro ,b)){
    pattern [1]. countB [1]+=1;
    pattern [2]. countB [1]+=1;
    pattern [3]. countB [1]+=1;
  }
  if(! strcmp(color [2]. iro ,b)){
    pattern [1]. countB [1]+=1;
    pattern [2]. countB [1]+=1;
    pattern [3]. countB [2]+=1;
  }
  if(! strcmp(color [3]. iro ,b)){
    pattern [1]. countB [1]+=1;
    pattern [2]. countB [2]+=1;
    pattern [3]. countB [2]+=1;
  }
  if(! strcmp(color [4]. iro ,b)){
    pattern [1]. countB [2]+=1;
    pattern [2]. countB [2]+=1;
    pattern [3]. countB [2]+=1;
  }

  while(kai <100){
    if(! strcmp(color [1]. iro ,r)){
      pattern [1]. ball [1]=R[1];
      pattern [2]. ball [1]=R[1];
      pattern [3]. ball [1]=R[1];
    }
    if(! strcmp(color [1]. iro ,b)){
      pattern [1]. ball [1]=B[1];
      pattern [2]. ball [1]=B[1];
      pattern [3]. ball [1]=B[1];
    }

    if(! strcmp(color [2]. iro ,r)){
      pattern [1]. ball [2]=R[1];
      pattern [2]. ball [2]=R[1];
      pattern [3]. ball [2]=R[2];
    }
    if(! strcmp(color [2]. iro ,b)){
      pattern [1]. ball [2]=B[1];
      pattern [2]. ball [2]=B[1];
      pattern [3]. ball [2]=B[2];
    }
    if(! strcmp(color [3]. iro ,r)){
      pattern [1]. ball [3]=R[1];
      pattern [2]. ball [3]=R[2];
      pattern [3]. ball [3]=R[2];
    }
    if(! strcmp(color [3]. iro ,b)){
      pattern [1]. ball [3]=B[1];
      pattern [2]. ball [3]=B[2];
      pattern [3]. ball [3]=B[2];
    }
    if(! strcmp(color [4]. iro ,r)){
      pattern [1]. ball [4]=R[2];
      pattern [2]. ball [4]=R[2];
      pattern [3]. ball [4]=R[2];
    }
    if(! strcmp(color [4]. iro ,b)){
      pattern [1]. ball [4]=B[2];
      pattern [2]. ball [4]=B[2];
      pattern [3]. ball [4]=B[2];
    }
    pattern [1]. kaku = pattern [1]. ball [1] * a[1][1] * pattern [1].ball [2] * a[1][1] * pattern [1].ball [3] * a[1][2] * pattern [1]. ball [4] * a[2][3];
    pattern [2]. kaku = pattern [2]. ball [1] * a[1][1] * pattern [2]. ball [2] * a[1][2] * pattern [2]. ball [3] * a[2][2] * pattern [2]. ball [4] * a[2][3];
    pattern [3]. kaku = pattern [3]. ball [1] * a[1][2] * pattern [3]. ball [2] * a[2][2] * pattern [3]. ball [3] * a[2][2] * pattern [3]. ball [4] * a[2][3];
    for(i=1;i<=kazu -1;i++){
      for(j=1;j<= tubo;j++){
        pattern[i]. waria[j][j]= pattern[i]. counta[j][j]/( pattern[i]. counta[j][j]+ pattern[i]. counta[j][j+1]);
        pattern[i]. waria[j][j+1]=1 - pattern[i]. waria[j][j];
        pattern[i]. wariR[j]= pattern[i]. countR[j]/( pattern[i]. countR[j]+ pattern[i]. countB[j]);
        pattern[i]. wariB[j]=1- pattern[i]. wariR[j];
      }
    }
    for(i=1;i<= tubo;i++){
      sum =0;
      sum2 =0;
      sum3 =0;
      sum4 =0;
      for(j=1;j<=kazu -1;j++){
        sum += pattern[j]. waria[i][i]* pattern[j]. kaku;
        sum2 += pattern[j]. waria[i][i+1]* pattern[j]. kaku;
        sum3 += pattern[j]. wariR[i]* pattern[j]. kaku;
        sum4 += pattern[j]. wariB[i]* pattern[j]. kaku;
      }
      a[i][i]= sum;
      a[i][i+1]= sum2;
      R[i]= sum3;
      B[i]= sum4;
    }
    for(i=1;i<= tubo;i++){
      a[i][i]=a[i][i]/(a[i][i]+a[i][i+1]);
      a[i][i+1]=1 -a[i][i];
      R[i]=R[i]/(R[i]+B[i]);
      B[i]=1-R[i];
    }
    kai ++;
  }
  printf("学習結果\n");
  for(i=1;i<= tubo;i++){
    printf("a[%d][%d] = %lf\n",i,i,a[i][i]);
    if(i== tubo)printf("a[%d][E] = %lf\n",i,a[i][i+1]);
    else printf("a[%d][%d] = %lf\n",i,i+1,a[i][i+1]);
    printf("R[%d] = %lf\n",i,R[i]);
    printf("B[%d] = %lf\n",i,B[i]);
  }
}
