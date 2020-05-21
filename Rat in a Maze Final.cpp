#include<bits/stdc++.h>
#define MAX 5
using namespace std;

bool isSafe(int row,int col,int m[][MAX],int n,bool visited[][MAX])
{
	if (row==-1 || row==n || col==-1 || col==n || visited[row][col] || m[row][col]==0)
        {
		return false;
        }
	return true;
}
/*
Function to print all the possible paths from Start to End
*/
void printPathUtil(int row,int col,int m[][MAX],int n,string& path,vector<string>&possiblePaths,bool visited[][MAX])
{
	if (row==-1 || row==n || col==-1|| col==n || visited[row][col]|| m[row][col]==0)
		return;

	if (row==n-1 && col==n-1)                            // If Last Cell Reached then store the String in Vector
    {
		possiblePaths.push_back(path);
		return;
	}

	visited[row][col]=true;                             // Mark the cell as visited

	if (isSafe(row+1,col,m,n,visited))                  // If Downward Possible
	{
		path.push_back('D');
		printPathUtil(row+1,col,m,n,path,possiblePaths,visited);
		path.pop_back();
	}

	if (isSafe(row,col-1,m,n,visited))                  // If Left Move is Possible
	{
		path.push_back('L');
		printPathUtil(row,col-1,m,n,path,possiblePaths,visited);
		path.pop_back();
	}

	if (isSafe(row,col+1,m,n,visited))                  // If Right Move is Possible
	{
		path.push_back('R');
		printPathUtil(row,col+1,m,n,path,possiblePaths,visited);
		path.pop_back();
	}

	if (isSafe(row-1,col,m,n,visited))                  // If UP Move is Possible
	{
		path.push_back('U');
		printPathUtil(row-1,col,m,n,path,possiblePaths,visited);
		path.pop_back();
	}

	visited[row][col]=false;                            // Mark the cell as Unvisited
}

void printPath(int m[MAX][MAX],int n)                   // Function to Print and Store all Valid Paths
{
	vector<string> possiblePaths;
	string path;
	bool visited[n][MAX];
	memset(visited,false,sizeof(visited));

	printPathUtil(0,0,m,n,path,possiblePaths,visited);

	for (int i = 0; i < possiblePaths.size(); i++)
    {
		cout<<i+1<<". "<<possiblePaths[i]<<endl;
    }
}

// Driver code
int main()
{
    cout<<"RAT IN A MAZE"<<endl<<endl;
    cout<<"Welcome to the Puzzle :)"<<endl<<endl;
    cout<<"We have a crazy rat which is at its start position in the Maze and is very Hungry !"<<endl<<"We need to tell him all the possible ways to reach at end of the Maze"<<endl<<"so that he can cross the maze and satisfy his Hunger"<<endl;

    /*int m[MAX][MAX];
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            cin>>m[i][j];
        }
    }*/
	int m[MAX][MAX] = { { 1, 0, 0, 0, 0 },
						{ 1, 1, 1, 1, 1 },
						{ 1, 1, 1, 0, 1 },
						{ 0, 0, 0, 0, 1 },
						{ 0, 0, 0, 0, 1 } };

	int n=sizeof(m)/sizeof(m[0]);
	cout<<endl;
	printPath(m,n);
	return 0;
}
