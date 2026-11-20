//#include <iostream>
//
//#define OK 1
//#define ERROR 0
//#define OVERFLOW -2
//
//using namespace std;
//
//typedef struct LNode
//{
//	size_t num;//��� 
//	int pw;//���� 
//	struct LNode *next; 
//} LNode,*LinkList;
//
////1.����
//int CreateList(LinkList &L)
//{
//	LinkList head=nullptr;
//	LinkList tail=nullptr;
//	LinkList p = new LNode;
//	if(!p)
//	   return ERROR;
//	   
//	//��ʼ����һ���ڵ�
//	p->num=1;
//	//cout<<"���ʼ����һ���ڵ㣺";
//	cin>>p->pw;
//	  
//	head=p;tail=p;
//	p->next=head;
//	L=head;//���������� 
//	return OK;
//}
//
////2.���루β���� 
//int InsertList(LinkList &L,int num,int pw)
//{
//	LinkList p=new LNode;
//	if(!p)
//	  return ERROR;
//	p->pw=pw;
//	p->num=num;
//	
//	LinkList tail=L;
//	while(tail->next!=L)
//	{
//		tail=tail->next;
//	}
//	
//	tail->next=p;
//	p->next=L;
//		
//	return OK;
//}
//
////3.�㷨
//void algorithm(LinkList &L,int n,int m)
//{
//	LinkList cur=L;
//	LinkList pre=L;
//	while(pre->next!=L)//��λpreΪtail 
//	{
//		pre=pre->next;
//	}
//	
//    int remaining=n;//������ 
//	while(remaining>1) 
//	{
//	  int count=1;	 
//	  while(count!=m)
//	  {
//		cur=cur->next;
//		pre=pre->next; 
//		count++;
//	  }
//	  if(count==m)
//	  {
//		pre->next=cur->next;
//		cur->next=nullptr;
//		int cur_pw=cur->pw;
//		cout<<cur->num<<' '; 
//		if(cur==L)
//		  L=pre->next;
//		delete cur;
//		remaining--;
//		cur=pre->next;
//		m=cur_pw; 
//	  }	
//	}
//	//�������һ����
//	cout<<cur->num<<' ';
//	delete L; 
//    L=nullptr;
//} 
//
//int main()
//{
//	int n,m;//�����ͱ߽� 
//	int pw;
//	cin>>n>>m;
//	
//	LinkList L;
//	CreateList(L);
//	
//	for(int num=2;num<=n;num++)//���� 
//	{
//		//cout<<"���ʼ����"<<num<<"���ڵ㣺";
//		cin>>pw;
//		InsertList(L,num,pw);
//	}
//	algorithm(L,n,m);
//	return 0;
//}
//
