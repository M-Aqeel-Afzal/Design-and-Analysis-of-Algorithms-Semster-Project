#include<iostream>
#include<string>
#include<ctime>
#include <algorithm>
#include <chrono>
#include<vector>
#include<cstdlib>
using namespace std;
using namespace std::chrono;

//float T1[15]={0.0};                                  //probabilty of each edge

float Page_rel_score=0.0;
int spanning_forests=0;
float weight[5]={0.0,0.0,0.0,0.0,0.0};    // page relevence score
int total[5]={0,0,0,0,0};     //total no. of forests
  bool visited[5]={0,0,0,0,0};



//small input

int sc1[7]={0,1,2,3,4,5,6};
string sr1[6]={"0,1","1,2","0,4","1,3","2,3","1,6"};

int w[6]={2,3,2,2,2,2};        
                                                            //weights user query

int const size_sp1=5;               //size of Page Query Concepts(nodes)
int const size_rp=5;                //size of page Query Relations(edges)

int const size_pw1=5;               //size of set of all concepts(nodes) of each page
int const size_w=5;                 //size of set of all relations (edges) of each page

int sp1[size_sp1]={0,1,2,3,4};            //set page concepts(nodes)
string rp[size_rp]={"0,1","1,2","1,3","2,3","0,4"};  //set of page relations(edges)



int pw1[3][5]={{1,2,1,1,1},{0,1,1,2,1},{0,1,1,1,0}};                 //weights of pages

float t1[size_rp+1]={0,0,0,0,0,0};                             //array to store revence socre of each edge of page



//cycle detecting

bool detectCycle(int a, int p)
{
 
    visited[a] = true;    // Mark the current node as visited
    for (int i = 0; i <size_sp1; ++i)    
    {                             
         
       
        
        if (!visited[i])           // If an adjacent edge is not visited,
        {                            //then recur for that adjacent edge
           if (detectCycle(i, a))
              return true;             //means cycle
        }
 
					// If an adjacent edge is visited and
					// is not parent of current edge,
					// then there exists a cycle in the graph.
        else if (i != p)
           return true;

    }
    return false;
}
 

bool cycle(int a)                                  // Returns true if the graph consists of
                                                   // a cycle, else return false.
{
    
   
        if (!visited[a])                          // If an adjacent edge is not visited,
          if (detectCycle(a,-1))
             return true;
 
    return false;
}




int a=0;


void visit(int o,int e,int l,float s)                   //Visit Function   for finding Page relevence score of the given Page
{                                                       //and Total spanning Forests of the given Page

a=e+1;
while(a<=size_rp-1&&l<=size_sp1-1)                                       //here 14 is size(RP1 -1)  and 9 is size(CP1-1)
{


	//IF a is not visited and a is safe(means NO cycle)
	//removing cycle through DFS Technique

	if(!cycle(a))       
	{
		visited[a]=true;                                       //mark a as visited
		cout<<"------------->no cycle detected "<<endl;
		visit(o,a,l+1,s*t1[a]);
		weight[l+1]+=s;
		total[l+1]+=1;
		visited[a]=false;                                     //mark a is not visited
		
	}
	else                                                    //else means there is a cycle
	{
		cout<<"cycle detected "<<a<<endl;
		a++;                                            //just incrementing a
	}
}
}
int main()
{

srand(time(0));




/*<=============================> Algorithm Implementation <==================================>
 * take each node as root of page query graph
 * find page relevence score of the given page
 * find total spanning forest of the given page
 *<=============================>***********************<=====================================>    */  


                                         //execution time calculation start
 vector<int> val(10000);
  
    // Generate Random values form rad function
    auto z = []() -> int { return rand() % 10000; };
  
    // Fill up the vector
    generate(val.begin(), val.end(), z);
  
    // Get starting timepoint
    auto st = high_resolution_clock::now();





                                                                                       
for(int m=0;m<3;m++)
{
int k=0;
cout<<"<==================> Page: "<<m+1<<" <==================>\n"<<endl;
for(int i=0;i<size_w;i++)                                    //finding value for relational probality(Tij)
{
for(int j=0;j<size_pw1;j++)
	{if(sr1[i]==rp[j])
	{
	cout<<"match---->"<<w[i]<<"    "<<pw1[m][j]<<"    "<<sr1[i]<<"  i="<<i<<endl;
	   t1[k]=(float)pw1[m][j]/w[i];
	k++;
	break;
	}
      }
}

cout<<"\n\nRelational probability "<<endl;
for(int i=0;i<6;i++)                                    //printing value for relational probality(Tij)
{
cout<<t1[i]<<endl;
}




for(int e=0;e<size_rp;e++)    //loop iterating all the edges of Page Query Graph                                       
{
visited[e]=true;
visit(e,e,0,t1[e]);
weight[e]+=t1[e];
total[e]+=1;

}

cout<<"\n\nweights"<<endl;
for(int i=0;i<size_rp;i++)          //printing page relevence score
{
cout<<weight[i]<<endl;
Page_rel_score+=weight[i];
}

cout<<"\n\nspanning Forests"<<endl;
for(int i=1;i<size_rp;i++)            // printing all possible spanning forests of variable length
{
cout<<"Length "<<i<<":  "<<total[i]<<endl;
if(spanning_forests<total[i])
spanning_forests=total[i];
}
cout<<"page relevence score OF Given Page:"<<Page_rel_score<<endl;
cout<<"Total Spanning Forests Of Given Page :"<<spanning_forests<<endl;


for(int i=0;i<6;i++)                              //setting intial values of arrays
{weight[i]=0.0;
total[0]=0;
t1[i]=0;
visited[i]=0;
}
Page_rel_score=0;
cout<<"\n\n";
}


//calulating Execution time
sort(val.begin(), val.end());
  
    
    auto stp = high_resolution_clock::now();                                
  
    auto dur = duration_cast<microseconds>(stp - st);
  
    cout << "Time taken by function: "
         << dur.count() << " (microseconds)" << endl;



return 0;
}



