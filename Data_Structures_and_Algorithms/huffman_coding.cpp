#include <iostream>
#include <cstring>
#include <cstdlib>
#define MAX 100
using namespace std;

typedef struct {
    int weigth;
    int parent;
    int rchild;
    int lchild;
} HTNode, *HuffmanTree;

static char N[MAX];

typedef char **HuffmanCode;

typedef struct {
    int s1;
    int s2;
} MinCode;

MinCode Select(HuffmanTree HT, int n);

HuffmanCode HuffmanCoding(HuffmanTree HT, HuffmanCode HC, int *w, int n) {
    int i, s1 = 0, s2 = 0;
    HuffmanTree p;
    char *cd;
    int f, c, start, m;
    MinCode min;

    m = 2 * n - 1;

    HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));

    for (p = HT, i = 0; i <= n; i++, p++, w++) {
        p->weigth = *w;
        p->parent = 0;
        p->rchild = 0;
        p->lchild = 0;
    }

    for (; i <= m; i++, p++) {
        p->weigth = 0;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    }

    for (i = n + 1; i <= m; i++) {
        min = Select(HT, i - 1);
        s1 = min.s1;
        s2 = min.s2;

        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weigth = HT[s1].weigth + HT[s2].weigth; // Merge weights
    }

    cout << "Huffman Tree List:" << endl;
    cout << "Serial Number\tWeight\tParent Node\tLeft Child\tRight Child" << endl;
    for (i = 1; i <= m; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", i, HT[i].weigth, HT[i].parent, HT[i].lchild, HT[i].rchild);

    HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
    cd = (char *)malloc(n * sizeof(char));
    cd[n - 1] = '\0';

    for (i = 1; i <= n; i++) {
        start = n - 1;

        for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent) {
            if (HT[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }

        HC[i] = (char *)malloc((n - start) * sizeof(char));
        strcpy(HC[i], &cd[start]);
    }
    free(cd);
    return HC;
}

// Function to select the two smallest nodes
MinCode Select(HuffmanTree HT, int n) {
    int min, secmin;
    int i, s1, s2;
    MinCode code;
    s1 = 1;
    s2 = 1;
    min = 0x3f3f3f3f;
    for (i = 1; i <= n; i++) {
        if (HT[i].weigth < min && HT[i].parent == 0) {
            min = HT[i].weigth;
            s1 = i;
        }
    }
    secmin = 0x3f3f3f3f;
    for (i = 1; i <= n; i++) {
        if ((HT[i].weigth < secmin) && (i != s1) && HT[i].parent == 0) {
            secmin = HT[i].weigth;
            s2 = i;
        }
    }
    code.s1 = s1;
    code.s2 = s2;
    return code;
}

int main() {
    HuffmanTree HT = NULL;
    HuffmanCode HC = NULL;
    int *w = NULL;
    int i, n;

    cout << "Please enter the string to be encoded: ";
    cin.getline(N, MAX);
    n = strlen(N);
    w = (int *)malloc((n + 1) * sizeof(int));
    w[0] = 0;

    cout << "Please enter the weights in sequence:" << endl;
    for (i = 1; i <= n; i++) {
        printf("w[%d]=", i);
        cin >> w[i];
    }

    HC = HuffmanCoding(HT, HC, w, n);

    cout << "Huffman Codes:" << endl;
    cout << "Character\tWeight\tCode" << endl;
    for (i = 1; i <= n; i++)
        cout << N[i - 1] << "\t" << w[i] << "\t" << HC[i] << endl;

    cout << "Huffman Codes (only codes):" << endl;
    for (i = 1; i <= n; i++)
        printf("%s\t", HC[i]);
    cout << endl;

    return 0;
}
    