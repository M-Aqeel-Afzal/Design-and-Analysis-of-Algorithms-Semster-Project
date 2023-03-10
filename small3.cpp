#include<iostream>
#include<string>
#include<ctime>
#include <algorithm>
#include <chrono>
#include<vector>
#include<cstdlib>
using namespace std;
using namespace std::chrono;
float t1[5]={0,0,0,0,0};
float T1[15]={0.0};                                  //probabilty of each edge

float Page_rel_score=0.0;
int spanning_forests=0;
float weight[4]={0.0,0.0,0.0,0.0};    // page relevence score
int total[6]={0,0,0,0,0,0};     //total no. of forests
  bool visited[4]={0,0,0,0};


//small input
int sc1[8]={0,1,2,3,4,5,6,7};
string sr1[8]={"0,1","1,2","0,3","2,5","4,3","3,7","4,8"};
int const size_sp1=8;               //size of Page Query Concepts(nodes)
int const size_rp=4;                //size of page Query Relations(edges)
int const size_pw1=5;
int const size_w=8;
int sp1[size_sp1]={0,1,2,3};
string rp[size_rp]={"0,1","1,2","1,3","2,3"};


int w[8]={2,3,2,2,0,3,1,2};                                           //weights user query
int pw1[5][4]={{1,2,1,1},{0,1,1,2},{0,1,1,1},{0,3,2,1},{2,3,1,3}};                 //weights of pages
/*
//small input 
int sc1[6]={0,1,2,3,4,5};  ///QUERY INSERTED (Size 6)
string sr1[6]={"0,1","1,2","0,4","1,3","2,3"}; //RELATIONS BETWEEN QUERY
int const size_sp1=4;               //size of Page Query Concepts(nodes)
int const size_rp=4;                //size of page Query Relations(edges)
int const size_pw1=4;
int const size_w=5;
int sp1[size_sp1]={0,1,2,3};			/
string rp[size_rp]={"0,1","1,2","1,3","2,3"};		//CHANGED NO OF PAGES

//small input 2
/*
int sc1[5]={0,1,2,3,4};
string sr1[5]={"0,1","1,3","1,4","0,2"};
int const size_sp1=4;               //size of Page Query Concepts(nodes)
int const size_rp=4;                //size of page Query Relations(edges)
int const size_pw1=4;
int const size_w=5;
int sp1[size_sp1]={0,1,2,3};
string rp[size_rp]={"0,1","1,2","1,3","2,3"};


int w[5]={2,3,2,2,2};                                           //weights user query
int pw1[3][4]={{1,2,1,1},{0,1,1,2},{0,1,1,1}};                 //weights of pages
*/

//small input 3
/*int sc1[8]={0,1,2,3,4,5,6,7};
string sr1[8]={"0,1","1,2","0,3","2,5","4,3","3,7","4,8"};
int const size_sp1=4;               //size of Page Query Concepts(nodes)
int const size_rp=4;                //size of page Query Relations(edges)
int const size_pw1=5;
int const size_w=8;
int sp1[size_sp1]={0,1,2,3};
string rp[size_rp]={"0,1","1,2","1,3","2,3"};


int w[8]={2,3,2,2,0,3,1,2};                                           //weights user query
int pw1[5][4]={{1,2,1,1},{0,1,1,2},{0,1,1,1},{0,3,2,1},{2,3,1,3}};                 //weights of pages
*/



//cycle detecting

bool detectCycle(int a, int parent)
{
 
    visited[a] = true;    // Mark the current node as visited
    for (int i = 0; i <size_sp1; ++i)    // If an adjacent edge is not visited,
    {                              //then recur for that adjacent edge
         
       
        
        if (!visited[i])
        {
           if (detectCycle(i, a))
              return true;
        }
 
					// If an adjacent edge is visited and
					// is not parent of current edge,
					// then there exists a cycle in the graph.
        else if (i != parent)
           return true;

    }
    return false;
}

