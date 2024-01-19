#include <iostream>

using namespace std;

#include "apartment.h"
#include "flat.h"

struct ApartmentNode *insertInEmpty(struct ApartmentNode *last, int new_max_bandwidth, string new_name)
{
   if (last != NULL)
      return last;

   struct ApartmentNode *temp = new ApartmentNode;

   temp->max_bandwidth = new_max_bandwidth;
   temp->current_bandwidth = 0;
   temp->flatList = NULL;
   temp->name = new_name;
   last = temp;

   last->next = last;

   return last;
}

struct ApartmentNode *insertAfter(struct ApartmentNode *last, string after_item, string new_name, int new_max_bandwidth)
{
   if (last == NULL)
      return NULL;

   struct ApartmentNode *temp, *p;
   p = last->next;
   do
   {
      if ((p->name).compare(after_item) == 0)
      {
         temp = new ApartmentNode;
         temp->max_bandwidth = new_max_bandwidth;
         temp->current_bandwidth = 0;
         temp->flatList = NULL;

         temp->name = new_name;
         temp->next = p->next;
         p->next = temp;

         if (p == last)
            last = temp;
         return last;
      }
      p = p->next;
   } while (p != last->next);

   return last;
}

struct ApartmentNode *insertPos(struct ApartmentNode *last, int pos, string new_name, int new_max_bandwidth)
{

   if (last == NULL)
      return NULL;

   struct ApartmentNode *temp, *p;
   p = last->next;

   while (pos--)
   {
      /* code */

      if (pos == 0)
      {
         temp = new ApartmentNode;
         temp->max_bandwidth = new_max_bandwidth;
         temp->flatList = NULL;

         temp->current_bandwidth = 0;
         temp->name = new_name;
         temp->next = p->next;
         p->next = temp;

         if (p == last)
            last = temp;
         return last;
      }
      p = p->next;
   }
   return last;
}

struct ApartmentNode *insertBefore(struct ApartmentNode *last, string before_item, string new_name, int new_max_bandwidth)
{
   if (last == NULL)
      return NULL;

   struct ApartmentNode *temp, *p;
   p = last->next;

   if ((p->name).compare(before_item) == 0)
   {

      temp = new ApartmentNode;

      temp->max_bandwidth = new_max_bandwidth;
      temp->flatList = NULL;

      temp->current_bandwidth = 0;
      temp->name = new_name;

      temp->next = last->next;
      last->next = temp;

      return last;
   }

   else
   {
      int count = 0;

      do
      {
         if ((p->name).compare(before_item) == 0)
            break;
         count++;
         p = p->next;
      } while (p != last->next);

      last = insertPos(last, count, new_name, new_max_bandwidth);
   }

   return last;
}

struct ApartmentNode *getApartment(struct ApartmentNode *last, string item)
{

   if (last == NULL)
      return NULL;

   struct ApartmentNode *temp, *p;
   p = last->next;

   int count = 0;

   do
   {
      if ((p->name).compare(item) == 0)
         break;
      p = p->next;
   } while (p != last->next);

   return p;
}

void traverseList(struct ApartmentNode *last)
{
   struct ApartmentNode *p;

   if (last == NULL)
   {
      return;
   }
   p = last->next;

   do
   {
      cout << p->name << "(" << p->max_bandwidth << ")"
           << "\t";
      displayList(p->flatList);
      p = p->next;
   } while (p != last->next);
   cout << "\n";
}

int findSumMaxBandwidth(struct ApartmentNode *last)
{
   struct ApartmentNode *p;

   int bandwidth = 0;
   p = last->next;

   do
   {
      bandwidth = bandwidth + p->max_bandwidth;
      p = p->next;
   } while (p != last->next);

   return bandwidth;
}

void traverseApartandFlat(struct ApartmentNode *last, int key)
{
   struct ApartmentNode *p;
   struct Node *temp_Flat = NULL;

   p = last->next;

   do
   {
      temp_Flat = traverseFlatList(p->flatList, key);
      if (temp_Flat != NULL)
      {
         deleteNode(&p->flatList, temp_Flat);
      }

      p = p->next;
   } while (p != last->next);
}

int getFlatBandwitdh(struct ApartmentNode *last, int key)
{
   struct ApartmentNode *p;
   struct Node *temp_Flat = NULL;

   p = last->next;

   do
   {
      temp_Flat = traverseFlatList(p->flatList, key);
      if (temp_Flat != NULL)
      {
         return temp_Flat->bandwidth;
      }

      p = p->next;
   } while (p != last->next);

   return -1;
}
struct ApartmentNode *deleteApartmentNode(ApartmentNode *head, string key)
{
   if (head == NULL)
      return NULL;

   if ((head)->name.compare(key) == 0 && (head)->next == head)
   {
      head = NULL;
      return NULL;
   }
   ApartmentNode *last = head, *d;

   if ((head)->name.compare(key) == 0)
   {
      while (last->next != head)
         last = last->next;

      last->next = (head)->next;

      return head;
   }

   while (last->next != head && last->next->name.compare(key) != 0)
   {
      last = last->next;
   }

   if (last->next->name.compare(key) == 0)
   {
      d = last->next;
      last->next = d->next;
   }

   return head;
}