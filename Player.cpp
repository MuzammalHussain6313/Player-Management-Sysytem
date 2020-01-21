#include<iomanip>
#include<ctime>
#include<string>
#include<iostream>
using namespace std;
time_t t = time(0);            // get system Date and time now 
tm* now = localtime(&t);       // (if system Date and time will wrong then calculation may wrong.)
void input(); 
void process();
void insertion();
void deletion();
void sorting(); 
void update();
struct match
{
	int score, wicket, score_given, over_bowled;
	match *newnode;
};
struct DOB
{
	int day;
	int month;
	int year;
};
struct DOD
{
	int day;
	int month;
	int year;
};
struct player
{
	string name;
	string country_name;
	string category;
	DOB date_of_birth;
	DOD date_of_dabut;
	player *link;

	match *head ;
	match *last;
	int total_score = 0, total_wicket = 0, total_over_bowled = 0, total_score_given = 0;
	int  best_score = 0;
	int best_wickect = 0;
};
void matchdata(match *newmatch)
{
	cout << "Enter score made : ";
	cin >> newmatch->score;
	while (newmatch->score < 0)
	{
		cout << "Invalid ! Enter a +ve value : ";
		cin >> newmatch->score;
	}
	cout << "Enter wickets taken :";
	cin >> newmatch->wicket;
	while (newmatch->wicket < 0)
	{
		cout << "Invalid ! Enter a +ve value : ";
		cin >> newmatch->wicket;
	}
	cout << "Entter score given : ";
	cin >> newmatch->score_given;
	while (newmatch->score_given < 0)
	{
		cout << "Invalid ! Enter a +ve value : ";
		cin >> newmatch->score_given;
	}
	cout << "Enter over bowled : ";
	cin >> newmatch->over_bowled;
	while (newmatch->over_bowled < 0)
	{
		cout << "Invalid ! Enter a +ve value : ";
		cin >> newmatch->over_bowled;
	}
}
player *first;
void getdata(player *currentt)
{
	cout << "Enter name of player : ";
	cin.ignore();
	getline(cin, currentt->name);
	cout << "Enter country name of player: ";
	getline(cin, currentt->country_name);
	cout << "Enter category of player: ";
	getline(cin, currentt->category);
	cout << "Enter the Date of birth (DD/MM/YY):" << endl;
	cout << "DD : ";
	cin >> currentt->date_of_birth.day;
	while (currentt->date_of_birth.day<0 || currentt->date_of_birth.day>31)
	{
		cout << " Enter day in 1-31 Range.\nEnter days again:";
		cin >> currentt->date_of_birth.day;
	}
	cout << "MM : "; 
	cin >> currentt->date_of_birth.month;
	while (currentt->date_of_birth.month<0 || currentt->date_of_birth.month>12)
	{
		cout << "Enter Month in 1-12 Range.\nEnter Month again:";
		cin >> currentt->date_of_birth.month;
	}
	cout << "YY : "; 
	cin >> currentt->date_of_birth.year;
	while (((currentt->date_of_birth.year)<=0) || ((currentt->date_of_birth.year)>(now->tm_year+1900)))
	{
		cout << "Enter year in 1-" << (now->tm_year+1900) << " Range.\nEnter year again:";
		cin >> currentt->date_of_birth.year;
	}
	cout << "Enter the Date of dabut (DD/MM/YY):" << endl;
	cout << "DD : ";
	cin >> currentt->date_of_dabut.day;
	while (currentt->date_of_dabut.day<0 || currentt->date_of_dabut.day>31)
	{
		cout << " Enter day in 1-31 Range.\nEnter days again:";
		cin >> currentt->date_of_dabut.day;
	}
	cout << "MM : "; 
	cin >> currentt->date_of_dabut.month;
	while (currentt->date_of_dabut.month<0 || currentt->date_of_dabut.month>12)
	{
		cout << "Enter Month in 1-12 Range.\nEnter Month again:";
		cin >> currentt->date_of_dabut.month;
	}
	cout << "YY : ";
	cin >> currentt->date_of_dabut.year;
	while (currentt->date_of_dabut.year<0 || currentt->date_of_dabut.year>(now->tm_year + 1900))
	{
		cout << "Enter year in 1-" << (now->tm_year+1900) << " Range.\nEnter year again:";
		cin >> currentt->date_of_dabut.year;
	}
	cout << "How mateches player play:";
	int n;
	cin >> n;
	while (n<0)
	{
		cout << "Invalid ! Enter a +ve value : ";
		cin >> n;
	}
	match *record = new match;
	matchdata(record);
	record->newnode = NULL;
	currentt->head = currentt->last = record;
	for (int i = 1; i < n; i++)
	{
		match *newrecord = new match;
		matchdata(newrecord);
		newrecord->newnode = NULL;
		currentt->last->newnode = newrecord;
		currentt->last = newrecord;
	}
}
void input()
{
	int n;
	player *last;
	first = last = NULL;
	cout << "Enter number of players : ";
	cin >> n;
	while (n<0 || n>99)
	{
		cout << "Enter players in 1-99 Range.\nEnter again number of players:";
		cin >> n;
	}
	player *current = new player;
	getdata(current);
	current->link = NULL;
	first = last = current;
	for (int i = 1; i < n; i++)
	{
		player *newplayer = new player;
		getdata(newplayer);
		newplayer->link = NULL;
		last->link = newplayer;
		last = newplayer;
	}
}
void process()
{
	player *temp1 = first;
	while (temp1 != NULL)
	{
		match *temp = temp1->head;
		while (temp != NULL)
		{
			temp1->total_score = temp1->total_score + temp->score;
			temp1->total_wicket = temp1->total_wicket + temp->wicket;
			temp1->total_over_bowled = temp1->total_over_bowled + temp->over_bowled;
			temp1->total_score_given = temp1->total_score_given + temp->score_given;
			if (temp1->best_score < temp->score)
				temp1->best_score = temp->score;
			if (temp1->best_wickect < temp->wicket)
				temp1->best_wickect = temp->wicket;
			temp = temp->newnode;
		}
		temp1 = temp1->link;
	}
}
void insertion()
{
	player *newrocord = new player;
	getdata(newrocord);
	newrocord->link = NULL;
	player *temp = first;
	while (temp->link != NULL)
	{
		temp = temp->link;
	}
	temp->link = newrocord;
	sorting();
}
void deletion()
{
	string name; 
	int dy, mon, yr;
	cout << "Enter name of player you want to remove : ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter DOB of " << name << " in (dd/mm/yy) formate : " << endl;
	cout << "Enter day:";
	cin >> dy;
	while (dy<0 || dy>31)
	{
		cout << "Enter days in 1-31 Range : ";
		cin >> dy;
	}
	cout << "Enter month:";
	cin >> mon;
	while (mon<0 || mon>12)
	{
		cout << "Enter month in 1-12 Range : ";
		cin >> mon;
	}
	cout << "Enter year : ";
	cin >> yr;
	while (yr<0 || yr>(now->tm_year+1900))
	{
		cout << "Enter year in 1-"<< (now->tm_year+1900) <<" Range : ";
		cin >> yr;
	}
	player *temp = first;
	player *previous = NULL;
	while (temp != NULL)
	{
		if ((temp->link->link == NULL) && (temp->link->name == name) && (temp->date_of_birth.day = dy) && (temp->date_of_birth.month = mon) && (temp->date_of_birth.year = yr))        //last digit
		{
			temp->link = NULL;
			break;
		}
		else if ((temp == first) && (temp->name == name) && (temp->date_of_birth.day = dy) && (temp->date_of_birth.month = mon) && (temp->date_of_birth.year = yr))                       //first digit
		{
			first = temp->link;
			delete temp;
			break;
		}
		else if ((temp->name == name) && (temp->date_of_birth.day = dy) && (temp->date_of_birth.month = mon) && (temp->date_of_birth.year = yr))                                            //digit in between list
		{
			previous->link = temp->link;
			delete temp;
			break;
		}
		else
		{
			previous = temp;
			temp = temp->link;
		}
	}
}
void sorting()
{
	player *previous, *current, *temp;
	temp = previous = first;
	int counter = 0;
	current = first->link;
	while (temp != NULL)
	{
		temp = temp->link;
		counter++;
	}
	for (int i = counter - 1; i >= 0; i--)
	{
		previous = first;
		current = first->link;
		for (int j = 0; j < counter - 1; j++)
		{
			if (previous->name > current->name)
			{
				swap(previous->country_name, current->country_name);
				swap(previous->name, current->name);
				swap(previous->category, current->category);
				swap(previous->date_of_birth, current->date_of_birth);
				swap(previous->date_of_dabut, current->date_of_dabut);
				swap(previous->head, current->head);
				swap(previous->best_score, current->best_score);
				swap(previous->best_wickect, current->best_wickect);
				swap(previous->total_over_bowled, current->total_over_bowled);
				swap(previous->total_score, current->total_score);
				swap(previous->total_score_given, current->total_score_given);
				swap(previous->total_wicket, current->total_wicket);
			}
			previous = current;
			current = current->link;
		}
	}
}
void update()
{
	string nam;
	cout << "Enter name of player (you want to update):";
	cin.ignore();
	getline(cin, nam);
	player *temp1 = first;
	while (temp1 != NULL)
	{
		if (temp1->name == nam)
			break;
		temp1 = temp1->link;
	}
	match *newrecord = new match;
	matchdata(newrecord);
	match *temp2 = temp1->head;
	while (temp2->newnode != NULL)
	{
		temp2 = temp2->newnode;
	}
	newrecord->newnode = NULL;
	temp2->newnode = newrecord;
	temp1->total_score = temp1->total_score + newrecord->score;
	temp1->total_wicket = temp1->total_wicket + newrecord->wicket;
	temp1->total_over_bowled = temp1->total_over_bowled + newrecord->over_bowled;
	temp1->total_score_given = temp1->total_score_given + newrecord->score_given;
	if (temp1->best_score < newrecord->score)
		temp1->best_score = newrecord->score;
	if (temp1->best_wickect < newrecord->wicket)
		temp1->best_wickect = newrecord->wicket;
}
void edit_name()
{
	player *temp = first;
	string namm; 
	int check_name = 0;
	cout << "Enter previous name : ";
	cin.ignore();
	getline(cin, namm);
	while (temp != NULL)
	{
		if (temp->name == namm)
		{
			cout << "Enter current Name : ";
			getline(cin, temp->name);
			cout << "Name is successfully changed." << endl; 
			check_name++;
			break;
		}
		temp = temp->link;
	}
	if (check_name == 0)
		cout << "Entered name doesn't exist in the list. Try another name." << endl;
}
void edit_countryName()
{
	player *temp = first;
	string naam; 
	int check_countryName = 0;
	cout << "Enter name of player who's country you want to edit : ";
	cin.ignore();
	getline(cin, naam);
	while (temp != NULL)
	{
		if (temp->name == naam)
		{
			cout << "Enter current country Name : ";
			getline(cin, temp->country_name);
			cout << "country name is successfully changed." << endl; 
			check_countryName++;
			break;
		}
		temp = temp->link;
	}
	if (check_countryName == 0)
		cout << "Entered player name doesn't exist in the list. Try another name." << endl;
}
void edit_DOB()
{
	player *temp = first;
	string nnam;
	int check_nam = 0;
	cout << "Enter player name : ";
	cin.ignore();
	getline(cin, nnam);
	while (temp != NULL)
	{
		if (temp->name == nnam)
		{
			cout << "Enter current Date of birth.\n";
			cout << "DD : ";
			cin >> temp->date_of_birth.day;
			while (temp->date_of_birth.day<0 || temp->date_of_birth.day>31)
			{
				cout << " Enter day in 1-31 Range.\nEnter days again:";
				cin >> temp->date_of_birth.day;
			}
			cout << "MM : ";
			cin >> temp->date_of_birth.month;
			while (temp->date_of_birth.month<0 || temp->date_of_birth.month>12)
			{
				cout << "Enter Month in 1-12 Range.\nEnter Month again:";
				cin >> temp->date_of_birth.month;
			}
			cout << "YY : ";
			cin >> temp->date_of_birth.year;
			while (((temp->date_of_birth.year) <= 0) || ((temp->date_of_birth.year)>(now->tm_year + 1900)))
			{
				cout << "Enter year in 1-" << (now->tm_year + 1900) << " Range.\nEnter year again:";
				cin >> temp->date_of_birth.year;
			}
			cout << "Date is successfully changed." << endl;
			check_nam++;
			break;
		}
		temp = temp->link;
	}
	if (check_nam == 0)
		cout << "Entered name doesn't exist in the list. Try another name." << endl;
}
void edit_DOD()
{
	player *temp = first;
	string naamm; 
	int check_namee = 0;
	cout << "Enter player name : ";
	cin.ignore();
	getline(cin, naamm);
	while (temp != NULL)
	{
		if (temp->name == naamm)
		{
			cout << "Enter current Date of birth.\n";
			cout << "DD : ";
			cin >> temp->date_of_dabut.day;
			while (temp->date_of_dabut.day<0 || temp->date_of_dabut.day>31)
			{
				cout << " Enter day in 1-31 Range.\nEnter days again:";
				cin >> temp->date_of_dabut.day;
			}
			cout << "MM : ";
			cin >> temp->date_of_dabut.month;
			while (temp->date_of_dabut.month<0 || temp->date_of_dabut.month>12)
			{
				cout << "Enter Month in 1-12 Range.\nEnter Month again:";
				cin >> temp->date_of_dabut.month;
			}
			cout << "YY : ";
			cin >> temp->date_of_dabut.year;
			while (((temp->date_of_dabut.year) <= 0) || ((temp->date_of_dabut.year)>(now->tm_year + 1900)))
			{
				cout << "Enter year in 1-" << (now->tm_year + 1900) << " Range.\nEnter year again:";
				cin >> temp->date_of_dabut.year;
			}
			cout << "Date is successfully changed." << endl; 
			check_namee++;
			break;
		}
		temp = temp->link;
	}
	if (check_namee == 0)
		cout << "Entered name doesn't exist in the list. Try another name." << endl;
}
void edit_category()
{
	player *temp = first;
	string naM;
	int check_NamE = 0;
	cout << "Enter name of player who's category you want to edit : ";
	cin.ignore();
	getline(cin, naM);
	while (temp != NULL)
	{
		if (temp->name == naM)
		{
			cout << "Enter current category of player : ";
			cin.ignore();
			getline(cin, temp->category);
			cout << "category is successfully changed." << endl;
			check_NamE++;
			break;
		}
		temp = temp->link;
	}
	if (check_NamE == 0)
		cout << "Entered player name doesn't exist in the list. Try another name." << endl;
}
void edit_recorde()
{
	int choiice;
	cout << "|************** Edit One of Them ***********|" << endl;
	cout << "| Press 1 to edit name of player            |" << endl;
	cout << "| Press 2 to edit counter name of player    |" << endl;
	cout << "| Press 3 to edit Date_Of_Birth             |" << endl;
	cout << "| Press 4 to Edit Date_Of_Dabit             |" << endl;
	cout << "| Press 5 to edit category of player.       |" << endl;
	cout << "| Press y OR Y to stop editing              |" << endl;
	cout << "|___________________________________________|" << endl;
	cout << "Enter your choice : ";
	cin >> choiice;
	while (choiice<1 || choiice>5)
	{
		cout << "Ivalid choice. Enter choice again.";
		cin >> choiice;
	}
	switch (choiice)
	{
	case 1:
		edit_name();
		break;
	case 2:
		edit_countryName();
		break;
	case 3:
		edit_DOB();
		break;
	case 4:
		edit_DOD();
		break;
	case 5:
		edit_category();
		break;
	default:
		cout << "Invlid choice. Try again latter." << endl;
	}
}
void display_match_data()
{
	string nAm;
	cout << "Enter name of player you want to display matches :";
	cin.ignore();
	getline(cin, nAm);
	player *temp = first;
	while (temp != NULL)
	{
		if (nAm == temp->name)
			break;
		else
			temp = temp->link;
	}
	match *temp1 = temp->head;
	int i = 1;
	cout << endl;
	cout << "|******************************** MATCH DATA ********************************|" << endl;
	cout << "|              score      wickect      score_given        over_bowled        |" << endl;
	while (temp1 != NULL)
	{
		cout << setw(8) << left << "|  Match " << setw(7) << left << i << setw(12) << left << temp1->score << setw(14) << left << temp1->wicket << setw(20) << left << temp1->score_given << setw(15) << left << temp1->over_bowled << setw(14) << left << "|" << endl;
		temp1 = temp1->newnode;
		i++;
	}
	cout << setw(16) << left << "|  Total" << setw(12) << left << temp->total_score << setw(14) << left << temp->total_wicket << setw(20) << left << temp->total_score_given << setw(15) << left << temp->total_over_bowled << "|" << endl;
	cout << "|----------------------------------------------------------------------------|" << endl;
	cout << "|                         | Best Score  : " << temp->best_score << " |                                |" << endl;
	cout << "|                         | Best Wicket : " << temp->best_wickect << " |                                |" << endl;
	cout << "|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
	cout << endl;
}
void display_player_data()
{
	player *temp;
	temp = first;
	cout << "|***************************************---- RESULT ----*********************************************|" << endl;
	cout << "|                                                               Dte of birth      date of dabut      |" << endl;
	cout << "|    " << setw(20) << left << "Player's Name" << setw(18) << left << "country_Name" << setw(18) << left << "Cagtegory" << "   dd/mm/yy" << setw(18) << right << "   dd/mm/yy" << setw(12) << right << "|" << endl;
	while (temp != NULL)
	{
		cout << "|    " << setw(20) << left << temp->name << setw(18) << left << temp->country_name << setw(21) << left << temp->category;
		cout << "   " << temp->date_of_birth.day << "/" << temp->date_of_birth.month << "/" << temp->date_of_birth.year << "        " << temp->date_of_dabut.day << "/" << temp->date_of_dabut.month << "/" << temp->date_of_dabut.year << setw(10) << right << "|" << endl;
		temp = temp->link;
	}
	cout << "|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
}
void manue()
{
	cout << "\t|****************-- MANUE --****************|" << endl;
	cout << "\t| Press 1 to input player data              |" << endl;
	cout << "\t| Press 2 to insert player in list          |" << endl;
	cout << "\t| Press 3 to remove player from the list    |" << endl;
	cout << "\t| Press 4 to update any player's match      |" << endl;
	cout << "\t| Press 5 to edit any record                |" << endl;
	cout << "\t| Press 6 to search data of player          |" << endl;
	cout << "\t| press 7 to display result of players      |" << endl;
	cout << "\t| Press y or Y to exit program              |" << endl;
	cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
}
void display_of_search(player *tempp)
{
	cout << "|***************************************---- RESULT ----*********************************************|" << endl;
	cout << "|                                                           Dte of birth         date of dabut       |" << endl;
	cout << "|    " << setw(20) << left << "Player's Name" << setw(18) << left << "country_Name" << setw(17) << left << "Cagtegory" << setw(21) << left << "dd/mm/yy" << setw(16) << left << "dd/mm/yy" << setw(5) << right << "|" << endl;
	cout << "|    " << setw(20) << left << tempp->name << setw(18) << left << tempp->country_name << setw(17) << left << tempp->category;
	cout << setw(2) << left << tempp->date_of_birth.day << "/" << setw(2) << left << tempp->date_of_birth.month << "/" << setw(15) << left << tempp->date_of_birth.year << setw(2) << left << setw(2) << left << tempp->date_of_birth.day << "/" << setw(2) << left << tempp->date_of_birth.month << "/" << setw(4) << left << tempp->date_of_birth.year << setw(11) << right << "|" << endl;
	cout << "|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
}
void search_by_name()
{
	string nam; int found = 0;
	cout << "Enter name of player (you want to search):";
	cin.ignore();
	getline(cin, nam);
	player*temp = first;
	while (temp != NULL)
	{
		if (nam == temp->name)
		{
			found++;
			break;
		}
		temp = temp->link;
	}
	if (found==1)
		display_of_search(temp);
	else 
		cout << nam << " doesn't exist in list. Try again." << endl;
}
void search_by_country_name()
{
	string country_nam; int found = 0;
	cout << "Enter name of player,s country (you want to search):";
	cin.ignore();
	getline(cin, country_nam);
	player*temp = first;
	cout << "|***************************************---- RESULT ----*********************************************|" << endl;
	cout << "|                                                           Dte of birth         date of dabut       |" << endl;
	cout << "|    " << setw(20) << left << "Player's Name" << setw(18) << left << "country_Name" << setw(17) << left << "Cagtegory" << setw(21) << left << "dd/mm/yy" << setw(16) << left << "dd/mm/yy" << setw(5) << right << "|" << endl;
	while (temp != NULL)
	{
		if (temp->country_name == country_nam)
		{
			found++;
			cout << "|    " << setw(20) << left << temp->name << setw(18) << left << temp->country_name << setw(17) << left << temp->category;
			cout << setw(2) << left << temp->date_of_birth.day << "/" << setw(2) << left << temp->date_of_birth.month << "/" << setw(15) << left << temp->date_of_birth.year << setw(2) << left << setw(2) << left << temp->date_of_birth.day << "/" << setw(2) << left << temp->date_of_birth.month << "/" << setw(4) << left << temp->date_of_birth.year << setw(11) << right << "|" << endl;
		}
		temp = temp->link;
	}
	cout << "|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
	if (found == 0)
	cout << country_nam << " doesn't exist in list. That's whay List showing empety. So Try another name." << endl;
}
void search_by_bestWicket()
{
	int best_wickett = first->best_wickect;
	player*temp = first->link;
	player *position = NULL;
	while (temp != NULL)
	{
		if (best_wickett < temp->best_wickect)
		{
			best_wickett = temp->best_wickect;
			position = temp;
		}
		temp = temp->link;
	}
	display_of_search(position);
}
void search_by_mostMatches()
{
	player *position = NULL;
	int most_match = 0;
	player *temp = first;
	while (temp != NULL)
	{
		int count = 0;
		match *temp1 = temp->head;
		while (temp1 != NULL)
		{
			count++;
			temp1 = temp1->newnode;
		}
		if (most_match < count)
		{
			most_match = count; 
			position = temp;
		}
		temp = temp->link;
	}
	display_of_search(position);
}
void search_by_bestBettingEveraeg()
{
	player *position = NULL;
	player *temp = first;
	int best_betting;
	int check = 0;
	while (temp != NULL)
	{
		int count = 0;
		int total = 0;
		match *temp1 = temp->head;
		while (temp1 != NULL)
		{
			total += temp1->score_given;
			count++;
			temp1 = temp1->newnode;
		}
		if (check == 0)
		{
			best_betting = (total / count);
			check++;
			position = temp;
		}
		else if (best_betting > (total / count))
		{
			best_betting = (total / count); 
			position = temp;
		}
		temp = temp->link;
	}
	display_of_search(position);
}
void search_by_oldestAge()
{
	int d, m, y;
	int  curDate = now->tm_mday, curMonth = (now->tm_mon + 1), curYear = (now->tm_year+1900);
	player *temp = first;
	player *positionn=NULL;
	int oldest_age = 0;
	int checkk = 0;
	while (temp != NULL)
	{
		d = (curDate - temp->date_of_birth.day);
		if (d < 0)
		{
			d = (30 - temp->date_of_birth.day) + curDate;
			curMonth = curMonth - 1;
		}
		m = curMonth - temp->date_of_birth.month;
		if (m < 0)
		{
			m = (12 - temp->date_of_birth.month) + curMonth;
			curYear = curYear - 1;
		}
		y = curYear - temp->date_of_birth.year;
		if (checkk == 0)
		{
			oldest_age = ((365 * y) + (m * 30) + d);
			positionn = temp;
			checkk++;
		}
		else
		{
			if (oldest_age < ((365 * y) + (m * 30) + d))
			{
				oldest_age = ((365 * y) + (m * 30) + d);
				positionn = temp;
			}
		}
		temp = temp->link;
	}
	display_of_search(positionn);
}
void search_by_youngestAge()
{
	int d, m, y;
	int  curDate = now->tm_mday, curMonth = (now->tm_mon + 1), curYear = (now->tm_year + 1900);
	player *temp = first;
	player *positionn = NULL;
	int youngest_age = 0;
	int checkk = 0;
	while (temp != NULL)
	{
		d = (curDate - temp->date_of_birth.day);
		if (d < 0)
		{
			d = (30 - temp->date_of_birth.day) + curDate;
			curMonth = curMonth - 1;
		}
		m = curMonth - temp->date_of_birth.month;
		if (m < 0)
		{
			m = (12 - temp->date_of_birth.month) + curMonth;
			curYear = curYear - 1;
		}
		y = curYear - temp->date_of_birth.year;
		if (checkk == 0)
		{
			youngest_age = ((365 * y) + (m * 30) + d);
			positionn = temp;
			checkk++;
		}
		else
		{
			if (youngest_age > ((365 * y) + (m * 30) + d))
			{
				youngest_age = ((365 * y) + (m * 30) + d);
				positionn = temp;
			}
		}
		temp = temp->link;
	}
	display_of_search(positionn);
}
void search_by_bestbowling()
{
	player *temp = first;
	player *positioon=NULL;
	int best_bowling = 0;
	int checck = 0;
	while (temp != NULL)
	{
		if (checck == 0)
		{
			best_bowling = ((temp->total_wicket * 20) - temp->total_score_given); 
			positioon = temp;
			checck++;
		}
		else if (best_bowling > ((temp->total_wicket * 20) - temp->total_score_given))
		{
			best_bowling = ((temp->total_wicket * 20) - temp->total_score_given);
			positioon = temp;
		}
		temp = temp->link;
	}
	display_of_search(positioon);
}
void search()
{
	int choic;
	cout << "\t|***************-- SEARCH_MANUE --****************|" << endl;
	cout << "\t| Press 1 to search by name of player             |" << endl;
	cout << "\t| Press 2 to search by country name of player     |" << endl;
	cout << "\t| Press 3 to search by youngest age               |" << endl;
	cout << "\t| Press 4 to search by oldest age                 |" << endl;
	cout << "\t| Press 5 to search by most number of matches     |" << endl;
	cout << "\t| Press 6 to search by bet betting everage        |" << endl;
	cout << "\t| Press 7 to search by best bowling record        |" << endl;
	cout << "\t| Press 8 to search by highest wicket taker       |" << endl;
	cout << "\t| Press y Or Y to stop search                     |" << endl;
	cout << "\t|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
	cout << "Enter your choice :";
	cin >> choic;
	while (choic<1 || choic>8)
	{
		cout << "Invlid choice. enter again.";
		cin >> choic;
	}
	switch (choic)
	{
	case 1:
		search_by_name();
		break;
	case 2:
		search_by_country_name();
		break;
	case 3:
		search_by_youngestAge();
		break;
	case 4:
		search_by_oldestAge();
		break;
	case 5:
		search_by_mostMatches();
		break;
	case 6:
		search_by_bestBettingEveraeg();
		break;
	case 7:
		search_by_bestbowling();
		break;
	case 8:
		search_by_bestWicket();
		break;
	default:
		cout << "Invalid choice OR another error ! " << endl;
	}
}
int main()
{
	char choice; int flage = 0;
	do
	{
		manue();
		cout << "Enter your choice :";
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
			break;
		while ((int(choice)<49 || int(choice)>55))
		{
			cout << "You are entering wrong chracter.\n Enter valid Charcter between 1-7 : ";
			cin >> choice;
		}
		switch (choice)
		{
		case '1':
		{
					if (flage == 1)
					{
						cout << "You have allready entered data.Now should do insertion." << endl;
					}
					else
					{
						input();
						process();
						sorting();
						flage++;
					}
					break;
		}
		case '2':
		{
					if (flage == 0)
						cout << "Please ! First enter data then insert another Player." << endl;
					else
					{
						insertion();
						process();
						sorting();
					}
					break;
		}
		case '3':
		{
					if (flage == 0)
						cout << "Error ! No record exists. First input the data." << endl;
					else
					{
						deletion();
						sorting();
					}
					break;
		}
		case '4':
		{
					if (flage == 0)
						cout << "Error ! No record exists. First input the data." << endl;
					else
						update();
					break;
		}
		case '5':
		{
				  if (flage == 0)
					  cout << "Error ! No record exists to edit.first enter data." << endl;
				  else
				  {
					  edit_recorde();
					  do
					  {
						  char y;
						  cout << "If you want to edit another record press y OR Y : " << endl;
						  cout << "OR Prees s Or S to stop...." << endl;
						  cin >> y;
						  if ((y == 's') || (y == 'S'))
							  break;
						  else
							  edit_recorde();
					  } while (1);
				  }
				  break;
		}
		case '6':
		{
					if (flage == 0)
						cout << "Error ! No record exists to search. First input the data." << endl;
					else
					{
						search();
						do
						{
							char y;
							cout << "If you want to search another record press y OR Y : " << endl;
							cout << "OR Prees s Or S to stop...." << endl;
							cin >> y;
							if ((y == 's') || (y == 'S'))
								break;
							else
								search();
						} while (1);
					}
					break;
		}
		case '7':
		{
					if (flage == 0)
						cout << "Error ! No rocord found to disply. First enter data." << endl;
					else
					{
						int choicce;
						cout << "\t|*********************************************************|" << endl;
						cout << "\t| Press 1 to display whole list of players :              |" << endl;
						cout << "\t| Press 2 to display indvidual player's match data :      |" << endl;
						cout << "\t|_________________________________________________________|" << endl;
						cout << "Now Enter your choice : ";
						cin >> choicce;
						if (choicce == 1)
							display_player_data();
						else if (choicce == 2)
							display_match_data();
					}
					break;
		}
		default:
			cout << "Sorry ! Your enter invalid choice." << endl;
		}
	} while ((choice > 0) || (choice < 8));
	system("pause");
	return 0;
}
