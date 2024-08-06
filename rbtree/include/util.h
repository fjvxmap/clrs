enum { RED, BLACK };

typedef struct node {
  int key;
  int color;
  struct node *left, *right, *parent;
} Node;

int getHeight(Node *node);

int getBalanceFactor(Node *node);

void compareBalanceFactor(Node **rbRoot, Node **bstRoot);
