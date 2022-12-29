#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

//Define the player character
class Player {
private:
string name;
int age;
int hack_level;
int reputation;
int money;
bool anonymous;
public:
Player(string name, int age, int hack_level, int reputation, int money, bool anonymous) {
this->name = name;
this->age = age;
this->hack_level = hack_level;
this->reputation = reputation;
this->money = money;
this->anonymous = anonymous;
}
string getName() {
return name;
}
int getAge() {
return age;
}
int getHackLevel() {
return hack_level;
}
int getReputation() {
return reputation;
}
int getMoney() {
return money;
}
bool isAnonymous() {
return anonymous;
}
void setName(string name) {
this->name = name;
}
void setAge(int age) {
this->age = age;
}
void setHackLevel(int hack_level) {
this->hack_level = hack_level;
}
void setReputation(int reputation) {
this->reputation = reputation;
}
void setMoney(int money) {
this->money = money;
}
void setAnonymous(bool anonymous) {
this->anonymous = anonymous;
}
};

//Define the various entities that the player can hack
class Entity {
private:
string name;
int security_level;
int reward;
public:
Entity(string name, int security_level, int reward) {
this->name = name;
this->security_level = security_level;
this->reward = reward;
}
string getName() {
return name;
}
int getSecurityLevel() {
return security_level;
}
int getReward() {
return reward;
}
void setName(string name) {
this->name = name;
}
void setSecurityLevel(int security_level) {
this->security_level = security_level;
}
void setReward(int reward) {
this->reward = reward;
}
};

