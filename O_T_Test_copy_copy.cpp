#include <iostream>
#include <unordered_map>

using namespace std;

class Player 
{
private:
string name;
string npc_name;
int opinion;

unordered_map<string, int> NPCopinion;
unordered_map<string, Player> player;

public:
    Player() : name("Unnamed"), npc_name("error"), opinion(0) {}  // ✅ Default constructor - Used when a Player object is created without arguments (e.g., when unordered_map creates a default object). -  Ensures the object has valid default values.

    Player(string name) : name(name), npc_name("error"), opinion(0) {} // ✅ Parameterized Constructor - Used when you want to explicitly set the name of the player when creating the object.

    // Why Keep the Initializer List in Player(string name)?
    // Without it, name, npc_name, and opinion would be default-constructed first and then reassigned inside the constructor body, which is less efficient.
    // The initializer list directly initializes the members at the moment of object creation, making it faster.
    // Summary
    // ✔ Keep both constructors
    // ✔ Keep the initializer list in Player(string name) for efficiency
    // ✔ Default constructor allows unordered_map to create objects properly
    
    // Let me know if anything is unclear! 🚀


    void NPC_saver()
    {
        cout << "Submit an NPC: ";
        cin >> npc_name;
        cout << "Between -50 and 50, in what regard do they hold you? ";
        cin >> opinion;
        NPCopinion[npc_name] = opinion;
    }

    void DATA_printer()
    {
        cout << "Character: " << name << ", has relationships with:" << endl;
        for (const auto& relation : NPCopinion) 
        {
            cout << "- NPC: " << relation.first << ", Opinion: " << relation.second << endl;
        }
    }
};

int main()
{
unordered_map<string, Player> players;
int menu = 0;
string name;
                                     
    while (menu != 4)
    {
        //___________________________________________________________________
        cout << "Type the corronsponding number of the option to execute it:" 
        << endl << "Type 1) To add a player and their npc relations" 
        << endl << "Type 2) To add an npc and their opinion score to an existing player" 
        << endl << "Type 3) To display the npc relations of a given player" 
        << endl << "Type 4) to end the program" 
        << endl;
        //___________________________________________________________________
        cin >> menu;

        if (menu == 1)
        {
        cout << "What is your name? ";
        cin >> name;
            //    \/ Checks if a player is already in the database  \/ equates that check to null. So the if statements asks "If searching for the name in the database is equal to null as in nothing is found, then proceed with adding a new player."
            if (players.find(name)                                 == players.end()) 
            {
            // |2|. Stores it in userStorage, an unordered_map<string, Opinion_tracker>, using name as the key.             |1|. Creates a new Opinion_tracker for the entered player name (name).
                players[name]                                                                                                = Player(name);  // ✅ Create and store the Player
            }

        char cycle = '\n';
            
            while (cycle == '\n')
            {
                players[name].NPC_saver();
                cout << "Press ENTER to continue adding NPC's. Press c to stop adding npc's";
                cin.ignore();
                cycle = cin.get();  // ✅ Reads one character, including `\n`
            }
        }

        else if (menu == 2)
        {
            cout << "Submit a name of an existing player to which you would like to add additional NPC relations: ";
            cin >> name;

            if (players.find(name) != players.end())
            {

            char cycle = '\n';

                while (cycle == '\n')
                {
                    players[name].NPC_saver();
                    cout << "Press ENTER to continue adding NPC's. Press c to stop adding npc's";
                    cin.ignore();
                    cycle = cin.get();  // ✅ Reads one character, including `\n`
                }
            }  
            else 
            {
                cout << "Player '" << name << "' not found." << endl << endl;
            }
        }
        
        
        else if (menu == 3)
        {
        cout << "Type the name of the character who's NPC relations you whish you view: ";
        cin >> name;
            if (players.find(name) != players.end())
            {
                players[name].DATA_printer();
            }  
            else 
            {
                cout << "Player '" << name << "' not found." << endl << endl;
            }
        }
    }
return 0;
}
