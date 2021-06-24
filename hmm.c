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
86 if(! strcmp(color [4]. iro ,r)){
87 pattern [1]. countR [2]+=1;
88 pattern [2]. countR [2]+=1;
89 pattern [3]. countR [2]+=1;
90 }
91 if(! strcmp(color [1]. iro ,b)){
92 pattern [1]. countB [1]+=1;
93 pattern [2]. countB [1]+=1;
94 pattern [3]. countB [1]+=1;
95 }
96 if(! strcmp(color [2]. iro ,b)){
97 pattern [1]. countB [1]+=1;
98 pattern [2]. countB [1]+=1;
99 pattern [3]. countB [2]+=1;
100 }
101 if(! strcmp(color [3]. iro ,b)){
102 pattern [1]. countB [1]+=1;
103 pattern [2]. countB [2]+=1;
104 pattern [3]. countB [2]+=1;
8105 }
106 if(! strcmp(color [4]. iro ,b)){
107 pattern [1]. countB [2]+=1;
108 pattern [2]. countB [2]+=1;
109 pattern [3]. countB [2]+=1;
110 }
111
112 while(kai <100){
113 if(! strcmp(color [1]. iro ,r)){
114 pattern [1]. ball [1]=R[1];
115 pattern [2]. ball [1]=R[1];
116 pattern [3]. ball [1]=R[1];
117 }
118 if(! strcmp(color [1]. iro ,b)){
119 pattern [1]. ball [1]=B[1];
120 pattern [2]. ball [1]=B[1];
121 pattern [3]. ball [1]=B[1];
122 }
123
124 if(! strcmp(color [2]. iro ,r)){
125 pattern [1]. ball [2]=R[1];
126 pattern [2]. ball [2]=R[1];
127 pattern [3]. ball [2]=R[2];
128 }
129 if(! strcmp(color [2]. iro ,b)){
130 pattern [1]. ball [2]=B[1];
131 pattern [2]. ball [2]=B[1];
132 pattern [3]. ball [2]=B[2];
133 }
134
135 if(! strcmp(color [3]. iro ,r)){
136 pattern [1]. ball [3]=R[1];
137 pattern [2]. ball [3]=R[2];
138 pattern [3]. ball [3]=R[2];
139 }
140 if(! strcmp(color [3]. iro ,b)){
141 pattern [1]. ball [3]=B[1];
142 pattern [2]. ball [3]=B[2];
143 pattern [3]. ball [3]=B[2];
144 }
145
146 if(! strcmp(color [4]. iro ,r)){
147 pattern [1]. ball [4]=R[2];
148 pattern [2]. ball [4]=R[2];
149 pattern [3]. ball [4]=R[2];
150 }
151 if(! strcmp(color [4]. iro ,b)){
152 pattern [1]. ball [4]=B[2];
153 pattern [2]. ball [4]=B[2];
154 pattern [3]. ball [4]=B[2];
155 }
156
157 pattern [1]. kaku = pattern [1]. ball [1]*a[1][1]
158 *pattern [1]. ball [2]*a[1][1]
159 *pattern [1]. ball [3]*a[1][2]
160 *pattern [1]. ball [4]*a[2][3];
161
162 pattern [2]. kaku = pattern [2]. ball [1]*a[1][1]
163 *pattern [2]. ball [2]*a[1][2]
164 *pattern [2]. ball [3]*a[2][2]
165 *pattern [2]. ball [4]*a[2][3];
166
167 pattern [3]. kaku = pattern [3]. ball [1]*a[1][2]
168 *pattern [3]. ball [2]*a[2][2]
169 *pattern [3]. ball [3]*a[2][2]
170 *pattern [3]. ball [4]*a[2][3];
171
172 for(i=1;i<=kazu -1;i++){//パターン数
173 for(j=1;j<= tubo;j++){//つぼ数
174 pattern[i]. waria[j][j]= pattern[i]. counta[j][j]/( pattern[i]. counta[j][j]+ pattern[i]. counta[j][j+1]);
175 pattern[i]. waria[j][j+1]=1 - pattern[i]. waria[j][j];
176
177 pattern[i]. wariR[j]= pattern[i]. countR[j]/( pattern[i]. countR[j]+ pattern[i]. countB[j]);
178 pattern[i]. wariB[j]=1- pattern[i]. wariR[j];
179 }
180 }
181 for(i=1;i<= tubo;i++){//つぼ数
182 sum =0;
183 sum2 =0;
9184 sum3 =0;
185 sum4 =0;
186 for(j=1;j<=kazu -1;j++){//パターン数
187 sum += pattern[j]. waria[i][i]* pattern[j]. kaku;
188 sum2 += pattern[j]. waria[i][i+1]* pattern[j]. kaku;
189 sum3 += pattern[j]. wariR[i]* pattern[j]. kaku;
190 sum4 += pattern[j]. wariB[i]* pattern[j]. kaku;
191 }
192 a[i][i]= sum;
193 a[i][i+1]= sum2;
194 R[i]= sum3;
195 B[i]= sum4;
196 }
197
198 for(i=1;i<= tubo;i++){//つぼ数
199 a[i][i]=a[i][i]/(a[i][i]+a[i][i+1]);
200 a[i][i+1]=1 -a[i][i];
201 R[i]=R[i]/(R[i]+B[i]);
202 B[i]=1-R[i];
203 }
204 kai ++;
205
206 }// while
207 printf("学習結果\n");
208 for(i=1;i<= tubo;i++){
209 printf("a[%d][%d] = %lf\n",i,i,a[i][i]);
210 if(i== tubo)printf("a[%d][E] = %lf\n",i,a[i][i+1]);
211 else printf("a[%d][%d] = %lf\n",i,i+1,a[i][i+1]);
212 printf("R[%d] = %lf\n",i,R[i]);
213 printf("B[%d] = %lf\n",i,B[i]);
214 }
215 }// mai
