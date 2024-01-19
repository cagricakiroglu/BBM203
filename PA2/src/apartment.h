#ifndef APARTMENT_H
#define APARTMENT_H

#include "flat.h"

struct ApartmentNode
{
   string name;
   int max_bandwidth;
   int current_bandwidth;
   Node *flatList;
   struct ApartmentNode *next;
};

class Apartment
{
public:
   Apartment();

   Apartment(int n);

   ~Apartment();
};

struct ApartmentNode *insertInEmpty(struct ApartmentNode *last, int new_max_bandwidth, string new_name);
struct ApartmentNode *insertAfter(struct ApartmentNode *last, string after_item, string new_name, int new_max_bandwidth);
struct ApartmentNode *insertPos(struct ApartmentNode *last, int pos, string new_name, int new_max_bandwidth);
struct ApartmentNode *insertBefore(struct ApartmentNode *last, string before_item, string new_name, int new_max_bandwidth);
struct ApartmentNode *getApartment(struct ApartmentNode *last, string item);
int findSumMaxBandwidth(struct ApartmentNode *last);
void traverseList(struct ApartmentNode *last);
void traverseApartandFlat(struct ApartmentNode *last, int key);
int getFlatBandwitdh(struct ApartmentNode *last, int key);
struct ApartmentNode *deleteApartmentNode(ApartmentNode *head, string key);

#endif