#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaring the student data:
struct student {
	int id;
	char name[50];
	int age;
	float gpa;
};

//creating the list nodes:
struct node {
	struct student data;
	struct node *next;
};

//making a pointer to the first node, it should be seen globally!!
struct node *head = NULL;

//a function to insert nodes from last
void addStudent(const struct student *const ptr) {
	struct node *std = (struct node*) malloc(sizeof(struct node));

	if (std == 0) {
		printf("failed to allocate memory\n");
		return;
	}

	std->data = *ptr;

	//this node is the last one, so its pointer points to NULL
	std->next = NULL;

	//for adding the first node:
	if (head == NULL) {
		head = std;
		printf("\n");
		printf("new student added successfully");
		return;
	}

	//make a copy of head, we don't want to mess with the head!
	struct node *current = head;

	//Looping until reaching last node:
	while (current->next != NULL) {

		//checking ID previous reservation
		if (current->data.id == ptr->id) {
			printf("this id is already reserved!\n");
			return;
		}

		//jumping to next node:
		current = current->next;
	}

	//attaching the inserted node with the previous one:
	current->next = std;
	printf("\n");
	printf("new student added successfully");
}


void displayStudents(void) {
	if (head == NULL) {
		printf("no students are present\n");
		return;
	}
	struct node *current = head;
	while (current != NULL) {
		printf("[ ID: %d, name: %s, age: %d, GPA: %0.1f]\n", current->data.id,
				current->data.name, current->data.age, current->data.gpa);
		current = current->next;
	}
}


void searchStudentByID(int id) {
	if (head == NULL) {
		printf("no students are present\n");
		return;
	}

	struct node *current = head;

	while (current != NULL) {
		if (current->data.id == id) {
			printf("student found: \n");
			printf("[ ID: %d, name: %s, age: %d, GPA: %0.1f]\n",
					current->data.id, current->data.name, current->data.age,
					current->data.gpa);
			return;
		}
		current = current->next;
	}

	printf("student with ID %d not found", id);
}
void updateStudent(int id) {
	if (head == NULL) {
		printf("no students are present\n");
		return;
	}
	struct node *current = head;
	while (current != NULL) {
		if (current->data.id == id) {
			printf("enter new details for the student with ID %d: \n", id);
			printf("Enter new name: ");
			scanf("%s", current->data.name);
			printf("Enter new age: ");
			scanf("%d", &current->data.age);
			printf("Enter new GPA: ");
			scanf("%f", &current->data.gpa);
			printf("student's data updated successfully");
			return;
		}
		current = current->next;
	}
	printf("ID not found");
}
void deleteStudent(int id) {
	if (head == NULL) {
		printf("no students are present\n");
		return;
	}

	struct node *delete_node = head;

	//checking first node:
	if (head->data.id == id) {
		head = head->next;
		free(delete_node);
		printf("student with ID %d has been deleted.\n", id);
		return;
	}

	struct node *current = head->next;
	struct node *prev = head;
	while (current != NULL) {
		if (current->data.id == id) {
			prev->next = current->next;
			free(current);
			printf("student with ID %d has been deleted.\n", id);
			return;
		}
		prev = prev->next;
		current = current->next;
	}

	// when there is no student with that ID:
	printf("student with ID [%d], not found.", id);
}
float calculateAverageGPA(void) {
	int counter = 0;
	float accum = 0;

	if (head == NULL) {
		printf("no students are present\n");
		return 0.0;
	}
	struct node *current = head;
	while (current != NULL) {
		accum += current->data.gpa;
		counter++;
		current = current->next;
	}

	return ( accum / (float)counter); //needs explicit casting
}
void searchHighestGPA(void) {
	float max = 0.0;

	if (head == NULL) {
		printf("no students are present\n");
		return;
	}
	struct node *current = head;
	while (current != NULL) {
		max = (current->data.gpa > max) ? current->data.gpa : max; //for compare
		current = current->next;
	}
	printf("the maximum GPA equals: %0.1f", max);
}

int main(void) {

	struct student new_st;
	//important for displaying printf()
	setvbuf(stdout, NULL, _IONBF, 0);

	//making a user input number for choosing the operation:
	//making a sample of id to be given in some operations:
	int op_num, id;
	do {
		printf(
				"\n==========================================================\n");
		printf("1. Add a Student\n");
		printf("2. Display All Students\n");
		printf("3. Search For a Student by ID\n");
		printf("4. Update Student Information\n");
		printf("5. Delete a Student\n");
		printf("6. Calculate Average GPA\n");
		printf("7. Find Student with Highest GPA\n");
		printf("8. Exit\n\n");
		printf("Choose an operation: ");
		scanf("%d", &op_num);
		printf("\n==========================================================\n");

		// to determine the req. operation:
		switch (op_num) {
		case 1:

				//collecting new student's info:
				printf("Enter student's ID: ");
				scanf("%d", &new_st.id);
				printf("Enter student's name: ");
				scanf("%s", new_st.name);
				printf("Enter student's age: ");
				scanf("%d", &new_st.age);
				printf("Enter student's GPA: ");
				scanf("%f", &new_st.gpa);
				addStudent(&new_st);
			break;
		case 2:
			displayStudents();
			break;
		case 3:
			printf("enter the id needed for searching: ");
			scanf("%d", &id);
			searchStudentByID(id);
			break;
		case 4:
			printf("enter the id to update the information: ");
			scanf("%d", &id);
			updateStudent(id);
			break;
		case 5:
			printf("enter the id to be deleted: ");
			scanf("%d", &id);
			deleteStudent(id);
			break;
		case 6:
			printf("the average GPA equals: %0.1f", calculateAverageGPA());
			break;
		case 7:
			searchHighestGPA();
			break;
		case 8:
			printf("Done Successfully\n");
			break;
		default:
			printf("Enter a valid number: \n");
		}

	} while (op_num != 8);

	return 0;
}

