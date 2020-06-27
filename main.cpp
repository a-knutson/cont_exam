#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <iostream>
#include <vector>
#include <map>

std::vector< std::map<long int,int> > gid2pid;

int main()
{

   gid2pid.resize( 4 ); 

   int h,i;
   int isize[4] = {12, 11, 2, 10}; // example: 12 nodes, 11 faces, 2 cells, 10 ghosts

   for (h=0; h<4; ++h) { // loop through element types (h = handle)
      for (i=0; i<isize[ h ]; ++i) {
         long int gid = 1000000000 + i; // doesn't matter, just has to be unique
         int pid = i + 1; // starts at 1
         gid2pid[ h ].insert(std::pair<long int,int>(gid,pid));
      }
   }

#ifdef _DEBUG_
   std::cout << "\n";
   for (h=0; h<4; ++h) {
      std::map<long int,int>::iterator it = gid2pid[ h ].begin();
      while (it != gid2pid[ h ].end())
      {
         std::cout << it->first << " " << it->second << "\n";
         it++;
      }
      std::cout << "\n";
   }

#endif

   // does this take significantly more time or memory
   // than indexing directly i.e. gid2pid[ 1 ]?
   //std::map<long int,int> faces = gid2pid[ 1 ];

   return 0;
}
