#include <iostream>
#include <math.h>
using namespace std;

double A[5][5] ={{0.5470 ,0.1835 ,0.9294 ,0.3063 ,0.6443},
                 {0.2963 ,0.3685 ,0.7757 ,0.5085 ,0.3786},
                 {0.7447 ,0.6256 ,0.4868 ,0.5108 ,0.8116},
                 {0.1890 ,0.7802 ,0.4359 ,0.8176 ,0.5328},
                 {0.6868 ,0.0811 ,0.4468 ,0.7948 ,0.3507}};
double bT[5] = {0.9390 ,0.8759 ,0.5502 ,0.6225 ,0.5870};

double B[5][6] ={{0.5470 ,0.1835 ,0.9294 ,0.3063 ,0.6443 ,0.9390},
                 {0.2963 ,0.3685 ,0.7757 ,0.5085 ,0.3786 ,0.8759},
                 {0.7447 ,0.6256 ,0.4868 ,0.5108 ,0.8116 ,0.5502},
                 {0.1890 ,0.7802 ,0.4359 ,0.8176 ,0.5328 ,0.6225},
                 {0.6868 ,0.0811 ,0.4468 ,0.7948 ,0.3507 ,0.5870}};

void matrisYazdir5e5(double A[5][5])
{
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}

void matrisYazdir5e6(double B[5][6])
{
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 6; ++j)
        {
            cout << B[i][j] << '\t';
        }
        cout<<endl;
    }
}

void matrisYazdir1e5(double bT[5])
{
    for(int i = 0;i<5;i++)
    {
        cout<< bT[i] <<"\t";
    }
}
// 1- A matrisinin determinantını hesaplayınız.
double determinantHesapla(double A[5][5],int n)
{
    double det = 0;
    double submatrix[5][5];
    if (n == 2)
        return ((A[0][0] * A[1][1]) - (A[1][0] * A[0][1]));
    else {
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x)
                continue;
                submatrix[subi][subj] = A[i][j];
                subj++;
            }
            subi++;
            }
            det = det + (pow(-1, x) * A[0][x] * determinantHesapla( submatrix, n - 1 ));
        }
    }
    return det;
}

double determinantHesapla4x4(double A[4][4],int n)
{
    double det = 0;
    double submatrix[5][5];
    if (n == 2)
        return ((A[0][0] * A[1][1]) - (A[1][0] * A[0][1]));
    else {
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x)
                continue;
                submatrix[subi][subj] = A[i][j];
                subj++;
            }
            subi++;
            }
            det = det + (pow(-1, x) * A[0][x] * determinantHesapla( submatrix, n - 1 ));
        }
    }
    return det;
}

//2- ATA matrisinin izini hesaplayınız.
double matrisinIziniHesaplama(double A[5][5])
{
    double devrik[5][5];
    double carpim[5][5];
    double toplam=0;
    double ara=0;
    for(int i =0;i<5;i++)
    {
        for(int j=0; j<5;j++)
        {
            devrik[i][j] = A[j][i];
        }
    }
    //ATA matrisini buluyoruz
    for(int i =0;i<5;i++)
    {
        for(int j=0; j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                ara += (devrik[i][k] * A[k][j]);
            }
            carpim[i][j] = ara;
            ara=0;
        }
    }
    //ATA matrisinin izini buluyoruz
    for(int i =0;i<5;i++)
    {
        for(int j=0; j<5;j++)
        {
            if(i==j)
            {
                toplam+=carpim[i][j];
            }
        }
    }

    return toplam;
}

//3- A matrisinin satır normlarını hesaplayınız.
void satirNormlari(double A[5][5])
{
    double norm=0;
    for(int i =0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            norm+=A[i][j];
        }
        cout<<i+1<<". satırın normu -->"<<norm<<endl;
        norm=0;
    }

}

//4- A matrisinin sutun normlarını hesaplayınız.
void sutunNormlari(double A[5][5])
{
    double norm=0;
    for(int i =0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            norm+=A[j][i];
        }
        cout<<i+1<<". sutunun normu -->"<<norm<<endl;
        norm=0;
    }

}

//5-) A matrisinin Öklid normunu (N(A)) hesaplayınız.
double oklidNormu(double A[5][5])
{
    double norm=0,aradeger=0;
    for(int i =0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            aradeger=pow(A[i][j], 2);
            norm +=aradeger;
        }
    }

    return sqrt(norm);
}

