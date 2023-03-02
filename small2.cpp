#include<iostream>
#include<string>
#include<ctime>
#include <algorithm>
#include <chrono>
#include<vector>
#include<cstdlib>
using namespace std;
using namespace std::chrono;

	float Page_rel_score=0.0;
	int spanning_forests=0;
	float weight[6]={0.0,0.0,0.0,0.0,0.0,0.0};    // page relevence score
	int total[6]={0,0,0,0,0,0};     //total no. of forests
	bool visited[5]={0,0,0,0,0};



	//small input
	int sc1[8]={0,1,2,3,4,5,6,7};					//user query nodes
	string sr1[8]={"0,3","0,1","6,8","4,5","2,7","2,4","4,7"};	//edges of query node
	int w[6]={2,3,2,2,2,3};                  	                //weights user query

	int const size_sp1=6;               //size of Page Query Concepts(nodes)
	int const size_rp=6;                //size of page Query Relations(edges)
	int const size_pw1=6;		    //Size page edges

	int const size_w=7;		    //Size of user query Edges.
	int sp1[size_sp1]={0,1,2,3,4,5};				//Pages nodes
	string rp[size_rp]={"0,1","1,2","1,3","2,3","4,5","3,5"};	//Pages edges
	int pw1[3][6]={{1,2,1,1,2,1},{0,1,1,2,2,1},{0,1,1,1,0,1}};	//weights of pages
	
	float t1[6]={0,0,0,0,0,0};	//Relational Probability.


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
		                                           // a cycle, else return false.
	{
	    
	   
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


	/*<=============================> Algorithm Implementation <==================================>
	 * take each node as root of page query graph
	 * find page relevence score of the given page
	 * find total spanning forest of the given page
	 <=============================>********<=====================================>    */  


		                                 //execution time calculation start
	    vector<int> values(10000);
	  
	    // Generate Random values
	    auto f = []() -> int { return rand() % 10000; };
	  
	    // Fill up the vector
	    generate(values.begin(), values.end(), f);
	  
	    // Get starting timepoint
	    auto start = high_resolution_clock::now();

		                                                                            
		for(int m=0;m<3;m++)
		{
		int k=0;
		cout<<"<==================> Page: "<<m+1<<" <==================>\n"<<endl;
			for(int i=0;i<size_w;i++)       //finding value for relational probality(Tij)
			{
				for(int j=0;j<size_pw1;j++)
				{
					if(sr1[i]==rp[j])
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
		
		for(int i=1;i<size_rp;i++)            // printing all possible spanning forests of variable length
		{
			cout<<"Length "<<i<<":  "<<total[i]<<endl;
			if(spanning_forests<total[i])
				spanning_forests=total[i];
		}

		cout<<"page relevence score OF Given Page:"<<Page_rel_score<<endl;
		cout<<"Total Spanning Forests Of Given Page :"<<spanning_forests<<endl;


		for(int i=0;i<7;i++)                              //setting intial values of arrays
		{
			weight[i]=0.0;
			total[i]=0;
			visited[i]=0;
			t1[i]=0;
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
