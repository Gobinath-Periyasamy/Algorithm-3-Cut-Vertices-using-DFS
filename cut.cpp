#include<bits/stdc++.h>
using namespace std;


/**********************************
Name: Gobinath P
Roll No : CS21M501
Algorithm for finding cut vertices using depth-first-search (DFS).
************************************/



unordered_map<int,vector<int>> near;

void Depth(int u, vector<int>& Notcon, vector<int>& Min, vector<int>& parent, vector<bool>& cutvert_arti_p)
{
	static int iterate = 0;

	Notcon[u] = Min[u] = iterate;

	iterate ++;
	int Branch = 0;

	for(int v: near[u])
	{
		// Vertex is not visited
		if(Notcon[v]==-1)	
		{
		Branch++;
			parent[v] = u;
			// Recursive call to contune Next branch 
			Depth(v,Notcon,Min,parent,cutvert_arti_p);
			Min[u] = min(Min[u],Min[v]);
			// Base Case
			if(parent[u]==-1 and Branch>1)
				cutvert_arti_p[u] = true;
			// for one loop is separated
			if(parent[u]!=-1 and Min[v]>=Notcon[u])	
				cutvert_arti_p[u] = true;
		}
		// Ignore branch to parent edge
		else if(v!=parent[u])	
			Min[u] = min(Min[u],Notcon[v]);
	}	
}

int main()
{

	int Vertex = 0;
	int Edge = 0;


    cout << "\n*********************************************"<<endl;
    cout << "* Name: Gobinath P                          *"<<endl;
    cout << "* Roll No : CS21M501                        *"<<endl;
    cout << "* Cut Vertices using depth-first-search     *"<<endl;
    cout << "*********************************************"<<endl;

	// User input for Vertices, Edges and 
	cout<< "Enter number of Vertex : " << endl;
	cin>>Vertex;
	cout<< "Enter number of Edges : "<<endl;
	cin>>Edge;

	for (int i=0; i < Edge;i++)
	{
		int y = 0, z =0;
		cout<<"Enter Edge " << i << " Vertices : \n\n\tSource : ";
		cin >> y;
		cout<<"\tDestination : ";
		cin >> z;
		near[y].push_back(z);
		cout<<"\n"<<endl;
	}

	vector<int> Notcon(Vertex,-1),Min(Vertex,-1),parent(Vertex,-1);

	// To eliminate cross
	vector<bool> cutvert_arti_p(Vertex,false);

	for(int i=0;i<Vertex;++i)
		if(Notcon[i] == -1)
			Depth(i,Notcon,Min,parent,cutvert_arti_p);

    cout<<"*************************************************************"<<endl;
	cout<<"The Cut Vertices Points for the given Points are: " << endl;
	for(int i=0;i<Vertex;++i)
		if(cutvert_arti_p[i]==true)
			cout<<i<<",";

	cout << "\nThe Time Complexity of the Algorithm is : O(V+E)"<<endl;
    cout<<"*************************************************************"<<endl;

    system("PAUSE");

    return EXIT_SUCCESS;
}