//6-) N(A)=(iz(ATA))^(1/2) olduğunun sağlamasını gerçekleştiriniz.
void saglama(double A[5][5])
{
    double oklid = oklidNormu(A);
    double iz=matrisinIziniHesaplama(A);
    cout<<"6-) N(A)=(iz(ATA))^(1/2) cunku;"<<endl;
    cout<<"    "<<oklid<<"="<<iz<<"^(1/2)"<<endl;
    cout<<"Yukarıdaki islemi yaptıgımzda --> "<<oklid<<"="<<sqrt(iz)<<endl;
}
//7-) A matrisini Öklid normuna göre normlaştırınız.
void normlastirma(double A[5][5])
{
    double Anormal[5][5];
    for(int i =0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            Anormal[i][j] = A[i][j] / oklidNormu(A);
        }
    }
    matrisYazdir5e5(Anormal);
    cout<<endl;
}

//8-) A matrisinin özdeğerlerini hesaplayınız.
//9-) A matrisinin Spektral (Todd) şart sayısını hesaplayarak kararsızlığını yorumlayınız.

//10-) A matrisinin Hadamard şart sayısını hesaplayarak kararsızlığını yorumlayınız
void hadamard(double A[5][5])
{
    double d = determinantHesapla(A, 5);
    double alpha[5];
    double aratoplam=0 , carpim=1;
    for(int i =0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            aratoplam+=pow(A[i][j], 2);
        }
        alpha[i] = sqrt(aratoplam);
        aratoplam=0;
    }
    for(int i =0;i<5;i++)
    {
        carpim*=alpha[i];
    }
    double hadamard = d/carpim;
    
    cout<<"10-) A matrisinin Hadamard sart sayisi -->"<<hadamard;
    
    if(hadamard<0.01)
    {
        cout<<"   ve kararsizdir "<<endl;
    }
    else
    {
        cout<<"   ve kararlidir"<<endl;
    }
}

