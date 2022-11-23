#include<iostream>

using namespace std;

struct Node{
    int coeff;
    int power;
<<<<<<< HEAD
    struct Node* node;
}*poly=NULL,*poly1=NULL,*poly2=NULL;;

typedef struct Node node;

=======
    struct Node* next;
}*poly=NULL,*poly1=NULL,*poly2=NULL;

typedef struct Node node;

struct Node*  newNode(int coeff,int pow){
    node *temp = (node*)malloc(sizeof(node));
    temp->coeff=coeff;
    temp->power=pow;
    temp->next=NULL;
    return temp;
}

void show(struct Node* node)
{
    while (node->next != NULL) 
    {
        printf("%dx^%d", node->coeff,node->power);
        node = node->next;
        if (node->power >= 0) 
        {
            if (node!= NULL)
                printf("+");
        }
    }
    printf("%dx^%d", node->coeff,node->power);
}

void polyAdd(node * poly1, node * poly2,node *poly)
{
    while (poly1->next && 
           poly2->next) 
    {
        // If power of 1st polynomial is greater 
        // than 2nd, then store 1st as it is and 
        // move its pointer
        if (poly1->power > poly2->power) 
        {
            poly->power = poly1->power;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
  
        // If power of 2nd polynomial is greater 
        // than 1st, then store 2nd as it is and 
        // move its pointer
        else if (poly1->power < poly2->power) 
        {
            poly->power = poly2->power;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
  
        // If power of both polynomial numbers 
        // is same then add their coefficients
        else 
        {
            poly->power = poly1->power;
            poly->coeff = (poly1->coeff + 
                           poly2->coeff);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
  
        // Dynamically create new node
        poly->next = 
              (struct Node*)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
    while (poly1->next || poly2->next) 
    {
        if (poly1->next) 
        {
            poly->power = poly1->power;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next) 
        {
            poly->power = poly2->power;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next = 
              (struct Node*)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
}

int main(){
    poly1=newNode(3,3);
    poly1->next=newNode(4,2);
    poly1->next->next=newNode(10,1);
    poly1->next->next->next=newNode(6,0);

    poly2=newNode(6,2);
    poly2->next=newNode(2,1);
    poly2->next->next=newNode(5,0);   

    show(poly1);
    cout<<"\n";
    show(poly2); 

    polyAdd(poly1,poly2,poly);
    show(poly);

    return 0;
}
>>>>>>> 7d08f6871305d1765a6e21715ddfac5e82608264
