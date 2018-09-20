#include <stdio.h>
#include <stdlib.h>

//structure for storing student's data
typedef struct Node{
  char studentName[20],branch[20];
  int age;
  int year;
  int preScore;
  struct Node* next;
}node;

//Function declaration
void sortedList(node **head);
void printList(node *head);
void insertNode(node **head);

int main()
{
   int input;
   node *head;
   head = NULL;
   printf("****Application Program****\n");

   while(1){
    //Menu for the database
    printf("Choose an option\n");
    printf("1: Create Database\n");
    printf("2: List of all students\n");
    printf("3: Filter as per previous semester score\n");
    printf("4: Exit\n");

    scanf("%d",&input);

    switch(input){
    case 1: insertNode(&head);
            break;

    case 2: printf("The list of student is as follows\n");
            printList(head);//function to print the list
            break;

    case 3: printf("Sorted list according to score of each student: \n");
            printList(head);
            break;

    case 4: exit(0);
            break;

    default : ("Invalid input, choose an option between 1-4");
   }
   }
    return 0;
}

//enter new nodes in a sorted order of score in previous semester
void insert(struct node **head){
  int age1;
  int year1;
  int preScore1;
  char studentName1[20],branch1[20];
  struct node *new_node = (node*)malloc(sizeof(node));
  struct node *ptr, *ptr1;

  printf("Enter student's name\n");
  scanf("%[^\n]s",studentName1);
  printf("Enter student's age\n");
  scanf("%d", &age1);
  printf("Enter student's branch\n");
  scanf("%[^\n]s", branch1);
  printf("Enter student's score in previous semester\n");
  scanf("%d", preScore1);

  new_node -> age = age1;
  new_node -> year = year1;
  new_node -> preScore = preScore1;
  new_node -> studentName = studentName1;
  new_node -> branch = branch1;
  new_node -> next  = NULL;

  if(head == NULL){
    *head = new_node;
  }
  do{
    *ptr = head;
    if((*new_node->preScore) > (head->preScore)){
            *head = new_node;
            new_node->next = ptr->next;
        }
    while(ptr1 != NULL){
        ptr1 = ptr;
        if(new_node->preScore < ptr->preScore){
            ptr = ptr->next;
            ptr1->next = ptr;
        }
        else{
            new_node->next = ptr -> next;
            ptr1-> next = new_node;
        }
    }
  }while(ptr != NULL);


}

void printList(struct node *head){
    while(head != NULL){
        printf("%s \n", node->studentName);
        head = head->next;
    }
}