//11-) Kramer kuralı ile A matrisinin tersini hesaplayınız.
void kramerTers(double A[5][5])
{
    double aradet=0;
    double araMatris1[4][4] = {{A[1][1] ,A[1][2] ,A[1][3] ,A[1][4]},
                              { A[2][1] ,A[2][2] ,A[2][3] ,A[2][4]},
                              { A[3][1] ,A[3][2] ,A[3][3] ,A[3][4]},
                              { A[4][1] ,A[4][2] ,A[4][3] ,A[4][4]}};
    aradet = determinantHesapla4x4(araMatris1, 4);
    double c11 = aradet;
    
    double araMatris2[4][4] = {{A[1][0] ,A[1][2] ,A[1][3] ,A[1][4]},
                              { A[2][0] ,A[2][2] ,A[2][3] ,A[2][4]},
                              { A[3][0] ,A[3][2] ,A[3][3] ,A[3][4]},
                              { A[4][0] ,A[4][2] ,A[4][3] ,A[4][4]}};
    aradet = determinantHesapla4x4(araMatris2, 4);
    double c12 = -aradet;
    
    double araMatris3[4][4] = {{A[1][0] ,A[1][1] ,A[1][3] ,A[1][4]},
                              { A[2][0] ,A[2][1] ,A[2][3] ,A[2][4]},
                              { A[3][0] ,A[3][1] ,A[3][3] ,A[3][4]},
                              { A[4][0] ,A[4][1] ,A[4][3] ,A[4][4]}};
    aradet = determinantHesapla4x4(araMatris3, 4);
    double c13 = aradet;
    
    double araMatris4[4][4] = {{A[1][0] ,A[1][1] ,A[1][2] ,A[1][4]},
                              { A[2][0] ,A[2][1] ,A[2][2] ,A[2][4]},
                              { A[3][0] ,A[3][1] ,A[3][2] ,A[3][4]},
                              { A[4][0] ,A[4][1] ,A[4][2] ,A[4][4]}};
    aradet = determinantHesapla4x4(araMatris4, 4);
    double c14 = -aradet;
    
    double araMatris5[4][4] = {{A[1][0] ,A[1][1] ,A[1][2] ,A[1][3]},
                              { A[2][0] ,A[2][1] ,A[2][2] ,A[2][3]},
                              { A[3][0] ,A[3][1] ,A[3][2] ,A[3][3]},
                              { A[4][0] ,A[4][1] ,A[4][2] ,A[4][3]}};
    aradet = determinantHesapla4x4(araMatris5, 4);
    double c15 = aradet;
    
    double araMatris6[4][4] = {{A[0][1] ,A[0][2] ,A[0][3] ,A[0][4]},
                              { A[2][1] ,A[2][2] ,A[2][3] ,A[2][4]},
                              { A[3][1] ,A[3][2] ,A[3][3] ,A[3][4]},
                              { A[4][1] ,A[4][2] ,A[4][3] ,A[4][4]}};
    aradet = determinantHesapla4x4(araMatris6, 4);
    double c21 = -aradet;
    
    double araMatris7[4][4] = {{A[0][0] ,A[0][2] ,A[0][3] ,A[0][4]},
                              { A[2][0] ,A[2][2] ,A[2][3] ,A[2][4]},
                              { A[3][0] ,A[3][2] ,A[3][3] ,A[3][4]},
                              { A[4][0] ,A[4][2] ,A[4][3] ,A[4][4]}};
    aradet = determinantHesapla4x4(araMatris7, 4);
    double c22 = aradet;
    
    double araMatris8[4][4] = {{A[0][0] ,A[0][1] ,A[0][3] ,A[0][4]},
                              { A[2][0] ,A[2][1] ,A[2][3] ,A[2][4]},
                              { A[3][0] ,A[3][1] ,A[3][3] ,A[3][4]},
                              { A[4][0] ,A[4][1] ,A[4][3] ,A[4][4]}};
    aradet = determinantHesapla4x4(araMatris8, 4);
    double c23 = -aradet;
    
    double araMatris9[4][4] = {{A[0][0] ,A[0][1] ,A[0][2] ,A[0][4]},
                              { A[2][0] ,A[2][1] ,A[2][2] ,A[2][4]},
                              { A[3][0] ,A[3][1] ,A[3][2] ,A[3][4]},
                              { A[4][0] ,A[4][1] ,A[4][2] ,A[4][4]}};
    aradet = determinantHesapla4x4(araMatris9, 4);
    double c24 = aradet;
    
    double araMatris10[4][4] = {{A[0][0] ,A[0][1] ,A[0][2] ,A[0][3]},
                               { A[2][0] ,A[2][1] ,A[2][2] ,A[2][3]},
                               { A[3][0] ,A[3][1] ,A[3][2] ,A[3][3]},
                               { A[4][0] ,A[4][1] ,A[4][2] ,A[4][3]}};
    aradet = determinantHesapla4x4(araMatris10, 4);
    double c25 = -aradet;
    
    double araMatris11[4][4] = {{A[0][1] ,A[0][2] ,A[0][3] ,A[0][4]},
                               { A[1][1] ,A[1][2] ,A[1][3] ,A[1][4]},
                               { A[3][1] ,A[3][2] ,A[3][3] ,A[3][4]},
                               { A[4][1] ,A[4][2] ,A[4][3] ,A[4][4]}};
    aradet = determinantHesapla4x4(araMatris11, 4);
    double c31 = aradet;
    
    double araMatris12[4][4] = {{A[0][0] ,A[0][2] ,A[0][3] ,A[0][4]},
                               { A[1][0] ,A[1][2] ,A[1][3] ,A[1][4]},
                               { A[3][0] ,A[3][2] ,A[3][3] ,A[3][4]},
                               { A[4][0] ,A[4][2] ,A[4][3] ,A[4][4]}};
    aradet = determinantHesapla4x4(araMatris12, 4);
    double c32 = -aradet;
    
    double araMatris13[4][4] = {{A[0][0] ,A[0][1] ,A[0][3] ,A[0][4]},
                               { A[1][0] ,A[1][1] ,A[1][3] ,A[1][4]},
                               { A[3][0] ,A[3][1] ,A[3][3] ,A[3][4]},
                               { A[4][0] ,A[4][1] ,A[4][3] ,A[4][4]}};
    aradet = determinantHesapla4x4(araMatris13, 4);
    double c33 = aradet;
    
    double araMatris14[4][4] = {{A[0][0] ,A[0][1] ,A[0][2] ,A[0][4]},
                               { A[1][0] ,A[1][1] ,A[1][2] ,A[1][4]},
                               { A[3][0] ,A[3][1] ,A[3][2] ,A[3][4]},
                               { A[4][0] ,A[4][1] ,A[4][2] ,A[4][4]}};
    aradet = determinantHesapla4x4(araMatris14, 4);
    double c34 = -aradet;
    
    double araMatris15[4][4] = {{A[0][0] ,A[0][1] ,A[0][2] ,A[0][3]},
                               { A[1][0] ,A[1][1] ,A[1][2] ,A[1][3]},
                               { A[3][0] ,A[3][1] ,A[3][2] ,A[3][3]},
                               { A[4][0] ,A[4][1] ,A[4][2] ,A[4][3]}};
    aradet = determinantHesapla4x4(araMatris15, 4);
    double c35 = aradet;
    
    double araMatris16[4][4] = {{A[0][1] ,A[0][2] ,A[0][3] ,A[0][4]},
                               { A[1][1] ,A[1][2] ,A[1][3] ,A[1][4]},
                               { A[2][1] ,A[2][2] ,A[2][3] ,A[2][4]},
                               { A[4][1] ,A[4][2] ,A[4][3] ,A[4][4]}};
    aradet = determinantHesapla4x4(araMatris16, 4);
    double c41 = -aradet;
    
    double araMatris17[4][4] = {{A[0][0] ,A[0][2] ,A[0][3] ,A[0][4]},
                               { A[1][0] ,A[1][2] ,A[1][3] ,A[1][4]},
                               { A[2][0] ,A[2][2] ,A[2][3] ,A[2][4]},
                               { A[4][0] ,A[4][2] ,A[4][3] ,A[4][4]}};
    aradet = determinantHesapla4x4(araMatris17, 4);
    double c42 = aradet;
    
    double araMatris18[4][4] = {{A[0][0] ,A[0][1] ,A[0][3] ,A[0][4]},
                               { A[1][0] ,A[1][1] ,A[1][3] ,A[1][4]},
                               { A[2][0] ,A[2][1] ,A[2][3] ,A[2][4]},
                               { A[4][0] ,A[4][1] ,A[4][3] ,A[4][4]}};
    aradet = determinantHesapla4x4(araMatris18, 4);
    double c43 = -aradet;
    
    double araMatris19[4][4] = {{A[0][0] ,A[0][1] ,A[0][2] ,A[0][4]},
                               { A[1][0] ,A[1][1] ,A[1][2] ,A[1][4]},
                               { A[2][0] ,A[2][1] ,A[2][2] ,A[2][4]},
                               { A[4][0] ,A[4][1] ,A[4][2] ,A[4][4]}};
    aradet = determinantHesapla4x4(araMatris19, 4);
    double c44 = aradet;
    
    double araMatris20[4][4] = {{A[0][0] ,A[0][1] ,A[0][2] ,A[0][3]},
                               { A[1][0] ,A[1][1] ,A[1][2] ,A[1][3]},
                               { A[2][0] ,A[2][1] ,A[2][2] ,A[2][3]},
                               { A[4][0] ,A[4][1] ,A[4][2] ,A[4][3]}};
    aradet = determinantHesapla4x4(araMatris20, 4);
    double c45 = -aradet;
    
    double araMatris21[4][4] = {{A[0][1] ,A[0][2] ,A[0][3] ,A[0][4]},
                               { A[1][1] ,A[1][2] ,A[1][3] ,A[1][4]},
                               { A[2][1] ,A[2][2] ,A[2][3] ,A[2][4]},
                               { A[3][1] ,A[3][2] ,A[3][3] ,A[3][4]}};
    aradet = determinantHesapla4x4(araMatris21, 4);
    double c51 = aradet;
    
    double araMatris22[4][4] = {{A[0][0] ,A[0][2] ,A[0][3] ,A[0][4]},
                               { A[1][0] ,A[1][2] ,A[1][3] ,A[1][4]},
                               { A[2][0] ,A[2][2] ,A[2][3] ,A[2][4]},
                               { A[3][0] ,A[3][2] ,A[3][3] ,A[3][4]}};
    aradet = determinantHesapla4x4(araMatris22, 4);
    double c52 = -aradet;
    
    double araMatris23[4][4] = {{A[0][0] ,A[0][1] ,A[0][3] ,A[0][4]},
                               { A[1][0] ,A[1][1] ,A[1][3] ,A[1][4]},
                               { A[2][0] ,A[2][1] ,A[2][3] ,A[2][4]},
                               { A[3][0] ,A[3][1] ,A[3][3] ,A[3][4]}};
    aradet = determinantHesapla4x4(araMatris23, 4);
    double c53 = aradet;
    
    double araMatris24[4][4] = {{A[0][0] ,A[0][1] ,A[0][2] ,A[0][4]},
                               { A[1][0] ,A[1][1] ,A[1][2] ,A[1][4]},
                               { A[2][0] ,A[2][1] ,A[2][2] ,A[2][4]},
                               { A[3][0] ,A[3][1] ,A[3][2] ,A[3][4]}};
    aradet = determinantHesapla4x4(araMatris24, 4);
    double c54 = -aradet;
    
    double araMatris25[4][4] = {{A[0][0] ,A[0][1] ,A[0][2] ,A[0][3]},
                               { A[1][0] ,A[1][1] ,A[1][2] ,A[1][3]},
                               { A[2][0] ,A[2][1] ,A[2][2] ,A[2][3]},
                               { A[3][0] ,A[3][1] ,A[3][2] ,A[3][3]}};
    aradet = determinantHesapla4x4(araMatris25, 4);
    double c55 = aradet;
    
    double anadet = determinantHesapla(A, 5);
    double tersmatris[5][5] ={{c11/anadet ,c21/anadet ,c31/anadet ,c41/anadet ,c51/anadet},
                              {c12/anadet ,c22/anadet ,c32/anadet ,c42/anadet ,c52/anadet},
                              {c13/anadet ,c23/anadet ,c33/anadet ,c43/anadet ,c53/anadet},
                              {c14/anadet ,c24/anadet ,c34/anadet ,c44/anadet ,c54/anadet},
                              {c15/anadet ,c25/anadet ,c35/anadet ,c45/anadet ,c55/anadet}};
    matrisYazdir5e5(tersmatris);
}

