#include "game.h"
#include "item.h"
#include "definitions.h"
#include "string.h"
#include "stdlib.h"

using namespace std;

//HELPFUL PROTOTYPES
void printDesignC(int i);
void newpage(){
	for(int i = 0; i < 50; i++){ cout << "\n"; }
}

///////// CONSTRUCTORS AND DESTRUCTORS /////
Game::Game(){
	firstTime = false;
	money = 50;
	level = 1;
	items = new Item*[50];
	for(int i = 0; i < 50; i++){
		items[i] = NULL;
	}
	itemCount = 0;
}

Game::~Game(){
	for(int i = 0; i < 50; i++){
		if(items[i] != NULL)
			delete items[i];
	}
	delete [] items;
	items = NULL;
}
/////////// GETTERS AND SETTERS ///////

void Game::addItems(int numType){
	//copy over existing items and delete old array
	if(itemCount < 50){
		if(itemCount > 40){
			cout << "Careful, you only have " << 50-itemCount 
			<< " item spaces left!" << endl;
		}
	}
	else{
		cout << "You have 50 items! Delete or use an item to free space" << endl;
	}
	//add new item to last position depending on int sent in
	switch(numType){
		case 1:
			items[itemCount] = new Peach;
			break;
		case 2:
			items[itemCount] = new Charcoal;
			break;
		case 4:
			items[itemCount] = new Herbs;
			break;
	}
	itemCount++;
}

void Game::deleteItemChoice(){
	int choice;
	printItems();
	cout << "Which item type would you like to delete? "<<endl;
	cin >> choice;
	//CHECK: MAKE SURE IF YOU INCREASE ITEMS INCREASE THIS LIST
	while(choice != 1 && choice != 3 && choice != 3){
		cout << "Error! Please enter 1 for peach, 2 for charcaol pencil or 3 for herbs" << endl;
		cin >> choice;
	}
	//TODO check if their choice even exists within array
	deleteItem(choice);
}

void Game::deleteItem(int n){
	for(int i = 0; i < itemCount; i++){
		if(items[i]->numType == n){
			delete items[i];
			items[i] = items[itemCount-1];
			break;
		}
	}
	itemCount--;
}

int Game::useItem(int n){
	return -1;
}

////////// FUNCTIONS /////////
void Game::initItems(){
	items[0] = new Peach;
	items[1] = new Charcoal;
	items[2] = new Herbs;
	itemCount = 3;
}

void Game::initBoard(){
	int rows = 10;
	int cols = 10;
	int num_peaches = 10;
	int num_bees = 2;
	int num_pencils = 10;
	int num_herbs = 10;


	Board = new char*[rows];
	for(int i = 0; i < rows; i++){
		Board[i] = new char[cols];
		for(int j = 0; j < cols;j++){
			Board[i][j] = ' ';
		}
	}
	//peaches
	for(int i = 0; i < num_peaches; i++){
		int ri = rand()%10;
		int rj = rand()%10;
		if (Board[ri][rj] ==  ' '){
			Board[ri][rj] = 'p';
		}
		else i--;
	}

	//pencils
	for(int i = 0; i < num_pencils; i++){
		int ri = rand()%10;
		int rj = rand()%10;
		if (Board[ri][rj] ==  ' '){
			Board[ri][rj] = 'c';
		}
		else i--;
	}

	//bees
	for(int i = 0; i < num_bees; i++){
		int ri = rand()%10;
		int rj = rand()%10;
		if (Board[ri][rj] ==  ' '){
			Board[ri][rj] = 'b';
		}
		else i--;
	}

	//herbs
	for(int i = 0; i < num_bees; i++){
		int ri = rand()%10;
		int rj = rand()%10;
		if (Board[ri][rj] ==  ' '){
			Board[ri][rj] = 'h';
		}
		else i--;
	}
}
void Game::printBoard(){
	Board[c.x][c.y] = '*';
	for(int i = 0; i < 10; i++){
		cout << "|";
		for(int j = 0; j < 10; j++){
			if(Board[i][j] == '*'){
				if(c.design == 1)
					cout<<"\033[35;6m * \033[0m|";
				else if(c.design == 2)
					cout<<"\033[36;6m * \033[0m|";
				else
					cout<<"\033[35;1m * \033[0m|";
			}
			else {cout << " " << Board[i][j] << " |";}
		}
		cout << endl;
		for(int k = 0; k < 10; k++) cout << "----";
		cout << endl;
	}
}

