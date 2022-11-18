#include <bits/stdc++.h>
using namespace std;
  
struct Node 
{
    int coeff;
    int pow;
    struct Node* next;
};

typedef struct Node node;

void create_node(int coeff, int power,struct Node** poly)
{
    node *nn, *temp = *poly;
    if (temp == NULL) 
    {
        nn = (node*)malloc(sizeof(node));
        nn->coeff = coeff;
        nn->pow = power;
        *poly = nn;
        nn->next = (node*)malloc(sizeof(node));
        nn = nn->next;
        nn->next = NULL;
    }
    else 
    {
        nn->coeff = coeff;
        nn->pow = power;
        nn->next = (node*)malloc(sizeof(node));
        nn = nn->next;
        nn->next = NULL;
    }
}
  
// Function Adding two polynomial 
void polyadd(node* poly1,node* poly2,node* poly)
{
    while (poly1->next && poly2->next) 
    {
        if (poly1->pow > poly2->pow) 
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) 
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else 
        {
            poly->pow = poly1->pow;
            poly->coeff = (poly1->coeff + poly2->coeff);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
  
        // Dynamically create new node
        poly->next = (node*)malloc(sizeof(node));
        poly = poly->next;
        poly->next = NULL;
    }
    while (poly1->next || poly2->next) 
    {
        if (poly1->next) 
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next) 
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next = (node*)malloc(sizeof(node));
        poly = poly->next;
        poly->next = NULL;
    }
}
  
// Display Linked list
void show(struct Node* node)
{
    while (node->next != NULL) 
    {
        printf("%dx^%d", node->coeff, 
                node->pow);
        node = node->next;
        if (node->coeff >= 0) 
        {
            if (node->next != NULL)
                printf("+");
        }
    }
}
  
// ---------------main-----------------
int main()
{
    struct Node *poly1 = NULL,*poly2 = NULL,*poly = NULL;
  
    create_node(6, 2, &poly1);
    create_node(8, 1, &poly1);
    create_node(20, 0, &poly1);

    create_node(3, 1, &poly2);
    create_node(4, 0, &poly2);
  
    printf("1st Number: ");
    show(poly1);
    cout<<endl;
    printf("2nd Number: ");
    show(poly2);
  
    poly = (node*)malloc(sizeof(node));
    
    cout<<endl;
    // add two polynomial 
    polyadd(poly1, poly2, poly);
  
    // Display resultant List
    printf("Added polynomial: ");
    show(poly);
  
    return 0;
}