#include "Harl.hpp"
#include <iostream>

int main( int argc, char **argv )
{  
  if ( argc != 2 )
  {
    std::cout << "Usage: ./harlFilter <level>" << std::endl
			<< "Levels are: DEBUG - INFO - WARNING - ERROR" << std::endl;
	  return ( 0 );
  }
  Harl        harl;
  std::string level = argv[1];

  harl.complain( level );

  return (0);
}