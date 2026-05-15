#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>

void	printError( const char* name )
{
	std::cout << "Usage: " << name << " <filename> <string to replace>"
		<< " <string replacement>" << std::endl;
}

int		openStreams( std::ifstream& ifs, std::ofstream& ofs, const std::string& filename, const std::string& outfile )
{
	ifs.open( filename.c_str(), std::ifstream::in );
	if ( !ifs.is_open() )
	{
		std::cerr << "Error: " << filename << ": " << strerror( errno ) << std::endl;
		return ( EXIT_FAILURE );
	}

	ofs.open( outfile.c_str(), std::ofstream::out | std::ofstream::trunc );
	if ( !ofs.is_open() )
	{
		std::cerr << "Error: " << outfile << ": " << strerror( errno ) << std::endl;
		return ( EXIT_FAILURE );
	}
	return ( EXIT_SUCCESS );
}

void	replaceBuffer( std::string& buffer, const std::string& s1, const std::string& s2 )
{
	size_t	pos;

	pos = 0;
	if ( s1.empty() )
		return ;
	while ( (pos = buffer.find( s1, pos )) != std::string::npos )
	{
		buffer.erase( pos, s1.length() );
		buffer.insert( pos, s2 );
		if ( s2.empty() )
			pos += s1.length();
		else
			pos += s2.length();
	}	
}

int		readFile( std::ifstream& ifs, std::ofstream& ofs, const std::string& s1, const std::string& s2 )
{
	std::string	buffer;

	while ( std::getline( ifs, buffer ) )
	{
		if ( ifs.fail() )
			return ( EXIT_FAILURE );
		replaceBuffer ( buffer, s1, s2 );
		ofs << buffer;
		if ( !ifs.eof() )
			ofs << std::endl;
	}
	return ( EXIT_SUCCESS );
}

int main( int argc, char **argv )
{
	std::ifstream	ifs; /* read */
	std::ofstream	ofs; /* write */	
	std::string		filename, outfile, s1, s2;

	if ( argc != 4 )
	{
		printError( argv[0] );
		return ( EXIT_FAILURE );
	}
	filename = argv[1];
	outfile = filename;
	outfile.append(".replace");
	s1 = argv[2];
	s2 = argv[3];
	if ( openStreams(ifs, ofs, filename, outfile) )
		return ( EXIT_FAILURE );
	if ( readFile( ifs, ofs, s1, s2 ) )
	{
		std::cerr << "Error: failed to read/replace file" << std::endl;
		return ( EXIT_FAILURE );
	}
	ifs.close();
	ofs.close();
	return ( EXIT_SUCCESS );
}