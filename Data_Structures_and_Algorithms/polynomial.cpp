#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct polynomial {
    int coef;
    int exp;
    struct polynomial *next;
} *Link, Node;

void inputPoly(Link head);
void print(Link head);
bool insert(Link head, int coef, int exp);
void combin2List(Link heada, Link headb, Link headab);

int main() {
    Link headA, headB;
    Link headAB;

    headA = (Link)malloc(sizeof(Node));
    if (headA == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    headA->next = NULL;
    headB = (Link)malloc(sizeof(Node));
    if (headB == NULL) {
        printf("Memory allocation failed!\n");
        free(headA);
        return 1;
    }
    headB->next = NULL;
    headAB = (Link)malloc(sizeof(Node));
    if (headAB == NULL) {
        printf("Memory allocation failed!\n");
        free(headA);
        free(headB);
        return 1;
    }
    headAB->next = NULL;

    printf("Please enter the coefficients and exponents of the first polynomial, ending with (0 0):\n");
    inputPoly(headA);
    printf("The first ");
    print(headA);
    printf("Please enter the coefficients and exponents of the second polynomial, ending with (0 0):\n");
    inputPoly(headB);
    printf("The second ");
    print(headB);

    combin2List(headA, headB, headAB);
    printf("After merging ");
    print(headAB);

    Link temp;
    while (headA != NULL) {
        temp = headA;
        headA = headA->next;
        free(temp);
    }
    while (headB != NULL) {
        temp = headB;
        headB = headB->next;
        free(temp);
    }
    while (headAB != NULL) {
        temp = headAB;
        headAB = headAB->next;
        free(temp);
    }

    return 0;
}

void inputPoly(Link head) {
    int coef, exp;
    printf("Please enter the coefficient and exponent (e.g., \"2 3\" represents 2x^3): ");
    scanf("%d %d", &coef, &exp);
    while (coef != 0 || exp != 0) {
        insert(head, coef, exp);
        printf("Please enter the coefficient and exponent: ");
        scanf("%d %d", &coef, &exp);
    }
}

bool insert(Link head, int coef, int exp) {
    Link node;
    Link q, p;
    q = head;
    p = head->next;
    node = (Link)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        return false;
    }
    node->coef = coef;
    node->exp = exp;

    if (head->next == NULL) {
        head->next = node;
        node->next = NULL;
    } else {
        while (p != NULL) {
            if (node->exp > p->exp) {
                node->next = p;
                q->next = node;
                return true;
            } else if (node->exp == p->exp) {
                p->coef += node->coef;
                free(node);
                return true;
            } else {
                q = p;
                p = p->next;
            }
        }
        q->next = node;
        node->next = NULL;
    }
    return true;
}

void print(Link head) {
    Link p;
    printf("The polynomial is as follows:\n");
    p = head->next;

    if (p == NULL) {
        printf("The polynomial is empty\n");
        return;
    }

    bool isFirstItem = true;
    while (p != NULL) {
        if (!isFirstItem && p->coef > 0) {
            printf("+");
        }
        if (p->coef != 1 && p->coef != -1) {
            printf("%d", p->coef);
        } else if (p->coef == -1) {
            printf("-");
        }
        if (p->exp == 1) {
            printf("x");
        } else if (p->exp > 1) {
            printf("x^%d", p->exp);
        } else if (p->exp == 0) {
            if (p->coef == 1 || p->coef == -1) {
                printf("1");
            } else {
                printf("%d", p->coef);
            }
        }
        p = p->next;
        isFirstItem = false;
    }
    printf("\n");
}

void combin2List(Link heada, Link headb, Link headab) {
    Link pa, pb, pab;
    pa = heada->next;
    pb = headb->next;
    pab = headab;

    while (pa != NULL && pb != NULL) {
        if (pa->exp > pb->exp) {
            insert(pab, pa->coef, pa->exp);
            pa = pa->next;
        } else if (pa->exp < pb->exp) {
            insert(pab, pb->coef, pb->exp);
            pb = pb->next;
        } else if (pa->exp == pb->exp) {
            int newCoef = pa->coef + pb->coef;
            if (newCoef != 0) {
                insert(pab, newCoef, pa->exp);
            }
            pa = pa->next;
            pb = pb->next;
        }
    }
    while (pa != NULL) {
        insert(pab, pa->coef, pa->exp);
        pa = pa->next;
    }
    while (pb != NULL) {
        insert(pab, pb->coef, pb->exp);
        pb = pb->next;
    }
}    