#ifndef FLAT_H
#define FLAT_H

struct Node
{
    int bandwidth;
    int flat_id;
    struct Node *next;
    struct Node *prev;
};

class Flat
{
public:
    Flat();

    Flat(int n);

    ~Flat();
};

void push_at(struct Node **head, int position, int bandwidth, int flat_id);
struct Node *traverseFlatList(struct Node *node, int key);
int getFlatPos(struct Node *node, int key);
void makeFlatEmpty(struct Node *node, int key);
struct Node *combine(struct Node *first, struct Node *second);
void deleteNode(Node **head, Node *del);
void displayList(struct Node *node);

#endif