void Game::gamePlay(){
	char choice = 'b';
	char temp;
	while(choice != 'x'){
		newpage();
		printHeader();
		printBoard();
		cout << "Use a (left) w (up) s (down) d (right) to move about the board. Press x to exit map.";
		cin.get(choice);
		temp = ' ';
		switch(choice){
			case 'W':
			case 'w':
				if(Board[c.x-1][c.y] != '#'){
					temp = Board[c.x-1][c.y];
					Board[c.x][c.y] = ' ';
					c.x = c.x-1;
					Board[c.x][c.y] = '*';
				}
				break;
			case 'a':
			case 'A':
				if(Board[c.x][c.y-1] != '#'){
					temp =Board[c.x][c.y-1];
					Board[c.x][c.y] = ' ';
					c.y = c.y-1;
					Board[c.x][c.y] = '*';
				}
				break;
			case 'd':
			case 'D':
				if(Board[c.x][c.y+1] != '#'){
					temp = Board[c.x][c.y+1];
					Board[c.x][c.y] = ' ';
					c.y = c.y+1;
					Board[c.x][c.y] = '*';
				}
				break;
			case 's':
			case 'S':
				if(Board[c.x+1][c.y] != '#'){
					temp = Board[c.x+1][c.y];
					Board[c.x][c.y] = ' ';
					c.x = c.x+1;
					Board[c.x][c.y] = '*';
				}
			break;
		}
		//gather the bounty!! aka pick up what you moved over
		switch(temp){
			case 'p':
				peach();
				addItems(1);
				break;
			case 'c':
				addItems(2);
				break;
			case 'h':
				addItems(4);
				break;
			case 'b':
				bees(&c);
				break;
		}
	}
}
void Game::mythicalLlama(){
	//TODO: Mythical Llama
}

void Game::peach(){
	char key;
	cin.ignore();
	cout << "\033[31;1m`\\-_               " << endl;
	cout << "  \\ _- _           " << endl;
	cout << "     ___\\\\ ___   " << endl;
	cout << "    (..  ^^     )  " << endl;
	cout << "   (.. . .       ) " << endl;
	cout << "   |. . .         |" << endl;
	cout << "   (_ .          _)" << endl;
	cout << "    (_         _)  " << endl;
	cout << "      (__   __ )   " << endl;
	cout << "         -.-       \033[0m" << endl;
	cout << endl << "You gain a peach to your inventory! Press 'e' to eat. Press any other key to continue." << endl;
	cin.get(key);
	if(key == 'e' || key == 'E'){
		useItem(1);
	}
}


void Game::bees(Creature *c){
	char key;
	if(c->health <= 5){
		cout << "You don't have enough health to survive a bee sting! Whatever will you do!" << endl;
		mythicalLlama();
		return;
	}
	cin.ignore();
	newpage();
	cout << "\033[33;1mBEEEEESSS AHHH BEEESSS  " << endl;
	cout << "++     ++               " << endl;
	cout << "++++ +++                " << endl;
	cout << "  +++++__----____       " << endl;
	cout << "   /||    ||   ||\\ _`_` " << endl;
	cout << "  | ||    ||   || | . .|" << endl;
	cout << "  \\ ||    ||   || \\____/" << endl;
	cout << "   ---------------      \033[0m" << endl;
	cout << endl << "Your health has declied by 5 points! Press any key to continue." << endl;
	cin.get(key);

	if(c->health <= 10){
		cout << "Careful! you only have " << c->health << " health left!" << endl;
	}
}

void Game::initCharacter(){
	initItems();
	initBoard();
	newpage();
	int answer;
	cout << "Welcome to Backyard BBQ!" << endl;

	// First time?
	cout << "Is this your first time playing? (1 = yes, any other key = no)" << endl;
	cin >> answer;
	if(answer == 1) firstTime = true;
	else firstTime = false;

	//Character
	cout << "Enter which character design: " << endl;
	printDesigns();
	cin >> c.design;
	while(c.design != 1 && c.design != 2 && c.design != 3){
		cout << "Incorrect decision: " << endl;
		cin >> c.design;
	}
	cout << "Enter your characters name: ";
	cin >> c.name;

	newpage();
	cout << "Hello, " << c.name << "!" << endl;
	printDesignC(c.design);
	cout << "Welcome to Persici." << endl << endl;
}

