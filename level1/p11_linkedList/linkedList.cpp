#include<stdio.h>
#include<stdlib.h>
struct list
	{
		int score;
		struct list *next;
	};
void value(struct list *p);
int find1(struct list *p,int n); 
int find2(struct list *p,int n);
struct list *creatlist(int n);
struct list *reverse(struct list *p);

int i,k=0;	
int j;

int main()
{
	int n,x1,x2;
	static struct list *p;
	printf("The number of nodes:");
	scanf("%d",&n);
	
	p=creatlist(n);
	value(p);
	reverse(p);
	value(p);
	reverse(p);
	
	x1=find1(p,n);
	printf("%d\n",x1);
	x2=find2(p,n);
	printf("%d\n",x2);
	
	return 0;
}

struct list *creatlist(int n) 
{
	struct list *head,*node,*end;
	head=(struct list*)malloc(sizeof(struct list));
	end=head;
	for(i=0;i<n;i++)
	{
		printf("Input score:");
		node=(struct list*)malloc(sizeof(struct list));
		scanf("%d",&node->score);
		end->next=node;
		end=node;
	}
	end->next=NULL;
	 return head;
}

void value(struct list *p)
{
	while(p->next!=NULL)
	{
		p=p->next;
		printf("%d ",p->score);
	}
	printf("\n");
}

struct list *reverse(struct list *p)
{
	struct list *t1,*t2,*t3;
	if(p==NULL||p->next==NULL)
	    return p;
	t1=p->next;
	t2=t1->next;
	t1->next=NULL;
	
	while(t2)
	{
		t3=t2->next; 
 		t2->next=t1;
 		t1=t2;
 		t2=t3;
	}
	p->next=t1;
	return p;
}

int find1(struct list *p,int n) 
{
	for(j=1;j<=n;j++)
	{
		p=p->next;
		if(p->score==5)
		{
			return j;
		}
	}
	return -1;
}

int find2(struct list *p,int n) 
{
	for(j=1;j<=n;j++)
	{
		p=p->next;
		if(p->score==5)
		{
			k++;
			if(k==2)
			    return j;
		}
	}
	return -1;
}

