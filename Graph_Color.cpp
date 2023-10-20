#include<iostream>
using namespace std;
class Graph
{
	public:
		int **G;
		int n;
		Graph()
		{
			cout<<"\nEnter vertices:";
			cin>>n;
			G=new int*[n];
			for(int i=0;i<n;i++)
			{
				G[i]=new int[n];
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					G[i][j]=0;
				}
			}
		}
			void readGraph()
			{
				cout<<"\n  Enter your "<<n<<" * "<<n<<" matrix is:";
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
					{
						cin>>G[i][j];
					}
				}
			}
			void showGraph()
			{
				cout<<"\n your "<<n<<" * "<<n<<" matrix is:";
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
					{
						cout<<G[i][j]<<" ";
					}
					cout<<endl;
				}
			}	
};
class graphColor
{
	Graph graph;
	int m;// no of color
	int *color;// which vertice have which color	
	public:
		graphColor()
		{
			graph.readGraph();
			graph.showGraph();
			cout<<"Enter no of colours:";
			cin>>m;
			color=new int[graph.n];
		}
		bool canicolor(int v,int c)
		{
			for(int i=0;i<graph.n;i++)
			{
				if(graph.G[v][i]!=0)
				{
					if(color[i]==c)
					{
						return false;// adjacent have that color
					}
				}
			}
			return true;
		}
		bool colourgraph(int v)
		{
			if(v==graph.n)
			{
				for(int i=0;i<graph.n;i++)
				{
					cout<<color[i]<<" ";
				}
				return true;
			}
			else
			{
				for(int c=1;c<=m;c++)
				{
					if(canicolor(v,c))
					{
						color[v]=c;
						bool ans=colourgraph(v+1);
						return ans;// if all backtrack ans is true then there are enough no of color
					}
				}
				return false;
			}
		}
		void graphcolouring()
		{
			bool ans;
			ans=colourgraph(0);
			if(!ans)
			{
				cout<<"cant color";	
			}
			else
			{
				cout<<m<<"color";
			}

		}
};
int main()
{
	graphColor g;
	g.graphcolouring();
}


