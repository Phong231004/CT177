#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Khai bao Queue
struct Node{
	int Data;
	struct Node *Next;
};
typedef struct {
	Node *front;
	Node *rear;
}Queue;
//Tao rong Queue
void MakenullQueue(Queue *Q){
	struct Node *Hear =(struct Node*)malloc(sizeof(struct Node));
	Hear->Next=NULL;
	Q->front=Hear;
	Q->rear=Hear;
}
//Kiem tra rong
int EmtyQueue(Queue Q){
	if (Q.front==Q.rear) return 1;
	return 0;
}
//Xac dinh gia tri o dau hang
int Front(Queue Q){
	return Q.front->Next->Data;
}
//Xoa gia tri dau hang
void DeleteFirstQueue(Queue *Q){
	struct Node*T=(struct Node*)malloc(sizeof(struct Node));
	T = Q->front;
	Q->front=Q->front->Next;
	free(T);	
}
//Them 1 phan tu vao cuoi danh sach
void AddEndQueue(int x,Queue *Q){
	struct Node*T = (struct Node*)malloc(sizeof(struct Node));
	T->Data=x;
	T->Next=NULL;
	Q->rear->Next=T;
	Q->rear=T;
}
//Ham nhap Queue
Queue ReadQueue(){
	Queue Q;
	MakenullQueue(&Q);
	int n,x;
	printf("\t- Nhap vao so nut chua data toi da trong Queue:");
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		printf("\t\t+ Nhap data cua phan tu thu %d: ",i);
		scanf("%d",&x);
		AddEndQueue(x,&Q);
	}
	return Q;
}
//Ham in Queue
void PrintQueue(Queue Q){
	printf("\t- Noi dung Queue: ");
	while (EmtyQueue(Q)!=1)
	{
		printf("%d ",Q.front->Next->Data);
		DeleteFirstQueue(&Q);
	}
}
//Tim so nhi phan
Queue BinaryQueue(int n){
	Queue Q,P;
	MakenullQueue(&Q);
	MakenullQueue(&P);
	int Bin;
	while (n!=0)
	{
		Bin=n%2;
		AddEndQueue(Bin,&Q);
		n=n/2;
	}
	while (EmtyQueue(Q)!=1)
	{
		AddEndQueue(Front(Q),&P);
		DeleteFirstQueue(&Q);
	}
	return P;
}
//Tim so bat phan
Queue OctalQueue(int n){
	Queue Q,P;
	MakenullQueue(&Q);
	MakenullQueue(&P);
	int Oct;
	while (n!=0)
	{
		Oct=n%8;
		AddEndQueue(Oct,&Q);
		n=n/8;
	}
	while (EmtyQueue(Q)!=1)
	{
		AddEndQueue(Front(Q),&P);
		DeleteFirstQueue(&Q);
	}
	return P;
}
void Display(Queue Q){
	while(EmtyQueue(Q)!=1)
	{
		printf("%d ",Front(Q));
		DeleteFirstQueue(&Q);
	}
}
int main (){
	Queue Q,P;
	MakenullQueue(&Q);
	MakenullQueue(&P);
	Q=ReadQueue();
	PrintQueue(Q);
	printf("\n");
	int n;
	printf("\t- Nhap vao gia tri ma ban muon doi: ");
	scanf("%d",&n);
	printf("\t\t--> So nhi phan tuong ung cua so %d la: ",n);
	P=BinaryQueue(n);
	Display(P);
	printf("\n");
	MakenullQueue(&P);
	printf("\t\t--> So bat phan tuong ung cua so %d la: ",n);
	P=OctalQueue(n);
	Display(P);
	printf("\n");
	
	
}
