#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern( string s )
    {
        if( s.length() <= 1 )
            return false;
        int slen = s.length();
        int plen = 0;

        string pattern;
        string tmp;
        
        int offset = 0;
        for( int i = 0; i < slen; i++ )
        {
            pattern += s[ i ];
            plen = pattern.length();

            if( plen > ( slen / 2 ) )
                break;

            if( ( slen % plen ) != 0 )
                continue;
                
            offset = 0;
            while ( offset < slen )
            {
                tmp = s.substr( offset, plen );
                if( tmp != pattern )
                    break;
                offset += plen;
            }

            if( tmp == pattern )
                return true;
        }
        return false;
    }
};

int main( int argc, char* argv[] )
{
    string str( "ab" );
    Solution s;
    cout << s.repeatedSubstringPattern( str ) << endl;
    return 0;
}