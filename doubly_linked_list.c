#include <stdio.h>
#include <stdlib.h>

/* Linked list structure */
struct linkedlist
{
	struct linkedlist *prev;
	int data;
	struct linkedlist *next;

}*node = NULL, *first = NULL, *last=NULL;

/* Function for create/insert node at the beginning of Linked list */
void insert_beginning() {
	/* Dynamic memory allocation */
	node = malloc(sizeof(struct linkedlist));
	printf("Enter value for the node: ");
	scanf_s("%i", &node->data);

	if (first == NULL)
	{
		node->prev = NULL;
		node->next = NULL;
		first = node;
		last = node;
		printf("Linked list created! \n");
	}
	else
	{
		node->prev = NULL;
		first->prev = node;
		node->next = first;
		first = node;
	}
}

/* Function for create/insert node at the end of Linked List */
void insert_end() {
	/* Dynamic memory allocation */
	node = malloc(sizeof(struct linkedlist));
	printf("Enter value for the node: ");
	scanf_s("%d", &node->data);

	if (first == NULL) 
	{
		node->prev = NULL;
		node->next = NULL;
		first = node;
		last = node;
		printf("Linked list created!\n");
	}
	else
	{
		node->next = NULL;
		last->next = node;
		node->prev = last;
		last = node;
		printf("Data inserted at the end of the Linked List!\n");
	}
}

/* Function of Display Linked list */
void display() {
	node = first;
	printf("List of data in Linked List in Ascending order!\n");
	while (node != NULL) 
	{
		printf("%d\n", node->data);
		node = node->next;
	}

	printf("\n\n-------------\n\n");

	node = last;
	printf("List of data in Linked list in Descending order!\n");
	while (node != NULL) {
		printf("%d\n", node->data);
		node = node->prev;
	}
}


/* Function for delete a node in Linked List */
void delete() {
	int number, encontrou = 0;
	node = first;
	struct linkedlist *prev = NULL, *next = NULL;
	
	printf("Enter the number of the node that you want to delete: ");
	scanf_s("%d", &number);

	while ((node != NULL) && (node->data != number)) {
		node = node->next;
		if ((node != NULL) && (node->data == number)) {
			encontrou = 1;
		}
	}


	if (encontrou == 1)
	{
		prev = node->prev;
		next = node->next;

		prev->next = next;
		next->prev = prev;
		node->next = NULL;
		node->prev = NULL;
		free(node);
		printf("\nNode has been deleted successfully!\n");
	}
	else 
	{
		printf("\nNot found!\n");
	}
}

int main() {
	int op = 0;
	while (op != 9) {
		printf("1 - Insert at the beginning\n");
		printf("2 - Insert at the end\n");
		printf("3 - Delete\n");
		printf("4 - Display\n");
		printf("9 - Exit\n");
		printf("Enter your choice: ");
		scanf_s("%d", &op);

		switch (op)
		{
			case 1:
				insert_beginning();
				break;

			case 2:
				insert_end();
				break;

			case 3:
				delete();
				break;

			case 4:
				display();
				break;

			case 9:
				printf("Goodbye.");
				exit(0);
				break;

			default:
				break;
			}
		}
	return 0;
}