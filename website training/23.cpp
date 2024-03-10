#include<iostream>
#include<vector>
#include<array>
#include<map>
#include<string>
using namespace std;
// A Funcyion To Decode Our Cipher Messge.
string decodeBaconian(const string &baconian) {
    string result = "";

    const int partSize = 5;
   // Baconian Shcdual .
    string baconianTable[] = {
        "aaaaa", "aaaab", "aaaba", "aaabb", "aabaa",
        "aabab", "aabba", "aabbb", "abaaa", "abaab",
        "ababa", "ababb", "abbaa", "abbab", "abbba",
        "abbbb"
    };
  // This Loop To Pass on Each 5 characters .
    for (size_t i = 0; i < baconian.size(); i += partSize) {
        string part = baconian.substr(i, partSize);
 // This Loop To Link ASCII By our Cipher.
        for (int j = 0; j < 26; ++j) {
            if (part == baconianTable[j]) {
                result += static_cast<char>('A' + j);
                break;
            }
        }
    }

    return result;
}


int main()
{
    // A While Loop to Ensure And Choice the user Among Encoding and Decoding.
    short result3 = 0;
    while(result3 < 1)
    {
        short result2 = 0;
        short result1 = 0;
        char choice;
        cout << "DO You Want To Encoding, Decoding Or Exit ?" << endl; cout << " Choose From A ,B and C.." << endl;
        cout << " A : Encoding " << "\n"; cout << " B : Decoding " << "\n"; cout << " C : Exit " << "\n";
        cout << "Your Choice : " ; cin >> choice;

        if (choice == 'C') 
        {
            cout << " End The Program " << endl;
            break;
        }
        if(choice == 'A')
        {
            while(result1 < 1)
            {
                // map to Each Character's value.
    map<char, string> baconiancipher_Enconding{ {'a',"aaaaa"} , {'b',"aaaab"} , {'c',"aaaba"} , {'d',"aaabb"} , {'e',"aabaa"} , {'f',"aabab"} , {'g',"aabba"} ,
    {'h',"aabbb"} , {'i',"abaaa"} , {'j',"abaab"} , {'k',"ababa"} , {'l',"ababb"} , {'m',"abbaa"} , {'n',"abbab"} , {'o',"abbba"} , {'p',"abbbb"} ,
    {'q',"baaaa"} , {'r',"baaab"} , {'s',"baaba"} , {'t',"baabb"} , {'u',"babaa"} , {'v',"babab"} , {'w',"babba"} , {'x',"babbb"} , {'y',"bbaaa"} ,
    {'z',"bbaab"} };



    /*===========================================================*/
    string message;
    string ciphermessage = "";
    cout << " Enter Your Message That You Want To Encoding : ";
    getline(cin, message);
    // Here Will Pass On All Chracters And Convert Them Into a & b According to The Baconian Rules. 
    for (char i : message)
    {
        i = tolower(i);
        if (isalpha(i))
        {
            ciphermessage += baconiancipher_Enconding[i];
        }
        else
        {
            if (isspace(i)) continue;
            else if (ispunct(i)) continue;
            else if (isdigit(i)) continue;
            ciphermessage += baconiancipher_Enconding[i];
        }


    cout << ciphermessage << endl;
    result1++;
            }
        }
/*==========================================================================*/
// Decoding //
     if(choice == 'B')
    {

        while(result2 < 1)
        {
    string Encode_Message;
    cout << " Enter The Original Message : ";
    getline(cin, Encode_Message);
    for(char i : Encode_Message)
    {
        if(!isalpha(i)) cout << " Please Enter A baconian cipher Not Any Thing else.." << endl;
        else if (isalpha(i)) 
          i = tolower(i);
        else if(isspace(i)) continue;
        else if (i != 'a' || i != 'b') cout << " Enter a & b Only.." << endl;
        break;

        if(Encode_Message.length() % 5 != 0)
        {
            cout << " Your Encoding Message Is Not Correct " << endl << " Enter A Groups With 5 Characters.." << "\n";
        }
   result2++;
    } 
    cout << (decodeBaconian(Encode_Message));

    }

    }

    }
  result3++;
    }

    return 1;
}