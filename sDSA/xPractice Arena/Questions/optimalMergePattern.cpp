/* Question : helloWorld

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
   int nFiles;
   if (!(cin >> nFiles))
   {
      cout << "Enter Numerric";
      return 404;
   }

   priority_queue<int, vector<int>, greater<int>> pq;
   for (int i = 0; i < nFiles; i++)
   {
      int fileData;
      if (cin >> fileData)
      {
         pq.push(fileData);
      }
      else
      {
         cout << "some wong value";
         return 404;
      }
   }

   if (pq.size() < 2)
   {
      cout << 0;
      return 0;
   }

   long long totalCost = 0;
   int nMerging = 0;
   while (pq.size() > 1)
   {
      int file1 = pq.top();
      pq.pop();
      int file2 = pq.top();
      pq.pop();

      int resultTwoFiles = file1 + file2;
      pq.push(resultTwoFiles);

      nMerging++;
      totalCost += resultTwoFiles;
   }

   cout << totalCost;
   return 0;
}