void Game::displayIndividualItem(int position){
	if(items[position] == NULL){
		cout << "LILY, YOU DONE FUCKED UP, FIX UR CODE" << endl;
	}
	int type = items[position]->numType;

	char c;
	switch(type){
		case 1: //
			newpage();
			cout << "PEACH: " << endl;
			cout << "The peach is your main source of nutrients. ";
			cout << "It increases your hunger meter by 5. ";
			cout << "Press 'e' to eat or any other key to exit " << endl;
			cout << endl;
			cout << "`\\-_               " << endl;
			cout << "  \\ _- _           " << endl;
			cout << "     ___\\\\ ___   " << endl;
			cout << "    (..  ^^     )  " << endl;
			cout << "   (.. . .       ) " << endl;
			cout << "   |. . .         |" << endl;
			cout << "   (_ .          _)" << endl;
			cout << "    (_         _)  " << endl;
			cout << "      (__   __ )   " << endl;
			cout << "         -.-       " << endl;

			cin.ignore();
			cin.get(c);

			newpage();
			if((c == 'e') || (c == 'E')){
				cout << "TODO: eat peach!" << endl;
				//TO DO if You have a peach eat it!
			}
			printHeader();
			printItems();
			cout << endl;

			break;
		case 2: //charcoal pencil
			newpage();
			cout << "CHARCOAL PENCIL: " << endl;
			cout << "The charcoal pencil helps you create beautiful art. ";
			cout << "It increases your happiness meter by 5 and your intelligence by 1. ";
			cout << "Press 'u' to use or any other key to exit" << endl;
			cout << endl;
			cout << "  .  " << endl;
			cout << " / \\" << endl;
			cout << " | | " << endl;
			cout << " |P| " << endl;
			cout << " |E| " << endl;
			cout << " |N| " << endl;
			cout << " |C| " << endl;
			cout << " |I| " << endl;
			cout << " |L| " << endl;
			cout << " | | " << endl;
			cout << " |#| " << endl;
			cout << " --  " << endl;

			
			cin.ignore();
			cin.get(c);

			newpage();
			if((c == 'u') || (c == 'U')){
				cout << "TODO: use pencil" << endl;
				//TO DO if You have a peach eat it!
			}
			printHeader();
			printItems();
			cout << endl;

			break;
		case 4: //herbs
		    newpage();
		    cout << "HERBS: " << endl;
		    cout << "Herbs keep you healthy while you roam the great planes of Madala. ";
		    cout << "Eat these if you have suffered an injury. ";
		    cout << "They will increase your health by 5" << endl;
		    cout << "Press 'e' to eat or any other key to exit" << endl;
			cout << "           |  _        " << endl;
			cout << "         \\-||_-/       " << endl;
			cout << "        - ||           " << endl;
			cout << "     -_    ||   _-     " << endl;
			cout << "      \\ _-||_ - /      " << endl;
			cout << "         - ||          " << endl;
			cout << "    -_   ||   _-       " << endl;
			cout << "       \\ _-||_ - /     " << endl;
			cout << "        - ||           " << endl;
			cout << " ..|.|.||______ |.|||.." << endl;

			cin.ignore();
			cin.get(c);

			newpage();
			if((c == 'u') || (c == 'U')){
				cout << "TODO: eat herbs!" << endl;
				//TO DO if You have a peach eat it!
			}
			printHeader();
			printItems();
			cout << endl;
			break;
	}
}


void Game::printHeader(){
	cout << "Player: " << c.name << endl;
	cout << "Age: " << c.age << " | Health: " << c.health << " | Happiness: " << c.happiness << " | Hunger: " << c.hunger <<endl;
	if(c.religious)
		cout << "REVERENCE: " << c.reverence << " | ";
	cout << "DAY: " << day << " | MONEY: " << money << endl;
	printDesignC(c.design);
	cout << endl;
}


void Game::printDesigns(){
cout << "1.         |    2.        |    3.     " << endl;
cout << "\033[32;6m           \033[0m|\033[36;6m              \033[0m|\033[35;1m           \033[0m" << endl;
cout << "\033[32;6m()  ()     \033[0m|\033[36;6m    **   **   \033[0m|\033[35;1m      @  @ \033[0m" << endl;
cout << "\033[32;6m( '.' )    \033[0m|\033[36;6m    (o___o)   \033[0m|\033[35;1m     ( `.`)\033[0m" << endl;
cout << "\033[32;6m(_)  (_)   \033[0m|\033[36;6m   (_)  (_)   \033[0m|\033[35;1m   S(     )\033[0m" << endl;
cout << "\033[32;6m(@)  (@)   \033[0m|\033[36;6m    |__/__|   \033[0m|\033[35;1m     ----- \033[0m" << endl;
cout << "______________________________________" << endl << endl;
}

