#include "duck_duck_goose.h"
#include<bits/stdc++.h>
using namespace std;
CircularListInt :: CircularListInt(){}
void CircularListInt :: push_back(int value)
{

	if(head == nullptr)
	{
		// cout<<"empty ";
		Item *node = new Item[1];
		node->value = value;
		node->next = node;
		node->prev = node;
		head = node; 
	}
	else
	{
		// cout<<"pushed ";
		Item *p;
		p = head;
		while(p->next != head)
		{
			p = p->next;
		}
		Item *node = new Item[1];
		node->value = value;
		node->prev = p;
		node->next = p->next;
		p->next = node;
		head->prev = node;
	}
}
size_t CircularListInt :: size() const
{
	size_t len=0;
	Item* p;
	p = head;
	while(p->next != head)
	{
		len++;
		p = p->next;
	}
	return len+1;	
}

int CircularListInt:: get(size_t index) const
{
	Item* p = head;
	for(int i=0;i<index;i++)
	{
		p = p->next;
	}
	return p->value;
}

void CircularListInt :: set(size_t index, int value)
{
	index = index%(size());
	Item *p = head;
	for(int i=0;i<index;i++)
	{
		p=p->next;
	}
	p->value = value;
}

void CircularListInt :: remove(size_t index)
{
	Item *p = head,*q;
	for(int i=0;i<index;i++)
	{
		p = p->next;
	}
	q = p->prev;
	q->next = p->next;
	p->next->prev = q;
	delete(p);
}

void simulateDDGRound(GameData * gameData, std::ostream & output)
{

	// gameData->playerList.printList();
	size_t len =  (gameData->playerList.size());
	// cout<<"length "<< len<<endl;
	int i=0,random = rand()%(4*len);
	// cout<<random<<endl;
	int places_to_adv = random % len;
	// cout<<"places_to_adv "<<places_to_adv<<endl;
	for(i=0;i<places_to_adv;i++)
	{
		output << gameData->playerList.get(i);
		output<<" is a Duck.\n";
		// cout<< gameData->playerList.get(i) <<" is a Duck."<<endl;
	}
	output<<gameData->playerList.get(i);
	output<< " is a Goose!"<<endl;
	// cout<<gameData->playerList.get(i)<<" is a Goose!"<<endl;
	int goose=0,it=0;
	while(goose == it)
	{
		goose = (rand()%49)+1;
		it = (rand()%49)+1;
	}
	if(it > goose)
	{
		int old_it_id = gameData->itPlayerID;
		int old_goose_id = gameData->playerList.get(i);
		// cout<<"old it"<<old_it_id<<endl;
		// cout<<"it is greater"<<endl;
		gameData->playerList.set(i,old_it_id);
		gameData->itPlayerID = old_goose_id;
		// cout<<gameData->playerList.get(i)<<endl;
		// cout<<"new it" <<(gameData->itPlayerID) <<endl;
		output<<old_it_id<<" took "<<old_goose_id<<"'s spot!\n";
		simulateDDGRound(gameData,output);
	}
	else
	{
		int old_it_id = gameData->itPlayerID;
		int old_goose_id = gameData->playerList.get(i);
		output<< old_it_id <<" is out!\n";
		if(gameData->playerList.size() == 1)
		{
			output<<gameData->playerList.get(0)<<" is winner"<<endl;
			exit(1);
		}
		int len = gameData->playerList.size();
		int new_it_index = rand()%len;
		if( (gameData->playerList.get(new_it_index)) == old_goose_id)
		{
			while( (gameData->playerList.get(new_it_index)) == old_goose_id )
			{
				new_it_index = rand()%len;
			}
		}
		int new_it_id = (gameData->playerList.get(new_it_index));
		output<<new_it_id<<" was chosen as the new it. "<<endl;
		gameData->playerList.remove(new_it_index);
		simulateDDGRound(gameData,output);

	}
}
int main(int argc, char *argv[])
{
	string conf = argv[1];
	string output = argv[2];
	fstream  config_file;
	ofstream out_file;
	// cout<<conf<<endl;
	config_file.open(conf,ios::in );
	out_file.open(output,ios::out);
	if(!config_file)
		cout<<"Can't open the file"<<endl;
	unsigned int seed=20,num_player=1,it_pid;
	config_file >> seed >> num_player >>it_pid;
	GameData *obj = new GameData[1];
	obj->itPlayerID = it_pid;
	int seated_pid[num_player-1];
	int i = 0;
	while(i<num_player)
	{
		config_file >> seated_pid[i];
		i++;
	}
	// cout<<seed<<" "<<num_player<<" "<<it_pid<<endl;
	for (i = 0;i<num_player-1;i++)
	{
		// cout<<seated_pid[i]<<" ";
		obj->playerList.push_back(seated_pid[i]);
	}
	srand(seed);
	// obj->playerList.printList();
	simulateDDGRound(obj , out_file);

}