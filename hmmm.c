#include <stdio.h> 
#include <string.h> 
int main(){ 
 int n,i,j = 0,k; 
 double M1[8],M2[8],ans1 = 0,ans2 = 0,A_M1 = 0,A_M2 = 0,A; 
 double ansM1[10][10],ansM2[10][10]; 
 char cl[10][10]; 
 M1[0] = 0.6; 
 M1[1] = 1.0 - M1[0]; 
 M1[2] = 0.6; 
 M1[3] = 1.0 - M1[2]; 
 M1[4] = 0.7; 
 M1[5] = 1.0 - M1[4]; 
 M1[6] = 0.5; 
 M1[7] = 1.0 - M1[6]; 
 M2[0] = 0.5; 
 M2[1] = 1.0 - M2[0]; 
 M2[2] = 0.8; 
 M2[3] = 1.0 - M2[2]; 
 M2[4] = 0.6; 
 M2[5] = 1.0 - M2[4]; 
 M2[6] = 0.4; 
 M2[7] = 1.0 - M2[6]; 
 printf("取り出すボールの個数 注）MAX9 => "); 
 scanf("%d",&n); 
 printf("\nR か B を 1 つずつ入力");for(i = 0;i < n;i++){ 
 printf("\n%d 個目=> ",i+1); 
 scanf("%s",&cl[i][i]); 
 } 
 i = 0; 
 for(k = n;k > 1;k--){ 
 if(k == 2){ 
 i = 0; 
 switch(cl[i][i]){ 
 case 'R': 
 ans1 = M1[1] * M1[2]; 
 break; 
 case 'B': 
 ans1 = M1[1] * M1[3]; 
 break; 
 } 
 k = 0; 
 i++; 
 } 
 for(i = i;i + 2 < k;i++){ 
 if(i == 0){ 
 switch(cl[i][i]){ 
 case 'R': 
 ans1 = M1[0] * M1[2]; 
 break; 
 case 'B': 
 ans1 = M1[0] * M1[3]; 
 break; 
 } 
 } 
 if((!k) == 0 && i > 0){ 
 switch(cl[i][i]){ 
 case 'R': 
 ans1 *= M1[0] * M1[2]; 
 break; 
 case 'B': 
 ans1 *= M1[0] * M1[3]; 
 break; 
 } 
 } 
 } 
 if((!k) == 0){ 
 switch(cl[i][i]){ 
 case 'R': 
 ans1 *= M1[1] * M1[2]; 
 break; 
 case 'B': 
 ans1 *= M1[1] * M1[3]; 
 break; 
 } 
 i++; 
 } 
 for(i = i;i + 1< n;i++){ 
 switch(cl[i][i]){case 'R': 
 ans1 *= M1[4] * M1[6]; 
 break; 
 case 'B': 
 ans1 *= M1[4] * M1[7]; 
 break; 
 } 
 } 
 switch(cl[i][i]){ 
 case 'R': 
 ans1 *= M1[5] * M1[6]; 
 break; 
 case 'B': 
 ans1 *= M1[5] * M1[7]; 
 break; 
 } 
 printf("%lf\n", ans1); 
 ansM1[j][j] = ans1; 
 j++; 
 } 
 i = 0; 
 j = 0; 
 for(k = n;k > 1;k--){ 
 if(k == 2){ 
 i = 0; 
 switch(cl[i][i]){ 
 case 'R': 
 ans2 = M2[1] * M2[2]; 
 break; 
 case 'B': 
 ans2 = M2[1] * M2[3]; 
 break; 
 } 
 k = 0; 
 i++; 
 } 
 for(i = i;i + 2 < k;i++){ 
 if(i == 0){ 
 switch(cl[i][i]){ 
 case 'R': 
 ans2 = M2[0] * M2[2]; 
 break; 
 case 'B': 
 ans2 = M2[0] * M2[3]; 
 break; 
 } 
 } 
 if((!k) == 0 && i > 0){ 
 switch(cl[i][i]){ 
 case 'R': 
 ans2 *= M2[0] * M2[2]; 
 break; 
 case 'B': 
 ans2 *= M2[0] * M2[3]; break; 
 } 
 } 
 } 
 if((!k) == 0){ 
 switch(cl[i][i]){ 
 case 'R': 
 ans2 *= M2[1] * M2[2]; 
 break; 
 case 'B': 
 ans2 *= M2[1] * M2[3]; 
 break; 
 } 
 i++; 
 } 
 for(i = i;i + 1< n;i++){ 
 switch(cl[i][i]){ 
 case 'R': 
 ans2 *= M2[4] * M2[6]; 
 break; 
 case 'B': 
 ans2 *= M2[4] * M2[7]; 
 break; 
 } 
 } 
 switch(cl[i][i]){ 
 case 'R': 
 ans2 *= M2[5] * M2[6]; 
 break; 
 case 'B': 
 ans2 *= M2[5] * M2[7]; 
 break; 
 } 
 ansM2[j][j] = ans2; 
 j++; 
 } 
 printf("観測=> "); 
 for(i = 0;i < n;i++){ 
 printf("%s",&cl[i][i]); 
 } 
 printf("\n"); 
 for(j = 0;j < 2;j++){ 
 A_M1 += ansM1[j][j]; 
 } 
 for(j = 0;j < 2;j++){ 
 A_M2 += ansM2[j][j]; 
 } 
 printf("モデル 1 の確率=> %lf\n",A_M1); 
 printf("モデル 2 の確率=> %lf\n",A_M2); 
 if(A_M1 > A_M2){ 
 printf("\n よってモデル 1 の方が確率が高い\n"); 
 } 
 else{ 
 printf("\n よってモデル 2 の方が確率が高い\n");} 
 return 0; 
} 
