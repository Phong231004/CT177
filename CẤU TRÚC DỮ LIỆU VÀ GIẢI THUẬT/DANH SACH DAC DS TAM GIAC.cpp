#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
typedef struct
{
	int x;
	int y;
	int z;
} Diem;
typedef struct
{
	Diem A ;
	Diem B ;
	Diem C ;
} TamGiac;
typedef struct 
{
	int n;
	TamGiac TG[40];
}DanhSach;
DanhSach dsRong()
{
	DanhSach L;
	L.n=0;
	return L;
}
int ktRong(DanhSach L)
{
	if (L.n==0) return 1;
	return 0;
}
int ktDay (DanhSach L)
{
	if (L.n==40) return 1;
	return 0;
}
int CuoiDS (DanhSach L)
{
	return L.n+1;
}
void chencuoi (TamGiac P, DanhSach *L)
{
	if (ktDay(*L)==1) printf ("LOI DAY!!!\n");
	else
	{
			L->n++;
			L->TG[CuoiDS(*L)-2]=P;
	}
}
int tim (TamGiac T, DanhSach L )
{
	int i;
	for (i=0; i<L.n; i++)
	{
		if (((T.A.x==L.TG[i].A.x && T.A.y==L.TG[i].A.y && T.A.z==L.TG[i].A.z)
		  && (T.B.x==L.TG[i].B.x && T.B.y==L.TG[i].B.y && T.B.z==L.TG[i].B.z)
		  && (T.C.x==L.TG[i].C.x && T.C.y==L.TG[i].C.y && T.C.z==L.TG[i].C.z))
		 || ((T.A.x==L.TG[i].B.x && T.A.y==L.TG[i].B.y && T.A.z==L.TG[i].B.z)
		  && (T.B.x==L.TG[i].A.x && T.B.y==L.TG[i].A.y && T.B.z==L.TG[i].A.z)
		  && (T.C.x==L.TG[i].C.x && T.C.y==L.TG[i].C.y && T.C.z==L.TG[i].C.z))
		 || ((T.A.x==L.TG[i].B.x && T.A.y==L.TG[i].B.y && T.A.z==L.TG[i].B.z)
		  && (T.B.x==L.TG[i].C.x && T.B.y==L.TG[i].C.y && T.B.z==L.TG[i].C.z)
		  && (T.C.x==L.TG[i].A.x && T.C.y==L.TG[i].A.y && T.C.z==L.TG[i].A.z))
		 || ((T.A.x==L.TG[i].C.x && T.A.y==L.TG[i].C.y && T.A.z==L.TG[i].C.x)
		  && (T.B.x==L.TG[i].A.x && T.B.y==L.TG[i].A.y && T.B.z==L.TG[i].A.z)
		  && (T.C.x==L.TG[i].B.x && T.C.y==L.TG[i].B.y && T.C.z==L.TG[i].B.z))
		 || ((T.A.x==L.TG[i].C.x && T.A.y==L.TG[i].C.y && T.A.z==L.TG[i].C.z)
		  && (T.B.x==L.TG[i].B.x && T.B.y==L.TG[i].B.y && T.B.z==L.TG[i].B.z)
		  && (T.C.x==L.TG[i].A.x && T.C.y==L.TG[i].A.y && T.C.z==L.TG[i].A.z))
		 || ((T.A.x==L.TG[i].A.x && T.A.y==L.TG[i].A.y && T.A.z==L.TG[i].A.z)
		  && (T.B.x==L.TG[i].C.x && T.B.y==L.TG[i].C.y && T.B.z==L.TG[i].C.z)
		  && (T.C.x==L.TG[i].B.x && T.C.y==L.TG[i].B.y && T.C.z==L.TG[i].B.z)))
		{
			return i+1;
		}
	}
	return L.n+1;
}
float DoDai(Diem A, Diem B)
{
	float d;
	d= sqrt(pow((B.x-A.x),2)+pow((B.y-A.y),2)+pow((B.z-A.z),2));
	return d;
}
DanhSach CheckTG (DanhSach L)
{
	DanhSach pL;
	pL=dsRong();
	int i;
	for (i=0; i<L.n; i++)
	{
		if (((DoDai(L.TG[i].A,L.TG[i].B)+DoDai(L.TG[i].B,L.TG[i].C))>DoDai(L.TG[i].A,L.TG[i].C))
		||((DoDai(L.TG[i].A,L.TG[i].B)+DoDai(L.TG[i].A,L.TG[i].C))>DoDai(L.TG[i].B,L.TG[i].C))
		||((DoDai(L.TG[i].A,L.TG[i].C)+DoDai(L.TG[i].B,L.TG[i].C))>DoDai(L.TG[i].A,L.TG[i].B)))
		{
		chencuoi(L.TG[i], &pL);
		}
	}
	return pL;
}
float Chuvi (TamGiac T)
{
	float C;
	C=DoDai(T.A,T.B) + DoDai(T.B,T.C) + DoDai(T.A,T.C);
	return C;
}
float DienTich (TamGiac T)
{
	float p, S;
	p=Chuvi(T)/2.0;
	S=sqrt(p*(p-(DoDai(T.A,T.B)))*(p-(DoDai(T.B,T.C)))*(p-(DoDai(T.A,T.C))));
	return S;
}
void sapxepS (DanhSach L)
{
	int i,j;
	int tem11, tem12, tem13;
	int tem21, tem22, tem23;
	int tem31, tem32, tem33;
	for (i=0; i<L.n; i++)
	{
		for (j=i; j<L.n; j++)
		{
		if (DienTich(L.TG[i]) > DienTich(L.TG[j]))
		{
			tem11 = L.TG[i].A.x;
			tem12 = L.TG[i].A.y;
			tem13 = L.TG[i].A.z;
			
			tem21 = L.TG[i].B.x;
			tem22 = L.TG[i].B.y;
			tem23 = L.TG[i].B.z;
			
			tem31 = L.TG[i].C.x;
			tem32 = L.TG[i].C.y;
			tem33 = L.TG[i].C.z;
			
			L.TG[i].A.x = L.TG[j].A.x;
			L.TG[i].A.y = L.TG[j].A.y;
			L.TG[i].A.z = L.TG[j].A.z;
			
			L.TG[i].B.x = L.TG[j].B.x;
			L.TG[i].B.y = L.TG[j].B.y;
			L.TG[i].B.z = L.TG[j].B.z;
			
			L.TG[i].C.x = L.TG[j].C.x;
			L.TG[i].C.y = L.TG[j].C.y;
			L.TG[i].C.z = L.TG[j].C.z;
			
			L.TG[j].A.x = tem11;
			L.TG[j].A.y = tem12;
			L.TG[j].A.z = tem13;
			
			L.TG[j].B.x = tem21;
			L.TG[j].B.y = tem22;
			L.TG[j].B.z = tem23;
			
			L.TG[j].C.x = tem31;
			L.TG[j].C.y = tem32;
			L.TG[j].C.z = tem33;
		}
		}
	}
}void sapxepC (DanhSach L)
{
	int i,j;
	TamGiac T;
	for (i=0; i<L.n; i++)
	{
		for (j=0; j<L.n; j++)
		{
			if (Chuvi(L.TG[j])>Chuvi(L.TG[i]))
			{
				T=L.TG[i];
				L.TG[j]=L.TG[i];
				L.TG[j]=T;
			}
		}
	}
}
DanhSach nhap()
{
	DanhSach L = dsRong();
	TamGiac T;
	int a;
	printf ("NHAP SO LUONG PHAN TU TOI DA CO TRONG DANH SACH: ");
	scanf ("%d",&a);
	for(int p=0; p<a; p++)
	{
		printf ("NHAP TOA DO CAC DINH CUA TAM GIAC THU %i TRONG DANH SACH:\n",p+1);
		printf ("Nhap 03 toa do dinh thu nhat I cua tam giac thu %d: ",p+1);
		scanf ("%d %d %d", &T.A.x, &T.A.y, &T.A.z);
		printf ("Nhap 03 toa do dinh thu nhat II cua tam giac thu %d: ",p+1);
		scanf ("%d %d %d", &T.B.x, &T.B.y, &T.B.z);
		printf ("Nhap 03 toa do dinh thu nhat III cua tam giac thu %d: ",p+1);
		scanf ("%d %d %d", &T.C.x, &T.C.y, &T.C.z);
		if (tim(T,L)==L.n+1)
		{
			chencuoi(T,&L);
		}
	}
	return L;
}
void hienthi (DanhSach L)
{
	for (int i=0; i<L.n; i++)
	{
		printf ("Toa do cac dinh cua tam giac thu %d trong danh sach:\n",i+1);
		printf ("Toa do diem A (%d, %d, %d)\n",L.TG[i].A.x, L.TG[i].A.y, L.TG[i].A.z);
		printf ("Toa do diem B (%d, %d, %d)\n",L.TG[i].B.x, L.TG[i].B.y, L.TG[i].B.z);
		printf ("Toa do diem C (%d, %d, %d)\n",L.TG[i].C.x, L.TG[i].C.y, L.TG[i].C.z);
		printf ("\n");
	}
}
int main ()
{
	DanhSach L;
	L=dsRong();
	L=nhap();
		printf("HIEN THI TAT CA CAC GIA TRI CO TRONG DANH SACH:\n");
	hienthi(L);
	DanhSach pL;
	pL= CheckTG(L);
	printf ("CAC TAM GIAC CO 3 DINH HOP THANH HOP LE LA: \n");
	hienthi(pL);
	printf ("DIEN TICH VA CHU VI CUA CAC TAM GIAC LAN LUOT THOA MAN CO TRONG DANH SACH: \n");
	int i;
	for (i=0; i<pL.n; i++)
	{
		printf ("%d. TAM GIAC THU %d:\n",i+1, i+1);
		printf ("Dien tich cua tam giac thu la: %.7f\n", DienTich(pL.TG[i]));
		printf ("Chu vi cua tam giac thula: %.7f\n", Chuvi(pL.TG[i]));
	}
	sapxepS(L);
	printf ("DANH SACH SAP XEP TAM GIAC CO DIEN TICH TANG DAN:\n");
	hienthi(L);
	sapxepC(L);
	printf ("DANH SACH SAP XEP TAM GIAC CO CHU VI GIAM DAN:\n");
	hienthi(L);
	return 0;
}
		

