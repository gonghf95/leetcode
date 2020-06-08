#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome( string s )
    {
        if( s.empty() )
            return true;

        int i = 0;
        int j = s.length();
        char lch;
        char rch;
        while( i <= j )
        {
            lch = tolower( s[ i ] );
            rch = tolower( s[ j ] );
            if( !isdigit( lch ) && !isalpha( lch ) )
            {
                i++;
                continue;
            }

            if( !isdigit( rch ) && !isalpha( rch ) )
            {
                j--;
                continue;
            }

            if( lch != rch )
                return false;
            
            i++;
            j--;
        }
        return true;
    }
};

int main( int argc, char* argv[] )
{
    string str( "  " );
    Solution s;
    cout << s.isPalindrome( str ) << endl;
    return 0;
}