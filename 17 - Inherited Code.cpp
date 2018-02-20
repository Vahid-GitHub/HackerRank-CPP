/* Define the exception here */

class BadLengthException : public exception {
    int n;
    public:
    BadLengthException(int a) { n = a; }
    //virtual const char * what () const throw () {
    //    stringstream ss;
    //    ss << n;
    //    return((ss.str()).c_str());
    int what () {
        return(n);
   }
};