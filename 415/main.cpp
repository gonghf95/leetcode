#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string addStrings( string num1, string num2 )
    {
        string ans;
        int i = num1.length() - 1, j = num2.length() - 1;
        int carry = 0;
        int tmp = 0;
        char ch;
        while( i >= 0 || j >= 0 || carry > 0 )
        {
            if( i >= 0 && j >= 0)
                tmp  = ( num1[ i ] - '0' ) + ( num2[ j ] - '0' ) + carry;
            else if( i >= 0 )
                tmp = num1[ i ] - '0' + carry;
            else if( j >= 0 )
                tmp = num2[ j ] - '0' + carry;
            else if( carry > 0 )
                tmp = carry;
            else
                break;
            
            carry = tmp / 10;
            ch = '0' + tmp % 10;
            ans = ch + ans;
            i--;
            j--;
        }
        return ans;
    }
};

int main( int argc, char* argv[] )
{
    string s1("9");
    string s2("99");

    Solution s;
    cout << s.addStrings( s1, s2 ) << endl;
    return 0;
}