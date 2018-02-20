#include <sstream>
// Write your Student class here
class Student
{
    int Scores[5];
    public:
        void input()
        {
            string scores;
            // cin.ignore(256, '\n');
            cin >> ws;
            getline(cin, scores);
            istringstream ss(scores);
            for (int i = 0; i < 5; i++)
                ss >> Scores[i];
        }
        int calculateTotalScore()
        {
            int ret = 0;
            for (int i = 0; i < 5; i++)
                ret += Scores[i];
            return (ret);
        }
};