#include <bits/stdc++.h>
using namespace std;
template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}
int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}