//14-) Gauss algoritması ile x bilinmeyenler vektörünü hesaplayınız. Önce alt üçgen matris oluşturulur.
void gaussIleXBilinmeyenlerVektoru(double B[5][6])
{
    double sifir=0.0;
    double carpim =0.0;
    for(int k = 0;k<=4;k++)
    {
        for(int i = k+1; i<=4;i++)
        {
            sifir = B[i][k] / B[k][k];
            for(int j = k; j<=5;j++)
            {
                carpim = B[k][j]*sifir;
                B[i][j] = B[i][j] - carpim;
            }
            carpim =0.0;
        }
        sifir=0.0;
    }
    B[3][1] =0.0;
    
    double x[5];
    x[4] = B[4][5] / B[4][4];
    for(int i=3;i>=0;i--)
    {
        double toplam =0;
        for(int j=i+1;j<=4;j++)
        {
            toplam = B[i][j] * x[j];
        }
        double tmp = B[i][5] - toplam;
        x[i] = tmp / B[i][i];
    }
    matrisYazdir1e5(x);
}

//15-) Gauss Jordan
void gaussJordan(double B[5][6])
{
    double b;//Line 1
    int i,j,k;
    double x[5];
    for(j=0; j<=4; j++)
    {
        for(i=0; i<=4; i++)
        {
            if(i!=j)
            {
                b=B[i][j]/B[j][j];
                for(k=0; k<=5; k++)
                {
                   B[i][k]=B[i][k]-b*B[j][k];
                }
             }
        }
    }
    for(i=0; i<=4; i++)
    {
        x[i]=B[i][4+1]/B[i][i];
        cout<<x[i]<<"\t";
    }
    
}

