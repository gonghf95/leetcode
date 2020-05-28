#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	Solution()
	{
		int i;
		for( i = 0; i < MAXSIZE; i++ )
			father[ i ] = i;
	}

	int findCircleNum( vector< vector< int > >& M )
	{
		unsigned int i, j;
		for( i = 0; i < M.size(); i++ )
			for( j = i; j < M.size(); j++ )
				if( M[ i ][ j ] == 1 )
					Union( i, j );
		
		int count = 0;
		for( i = 0; i < M.size(); i++ )
			if( father[ i ] == i )
				++count;
		return count;
	}

private:

	int Find( int a )
	{
		int fa = father[ a ];
		if( fa == a )
			return fa;
		return father[ a ] = Find( fa );
	}

	void Union( int a, int b )
	{
		int fa = Find( a );
		int fb = Find( b );
		if( fa < fb )
			father[ fb ] = fa;
		else
			father[ fa ] = fb;
	}

private:
	enum { MAXSIZE = 201 };
	unsigned int father[ MAXSIZE ];
};

int main( int argc, char* argv[] )
{
	vector< vector< int > > stus = {
		{ 1, 1, 0 },
		{ 1, 1, 1 },
		{ 0, 1, 1 }
	};

	Solution s;
	cout << s.findCircleNum( stus ) << endl;
	return 0;
}
