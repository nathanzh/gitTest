#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <stdexcept> // for runtime_error
#include <cstdlib>
#include <memory>
using namespace std;
void runQueries(ifstream &infile)
{
     // infile is an ifstream that is the file we want to query
     TextQuery tq(infile); // store the file and build the query map
     // iterate with the user: prompt for a word to find and print results
     while (true)
     {
          cout << "enter word to look for, or q to quit: ";
          string s;
          // stop if we hit end-of-file on the input or if a 'q' is entered
          if (!(cin >> s) || s == "q")
               break;
          // run the query and print the results
          print(cout, tq.query(s)) << endl;
     }

     int main()
     {
          int n = 10;
          allocator<string> alloc;
          auto const p = alloc.allocate(n);
          // // cout << *p << endl;  this will cause unknow problem
          // cout <<"p addr:   --> " <<p << endl;
          auto q = p;
          // cout << *p << endl; // this will cause unknow problem
          //alloc.construct(p,"hi");
          alloc.construct(q++);
          // cout << *q << endl;
          alloc.construct(q++, "q++ add value1");
          // cout << *q << endl;
          alloc.construct(q++, "q++ add value2");
          // cout << *p << endl;
          while (q != p)
          {
               cout << *(--q) << endl;
               alloc.destroy(q);
          }
          // alloc.construct(q++,2,'c');
          // alloc.construct(q++,10,'b');

          // cout << *(q++)<<endl;
          // shared_ptr<string> p;
          // if (p-> empty( ))
          // *p = "hi";
          // else
          // cout<<"p is not empty     "<<*p<<endl;

          // shared_ptr<int> p (new int(42));
          // p.reset(new int(1024));
          // cout <<*p << endl;
          // if(!p.unique())
          // //cout << "p is not unique";
          // p.reset (new string (*p));
          // // p.reset (new string(*p));

          //     cout << "p is unique";

          // p.reset (new string (*p));
          //*p = {'x'};
          // const int i=42;

          // typedef string::size_type sz;
          // sz wd = 80;
          // char def = ' ';
          // string screen (sz ht =24, sz wid = 80, char = def);

          // void f2 (){
          // def = '+';

          // }
          system("pause");
          return 0;
     }