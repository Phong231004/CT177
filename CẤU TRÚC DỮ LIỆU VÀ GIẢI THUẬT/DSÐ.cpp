#include <stdio.h>
#include<string.h>

typedef struct {
    char MSSV[10];
    char HoTen[50];
    float DiemLT;
    float DiemTH1;
    float DiemTH2;
}SinhVien;
typedef struct
{
    SinhVien A[40];
    int n;
}DanhSach;
void MakeNull(DanhSach *pL){
	pL->n = 0;
}
DanhSach dsRong(){
    DanhSach L;
    L.n=0;
    return L;
};
int ktRong(DanhSach L){
    return(L.n==0);
}
int EndDanhSach(DanhSach L){
    return L.n+1;
}
int FullDanhSach(DanhSach L){
    if(L.n==40) return 1;
    else return 0;
}
void chenCuoi(SinhVien s, DanhSach *pL){
    if(FullDanhSach(*pL)==1) printf ("Loi! Danh sach day!");
    else {
        pL->n++;
        pL->A[EndDanhSach(*pL)-2]=s;
    }
}
int tim(char x[10],DanhSach L)
{
    for(int i=0; i<L.n; i++)
    {
        if(strncmp(L.A[i].MSSV,x,8)==0) return i+1;
    }
    return L.n+1;
}
void hienthi(DanhSach L)
{
    int i=0;
    for (i=1;i<=L.n;i++)
    {
        printf ("%s - %s - %.2f - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2,L.A[i].DiemLT+L.A[i].DiemTH1+L.A[i].DiemTH2 );
    }
}
void checkstr(char x[])
{
    if(x[strlen(x)-1] == '\n')//h\n\0
    {
        x[strlen(x)-1] = '\0';
    }
}
DanhSach nhap()
{
    DanhSach DS = dsRong();
    SinhVien s;
    int a;
    scanf("%d ", &a);
    int p = 1;
    while(p <= a)
    {
        fgets(s.MSSV, sizeof(s.MSSV), stdin);
        checkstr(s.MSSV);
        fgets(s.HoTen, sizeof(s.HoTen), stdin);
        checkstr(s.HoTen);
        scanf("%f %f %f\n", &s.DiemLT, &s.DiemTH1, &s.DiemTH2 );
        if( (tim(s.MSSV, DS) == DS.n+1))
        {
            chenCuoi(s, &DS);
        }
        p++;
    }
    return DS;
}
void hienthiDat(DanhSach L)
{
    int i=0;
    for (i=0;i<L.n;i++)
    {
        float DTB=L.A[i].DiemLT+L.A[i].DiemTH1+L.A[i].DiemTH2 ;
        if(DTB>=4.0)
        {
        printf ("%s - %s - %.2f - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2,L.A[i].DiemLT+L.A[i].DiemTH1+L.A[i].DiemTH2 );
        }
    }
}
DanhSach chepKhongDat(DanhSach L)
{
    DanhSach pL=dsRong();
    int i=0;
    for (i=0;i<L.n;i++)
    {
        float DTB=L.A[i].DiemLT+L.A[i].DiemTH1+L.A[i].DiemTH2 ;
        if(DTB<4.0)
        {
        chenCuoi(L.A[i],&pL);
        }
    }
    return pL;
}
int main ()
{
	DanhSach L;
	MakeNull(&L);
	nhap();
	hienthi(L);
	chepKhongDat(L);
	return 0;
}
