#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

vector <vector <int> > adjlist;
vector <bool> isvisited;
queue <int> bfsqueue;
int reachable = 0;

int main() {
    int ncomputers, nqueries;
    vector <int> distance;

    cin >> ncomputers >> nqueries;

    adjlist.resize(ncomputers + 5);
    isvisited.resize(ncomputers + 5, false);
    distance.resize(ncomputers + 5, 100000000);

    for(int i = 0; i != nqueries; ++i)
    {
        int ntype;

        cin >> ntype;

        if(ntype == 1)
        {
            int A, B;

            cin >> A >> B;

            adjlist[A].push_back(B);
            adjlist[B].push_back(A);
        }
        else if(ntype == 2)
        {
            int s = 1;
            bfsqueue.push(s);
            isvisited[s] = true;

            while(!bfsqueue.empty()) 
            {
                int A = bfsqueue.front();
                bfsqueue.pop();
                for(auto it = adjlist[A].begin(); it != adjlist[A].end(); ++it) 
                {    
                    if(*it == ncomputers)
                    {
                        reachable = 1;
                        break;
                    }
                    if(!isvisited[*it]) 
                    {
                        bfsqueue.push(*it);
                        isvisited[*it] = true;
                    }
                }
            }
            isvisited.assign(isvisited.size(), false);
            if(reachable == 1)
                cout << "CONNECTED" << endl;
            else 
                cout << "NOT CONNECTED" << endl;
        }
        else if(ntype == 3)
        {
            int s = 1;
            bfsqueue.push(s);
            isvisited[s] = true;
            distance[s] = -1;
            while(!bfsqueue.empty()) 
            {
                int A = bfsqueue.front();
                bfsqueue.pop();
                for(auto it = adjlist[A].begin(); it != adjlist[A].end(); ++it) 
                {    
                    if((*it == ncomputers) && (!isvisited[*it]))
                    {
                        distance[*it] = distance[A] + 1;
                        isvisited[*it] = true;
                        reachable = 1;
                        break;
                    }
                    if(!isvisited[*it]) 
                    {
                        bfsqueue.push(*it);
                        isvisited[*it] = true;
                        distance[*it] = distance[A] + 1;
                    }
                }  
            }                
            isvisited.assign(isvisited.size(), false);
            if(reachable != 1)
                cout << "INFINITY" << endl;
            else
            {  
                cout << distance[ncomputers] << endl;
            }            
        }
        else
            return 0;    
    }


}
