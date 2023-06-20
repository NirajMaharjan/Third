#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct LinkedList{
	int info;
	struct LinkedList *next;
};
typedef struct LinkedList node;

node *start;

int isEmpty(){
	if (start==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
void read(){								//on test for creating nodes
	node *newNode;
	int item;
	newNode=(node*)malloc(sizeof(node));
	printf("Enter the item: ");
	scanf("%d",&item);
	newNode->info=item;
}	
void iBegin(){										//beginning insertion
	if (start==NULL){							//to insert into empty
		node *newNode;
		int item;
		newNode=(node*)malloc(sizeof(node));
		printf("Enter the item: ");
		scanf("%d",&item);
		newNode->info=item;
		newNode->next=start;
		start=newNode;
	}
	else{										//insert into beginning for non-empty
		node *newNode;
		int item;
		newNode=(node*)malloc(sizeof(node));
		printf("Enter the item: ");
		scanf("%d",&item);
		newNode->info=item;
		newNode->next=start;
		start=newNode;
	}
}

void iEnd(){
	node *newNode;
	node* temp,*prevNode;
	int item;
	newNode=(node*)malloc(sizeof(node));
	printf("Enter the item: ");
	scanf("%d",&item);
	newNode->info=item;
	temp=start;
	while(temp!=NULL){
		prevNode=temp;
		temp=temp->next;
	}
	newNode->next=NULL;
	prevNode->next=newNode;
}

void iNth(){
	node *newNode;
	node* temp,*prevNode;
	int item,pos,n=1;
	newNode=(node*)malloc(sizeof(node));
	printf("Enter the item: ");
	scanf("%d",&item);
	newNode->info=item;
	printf("Enter the position to insert at: ");
	scanf("%d",&pos);
	temp=start;
	while(n!=pos){
		prevNode=temp;
		temp=temp->next;
		n++;
	}
	newNode->next=prevNode->next;		//(or temp) temp contains next node address
	prevNode->next=newNode;

}
void display(){
	node* temp;
	int i=0;
	if(start==NULL){
		printf("List Empty");
	}
	temp=start;
	while (temp!=NULL){
		printf("\n a[%d]=%d",i,temp->info);
		i++;
		temp=temp->next;
	}
}
int main(){
	int choice;
	do{
		system("cls");
		printf("1.insert at begin \n2.Insert at end  \n3.Insert at nth node \n4.Display \n5.Quit \n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				iBegin();
				break;
			case 2:
				iEnd();
				break;
			case 3:
				iNth();
				break;
			case 4:
				display();
				break;		
		}
		
		getch();
	}while(choice!=5);
	
	return 0;
}
