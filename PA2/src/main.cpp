#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "flat.h"
#include "apartment.h"

int main(int argc, char** argv)
{

   std::ofstream out(argv[2]);
   std::streambuf *coutbuf = std::cout.rdbuf(); 
   std::cout.rdbuf(out.rdbuf());


   struct ApartmentNode *Head = NULL;
   struct ApartmentNode *temp_Apartment = NULL;
   struct ApartmentNode *temp_Apartment_Second = NULL;

   std::ifstream file(argv[1]);
   std::vector<std::string> tokens;
   std::vector<std::string> flatTokens;

   if (file.is_open())
   {
      std::string line;
      while (std::getline(file, line))
      {

         std::istringstream iss(line);
         std::string token;

         while (std::getline(iss, token, '\t'))
            tokens.push_back(token);

         string command = tokens[0];

         if ((command).compare("add_apartment") == 0)
         {
            string position = tokens[2];

            if (position.compare("head") == 0)
            {
               int bandwidth = stoi(tokens[3]);
               Head = insertInEmpty(Head, bandwidth, tokens[1]);
            }
            if (position.find("after") != std::string::npos)
            {
               char temp = position.back();
               string temp_apt(1, temp);
               int bandwidth = stoi(tokens[3]);
               Head = insertAfter(Head, temp_apt, tokens[1], bandwidth);
            }
            if (position.find("before") != std::string::npos)
            {
               char temp = position.back();
               string temp_apt(1, temp);
               int bandwidth = stoi(tokens[3]);
               Head = insertBefore(Head, temp_apt, tokens[1], bandwidth);
            }
         }
         if ((command).compare("add_flat") == 0)
         {
            string apartment = tokens[1];
            int index = stoi(tokens[2]);
            int bandwidth = stoi(tokens[3]);
            int flat_id = stoi(tokens[4]);
            temp_Apartment = getApartment(Head, apartment);
            int difference_bandwidth = temp_Apartment->max_bandwidth - temp_Apartment->current_bandwidth;

            if (bandwidth >= difference_bandwidth)
               bandwidth = difference_bandwidth;

            temp_Apartment->current_bandwidth = temp_Apartment->current_bandwidth + bandwidth;
            push_at(&temp_Apartment->flatList, index + 1, bandwidth, flat_id);
         }
         if ((command).compare("remove_apartment") == 0)
         {
            string apartment = tokens[1];
            Head = deleteApartmentNode(Head, apartment);
         }
         if ((command).compare("merge_two_apartments") == 0)
         {
            string apartment_first = tokens[1];
            string apartment_second = tokens[2];
            temp_Apartment = getApartment(Head, apartment_first);
            temp_Apartment_Second = getApartment(Head, apartment_second);
            temp_Apartment->flatList = combine(temp_Apartment->flatList, temp_Apartment_Second->flatList);
            temp_Apartment->max_bandwidth = temp_Apartment->max_bandwidth + temp_Apartment_Second->max_bandwidth;
            Head = deleteApartmentNode(Head, apartment_second);
         }
         if ((command).compare("list_apartments") == 0)
         {
            traverseList(Head);
         }
         if ((command).compare("make_flat_empty") == 0)
         {
            string apartment_first = tokens[1];
            int dest_flat = stoi(tokens[2]);
            temp_Apartment = getApartment(Head, apartment_first);
            makeFlatEmpty(temp_Apartment->flatList, dest_flat);
         }
         if ((command).compare("find_sum_of_max_bandwidths") == 0)
         {
            cout << "sum of bandwidth: " << findSumMaxBandwidth(Head) << endl;
            cout << "\n";
         }
         if ((command).compare("relocate_flats_to_same_apartment") == 0)
         {
            string apartment = tokens[1];
            int dest_flat = stoi(tokens[2]);

            temp_Apartment = getApartment(Head, apartment);

            int pos = getFlatPos(temp_Apartment->flatList, dest_flat);

            string flats = tokens[3];
            flats.erase(0, 1);
            flats.erase(flats.size() - 1);

            std::vector<int> vect;

            std::stringstream ss(flats);

            for (int i; ss >> i;)
            {
               vect.push_back(i);
               if (ss.peek() == ',')
                  ss.ignore();
            }
            std::reverse(vect.begin(), vect.end());

            for (std::size_t i = 0; i < vect.size(); i++)
            {
               int bandwitdh = getFlatBandwitdh(Head, vect[i]);
               traverseApartandFlat(Head, vect[i]);
               push_at(&temp_Apartment->flatList, pos + 1, bandwitdh, vect[i]);
               temp_Apartment->max_bandwidth = temp_Apartment->max_bandwidth + bandwitdh;
            }
         }

         tokens.clear();
      }
      file.close();
   }
   return 0;
}