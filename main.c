#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_BOOKS 100
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 100
#define MAX_ID_LENGTH 20

struct Book {
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
    char author[MAX_NAME_LENGTH];
    int issued;
    char student_id[MAX_ID_LENGTH];
    time_t issued_date;
};

struct Student {
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
    int issued_books;
};

struct Book books[MAX_BOOKS];
struct Student students[MAX_STUDENTS];
int books_count = 0;
int students_count = 0;

void add_book() {
    printf("Enter Book ID: ");
    scanf("%s", books[books_count].id);
    printf("Enter Book Name: ");
    scanf("%s", books[books_count].name);
    printf("Enter Book Author: ");
    scanf("%s", books[books_count].author);
    books[books_count].issued = 0;
    books_count++;
    printf("Book Added Successfully!\n");
    return;
}

void add_student() {
    printf("Enter Student ID: ");
    scanf("%s", students[students_count].id);
    printf("Enter Student Name: ");
    scanf("%s", students[students_count].name);
    students[students_count].issued_books = 0;
    students_count++;
    printf("Student Added Successfully!\n");
    return;
}

void issue_book() {
    char student_id[MAX_ID_LENGTH], book_id[MAX_ID_LENGTH];
    int student_index, book_index;
    printf("Enter Student ID: ");
    scanf("%s", student_id);
    printf("Enter Book ID: ");
    scanf("%s", book_id);

    for (int i = 0; i < students_count; i++) {
    if (strcmp(students[i].id, student_id) == 0) {
        student_index = i;
        break;
    }
    }

    for (int i = 0; i < books_count; i++) {
    if (strcmp(books[i].id, book_id) == 0) {
        book_index = i;
        break;
    }
    }

    if (students[student_index].issued_books >= 3) {
    printf("Student has already issued 3 books.\n");
    return;
    }

    if (books[book_index].issued) {
    printf("Book is already issued.\n");
    return;
    }

    books[book_index].issued = 1;
    strcpy(books[book_index].student_id, student_id);
    books[book_index].issued_date = time(NULL);
    students[student_index].issued_books++;
    printf("Book Issued Successfully!\n");
    return;
}

void return_book() {
char book_id[MAX_ID_LENGTH];
int book_index;
printf("Enter Book ID: ");
scanf("%s", book_id);

for (int i = 0; i < books_count; i++) {
if (strcmp(books[i].id, book_id) == 0) {
book_index = i;
break;
}
}

if (!books[book_index].issued) {
printf("Book is not issued.\n");
return;
}

for (int i = 0; i < students_count; i++) {
if (strcmp(students[i].id, books[book_index].student_id) == 0) {
students[i].issued_books--;
break;
}
}

books[book_index].issued = 0;
printf("Book Returned Successfully!\n");
return;
}

void show_student_books() {
char student_id[MAX_ID_LENGTH];
int student_index;
printf("Enter Student ID: ");
scanf("%s", student_id);

for (int i = 0; i < students_count; i++) {
if (strcmp(students[i].id, student_id) == 0) {
student_index = i;
break;
}
}

printf("Books issued to %s:\n", students[student_index].name);
for (int i = 0; i < books_count; i++) {
if (strcmp(books[i].student_id, student_id) == 0) {
printf("Book ID: %s\n", books[i].id);
printf("Book Name: %s\n", books[i].name);
printf("Book Author: %s\n", books[i].author);
printf("Issued Date: %s\n", ctime(&books[i].issued_date));
printf("\n");
}
}
return;
}

void check_book_status() {
char book_id[MAX_ID_LENGTH];
int book_index;
printf("Enter Book ID: ");
scanf("%s", book_id);

for (int i = 0; i < books_count; i++) {
if (strcmp(books[i].id, book_id) == 0) {
book_index = i;
break;
}
}

if (books[book_index].issued) {
printf("Book is issued to %s.\n", books[book_index].student_id);
} else {
printf("Book is not issued.\n");
}
return;  
}

int main() {
int option;
while (1) {
printf("\n");
printf("1. Add Book\n");
printf("2. Add Student\n");
printf("3. Issue Book\n");
printf("4. Return Book\n");
printf("5. Show Student Books\n");
printf("6. Check Book Status\n");
printf("7. Exit\n");
printf("Enter option: ");
scanf("%d", &option);

switch (option) {
    case 1:
    add_book();
    break;
    case 2:
    add_student();
    break;
    case 3:
    issue_book();
    break;
    case 4:
    return_book();
    break;
    case 5:
    show_student_books();
    break;
    case 6:
    check_book_status();
    break;
    case 7:
    return 0;
    default:
    printf("Invalid option. Try again.\n");
    break;
}
}
return 0;

} 