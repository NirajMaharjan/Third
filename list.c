#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 5


struct List{
	int arr[max];
	int size;
};
typedef struct List list;

int isEmpty(list*);
int isFull(list *);
void insert(list *);
//void remove(list*);
void traverse(list*);
void search(list*);
void modify(list*);


int main(){
	list l;
	int option;
	l.size=0;

	
	do{
		system("cls");
		printf("1.Insert 2.Remove 3.Traverse 4.Search 5.Modify 6.Exit");
		printf("\nEnter your choice: ");
		scanf ("%d",&option);
		switch(option){
			case 1:
				insert(&l);
				break;
			case 2:
				//remove();
				break;
			case 3:
				traverse(&l);
				break;
			case 4:
				//search();
				break;
			case 5:
				modify(&l);
				break;
			case 6:
				printf("Quitting...");
		}
		getch();
	}while(option!=6);
	return 0;
}

int isFull(list *l){
	if (l->size==max){
		return 1;
	}
	return 0;
}

int isEmpty(list *l){
	if (l->size==0){
		return 1;
	}
	return 0;
}
void insert(list *l){
	int n,pos,i;
	if (isFull(l)){
		printf("List is Full");
		return;
	}
	printf("Enter the item to push: ");
	scanf("%d",&n);
	printf("Enter the index to push item: ");
	scanf("%d",&pos);
	if(pos>l->size+1 || pos<1){
		printf("Wrong Index");
		return;
	}
	if (pos==(l->size)+1){
		l->size++;
		l->arr[l->size-1]=n;
	}
	else{
		for (i=l->size-1;i>=pos-1;i--){
			l->arr[i+1]=l->arr[i];
		}
		++l->size;
		l->arr[pos-1]=n;
	}

}



void traverse(list *l){
	int i;
	for (i=0;i<=l->size-1;i++){
		printf("\na[%d]=%d",i+1,l->arr[i]);
	}
}

void modify(list *l){
	int i,pos,item;
	if(isEmpty(l)){
		printf("list is empty");
		return;
	}
	printf("Enter the position to modify: ");
	scanf("%d",&pos);
	if(pos<1 || pos>l->size){
		printf("Invalid Index");
		return;
	}
	else{
		printf("Enter the new element: ");
		scanf("%d",&item);
	}
	l->arr[pos-1]=item;
}
