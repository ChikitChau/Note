#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode
{
    float coef;
    int expon;
    int cnt;
    Polynomial next;
};

Polynomial CreatPolyn()
{
    Polynomial q, r, head;
    head = (Polynomial)malloc(sizeof(struct PolyNode));
    r = head;
    char c;
    do
    {
        q = (Polynomial)malloc(sizeof(struct PolyNode));
        scanf("%f %d", &q->coef, &q->expon);
        r->next = q;
        r = q;
        c = getchar();
    } while (c != '\n');
    r->next = NULL;
    return head;
}

Polynomial sort(Polynomial head)
{
    Polynomial p = head->next, q, r;
    if (p != NULL)
    {
        r = p->next;
        p->next = NULL;
        p = r;
        while (p != NULL)
        {
            r = p->next;
            q = head;
            while (q->next != NULL && q->next->expon > p->expon)
                q = q->next;
            p->next = q->next;
            q->next = p;
            p = r;
        }
    }
    return head;
}

Polynomial AddPolyn(Polynomial a, Polynomial b)
{
    Polynomial p, q, r, c, s;
    p = a->next;
    q = b->next;
    c = (Polynomial)malloc(sizeof(struct PolyNode));
    r = c;
    while (p && q)
    {
        if (p->expon < q->expon)
        {
            s = (Polynomial)malloc(sizeof(struct PolyNode));
            s->expon = q->expon;
            s->coef = q->coef;
            r->next = s;
            r = s;
            q = q->next;
        }
        else if (p->expon > q->expon)
        {
            s = (Polynomial)malloc(sizeof(struct PolyNode));
            s->expon = p->expon;
            s->coef = p->coef;
            r->next = s;
            r = s;
            p = p->next;
        }
        else
        {
            double sum = p->coef + q->coef;
            if (sum != 0)
            {
                s = (Polynomial)malloc(sizeof(struct PolyNode));
                s->coef = sum;
                s->expon = p->expon;
                r->next = s;
                r = s;
                p = p->next;
                q = q->next;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
    }
    if (p == NULL && q == NULL)
        r->next = NULL;
    if (p != NULL)
    {
        r->next = p;
    }
    if (q != NULL)
    {
        r->next = q;
    }
    return c;
}

void PrintPolyn(Polynomial pc)
{
    int n;
    Polynomial p = pc;
    scanf("%d", &n);
    while (n--)
    {
        p = p->next;
    }
    printf("%.1f %d", p->coef, p->expon);
    printf("\n");
}

int main()
{
    Polynomial pa, pb, pc, d, e;
    pa = CreatPolyn();
    pb = CreatPolyn();
    d = sort(pa);
    e = sort(pb);
    pc = AddPolyn(d, e);
    PrintPolyn(pc);
    return 0;
}
