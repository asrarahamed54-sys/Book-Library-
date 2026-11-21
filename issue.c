#include <stdio.h>
#include <string.h>
#include <time.h>

struct Book
{
    int book_id;
    char title[100];
    char author[100];
    int quantity;
};

struct Issue
{
    int issue_id;
    int book_id;
    int user_id;
    char user_name[100];

    char issue_date[11];
    char due_date[11];
    char return_date[11];

    int fine;
    int returned;
};

/* Shared data from library.c */

extern struct Book books[100];
extern struct Issue issues[100];

extern int book_count;
extern int issue_count;


void issueBook()
{
    int i;
    int book_id;
    int user_id;
    int found = 0;

    time_t current_time;
    struct tm *date;


    printf("\n");
    printf("========================================\n");
    printf("              ISSUE BOOK\n");
    printf("========================================\n");


    if(book_count == 0)
    {
        printf("No books available!\n");
        return;
    }


    printf("Enter Book ID: ");
    scanf("%d", &book_id);


    /* Search Book */

    for(i = 0; i < book_count; i++)
    {
        if(books[i].book_id == book_id)
        {
            found = 1;
            break;
        }
    }


    if(found == 0)
    {
        printf("\nBook ID not found!\n");
        return;
    }


    /* Check Quantity */

    if(books[i].quantity <= 0)
    {
        printf("\nBook is not available!\n");
        return;
    }


    printf("\nBook Details\n");
    printf("-------------------------\n");

    printf("Book ID  : %d\n", books[i].book_id);
    printf("Title    : %s\n", books[i].title);
    printf("Author   : %s\n", books[i].author);
    printf("Quantity : %d\n", books[i].quantity);

    printf("-------------------------\n");


    /* User Details */

    printf("\nEnter User ID: ");
    scanf("%d", &user_id);

    printf("Enter User Name: ");
    scanf(" %[^\n]", issues[issue_count].user_name);


    /* Issue ID */

    issues[issue_count].issue_id = issue_count + 1;

    issues[issue_count].book_id = book_id;

    issues[issue_count].user_id = user_id;


    /* Issue Date */

    current_time = time(NULL);

    date = localtime(&current_time);

    strftime(issues[issue_count].issue_date,
             sizeof(issues[issue_count].issue_date),
             "%d-%m-%Y",
             date);


    /* Due Date - 7 Days */

    current_time = current_time + (7 * 24 * 60 * 60);

    date = localtime(&current_time);

    strftime(issues[issue_count].due_date,
             sizeof(issues[issue_count].due_date),
             "%d-%m-%Y",
             date);


    /* Return Details */

    strcpy(issues[issue_count].return_date, "Not Returned");

    issues[issue_count].fine = 0;

    issues[issue_count].returned = 0;


    /* Reduce Quantity */

    books[i].quantity--;


    /* Increase Issue Count */

    issue_count++;


    printf("\n");
    printf("========================================\n");
    printf("          BOOK ISSUED SUCCESSFULLY\n");
    printf("========================================\n");

    printf("Issue ID   : %d\n",
           issues[issue_count - 1].issue_id);

    printf("Book ID    : %d\n",
           issues[issue_count - 1].book_id);

    printf("Book Title : %s\n",
           books[i].title);

    printf("User ID    : %d\n",
           issues[issue_count - 1].user_id);

    printf("User Name  : %s\n",
           issues[issue_count - 1].user_name);

    printf("Issue Date : %s\n",
           issues[issue_count - 1].issue_date);

    printf("Due Date   : %s\n",
           issues[issue_count - 1].due_date);

    printf("========================================\n");
}
