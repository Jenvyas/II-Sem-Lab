/*******************************************

Jevgenijs Pigožņa, jp22034

F14. Dots teksta fails, kurā atrodas C++ programmas teksts. 
Pārbaudīt dotajā programmas tekstā atverošo un aizverošo iekavu lietojumu 
(t.i., vai katrai atverošajai iekavai seko aizverošā, un vai iekavu secība ir pieļaujama). 
Nepieļaujami ir sekojoši gadījumi:  )(   vai  ()) , vai  ((). 
Drīkst uzskatīt, ka programmas tekstā nav komentāru 
un ka attiecīgie simboli neparādīsies teksta literāļos.

Programma izveidota: 2023/02

*******************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct OpeningParenthesis
{
    int line;
    int position;
};

int main()
{
    int running = 1;

    while (running == 1)
    {
        cout << "Input the name of the text file to check : ";
        string file_name;
        cin >> file_name;
        cout << '\n';

        fstream input_file(file_name, ios::in); //izveido straumi izvēlētajam failam

        string line; // strings kur nokope rindu no teksta faila

        int position;
        int line_count(0);

        vector<OpeningParenthesis> parenthesis_vec; //vektors, kur glabāt iekavas(tiek lietots kā stacks)

        if (input_file.is_open())
        {

            while (getline(input_file, line))
            {
                line_count++;
                position = 0;
                for (char c : line)
                {

                    position++;

                    if (c == '(')
                    {
                        OpeningParenthesis opening_parenthesis;
                        opening_parenthesis.line = line_count;
                        opening_parenthesis.position = position;

                        parenthesis_vec.push_back(opening_parenthesis);
                    }
                    else if (c == ')')
                    {
                        if (parenthesis_vec.size() == 0) // pārbaude vai aizveramai iekavai ir atbilstoša atveramā
                        {
                            cout << "Closing parenthesis with no opening parenthesis on line: ";
                            cout << line_count << " position: " << position << '\n';
                        }
                        else // ja ir atbilstoša iekava, tā tiek izmesta no vektora.
                        {
                            parenthesis_vec.pop_back();
                        }
                    }
                }
            }

            if (parenthesis_vec.size() != 0) // ja ir palikusi pāri kāda iekava, tad izvada, kur tā atrodas
            {
                for (const OpeningParenthesis &parenthesis : parenthesis_vec)
                {
                    cout << "Opening parenthesis with no closing parenthesis on line: ";
                    cout << parenthesis.line << " position: " << parenthesis.position << '\n';
                }
            }

            input_file.close();
        }
        else
        {
            cout << "There was an issue with opening the file.\n";
        }

        cout << "Would you like to check another file?\n";
        cout << "(1 - yes/0 - no): \n";
        cin >> running;
    }
}