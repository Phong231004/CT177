#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    int mau;
    int tu;
}Phanso;
typedef struct
{
    Phanso PS[40];
    int n;
}DanhSach;
DanhSach dsRong(){
    DanhSach L;
    L.n=0;
    return L;
};
int KTrong (DanhSach L)
{
	if (L.n==0) return 1;
	return 0;
}
int KTday (DanhSach L)
{
	if (L.n==40) return 1;
	return 0;
}
int CuoiDS (DanhSach L)
{
	return L.n+1;
}
void chencuoi(Phanso P, DanhSach *L)
{
	if (KTday(*L)==1) printf ("Loi day!!!\n");
	else 
	{
		L->n++;
		L->PS[CuoiDS(*L)-2]=P;
	}
}
int tim (Phanso P, DanhSach L)
{
	int i;
	for (i=0; i<L.n; i++)
	{
		if (P.tu==L.PS[i].tu && P.mau==L.PS[i].mau) return i+1;
	}
	return L.n+1;
}
float GTPS(Phanso P)
{
	return (float)P.tu/(float)P.mau;
}
int UCLN (int a, int b)
{
	if (b==0) return a;
	return UCLN (b, a%b);
}
void ToigianPS(Phanso *P)
{
	int ucln;
	ucln = UCLN (P->tu, P->mau);
	P->tu=P->tu/ucln;
	P->mau=P->mau/ucln;
}
void DSTG(DanhSach *L)
{
	int i;
	for(i=0; i<L->n; i++)
	{
		ToigianPS(&L->PS[i]);
	}
}
void sapxep (DanhSach L)
{
	int tem1, tem2; 
	int n;
	int i,j;
	for (i=0; i<L.n; i++)
	{
		for (j=i; j<L.n; j++)
		{
			if (GTPS(L.PS[i]) > GTPS(L.PS[j]))
			{
				tem1=L.PS[i].tu;
				tem2=L.PS[i].mau;
				L.PS[i].tu=L.PS[j].tu;
				L.PS[i].mau=L.PS[j].mau;
				L.PS[j].tu=tem1;
				L.PS[j].mau=tem2;
			}
		}
	}
}	
Phanso Tong(DanhSach *L)
{
	Phanso P1;
	int TongTu;
	int TongMau;
	P1=L->PS[0];
	int j;
	for (j=1; j<L->n; j++)
	{
		TongTu=L->PS[j].mau*P1.tu+L->PS[j].tu*P1.mau;
		TongMau=L->PS[j].mau*P1.mau;
	}
	Phanso P;
	P.tu=TongTu;
	P.mau=TongMau;
	ToigianPS(&P);
	return P;		
}
Phanso Tich(DanhSach *L)
{
	int TichTu=1;
	int TichMau=1;
	int i;
	for (i=0; i<L->n; i++)
	{
		TichTu=TichTu*L->PS[i].tu;
		TichMau=TichMau*L->PS[i].mau;
	}
	Phanso P;
	P.tu=TichTu;
	P.mau=TichMau;
	ToigianPS(&P);
	return P;
}
DanhSach PSlonhon1(DanhSach pL)
{
	DanhSach L;
	L =dsRong();
	int i;
	for (i=0; i<pL.n; i++)
	{
		if (GTPS(pL.PS[i])>=1.0)
		{
			chencuoi(pL.PS[i], &L);
		}
	}
	return L;
}
DanhSach PSnhohon1(DanhSach pL)
{
	DanhSach L;
	L =dsRong();
	int i;
	for (i=0; i<pL.n; i++)
	{
		if (GTPS(pL.PS[i])<1.0)
		{
			chencuoi(pL.PS[i], &L);
		}
	}
	return L;
}
DanhSach nhap()
{
    DanhSach DS = dsRong();
    Phanso Ps;
    int a;
    printf ("Nhap so luong phan tu toi da co trong danh sach: ");
    scanf("%d", &a);
    int p;
    for (p=0; p<a; p++)
    {
    	printf ("Nhap gia tri thu %d: \n",p+1);
    	printf ("Nhap gia tri tu cua phan so thu %d: ",p+1);
        scanf ("%d", &Ps.tu );
        printf ("Nhap gia tri mau cua phan so thu %d: ",p+1);
    	scanf ("%d", &Ps.mau);
        if( (tim(Ps, DS) == DS.n+1))
        {
            chencuoi(Ps, &DS);
        }
    }
	return DS;
}
void hienthi (DanhSach L)
{
	int i;
	for (i=0; i<L.n; i++)
	{
		printf ("Phan so thu %i la: ",i+1);
		printf ("%d/%d",L.PS[i].tu, L.PS[i].mau);
		printf ("\n");
	}
}
int main ()
{
	DanhSach L;
	L=dsRong();
	L=nhap();
	printf ("\n");
	printf ("DANH SACH: \n");
	hienthi(L);
	DSTG(&L);
	printf("\n");
	printf ("DANH SACH DA TOI GIAN: \n");
	hienthi(L);
	sapxep(L);
	printf ("\n");
	printf ("DANH SACH DA DUOC SAP XEP TANG DAN: \n");
	hienthi(L);
	Phanso P;
	printf ("\n");
	scanf ("%d %d", &P.tu, &P.mau);
	ToigianPS(&P);
	printf ("Phan so can tim: %d/%d\n", P.tu, P.mau);
	int i, dem=0;
	for (i=0; i<L.n; i++)
	{
		if (tim(P, L)==i+1)
		{
			printf ("Phan so %d/%d co trong danh sach, nam o vi tri thu %d trong danh sach.", P.tu, P.mau, i+1);
			dem=1;
		}
	}
	if (dem==0) printf ("phan so %d/%d khong co trong danh sach.", P.tu, P.mau);	
	Phanso PS;
	PS=Tong(&L);
	printf ("\n");
	printf ("TONG CAC GIA TRI PHAN SO TRONG DANH SACH BANG: ");
	printf ("%d/%d (%.5f)",PS.tu, PS.mau, GTPS(PS));
	printf ("\n");
	Phanso Ps;
	Ps=Tich(&L);
	printf ("TICH CAC GIA TRI PHAN SO TRONG DANH SACH BANG: ");
	printf ("%d/%d (%.5f)",Ps.tu, Ps.mau, GTPS(Ps));
	printf ("\n");
	DanhSach PL;
	PL=dsRong();
	printf ("CAC PHAN SO CO GIA TRI LON HON 1 LA:\n");
	PL= PSlonhon1(L);
	hienthi(PL);
	printf ("CAC PHAN SO CO GIA TRI NHO HON 1 LA:\n");
	PL= PSnhohon1(L);
	hienthi(PL);
	return 0;
}
	
	