bool cycle(int a)                                  // Returns true if the graph consists of
{								                // a cycle, else return false.	
       
        if (!visited[a])
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
string edges[100];
//Main Ontology Knowledge Base

//Concepts(Nodes) in Main Ontology
//For example 1
int C1[50]={1,2,3,4,5,6,7,8,9,10,
           11,12,13,14,15,16,17,
           18,19,20,21,22,23,24,
	   25,26,27,28,29,30,31,
	   32,33,34,35,36,37,38,
	   39,40,41,42,43,44,45,
	   46,47,48,49,50};
//For example 2
int C2[50]={1,2,3,4,5,6,7,8,9,10,
           11,12,13,14,15,16,17,
           18,19,20,21,22,23,24,
	   25,26,27,28,29,30,31,
	   32,33,34,35,36,37,38,
	   39,40,41,42,43,44,45,
	   46,47,48,49,50};
//For example 3
int C3[50]={1,2,3,4,5,6,7,8,9,10,
           11,12,13,14,15,16,17,
           18,19,20,21,22,23,24,
	   25,26,27,28,29,30,31,
	   32,33,34,35,36,37,38,
	   39,40,41,42,43,44,45,
	   46,47,48,49,50};

//Relations(Edges) in main Ontology Knowledge Base b/w i and i concepts

//For example 1
string R1[100]={"32,46","30,47","1,40","33,22","25,9","46,7","39,32","34,49","28,4",	       		            		       "28,34","8,15","10,46","21,46","12,30","21,7","21,2","40,42","43,25",
	       "20,5","25,32","36,42","45,3","48,23","44,34","10,6","37,26","21,17",
 	       "36,10","2,31","23,6","29,43","49,37","16,36","29,30","24,41","26,27",
               "30,48","26,33","47,36","24,10","33,38","34,36","38,2","15,32","26,7",
               "43,33","37,14","47,39","19,36","21,11","28,45","31,29","21,18","47,32",
               "3,8","50,50","25,38","47,34","3,2","47,22","49,1","40,34","18,4","48,2",
	       "9,5","26,6","28,32","44,30","47,34","37,31","38,31","33,22","8,39","50,36",
               "25,44","10,22","43,1","16,44","22,41","31,27","14,16","50,48","18,5","40,6",
               "16,31","45,42","30,36","47,1","44,24","26,7","38,22","30,23","43,41","46,32",
               "33,47","16,42","21,23","27,21","26,16","19,41"};


string PR1[15]={"36,10","21,7","40,34","27,21","43,25","16,42",                 //edges for page 1
                "33,22","10,22","43,33","20,5","48,23","22,41","8,39",
                "40,6","3,2"};



//For example 2
string R2[100]={"20,7","27,1","14,50","5,7","19,45","16,43","22,36","36,37","45,48",
                "2,41","23,12","2,38","12,2","31,8","2,27","43,42","27,15","6,50",
                "27,46","2,50","42,22","40,26","40,37","41,19","49,20","1,14","47,42",
                "29,48","47,26","14,28","22,19","41,10","49,49","11,39","30,39","25,39",
                "13,38","17,16","20,15","18,28","18,49","39,41","35,40","19,2","19,31",
                "42,7","30,21","7,37","34,6","36,25","17,42","16,30","26,14","34,32",
                "32,2","19,45","47,24","13,31","45,16","41,1","17,19","43,34","7,11",
                "15,46","23,27","12,48","8,46","27,8","31,3","43,45","29,13","6,5",
                "13,14","34,28","40,50","45,13","47,23","25,49","34,31","7,23","33,3",
                "28,9","5,21","45,6","29,45","40,42","50,40","5,16","20,50","38,8","1,40",
                "29,17","9,24","4,18","28,46","49,38","37,37","45,44","3,15","42,4"};
//For example 3
string R3[100]={"38,2","50,45","45,36","13,13","50,50","19,10","7,35","12,46",
                "16,40","44,18","3,7","28,6","29,1","21,15","37,15","44,33",
                "6,41","39,5","35,20","33,13","38,17","42,46","42,24","28,44",
                "28,30","29,25","40,31","36,19","26,4","8,38","8,25","13,18",
                "25,9","39,36","17,15","12,44","43,35","14,20","40,46","36,5",
                "47,12","23,26","45,50","40,38","32,7","4,20","1,12","29,25",
                "28,16","30,4","21,50","36,24","20,18","13,9","43,41","37,44",
                "29,46","3,27","46,4","39,36","35,6","45,44","31,15","18,27",
                "42,19","25,8","24,36","39,38","28,35","32,25","42,10","2,4",
                "36,36","38,3","50,47","2,21","47,46","40,34","9,11","32,45",
                "39,36","6,39","16,25","41,14","44,15","17,16","48,14","13,4",
                "16,12","7,45","20,34","43,41","23,7","38,49","8,44","24,10",
                "10,9","44,22","11,39","40,45"};
//Sub_Relations(Edges) in main Ontology Knowledge Base b/w i and i concepts
//For example 1
string r1[100]={"1,2,3,4,5,6,7,8,9","1,2,3,4,5,6,7,8","1,2,3,4","1,2,3,4,5,6,7,8,9",
                "1,2,3,4,5,6,7","1,2,3,4,5,6,7,8,9,10","1,2,3,4","1","1,2,3,4","1,2,3,4,5,6",
		"1,2,3,4,5,6,7,8","1","1,2,3,4","1,2,3,4,5,6,7,8","1,2,3,4,5,6,7,8,9,10",
		"1,2,3,4,5","1,2,3,4,5,6,7,8","1,2,3","1,2,3,4,5","1,2,3,4,5,6,7,8",
		"1,2,3,4,5,6,7,8,9","1,2,3,4,5,6,7,8","1,2,3,4,5","1,2,3,4,5","1,2,3,4,5,6",
		"1,2,3,4,5,6,7","1,2,3,4,5,6,7","1,2,3,4,5,6,7,8,9","1,2","1",
		"1,2,3,4,5,6,7,8","1,2","1,2,3,4,5,6,7,8,9,10","1","1,2,3,4,5,6,7,8,9,10",
		"1,2,3,4,5,6,7,8","1,2","1,2,3,4,5,6","1","1,2,3,4,5","1","1,2,3,4,5,6,7,8,9,10",
		"1,2,3,4,5,6,7","1,2,3,4,5,6","1,2,3,4,5,6,7","1,2,3,4,5,6,7","1,2",
		"1,2,3,4,5,6","1,2,3,4,5,6,7,8,9","1,2,3,4,5,6,7","1,2,3,4,5,6","1,2,3,4,5,6,7,8,9,10",
		"1,2,3,4,5,6","1,2","1,2,3,4","1,2,3","1,2,3,4,5,6,7,8","1,2","1",
		"1,2,3,4,5,6,7,8,9","1,2,3,4","1,2,3,4,5,6,7,8","1,2,3,4,5,6,7,8,9,10",
		"1,2,3,4,5,6","1,2,3,4,5,6,7,8,9,10","1","1,2,3","1,2","1,2,3,4,5,6",
		"1,2,3","1,2,3,4,5,6,7,8","1,2,3,4,5,6","1,2","1,2,3,4,5","1,2,3",
		"1,2,3,4,5,6,7,8,9,10","1,2,3","1,2,3,4,5","1,2,3,4,5,6,7,8","1,2,3","1,2,3",
		"1,2,3","1,2","1,2,3,4,5,6,7,8","1,2,3,4","1,2,3,4,5,6,7,8","1,2,3","1",
		"1,2,3,4,5,6,7,8,9","1,2,3","1","1,2,3,4,5","1,2,3","1,2,3,4,5,6,7,8,9,10",
		"1,2,3,4,5,6,7,8,9,10","1,2","1,2,3,4,5,6,7,8,9,10","1,2","1,2,3,4,5","1,2,3,4,5,6,7,8"};

//For example 2
string r2[100]={"1","1","1,2,3,4,5,6,7,8","1,2,3,4,5,6,7,8,9","1,2,3,4,5,6,7,8,9,10",
		"1,2,3,4,5,6,7,8","1","1,2,3,4,5,6","1,2,3,4,5","1,2,3,4,5,6,7,8","1",
		"1","1,2,3,4,5,6,7,8","1,2,3,4","1,2,3,4,5,6","1","1,2,3,4,5,6,7",
		"1,2,3,4,5,6,7,8,9","1,2","1,2,3,4,5,6,7,8","1,2","1,2,3,4,5","1,2,3",
		"1,2,3,4,5,6,7,8,9,10","1,2,3,4,5,6,7","1,2,3,4,5,6,7","1,2,3,4,5,6,7",
		"1,2,3","1,2","1,2","1,2,3,4,5,6,7,8,9","1,2","1,2,3,4","1,2,3,4,5,6,7,8",
		"1,2","1,2,3,4,5","1,2,3,4,5,6,7,8","1,2","1,2,3,4,5,6,7,8,9,10","1,2",
		"1","1,2","1,2,3,4,5","1,2,3,4,5,6,7,8","1,2,3,4,5,6,7","1,2,3,4,5,6,7,8,9,10",
		"1","1,2,3","1,2,3,4,5,6,7,8,9,10","1,2,3,4","1,2,3","1,2,3","1,2,3,4,5,6,7,8",
		"1,2,3,4,5,6,7","1,2,3","1,2,3,4,5,6,7","1,2,3","1,2,3,4,5,6,7,8,9","1,2,3,4,5,6,7,8,9",
		"1,2,3,4","1,2","1,2,3,4,5,6,7,8,9","1,2,3,4,5,6,7","1,2,3,4,5","1,2,3,4,5,6",
		"1,2,3,4,5,6,7,8,9","1,2,3,4,5,6,7,8,9","1,2,3","1,2","1","1,2,3,4,5,6,7","1,2,3,4,5",
		"1,2,3,4","1","1,2,3,4","1","1,2","1,2,3,4","1,2,3,4,5","1,2,3","1,2,3,4,5,6,7,8",
		"1,2,3,4,5,6,7","1,2,3,4,5,6","1,2,3,4,5,6,7","1,2,3","1,2,3,4,5,6,7,8","1,2,3,4,5",
		"1,2,3,4,5,6,7,8","1,2,3,4,5,6,7,8","1,2,3,4,5","1","1","1,2,3","1,2,3,4,5,6,7,8,9,10",
		"1,2,3,4,5,6,7","1,2,3,4,5,6,7,8,9","1,2,3,4,5,6,7,8,9,10","1,2,3,4,5","1","1,2,3"};

string r3[100]={"1","1,2","1,2,3,4,5,6,7,8,9","1,2,3","1","1,2","1,2,3,4,5",
		"1,2,3,4,5,6,7","1,2,3,4,5,6","1,2,3,4,5,6","1,2,3,4,5,6,7,8,9,10",
		"1,2","1,2,3,4,5,6,7,8,9","1,2,3,4,5,6,7,8","1,2,3","1,2,3,4",
		"1,2,3,4,5,6,7,8","1,2,3,4,5,6,7,8","1,2,3,4,5,6,7","1,2,3,4,5,6,7,8",
		"1,2,3","1,2","1,2","1,2,3,4,5,6,7,8,9,10","1,2,3,4,5,6,7,8,9",
		"1,2,3,4,5,6,7,8,9","1,2,3,4,5,6","1,2,3,4,5,6,7,8","1,2,3,4,5,6,7,8,9",
		"1,2,3","1,2,3,4,5,6,7,8,9,10","1,2,3,4,5,6,7,8,9","1,2,3,4,5,6,7",
		"1,2,3,4,5,6,7,8","1,2","1,2,3,4,5,6,7","1,2","1,2,3,4,5,6","1,2,3",
		"1,2,3,4,5,6,7","1,2,3,4","1,2,3","1,2,3,4,5,6,7,8,9,10","1,2","1,2",
		"1,2","1,2,3,4,5,6,7","1","1,2","1,2,3,4","1,2,3,4,5,6,7,8,9","1,2,3,4",
		"1,2,3,4,5,6,7","1,2,3,4,5,6,7,8,9,10","1,2,3,4,5","1,2,3,4,5,6",
		"1,2,3,4,5,6,7,8,9,10","1,2,3,4,5,6,7,8,9,10","1,2,3,4,5","1,2,3,4,5,6,7,8",
		"1,2,3,4,5","1,2,3,4","1,2,3,4,5,6,7","1","1,2,3","1,2,3,4,5,6,7,8",
		"1,2,3,4,5,6,7,8,9","1,2,3,4,5,6","1,2,3,4,5","1,2,3,4","1,2,3",
		"1,2,3,4,5,6,7,8","1,2,3,4,5,6,7,8","1,2,3,4","1,2,3,4,5,6,7,8,9",
		"1,2,3,4,5,6,7,8,9","1,2,3,4,5,6","1,2,3,4,5,6,7,8","1,2,3,4,5,6,7,8,9,10",
		"1,2,3,4,5,6,7,8,9","1,2,3","1,2,3,4,5,6,7,8,9,10","1,2,3,4","1,2,3,4,5,6,7,8,9",
		"1,2,3,4,5,6,7,8,9","1,2,3,4,5,6,7,8,9","1,2,3,4","1","1,2,3,4,5,6,7,8",
		"1,2,3,4,5,6,7,8,9,10","1,2,3,4,5,6,7,8","1,2,3,4","1,2,3,4,5","1,2,3,4,5,6",
		"1,2,3,4,5,6","1,2,3,4,5,6,7,8","1,2,3,4,5","1,2,3,4,5","1,2,3","1,2,3,4,5,6,7,8,9,10"};

cout<<endl;

int n1[100]={9,8,4,9,7,10,4,1,4,6,8,1,4,8,10,5,8,3,5,8,9,8,5,5,6,7,7,9,2,      //weights for C1    
	     1,8,2,10,1,10,8,2,6,1,5,1,10,7,6,7,7,2,6,9,7,6,10,6,2,4,3,8,
	     2,1,9,4,8,10,6,10,1,3,2,6,3,8,6,2,5,3,10,3,5,8,3,3,3,2,8,4,8,
	     3,1,9,3,1,5,3,10,10,2,10,2,5,8};

int n2[100]={1,1,8,9,10,8,1,6,5,8,1,1,8,4,6,1,7,9,2,8,2,5,3,10,                 //weights for C2
	     7,7,7,3,2,2,9,2,4,8,2,5,8,2,10,2,1,2,5,8,7,10,1,3,
	     10,4,3,3,8,7,3,7,3,9,9,4,2,9,7,5,6,9,9,3,2,1,7,5,4,
	     1,4,1,2,4,5,3,8,7,6,7,3,8,5,8,8,5,1,1,3,10,7,9,10,5,
             1,3};

int n3[100]={1,2,9,3,1,2,5,7,6,6,10,2,9,8,3,4,8,8,7,                            //weights for C3
	     8,3,2,2,10,9,9,6,8,9,3,10,9,7,8,2,7,2,6,
	     3,7,4,3,10,2,2,2,7,1,2,4,9,4,7,10,5,6,10,
	     10,5,8,5,4,7,1,3,8,9,6,5,4,3,8,8,4,9,9,6,
	     8,10,9,3,10,4,9,9,9,4,1,8,10,8,4,5,6,6,8,
	     5,5,3,10};



int p1[10]={1,2,3,4,5,6,7,8,9,10};



int rp1[15]={3,4,1,3,2,5,3,1,1,4,2,3,2,3,4};                                   //weights of edges for page 1


/*<=============================> Algorithm Implementation <==================================>
 * take each node as root of page query graph
 * find page relevence score of the given page
 * find total spanning forest of the given page
 *<=============================>***********************<=====================================>    */  


                                         //execution time calculation start
 vector<int> values(10000);
  
    // Generate Random values
    auto f = []() -> int { return rand() % 10000; };
  
    // Fill up the vector
    generate(values.begin(), values.end(), f);
  
    // Get starting timepoint
    auto start = high_resolution_clock::now();





                                                                                       
for(int m=0;m<5;m++)
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
for(int i=0;i<5;i++)                                    //printing value for relational probality(Tij)
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
for(int i=0;i<size_rp;i++)            // printing all possible spanning forests of variable length
{
cout<<"Length "<<i+1<<":  "<<total[i]<<endl;
if(spanning_forests<total[i])
spanning_forests=total[i];
}
cout<<"page relevence score OF Given Page:"<<Page_rel_score<<endl;
cout<<"Total Spanning Forests Of Given Page :"<<spanning_forests<<endl;


for(int i=0;i<6;i++)                              //setting intial values of arrays
{weight[i]=0.0;
total[i]=0;
t1[i]=0;
visited[i]=0;
}
Page_rel_score=0;
cout<<"\n\n";
}



sort(values.begin(), values.end());
  
    // Get ending timepoint
    auto stop = high_resolution_clock::now();                                //execution time calculation end
  
    // Get duration. Substart timepoints to 
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;



return 0;
}

