//Define the various hacking tools that the player can use
class Tool {
private:
string name;
int cost;
int effectiveness;
public:
Tool(string name, int cost, int effectiveness) {
this->name = name;
this->cost = cost;
this->effectiveness = effectiveness;
}
string getName() {
return name;
}
int getCost() {
return cost;
}
int getEffectiveness() {
return effectiveness;
}
void setName(string name) {
this->name = name;void setCost(int cost) {
this->cost = cost;
}
void setEffectiveness(int effectiveness) {
this->effectiveness = effectiveness;
}
};

//Define the various actions that the player can perform during a hack
class HackAction {
private:
string name;
int difficulty;
public:
HackAction(string name, int difficulty) {
this->name = name;
this->difficulty = difficulty;
}
string getName() {
return name;
}
int getDifficulty() {
return difficulty;
}
void setName(string name) {
this->name = name;
}
void setDifficulty(int difficulty) {
this->difficulty = difficulty;
}
};

//Define the black market where the player can buy additional hacking tools
class BlackMarket {
private:
vector<Tool> tools;
public:
BlackMarket() {
tools = {};
}
void addTool(Tool tool) {
tools.push_back(tool);
}
void removeTool(Tool tool) {
for (int i = 0; i < tools.size(); i++) {
if (tools[i].getName() == tool.getName()) {
tools.erase(tools.begin() + i);
break;
}
}
}
vector<Tool> getTools() {
return tools;
}
};

//Define the various hacking scenarios that the player will encounter
class HackScenario {
private:
string name;
Entity target;
int reward;
vector<HackAction> actions;
public:
HackScenario(string name, Entity target, int reward, vector<HackAction> actions) {
this->name = name;
this->target = target;
this->reward = reward;
this->actions = actions;
}
string getName() {
return name;
}
Entity getTarget() {
return target;
}
int getReward() {
return reward;
}
vector<HackAction> getActions() {
return actions;
}
void setName(string name) {
this->name = name;
}
void setTarget(Entity target) {
this->target = target;
}
void setReward(int reward) {
this->reward = reward;
}
void setActions(vector<HackAction> actions) {
this->actions = actions;
}
};

//Define the government agency that is trying to track down and stop the player
class GovernmentAgency {
private:
string name;
int power;
public:
GovernmentAgency(string name, int power) {
this->name = name;
this->power = power;
}
string getName() {
return name;
}
int getPower() {
return power;
}
void setName(string name) {
this->name = name;
}
void setPower(int power) {
this->power = power;
}
};

//Define the underground hacking group that may try to recruit or attack the player
class UndergroundHackingGroup {
private:
string name;
int power;
public:
UndergroundHackingGroup(string name, int power) {
this->name = name;
this->power = power;
}
string getName() {
return name;
}
int getPower() {
return power;
}
void setName(string name) {
this->name = name;
}
void setPower(int power) {
this->power = power;
}
};

//Define the game itself
class HackGame {
private:
Player player;
vector<Entity> entities;
BlackMarket black_market;
vector<HackScenario> scenarios;
GovernmentAgency government_agency;
UndergroundHackingGroup underground_group;
public:
HackGame(Player player, vector<Entity> entities, BlackMarket black_market, vector<HackScenario> scenarios, GovernmentAgency government_agency, UndergroundHackingGroup underground_group) {
this->player = player;
this->entities = entities;
this->black_market = black_market;
this->scenarios = scenarios;
this->government_agency = government_agency;
this->underground_group = underground_group;
}
Player getPlayer() {
return player;
}
vector<Entity> getEntities() {
return entities;
}
BlackMarket getBlackMarket() {
return black_market;
}
vector<HackScenario> getScenarios() {
return scenarios;
}
GovernmentAgency getGovernmentAgency() {
return government_agency;
}
UndergroundHackingGroup getUndergroundGroup() {
return underground_group;
}
void setPlayer(Player player) {
this->player = player;
}
void setEntities(vector<Entity> entities) {
this->entities = entities;
}
void setBlackMarket(BlackMarket black_market) {
this->black_market = black_market;
}
void setScenarios(vector<HackScenario> scenarios) {
this->scenarios = scenarios;
}
void setGovernmentAgency(GovernmentAgency government_agency) {
this->government_agency = government_agency;
}
void setUndergroundGroup(UndergroundHackingGroup underground_group) {
this->underground_group = underground_group;
}
};

int main() {
//Create the player character
Player player = Player("John", 18, 1, 0, 0, true);

//Create the list of entities that the player can hack
vector<Entity> entities = {
Entity("Local Bank", 1, 1000),
Entity("Small Company", 2, 2000),
Entity("Medium Company", 3, 3000),
Entity("Large Company", 4, 4000),
Entity("Government Agency", 5, 5000)
};

//Create the black market
BlackMarket black_market = BlackMarket();//Create the list of hacking tools that the player can use
vector<Tool> tools = {
Tool("Brute Force Tool", 100, 1),
Tool("SQL Injection Tool", 200, 2),
Tool("Keylogger", 300, 3),
Tool("Spyware", 400, 4),
Tool("Ransomware", 500, 5)
};

//Add the tools to the black market
for (int i = 0; i < tools.size(); i++) {
black_market.addTool(tools[i]);
}

//Create the list of hack actions that the player can perform
vector<HackAction> actions = {
HackAction("Copy files", 1),
HackAction("Edit file names", 2),
HackAction("Hide log files", 3),
HackAction("Delete log files", 4),
HackAction("Read company emails", 5)
};

//Create the list of hacking scenarios that the player will encounter
vector<HackScenario> scenarios = {
HackScenario("Hack Local Bank", entities[0], 1000, actions),
HackScenario("Hack Small Company", entities[1], 2000, actions),
HackScenario("Hack Medium Company", entities[2], 3000, actions),
HackScenario("Hack Large Company", entities[3], 4000, actions),
HackScenario("Hack Government Agency", entities[4], 5000, actions)
};

//Create the government agency that is trying to track down the player
GovernmentAgency government_agency = GovernmentAgency("NSA", 5);

//Create the underground hacking group that may try to recruit or attack the player
UndergroundHackingGroup underground_group = UndergroundHackingGroup("Anonymous", 5);

//Create the game
HackGame game = HackGame(player, entities, black_market, scenarios, government_agency, underground_group);

//Start the game loop
while (true) {
//Display the main menu
cout << "Welcome to Script Kiddy OS" << endl;
cout << "1. Hack an entity" << endl;
cout << "2. Visit the black market" << endl;
cout << "3. View player stats" << endl;
cout << "4. Quit game" << endl;

//Get the player's choice
int choice;
cin >> choice;

//Handle the player's choice
switch (choice) {
case 1: {
//Display the list of entities that the player can hack
cout << "Choose an entity to hack:" << endl;
for (int i = 0; i < entities.size(); i++) {
cout << i + 1 << ". " << entities[i].getName() << endl;
}

  //Get the player's choice
  int entity_choice;
  cin >> entity_choice;

  //Get the selected entity
  Entity entity = entities[entity_choice - 1];

  //Check if the player has the required hack level to hack the entity
  if (player.getHackLevel() < entity.getSecurityLevel()) {
    cout << "You do not have the required hack level to hack this entity." << endl;
    break;
  }

  //Choose a random hack scenario for the entity
  int scenario_index = rand() % scenarios.size();
HackScenario scenario = scenarios[scenario_index];

  //Display the hack scenario to the player
  cout << "You have chosen to hack " << scenario.getTarget().getName() << "." << endl;
  cout << "Rewards: " << scenario.getReward() << " money" << endl;

  //Give the player the option to use a hacking tool
  cout << "Choose a hacking tool to use: " << endl;
  cout << "0. None" << endl;
  for (int i = 0; i < tools.size(); i++) {
    cout << i + 1 << ". " << tools[i].getName() << " (" << tools[i].getCost() << " money)" << endl;
  }

  //Get the player's choice
  int tool_choice;
  cin >> tool_choice;

  //Deduct the cost of the tool from the player's money if a tool was chosen
  if (tool_choice != 0) {
    Tool tool = tools[tool_choice - 1];
    player.setMoney(player.getMoney() - tool.getCost());
  }

  //Perform the hack actions
  for (int i = 0; i < scenario.getActions().size(); i++) {
    HackAction action = scenario.getActions()[i];

    //Determine if the hack action is successful or not
    bool success = false;
    if (tool_choice != 0) {
      //Use the effectiveness of the chosen tool to determine success
      Tool tool = tools[tool_choice - 1];
      int chance = rand() % 100;
      if (chance < (tool.getEffectiveness() * 20)) {
        success = true;
      }
    } else {
      //Use the player's hack level to determine success
      int chance = rand() % 100;
      if (chance < (player.getHackLevel() * 20)) {
        success = true;
      }
    }

    //If the hack action was successful, add to the player's reputation
    if (success) {
      cout << "Successfully performed hack action: " << action.getName() << endl;
      player.setReputation(player.getReputation() + action.getDifficulty());
    } else {
      cout << "Failed to perform hack action: " << action.getName() << endl;
    }
  }

  //Add the reward to the player's money
  player.setMoney(player.getMoney() + scenario.getReward());

  //Increase the player's hack level
  player.setHackLevel(player.getHackLevel() + 1);

  breakcase 2: {
//Display the list of tools in the black market
cout << "Choose a tool to buy: " << endl;
cout << "0. Back" << endl;
vector<Tool> market_tools = black_market.getTools();
for (int i = 0; i < market_tools.size(); i++) {
cout << i + 1 << ". " << market_tools[i].getName() << " (" << market_tools[i].getCost() << " money)" << endl;
}

  //Get the player's choice
  int tool_choice;
  cin >> tool_choice;

  //If the player chose to go back, break out of the loop
  if (tool_choice == 0) {
    break;
  }

  //Get the chosen tool
  Tool tool = market_tools[tool_choice - 1];

  //Deduct the cost of the tool from the player's money
  player.setMoney(player.getMoney() - tool.getCost());

  //Add the tool to the player's inventory
  player.addTool(tool);

  //Remove the tool from the black market
  black_market.removeTool(tool);

  break;
}
case 3: {
  //Display the player's stats
  cout << "Name: " << player.getName() << endl;
  cout << "Age: " << player.getAge() << endl;
  cout << "Hack level: " << player.getHackLevel() << endl;
  cout << "Reputation: " << player.getReputation() << endl;
  cout << "Money: " << player.getMoney() << endl;

  break;
}
case 4: {
  //End the game loop
  return 0;
}
default: {
  cout << "Invalid choice." << endl;
  break;
}

}
}

return 0;
}
