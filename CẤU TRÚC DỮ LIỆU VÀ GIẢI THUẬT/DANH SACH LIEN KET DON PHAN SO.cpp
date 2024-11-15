#include <stdio.h>
#include <malloc.h>
typedef struct
{
 	int mau;
 	int tu;
} Phanso;
typedef struct Node
{
	Phanso PS;
	Node *lienket;
};
typedef struct Node * vitri;
typedef vitri DS;
void Khoitao (DS *L)
{
	(*L)->lienket=NULL;
}
int KTRong (DS L)
{
	if (L->lienket==NULL) return 1;
	return 0;
}
vitri DauDS (DS L)
{
	return L;
}
vitri CuoiDS (DS L)
{
	vitri P;
	P=DauDS(L);
	while (P->lienket!=NULL)
	{
		P=P->lienket;
	}
	return P;
}
void chen (Phanso X,vitri P,DS *L){
	vitri T;
	T = (struct Node*)malloc(sizeof(struct Node));
	T->PS = X;
	T->lienket= P->lienket;
	P->lienket = T;
}
void xoa (vitri P, DS L)
{
	vitri K;
	if (P->lienket!=NULL)
	{
		K=P->lienket;
		P->lienket=K->lienket;
		free(K);
	}
}
int UCLN (int A, int B)
{
	if (B==0) return A;
	return UCLN (B, A%B);
}
void toigian (Phanso *P)
{
	int ucln;
	ucln=UCLN(P->tu,P->mau);
	P->tu=P->tu/ucln;
	P->mau=P->mau/ucln;
}
float GTPS(Phanso P,DS L)
{
	return (float)P.tu/(float)P.mau;
}
void sapxep (DS *L)
{
	vitri P=*L;
	vitri T;
	Phanso PS;
	int tem1, tem2;
	while (P->lienket!=NULL)
	{
		T=P->lienket;
		while (T->lienket!=NULL)
		{
			if(GTPS(P->lienket->PS,*L)>GTPS(T->lienket->PS,*L))
			{
				tem1=P->lienket->PS.tu;
				tem2=P->lienket->PS.mau;
				P->lienket->PS.tu=T->lienket->PS.tu;
				P->lienket->PS.mau=T->lienket->PS.mau;
				T->lienket->PS.tu=tem1;
				T->lienket->PS.mau=tem2;
			}
		T=T->lienket;
		}
	P=P->lienket;
	}
}
void tim (Phanso PS, DS L)
{
	vitri P;
	P=DauDS(L);
	int dem=0;
	int i=1;
	while (P!=CuoiDS(L) && dem!=1)
	{
		if (P->lienket->PS.tu==PS.tu && P->lienket->PS.mau==PS.mau) 
		{
			dem=1;
			printf ("Phan so can tim co trong danh sach\n");
			printf ("Phan so can tim nam o vi tri thu %i trong danh sach.\n",i);
			i++;
		}
		
		else
		{
		P=P->lienket;
		}
	}
	if (dem==0) printf ("Khong tim thay phan so trong danh sach");
}
void nhap(DS *pL)
{ 
	int i,n,t;
	Phanso X;
	vitri P;
	P=DauDS(*pL);
	printf ("Nhap so phan tu toi da co trong danh sach: ");
	scanf ("%d",&n);
	for (i=1; i<=n; i++)
	{
		printf("Nhap phan so thu %d: \n",i);
		printf ("1. Nhap tu so: ");
		scanf ("%d",&X.tu);
		printf ("2. Nhap mau so: ");
		scanf ("%d",&X.mau);
		printf ("\n");
		chen(X,CuoiDS(*pL),pL);
	}
	
    
}
void in (DS L)
{
	vitri P;
	Phanso PS;
	P=DauDS(L);
	int i=1;
	while (P!=CuoiDS(L))
	{
		printf ("Phan so thu %d la: ",i);
		printf ("%d/%d ",P->lienket->PS.tu,P->lienket->PS.mau);
		printf ("\n");
		i++;
		P=P->lienket;
	}
}
int main ()
{
	DS L;
	Khoitao(&L);
	nhap(&L);
	printf ("Danh sach phan so sau khi nhap la: \n");
	in(L);
	vitri X;
	X=DauDS(L);
	while (X!=NULL)
	{
		toigian(&X->PS);
		X=X->lienket;
	}
	printf ("\n\n");
	printf ("Danh sach phan so da toi gian:\n");
	in(L);
	printf ("\n");
	printf ("Danh sach phan so da sap xep: \n");
	sapxep(&L);
	in(L);
	printf ("\n");
	Phanso PS;
	printf ("Nhap phan so can tim: ");
	scanf ("%d %d", &PS.tu, &PS.mau);
	printf ("Phan so can tim la: %d/%d", PS.tu, PS.mau);
	printf ("\n");
	toigian(&PS);
	tim(PS, L);
		
	return 0;
}
