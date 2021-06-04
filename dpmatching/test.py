import numpy as np
Temprate_file_name = "./city022/city022_"
Target_file_name = "./city021/city021_"

def read_file(file_name):

    list=[]

    for number in range(1,101):

        file_number='%03d' % number
        file_name_number=file_name+file_number+".txt"
        array=(np.loadtxt(file_name_number, skiprows=3, unpack=True)).T
        list.append(array)
        
    return list

def Local_distance(Temprate,Target):

    #テンプレートとターゲットの最大フレームと次元を保存
    Temprate_frame,Temprate_dimention = Temprate.shape
    Target_frame,Target_dimention = Target.shape

    D=np.empty((Temprate_frame,Target_frame))

    for i in range(Temprate_frame):

        for j in range(Target_frame):
            rootbefore=0.0
            for k in range(Temprate_dime):
                rootbefore+=((Temp[i][k]-Targ[j][k])**2)
            D[i][j]=np.sqrt(rootbefore)
    return D

def matching(D):

    gyou,retsu=D.shape

    for i in range(retsu):
        if(i>0):
            D[0][i]=D[0][i-1]+D[0][i]

    for j in range(gyou):
        if(j>0):
            D[j][0]=D[j-1][0]+D[j][0]
    
    for j in range(1,gyou):
            for i in range(1,retsu):
                D[j][i]=min([D[j][i-1]+D[j][i],D[j-1][i-1]+(D[j][i])*2,D[j-1][i]+D[j][i]])
    
    word_distance=(D[gyou-1][retsu-1])/(gyou+retsu)

    return D,word_distance

def accuracy(Temprate,Target):

    accuracy=0

    for Temprate100 in range(100):

        bwd=1000

        for Target100 in range(100):

            D=Local_distance(Temprate[Temprate100],Target[Target100])

            g,wd=matching(D)

            if wd<bwd:
                judge_num=Target100
                bwd=wd

        if judge_num==Temprate100:
            accuracy+=1
        else:
            print(Temprate100+1,"番、不正解",judge_num+1,"と誤認")

    print("\n","accuracy=",accuracy)
def pinpointTem(TemprateNumber,Temprate,Target):
    bwd=1000
    for Target100 in range(100):
        D=Local_distance(Temprate[TempNumber],Target[Target100])
        g,wd=matching(d)
        if wd<bwd:
            bwd=wd
            judge=Target100
    print(judge,bwd)

def main():
    Temprate = read_file(Temprate_file_name)
    Target = read_file(Target_file_name)
    print("Template file name = ",Temprate_file_name)
    print("Target file name = ",Target_file_name)
    accuracy(Temprate,Target)

if __name__ == '__main__':
    main() 