int main()
{

    cout<<"1-) A matrisinin determinantı      --> "<<determinantHesapla(A,5)<<endl;
    cout<<"2-) A matrisinin transpozunun izi  -->"<<matrisinIziniHesaplama(A)<<endl;
    cout<<"3-) A matrisinin satır normları ;"<<endl;
    satirNormlari(A);
    cout<<"4-) A matrisinin sutun normları ;"<<endl;
    sutunNormlari(A);
    cout<<"5-) A matrisinin oklid normu  --> "<< oklidNormu(A)<<endl;
    saglama(A);
    cout<<"7-) A matrisinin oklid normu ile normallastirlmis hali;"<<endl;
    normlastirma(A);
    hadamard(A);
    cout<<"11-) A matrisinin kramer kuralı ile tersi hesaplandı ve matris;"<<endl;
    kramerTers(A);
    cout<<endl;
    cout<<"14-)Gauss algoritması ile x bilinmeyenler vektörü hesaplandı ve matris;"<<endl;
    gaussIleXBilinmeyenlerVektoru(B);
    cout<<endl;
    cout<<"15-)Gauss jordan yöntemi ile x bilinmeyenler vektörü hesaplandı ve matris;"<<endl;
    gaussJordan(B);
    cout<<endl;
    return 0;
}
