#include<stdio.h>
#define max_books 100
struct books
{
    char name[100];
    char author[100];
    char ISBI_number[100];
    char genre[100];
    float price;
    int publication_year;
    int avail;
} book[max_books];
float avg_price(int n)
{
    float sum=0.0;
    for(int i=0;i<n;i++)
    {
        sum=sum+book[i].price;
    }
    float avg=sum/n;
    return avg;
}
void old_new(int n,int *maxind,int *minind)
{
    int max,min;
    max=book[0].publication_year;
    min=book[0].publication_year;
    for(int i=0;i<n;i++)
    {
        if(max<book[i].publication_year)
        {
            max=book[i].publication_year;
            *maxind=i;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(min>book[i].publication_year)
        {
            min=book[i].publication_year;
            *minind=i;
        }
    }
}
int count(int n)
{
    int book_count=0;
    for(int i=0;i<n;i++)
    {
        book_count++;
    }
    return book_count;
}
void expensive(int n,int *expind)
{
    int exp;
    exp=book[1].price;
    for(int i=0;i<n;i++)
    {
        if(exp<book[i].price)
        {
            exp=book[i].price;
            *expind=i;
        }
    }
}

int main()
{
    int maxind=0,minind=0,expind=0;
    int n;
    
    printf("enter the num of books you want to enter:\n");
    scanf("%d",&n);
    old_new(n,&maxind,&minind);
    expensive(n,&expind);
    for(int i=1;i<=n;i++)
    {
        printf("\nenter the book %d details:\n",i);
        printf("enter the title:\n");
        scanf("%s",book[i].name);
        printf("name of the author:\n");
        scanf("%s",book[i].author);
        printf("ISBN:");
        scanf("%s",book[i].ISBI_number);
        printf("enter the genre:\n");
        scanf("%s",book[i].genre);
        printf("enter the price of the book\n");
        scanf("%d",&book[i].price);
        printf("enter the publication year:\n");
        scanf("%d",&book[i].publication_year);
        printf("availability(1 for available,0 for not available):\n");
        scanf("%d",&book[i].avail);
    }
    for(int i=1;i<=n;i++)
    {
        printf  ("book %d details:\n",i);
        printf("\ntitle:%s",book[i].name);
        printf("\nauthor:%s",book[i].author);
        printf("\nISBN:%s",book[i].ISBI_number);
        printf("\ngenre:%s",book[i].genre);
        printf("\npublication year:%d",book[i].publication_year);
        printf("\nprice:%d",book[i].price);
        if(book[i].avail==1)
        {
            printf("\n\nthe book is available.....");
        }
        else{
            printf("\n\nthe book is not available(borrowed)......");
        }
    }
    
    printf("\n\nthe expensive book is:%s(%d)",book[expind].name,book[expind].price);
    int total_books=count(n);
    printf("\n\nthe total no of books:%d",total_books);
    
    printf("\n\nthe oldest book:%s(%d)",book[minind].name,book[minind].publication_year);
    printf("\n\nthe newest book:%s(%d)",book[maxind].name,book[maxind].publication_year);
    printf("\n\nthe average price of the books:%2f",avg_price(n));
    printf("\n\nthe book whose price is above the average");
    for(int i=0;i<n;i++)
    {
        if(book[i].price>avg_price(n))
        {
            printf("%s(%d)",book[i].name,book[i].price);
        }
    }
}