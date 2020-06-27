#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <map>

std::vector< std::map<long int,int> > gid2pid;

int main()
{

   gid2pid.resize( 4 ); // 4 element types 

   int h,i;

   // example: 12 nodes, 11 faces, 2 cells, 10 ghosts
   int isize[4] = {12, 11, 2, 10};

   for (h=0; h<4; ++h) { // loop through element types (h = handle)
      for (i=0; i<isize[ h ]; ++i) {
         long int gid = 10000000010 + 2345678900*(i+1);
         int pid = i + 1; // start at 1
         gid2pid[ h ].insert(std::pair<long int,int>(gid,pid));
      }
   }

   // print out face GID->PID map
   std::map<long int,int> faces = gid2pid[ 1 ];
   std::cout << "faces GID->PID\n";
   std::map<long int,int>::iterator it = faces.begin();
   while (it != faces.end())
   {
      std::cout << it->first << " | " << it->second << "\n";
      it++;
   }
   faces.clear();

#ifdef _DEBUG_
   std::cout << "\n";
   for (h=0; h<4; ++h) {
      std::map<long int,int>::iterator it = gid2pid[ h ].begin();
      while (it != gid2pid[ h ].end())
      {
         std::cout << it->first << " | " << it->second << "\n";
         it++;
      }
      std::cout << "\n";
   }
#endif

   gid2pid.clear();

   return 0;
}
