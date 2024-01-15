#include <stdio.h>
#include <stdlib.h> 
typedef struct stud{
	int i;
	struct stud *next;
}stu;
struct newStu{
	int idnew;
	int idold;
}nstu;
int main(){
	int n,t;
	scanf("%d",&n,&t);
	stu  *p,*head,*tail;
	p=(struct stud*)malloc(sizeof(struct stud));
	head=p;
	tail=p;
	head->next=NULL;
	for(int i=0;i<n;i++){
		p=(struct stud*)malloc(sizeof(struct stud));
		scanf("%d",&p->i);
		tail->next=p;
		tail=p;
		tail->next=NULL;	
	} 
	stu *q;
	q=(struct stud*)malloc(sizeof(struct stud));
	struct newStu nstu[3000];
	for(int j=0;j<t;j++){
		scanf("%d %d",&nstu[j].idnew,&nstu[j].idold);
		q->i=nstu[j].idnew;
		p=head;
		while(p!=NULL){
			if(p->next->i==q->i){
				q->next=p->next;
				p->next=q;
				break; 
			}
			p=p->next;
			
		}
		p=p->next;
	}
	while(p!=NULL){
		printf("%d ",p->i);
		p=p->next;
	}
	
}