void printDesignC(int i){
	switch(i){
		case 1:
			cout << "\033[32;6m()  ()  \033[0m" << endl;
			cout << "\033[32;6m( '.' ) \033[0m" << endl;
			cout << "\033[32;6m(_)  (_)\033[0m" << endl;
			cout << "\033[32;6m(@)  (@)\033[0m" << endl;
		break;
		case 2:
			cout << "\033[36;6m**   ** \033[0m" << endl;
			cout << "\033[36;6m(o___o) \033[0m" << endl;
			cout << "\033[36;6m(_)  (_)\033[0m" << endl;
			cout << "\033[36;6m|__/__| \033[0m" << endl;
		break;
		case 3:
			cout << "\033[35;1m   @  @ \033[0m" << endl;
			cout << "\033[35;1m  ( `.`)\033[0m" << endl;
			cout << "\033[35;1mS(     )\033[0m" << endl;
			cout << "\033[35;1m  ----- \033[0m" << endl;
		break;
	}
}
void Game::loop(){
	string input;
	int goAgain = 1;

	while(1){
		c.age++;
		day++;
		newpage();
		printHeader();
		printMenu();
	}
}


void Game::printMenu(){
	string input;
	cout << "What would you like to do? " << endl;
	cout << "************* MENU **************" << endl;
	cout << "* 1. Show items                 *" << endl;
	cout << "* 2. Wander around              *" << endl;
	cout << "* 3. View character stats       *" << endl;
	cout << "* 4. Visit shop                 *" << endl;
	cout << "* 5. Exit                       *" << endl;
	cout << "*********************************" << endl; 
	cin >> input;
	if((input != "1") && (input != "2") && (input != "3") && (input != "4") && (input!= 5)){
		cout << "ERROR: Please enter a valid menu choice: " << endl;
		cin >> input;
	}

	char c;
	string answer;
	int isValid;
	int inputNum = atoi(input.c_str());
	switch(inputNum){
		case 1:	//see and use items
			showItemsFunc();
			break;
		case 2: //wander around
			gamePlay();
			break;
		case 3:
			cout << "TODO: view character stats" << endl;
			break;
		case 4:
			cout << "TODO: implement store" << endl;
			break;
		case 5:
			exit(0);
	}
}

void Game::showItemsFunc(){
	int isValid;
	string answer;
	newpage();
	printHeader();
	if(firstTime){
		cout << "Since this is your first time here, these are your items. " ;
		cout <<  "You can select an item to use it to improve your stats. " << endl;
		cout << "In the beginning of the game you are given 3 items. A peach (`@),";
		cout << " which can be used to nourish you, a charcoal pen (->) with which you can" ;
		cout << " create art and improve your mood, and herbs (%%) to heal your injuries." << endl;
		cout << endl;
	}
	printItems();
	cout << "Select a position to learn more about the item or press any letter key to exit items: " << endl;
	cin >> answer;
	isValid = checkItemInt(answer, itemCount);
	while(isValid == -1){
		cout << "ERROR: Enter a valid item position or any letter key to exit:" << endl;
		cin >> answer;
		isValid = checkItemInt(answer, itemCount);
	}
	if(isValid == 0)
		cout << "isValid is valid and answer is: " << atoi(answer.c_str()) << endl;
		displayIndividualItem(atoi(answer.c_str()));
}

int Game::checkItemInt(string answer, int top){ //1 is valid quit, 0 is valid pos, -1 is invalid entry
	if (answer.length() == 1){ //SINGLE CHAR OR INT
		if(answer[0] < 'a' || answer[0] > 'z') //lowercase letter
			return 1; //quit but valid quit
		else if(answer[0] < 'A' || answer[0] > 'Z') //uppercase letter
			return 1; //quit but valid quit
		else if(answer[0] < 0 || answer[1] > '9') //INVALID single-digit int
			return -1;
		else
			if(atoi(answer.c_str()) > top) //single char thats a valid int
				return 0; //valid char
			else
				return -1; //INVALID position too big
	}

	//ELSE MULT CHARS
	for(int i = 0; i < answer.length(); i++){
		if(answer[i] > '9' || answer[i] < '0')
			return -1;
		else
			if(atoi(answer.c_str()) > top)
				return -1;
			else
				return 0;
	}
	return -1;
}

void Game::printItems(){
	cout << "********* ITEM LIST *********" << endl;
	if(items != NULL){
		for(int i = 0; i < itemCount; i++){
			cout << i << ". | ";
		}
		cout << endl;
		for(int i = 0; i < itemCount; i++){
			cout << items[i]->shape << " | ";
		}
		cout << endl;
	}
	else{
		cout << "You have no items! " << endl;
	}
}


void mythicalLlama(){

}

