// Program Ch03pr01
// Program to manage strings

#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 10 ;

class char_array
{
	private :

		char str[MAX] ;

	public :

        string( ) ;
		string ( char *s ) ;
		int xstrlen( ) ;
		static void xstrcpy ( string &t, string &s ) ;
		static void xstrcat ( string &t, string &s ) ;
		static int xstrcmp ( string &s1, string &s2 ) ;
		void show( ) ;
} ;

// initializes data member
char_array :: string( )
{
}

// initialize the data memebers
char_array :: string ( char *s )
{
	strcpy ( str, s ) ;
}

// finds the length of the string
int char_array :: xstrlen( )
{
	int l = 0 ;
	char *s = str ;
	while ( *s )
    {
		l++ ;
        s++ ;
    }
	return l ;
}

// copies source string s to the target string t
void char_array :: xstrcpy ( string &t, string &s )
{
	char *s1 = t.str ;
	char *s2 = s.str ;

	while ( *s2 )
	{
		*s1 = *s2 ;
		s1++ ;
		s2++ ;
	}
	*s1 = '\0' ;
}

// concatenates the two strings
void char_array :: xstrcat ( string &t, string &s )
{
	char *s1 = t.str ;
	char *s2 = s.str ;

	while ( *s1 )
		s1++ ;
	while ( *s2 )
		*s1++ = *s2++ ;
	*s1 = '\0' ;
}

// comapres two strings s1 and s2 for equality
int char_array :: xstrcmp ( string &s1, string &s2 )
{
	char *s = s1.str ;
	char *t = s2.str ;

	while ( *s == *t )
	{
		if ( ! ( *s ) )
			return 0 ;
		s++ ;
		t++ ;
	}
	return ( *s - *t ) ;
}

// displays the string
void char_array :: show( )
{
	cout << str << endl ;
}

int main( )
{
	char_array s1 ( "kicit" ) ;
	char_array s2 ( "Nagpur" ) ;

	cout << endl ;
	cout << "String s1: " ;
	s1.show( ) ;
	cout << "\nLength of string s1: " << s1.xstrlen( ) << endl ;

	cout << "\nString s2: " ;
	s2.show( ) ;

	char_array s3 ;
	char_array :: xstrcpy ( s3, s1 ) ;
	cout << "\nString s3 after copying s1 to it: " ;
	s3.show( ) ;

	char_array :: xstrcat ( s3, s2 ) ;
	cout << "\nString s3 after concatenation: " ;
	s3.show( ) ;

	if ( char_array :: xstrcmp ( s1, s2 ) == 0 )
		cout << "\nThe strings s1 and s2 are similar" << endl ;
	else
		cout << "\nThe strings s1 and s2 are not similar" << endl ;
		
	return 0;
}
