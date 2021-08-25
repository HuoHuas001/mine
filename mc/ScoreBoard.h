#pragma once
#include <vector>
#include <string>

struct Player;
struct PlayerScore {
	uintptr_t getScore();
};
//scoreboardcmd list; objective::objective; scoreboard getscores
//int scores    +12 this[12]
//string displayname  +96
//string name +64
struct ScoreInfo {
	int getCount();
};
struct ScoreboardId {
	int id;
	uintptr_t null;
};
struct ScorePacketInfo {
	ScoreboardId sid;
	std::string obj_name = "name";
	unsigned score;
	enum Type : char { Invalid = 0, Player = 1, Actor = 2, Fake = 3 };
	Type type = Fake;
	uintptr_t pid;
	uintptr_t aid;
	std::string fake_name;

	ScorePacketInfo(ScoreboardId* s, unsigned num, const std::string& fake);
};
struct Objective {
	//��ȡ�Ʒְ�����
	std::string getScoreName();
	//��ȡ�Ʒְ�չʾ����
	std::string getScoreDisplayName();
	auto createScoreboardId(Player* player);
	ScoreInfo* getPlayerScore(ScoreboardId* a2);
};
struct Scoreboard {
	Objective* getObjective(const std::string&);
	ScoreboardId* getScoreboardId(const std::string&);
	std::vector<Objective*> getObjectives();
	auto getDisplayInfoFiltered(const std::string& str);
	auto getTrackedIds();
	ScoreboardId* getScoreboardId(Player* a2);
	//������ҷ���
	int modifyPlayerScore(ScoreboardId* a3, Objective* a4, int count, int mode);
	ScoreboardId* createScoreBoardId(const std::string& s);
	ScoreboardId* createScoreBoardId(Player* player);
};
